#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Mot.h"
#include "CorrecteurOrthographique.h"

Mot CO_remplacerIemeLettre(Mot unMot, unsigned int i, char uneLettre){ 
    CO_supprimerIemeLettre(unMot, i);
    CO_insererLettre(unMot, i, uneLettre);
    return unMot;
}

Mot CO_supprimerIemeLettre(Mot unMot, unsigned int i){
    assert(M_longueurMot(unMot) > 1 && M_longueurMot(unMot) < i);
    return unMot;
}

Mot CO_inverserDeuxLettresConsecutives(Mot mot, unsigned int i){
    Mot unMot;
    unMot.chaine="a";
    unMot.longueur=1;
    return unMot;
}

Mot CO_insererLettre(Mot mot, unsigned int i, char uneLettre){
    Mot unMot;
    unMot.chaine="a";
    unMot.longueur=1;
    return unMot;
}

Mot CO_decomposerMot(Mot *mot1, unsigned int i){
    Mot mot2; 
    mot2.chaine="a";
    mot2.longueur=1;
    return mot2;
}

Mot CO_reduireLaCasse(Mot mot){
    Mot unMot;
    unMot.chaine="a";
    unMot.longueur=1;
    return unMot;
}
