#ifndef _FICHIER_TEXTE__
#define _FICHIER_TEXTE__
#include <stdio.h>
typedef enum {LECTURE, ECRITURE} Mode;

typedef struct Fichier {
	FILE* file;
	char* nom;
	Mode mode;
} Fichier;


void ouvrir(Fichier *fichier, Mode mode);
void fermer(Fichier *fichier);
unsigned int estOuvert(Fichier fichier);
Mode FichierTexte_mode(Fichier fichier);
unsigned int finFichier(Fichier fichier);
void ecrireChaine(Fichier *fichier, char* chaine);
char* lireChaine(Fichier fichier);
void ecrireCaractere(Fichier *fichier, char caractere);
char lireCaractere(Fichier fichier);
#endif




