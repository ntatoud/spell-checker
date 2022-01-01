#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Dictionnaire.h"
#include "ArbreDeLettres.h"
#include "Mot.h"
#include "FichierTexte.h"
#define NB_MOTS_DICTIONNAIRE 350000
#define LONGUEUR_MAX_MOT 27

/* Partie privée */

void D_insererMot(Dictionnaire* unDico, Mot unMot){
    Dictionnaire temp;
    int enFinDeMot = 0;
    if(M_longueurMot(unMot) == 1){
        enFinDeMot = 1;
        if(ADL_estVide(*unDico)){
            D_insererLettre(unDico, M_iemeCaractere(unMot, 1), enFinDeMot);
        }
        else{
            if(D_lettreEstRacine(*unDico, M_iemeCaractere(unMot, 1))){
                ADL_fixerEstFinDeMot(unDico, enFinDeMot);
            }
            else{
                temp = ADL_obtenirFrere(*unDico);
                D_insererMot(&temp, unMot);
                ADL_fixerFrere(unDico, temp);
            }
        }
    }
    else{
        if(ADL_estVide(*unDico)){
            D_insererLettre(unDico, M_iemeCaractere(unMot, 1), enFinDeMot);
            M_supprimerIemeLettre(&unMot, 1);
            temp = ADL_obtenirFils(*unDico);
            D_insererMot(&temp, unMot);
            ADL_fixerFils(unDico, temp);
        }
        else{
            if(D_lettreEstRacine(*unDico, M_iemeCaractere(unMot, 1))){
                M_supprimerIemeLettre(&unMot, 1);
                temp = ADL_obtenirFils(*unDico);
                D_insererMot(&temp, unMot);
                ADL_fixerFils(unDico, temp);
            }
            else{
                temp = ADL_obtenirFrere(*unDico);
                D_insererMot(&temp, unMot);
                ADL_fixerFrere(unDico, temp);
            }
        
        }
       
    }
}

void D_insererLettre(Dictionnaire* unDico, char uneLettre, int estFinDeMot){
    assert(ADL_estVide(*unDico));
    *unDico = ADL_creerADL(NULL, NULL, uneLettre, estFinDeMot);
    
}

int D_lettreEstRacine(Dictionnaire unDico, char uneLettre){
    return ADL_obtenirLettre(unDico) ==  uneLettre;
}

Mot* supprimerLesMots(Mot *lesMots, int nbMots){
    Mot* lesMotsASupprimer = lesMots;

    int i = 0;
    while(i < nbMots){
        M_supprimerMot(&lesMotsASupprimer[i]);
        i++;
    }
        
    return lesMotsASupprimer;
}

void supprimerTabMots(Mot **lesMots, int nbMots){
    *lesMots = supprimerLesMots(*lesMots, nbMots);
    free(*lesMots);
}

Mot* D_genererTableauDeMotAvecFichierTexte(FichierTexte ficDico, int *nbMots){
    Mot* lesMots=(Mot*)malloc(((sizeof(char)*27)+sizeof(int))*NB_MOTS_DICTIONNAIRE);

    FT_ouvrir(&ficDico, LECTURE);

    char* chaine;
    
    int tailleTab = 0;
    while(!FT_estEnFinDeFichier(ficDico)){
        chaine = FT_lireChaineSansLeRetourChariot(ficDico);

        if(strlen(chaine)>0){
            lesMots[tailleTab] = M_creerUnMot(chaine);
            free(chaine);
        
            tailleTab++;
        }
    }
    FT_fermer(&ficDico);
    *nbMots = tailleTab;
    return lesMots;
}

Dictionnaire D_genererDicoAvecTableauDeMots(Mot* lesMots, int nbMots){
    Dictionnaire unDico = ADL_creerADLVide();
    int i;
    Mot unMot;
    for(i =0; i < nbMots; i++){
        unMot = M_copierMot(lesMots[i]);
        D_insererMot(&unDico, unMot);
        M_supprimerMot(&unMot);
    }
    return unDico;
}

int charEnInt(char c){
    return c - '0';
}

