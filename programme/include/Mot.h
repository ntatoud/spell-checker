#ifndef __MOT__
#define __MOT__
#include "EnsembleDeMot.h"

typedef struct Mot{
  char* chaine; 
  unsigned int longueur; 
} Mot;

int M_estUnMotValide(char c);
Mot M_creerUnMot(char c);
unsigned int M_longueurMot(Mot mot);
char M_iemeCaractere(Mot mot, unsigned int i);
int M_sontIdentiques(Mot mot1, Mot mot2);
void M_fixerIemeCaractere(Mot*, unsigned int, char);
void M_fixerLongueur(Mot*, unsigned int);


Mot CO_remplacerIemeLettre(Mot, unsigned int, char);
EnsembleDeMot CO_supprimerIemeLettre(Mot, unsigned int );
Mot CO_inverserDeuxLettresConsecutives(Mot, unsigned int );
EnsembleDeMot CO_insererLettre(Mot, unsigned int, char);
Mot CO_decomposerMot(Mot*, unsigned int); 
Mot CO_reduireLaCasse(Mot);


#endif
