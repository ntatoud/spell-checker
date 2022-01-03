#ifndef __CORRIGER_TEXTE__
#define __CORRIGER_TEXTE__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Dictionnaire.h"
#include "CorrecteurOrthographique.h"
#include "Mot.h"
#include "EnsembleDeMot.h"

/*!
 * procédure qui affiiche pour chaque mot s'il est bon, et son emplacement dans la chaine, le nombre de corrections et les corrections si le mot est faux
 *\param[in] char* la chaine d'entrée
 *\param[in] Dictionnaire le dictionnaire utilisé pour la correction
 */

void CT_corrigerTexte(char *, Dictionnaire);

/*!
 * fonction qui indique si le caractère est un séparateur de mots ou non 
 *\param[in] char le caractère d'entrée
 *\param[out] int, le booleen de sortie
 */

int CT_estUnSeparateur(char);

/*!
 * fonction qui crée une sous chaine d'une chaine de caractères
 *\param[in] char* la chaine d'entrée
 *\param[in] int, la borne gauche de la sous chaine
 *\param[in] int, la borne droite de la sous chaine
 *\param[out] char*, la sous chaine de sortie
 */

char *CT_creerSousChaine(char *, unsigned int, unsigned int);

/*!
 * fonction qui trouve les corrections d'un mot et remplit un correcteur 
 *\param[in] Dictionnaire le dictionnaire utilisé
 *\param[in] Mot, le mot à corriger
 *\param[out] CorrecteurOrthographique, correcteur de sortie
 */

CorrecteurOrthographique CT_trouverCorrections(Dictionnaire dico, Mot unMot);

/*!
 * procédure qui affiche les corrections d'un mot faux
 *\param[in] int l'indice de début de mot dans la chaine entrée par l'utilisateur
 *\param[in] CorrecteurOrthographique, le correcteur utilisé
 */

void CT_afficherCorrection(int indiceDebutMot, CorrecteurOrthographique correcteur);

/*!
 * procédure qui trouve affiche les corrections d'un mot faux
 *\param[in] char* chaine entrée par l'utilisateur
 *\param[in] int l'indice de début de mot dans la chaine entrée par l'utilisateur
 *\param[in] int l'indice de fin de mot dans la chaine entrée par l'utilisateur
 *\param[in] Dictionnaire dictionnaire utilisé
 */

void CT_trouverEtAfficherCorrection(char *chaine, int indiceDebutMot, int position, Dictionnaire dico);

#endif