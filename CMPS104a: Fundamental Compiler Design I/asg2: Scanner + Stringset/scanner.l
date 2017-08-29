%{

#include "auxlib.h"
#include "lyutils.h"

#define IGNORE(THING)   { }


%}

%option 8bit
%option debug
%option nodefault
%option nounput
%option noyywrap
%option verbose
%option warn


LETTER          [A-Za-z_]
DIGIT           [0-9]
NUMBER          {DIGIT}+

CHAR ('([^\\'\n]|\\[\\'"0nt])')
STRING (\"([^\\"\n]|\\[\\'"0nt])*\")
PREPROC (#{NUMBER} {STRING})
IDENT           ({LETTER}({LETTER}|{DIGIT})*)
BADIDENT ({NUMBER}+{IDENT})
BADSTRING (\"[^\n\"\\]*(.|\n))
ABADCHAR ('(.*)|\n')
BADCHAR ('[\n\'\\]'|'.[^\'])

%%

"#".*           { scanner_include(); }
[ \t]+          { IGNORE (white space) }
\n              { scanner_newline(); }
"="            { return yylval_token ('=');  }
"+"            { return yylval_token ('+');  }
"-"            { return yylval_token ('-');  }
"*"            { return yylval_token ('*');  }
"/"            { return yylval_token ('/');  }
"("            { return yylval_token ('(');  }
")"            { return yylval_token (')');  }
";"            { return yylval_token (';');  }
"["            { return yylval_token ('[');  }
"]"            { return yylval_token (']');  }
"{"            { return yylval_token ('{');  }
"}"            { return yylval_token ('}');  }
","            { return yylval_token (',');  }
"."            { return yylval_token ('.');  }
"%"            { return yylval_token ('%');  }
"!"            { return yylval_token ('!');  }
"=="           { return yylval_token (TOK_EQ);     }
"!="           { return yylval_token (TOK_NE);     }
"<"            { return yylval_token (TOK_LT);     }
"<="           { return yylval_token (TOK_LE);     }
">"            { return yylval_token (TOK_GT);     }
">="           { return yylval_token (TOK_GE);     }
"[]"           { return yylval_token (TOK_ARRAY);  }
.              { scanner_badchar (*yytext); }

"void"         { return yylval_token (TOK_VOID);   }
"string"       { return yylval_token (TOK_STRING); }
"if"           { return yylval_token (TOK_IF);     }
"else"         { return yylval_token (TOK_ELSE);   }
"while"        { return yylval_token (TOK_WHILE);  }
"return"       { return yylval_token (TOK_RETURN); }
"struct"       { return yylval_token (TOK_STRUCT); }
"int"          { return yylval_token (TOK_INT); }
"null"         { return yylval_token (TOK_NULL);   }
"new"          { return yylval_token (TOK_NEW);    }

{NUMBER}       { return yylval_token (TOK_INTCON);       }
{IDENT}        { return yylval_token (TOK_IDENT);        }
{BADIDENT}     { scanner_badtoken(yytext);               }
{CHAR}         { return yylval_token (TOK_CHARCON);      }
{STRING}       { return yylval_token (TOK_STRINGCON);    }
{BADCHAR}      { scanner_badtoken(yytext);               }
{BADSTRING}    { scanner_badtoken(yytext);               }


%%
