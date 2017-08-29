#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <string.h>

#include "symtab.h"
#include "astree.h"
#include "auxlib.h"
#include "lyutils.h"
#include "stringset.h"

vector<symbol_table*> symbol_stack={new symbol_table,nullptr};
int next_block = 1;
vector<int> block_count={0};

symbol* new_symbol(astree* node){

	symbol *sym = new symbol();

	sym->fields=nullptr;
	sym->parameters=nullptr;
	sym->structtype=nullptr;
	sym->fieldtype=nullptr;
	sym->attributes=node->attributes;
	sym->block_nr=block_count.back();
	sym->filenr=node->lloc.filenr;
	sym->linenr=node->lloc.linenr;
	sym->offset=node->lloc.offset;
	return sym;
}

const char* check_attributes(astree* node){
	attr_bitset attr_arr= node->attributes;
	string s = "";

	if(attr_arr[ATTR_field]){
		s+="field ";
		if(node->fieldtype){
			s=s+"{"+*(node->fieldtype)+"} ";
		}
	}
	if(attr_arr[ATTR_void]){
		s+="void ";
	}
	if(attr_arr[ATTR_int]){
		s+="int ";
	}
	if(attr_arr[ATTR_null]){
		s+="null ";
	}
	if(attr_arr[ATTR_string]){
		s+="string ";
	}
	if(attr_arr[ATTR_struct]){
		s+="struct ";
		if(node->structtype){
			s=s+"\"" +*(node->structtype)+"\" ";
		}
	}
	if(attr_arr[ATTR_array]){
		s+="array ";
	}
	if(attr_arr[ATTR_function]){
		s+="function ";
	}
	if(attr_arr[ATTR_variable]){
		s+="variable ";
	}
	if(attr_arr[ATTR_typeid]){
		s+="typeid ";
	}
	if(attr_arr[ATTR_lval]){
		s+="lval ";
	}
	if(attr_arr[ATTR_param]){
		s+="param ";
	}
	if(attr_arr[ATTR_const]){
		s+="const ";
	}
	return s.c_str();
}

// Sets the attributes recursively
void set_attributes(astree* node){
	for(size_t i=0;i<node->children.size();i++){
		set_attributes(node->children[i]);
	}

  switch(node->symbol){
    case TOK_VOID:
      node->attributes[ATTR_void]=true;
  		if(node->children.size()>0){
  			node->children[0]->attributes[ATTR_void]=true;
  		}
      break;
    case TOK_INT:
      node->attributes[ATTR_int]=true;
      node->attributes[ATTR_const]=true;
      if(node->children.size()>0){
        node->children[0]->attributes[ATTR_int]=true;
        node->children[0]->structtype=node->lexinfo;
      }
      break;
    case TOK_NULL:
      node->attributes[ATTR_null]=true;
      node->attributes[ATTR_const]=true;
      break;
    case TOK_STRING:
      node->attributes[ATTR_string]=true;
      node->attributes[ATTR_lval]=true;
      if(node->children.size()>0){
        node->children[0]->attributes[ATTR_string]=true;
      }
      break;
    case TOK_STRUCT:
      node->attributes[ATTR_struct]=true;
      node->structtype=node->children[0]->lexinfo;
      node->attributes[ATTR_variable]=false;
      node->attributes[ATTR_lval]=false;

      node->children[0]->attributes[ATTR_struct]=true;
      node->children[0]->attributes[ATTR_variable]=false;
      node->children[0]->attributes[ATTR_lval]=false;
      break;
    case TOK_ARRAY:
      node->attributes[ATTR_array]=true;
      break;
    case TOK_FUNCTION:
      node->attributes[ATTR_function]=true;
      node->attributes[ATTR_variable]=false;
      node->attributes[ATTR_lval]=false;

      node->children[0]->attributes[ATTR_function]=true;
      node->children[0]->attributes[ATTR_variable]=false;
      node->children[0]->attributes[ATTR_lval]=false;
      break;
    case TOK_VARDECL:
      node->attributes[ATTR_variable]=true;
      break;
    case '.':
      node->children[0]->attributes[ATTR_struct]=true;
      node->children[1]->attributes[ATTR_field]=true;
      break;
    case TOK_FIELD:
      node->attributes[ATTR_field]=true;
      break;
    case TOK_TYPEID:
      node->attributes[ATTR_typeid]=true;
       for(size_t i=0;i<node->children.size();i++){
        node->children[i]->attributes[ATTR_struct]=true;
        node->children[i]->structtype=node->lexinfo;
      }
      break;
    case TOK_PARAMLIST:
      for(size_t i=0;i<node->children.size();i++){
        node->children[i]->attributes[ATTR_param]=true;
      }
      break;
    case TOK_INTCON:
      node->attributes[ATTR_int]=true;
  		node->attributes[ATTR_const]=true;
  		node->attributes[ATTR_lval]=true;
      break;
    case TOK_CHARCON:
      node->attributes[ATTR_int]=true;
  		node->attributes[ATTR_const]=true;
  		node->attributes[ATTR_lval]=true;
      break;
    case TOK_STRINGCON:
      node->attributes[ATTR_string]=true;
      node->attributes[ATTR_const]=true;
      node->attributes[ATTR_lval]=true;
      break;
    case TOK_DECLID:
      node->attributes[ATTR_variable]=true;
      node->attributes[ATTR_lval]=true;
      break;
    case TOK_IDENT:
      node->attributes[ATTR_variable]=true;
      node->attributes[ATTR_lval]=true;
      break;
    case TOK_PROTOTYPE:
      node->children[0]->children[0]->attributes[ATTR_variable]=false;
      node->children[0]->children[0]->attributes[ATTR_lval]=false;
      break;
  }
}


