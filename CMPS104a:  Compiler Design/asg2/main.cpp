
#include <string>
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

/* Parses and stores the char* into hashtable */
void parse_n_store(){
   //read cpp data into hashtable
   unsigned token_type;

   do{
     token_type = yylex();
   }while(token_type != YYEOF);

 }

/* */
struct Flag setFlag(struct Flag flag, int argc , char** argv) {
  int c;
  while((c = getopt(argc-1, argv, "lyD:@:")) != -1){
    switch(c){
       case 'l':
          flag.lflag =  true;
          break;
       case 'y':
          flag.yflag =  true;
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
     exit(1);
  }
}

/* Parses the char* into a pipe*/
void fileParsing(char* filename, char* options){
  //File parsing
  FILE* pipe = cpp(filename, options);
  parse_n_store();
  fclose(pipe);
}
char* getOutName(char* filename, const char* extension){
  char* outname = basename(filename);
  auto dotIndex = strrchr(outname, '.');
  *dotIndex = '\0';
  strcat(outname,extension);
  return outname;
}

/* Dumps to a file*/
void dumpToFile(char* ocfname){
  const char* str = ".str";
  const char* tok = ".tok";
  char* str_outname = getOutName(ocfname,str);
  char* tok_outname = getOutName(ocfname,tok);
  FILE* strfile = fopen(str_outname, "w");
  string_set::dump(strfile);
  tokfile = fopen(tok_outname, "w");
  fclose(strfile);
  fclose(tokfile);
}

/***************************************************************************
*                               Main
*************************************************************************** */
int main (int argc, char **argv) {
   struct Flag flag;
   char* ocfname = argv[argc-1];

   //Gets flags and parses the file
   flag = setFlag(flag,argc, argv);
   checkFileExtension(ocfname);
   fileParsing(ocfname, flag.dOption);

   //Dump to file
   dumpToFile(ocfname);
   return EXIT_SUCCESS;
}
