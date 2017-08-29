/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

#include <cassert>

#include "lyutils.h"
#include "astree.h"


/* Line 371 of yacc.c  */
#line 76 "yyparse.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.h".  */
#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_VOID = 258,
     TOK_CHAR = 259,
     TOK_INT = 260,
     TOK_STRING = 261,
     TOK_IF = 262,
     TOK_ELSE = 263,
     TOK_WHILE = 264,
     TOK_RETURN = 265,
     TOK_STRUCT = 266,
     TOK_NULL = 267,
     TOK_NEW = 268,
     TOK_ARRAY = 269,
     TOK_EQ = 270,
     TOK_NE = 271,
     TOK_LT = 272,
     TOK_LE = 273,
     TOK_GT = 274,
     TOK_GE = 275,
     TOK_IDENT = 276,
     TOK_INTCON = 277,
     TOK_CHARCON = 278,
     TOK_STRINGCON = 279,
     TOK_BLOCK = 280,
     TOK_CALL = 281,
     TOK_IFELSE = 282,
     TOK_INITDECL = 283,
     TOK_POS = 284,
     TOK_NEG = 285,
     TOK_NEWARRAY = 286,
     TOK_TYPEID = 287,
     TOK_FIELD = 288,
     TOK_ROOT = 289,
     TOK_FALSE = 290,
     TOK_TRUE = 291,
     TOK_BOOL = 292,
     TOK_ORD = 293,
     TOK_CHR = 294,
     TOK_FUNCTION = 295,
     TOK_PARAMLIST = 296,
     TOK_PROTOTYPE = 297,
     TOK_NEWSTRING = 298,
     TOK_INDEX = 299,
     TOK_DECLID = 300,
     TOK_RETURNVOID = 301,
     TOK_VARDECL = 302
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 189 "yyparse.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   538

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,    53,     2,     2,
      58,    60,    51,    49,    59,    50,    63,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    55,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    18,    22,    23,
      27,    31,    36,    41,    44,    48,    50,    52,    54,    56,
      58,    61,    65,    70,    75,    80,    85,    88,    92,    95,
      98,   101,   104,   106,   108,   110,   112,   114,   117,   119,
     124,   130,   138,   144,   147,   151,   155,   158,   160,   162,
     166,   168,   170,   172,   174,   176,   178,   180,   182,   184,
     186,   188,   190,   192,   194,   196,   198,   200,   205,   211,
     217,   221,   225,   228,   232,   234,   239,   243,   245,   247,
     249
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    66,    -1,    66,    68,    -1,    66,    72,
      -1,    66,    76,    -1,    66,     1,    55,    -1,    66,     1,
      56,    -1,    -1,    57,    69,    56,    -1,    67,    69,    56,
      -1,    11,    21,    67,    55,    -1,    11,    21,    57,    55,
      -1,    70,    21,    -1,    70,    14,    21,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,    21,    -1,    58,    73,
      -1,    71,    59,    73,    -1,    73,    71,    60,    75,    -1,
      73,    71,    60,    56,    -1,    73,    58,    60,    75,    -1,
      73,    58,    60,    56,    -1,    70,    21,    -1,    70,    14,
      21,    -1,    57,    76,    -1,    74,    76,    -1,    74,    55,
      -1,    57,    55,    -1,    75,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    56,    -1,    56,    -1,    73,
      48,    81,    56,    -1,     9,    58,    81,    60,    76,    -1,
       7,    58,    81,    60,    76,     8,    76,    -1,     7,    58,
      81,    60,    76,    -1,    10,    56,    -1,    10,    81,    56,
      -1,    81,    82,    81,    -1,    83,    81,    -1,    84,    -1,
      86,    -1,    58,    81,    60,    -1,    87,    -1,    88,    -1,
      15,    -1,    16,    -1,    17,    -1,    18,    -1,    19,    -1,
      20,    -1,    49,    -1,    50,    -1,    51,    -1,    52,    -1,
      48,    -1,    29,    -1,    30,    -1,    54,    -1,    13,    -1,
      13,    21,    58,    60,    -1,    13,     6,    58,    81,    60,
      -1,    13,    70,    61,    81,    62,    -1,    21,    58,    81,
      -1,    85,    59,    81,    -1,    85,    60,    -1,    21,    58,
      60,    -1,    21,    -1,    81,    61,    81,    62,    -1,    81,
      63,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    12,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    40,    40,    43,    44,    45,    46,    47,    48,    51,
      56,    63,    69,    77,    82,    89,    90,    91,    92,    93,
      96,   101,   108,   115,   121,   129,   138,   143,   150,   155,
     161,   166,   173,   174,   175,   176,   177,   178,   183,   186,
     194,   201,   208,   215,   220,   227,   228,   229,   230,   231,
     236,   237,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   253,   254,   255,   256,   259,   265,   271,
     279,   284,   291,   296,   304,   305,   311,   318,   319,   320,
     321
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_CHAR", "TOK_INT",
  "TOK_STRING", "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_RETURN",
  "TOK_STRUCT", "TOK_NULL", "TOK_NEW", "TOK_ARRAY", "TOK_EQ", "TOK_NE",
  "TOK_LT", "TOK_LE", "TOK_GT", "TOK_GE", "TOK_IDENT", "TOK_INTCON",
  "TOK_CHARCON", "TOK_STRINGCON", "TOK_BLOCK", "TOK_CALL", "TOK_IFELSE",
  "TOK_INITDECL", "TOK_POS", "TOK_NEG", "TOK_NEWARRAY", "TOK_TYPEID",
  "TOK_FIELD", "TOK_ROOT", "TOK_FALSE", "TOK_TRUE", "TOK_BOOL", "TOK_ORD",
  "TOK_CHR", "TOK_FUNCTION", "TOK_PARAMLIST", "TOK_PROTOTYPE",
  "TOK_NEWSTRING", "TOK_INDEX", "TOK_DECLID", "TOK_RETURNVOID",
  "TOK_VARDECL", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'}'",
  "';'", "'{'", "'('", "','", "')'", "'['", "']'", "'.'", "$accept",
  "start", "program", "structstmts", "structdef", "fielddecl", "basetype",
  "params", "function", "identdecl", "body", "block", "statement",
  "vardecl", "while", "ifelse", "return", "expr", "binop", "unop",
  "allocator", "cexprs", "call", "variable", "constant", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    61,    43,
      45,    42,    47,    37,    33,   125,    59,   123,    40,    44,
      41,    91,    93,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    77,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    84,    84,    84,
      85,    85,    86,    86,    87,    87,    87,    88,    88,    88,
      88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     3,
       3,     4,     4,     2,     3,     1,     1,     1,     1,     1,
       2,     3,     4,     4,     4,     4,     2,     3,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     2,     1,     4,
       5,     7,     5,     2,     3,     3,     2,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     5,
       3,     3,     2,     3,     1,     4,     3,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    15,    16,    17,    18,     0,
       0,     0,     0,    80,    66,    74,    77,    78,    79,    63,
      64,    65,    38,     0,     0,     3,     0,     4,     0,     0,
      32,     5,    33,    34,    35,    36,     0,     0,    47,     0,
      48,    50,    51,     6,     7,     0,     0,    74,    43,     0,
       0,    18,    19,     0,     0,    31,     0,    28,     0,     0,
      26,     0,     0,     0,    30,    29,    52,    53,    54,    55,
      56,    57,    62,    58,    59,    60,    61,    37,     0,     0,
       0,    46,     0,    72,     0,     0,    44,     0,     0,     0,
       0,     0,    73,    70,    49,    27,     0,    19,     0,    20,
       0,     0,     0,    76,    45,    71,     0,     0,    12,     0,
       0,    11,     0,     0,    67,     0,    39,    25,    24,    21,
      23,    22,    75,    42,    40,     9,     0,    13,    10,    68,
      69,     0,    14,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    88,    25,   109,    26,    63,    27,    56,
      29,    30,    31,    32,    33,    34,    35,    36,    80,    37,
      38,    39,    40,    41,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
     -67,    24,    91,   -67,   -51,   -67,   -67,   -67,   -67,   -36,
     -20,   433,    34,   -67,    38,     9,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   129,   480,   -67,     6,   -67,   -27,   167,
     -67,   -67,   -67,   -67,   -67,   -67,   221,   480,   -67,   -13,
     -67,   -67,   -67,   -67,   -67,   480,   480,     0,   -67,   237,
       3,     7,    14,     1,    27,   -67,    40,   -67,   286,    45,
     -67,   480,     4,    -6,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   480,    49,
     480,   423,   480,   -67,   292,   308,   -67,     8,    13,   480,
      26,   480,   -67,   423,   -67,   -67,   346,   -67,    18,   -67,
     119,    22,   362,   -67,   423,   423,   205,   205,   -67,    33,
      12,   -67,    37,   368,   -67,   417,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,    82,   -67,   -67,    84,   -67,   -67,   -67,
     -67,   205,   -67,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,    19,   -11,   -67,   -67,    -1,
     -67,   -66,   -23,   -67,   -67,   -67,   -67,    -9,   -67,   -67,
     -67,   -67,   -67,   -67,   -67
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -20
static const yytype_int16 yytable[] =
{
      57,    28,    49,    53,    43,    44,    65,     5,     6,     7,
       8,     5,     6,     7,     8,    58,     5,     6,     7,     8,
      59,    61,    45,   -19,     3,    97,   126,    60,    81,    97,
     -19,    62,   118,   127,    97,   121,    84,    85,    46,    13,
      14,     5,     6,     7,    51,    93,    82,    83,    47,    16,
      17,    18,    96,   100,   101,    50,    19,    20,    54,    52,
      87,    99,    91,   108,    98,    89,    95,    54,   111,   102,
     103,   104,    90,   105,   117,    23,   110,   110,   120,    23,
     113,    21,   115,   123,   124,    24,   114,    92,    61,   125,
     131,    -2,     4,   128,     5,     6,     7,     8,     9,   119,
      10,    11,    12,    13,    14,   132,     0,   112,   133,     0,
       0,     0,    15,    16,    17,    18,     0,     0,     0,     0,
      19,    20,     5,     6,     7,     8,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,     0,    10,    11,
      97,    13,    14,     0,     0,    21,     0,    22,    23,    24,
      15,    16,    17,    18,     0,     0,     0,     0,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,     0,    10,    11,     0,    13,
      14,     0,     0,    21,    55,    22,    23,    24,    15,    16,
      17,    18,     0,     0,     0,     0,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,     0,    10,    11,     0,    13,    14,     0,
       0,    21,    64,    22,    23,    24,    15,    16,    17,    18,
       0,     0,     0,     0,    19,    20,    66,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,     0,    21,
       0,    22,    23,    24,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,     0,     0,     0,    77,     0,     0,
       0,     0,    78,     0,    79,    72,    73,    74,    75,    76,
       0,     0,     0,    86,     0,     0,     0,     0,    78,     0,
      79,    66,    67,    68,    69,    70,    71,    66,    67,    68,
      69,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,     0,
      72,    73,    74,    75,    76,     0,    94,    78,     0,    79,
       0,     0,   106,    78,     0,    79,    72,    73,    74,    75,
      76,    66,    67,    68,    69,    70,    71,     0,   107,    78,
       0,    79,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,    71,    66,    67,    68,    69,    70,    71,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,     0,
       0,     0,   116,     0,     0,     0,     0,    78,     0,    79,
      72,    73,    74,    75,    76,     0,    72,    73,    74,    75,
      76,     0,     0,    78,   122,    79,     0,     0,   129,    78,
       0,    79,    66,    67,    68,    69,    70,    71,    66,    67,
      68,    69,    70,    71,     0,    13,    14,     0,     0,     0,
       0,     0,     0,     0,    47,    16,    17,    18,     0,     0,
       0,     0,    19,    20,     0,    72,    73,    74,    75,    76,
       0,    72,    73,    74,    75,    76,     0,     0,    78,   130,
      79,     0,     0,     0,    78,     0,    79,    21,     0,    48,
       0,    24,    13,    14,     0,     0,     0,     0,     0,     0,
       0,    47,    16,    17,    18,     0,     0,     0,     0,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    24
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      23,     2,    11,    14,    55,    56,    29,     3,     4,     5,
       6,     3,     4,     5,     6,    24,     3,     4,     5,     6,
      14,    48,    58,    14,     0,    21,    14,    21,    37,    21,
      21,    58,    98,    21,    21,   101,    45,    46,    58,    12,
      13,     3,     4,     5,     6,    54,    59,    60,    21,    22,
      23,    24,    61,    59,    60,    21,    29,    30,    58,    21,
      57,    62,    61,    55,    60,    58,    21,    58,    55,    78,
      21,    80,    58,    82,    56,    57,    87,    88,    56,    57,
      89,    54,    91,   106,   107,    58,    60,    60,    48,    56,
       8,     0,     1,    56,     3,     4,     5,     6,     7,   100,
       9,    10,    11,    12,    13,    21,    -1,    88,   131,    -1,
      -1,    -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,     9,    10,
      21,    12,    13,    -1,    -1,    54,    -1,    56,    57,    58,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    12,
      13,    -1,    -1,    54,    55,    56,    57,    58,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    12,    13,    -1,
      -1,    54,    55,    56,    57,    58,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    54,
      -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    61,    -1,    63,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    61,    -1,
      63,    15,    16,    17,    18,    19,    20,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    -1,
      48,    49,    50,    51,    52,    -1,    60,    61,    -1,    63,
      -1,    -1,    60,    61,    -1,    63,    48,    49,    50,    51,
      52,    15,    16,    17,    18,    19,    20,    -1,    60,    61,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    61,    -1,    63,
      48,    49,    50,    51,    52,    -1,    48,    49,    50,    51,
      52,    -1,    -1,    61,    62,    63,    -1,    -1,    60,    61,
      -1,    63,    15,    16,    17,    18,    19,    20,    15,    16,
      17,    18,    19,    20,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    -1,    48,    49,    50,    51,    52,
      -1,    48,    49,    50,    51,    52,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,    61,    -1,    63,    54,    -1,    56,
      -1,    58,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    66,     0,     1,     3,     4,     5,     6,     7,
       9,    10,    11,    12,    13,    21,    22,    23,    24,    29,
      30,    54,    56,    57,    58,    68,    70,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    83,    84,    85,
      86,    87,    88,    55,    56,    58,    58,    21,    56,    81,
      21,     6,    21,    70,    58,    55,    73,    76,    81,    14,
      21,    48,    58,    71,    55,    76,    15,    16,    17,    18,
      19,    20,    48,    49,    50,    51,    52,    56,    61,    63,
      82,    81,    59,    60,    81,    81,    56,    57,    67,    58,
      58,    61,    60,    81,    60,    21,    81,    21,    60,    73,
      59,    60,    81,    21,    81,    81,    60,    60,    55,    69,
      70,    55,    69,    81,    60,    81,    56,    56,    75,    73,
      56,    75,    62,    76,    76,    56,    14,    21,    56,    60,
      62,     8,    21,    76
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 40 "parser.y"
    { yyparse_astree = (yyvsp[(1) - (1)]); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 43 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 44 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 45 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 46 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 47 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 48 "parser.y"
    { (yyval) = new_parseroot(); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 52 "parser.y"
    {
                  destroy((yyvsp[(3) - (3)]));
                  (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)]));
              }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 57 "parser.y"
    {
                  destroy((yyvsp[(3) - (3)]));
                  (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)]));
              }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 64 "parser.y"
    {
                  destroy((yyvsp[(4) - (4)]));
                  (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->adopt_sym((yyvsp[(2) - (4)]), TOK_TYPEID);
                  (yyval) = (yyvsp[(1) - (4)])->adopt((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
              }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 70 "parser.y"
    {
                  destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
                  (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->adopt_sym((yyvsp[(2) - (4)]), TOK_TYPEID);
                  (yyval) = (yyvsp[(1) - (4)])->adopt((yyvsp[(2) - (4)]));
              }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 78 "parser.y"
    {
                  (yyvsp[(2) - (2)]) = (yyvsp[(2) - (2)])->adopt_sym((yyvsp[(2) - (2)]), TOK_FIELD);
                  (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));
              }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 83 "parser.y"
    {
                  (yyvsp[(3) - (3)]) = (yyvsp[(3) - (3)])->adopt_sym((yyvsp[(3) - (3)]), TOK_FIELD);
                  (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
              }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 89 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 90 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 91 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 92 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)])->adopt_sym((yyvsp[(1) - (1)]), TOK_TYPEID); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 97 "parser.y"
    {
                  (yyvsp[(1) - (2)]) = (yyvsp[(1) - (2)])->adopt_sym((yyvsp[(1) - (2)]), TOK_PARAMLIST);
                  (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));
              }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 102 "parser.y"
    {
                  destroy((yyvsp[(2) - (3)]));
                  (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(3) - (3)]));
              }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 109 "parser.y"
    {
                  destroy((yyvsp[(3) - (4)]));
                  (yyval) = new astree(TOK_FUNCTION, (yyvsp[(1) - (4)])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
                  (yyval) = (yyval)->adopt((yyvsp[(4) - (4)]));
              }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    {
                  destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
                  (yyval) = new astree(TOK_PROTOTYPE, (yyvsp[(1) - (4)])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
              }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 122 "parser.y"
    {
                  destroy((yyvsp[(3) - (4)]));
                  (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->adopt_sym((yyvsp[(2) - (4)]), TOK_PARAMLIST);
                  (yyval) = new astree(TOK_FUNCTION, (yyvsp[(1) - (4)])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
                  (yyval) = (yyval)->adopt((yyvsp[(4) - (4)]));
              }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 130 "parser.y"
    {
                  destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
                  (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->adopt_sym((yyvsp[(2) - (4)]), TOK_PARAMLIST);
                  (yyval) = new astree(TOK_PROTOTYPE, (yyvsp[(1) - (4)])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
              }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 139 "parser.y"
    {
                  (yyvsp[(2) - (2)]) = (yyvsp[(2) - (2)])->adopt_sym((yyvsp[(2) - (2)]), TOK_DECLID);
                  (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));
              }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 144 "parser.y"
    {
                  (yyvsp[(3) - (3)]) = (yyvsp[(3) - (3)])->adopt_sym((yyvsp[(3) - (3)]), TOK_DECLID);
                  (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
              }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 151 "parser.y"
    {
                  (yyvsp[(1) - (2)]) = (yyvsp[(1) - (2)])->adopt_sym((yyvsp[(1) - (2)]), TOK_BLOCK);
                  (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));
              }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    {
                  (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));
              }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    {
                  destroy((yyvsp[(2) - (2)]));
                  (yyval) = (yyvsp[(1) - (2)])->adopt_sym((yyvsp[(1) - (2)]), TOK_BLOCK);
              }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 167 "parser.y"
    {
                  destroy((yyvsp[(2) - (2)]));
                  (yyval) = (yyvsp[(1) - (2)])->adopt_sym((yyvsp[(1) - (2)]), TOK_BLOCK);
              }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 174 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 177 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 179 "parser.y"
    {
                  destroy((yyvsp[(2) - (2)]));
                  (yyval) = (yyvsp[(1) - (2)]);
              }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 187 "parser.y"
    {
                  destroy((yyvsp[(4) - (4)]));
                  (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->adopt_sym((yyvsp[(2) - (4)]), TOK_VARDECL);
                  (yyval) = (yyvsp[(2) - (4)])->adopt((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
              }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 195 "parser.y"
    {
                  destroy((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
                  (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
              }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 202 "parser.y"
    {
                  destroy((yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]));
                  (yyvsp[(1) - (7)])->adopt_sym((yyvsp[(1) - (7)]), TOK_IFELSE);
                  (yyval) = (yyvsp[(1) - (7)])->adopt((yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]));
                  (yyval) = (yyval)->adopt((yyvsp[(7) - (7)]));
              }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    {
                  destroy((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
                  (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
              }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 216 "parser.y"
    {
                  destroy((yyvsp[(2) - (2)]));
                  (yyval) = (yyvsp[(1) - (2)])->adopt_sym((yyvsp[(1) - (2)]), TOK_RETURNVOID);
              }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 221 "parser.y"
    {
                  destroy((yyvsp[(3) - (3)]));
                  (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)]));
              }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 227 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 228 "parser.y"
    { (yyval) = (yyval)->adopt((yyvsp[(2) - (2)])); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 229 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 230 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 232 "parser.y"
    {
                   destroy((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                   (yyval) = (yyvsp[(2) - (3)]);
              }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 236 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 237 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 240 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 241 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 242 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 243 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 244 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 245 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 246 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 247 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 248 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 249 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 250 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 253 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 254 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 255 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 256 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 260 "parser.y"
    {
                  destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
                  (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->adopt_sym((yyvsp[(2) - (4)]), TOK_TYPEID);
                  (yyval) = (yyvsp[(1) - (4)])->adopt((yyvsp[(2) - (4)]));
              }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 266 "parser.y"
    {
                  destroy((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
                  (yyvsp[(1) - (5)]) = (yyvsp[(1) - (5)])->adopt_sym((yyvsp[(1) - (5)]), TOK_NEWSTRING);
                  (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(4) - (5)]));
              }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 272 "parser.y"
    {
                  destroy((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
                  (yyvsp[(1) - (5)]) = (yyvsp[(1) - (5)])->adopt_sym((yyvsp[(1) - (5)]), TOK_NEWARRAY);
                  (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
              }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 280 "parser.y"
    {
                  (yyvsp[(2) - (3)]) = (yyvsp[(2) - (3)])->adopt_sym((yyvsp[(2) - (3)]), TOK_CALL);
                  (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
              }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 285 "parser.y"
    {
                  destroy((yyvsp[(2) - (3)]));
                  (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(3) - (3)]));
              }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 292 "parser.y"
    {
                  destroy((yyvsp[(2) - (2)]));
                  (yyval) = (yyvsp[(1) - (2)]);
              }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 297 "parser.y"
    {
                  destroy((yyvsp[(3) - (3)]));
                  (yyvsp[(2) - (3)]) = (yyvsp[(2) - (3)])->adopt_sym((yyvsp[(2) - (3)]), TOK_CALL);
                  (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]));
              }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 304 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 306 "parser.y"
    {
                  destroy((yyvsp[(4) - (4)]));
                  (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->adopt_sym((yyvsp[(2) - (4)]), TOK_INDEX);
                  (yyval) = (yyvsp[(2) - (4)])->adopt((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
              }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 312 "parser.y"
    {
                  (yyvsp[(3) - (3)]) = (yyvsp[(3) - (3)])->adopt_sym((yyvsp[(3) - (3)]), TOK_FIELD);
                  (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
              }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 318 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 319 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 320 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 321 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;


/* Line 1792 of yacc.c  */
#line 2190 "yyparse.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 324 "parser.y"


const char *parser::get_tname(int symbol) {
   return yytname [YYTRANSLATE(symbol)];
}

const char *get_yytname(int symbol) {
   return yytname [YYTRANSLATE(symbol)];
}


bool is_defined_token(int symbol) {
   return YYTRANSLATE(symbol) > YYUNDEFTOK;
}
