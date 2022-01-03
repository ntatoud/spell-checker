#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "CorrecteurOrthographique.h"
#include "Mot.h"
#include "EnsembleDeMot.h"
#include "Dictionnaire.h"

CorrecteurOrthographique CO_correcteur(Dictionnaire unDico, Mot unMotFaux)
{
    assert(!D_estUnMotDuDictionnaire(unDico, M_copierMot(unMotFaux)));
    CorrecteurOrthographique unCorrecteur;
    unCorrecteur.leDictionnaire = unDico;
    unCorrecteur.motACorriger = M_copierMot(unMotFaux);
    unCorrecteur.lesCorrections = ensembleDeMot();
    return unCorrecteur;
}

Mot CO_obtenirMotACorriger(CorrecteurOrthographique unCorrecteur)
{
    return unCorrecteur.motACorriger;
}

Dictionnaire CO_obtenirDictionnaire(CorrecteurOrthographique unCorrecteur)
{
    return unCorrecteur.leDictionnaire;
}

EnsembleDeMot CO_obtenirCorrections(CorrecteurOrthographique unCorrecteur)
{
    return unCorrecteur.lesCorrections;
}

void CO_fixerDico(CorrecteurOrthographique *unCorrecteur, Dictionnaire unDico)
{
    unCorrecteur->leDictionnaire = unDico;
}

void CO_fixerMotACorriger(CorrecteurOrthographique *unCorrecteur, Mot unMotFaux)
{
    assert(!D_estUnMotDuDictionnaire(CO_obtenirDictionnaire(*unCorrecteur), unMotFaux));
    unCorrecteur->motACorriger = unMotFaux;
}

void CO_ajouterNouvellesCorrections(CorrecteurOrthographique *unCorrecteur, EnsembleDeMot desCorrections)
{
    EnsembleDeMot temp = unCorrecteur->lesCorrections;
    unCorrecteur->lesCorrections = EDM_union(desCorrections, temp);
    EDM_vider(&temp);
}

void CO_trouverCorrectionsPossibles(CorrecteurOrthographique *unCorrecteur)
{
    CO_strategieRemplacerLettres(unCorrecteur);
    CO_strategieSupprimerLettres(unCorrecteur);
    CO_strategieInsererLettres(unCorrecteur);
    CO_strategieInverserDeuxLettresConsecutives(unCorrecteur);
    CO_strategieDecomposerMot(unCorrecteur);
}

EnsembleDeMot CO_remplacerIemeLettreEnBoucle(Mot motACorriger, int i)
{
    EnsembleDeMot desCorrections;
    Mot uneCorrection;
    desCorrections = ensembleDeMot();
    char *lettres;
    lettres = "abcdefghijklmnopqrstuvwxyzàéèëùûêîïçôö-";
    for (int j = 0; j < strlen(lettres); j++)
    {
        uneCorrection = M_copierMot(motACorriger);
        M_fixerIemeCaractere(&uneCorrection, i, lettres[j]);
        EDM_ajouter(&desCorrections, uneCorrection);
    }
    return desCorrections;
}

void CO_strategieRemplacerLettres(CorrecteurOrthographique *unCorrecteur)
{
    unsigned int i, longueur;
    Mot uneCorrection;

    Mot leMotACorriger = CO_obtenirMotACorriger(*unCorrecteur);
    Dictionnaire leDico = CO_obtenirDictionnaire(*unCorrecteur);
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();
    EnsembleDeMot correctionsCourantes = ensembleDeMot();
    for (i = 1; i < longueur + 1; i++)
    {
        correctionsCourantes = CO_remplacerIemeLettreEnBoucle(leMotACorriger, i);

        while (EDM_cardinalite(correctionsCourantes) != 0)
        {
            uneCorrection = EDM_obtenirMot(correctionsCourantes);
            EDM_retirer(&correctionsCourantes, uneCorrection);
            if (D_estUnMotDuDictionnaire(leDico, M_copierMot(uneCorrection)) && !EDM_estPresent(desCorrections, uneCorrection))
                EDM_ajouter(&desCorrections, uneCorrection);
            else
                M_supprimerMot(&uneCorrection);
        }
        CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);

        EDM_vider(&correctionsCourantes);
        EDM_vider(&desCorrections);
    }
}

void CO_strategieSupprimerLettres(CorrecteurOrthographique *unCorrecteur)
{
    unsigned int i, longueur;
    Mot uneCorrection;

    Mot leMotACorriger = CO_obtenirMotACorriger(*unCorrecteur);
    Dictionnaire leDico = CO_obtenirDictionnaire(*unCorrecteur);
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();

    for (i = 1; i < longueur; i++)
    {
        uneCorrection = M_copierMot(leMotACorriger);
        M_supprimerIemeLettre(&uneCorrection, i);
        if (D_estUnMotDuDictionnaire(leDico, M_copierMot(uneCorrection)) && !EDM_estPresent(desCorrections, uneCorrection))
            EDM_ajouter(&desCorrections, uneCorrection);
        else
            M_supprimerMot(&uneCorrection);
    }
    CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);
    EDM_vider(&desCorrections);
}

