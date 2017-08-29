#-----------------------------------------------------------------
# Name: Juan D. Cardozo 

# Student I.D: 1362585 

# Cruz I.D: jcardozo

# Class:  CMPS 12M

# Date: 04/08/2015

#-----------------------------------------------------------------

JAVASRC = Extrema.java
SOURCES = README Makefile $(JAVASRC)
MAINCLASS = Extrema
CLASSES = Extrema.class
JARFILE = Extrema
SUBMIT = submit cmps012b-pt.s15 pa1



all: $(JARFILE)
	

$(JARFILE): $(CLASSES)

	echo Main-class: $(MAINCLASS) > Manifest

	jar cvfm $(JARFILE) Manifest $(CLASSES)

	rm Manifest

	chmod +x $(JARFILE)



$(CLASSES): $(JAVASRC)

	javac -Xlint $(JAVASRC)



clean:

	rm $(CLASSES) $(JARFILE)



submit: $(SOURCES)

	$(SUBMIT) $(SOURCES)
