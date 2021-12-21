#ifndef __LISTE_CHAINEE_DE_MOT__
#define __LISTE_CHAINEE_DE_MOT__
#include <errno.h>
#include "Mot.h"

/* Partie privee */
typedef struct Noeud *ListeChaineeDeMot;
typedef struct Noeud {
	Mot mot;
	ListeChaineeDeMot listeSuivante;
} Noeud;

/* Partie publique */
#define LCDM_ERREUR_MEMOIRE 1

ListeChaineeDeMot LCDM_listeChaineeDeMot();
int LCDM_estVide(ListeChaineeDeMot);
void LCDM_ajouter(ListeChaineeDeMot*,Mot); /* errno=LCDM_ERREUR_MEMOIRE si pas assez de m�moire */
Mot LCDM_obtenirMot(ListeChaineeDeMot); /* assertion : liste non vide */
ListeChaineeDeMot LCDM_obtenirListeSuivante(ListeChaineeDeMot); /* assertion : liste non vide */
void LCDM_fixerListeSuivante(ListeChaineeDeMot*, ListeChaineeDeMot); /* assertion : liste non vide */
void LCDM_fixerMot(ListeChaineeDeMot*,Mot); /* assertion : liste non vide */
void LCDM_supprimerMot(ListeChaineeDeMot*, Mot);
void LCDM_supprimerTete(ListeChaineeDeMot*); /* assertion : liste non vide */
void LCDM_supprimer(ListeChaineeDeMot*);
ListeChaineeDeMot LCDM_copier(ListeChaineeDeMot);
int LCDM_egale(ListeChaineeDeMot,ListeChaineeDeMot);
#endif 
