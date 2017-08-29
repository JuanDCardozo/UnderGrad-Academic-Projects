
#include <string>
#include <iostream>
#include <unistd.h>
#include <fstream>
using namespace std;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <unistd.h>
#include <vector>
#include "auxlib.h"
#include "astree.h"
#include "lyutils.h"

#include "stringset.h"
#define BUFSIZE 4096

const string CPPLINE = "/usr/bin/cpp -nostdinc";
constexpr size_t LINESIZE = 1024;

struct Flag{
  bool lflag = false;
  bool yflag = false;
  bool dflag = false;
  bool atflag = false;
  char* dOption;
  char* atOption;
};
/***************************************************************************
*                               Helper Functions
*************************************************************************** */
/* Runs the c preprocessor*/
FILE* cpp(char* filename, char* options){
   string command = CPPLINE + " " + filename + " " ;
   if (options != NULL){
      command = command + "-D" + options;
  }
   //Run cpp on a process
   return(popen(command.c_str(), "r"));
}

/* */
struct Flag setFlag(struct Flag flag, int argc , char** argv) {
  int c;
  yy_flex_debug = 0;
  yydebug = 0;
  while((c = getopt(argc-1, argv, "lyD:@:")) != -1){
    switch(c){
       case 'l':
          flag.lflag =  true;
          yy_flex_debug = 1;
          break;
       case 'y':
          flag.yflag =  true;
          yydebug = 1;
          break;
       case 'D':
          flag.dflag = true;
          flag.dOption = optarg;
          break;
       case '@':
          flag.atflag = true;
          flag.atOption = optarg;
          set_debugflags(optarg);
          break;
       default:
          fprintf(stderr, "Unknown option `%s'\n", optarg);
          exit(EXIT_FAILURE);
    }
  }
  return flag;
}

/* Checks if the extension is oc */
void checkFileExtension(char* filename){
  if (!strstr(filename, ".oc")){
     fprintf(stderr, "File not valid. Need .oc file extension\n");
     exit(EXIT_FAILURE);
  }
}

char* getOutName(char* filename, const char* extension){
  char* outname = basename(filename);
  auto dotIndex = strrchr(outname, '.');
  *dotIndex = '\0';
  strcat(outname,extension);
  return outname;
}

/* **************************************************************************
*                        File ouputs builders
**************************************************************************** */
// Preprocesses the oc program
void preprocess(char* filename, int argc, char **argv){
  int parsecode = 0;
  struct Flag flag;

  //Gets flags and parses the file
  flag = setFlag(flag,argc, argv);
  checkFileExtension(filename);
  //File preprocessing
  FILE* pipe = cpp(filename, flag.dOption);
  const char* tok = ".tok";
  char* outname = getOutName(filename,tok);
  FILE* tokfile = fopen(outname, "w+");
  if (pipe == NULL) {
      fprintf(stderr, "Command Error");
      exit(EXIT_FAILURE);
   } else {
      yyin = pipe;
      parsecode = yyparse();
      if (parsecode) {
        fprintf(stderr, "Error Parsing");
        exit(EXIT_FAILURE);
   }
 }
 const char* str = ".str";
 char* outname2 = getOutName(filename,str);
 FILE* strfile = fopen(outname2, "w+");
 string_set::dump(strfile);
 fclose(strfile);
  fclose(pipe);
  fclose(tokfile);
}
/*
// Generates the .tok file
void build_tok(char* filename){


}*/

// Generates the .str file
void build_str(char* filename){
  const char* str = ".str";
  char* outname = getOutName(filename,str);
  FILE* strfile = fopen(outname, "w+");
  string_set::dump(strfile);
  fclose(strfile);

}

// Generates the .ast file
 void build_ast(char* filename){
   const char* ast= ".ast";
   char* outname = getOutName(filename,ast);
   FILE* astfile = fopen(outname, "w+");
   astree::dump(astfile, yyparse_astree);
   fclose(astfile);
 }
/***************************************************************************
*                               Main
*************************************************************************** */
int main (int argc, char **argv) {
   char* filename = argv[argc-1];

   // NEW code
   // Preprocess the oc program. Add directives and set flags
   preprocess(filename,argc,argv);

   //Tokenize the oc program. Using parse.y
   //build_tok(filename);

   // Dump the string set from the tokenized
   build_str(filename);

  // Build these ast tree
   build_ast(filename);

   return EXIT_SUCCESS;
}