// Insert symbol itno table
void sym_insert(symbol_table table, const string* key,
				symbol* sym, astree* node, FILE* symfile){
	table[key]=sym;
	for(size_t i=1;i<block_count.size(); i++){
		fprintf(symfile, "  ");
	}
	fprintf(symfile, "%s (%zd.%zd.%zd) {%zd} %s\n",
			key->c_str(),sym->filenr, sym->linenr, sym->offset,
			sym->block_nr,check_attributes(node));
}
/* ****************************************************************
 *  Parts Definitions
 **********************************************=****************** */
// makes a block for if, ifelse, else
void block(astree* root,  FILE* symfile){
	block_count.push_back(next_block);
	next_block++;
	symbol_stack[block_count.back()]=new symbol_table;
	symbol_stack.push_back(nullptr);
	traversal(root,symfile);
	block_count.pop_back();
}


// Declare variable
void vardecl(astree *root, FILE *symfile){
	astree *vardecl = root->children[0]->children[0];
	vardecl->structtype=root->children[0]->lexinfo;
	symbol* sym = new_symbol(vardecl);
	sym->structtype=vardecl->structtype;
	sym_insert(*symbol_stack[block_count.back()], vardecl->lexinfo,
		sym, vardecl,symfile);
}

// Start struct
void sym_struct(astree* root, FILE* symfile){
  astree* child1 = root->children[0];
  astree* child2 = root->children[1];

	if(root->children.size()>0){
		child1->structtype = child1->lexinfo;
		child1->attributes[ATTR_typeid]=false;
	}
	symbol* sym = new_symbol(child1);
	symbol_table fieldloc;
	sym->fields=&fieldloc;
	sym->structtype = child1->lexinfo;
	sym_insert(*symbol_stack[0], child1->lexinfo,sym,child1,symfile);
	for(size_t i=0;i< child2->children.size();i++){
		fprintf(symfile,"  ");
		astree* field = child2->children[i]->children[0];
		field->fieldtype = child1->lexinfo;
		field->structtype = child2->children[i]->lexinfo;
		sym=new_symbol(field);
		sym_insert(fieldloc,field->lexinfo,sym,field,symfile);
	}
}

