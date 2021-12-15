#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Mot.h"
#include "CorrecteurOrthographique.h"
#include "EnsembleDeMot.h"

CorrecteurOrthographique CO_creerCorrecteur(Dictionnaire unDico, Mot unMot){
    CorrecteurOrthographique unCorrecteur;
    unCorrecteur.leDictionnaire = unDico;
    unCorrecteur.motACorriger = unMot;
    unCorrecteur.lesCorrections = ensembleDeMot();
    return unCorrecteur;
}
void CO_strategieRemplacerLettres(CorrecteurOrthographique* leCorrecteur){
    ;
}
void CO_strategieSupprimerIemeLettres(CorrecteurOrthographique* leCorrecteur){
    ;
}
void CO_strategieInverserDeuxLettresConsecutives(CorrecteurOrthographique* leCorrecteur){
    ;
}
void CO_strategieInsererLettres(CorrecteurOrthographique* leCorrecteur){
    ;
}
void CO_strategieDecomposerMot(CorrecteurOrthographique* leCorrecteur){
    ;
}
