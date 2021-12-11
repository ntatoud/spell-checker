SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=c99 -I$(INCLUDEDIR)
LDFLAGS=-lMot -lCorrecteurOrthographique -lFichierTexte -lDictionnaire -lm -lcurses
EXEC=correcteur
LIBRARY=$(LIBDIR)/libMot.a  $(LIBDIR)/libCorrecteurOrthographique.a $(LIBDIR)/libFichierTexte.a $(LIBDIR)/libDictionnaire.a
#CORRECTEUR=$(SRCDIR)/chargerDico.o $(SRCDIR)/corrigerDico.o $(SRCDIR)/corrigerTexte.o $(SRCDIR)/sauvegarderArbreEnDictionnaire.o

all :  $(BINDIR)#/$(EXEC)

doc : .PHONY
	doxygen Doxyfile
	
proper : clean all

tests : $(TESTDIR)/tests

#$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBRARY) $(CORRECTEUR)
#	$(CC) -o $@ $^ $(LDFLAGS) -L $(LIBDIR)

$(TESTDIR)/tests : $(SRCDIR)/tests.o $(LIBRARY)
	$(CC) -o $@ $^ $(LDFLAGS) -L $(LIBDIR) -lcunit

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(LIBDIR)/libMot.a : $(SRCDIR)/Mot.o
	$(AR) -r $@ $^

$(LIBDIR)/libCorrecteurOrthographique.a : $(SRCDIR)/CorrecteurOrthographique.o
	$(AR) -r $@ $^

$(LIBDIR)/libFichierTexte.a : $(SRCDIR)/FichierTexte.o
	$(AR) -r $@ $^

$(LIBDIR)/libDictionnaire.a : $(SRCDIR)/Dictionnaire.o
	$(AR) -r $@ $^
	
clean clear :
	rm -rf $(BINDIR)/correcteur
	
	rm -rf $(LIBDIR)/*
	touch $(LIBDIR)/.gitkeep
	
	rm -rf $(SRCDIR)/*.o
	
	rm -rf $(TESTDIR)/*
	touch $(TESTDIR)/.gitkeep

cleanO :
	rm -rf $(SRCDIR)/*.o
	rm -rf $(LIBDIR)/*.a

.PHONY :