void D_chargerDicoR(Dictionnaire* unDico, FichierTexte sauvegardeDico){
    Dictionnaire temp;
    char lettre, estFinDeMot, aUnFils, aUnFrere;
    char* element = FT_lireElement(sauvegardeDico);
    lettre = element[0];
    estFinDeMot = element[1];
    aUnFils = element[2];
    aUnFrere = element[3];
    *unDico = ADL_creerADL(NULL, NULL, lettre, charEnInt(estFinDeMot));
    if(charEnInt(aUnFils) == 1){
        D_chargerDicoR(&temp, sauvegardeDico);
        ADL_fixerFils(unDico, temp);
    }
    if(charEnInt(aUnFrere) == 1){
        D_chargerDicoR(&temp, sauvegardeDico);
        ADL_fixerFrere(unDico, temp);
    }
    /*
    if(!charEnInt(element[3]) && !charEnInt(element[2])){
        *unDico = ADL_creerADL(NULL, NULL, element[0], charEnInt(element[1]));
    }
    */
    free(element);

}

void D_sauvegarderDicoR(Dictionnaire* unDico, FichierTexte fic){
    
    Dictionnaire tempFils, tempFrere;
    if(!ADL_estVide(*unDico)){
        FT_ecrireCaractere(&fic ,ADL_obtenirLettre(*unDico));
        if(ADL_obtenirEstFinDeMot(*unDico))
            FT_ecrireCaractere(&fic , '1');
        else FT_ecrireCaractere(&fic , '0');

        tempFils = ADL_obtenirFils(*unDico);
        tempFrere = ADL_obtenirFrere(*unDico);
        if(!ADL_estVide(tempFils)){
            FT_ecrireCaractere(&fic ,'1');   
        }
        else FT_ecrireCaractere(&fic ,'0');  
        if(!ADL_estVide(tempFrere)){
            FT_ecrireCaractere(&fic ,'1');   
        }
        else FT_ecrireCaractere(&fic ,'0');  
        
        D_sauvegarderDicoR(&tempFils, fic);
        D_sauvegarderDicoR(&tempFrere, fic);
    }

}

/* Partie publique */

Dictionnaire D_genererDicoAvecFichierTexte(FichierTexte ficDico){
    int nbMots;
    Mot *lesMots = D_genererTableauDeMotAvecFichierTexte(ficDico, &nbMots);
    Dictionnaire leDico = D_genererDicoAvecTableauDeMots(lesMots, nbMots);
    supprimerTabMots(&lesMots, nbMots);
    return leDico;
}

int D_estUnMotDuDictionnaire(Dictionnaire unDico, Mot unMot){
    Dictionnaire temp;
    if(M_longueurMot(unMot) == 1){
        if(!ADL_estVide(unDico)){
            if(M_iemeCaractere(unMot, 1) == ADL_obtenirLettre(unDico)){
                M_supprimerMot(&unMot);
                return ADL_obtenirEstFinDeMot(unDico);
            }
            else{
                temp = ADL_obtenirFrere(unDico);
                return D_estUnMotDuDictionnaire(temp, unMot);
            }
        }
        else{
            M_supprimerMot(&unMot);
            return 0;
        }
    }
    else{
        if(!ADL_estVide(unDico)){
            if(M_iemeCaractere(unMot, 1) == ADL_obtenirLettre(unDico)){
                M_supprimerIemeLettre(&unMot, 1);
                temp = ADL_obtenirFils(unDico);
                return D_estUnMotDuDictionnaire(temp, unMot);
            }
            else{
                temp = ADL_obtenirFrere(unDico);
                return D_estUnMotDuDictionnaire(temp, unMot);
            }
        }
        else{
            M_supprimerMot(&unMot);
            return 0;
        }
    }
}

Dictionnaire D_chargerDico(FichierTexte sauvegardeDico){
    Dictionnaire unDico;
    FT_ouvrir(&sauvegardeDico, LECTURE);
    if(FT_verifierIdDico(sauvegardeDico))
        D_chargerDicoR(&unDico, sauvegardeDico);
    else 
        printf("Le fichier que vous essayez d'utiliser n'est pas compatible");
    FT_fermer(&sauvegardeDico);
    return unDico;
}

void D_sauvegarderDico(Dictionnaire* unDico, FichierTexte *sauvegardeDico){
    FT_ouvrir(sauvegardeDico, ECRITURE);
    FT_ecrireID(sauvegardeDico);
    D_sauvegarderDicoR(unDico, *sauvegardeDico);
    FT_fermer(sauvegardeDico);
}
