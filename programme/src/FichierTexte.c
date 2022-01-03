#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "FichierTexte.h"
#define LONGUEUR_MAX_CHAINE 100
#define ID_DICO "DICO GROUPE DD"

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

char *FT_lireChaine(FichierTexte unFichier)
{
    assert(FT_estOuvert(unFichier) && (FT_obtenirMode(unFichier) == LECTURE) && !FT_estEnFinDeFichier(unFichier));

    char *buffer = (char *)malloc(sizeof(char) * LONGUEUR_MAX_CHAINE);
    if (fgets(buffer, LONGUEUR_MAX_CHAINE, unFichier.fichier))
    {
        return buffer;
    }
    else
    {
        free(buffer);
        return NULL;
    }
}

void FT_afficherContenuFichier(FichierTexte unFichier)
{
    FT_ouvrir(&unFichier, LECTURE);
    char *chaine;

    while (!FT_estEnFinDeFichier(unFichier))
    {
        chaine = FT_lireChaineSansLeRetourChariot(unFichier);
        if (strlen(chaine) > 0)
        {
            puts(chaine);
            free(chaine);
        }
    }

    FT_fermer(&unFichier);
}

void supprimerRetourChariot(char *chaine)
{
    int i = 0;
    while (chaine[i] != '\0')
    {
        if (chaine[i] == '\n')
        {
            chaine[i] = '\0';
        }
        i++;
    }
}

char *FT_lireChaineSansLeRetourChariot(FichierTexte unFichier)
{
    assert(FT_estOuvert(unFichier) && (FT_obtenirMode(unFichier) == LECTURE) && !FT_estEnFinDeFichier(unFichier));
    char *ligne;
    ligne = FT_lireChaine(unFichier);
    if (ligne != NULL)
    {
        supprimerRetourChariot(ligne);
        return ligne;
    }
    else
    {
        free(ligne);
        return "";
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

char *FT_lireElement(FichierTexte unFichier)
{
    char *element = malloc(4);
    element[0] = FT_lireCaractere(unFichier);
    element[1] = FT_lireCaractere(unFichier);
    element[2] = FT_lireCaractere(unFichier);
    element[3] = FT_lireCaractere(unFichier);
    return element;
}

int FT_verifierIdDico(FichierTexte unFichier)
{
    assert(FT_estOuvert(unFichier) && (FT_obtenirMode(unFichier) == LECTURE));
    char *id = FT_lireChaineSansLeRetourChariot(unFichier);
    int idCorrect = strcmp(id, ID_DICO);
    free(id);
    return (idCorrect == 0);
}
void FT_ecrireChaine(FichierTexte *unFichier, char *chaine)
{
    assert(FT_estOuvert(*unFichier) && (FT_obtenirMode(*unFichier) == ECRITURE));
    fputs(chaine, unFichier->fichier);
}

void FT_ecrireID(FichierTexte *unFichier)
{
    FT_ecrireChaine(unFichier, ID_DICO);
    FT_ecrireCaractere(unFichier, '\n');
}