void CO_strategieInverserDeuxLettresConsecutives(CorrecteurOrthographique *unCorrecteur)
{
    unsigned int i, longueur;
    Mot uneCorrection;

    Mot leMotACorriger = CO_obtenirMotACorriger(*unCorrecteur);
    Dictionnaire leDico = CO_obtenirDictionnaire(*unCorrecteur);
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();

    for (i = 1; i < longueur - 1; i++)
    {
        uneCorrection = M_copierMot(leMotACorriger);
        M_inverserDeuxLettresConsecutives(&uneCorrection, i);
        if (D_estUnMotDuDictionnaire(leDico, M_copierMot(uneCorrection)) && !EDM_estPresent(desCorrections, uneCorrection))
            EDM_ajouter(&desCorrections, uneCorrection);
        else
        {
            M_supprimerMot(&uneCorrection);
        }
    }
    CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);
    EDM_vider(&desCorrections);
}

EnsembleDeMot CO_insererIemeLettreEnBoucle(Mot motACorriger, int i)
{
    EnsembleDeMot desCorrections;
    Mot uneCorrection;
    desCorrections = ensembleDeMot();
    char *lettres;
    lettres = "abcdefghijklmnopqrstuvwxyzàéèëùûêîïçôö-";
    for (int j = 0; j < strlen(lettres); j++)
    {
        uneCorrection = M_copierMot(motACorriger);
        M_insererLettre(&uneCorrection, i, lettres[j]);
        EDM_ajouter(&desCorrections, uneCorrection);
    }
    return desCorrections;
}

void CO_strategieInsererLettres(CorrecteurOrthographique *unCorrecteur)
{
    unsigned int i, longueur;
    Mot uneCorrection;

    Mot leMotACorriger = CO_obtenirMotACorriger(*unCorrecteur);
    Dictionnaire leDico = CO_obtenirDictionnaire(*unCorrecteur);
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();
    EnsembleDeMot correctionsCourantes = ensembleDeMot();
    for (i = 1; i <= longueur + 1; i++)
    {
        correctionsCourantes = CO_insererIemeLettreEnBoucle(leMotACorriger, i);

        while (EDM_cardinalite(correctionsCourantes) != 0)
        {
            uneCorrection = EDM_obtenirMot(correctionsCourantes);
            EDM_retirer(&correctionsCourantes, uneCorrection);
            if (D_estUnMotDuDictionnaire(leDico, M_copierMot(uneCorrection)) && !EDM_estPresent(desCorrections, uneCorrection))
                EDM_ajouter(&desCorrections, uneCorrection);
            else
                M_supprimerMot(&uneCorrection);
        }
        CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);

        EDM_vider(&correctionsCourantes);
        EDM_vider(&desCorrections);
    }
}

void CO_strategieDecomposerMot(CorrecteurOrthographique *unCorrecteur)
{
    unsigned int i, longueur;
    Mot leMotACorriger = CO_obtenirMotACorriger(*unCorrecteur);
    Mot uneCorrection;
    Mot unMotModifiable;
    Dictionnaire leDico = CO_obtenirDictionnaire(*unCorrecteur);
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();

    for (i = 2; i < longueur + 1; i++)
    {
        unMotModifiable = M_copierMot(leMotACorriger);
        uneCorrection = M_decomposerMot(&unMotModifiable, i);
        if (D_estUnMotDuDictionnaire(leDico, M_copierMot(uneCorrection)) && D_estUnMotDuDictionnaire(leDico, M_copierMot(unMotModifiable)) && !EDM_estPresent(desCorrections, unMotModifiable) && !EDM_estPresent(desCorrections, uneCorrection))
        {
            EDM_ajouter(&desCorrections, uneCorrection);
            EDM_ajouter(&desCorrections, unMotModifiable);
        }
        else
        {
            M_supprimerMot(&uneCorrection);
            M_supprimerMot(&unMotModifiable);
        }
    }
    CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);
    EDM_vider(&desCorrections);
}

void CO_supprimerCorrecteur(CorrecteurOrthographique *unCorrecteur)
{
    Mot unMot;
    M_supprimerMot(&unCorrecteur->motACorriger);

    while (EDM_cardinalite(unCorrecteur->lesCorrections) != 0)
    {
        unMot = EDM_obtenirMot(unCorrecteur->lesCorrections);
        EDM_retirer(&unCorrecteur->lesCorrections, unMot);
        M_supprimerMot(&unMot);
    }

    ADL_supprimer(&unCorrecteur->leDictionnaire);
}