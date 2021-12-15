#ifndef __CORRECTEUR_ORTHOGRAPHIQUE__
#define __CORRECTEUR_ORTHOGRAPHIQUE__
#include "Dictionnaire.h"
#include "Mot.h"
#include "EnsembleDeMot.h"

typedef struct{
    Dictionnaire leDictionnaire ;
    Mot motACorriger ;
    EnsembleDeMot lesCorrections;
} CorrecteurOrthographique;

CorrecteurOrthographique CO_creerCorrecteur(Dictionnaire, Mot);
void CO_strategieRemplacerLettres(CorrecteurOrthographique*);
void CO_strategieSupprimerIemeLettres(CorrecteurOrthographique*);
void CO_strategieInverserDeuxLettresConsecutives(CorrecteurOrthographique*);
void CO_strategieInsererLettres(CorrecteurOrthographique*);
void CO_strategieDecomposerMot(CorrecteurOrthographique*); 


#endif