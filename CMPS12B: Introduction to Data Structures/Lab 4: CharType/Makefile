# Name: Juan D. Cardozo
# Student I.D: 1362585
# Cruz I.D: jcardozo
# Section: Mondays 6-8
# Lab 4
# Makefile

FLAGS = -std=c99 -Wall
SOURCES = charType.c
EXTRA =  README Makefile
OBJECTS = charType.o
EXEBIN =  charType
SUBMIT = submit cmps012b-pt.s15 lab4

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean:
	rm -f $(EXEBIN) $(OBJECTS)

submit: $(SOURCES)
	$(SUBMIT) $(SOURCES) $(EXTRA)

check: $(SOURCES)
	valgrind --leak-check=full charType charType.c out