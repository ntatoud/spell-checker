
/**
 * \file EnsembleDeMot.h
 * \brief Implantation du type EnsembleDeMot pour le Projet Algo de correcteur orthographique
 * \authors N. Tatoud
 * \version 1.0
 * \date 31/12/2021
 *
 */
#ifndef __ENSEMBLE_DE_MOT__
#define __ENSEMBLE_DE_MOT__
#include <errno.h>
#include "ListeChaineeDeMot.h"
#include "Mot.h"

/**
 * \brief Le type EnsembleDeMot permet de traiter un groupe de mots sous forme d'ensemble
 *
*/
typedef struct EnsembleDeMot{
    ListeChaineeDeMot lesMots; /**<les mots de l'ensemble>*/
    long int nbMots; /**<le nombre de mots dans l'ensemble>*/
} EnsembleDeMot;


#define EDM_ERREUR_MEMOIRE 1

/**
 * \fn EnsembleDeMot ensembleDeMot();
 * \brief Fonction de création d'un ensembleDeMot
 *
 * \return EnsembleDeMot : un ensemble vide
*/
EnsembleDeMot ensembleDeMot();

/**
 * \fn void EDM_vider(EnsembleDeMot*);
 * \brief Fonction de suppression d'un ensembleDeMot
 *
 * \param unEDM : un pointeur sur un ensemble de Mot
*/
void EDM_vider(EnsembleDeMot * unEDM);
/**
 * \fn EnsembleDeMot EDM_copier(EnsembleDeMot); 
 * \brief Fonction de copie d'un ensemble de Mot
 *
 * \param unEDM : un ensemble de Mot
 * \return EnsembleDeMot : la copie de l'ensemble en entrée
*/
EnsembleDeMot EDM_copier(EnsembleDeMot unEDM); 
/**
 * \fn int EDM_egale(EnsembleDeMot, EnsembleDeMot);
 * \brief Fonction de comparaison de deux ensembles (égaux si contiennent les mêmes mots)
 *
 * \param edm1 : un ensemble de Mot
 * \param edm2 : un autre ensemble de Mot
 * \return 1 si les ensembles sont égaux, 0 sinon
*/
int EDM_egale(EnsembleDeMot edm1, EnsembleDeMot edm2);
/**
 * \fn void EDM_ajouter(EnsembleDeMot *, Mot); 
 * \brief Fonction d'ajout d'un Mot à un ensemble 
 *
 * \param unEDM : un pointeur sur un ensemble de Mot
 * \param unMot : un Mot qu'on veut ajouter à l'ensemble
*/
void EDM_ajouter(EnsembleDeMot * unEDM, Mot unMot); 

/**
 * \fn void EDM_retirer(EnsembleDeMot *, Mot); 
 * \brief Fonction de suppression d'un Mot d'un ensemble
 *
 * \param unEDM : un pointeur sur un ensemble de Mot
 * \param unMot : un Mot qu'on veut ajouter retirer de l'ensemble
*/
void EDM_retirer(EnsembleDeMot * unEDM, Mot unMot);

/**
 * \fn int EDM_estPresent(EnsembleDeMot, Mot); 
 * \brief Fonction de vérification de la présence d'un mot dans un ensemble
 *
 * \param unEDM : un ensemble de Mot
 * \param unMot : un Mot dont on veut vérifier la présence
 * \return 1 si le mot est présent, 0 sinon
*/
int EDM_estPresent(EnsembleDeMot unEDM, Mot unMot);

/**
 * \fn long int EDM_cardinalite(EnsembleDeMot); 
 * \brief Fonction d'accès au nombre d'éléments de l'ensemble
 *
 * \param unEDM : un ensemble de Mot
 * \return long int : le nombre de mots dans l'ensemble
*/
long int EDM_cardinalite(EnsembleDeMot unEDM);

/**
 * \fn EnsembleDeMot EDM_union(EnsembleDeMot, EnsembleDeMot); 
 * \brief Fonction d'opération mathématique d'union sur deux ensembles
 *
 * \param edm1 : un ensemble de Mot
 * \param edm2 : un autre ensemble de Mot
 * \return EnsembleDeMot : l'union mathématique des deux ensembles en entrée
*/
EnsembleDeMot EDM_union(EnsembleDeMot edm1, EnsembleDeMot emd2);

/**
 * \fn Mot EDM_obtenirMot(EnsembleDeMot);
 * \brief Fonction d'obtention du dernier élément ajouté à l'ensemble
 *
 * \param unEDM : un ensemble de Mot
 * \return Mot : le dernier mot ajouté à l'ensemble
*/      
Mot EDM_obtenirMot(EnsembleDeMot unEDM);
#endif