//
void sym_func(astree *root, FILE* symfile){
  astree *grandchild = root->children[0]->children[0];
  astree* child = root->children[0];

	grandchild->functype = child->lexinfo;
	grandchild->attributes[ATTR_function]=true;
	grandchild->attributes[ATTR_lval]=false;
	grandchild->attributes[ATTR_variable]=false;
	symbol *sym = new_symbol(grandchild);
	vector<symbol*> paramloc;
	sym->parameters=&paramloc;
	sym_insert(*symbol_stack[0],grandchild->lexinfo,
			sym,grandchild,symfile);
	astree* params = root->children[1];
	for(size_t i=0;i<params->children.size();i++){
		params->children[i]->children[0]->structtype=
			params->children[i]->lexinfo;
		params->children[i]->children[0]->attributes[ATTR_param]=true;
		sym=new_symbol(params->children[i]->children[0]);
		sym->structtype=params->children[i]->children[0]->structtype;
		sym->block_nr++;
		paramloc.push_back(sym);
		fprintf(symfile,"  ");
		sym_insert(*symbol_stack[0],
			params->children[i]->children[0]->lexinfo,sym,
			params->children[i]->children[0],symfile);
	}
	block(root->children[2],symfile);
}

void prototype(astree *root, FILE* symfile){
  astree *grandchild = root->children[0]->children[0];
  astree* child = root->children[0];

	grandchild->functype = child->lexinfo;
	grandchild->attributes[ATTR_function]=true;
	grandchild->attributes[ATTR_lval]=false;
	grandchild->attributes[ATTR_variable]=false;
	symbol *sym = new_symbol(grandchild);
	vector<symbol*> paramloc;
	sym->parameters=&paramloc;
	sym_insert(*symbol_stack[0],grandchild->lexinfo, sym,
			grandchild,symfile);

	astree* params = root->children[1];
	for(size_t i=0;i<params->children.size();i++){
		params->children[i]->children[0]->structtype=
			params->children[i]->lexinfo;
		params->children[i]->children[0]->attributes[ATTR_param]=true;
		sym = new_symbol(params->children[i]->children[0]);
		sym->block_nr++;
		paramloc.push_back(sym);
	}
}

// Check if dot field something.field
void fieldot(astree *root){
  astree* child1 = root->children[0];
  astree* child2 = root->children[1];

	symbol_table* base_tbl=symbol_stack[0];
	auto c1=base_tbl->find(child1->lexinfo);
	if(c1 != base_tbl->end()){
		child1->attributes[ATTR_struct]=true;
		child1->structtype=c1->second->structtype;
		child2->attributes[ATTR_field]=true;
		child2->fieldtype=c1->second->structtype;
	}
}


void traversal(astree *root,FILE* symfile){
	for(size_t i=0;i<root->children.size();i++){
		int sym = root->children[i]->symbol;
		switch(sym){
			case '.':
				fieldot(root->children[i]);
				fprintf(symfile, "\n");
			case TOK_STRUCT:
				sym_struct(root->children[i],symfile);
				fprintf(symfile, "\n");
				break;
			case TOK_FUNCTION:
				sym_func(root->children[i],symfile);
				fprintf(symfile, "\n");
				break;
			case TOK_VARDECL:
				vardecl(root->children[i],symfile);
				break;
			case TOK_PROTOTYPE:
				prototype(root->children[i],symfile);
				fprintf(symfile, "\n");
				break;
			case TOK_IF:
				block(root->children[i]->children[1],symfile);
				break;
			case TOK_IFELSE:
				block(root->children[i]->children[1],symfile);
				block(root->children[i]->children[2],symfile);
				break;
			default:
				break;
		}
	}
}
symbol* symlookup(symbol_table* st,  astree* node){
   string* lexinfo = const_cast<string*>(node->lexinfo);
   if(!st->count(lexinfo))
      return nullptr;
   symbol_entry ent = *st->find(const_cast<string*>(node->lexinfo));
   node->deflinenr = ent.second->linenr;
   node->deffilenr = ent.second->filenr;
   node->defoffset = ent.second->offset;
   return ent.second;
}
