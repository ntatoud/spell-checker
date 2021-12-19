#ifndef __MOT__
#define __MOT__

typedef struct Mot{
  char* chaine; 
  unsigned int longueur; 
} Mot;

#include "EnsembleDeMot.h"

int M_estUnMotValide(char c);
Mot M_creerUnMot(char c);
unsigned int M_longueurMot(Mot mot);
char M_iemeCaractere(Mot mot, unsigned int i);
int M_sontIdentiques(Mot mot1, Mot mot2);
void M_fixerIemeCaractere(Mot*, unsigned int, char);
void M_fixerLongueur(Mot*, unsigned int);
EnsembleDeMot M_remplacerIemeLettre(Mot, unsigned int);
Mot M_supprimerIemeLettre(Mot, unsigned int );
Mot M_inverserDeuxLettresConsecutives(Mot, unsigned int);
EnsembleDeMot M_insererLettre(Mot, unsigned int);
Mot M_decomposerMot(Mot*, unsigned int); 
Mot M_reduireLaCasse(Mot);

#endif
