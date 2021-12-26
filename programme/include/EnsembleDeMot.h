#ifndef __ENSEMBLE_DE_MOT__
#define __ENSEMBLE_DE_MOT__
#include <errno.h>
#include "ListeChaineeDeMot.h"
#include "Mot.h"

/* Partie privee */
typedef struct EnsembleDeMot{
  ListeChaineeDeMot lesMots;
  long int nbMots;
} EnsembleDeMot;


/* Partie publique */
#define EDM_ERREUR_MEMOIRE 1

EnsembleDeMot ensembleDeMot();
void EDM_vider(EnsembleDeMot*); 
EnsembleDeMot EDM_copier(EnsembleDeMot);  /* errno=EDM_ERREUR_MEMOIRE si pas assez de m�moire */
int EDM_egale(EnsembleDeMot,EnsembleDeMot);
void EDM_ajouter(EnsembleDeMot*,Mot);  /* errno=EDM_ERREUR_MEMOIRE si pas assez de m�moire */
void EDM_retirer(EnsembleDeMot*,Mot);
int EDM_estPresent(EnsembleDeMot,Mot);
long int EDM_cardinalite(EnsembleDeMot);

EnsembleDeMot EDM_union(EnsembleDeMot,EnsembleDeMot);  /* errno=EDM_ERREUR_MEMOIRE si pas assez de m�moire */
EnsembleDeMot EDM_intersection(EnsembleDeMot,EnsembleDeMot);  /* errno=EDM_ERREUR_MEMOIRE si pas assez de m�moire */
EnsembleDeMot EDM_soustraction(EnsembleDeMot,EnsembleDeMot);  /* errno=EDM_ERREUR_MEMOIRE si pas assez de m�moire */


Mot EDM_obtenirMot(EnsembleDeMot);
#endif 