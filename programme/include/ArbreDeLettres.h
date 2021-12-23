#ifndef __ARBRE_DE_LETTRES__
#define __ARBRE_DE_LETTRES__
#include <errno.h>

typedef struct ADL *ArbreDeLettres;

typedef struct ADL{
	ArbreDeLettres fils, frere;
	char lettre;
	int estFinDeMot;
} ADL;

#define ADL_ERREUR_MEMOIRE 1

ArbreDeLettres ADL_creerADLVide(); 
int ADL_estVide(ArbreDeLettres);
ArbreDeLettres ADL_creerADL(ArbreDeLettres,ArbreDeLettres,char,int);
void ADL_fixerEstFinDeMot(ArbreDeLettres*,int);//non estVide(adl)
void ADL_fixerLettre(ArbreDeLettres*,char);//non estVide(adl)
void ADL_fixerElement(ArbreDeLettres*,char,int);
void ADL_fixerFrere(ArbreDeLettres*,ArbreDeLettres);//non estVide(adl)
void ADL_fixerFils(ArbreDeLettres*,ArbreDeLettres);//non estVide(adl)
ArbreDeLettres ADL_obtenirFils(ArbreDeLettres); //non estVide(adl)
ArbreDeLettres ADL_obtenirFrere(ArbreDeLettres);//non estVide(adl)
char ADL_obtenirLettre(ArbreDeLettres);//non estVide(adl)
int ADL_obtenirEstFinDeMot(ArbreDeLettres);//non estVide(adl)

#endif