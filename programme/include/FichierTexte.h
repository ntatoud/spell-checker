#ifndef _FICHIER_TEXTE__
#define _FICHIER_TEXTE__
#include <stdio.h>
typedef enum {LECTURE, ECRITURE} Mode;


/* Partie privée */
typedef struct FichierTexte {
	FILE* fichier;
	char* nom;
	Mode mode;
} FichierTexte;

void supprimerRetourChariot(char *);

/* Partie publique */
FichierTexte FT_fichierTexte(char *nomDuFichier);
void FT_ouvrir(FichierTexte *fichier, Mode mode);
void FT_fermer(FichierTexte *fichier);
unsigned int FT_estOuvert(FichierTexte fichier);
Mode FT_obtenirMode(FichierTexte fichier);
unsigned int FT_estEnFinDeFichier(FichierTexte fichier);
void FT_ecrireChaine(FichierTexte *fichier, char* chaine);
char* FT_lireChaineSansLeRetourChariot(FichierTexte fichier);
char* FT_lireChaine(FichierTexte fichier);

void FT_ecrireCaractere(FichierTexte *fichier, char caractere);
char FT_lireCaractere(FichierTexte fichier);

#endif