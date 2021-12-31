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

Dictionnaire D_genererArbreAvecTableauDeMots(Mot* lesMots, int nbMots){
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

/* Partie publique */

Dictionnaire D_genererArbreAvecFichierTexte(FichierTexte ficDico){
    int nbMots;
    Mot *lesMots = D_genererTableauDeMotAvecFichierTexte(ficDico, &nbMots);
    Dictionnaire leDico = D_genererArbreAvecTableauDeMots(lesMots, nbMots);
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
    Dictionnaire unDico = ADL_creerADLVide();
    return unDico;
}
FichierTexte D_sauvegarderArbreEnFichierTexte(Dictionnaire unDico){
    FichierTexte sauvegardeDico;
    sauvegardeDico.fichier = NULL;

    return sauvegardeDico;
}