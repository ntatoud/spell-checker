#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Mot.h"
#include "CorrecteurOrthographique.h"
#include "EnsembleDeMot.h"
#include "Dictionnaire.h"

CorrecteurOrthographique CO_correcteur(Dictionnaire unDico, Mot unMotFaux){
    assert(!estUnMotDuDictionnaire(unDico, unMotFaux));
    CorrecteurOrthographique unCorrecteur;
    unCorrecteur.leDictionnaire = unDico;
    unCorrecteur.motACorriger = unMotFaux;
    unCorrecteur.lesCorrections = ensembleDeMot();
    return unCorrecteur;
}
Mot CO_obtenirMotACorriger(CorrecteurOrthographique unCorrecteur){
    return unCorrecteur.motACorriger;
}

Dictionnaire CO_obtenirDictionnaire(CorrecteurOrthographique unCorrecteur){
    return unCorrecteur.leDictionnaire;
}
EnsembleDeMot CO_obtenirCorrections(CorrecteurOrthographique unCorrecteur){
    return unCorrecteur.lesCorrections;
}
void CO_fixerDico(CorrecteurOrthographique* unCorrecteur, Dictionnaire unDico){
    unCorrecteur->leDictionnaire = unDico;
}

void CO_fixerMotACorriger(CorrecteurOrthographique* unCorrecteur, Mot unMotFaux){
    assert(!estUnMotDuDictionnaire(CO_obtenirDictionnaire(*unCorrecteur), unMotFaux));
    unCorrecteur->motACorriger = unMotFaux;
}

void CO_ajouterNouvellesCorrections (CorrecteurOrthographique* unCorrecteur, EnsembleDeMot desCorrections){
    EDM_union(unCorrecteur->lesCorrections, desCorrections);
}

void CO_trouverCorrectionsPossibles(CorrecteurOrthographique* unCorrecteur){
    CO_strategieRemplacerLettres(unCorrecteur);
    CO_strategieSupprimerLettres(unCorrecteur);
    CO_strategieInsererLettres(unCorrecteur);
    CO_strategieInverserDeuxLettresConsecutives(unCorrecteur);
    CO_strategieDecomposerMot(unCorrecteur);
}

void CO_strategieRemplacerLettres(CorrecteurOrthographique* unCorrecteur){
    unsigned int i, longueur;
    int j;
    Mot uneCorrection;

    Mot leMotACorriger = CO_obtenirMotACorriger(*unCorrecteur);
    Dictionnaire leDico = CO_obtenirDictionnaire(*unCorrecteur);
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();
    
    for(i = 1; i < longueur ; i++){
        desCorrections = M_remplacerIemeLettre(leMotACorriger, i);
        int nbCorrections = EDM_cardinalite(desCorrections);
        for(j = 0; j < nbCorrections ; j++){
            uneCorrection = EDM_obtenirElement(desCorrections, j);

            if(estUnMotDuDictionnaire(leDico, uneCorrection))
                EDM_ajouter(&desCorrections, uneCorrection);
        }
        CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);
    }
}

void CO_strategieSupprimerLettres(CorrecteurOrthographique* unCorrecteur){
    unsigned int i, longueur;
    Mot uneCorrection;

    Mot leMotACorriger = CO_obtenirMotACorriger(*unCorrecteur);
    Dictionnaire leDico = CO_obtenirDictionnaire(*unCorrecteur);
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();
    
    for(i = 1; i < longueur; i++){
        uneCorrection = M_supprimerIemeLettre(leMotACorriger, i);
        if(estUnMotDuDictionnaire(leDico, uneCorrection))
            EDM_ajouter(&desCorrections, uneCorrection);
    }
    CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);
}

void CO_strategieInverserDeuxLettresConsecutives(CorrecteurOrthographique* unCorrecteur){
    unsigned int i, longueur;
    Mot uneCorrection;

    Mot leMotACorriger = CO_obtenirMotACorriger(*unCorrecteur);
    Dictionnaire leDico = CO_obtenirDictionnaire(*unCorrecteur);
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();

    for(i = 1; i < longueur; i++){
        uneCorrection = M_inverserDeuxLettresConsecutives(leMotACorriger,i);
        if(estUnMotDuDictionnaire(leDico, uneCorrection))
            EDM_ajouter(&desCorrections, uneCorrection);
    }
    CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);
}

void CO_strategieInsererLettres(CorrecteurOrthographique* unCorrecteur){
    unsigned int i, longueur;
    int j;
    Mot uneCorrection;

    Mot leMotACorriger = CO_obtenirMotACorriger(*unCorrecteur);
    Dictionnaire leDico = CO_obtenirDictionnaire(*unCorrecteur);
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();
    
    for(i = 1; i < longueur ; i++){
        desCorrections = M_insererLettre(leMotACorriger, i);
        int nbCorrections = EDM_cardinalite(desCorrections);
        for(j = 0; j < nbCorrections ; j++){
            uneCorrection = EDM_obtenirElement(desCorrections, j);

            if(estUnMotDuDictionnaire(leDico, uneCorrection))
                EDM_ajouter(&desCorrections, uneCorrection);
        }
        CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);
    }
}

void CO_strategieDecomposerMot(CorrecteurOrthographique* unCorrecteur){
        unsigned int i, longueur;
    Mot uneCorrection;

    Mot leMotACorriger = CO_obtenirMotACorriger(*unCorrecteur);
    Mot unMotModifiable;
    Dictionnaire leDico = CO_obtenirDictionnaire(*unCorrecteur);
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();

    for(i = 1; i < longueur; i++){
        unMotModifiable = leMotACorriger;
        uneCorrection = M_decomposerMot(&unMotModifiable, i);
        if(estUnMotDuDictionnaire(leDico, uneCorrection) && estUnMotDuDictionnaire(leDico, unMotModifiable))
            EDM_ajouter(&desCorrections, uneCorrection);
    }
    CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);
}
