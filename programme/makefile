SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
DOCDIR=doc
TESTS = $(TESTDIR)/testEDM $(TESTDIR)/testLCDM $(TESTDIR)/testArbreDeLettres
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=c99 -I$(INCLUDEDIR)
LDFLAGS=-lMot -lCorrecteurOrthographique -lFichierTexte -lDictionnaire -lListeChaineeDeMot -lEnsembleDeMot -lm -lcurses
EXEC=correcteur
LIBRARY=$(LIBDIR)/libMot.a  $(LIBDIR)/libCorrecteurOrthographique.a $(LIBDIR)/libFichierTexte.a $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libListeChaineeDeMot.a $(LIBDIR)/libEnsembleDeMot.a $(LIBDIR)/libArbreDeLettres.a
CORRECTEUR=$(SRCDIR)/chargerDico.o $(SRCDIR)/corrigerDico.o $(SRCDIR)/main.o

all :  $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBRARY) $(CORRECTEUR)
	$(CC) -o $@ $^ $(LDFLAGS) -L $(LIBDIR)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(LIBDIR)/libMot.a : $(SRCDIR)/Mot.o
	$(AR) -r $@ $^

$(LIBDIR)/libListeChaineeDeMot.a : $(SRCDIR)/ListeChaineeDeMot.o
	$(AR) -r $@ $^

$(LIBDIR)/libEnsembleDeMot.a : $(SRCDIR)/EnsembleDeMot.o
	$(AR) -r $@ $^
	
$(LIBDIR)/libArbreDeLettres.a : $(SRCDIR)/ArbreDeLettres.o
	$(AR) -r $@ $^

$(LIBDIR)/libCorrecteurOrthographique.a : $(SRCDIR)/CorrecteurOrthographique.o
	$(AR) -r $@ $^

$(LIBDIR)/libFichierTexte.a : $(SRCDIR)/FichierTexte.o
	$(AR) -r $@ $^

$(LIBDIR)/libDictionnaire.a : $(SRCDIR)/Dictionnaire.o
	$(AR) -r $@ $^
	
tests : $(TESTS)
$(TESTDIR)/testEDM : $(SRCDIR)/testEDM.o $(LIBDIR)/libEnsembleDeMot.a $(LIBDIR)/libListeChaineeDeMot.a $(LIBDIR)/libMot.a
	$(CC)  -o $@ $< -lEnsembleDeMot -lListeChaineeDeMot -lMot -lcunit -L $(LIBDIR)

$(TESTDIR)/testLCDM : $(SRCDIR)/testLCDM.o $(LIBDIR)/libMot.a $(LIBDIR)/libListeChaineeDeMot.a
	$(CC) -o $@  $< -lListeChaineeDeMot -lMot -lcunit -L $(LIBDIR)

$(TESTDIR)/testArbreDeLettres : $(SRCDIR)/testArbreDeLettres.o $(LIBDIR)/libMot.a $(LIBDIR)/libArbreDeLettres.a
	$(CC) -o $@  $< -lArbreDeLettres -lMot -lcunit -L $(LIBDIR)

doc : .PHONY
	doxygen Doxyfile
	
proper : clean all

clean clear :
	rm -rf $(BINDIR)/correcteur
	
	rm -rf $(LIBDIR)/*
	touch $(LIBDIR)/.gitkeep
	
	rm -rf $(SRCDIR)/*.o
	
	rm -rf $(TESTDIR)/*
	touch $(TESTDIR)/.gitkeep

	rm -rf $(DOCDIR)/*

cleanO :
	rm -rf $(SRCDIR)/*.o
	rm -rf $(LIBDIR)/*.a

.PHONY :
