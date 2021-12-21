/**
 * \file CorrecteurOrthographique.h
 * \brief Implantation du TAD CorrecteurOrthogrpahique pour le Projet Algo de correcteur orthographique
 * \author N. Tatoud
 * \version 1.0
 * \date 21/12/2021
 *
 */


#ifndef __CORRECTEUR_ORTHOGRAPHIQUE__
#define __CORRECTEUR_ORTHOGRAPHIQUE__
#include "Dictionnaire.h"
#include "Mot.h"
#include "EnsembleDeMot.h"

/**
 * \brief Le type CorrecteurOrthographique permet de représenter un correcteur et l'ensemble des éléments dont il a besoin.
 *
*/
typedef struct CorrecteurOrthographique{
    Dictionnaire leDictionnaire ; /**< un dictionnaire genéré à partir d'une liste de mots >*/
    Mot motACorriger ; /**< le mot à corriger>*/
    EnsembleDeMot lesCorrections; /** < l'ensemble des corrections possiblespour le mot à corriger> */
} CorrecteurOrthographique;


/**
 * \fn CorrecteurOrthographique CO_correcteur(Dictionnaire, Mot);
 * \brief Fonction de création d'un correcteur
 * \attention assertion : sur unMotFaux
 *
 * \param unDictionnaire : unDictionnaire généré à partir d'une liste de mots
 * \param unMotFaux : un mot qui n'est pas dans le dictionnaire
 * \return CorrecteurOrthographique
*/
CorrecteurOrthographique CO_correcteur(Dictionnaire unDictionnaire, Mot unMotFaux);

/**
 * \fn Mot CO_obtenirMotACorriger(CorrecteurOrthographique);
 * \brief Fonction d'accès au champ motACorriger d'unCorrecteur
 *
 * \param unCorrecteur : un correcteur orthographique
 * \return Mot
*/
Mot CO_obtenirMotACorriger(CorrecteurOrthographique unCorrecteur);

/**
 * \fn Dictionnaire CO_obtenirDictionnaire(CorrecteurOrthographique);
 * \brief Fonction d'accès au champ leDictionnaire d'unCorrecteur
 *
 * \param unCorrecteur : un correcteur orthographique
 * \return Dictionnaire
*/
Dictionnaire CO_obtenirDictionnaire(CorrecteurOrthographique);

/**
 * \fn EnsembleDeMot CO_obtenirCorrections(CorrecteurOrthographique);
 * \brief Fonction d'accès au champ lesCorrections d'unCorrecteur
 *
 * \param unCorrecteur : un correcteur orthographique
 * \return EnsembleDeMot
*/
EnsembleDeMot CO_obtenirCorrections(CorrecteurOrthographique unCorrecteur);

/**
 * \fn void CO_fixerDico(CorrecteurOrthographique*, Dictionnaire);
 * \brief Fonction de modification du champ leDictionnaire d'unCorrecteur
 *
 * \param CorrecteurOrthogrpahique : un pointeur sur un CorrecteurOrthographique
 * \param unDico : un dictionnaire à fournir au correcteur
*/
void CO_fixerDico(CorrecteurOrthographique* unCorrecteur , Dictionnaire unDico);

/**
 * \fn void CO_fixerMotACorriger(CorrecteurOrthographique*, Mot);
 * \brief Fonction de modification du champ motACorriger d' unCorrecteur
 * \attention assertion : sur unMotFaux 
 * 
 * \param unCorrecteur : un pointeur sur un CorrecteurOrthographique
 * \param unMotFaux : un mot qui n'est pas dans le dictionnaire
*/
void CO_fixerMotACorriger(CorrecteurOrthographique* unCorrecteur, Mot unMotFaux);

/**
 * \fn void CO_ajouterNouvellesCorrections (CorrecteurOrthographique*, EnsembleDeMot);
 * \brief Fonction d'ajout de corrections à l'ensemble de mot lesCorrections d'unCorrecteur
 *
 * \param unCorrecteur : un pointeur sur un CorrecteurOrthographique
 * \param desCorrections : de nouvelles corrections qu'on souhaite ajouter au correcteur
 *
 *

*/
void CO_ajouterNouvellesCorrections (CorrecteurOrthographique* unCorrecteur, EnsembleDeMot desCorrections);

/**
 * \fn void CO_trouverCorrectionsPossibles(CorrecteurOrthographique*);
 * \brief Fonction de calcul de l'ensemble des corrections valides d'un mot *
 * \param unCorrecteur : un pointeur sur un CorrecteurOrthographique
*/
void CO_trouverCorrectionsPossibles(CorrecteurOrthographique* unCorrecteur);

/**
 * \fn void CO_strategieRemplacerLettres(CorrecteurOrthographique*);
 * \brief Fonction de calcul de l'ensemble des corrections valides d'un mot en remplaçant les lettres une à une
 *
 * \param unCorrecteur : un pointeur sur un CorrecteurOrthographique
*/
void CO_strategieRemplacerLettres(CorrecteurOrthographique* unCorrecteur);

/**
 * \fn void CO_strategieSupprimerLettres(CorrecteurOrthographique*);
 * \brief Fonction de calcul de l'ensemble des corrections valides d'un mot en supprimant les lettres une à une
 *
 * \param unCorrecteur : un pointeur sur un CorrecteurOrthographique
*/
void CO_strategieSupprimerLettres(CorrecteurOrthographique* unCorrecteur);

/**
 * \fn void CO_strategieInverserDeuxLettresConsecutives(CorrecteurOrthographique*);
 * \brief Fonction de calcul de l'ensemble des corrections valides d'un mot en inversant les lettres consecutives deux à deux
 *
 * \param unCorrecteur : un pointeur sur un CorrecteurOrthographique
*/
void CO_strategieInverserDeuxLettresConsecutives(CorrecteurOrthographique* unCorrecteur);

/**
 * \fn void CO_strategieInsererLettres(CorrecteurOrthographique*);
 * \brief Fonction de calcul de l'ensemble des corrections valides d'un mot en insérant des lettres à toutes les positions du mot 
 *
 * \param unCorrecteur : un pointeur sur un CorrecteurOrthographique
*/
void CO_strategieInsererLettres(CorrecteurOrthographique* unCorrecteur);

/**
 * \fn void CO_strategieDecomposerMot(CorrecteurOrthographique*);
 * \brief Fonction de calcul de l'ensemble des corrections valides d'un mot en séparant le mot en deux parties de toutes les façons possibles
 *
 * \param unCorrecteur : un pointeur sur un CorrecteurOrthographique
*/
void CO_strategieDecomposerMot(CorrecteurOrthographique* unCorrecteur); 



#endif