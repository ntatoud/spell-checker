#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "FichierTexte.h"
#define LONGUEUR_MAX_MOT 27

FichierTexte FT_fichierTexte(char *nomDuFichier)
{
    FichierTexte unFichier;
    unFichier.fichier = NULL;
    unFichier.nom = nomDuFichier;
    return unFichier;
}

void FT_ouvrir(FichierTexte *unFichier, Mode mode)
{
    assert(!FT_estOuvert(*unFichier));

    if (mode == ECRITURE)
    {
        unFichier->fichier = fopen(unFichier->nom, "w+");
        unFichier->mode = mode;
    }
    else if (mode == LECTURE)
    {
        unFichier->fichier = fopen(unFichier->nom, "r");
        unFichier->mode = mode;
    }
    else
        printf("ERREUR : Le mode choisi n'est pas le bon\n");
}

void FT_fermer(FichierTexte *unFichier)
{
    if (FT_estOuvert(*unFichier))
    {
        fclose(unFichier->fichier);
        unFichier->fichier = NULL;
    }
}

unsigned int FT_estOuvert(FichierTexte unFichier)
{
    return unFichier.fichier != NULL;
}

Mode FT_obtenirMode(FichierTexte unFichier)
{
    return unFichier.mode;
}

unsigned int FT_estEnFinDeFichier(FichierTexte unFichier)
{
    assert((unFichier.mode == LECTURE) && FT_estOuvert(unFichier));
    return feof(unFichier.fichier);
}
/*
void FT_ecrireChaine(FichierTexte *fichier, char *chaine)
{
    assert(FT_estOuvert(*fichier) && (FT_mode(*fichier) == ECRITURE));
    fputs(chaine, fichier->fichier);
}
*/
char *FT_lireChaine(FichierTexte unFichier)
{
    assert(FT_estOuvert(unFichier) && (FT_obtenirMode(unFichier) == LECTURE) && !FT_estEnFinDeFichier(unFichier));
    
    char* buffer = (char*)malloc(sizeof(char)*LONGUEUR_MAX_MOT);
    if(fgets(buffer, LONGUEUR_MAX_MOT, unFichier.fichier)){
        return buffer;
    }
    else{
        free(buffer);
        return NULL;
    }
}

void supprimerRetourChariot(char *chaine){
    int i = 0;
    while(chaine[i] != '\0'){
        if(chaine[i] == '\n'){
            chaine[i] = '\0';
        }
        i++;
    }
}

char* FT_lireChaineSansLeRetourChariot(FichierTexte unFichier){
    assert(FT_estOuvert(unFichier) && (FT_obtenirMode(unFichier) == LECTURE) && !FT_estEnFinDeFichier(unFichier));
    char* ligne;
    ligne = FT_lireChaine(unFichier);
    if(ligne != NULL){
        supprimerRetourChariot(ligne);
        return ligne;
    }
    else{
        return ""; //A voir
    }
}

void FT_ecrireCaractere(FichierTexte *unFichier, char lettre)
{
    assert(FT_estOuvert(*unFichier) && (FT_obtenirMode(*unFichier) == ECRITURE));
    fputc(lettre, unFichier->fichier);
}


char FT_lireCaractere(FichierTexte unFichier)
{
    assert(FT_estOuvert(unFichier) && (FT_obtenirMode(unFichier) == LECTURE) && !FT_estEnFinDeFichier(unFichier));
    return fgetc(unFichier.fichier);
}
