#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include "Mot.h"
#include "ListeChaineeDeMot.h"
#include "EnsembleDeMot.h"

/* Partie privee */
void EDM_ajouterElements(EnsembleDeMot motsAAjouter, EnsembleDeMot *edmACompleter)
{
    errno = 0;
    ListeChaineeDeMot l = LCDM_listeChaineeDeMot();
    l = motsAAjouter.lesMots;
    while (!LCDM_estVide(l))
    {
        EDM_ajouter(edmACompleter, LCDM_obtenirMot(l));
        l = LCDM_obtenirListeSuivante(l);
    }
}

/* Partie publique */
EnsembleDeMot ensembleDeMot()
{
    errno = 0;
    EnsembleDeMot unEDM;
    unEDM.lesMots = LCDM_listeChaineeDeMot();
    unEDM.nbMots = 0;
    return unEDM;
}

void EDM_vider(EnsembleDeMot *unEDM)
{
    errno = 0;
    unEDM->nbMots = 0;
    LCDM_supprimer(&unEDM->lesMots);
    *unEDM = ensembleDeMot();
}

EnsembleDeMot EDM_copier(EnsembleDeMot unEDM)
{
    EnsembleDeMot copieEDM = ensembleDeMot();
    copieEDM.nbMots = unEDM.nbMots;
    copieEDM.lesMots = LCDM_copier(unEDM.lesMots);
    return copieEDM;
}

int EDM_egale(EnsembleDeMot edm_1, EnsembleDeMot edm_2)
{
    errno = 0;
    int sontEgales = 0;
    if (EDM_cardinalite(edm_1) == EDM_cardinalite(edm_2))
    {
        sontEgales = LCDM_egale(edm_1.lesMots, edm_2.lesMots);
    }
    return sontEgales;
}

void EDM_ajouter(EnsembleDeMot *unEDM, Mot unMot)
{
    if (!EDM_estPresent(*unEDM, unMot))
    {
        LCDM_ajouter(&unEDM->lesMots, unMot);
        unEDM->nbMots = unEDM->nbMots + 1;
    }
    else
    {
        errno = LCDM_ERREUR_MEMOIRE;
    }
}

void EDM_retirer(EnsembleDeMot *unEDM, Mot unMot)
{
    errno = 0;
    if (EDM_estPresent(*unEDM, unMot))
    {
        LCDM_supprimerMot(&unEDM->lesMots, unMot);
        unEDM->nbMots--;
    }
}

int EDM_estPresentDansListe(ListeChaineeDeMot l, Mot unMot)
{
    errno = 0;
    if (LCDM_estVide(l))
    {
        return 0;
    }
    else
    {
        if (M_sontIdentiques(LCDM_obtenirMot(l), unMot))
        {
            return 1;
        }
        else
        {
            return EDM_estPresentDansListe(LCDM_obtenirListeSuivante(l), unMot);
        }
    }
}

int EDM_estPresent(EnsembleDeMot unEDM, Mot unMot)
{
    return EDM_estPresentDansListe(unEDM.lesMots, unMot);
}

long int EDM_cardinalite(EnsembleDeMot unEDM)
{
    errno = 0;
    return unEDM.nbMots;
}

EnsembleDeMot EDM_union(EnsembleDeMot edm_1, EnsembleDeMot edm_2)
{
    EnsembleDeMot unionEDM = ensembleDeMot();
    EDM_ajouterElements(edm_1, &unionEDM);
    EDM_ajouterElements(edm_2, &unionEDM);
    return unionEDM;
}

Mot EDM_obtenirMot(EnsembleDeMot unEDM)
{
    errno = 0;
    Mot leMot;
    ListeChaineeDeMot l = LCDM_listeChaineeDeMot();
    l = unEDM.lesMots;
    leMot = LCDM_obtenirMot(l);
    //free(l);
    return leMot;
}
