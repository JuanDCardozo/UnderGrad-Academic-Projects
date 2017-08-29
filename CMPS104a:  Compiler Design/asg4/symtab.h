#ifndef __SYM_TABLE__
#define __SYM_TABLE__

#include <bitset>
#include <string.h>
#include <vector>
#include <unordered_map>

#include "auxlib.h"
#include "astree.h"

enum { ATTR_void, ATTR_int, ATTR_null, ATTR_string,
	ATTR_struct, ATTR_array, ATTR_function, ATTR_variable,
	ATTR_field, ATTR_typeid, ATTR_param, ATTR_lval, ATTR_const,
	ATTR_vreg, ATTR_vaddr, ATTR_bitset_size,
};
using attr_bitset = bitset<ATTR_bitset_size>;

struct astree;
struct symbol;
using symbol_table = unordered_map<const string*,symbol*>;
using symbol_entry = symbol_table::value_type;

struct symbol {
	attr_bitset attributes;
	symbol_table* fields;
	size_t filenr, linenr, offset;
	size_t block_nr;
	vector<symbol*>* parameters;
	const string* structtype;
	const string* fieldtype;
};

symbol* new_symbol(astree* node);
const char* check_attributes(astree* node);
void sym_insert(symbol_table table, const string *key,
				symbol *sym, astree* node,FILE* symfile);
void block(astree* root,FILE* symfile);
void set_attributes(astree* root);
void vardecl(astree *root, FILE *symfile);
void sym_struct(astree *root, FILE* symfile);
void sym_func(astree *root, FILE* symfile);
void prototype(astree *root, FILE* symfile);
void traversal(astree *root,FILE* symfile);
void fieldot(astree *root);
#endif
