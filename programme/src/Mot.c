#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Mot.h"

int M_estUnMotValide(char c){
    return 1;
}

Mot M_creerUnMot(char c){
    Mot unMot;
    unMot.chaine='a';
    unMot.longueur=1;
    return unMot;
}

unsigned int M_longueurMot(Mot mot){
    return 1;
}

char M_iemeCaractere(Mot mot){
    char c='a';
    return c;
}

int M_sontIdentiques(Mot mot1, Mot mot2){
    return 1;
}

