#ifndef __ENSEMBLE_DENTIERS__
#define __ENSEMBLE_DENTIERS__
#include <errno.h>
#include "ListeChaineeDeMot.h"

/* Partie privee */
typedef struct {
  ListeChaineeDeMot lesMots;
  int nbMots;
} EnsembleDeMot;

/* Partie publique */
#define EDM_ERREUR_MEMOIRE 1

EnsembleDeMot ensembleDeMot();
void EDM_ajouter(EnsembleDeMot*,Mot);  /* errno=EDM_ERREUR_MEMOIRE si pas assez de m�moire */
void EDM_retirer(EnsembleDeMot*,Mot);
int EDM_estPresent(EnsembleDeMot,Mot);
int EDM_cardinalite(EnsembleDeMot);
EnsembleDeMot EDM_union(EnsembleDeMot,EnsembleDeMot);  /* errno=EDM_ERREUR_MEMOIRE si pas assez de m�moire */
EnsembleDeMot EDM_intersection(EnsembleDeMot,EnsembleDeMot);  /* errno=EDM_ERREUR_MEMOIRE si pas assez de m�moire */
EnsembleDeMot EDM_soustraction(EnsembleDeMot,EnsembleDeMot);  /* errno=EDM_ERREUR_MEMOIRE si pas assez de m�moire */
void EDM_vider(EnsembleDeMot*); 
EnsembleDeMot EDM_copier(EnsembleDeMot);  /* errno=EDM_ERREUR_MEMOIRE si pas assez de m�moire */
int EDM_egale(EnsembleDeMot,EnsembleDeMot);
#endif 