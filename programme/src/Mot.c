#include <stdlib.h>
#include <assert.h>
#include "Mot.h"
#include <string.h>


int M_estUnCaractereAlphabetique(char* c){
    assert(strlen(c)==1);
    int result=1;
    if(!((strcmp(c,"a")>=0) && (!(strcmp(c,"z")<=0)))){
        result=0;
    }
    else if (result==1 && (!(((strcmp(c,"A")>=0)) && ((!(strcmp(c,"Z")<=0)))))){
        result=0;
    }
    else if(result==1 && (!((strcmp(c,"À")>=0) && (!(strcmp(c,"Ü")<=0))))){
        result=0;
    }
    return result;
}

void M_decalerVersLaDroite(Mot* unMot,unsigned int i){
    assert(i<=M_longueurMot(*unMot));
    M_fixerLongueur(unMot,M_longueurMot(*unMot)+1);
    unsigned int j;
    for(j=M_longueurMot(*unMot);j>i;j--){
        M_fixerIemeCaractere(unMot,j,M_iemeCaractere(*unMot,j-1));
    }
}


int M_estUnMotValide(char* c){
    assert(strlen(c)>0);
    int longueurChaine = strlen(c);
    char* chaineTemp="";
    int estValide = 1;
    int i = 0;
    while(estValide && i<longueurChaine){
        chaineTemp[0]=c[i];
        if(!M_estUnCaractereAlphabetique(chaineTemp)){
            estValide=0;
        }
        i=i+1;
    }
    return estValide;
}


Mot M_creerUnMot(char * c){
    assert(M_estUnMotValide(c));
    Mot unMot;
    unMot.longueur=strlen(c);
    unMot.chaine=c;
    return unMot;
}

unsigned int M_longueurMot(Mot unMot){
    return unMot.longueur;
}

char* M_iemeCaractere(Mot unMot, unsigned int i){
    assert(i<=M_longueurMot(unMot));
    char* element = "";
    element[0]=unMot.chaine[i];
    return element;
}

int M_sontIdentiques(Mot mot1, Mot mot2){ 
    int identique = 0;
    if((mot1.longueur==mot2.longueur)&&(mot1.chaine==mot2.chaine)){
        identique=1;
    }
    return identique;
}

void M_fixerIemeCaractere(Mot* unMot, unsigned int i, char* c){
    assert(M_estUnCaractereAlphabetique(c)&&i<=M_longueurMot(*unMot));
    unMot->chaine[i]=c[0];
}


void M_fixerLongueur(Mot* unMot, unsigned int i){
    unMot->longueur=i;
}

void M_supprimerIemeLettre(Mot* unMot, unsigned int i){
    assert(i<=M_longueurMot(*unMot));
    unsigned int j;
    for(j=i;j<M_longueurMot(*unMot);j++){
        M_fixerIemeCaractere(unMot,j,M_iemeCaractere(*unMot,j+1));
    }
    M_fixerLongueur(unMot,M_longueurMot(*unMot)-1);
}

void M_inverserDeuxLettresConsecutives(Mot* unMot, unsigned int i){
    assert(i<M_longueurMot(*unMot));
    char* temp = M_iemeCaractere(*unMot,i);
    M_fixerIemeCaractere(unMot,i,M_iemeCaractere(*unMot,i+1));
    M_fixerIemeCaractere(unMot,i+1,temp);
}

void M_insererLettre(Mot* unMot, unsigned int i, char* c){
    assert(i<=M_longueurMot(*unMot)+1);
    M_decalerVersLaDroite(unMot,i);
    M_fixerIemeCaractere(unMot,i,c);
}

Mot M_decomposerMot(Mot* unMot, unsigned int i){ //on modifie le mot et récupère le mot de sortie
    assert(i<=M_longueurMot(*unMot));
    char* chaine=(*unMot).chaine;               //https://www.delftstack.com/fr/howto/c/get-c-substring/
    char texteGauche[i];
    char texteDroit[(*unMot).longueur-i+2];
    memcpy(texteGauche,&chaine[0],i-1);
    texteGauche[i] = '\0';
    memcpy(texteDroit,&chaine[i],(*unMot).longueur-i+1);
    texteDroit[(*unMot).longueur-i+2] = '\0';
    
    Mot motGauche = M_creerUnMot(texteGauche);
    unMot->longueur = (*unMot).longueur-i+1;
    unMot->chaine = texteDroit;
    return motGauche;
} 

void M_reduireLaCasse(Mot* unMot){
    unsigned int j;
    for(j=1;j<=(*unMot).longueur;j++){
        char* c = M_iemeCaractere(*unMot,j);
        if((strcmp(c,"a")>=0) && (!(strcmp(c,"z")<=0))){
            c[0]=c[0]+32; // ok car pas d'accent
            M_fixerIemeCaractere(unMot,j,c);
        }
        else if((strcmp(c,"À")>=0) && (!(strcmp(c,"Û")<=0))){
            int carEnAscii = c[0]+32;
            c[0] = carEnAscii;
            M_fixerIemeCaractere(unMot,j,c);
        }
    }
}