
/**
 * \file Dictionnaire.h
 * \brief Implantation du TAD Dictionnaire pour le Projet Algo de correcteur orthographique
 * \authors N. Tatoud, F. Chevrier
 * \version 1.0
 * \date 31/12/2021
 *
 */

#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__
#include <stdio.h>
#include "EnsembleDeMot.h"
#include "FichierTexte.h"
#include "ArbreDeLettres.h"
#include "Mot.h"
#include "FichierTexte.h"

/**
 * \brief Le type Dictionnaire est une extension du type ArbreDeLettres, auquel on ajoute de nouvelles opérations spécifiques à un dictionnaire
 *
*/
typedef ArbreDeLettres Dictionnaire;

/**
 * \fn void D_insererMot(Dictionnaire*, Mot);
 * \brief Fonction d'insértion d'un mot dans un dictionnaire
 *
 * \param unDico : un dictionnaire mis sous forme d'arbre de lettres
 * \param unMot : un mot qui n'est pas dans le dictionnaire
*/
void D_insererMot(Dictionnaire* unDico, Mot unMot);

/**
 * \fn void D_insererLettre(Dictionnaire*, char, int);
 * \brief Fonction d'insértion d'une lettre d'un mot dans un dictionnaire
 * \attention assertion : sur unDico
 *
 * \param unDico : un dictionnaire mis sous forme d'arbre de lettres
 * \param lettre : une lettre d'un mot que l'on insère dans le dictionnaire
 * \param estFinDeMot : indique si la lettre insérée est en fin de mot
*/
void D_insererLettre(Dictionnaire* unDico, char lettre, int estFinDeMot);

/**
 * \fn int D_lettreEstRacine(Dictionnaire, char);
 * \brief Fonction de comparaison d'une lettre et de la lettre racine d'un dictionnaire sous forme d'arbre
 * \attention assertion : sur unDico
 *
 * \param unDico : un dictionnaire mis sous forme d'arbre de lettres
 * \param lettre : une lettre d'un mot 
  * \return 0 si la lettre est racine, 1 sinon
*/
int D_lettreEstRacine(Dictionnaire unDico, char lettre);

/**
 * \fn Mot* supprimerLesMots(Mot*, int);
 * \brief Fonction de suppression des mots d'un tableau de mot
 *
 * \param lesMots : un tableau de Mot
 * \param  nbMots: le nombre de mots dans le tableau 
  * \return Mot* : le tableau de mot avec les mots supprimés
*/
Mot* supprimerLesMots(Mot *lesMots, int nbMots);

/**
 * \fn void supprimerTabMots(Mot**, int);
 * \brief Fonction de suppression d'un tableau de mot
 *
 * \param lesMots : un pointeur sur un tableau de Mot
 * \param  nbMots: le nombre de mots dans le tableau 
*/
void supprimerTabMots(Mot **lesMots, int nbMots);

/**
 * \fn Mot* D_genererTableauDeMotAvecFichierTexte(FichierTexte, int* );
 * \brief Fonction de création d'un tableau de mot à partir d'un fichier texte rempli de mots
 *
 * \param ficDico : le fichier texte rempli de mots
 * \param  nbMots : un pointeur sur un entier qui représente le nombre de mots dans le tableau
  * \return Mot* : le tableau de mot rempli avec les mots du fichier
*/
Mot* D_genererTableauDeMotAvecFichierTexte(FichierTexte ficDico, int* nbMots);

/**
 * \fn Dictionnaire D_genererDicoAvecTableauDeMots(Mot* , int);
 * \brief Fonction de création d'un dictionnaire à partir d'un tableau de mot
 *
 * \param lesMots : un tableau de Mot
 * \param  nbMots : le nombre de mots dans le tableau
  * \return Dictionnaire : un dictionnaire généré à partir des mots du tableau
*/
Dictionnaire D_genererDicoAvecTableauDeMots(Mot* lesMots, int nbMots);

/**
 * \fn void D_chargerDicoR(Dictionnaire*, FichierTexte);
 * \brief Fonction récursive de complétion d'un dictionnaire à partir d'une sauvegarde en fichier
 *
 * \param unDico : un dictionnaire mis sous forme d'arbre de lettres
 * \param  sauvegardeDico : le fichier où est sauvegardé le dictionnaire
*/
void D_chargerDicoR(Dictionnaire* unDico, FichierTexte sauvegardeDico);

/**
 * \fn void D_sauvegarderDicoR(Dictionnaire*, FichierTexte);
 * \brief Fonction récursive de sauvegarde d'un dictionnaire dans un fichier
 *
 * \param unDico : un dictionnaire mis sous forme d'arbre de lettres
 * \param  sauvegardeDico : le fichier où on veut sauvegarder le dictionnaire
*/
void D_sauvegarderDicoR(Dictionnaire* unDico, FichierTexte sauvegardeDico);

/**
 * \fn Dictionnaire D_genererDicoAvecFichierTexte(FichierTexte);
 * \brief Fonction de création d'un dictionnaire à partir d'un fichier texte
 *
 * \param ficDico: le fichier texte rempli de mots
 * \return Dictionnaire : un dictionnaire généré avec les mots du fichier
*/
Dictionnaire D_genererDicoAvecFichierTexte(FichierTexte ficDico);

/**
 * \fn int D_estUnMotDuDictionnaire(Dictionnaire, Mot);
 * \brief Fonction de vérification de la présence d'un mot dans un dictionnaire
 *
 * \param unDico: le fichier texte rempli de mots
 * \param copieMot : une copie du mot à vérifier (sinon la fonction supprime le mot)
 * \return 0 si le mot n'est pas dans le dictionnaire, 1 sinon
*/
int D_estUnMotDuDictionnaire(Dictionnaire unDico, Mot copieMot);

/**
 * \fn Dictionnaire D_chargerDico(FichierTexte);
 * \brief Fonction de création d'un dictionnaire à partir d'une sauvegarde sous forme de fichier
 *
 * \param sauvegardeDico : le fichier où est sauvegardé le dictionnaire
 * \return Dictionnaire : le dictionnaire correspondant au fichier de sauvegarde
*/
Dictionnaire D_chargerDico(FichierTexte sauvegardeDico);

/**
 * \fn void D_sauvegarderDico(Dictionnaire*, FichierTexte*);
 * \brief Fonction de sauvegarde d'un dictionaire dans un fichie texte
 *
 * \param sauvegardeDico : un pointeur sur le fichier où on veut sauvegarder le dictionnaire
 * \param unDico : un pointeur sur un dictionnaire que l'on veut sauvegarder
*/
void D_sauvegarderDico(Dictionnaire *unDico, FichierTexte *sauvegardeDico);

#endif