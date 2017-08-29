GPP      = g++ -std=gnu++14 -g -O0 -Wall -Wextra
MKDEP    = g++ -std=gnu++14 -MM
VALGRIND   = valgrind --leak-check=full --show-reachable=yes

MKFILE   = Makefile
DEPFILE  = Makefile.dep
SOURCES  = astree.cpp auxlib.cpp lyutils.cpp main.cpp stringset.cpp
HEADERS  = astree.h  lyutils.h  auxlib.h  stringset.h
OBJECTS  = ${SOURCES:.cpp=.o}
EXECBIN  = oc
SRCFILES = ${HEADERS} ${SOURCES} ${MKFILE}
YSOURCES = parser.y
LSOURCES = scanner.l
CLGEN = yylex.cpp
HYGEN = yyparse.h
CYGEN = yyparse.cpp
LREPORT = yylex.output
YREPORT = yyparse.output

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${GPP} ${OBJECTS} -o ${EXECBIN}

%.o : %.cpp
	${GPP} -c $<

${CLGEN} : ${LSOURCES}
			flex --outfile=${CLGEN} ${LSOURCES}

${CYGEN} ${HYGEN} : ${YSOURCES}
			bison --defines=${HYGEN} --output=${CYGEN} ${YSOURCES}

ci :
	git commit -m "$m" + ${SRCFILES}

clean :
	-rm ${OBJECTS} ${DEPFILE}

spotless : clean
	- rm ${EXECBIN}

${DEPFILE} :
	${MKDEP} ${SOURCES} >${DEPFILE}

dep :
	- rm ${DEPFILE}
	${MAKE} --no-print-directory ${DEPFILE}

include ${DEPFILE}

again : ${SRCFILES}
	make --no-print-directory spotless dep ci

submit:
		submit cmps104a-wm.s17 asg2 Makefile README Makefile.dep ${SOURCES}\
		 ${HEADERS} parser.y scanner.l yyparse.cpp yyparse.h

test: ${EXECBIN}
		/afs/cats.ucsc.edu/courses/cmps104a-wm/Assignments/\
		grading/mk.tests
