#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__
#include <stdio.h>
#include "EnsembleDeMot.h"
#include "FichierTexte.h"
#include "ArbreDeLettres.h"

typedef FichierTexte Dictionnaire;

ArbreDeLettres genererArbreAvecEnsembleDeMots(EnsembleDeMot);
int estUnMotDuDictionnaire(ArbreDeLettres,Mot);
ArbreDeLettres chargerDico(Dictionnaire);
Dictionnaire sauvegarderArbreEnDictionnaire(ArbreDeLettres);

#endif