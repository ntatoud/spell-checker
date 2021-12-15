#ifndef _FICHIER_TEXTE__
#define _FICHIER_TEXTE__
#include <stdio.h>
#include "Mot.h"

typedef enum {lecture=0, ecriture=1} F_Mode;

typedef struct {
	FILE* fb;
	char* nom;
	unsigned int longueur;
} FichierTexte;

FichierTexte F_InitFichier(char *nom, F_Mode mode, int *status);
Mot F_LireMot(FichierTexte fichier, int *status);
void F_EcrireMot(FichierTexte fichier,Mot unMot, int *status);
FILE *F_OuvrirFichier(char *nom, F_Mode mode, int *status);
void F_FermerFichier(FichierTexte fichier, int *status);

#endif