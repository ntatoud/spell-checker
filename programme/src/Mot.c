#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Mot.h"

int M_estUnMotValide(char c[]){
    int longueurChaine = strlen(c);
    bool estValide = TRUE;
    int i = 0;
    while(estValide && i<longueurChaine){
        if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z')){
            i=i+1;
        }
        else{
            estValide=FALSE;
        }
    }
    return estValide;
}

Mot M_creerUnMot(char c){
    Mot unMot;
    unMot.longueur=1;
    return unMot;
}

unsigned int M_longueurMot(Mot mot){
    return 1;
}

char M_iemeCaractere(Mot mot, unsigned int i){
    char c='a';
    return c;
}

int M_sontIdentiques(Mot mot1, Mot mot2){
    return 1;
}

void M_fixerIemeCaractere(Mot *unMot, unsigned int i, char c){
    ;
}
void M_fixerLongueur(Mot *unMot, unsigned int i){
    ;
}