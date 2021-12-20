#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <wchar.h>
#include "Mot.h"

int M_estUnMotValide(wchar_t * c){
    int longueurChaine = wcslen(c);
    int estValide = 1;
    int i = 1;
    while(estValide && i<=longueurChaine){ //la cd utilise acceder ieme car..
        /*
        valide=E_estPresent(CaractereAlphabetique,c[i])
        */
    }
    return estValide;
}
/* versoin cd : est-ce qu'on prend un mot en entrée ou une wcah*

int M_estUnMotValide(wchar_t * c){
    int valide = 1;
    int i = 1;
    while((valide) && (i<=M_longueur(mot))){
        c=M_iemeCaractere(mot,i);
        valide=E_estPresent(CaractereAlphabetique,c)
        i=i+1
    }
    return valide;
}



*/


Mot M_creerUnMot(wchar_t * c){
    Mot unMot;
    unMot.longueur=wcslen (c);
    unMot.chaine=c;
    return unMot;
}

unsigned int M_longueurMot(Mot mot){
    return mot.longueur;
}

wchar_t M_iemeCaractere(Mot mot, unsigned int i){
    return mot.chaine[i];
}

int M_sontIdentiques(Mot mot1, Mot mot2){
    return 1;
}

Mot M_fixerIemeCaractere(Mot unMot, unsigned int i, wchar_t c){
    return unMot;
}
Mot M_fixerLongueur(Mot unMot, unsigned int i){
    return unMot;
}

Mot M_supprimerIemeLettre(Mot unMot, unsigned int i){
    return unMot;
}
Mot M_inverserDeuxLettresConsecutives(Mot unMot, unsigned int i){
    return unMot;
}
Mot M_insererLettre(Mot unMot, unsigned int i, wchar_t c){
    return unMot;
}
Mot M_decomposerMot(Mot* unMot, unsigned int i){ //on modifie le mot et récupère le mot de sortie
    return *unMot;
} 
Mot M_reduireLaCasse(Mot unMot){
    return unMot;
}