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
    char* chaineTemp = (char*)malloc(1);
    chaineTemp="";
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

Mot M_copierMot(Mot unMot){
    Mot copie;
    copie = M_creerUnMot(unMot.chaine);
    return copie;
}


Mot M_creerUnMot(char * c){
    assert(M_estUnMotValide(c));
    Mot unMot;
    unMot.chaine = malloc(strlen(c)+1);
    strcpy(unMot.chaine, c);
    unMot.longueur=strlen(unMot.chaine);
    return unMot;
}

unsigned int M_longueurMot(Mot unMot){
    return unMot.longueur;
}

char* M_obtenirChaine(Mot unMot){
    return unMot.chaine;
}

char* M_iemeCaractere(Mot unMot, unsigned int i){
    assert(i<=M_longueurMot(unMot));
    char* element = (char*)malloc(1);
    element="";
    element[0]=unMot.chaine[i];
    return element;
}

int M_sontIdentiques(Mot mot1, Mot mot2){ 
    return mot1.longueur==mot2.longueur && strcmp(mot1.chaine,mot2.chaine)==0;
}

void M_fixerIemeCaractere(Mot* unMot, unsigned int i, char* c){
    assert(M_estUnCaractereAlphabetique(c)&&i<=M_longueurMot(*unMot));

    if((strcmp(c,"À")>=0) && (!(strcmp(c,"Û")<=0))){
            int carEnAscii = c[0]+32;
            c[0] = carEnAscii;

    unMot->chaine[i]=c[0];
    }
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
    assert(i<M_longueurMot(*unMot)-1);
    char* temp = (char*)malloc(1);
    temp = M_iemeCaractere(*unMot,i);
    M_fixerIemeCaractere(unMot,i,M_iemeCaractere(*unMot,i+1));
    M_fixerIemeCaractere(unMot,i+1,temp);
}

void M_insererLettre(Mot* unMot, unsigned int i, char* c){
    assert(i<=M_longueurMot(*unMot)+1);
    if(i<=M_longueurMot(*unMot)){
        M_decalerVersLaDroite(unMot,i);
    }
    M_fixerIemeCaractere(unMot,i,c);
}

Mot M_decomposerMot(Mot* unMot, unsigned int i){ //on modifie le mot et récupère le mot de sortie
    assert(i<=M_longueurMot(*unMot));
    char* chaine = (char*)malloc(M_longueurMot(*unMot));
    chaine =(*unMot).chaine;               //https://www.delftstack.com/fr/howto/c/get-c-substring/
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

void M_reduireLaCasse(char** chaine){
    assert(strlen(*chaine)>0);
    unsigned int j;
    for(j=0;j<=strlen((*chaine))-1;j++){
        char* element = (char*)malloc(1);
        element="";
        element[0]=(*chaine)[j];
        if((strcmp(element,"a")>=0) && (!(strcmp(element,"z")<=0))){
            element[0]=element[0]+32;
            (*chaine)[j]=element[0];
        }
        else if((strcmp(element,"À")>=0) && (!(strcmp(element,"Û")<=0))){
            int carEnAscii = element[0]+32;
            element[0] = carEnAscii;
            (*chaine)[j]=element[0];
        }
    }
}


void M_supprimerMot(Mot *unMot){
    free((*unMot).chaine);
    (*unMot).longueur=0;
}