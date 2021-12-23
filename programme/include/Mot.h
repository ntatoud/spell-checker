#ifndef __MOT__
#define __MOT__
#include <stdlib.h>
#include <assert.h>


typedef struct Mot{
  char * chaine;
  unsigned int longueur; 
} Mot;


int M_estUnCaractereAlphabetique(char c);
void M_decalerVersLaDroite(Mot *unMot,unsigned int i);

int M_estUnMotValide(char *c);
Mot M_creerUnMot(char *c);
unsigned int M_longueurMot(Mot mot);
char M_iemeCaractere(Mot mot, unsigned int i);
int M_sontIdentiques(Mot mot1, Mot mot2);
void M_fixerIemeCaractere(Mot* unMot, unsigned int i, char c);
void M_fixerLongueur(Mot* unMot, unsigned int i);
void M_supprimerIemeLettre(Mot* unMot, unsigned int i);
void M_inverserDeuxLettresConsecutives(Mot* unMot, unsigned int i);
void M_insererLettre(Mot* unMot, unsigned int i, char c);
Mot M_decomposerMot(Mot* unMot, unsigned int i); //on modifie le mot et récupère le mot de sortie
void M_reduireLaCasse(Mot* unMot);

#endif