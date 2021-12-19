#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Mot.h"
#include "CorrecteurOrthographique.h"
#include "EnsembleDeMot.h"
#include "Ditionnaire.h"

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
    CO_strategieSupprimerIemeLettres(unCorrecteur);
    CO_strategieInsererLettres(unCorrecteur);
    CO_strategieInverserDeuxLettresConsecutives(unCorrecteur);
    CO_strategieDecomposerMot(unCorrecteur);
    ;
}
void CO_strategieRemplacerLettres(CorrecteurOrthographique* unCorrecteur){
   /* unsigned int i, longueur;
    int j;
    Mot leMotACorriger = CO_obtenirMotACorriger(unCorrecteur);
    longueur = M_longeurMot(leMotACorriger);
    EnsembleDeMot desCorrections = ensembleDeMot();
    for(i = 1; i < longueur ; i++){
        desCorrections = CO_remplacerIemeLettre(leMotACorriger);
        int nbCorrections = EDM_cardinalite(desCorrections);
    }
    */
    ;
}
void CO_strategieSupprimerLettres(CorrecteurOrthographique* unCorrecteur){
    unsigned int i, longueur;
    EnsembleDeMot desCorrections = ensembleDeMot();
    Mot uneCorrection;
    longueur = M_longeurMot(leMotACorriger);
    for(i = 1; i < longueur; i++){
        uneCorrection = M_supprimerIemeLettre(leMotACorriger);
        if(D_estUnMotDuDictionnaire(uneCorrection))
            EDM_ajouter(desCorrections, uneCorrection);
    }
    CO_ajouterNouvellesCorrections(unCorrecteur, desCorrections)
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
