#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Mot.h"
#include "CorrecteurOrthographique.h"
#include "EnsembleDeMot.h"
#include "Dictionnaire.h"

CorrecteurOrthographique CO_correcteur(Dictionnaire unDico, Mot unMotFaux){
    CorrecteurOrthographique unCorrecteur;
    unCorrecteur.leDictionnaire = unDico;
    unCorrecteur.motACorriger = unMotFaux;
    unCorrecteur.lesCorrections = ensembleDeMot();
    return unCorrecteur;
}
Mot CO_obtenirMotACorriger(CorrecteurOrthographique unCorrecteur){
    return unCorrecteur.motACorriger;
}
void CO_fixerDico(CorrecteurOrthographique* unCorrecteur, Dictionnaire unDico){
    unCorrecteur->leDictionnaire = unDico;
}

void CO_fixerMotACorriger(CorrecteurOrthographique* unCorrecteur, Mot unMotFaux){
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
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();
    
    for(i = 1; i < longueur ; i++){
        desCorrections = M_remplacerIemeLettre(leMotACorriger, i);
        int nbCorrections = EDM_cardinalite(desCorrections);
        for(j = 0; j < nbCorrections ; j++){
            uneCorrection = EDM_obtenirElement(desCorrections, j);

            if(estUnMotDuDictionnaire(unCorrecteur->leDictionnaire, uneCorrection))
                EDM_ajouter(&desCorrections, uneCorrection);
        }
        CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);
    }
}
void CO_strategieSupprimerLettres(CorrecteurOrthographique* unCorrecteur){
    unsigned int i, longueur;
    Mot uneCorrection;

    Mot leMotACorriger = CO_obtenirMotACorriger(*unCorrecteur);
    longueur = M_longueurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();
    
    for(i = 1; i < longueur; i++){
        uneCorrection = M_supprimerIemeLettre(leMotACorriger, i);
        if(estUnMotDuDictionnaire(unCorrecteur->leDictionnaire, uneCorrection))
            EDM_ajouter(&desCorrections, uneCorrection);
    }
    CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections);
}
void CO_strategieInverserDeuxLettresConsecutives(CorrecteurOrthographique* unCorrecteur){
    ;
}
void CO_strategieInsererLettres(CorrecteurOrthographique* unCorrecteur){
    ;
}
void CO_strategieDecomposerMot(CorrecteurOrthographique* unCorrecteur){
    ;
}
