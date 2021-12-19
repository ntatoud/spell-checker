#ifndef __CORRECTEUR_ORTHOGRAPHIQUE__
#define __CORRECTEUR_ORTHOGRAPHIQUE__
#include "Dictionnaire.h"
#include "Mot.h"
#include "EnsembleDeMot.h"

typedef struct CorrecteurOrthographique{
    Dictionnaire leDictionnaire ;
    Mot motACorriger ;
    EnsembleDeMot lesCorrections;
} CorrecteurOrthographique;

CorrecteurOrthographique CO_correcteur(Dictionnaire, Mot);
Mot CO_obtenirMotACorriger(CorrecteurOrthographique);
void CO_fixerDico(CorrecteurOrthographique*, Dictionnaire);
void CO_fixerMotACorriger(CorrecteurOrthographique*, Mot);
void CO_ajouterNouvellesCorrections (CorrecteurOrthographique*, EnsembleDeMot);
void CO_trouverCorrectionsPossibles(CorrecteurOrthographique*);
void CO_strategieRemplacerLettres(CorrecteurOrthographique*);
void CO_strategieSupprimerLettres(CorrecteurOrthographique*);
void CO_strategieInverserDeuxLettresConsecutives(CorrecteurOrthographique*);
void CO_strategieInsererLettres(CorrecteurOrthographique*);
void CO_strategieDecomposerMot(CorrecteurOrthographique*); 


#endif