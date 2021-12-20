#ifndef __MOT__
#define __MOT__
#include "EnsembleDeMot.h"
#include <wchar.h>

typedef struct Mot{
  wchar_t * chaine; 
  unsigned int longueur; 
} Mot;
                                    //exemple : wchar_t p = L"Hello" ;
int M_estUnMotValide(wchar_t *);
Mot M_creerUnMot(wchar_t *);
unsigned int M_longueurMot(Mot);
wchar_t M_iemeCaractere(Mot, unsigned int);
int M_sontIdentiques(Mot, Mot);
Mot M_fixerIemeCaractere(Mot, unsigned int, wchar_t);
Mot M_fixerLongueur(Mot, unsigned int);

Mot M_supprimerIemeLettre(Mot, unsigned int );
Mot M_inverserDeuxLettresConsecutives(Mot, unsigned int );
Mot M_insererLettre(Mot, unsigned int, wchar_t);
Mot M_decomposerMot(Mot*, unsigned int); //on modifie le mot et récupère le mot de sortie
Mot M_reduireLaCasse(Mot);


#endif