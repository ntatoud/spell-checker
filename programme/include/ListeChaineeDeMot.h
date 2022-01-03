#ifndef __LISTE_CHAINEE_DE_MOT__
#define __LISTE_CHAINEE_DE_MOT__
#include <errno.h>
#include "Mot.h"

/* Partie privee */

/**
 * \brief Le type Noeud est un élément d'une liste chainée de mot
 *
*/

typedef struct Noeud *ListeChaineeDeMot;
typedef struct Noeud
{
	Mot mot; /**<le mot du Noeud>*/
	ListeChaineeDeMot listeSuivante;/**<la liste suivante>*/
} Noeud;

/* Partie publique */
#define LCDM_ERREUR_MEMOIRE 1

ListeChaineeDeMot LCDM_listeChaineeDeMot();

/*!
 * Fonction qui permet de savoir si une liste est vide ou non
 *\param[in] ListeChaineeDeMot la liste à tester
 *\param[out] int, 1 si la liste est vide, 0 sinon 
 */
int LCDM_estVide(ListeChaineeDeMot);

/*!
 * Fonction qui permet d'ajouter un Mot à une liste
 *\param[in] ListeChaineeDeMot la liste où l'on veut ajouter le Mot
 *\param[in] Mot le Mot à ajouter 
 */
void LCDM_ajouter(ListeChaineeDeMot *, Mot);

/*!
 * Fonction qui permet d'obtenir un mot
 *\pre la liste ne doit pas être vide
 *\param[in] ListeChaineeDeMot la liste qui contient le mot
 *\param[out] Mot le mot en tête de la liste  
 */
Mot LCDM_obtenirMot(ListeChaineeDeMot);

/*!
 * Fonction qui permet d'obtenir la liste suivante
 *\pre la liste ne doit pas être vide
 *\param[in] ListeChaineeDeMot la liste de départ
 *\param[out] ListeChaineeDeMot la liste suivante 
 */
ListeChaineeDeMot LCDM_obtenirListeSuivante(ListeChaineeDeMot);

/*!
 * Fonction qui permet de fixer la liste suivante
 *\pre la liste ne doit pas être vide
 *\param[in] ListeChaineeDeMot la liste de départ
 *\param[in] ListeChaineeDeMot la liste suivante 
 */
void LCDM_fixerListeSuivante(ListeChaineeDeMot *, ListeChaineeDeMot);

/*!
 * Fonction qui permet de fixer le mot
 *\pre la liste ne doit pas être vide
 *\param[in] ListeChaineeDeMot la liste de départ
 *\param[in] Mot le mot à fixer
 */
void LCDM_fixerMot(ListeChaineeDeMot *, Mot);

/*!
 * Fonction qui permet de supprimer un mot
 *\pre la liste ne doit pas être vide
 *\param[in] ListeChaineeDeMot la liste de départ
 *\param[in] Mot le mot à fixer
 */
void LCDM_supprimerMot(ListeChaineeDeMot *, Mot);

/*!
 * Fonction qui permet de supprimer la tete de la liste
 *\pre la liste ne doit pas être vide
 *\param[in] ListeChaineeDeMot la liste dont on veut supprimer la tête
 */
void LCDM_supprimerTete(ListeChaineeDeMot *);

/*!
 * Fonction qui permet de supprimer une liste
 *\param[in] ListeChaineeDeMot la liste à supprimer
 */
void LCDM_supprimer(ListeChaineeDeMot *);

/*!
 * Fonction qui permet de copier une liste
 *\param[in] ListeChaineeDeMot la liste de départ
 *\param[out] ListeChaineeDeMot la copie de la liste
 */
ListeChaineeDeMot LCDM_copier(ListeChaineeDeMot);

/*!
 * Fonction qui permet de savoir si deux listes sont égales
 *\param[in] ListeChaineeDeMot1 la 1ère liste à comparer
 *\param[in] ListeChaineeDeMot2 la 2ème liste à comparer
 *\param[out] int, 1 si les listes sont identiques, 0 sinon 
 */
int LCDM_egale(ListeChaineeDeMot, ListeChaineeDeMot);
#endif
