#ifndef __ARBRE_DE_LETTRES__
#define __ARBRE_DE_LETTRES__
#include <errno.h>

typedef struct ADL *ArbreDeLettres;

typedef struct ADL{
	ArbreDeLettres fils, frere;
	char* lettre;
	int estFinDeMot;
} ADL;

#define ADL_ERREUR_MEMOIRE 1

ArbreDeLettres ADL_creerADLVide(); 

/*!
 * Fonction qui permet de savoir si un arbre est vide ou non
 *\param[in] ListeChaineeDeMot la liste à tester
 *\param[out] int, 1 si la liste est vide, 0 sinon 
 */
int ADL_estVide(ArbreDeLettres);


ArbreDeLettres ADL_creerADL(ArbreDeLettres,ArbreDeLettres,char*,int);


void ADL_fixerEstFinDeMot(ArbreDeLettres*,int);
void ADL_fixerLettre(ArbreDeLettres*,char*);
void ADL_fixerElement(ArbreDeLettres*,char*,int);
void ADL_fixerFrere(ArbreDeLettres*,ArbreDeLettres);
void ADL_fixerFils(ArbreDeLettres*,ArbreDeLettres);
ArbreDeLettres ADL_obtenirFils(ArbreDeLettres);
ArbreDeLettres ADL_obtenirFrere(ArbreDeLettres);
char* ADL_obtenirLettre(ArbreDeLettres);
int ADL_obtenirEstFinDeMot(ArbreDeLettres);

#endif