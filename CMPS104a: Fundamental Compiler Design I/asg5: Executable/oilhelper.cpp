#include "oilhelper.h"
#include <cstdlib>
#include <cstring>

size_t int_count = 0;
size_t ind_ptr_count = 0;
size_t ptr_count = 0;
size_t string_count = 0;

symbol_table* symtable = new symbol_table;
void codegen_node(FILE* file, astree* node);
void codegen_expr(FILE* file, astree* node);
void codegen_new_vreg(FILE* file, astree* node);

void indent(FILE* file){
	fprintf(file, "        ");
}

string new_vreg(char type){
	string vreg_string;
	switch(type){
		case 'i':
			vreg_string += type;
        	vreg_string += to_string(++int_count);
        	break;
        case 'p':
            vreg_string += type;
            vreg_string += to_string(++ptr_count);
            break;
        case 's':
        	vreg_string += type;
        	vreg_string += to_string(++string_count);
        	break;
        case 'a':
        	vreg_string += type;
        	vreg_string += to_string(++ind_ptr_count);
        	break;
        default:
        errprintf("Invalid Virtual Register type: %c \n", type);
	}
	return vreg_string;
}

// Does same work for if, if else and while
void worker1(FILE* file, astree* node){
    switch(node->children[0]->symbol){
        case TOK_IDENT:
        case TOK_CHARCON:
        case TOK_INTCON:
            break;
        default:
            indent(file);
            codegen_expr(file, node->children[0]);
    }
    indent(file);
}

// Does some work that is repeated in if and in ifelse
void worker2(FILE* file, astree* node){
  for(auto child : node->children[0]->children){
      indent(file);
      codegen_node(file, child);
  }
}

void codegen_while(FILE* file, astree* node){
  // Declare Variables
  size_t filenr = node->lloc.filenr;
  size_t linenr = node->lloc.linenr;
  size_t offset = node->lloc.offset;
  size_t filenr1 = node->children[1]->lloc.filenr;
  size_t linenr1 = node->children[1]->lloc.linenr;
  size_t offset1 = node->children[1]->lloc.offset;
  const char* vreg0 = node->children[0]->vreg.c_str();

	fprintf(file, "while_%zu_%zu_%zu:;\n",filenr,linenr,offset);
	worker1(file,node);
  fprintf(file,"if (!%s) goto break_%zu_%zu_%zu\n",
    vreg0,filenr1,linenr1,offset1);
  codegen_node(file, node->children[1]);
  indent(file);
  fprintf(file,"goto while_%zu_%zu_%zu\n",filenr,linenr,offset);
  fprintf(file,"break_%zu_%zu_%zu):;\n",filenr1,linenr1,offset1);
}

// Generates the code for if
void codegen_if(FILE* file, astree* node){
  // Declare Variables
  size_t filenr = node->children[0]->lloc.filenr;
  size_t linenr = node->children[0]->lloc.linenr;
  size_t offset = node->children[0]->lloc.offset;
  const char* vreg = node->children[0]->vreg.c_str();

  worker1(file,node);
  fprintf(file, "if (!%s) goto fi_%zu_%zu_%zu;\n"
		,vreg,filenr,linenr,offset);

  for(auto child : node->children[0]->children){
      indent(file);
      codegen_node(file, child);
  }
  fprintf(file, "fi_%zu_%zu_%zu:;\n",filenr,linenr,offset);

}

// Generaete the code for the ifelse
void codegen_ifelse(FILE* file, astree* node){
  // Declare Variables
  size_t filenr = node->children[0]->lloc.filenr;
  size_t linenr = node->children[0]->lloc.linenr;
  size_t offset = node->children[0]->lloc.offset;
  const char* vreg = node->children[0]->vreg.c_str();

  worker1(file,node);
  fprintf(file, "if (!%s) goto else_%zu_%zu_%zu;\n"
		,vreg,filenr,linenr,offset);
  worker2(file,node);
  fprintf(file,"goto fi_%zu_%zu_%zu:;\n",filenr,linenr,offset);
  fprintf(file,"else_%zu_%zu_%zu:;\n",filenr,linenr,offset);
  worker2(file,node);
  fprintf(file,"fi_%zu_%zu_%zu:;\n",filenr,linenr,offset);

}

void codegen_ident(FILE* file, astree* node){
    printf("codegen ident: %s\n", node->lexinfo->c_str());
    string ident = mangle_ident(node);
    fprintf(file, ident.c_str());
    node->vreg = ident;
}

void codegen_expr(FILE* file, astree* node){
    if(node->attributes[ATTR_vreg]){
      fprintf(file, "%s %s %s",
          node->children[0]->vreg.c_str(),
          node->lexinfo->c_str(),
          node->children[1]->vreg.c_str()
          );
    }else{
        switch(node->symbol){
            case TOK_IDENT:
                codegen_ident(file, node);
                break;
            case TOK_INTCON:
            case TOK_CHARCON:
                codegen_new_vreg(file, node);
                break;
        }
    }
    fprintf(file, "\n");
}

void codegen_rec(FILE* file, astree* node){
    for(auto child : node->children){
        codegen_rec(file, child);
    }
    codegen_node(file, node);
}

void codegen_return(FILE* file, astree* node){
    if(!node->children.empty()){
        fprintf(file, "return %s;\n", node->children[0]->vreg.c_str());
    }else{
        indent(file);
        fprintf(file, "return;\n");
    }
}

