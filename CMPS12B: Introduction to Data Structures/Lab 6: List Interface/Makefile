#------------------------------------------------------------------------------
# Name: Juan D. Cardozo
# Cruz I.D: jcardozo
# Student I.D: 1362585
# 5/14/2015
#------------------------------------------------------------------------------

# Variables
SOURCES    = List.java ListInterface.java  ListTest.java ListClient.java\
             ListIndexOutOfBoundsException.java
MAINCLASS  = ListClient
CLASSES    = List.class ListInterface.class ListClient.class List\$$Node.class\
             ListIndexOutOfBoundsException.class
JARFILE    = ListClient

# Build Targets
all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(CLASSES)
	rm Manifest
	chmod +x $(JARFILE)

$(CLASSES): $(SOURCES)
	javac -Xlint:all,-serial $(SOURCES)  

clean:
	rm -f $(CLASSES) $(JARFILE) 

submit:
	submit cmps012b-pt.s15 lab6 $(SOURCES) Makefile README ListTest.java