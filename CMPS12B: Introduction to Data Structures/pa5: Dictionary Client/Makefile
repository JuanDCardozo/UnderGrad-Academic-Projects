#------------------------------------------------------------------------------
# Makefile for DictionaryClient.c with macros
#------------------------------------------------------------------------------

FLAGS   = -std=c99 -Wall
SOURCES = Dictionary.c  DictionaryClient.c DictionaryTest.c
OBJECTS = Dictionary.o DictionaryClient.o
HEADERS = Dictionary.h
EXEBIN  = DictionaryClient

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS) $(HEADERS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES) $(HEADERS)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)

check:
	valgrind --leak-check=full $(EXEBIN)

submit:
	submit cmps012b-pt.s15 pa5 $(SOURCES) $(HEADERS) Makefile README