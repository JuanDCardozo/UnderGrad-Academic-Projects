MKFILE    = Makefile
DEPSFILE  = ${MKFILE}.deps
NOINCLUDE = ci clean spotless
NEEDINCL  = ${filter ${NOINCLUDE}, ${MAKECMDGOALS}}
VALGRIND  = valgrind --leak-check=full --show-reachable=yes

#
# Definitions of list of files:
#
HSOURCES  = symtab.h astree.h lyutils.h auxlib.h stringset.h oilhelper.h
CSOURCES2 = stringset.cpp oilhelper.cpp main.cpp
CSOURCES  = symtab.cpp astree.cpp lyutils.cpp auxlib.cpp ${CSOURCES2} 
LSOURCES  = scanner.l
YSOURCES  = parser.y
ETCSRC    = README ${MKFILE}
CLGEN     = yylex.cpp
HYGEN     = yyparse.h
CYGEN     = yyparse.cpp
CGENS     = ${CLGEN} ${CYGEN}
ALLGENS   = ${HYGEN} ${CGENS}
EXECBIN   = oc
ALLCSRC   = ${CSOURCES} ${CGENS}
OBJECTS   = ${ALLCSRC:.cpp=.o}
LREPORT   = yylex.output
YREPORT   = yyparse.output
REPORTS   = ${LREPORT} ${YREPORT}
ALLSRC    = ${ETCSRC} ${YSOURCES} ${LSOURCES} ${HSOURCES} ${CSOURCES}
CLASS       = cmps104a-wm.s17
PROJECT     = asg5

#
# Definitions of the compiler and compilation options:
#
GCC       = g++ -g -O0 -Wall -Wextra -std=gnu++14
MKDEPS    = g++ -MM -std=gnu++14

all : ${EXECBIN}
	- checksource ${ALLSRC}

${EXECBIN} : ${OBJECTS}
	${GCC} -o${EXECBIN} ${OBJECTS}

%.o : %.cpp
	${GCC} -c $<



${CLGEN} : ${LSOURCES}
	flex --outfile=${CLGEN} ${LSOURCES} 2>${LREPORT}
	- grep -v '^  ' ${LREPORT}

${CYGEN} ${HYGEN} : ${YSOURCES}
	bison --defines=${HYGEN} --output=${CYGEN} ${YSOURCES}

ci : ${ALLSRC}
	- checksource ${ALLSRC}
	cid + ${ALLSRC}

clean :
	- rm ${OBJECTS} ${ALLGENS} ${REPORTS}

spotless : clean
	- rm ${EXECBIN}

submit : ${ALLSRC}
	- checksource ${ALLSRC}
	submit ${CLASS} ${PROJECT} ${ALLSRC}

deps : ${ALLCSRC}
	@ echo "# ${DEPSFILE} created `date` by ${MAKE}" >${DEPSFILE}
	${MKDEPS} ${ALLCSRC} >>${DEPSFILE}

${DEPSFILE} :
	@ touch ${DEPSFILE}
	${MAKE} --no-print-directory deps

again :
	gmake --no-print-directory spotless deps ci all lis

ifeq "${NEEDINCL}" ""
include ${DEPSFILE}
endif
