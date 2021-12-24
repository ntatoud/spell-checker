#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ListeChaineeDeMot.h"
#include "Mot.h"

ListeChaineeDeMot LCDM_listeChaineeDeMot(){
    errno = 0;
    return NULL;
}

int LCDM_estVide(ListeChaineeDeMot l){
    errno = 0;
    return (l == NULL);
}

void LCDM_ajouter(ListeChaineeDeMot *l, Mot unMot){
   ListeChaineeDeMot pNoeud = malloc(sizeof(Noeud));
    if (pNoeud != NULL){
        errno = 0;
        pNoeud->mot = unMot;
        pNoeud->listeSuivante = *l;
        *l = pNoeud;
    }
    else{
        errno = LCDM_ERREUR_MEMOIRE;
    }
}

Mot LCDM_obtenirMot(ListeChaineeDeMot l){
    assert(!LCDM_estVide(l));
    errno = 0;
    return l->mot;
}

void LCDM_supprimerMot(ListeChaineeDeMot *l, Mot unMot){
    assert(!LCDM_estVide(*l));
    ListeChaineeDeMot temp = LCDM_listeChaineeDeMot();
    if (!LCDM_estVide(*l)){
        if (M_sontIdentiques(LCDM_obtenirMot(*l), unMot)){
            LCDM_supprimerTete(l);
        }else{
            temp = LCDM_obtenirListeSuivante(*l);
            LCDM_supprimerMot(&temp, unMot);
            LCDM_fixerListeSuivante(l, temp);

        }
    }
    //free(temp);
}

ListeChaineeDeMot LCDM_obtenirListeSuivante(ListeChaineeDeMot l){
    assert(!LCDM_estVide(l));
    errno = 0;
    return l->listeSuivante;
}

void LCDM_fixerListeSuivante(ListeChaineeDeMot *l, ListeChaineeDeMot suivant){
    assert(!LCDM_estVide(*l));
    errno = 0;
    (*l)->listeSuivante = suivant;
}

void LCDM_fixerMot(ListeChaineeDeMot *l, Mot unMot){
    assert(!LCDM_estVide(*l));
    errno = 0;
    (*l)->mot = unMot;
}

void LCDM_supprimerTete(ListeChaineeDeMot *l){
    ListeChaineeDeMot temp;
    assert(!LCDM_estVide(*l));
    errno = 0;
    temp = *l;
    *l = LCDM_obtenirListeSuivante(*l);
    free(temp); 
}

void LCDM_supprimer(ListeChaineeDeMot *l){
    errno = 0;
    if (!LCDM_estVide(*l)){
        LCDM_supprimerTete(l);
        LCDM_supprimer(l);
    }
    free(*l); /**/
}

ListeChaineeDeMot LCDM_copier(ListeChaineeDeMot l){
    ListeChaineeDeMot temp;
    errno = 0;
    if (LCDM_estVide(l)){
        return LCDM_listeChaineeDeMot();
        free(temp);
    }else{
        temp = LCDM_copier(LCDM_obtenirListeSuivante(l));
        LCDM_ajouter(&temp, LCDM_obtenirMot(l));
        return temp;
    }
}

int LCDM_egale(ListeChaineeDeMot l1, ListeChaineeDeMot l2){
    errno = 0;
    if (LCDM_estVide(l1) && LCDM_estVide(l2)){
        return 1;
    }else{
        if (LCDM_estVide(l1) || LCDM_estVide(l2)){
            return 0;
        }else{
            if (M_sontIdentiques(LCDM_obtenirMot(l1),LCDM_obtenirMot(l2))){
                return LCDM_egale(LCDM_obtenirListeSuivante(l1), LCDM_obtenirListeSuivante(l2));
            }
            else{
                return 0;
            }
        }
    }
}
