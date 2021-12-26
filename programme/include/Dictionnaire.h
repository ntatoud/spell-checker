#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__
#include <stdio.h>
#include "EnsembleDeMot.h"
#include "FichierTexte.h"
#include "ArbreDeLettres.h"


typedef ArbreDeLettres Dictionnaire;

Dictionnaire genererArbreAvecEnsembleDeMots(EnsembleDeMot);
int estUnMotDuDictionnaire(Dictionnaire,Mot);
Dictionnaire chargerDico(FILE*);
FILE* sauvegarderArbreEnDictionnaire(Dictionnaire);

#endif