void codegen_assignment(FILE* file, astree* node){
    symbol* sym = symlookup(symtable, node);
    char* type_buf = nullptr;
    indent(file);
    if(node->attributes[ATTR_int]){
        node->vreg = new_vreg('i');
        type_buf = strdup("int");
    }else if(node->attributes[ATTR_struct]){
        node->vreg = new_vreg('p');
        type_buf = (char*)  node->children[0]->lexinfo;
    }

    if(sym == nullptr){
        fprintf(file, "%s %s %s %s;\n",
            type_buf, node->children[0]->vreg.c_str(),
            node->lexinfo->c_str(), node->vreg.c_str());
    }else{
        fprintf(file, "%s %s %s;\n",
            node->children[0]->vreg.c_str(),
            node->lexinfo->c_str(),
            node->vreg.c_str());
    }
}

void codegen_new_vreg(FILE* file, astree* node){
    char* type_buf;
    if(node->attributes[ATTR_int]){
        node->vreg = new_vreg('i');
        type_buf = strdup("int");
    }else if(node->attributes[ATTR_struct]){
        node->vreg = new_vreg('p');
        type_buf = (char*) node->children[0]->lexinfo->c_str();
    }else{
        node->vreg = new_vreg('a');
        type_buf = strdup("unknown");
    }
    fprintf(file, "%s %s", type_buf, node->vreg.c_str());
}

void codegen_call(FILE* file, astree* node){
    if(!node->attributes[ATTR_void]){
        codegen_new_vreg(file, node);
    }
    fprintf(file, "%s ( ", node->children.back()->lexinfo->c_str());
    for(auto child = node->children.begin();
		 	child != node->children.end()-1; child++){
        fprintf(file, "%s", (*child)->vreg.c_str());
        if(child != node->children.end()-2){
            fprintf(file, ", ");
        }else{
            fprintf(file, " );\n");
        }
    }
}

void codegen_node(FILE* file, astree* node){
    switch(node->symbol){
        case TOK_WHILE:
            codegen_while(file, node);
            break;
        case TOK_IF:
            codegen_if(file, node);
            break;
        case TOK_IFELSE:
            codegen_ifelse(file, node);
            break;
        case TOK_VARDECL:
            codegen_assignment(file, node);
            break;
        case TOK_RETURN:
            codegen_return(file, node);
            break;
        case TOK_CALL:
            codegen_call(file, node);
            break;
        case '+':
        case '-':
        case '*':
        case '%':
        case TOK_EQ:
        case TOK_NE:
        case TOK_LE:
        case TOK_GE:
        case TOK_LT:
        case TOK_GT:
        case TOK_POS:
        case TOK_NEG:
        case TOK_INTCON:
        case TOK_IDENT:
        case TOK_CHARCON:
            codegen_expr(file, node);
            break;
    }
}

string mangle_ident(astree* node){
    string ident_str = *node->lexinfo + " ";
    astree* child = nullptr;
    if (!node->children.empty()){
        child = node->children[0];
    }else{
        child = node;
    }
    // Global Identifier
    if(node->block_nr == 0){
        // Two underscore for global.
        ident_str += "__";
        ident_str += *child->lexinfo;
    }else{
        ident_str += "_";
        ident_str += child->block_nr;
        ident_str += "_";
        ident_str += *child->lexinfo;
    }
    return ident_str;
}

void codegen_func(FILE* file, astree* node){
    string func_str = "__" + *node->children[0]->lexinfo + " ";
    func_str += *node->children[0]->children[0]->lexinfo + "(\n";
    // For every parameter mangle it
    for(auto param : node->children[1]->children){
        func_str += "        ";
        func_str += *param->lexinfo;
        func_str += " _";
        func_str += to_string(param->children[0]->block_nr);
        func_str += "_";
        func_str += *param->children[0]->lexinfo;
        func_str += ",\n";
    }

    // Correct last comma from above forloop on last param w/ ')'
    func_str.pop_back();
    func_str.pop_back();
    func_str += ")\n{\n";

    fprintf(file, func_str.c_str());
    for(auto func_block : node->children[2]->children){
        codegen_rec(file, func_block);
    }
    fprintf(file, "}\n");
}

void codegen_oil(FILE* file, astree* root){
    // Prolog
    fprintf(file, "#define __OCLIB_C__\n");
    fprintf(file, "#include \"oclib.oh\"");
    // First process structs
    for(auto child : root->children){
        if(child->symbol == TOK_STRUCT){
          string struct_str;
          struct_str += "struct s_" + *child->children[0]->lexinfo;
					struct_str += "{\n";
          for(auto field = child->children.cbegin()+1;
              field != child->children.cend(); field++){
              struct_str += "        ";
              struct_str += *(*field)->lexinfo;
              struct_str += " _f";
              struct_str += *(*field)->children[0]->lexinfo;
              struct_str += "_";
              struct_str += *(*field)->children[0]->lexinfo;
              struct_str += ";\n";
          }
          struct_str += "};\n";
          fprintf(file,struct_str.c_str());
        }
    }

    // ocmain Function Header
    fprintf(file, "void __ocmain (void) {\n");

    // STRINGCON
    for(auto child : root->children){
        indent(file);
        string vreg = new_vreg('s');
        child->vreg = vreg;
        fprintf(file, "char* %s = %s;\n",
            child->vreg.c_str(), child->lexinfo->c_str());
    }

    // Global Variables
    for(auto child : root->children){
        if(child->symbol == TOK_VARDECL){
            fprintf(file, "        ");
            child->vreg = mangle_ident(child->children[0]);
            fprintf(file, child->vreg.c_str());
        }else if(child->symbol != TOK_FUNCTION
						&& child->symbol != TOK_PROTOTYPE){
            codegen_rec(file, root);
        }
    }
    fprintf(file, "}\n");
    // Function Emission

    for(auto child : root->children){
        if(child->symbol == TOK_FUNCTION){
            codegen_func(file, child);
        }
    }

}
