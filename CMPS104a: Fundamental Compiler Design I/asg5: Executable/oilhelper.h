#ifndef __CODE_GEN__
#define __CODE_GEN__

#include <bitset>
#include <string.h>
#include <vector>
#include <unordered_map>


#include "auxlib.h"
#include "astree.h"
#include "symtab.h"
#include "lyutils.h"

// return appropriate oil type, or could print directly to oil file
string mangle_struct(astree* node);
string mangle_ident(astree* node);
string new_vreg(char type);

void codegen_oil(FILE* file, astree* root);

#endif
