#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ArbreDeLettres.h"

ArbreDeLettres ADL_creerADLVide(){
    errno = 0;
    return NULL;
} 

int ADL_estVide(ArbreDeLettres arbre){
    errno = 0;
    return (arbre == NULL);
}

ArbreDeLettres ADL_creerADL(ArbreDeLettres fils, ArbreDeLettres frere, char lettre, int estUneFin){
    ArbreDeLettres arbre = (ArbreDeLettres)malloc(sizeof(ADL));
    arbre->fils = fils;
    arbre->frere = frere;
    arbre->estFinDeMot = estUneFin;
    arbre->lettre = lettre;
    return arbre;
}

void ADL_fixerElement(ArbreDeLettres *arbre, char c, int estUneFin){
    (*arbre)->estFinDeMot=estUneFin;
    (*arbre)->lettre=c;
    (*arbre)->fils=NULL;
    (*arbre)->frere=NULL;
}

void ADL_fixerEstFinDeMot(ArbreDeLettres *arbre, int estUneFin){
    assert(!ADL_estVide(*arbre));
    errno = 0;
    (*arbre)->estFinDeMot = estUneFin;
}

void ADL_fixerLettre(ArbreDeLettres *arbre, char lettre){
    assert(!ADL_estVide(*arbre));
    errno = 0;
    (*arbre)->lettre = lettre;
}

void ADL_fixerFrere(ArbreDeLettres *arbre, ArbreDeLettres frere){
    assert(!ADL_estVide(*arbre));
    errno = 0;
    (*arbre)->frere = frere;
}

void ADL_fixerFils(ArbreDeLettres *arbre, ArbreDeLettres fils){
    assert(!ADL_estVide(*arbre));
    errno = 0;
    (*arbre)->fils = fils;
}

ArbreDeLettres ADL_obtenirFils(ArbreDeLettres arbre){
    assert(!ADL_estVide(arbre));
    errno = 0;
    return arbre->fils;
}

ArbreDeLettres ADL_obtenirFrere(ArbreDeLettres arbre){
    assert(!ADL_estVide(arbre));
    errno = 0;
    return arbre->frere;
}

char ADL_obtenirLettre(ArbreDeLettres arbre){
    assert(!ADL_estVide(arbre));
    errno = 0;
    return arbre->lettre;
}

int ADL_obtenirEstFinDeMot(ArbreDeLettres arbre){
    assert(!ADL_estVide(arbre));
    errno = 0;
    return arbre->estFinDeMot;
}

void ADL_supprimer(ArbreDeLettres arbre){
    ArbreDeLettres tmp = ADL_creerADLVide();
    if (!ADL_estVide(arbre)){
        tmp=ADL_obtenirFils(arbre);
        ADL_supprimer(tmp);
        tmp=ADL_obtenirFrere(arbre);
        ADL_supprimer(tmp);
    }
    free(arbre);
}
