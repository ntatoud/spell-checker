#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Dictionnaire.h"
#include "CorrecteurOrthographique.h"
#include "Mot.h"
#include "EnsembleDeMot.h"


void corrigerTexte(char* chaine,Dictionnaire dico){ 
    int indiceDebutMot=0;
    for(int position=0,position<strlen(chaine),position++){
        if(CT_estUnSeparateur(chaine[position])){
            if(position>indiceDebutMot){
                CT_trouverEtAfficherCorrection(chaine, indiceDebutMot,position,dico);
            }
            else{}
            indiceDebutMot=position+1;
        }
        else{}
    }
}



int CT_estUnSeparateur(char c){
    char* apostrophe = malloc(sizeof(char));
    apostrophe = "'";
    return (c==' ')||(c==',')||(c=='.')||(c=='?')||(c==';')||(c=='!')||(c==':')||(c=='\0')||(c==apostrophe[0]);
}

char* CT_creerSousChaine(char* chaine,unsigned int gauche,unsigned int droite){
    assert((gauchex<=droite) && (droite<strlen(chaine)));
    char* sousChaine=malloc((droite-gauche+2)*sizeof(char));
    memcpy(sousChaine,&chaine[gauche],droite-gauche+1);
    sousChaine[droite-gauche+1] = '\0';
    return sousChaine;
}

CorrecteurOrthographique CT_trouverCorrections(Dictionnaire dico,Mot unMot){
    CorrecteurOrthographique correcteur = CO_correcteur(dico,unMot);
    CO_trouverCorrectionsPossibles(&correcteur);
    return correcteur;
}

void CT_afficherCorrection(int indiceDebutMot,CorrecteurOrthographique correcteur){
    printf("& %s %i %i :", unMot.chaine, indiceDebutMot,EDM_cardinalite(CO_obtenirCorrections(correcteur)));
    if(EDM_cardinalite(CO_obtenirCorrections(correcteur))==0){
        printf(" trop d'erreurs dans ce mot")
    }
    else{
        for(i=1, i<=EDM_cardinalite(CO_obtenirCorrections(correcteur)),i++){
        printf(" %s", M_obtenirChaine(EDM_obtenirMot(CO_obtenirCorrections(correcteur))));
    }
    printf('\n');
    }
}

void CT_trouverEtAfficherCorrection(char* chaine, int indiceDebutMot,int position,Dictionnaire dico){
    char* sousChaine = malloc((position-1-indiceDebutMot));
    sousChaine = CT_creerSousChaine(chaine,indiceDebutMot,position-1); //tester souschaine avec un seul car
    Mot unMot = M_creerUnMot(sousChaine);
    free(sousChaine);
    if(!D_estUnMotDuDictionnaire(dico,unMot)){
        CorrecteurOrthographique correcteur = CT_trouverCorrections(dico, unMot);
        CT_afficherCorrection(indiceDebutMot,correcteur);
    }
    else{
        printf("*\n");
    }
}