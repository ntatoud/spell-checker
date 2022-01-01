#ifndef __IHM__
#define __IHM__
#include <stdio.h>

char* lireChaineEntreeStandard();

void afficherAide();

void gererCommandeAide(char *commande);

void gererCommandeCreerDico(char *commande1, char *fichier1, char *commande2, char *fichier2);

void gererCommandeCorrection(char *commande, char *fichier);

#endif