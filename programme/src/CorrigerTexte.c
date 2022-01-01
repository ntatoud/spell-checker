#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Dictionnaire.h"
#include "CorrecteurOrthographique.h"
#include "Mot.h"
#include "EnsembleDeMot.h"
#include "CorrigerTexte.h"


void CT_corrigerTexte(char* chaine,Dictionnaire dico){ 
    int indiceAvantMot=0;
    for(int position=0;position<strlen(chaine);position++){
        if(CT_estUnSeparateur(chaine[position])){
            if(position>indiceAvantMot){
                CT_trouverEtAfficherCorrection(chaine, indiceAvantMot,position,dico);
            }
            indiceAvantMot=position+1;
        }
        else{
        }
    }
    if(strlen(chaine)>indiceAvantMot){
        CT_trouverEtAfficherCorrection(chaine, indiceAvantMot,strlen(chaine),dico);
    }
    printf("\n");
}

int CT_estUnSeparateur(char c){
    char* apostrophe = "'";
    return (c==' ')||(c==',')||(c=='.')||(c=='?')||(c==';')||(c=='!')||(c==':')||(c=='\0')||(c==apostrophe[0]) ||(c =='\n');
}

char* CT_creerSousChaine(char* chaine,unsigned int gauche,unsigned int droite){
    assert((gauche<=droite) && (droite<strlen(chaine)));
    char* sousChaine = malloc((droite-gauche+2)*sizeof(char));
    memcpy(sousChaine,&chaine[gauche],droite-gauche+1);
    sousChaine[droite-gauche+1] = '\0';
    return sousChaine;
}

CorrecteurOrthographique CT_trouverCorrections(Dictionnaire dico, Mot unMot){
    CorrecteurOrthographique correcteur = CO_correcteur(dico, unMot);
    CO_trouverCorrectionsPossibles(&correcteur);
    return correcteur;
}

void CT_afficherCorrection(int indiceDebutMot,CorrecteurOrthographique correcteur){
    printf("& %s %i %ld :", CO_obtenirMotACorriger(correcteur).chaine, indiceDebutMot,EDM_cardinalite(CO_obtenirCorrections(correcteur)));
    if(EDM_cardinalite(CO_obtenirCorrections(correcteur))==0){
        printf(" Trop d'erreurs dans ce mot\n");
    }
    else{
        int cardinalite = EDM_cardinalite(CO_obtenirCorrections(correcteur));
        for(int i=0; i<cardinalite;i++){
            Mot tmp = EDM_obtenirMot(CO_obtenirCorrections(correcteur));
            printf(" %s", M_obtenirChaine(tmp));
            EDM_retirer(&correcteur.lesCorrections, tmp);
            M_supprimerMot(&tmp);
            
        }
    printf("\n");
    }
}

void CT_trouverEtAfficherCorrection(char* chaine, int indiceDebutMot,int position,Dictionnaire dico){
    char *sousChaine = CT_creerSousChaine(chaine,indiceDebutMot,position-1); //tester souschaine avec un seul car
    Mot unMot = M_creerUnMot(sousChaine);
    
    if(!D_estUnMotDuDictionnaire(dico, M_copierMot(unMot))){
        CorrecteurOrthographique correcteur = CT_trouverCorrections(dico, unMot);
        CT_afficherCorrection(indiceDebutMot,correcteur);
        M_supprimerMot(&correcteur.motACorriger);
    }
    else{
        M_supprimerMot(&unMot);
        printf("*\n");
    }
    free(sousChaine);
    M_supprimerMot(&unMot);
}
/*
int main(){


    //FichierTexte ficDico = FT_fichierTexte("dicoTest");
    FichierTexte ficDico = FT_fichierTexte("dico-ref-ascii.txt");
    Dictionnaire unDico = D_genererDicoAvecFichierTexte(ficDico);
    char* chaine = "j'ai vraimentt sommeiil";
    corrigerTexte(chaine,unDico);
    
    ADL_supprimer(&unDico);
    return 0;

}*/