SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
DOCDIR=doc
TESTS = $(TESTDIR)/testEDM $(TESTDIR)/testLCDM $(TESTDIR)/testArbreDeLettres $(TESTDIR)/testMot $(TESTDIR)/testDictionnaire $(TESTDIR)/testCO
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=c99 -I$(INCLUDEDIR) -fexec-charset=ISO8859-1
LDFLAGS=  -lCorrecteurOrthographique -lFichierTexte -lDictionnaire -lEnsembleDeMot -lListeChaineeDeMot  -lArbreDeLettres -lIHM -lCorrigerTexte -lMot  -lm -lcurses
EXEC= correcteur
LIBRARY= $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libCorrecteurOrthographique.a $(LIBDIR)/libFichierTexte.a  $(LIBDIR)/libListeChaineeDeMot.a $(LIBDIR)/libEnsembleDeMot.a $(LIBDIR)/libArbreDeLettres.a $(LIBDIR)/libIHM.a $(LIBDIR)/libCorrigerTexte.a $(LIBDIR)/libMot.a 
CORRECTEUR= $(SRCDIR)/main.o

all :  $(BINDIR)/$(EXEC)

doc : .PHONY
	doxygen Doxyfile
	
proper : clean all

tests : $(TESTS)

$(TESTDIR)/testEDM : $(SRCDIR)/testEDM.o $(LIBDIR)/libEnsembleDeMot.a $(LIBDIR)/libListeChaineeDeMot.a $(LIBDIR)/libMot.a
	$(CC)  -o $@ $< -lEnsembleDeMot -lListeChaineeDeMot -lMot -lcunit -L $(LIBDIR)

$(TESTDIR)/testLCDM : $(SRCDIR)/testLCDM.o $(LIBDIR)/libMot.a $(LIBDIR)/libListeChaineeDeMot.a
	$(CC) -o $@  $< -lListeChaineeDeMot -lMot -lcunit -L $(LIBDIR)

$(TESTDIR)/testArbreDeLettres : $(SRCDIR)/testArbreDeLettres.o $(LIBDIR)/libMot.a $(LIBDIR)/libArbreDeLettres.a
	$(CC) -o $@  $< -lArbreDeLettres -lMot -lcunit -L $(LIBDIR)

$(TESTDIR)/testMot : $(SRCDIR)/testMot.o $(LIBDIR)/libMot.a
	$(CC) -o $@  $< -lMot -lcunit -L $(LIBDIR)

$(TESTDIR)/testDictionnaire : $(SRCDIR)/testDictionnaire.o $(LIBDIR)/libMot.a $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libFichierTexte.a
	$(CC) -o $@  $< -lDictionnaire -lArbreDeLettres -lFichierTexte -lMot  -lcunit -L $(LIBDIR)

$(TESTDIR)/testCO: $(SRCDIR)/testCO.o $(LIBDIR)/libMot.a $(LIBDIR)/libCorrecteurOrthographique.a
	$(CC) -o $@  $< -lCorrecteurOrthographique -lDictionnaire -lArbreDeLettres -lFichierTexte -lEnsembleDeMot -lListeChaineeDeMot -lMot  -lcunit -L $(LIBDIR)

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBRARY) $(CORRECTEUR)
	$(CC) -o $@ $^ $(LDFLAGS) -L $(LIBDIR)

$(TESTDIR)/tests : $(SRCDIR)/tests.o $(LIBRARY)
	$(CC) -o $@ $^ $(LDFLAGS) -L $(LIBDIR) -lcunit

$(SRCDIR)/%.o : $(SRCDIR)/%.c $
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

$(LIBDIR)/libIHM.a : $(SRCDIR)/IHM.o
	$(AR) -r $@ $^

$(LIBDIR)/libCorrigerTexte.a : $(SRCDIR)/corrigerTexte.o
	$(AR) -r $@ $^

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
