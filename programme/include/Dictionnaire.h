#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__
#include <stdio.h>
#include "EnsembleDeMot.h"
#include "FichierTexte.h"
#include "ArbreDeLettres.h"
#include "Mot.h"


/* Partie privée */

typedef ArbreDeLettres Dictionnaire;

void D_insererMot(Dictionnaire*, Mot);
void D_insererLettre(Dictionnaire*, char, int);
int D_lettreEstRacine(Dictionnaire, char);

Mot* supprimerLesMots(Mot *lesMots, int nbMots);
void supprimerTabMots(Mot **lesMots, int nbMots);


Mot* D_genererTableauDeMotAvecFichierTexte(FichierTexte ficDico, int* nbMots);
Dictionnaire D_genererArbreAvecTableauDeMots(Mot* lesMots, int nbMots);

/* Partie publique */
Dictionnaire D_genererArbreAvecFichierTexte(FichierTexte ficDico);

int D_estUnMotDuDictionnaire(Dictionnaire,Mot);
Dictionnaire D_chargerDico(FichierTexte);
FichierTexte D_sauvegarderArbreEnFichierTexte(Dictionnaire);


#endif