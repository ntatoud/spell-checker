#ifndef __ARBRE_DE_LETTRES__
#define __ARBRE_DE_LETTRES__
#include <errno.h>
/**
 * \brief Le type arbre binaire permet de stocker des mots sous forme de lettres
 *
*/

typedef struct ADL *ArbreDeLettres;

typedef struct ADL
{
	ArbreDeLettres fils, frere; /**< le fils et le frere de l'ADL>*/
	char lettre; /**<la lettre de l'ADL>*/
	int estFinDeMot; /**<le booléen qui indique si c'es une fin de mot >*/
} ADL;

#define ADL_ERREUR_MEMOIRE 1

ArbreDeLettres ADL_creerADLVide();

/*!
 * Fonction qui permet de savoir si un arbre est vide ou non
 *\param[in] ArbreDeLettres l'arbre à tester
 *\param[out] int, 1 si l'arbre est vide, 0 sinon 
 */
int ADL_estVide(ArbreDeLettres);

/*!
 * Fonction qui permet de créer un arbre à partir d'une lettre, du booléen, du fils et du frère 
 *\param[in] ArbreDeLettres le frère
 *\param[in] ArbreDeLettres le fils
 *\param[in] char la lettre
 *\param[in] int qui permet de savoir si c'est une fin de mot
 *\return ArbreDeLettres, l'arbre créé
 */
ArbreDeLettres ADL_creerADL(ArbreDeLettres, ArbreDeLettres, char, int);

/*!
 * Fonction qui permet de fixer si la lettre est une fin de mot
 *\param[in] ArbreDeLettres l'arbre à fixer
 *\param[in] int, 1 si la lettre est une fin de mot, 0 sinon 
 */
void ADL_fixerEstFinDeMot(ArbreDeLettres *, int);

/*!
 * Fonction qui permet de fixer la lettre d'un arbre
 *\param[in] ArbreDeLettres l'arbre à fixer
 *\param[in] char, la lettre à fixer
 */
void ADL_fixerLettre(ArbreDeLettres *, char);

/*!
 * Fonction qui permet de fixer la lettre et le booléen d'un arbre
 *\param[in] ArbreDeLettres l'arbre à fixer
 *\param[in] char, la lettre à fixer
 *\param[in] int le booléen qui indique une fin de mot
 */
void ADL_fixerElement(ArbreDeLettres *, char, int);

/*!
 * Fonction qui permet de fixer le frère d'un arbre
 *\param[in] ArbreDeLettres* l'arbre
 *\param[in] ArbreDeLettres, le frère
 */
void ADL_fixerFrere(ArbreDeLettres *, ArbreDeLettres);

/*!
 * Fonction qui permet de fixer le fils d'un arbre
 *\param[in] ArbreDeLettres* l'arbre
 *\param[in] ArbreDeLettres, le fils
 */
void ADL_fixerFils(ArbreDeLettres *, ArbreDeLettres);

/*!
 * Fonction qui permet d'obtenir le fils d'un arbre
 *\param[in] ArbreDeLettres l'arbre
 *\return ArbreDeLettres, le fils
 */
ArbreDeLettres ADL_obtenirFils(ArbreDeLettres);

/*!
 * Fonction qui permet d'obtenir le frère d'un arbre
 *\param[in] ArbreDeLettres l'arbre
 *\return ArbreDeLettres, le frère
 */
ArbreDeLettres ADL_obtenirFrere(ArbreDeLettres);

/*!
 * Fonction qui permet d'obtenir la lettre d'un arbre
 *\param[in] ArbreDeLettres l'arbre
 *\return char, la lettre
 */
char ADL_obtenirLettre(ArbreDeLettres);

/*!
 * Fonction qui permet d'obtenir le estUneFinDeMot d'un arbre
 *\param[in] ArbreDeLettres l'arbre
 *\return int, le booléen
 */
int ADL_obtenirEstFinDeMot(ArbreDeLettres);

/*!
 * Procédure qui permet de supprimer un arbre
 *\param[in] ArbreDeLettres arbre à supprimer
 */
void ADL_supprimer(ArbreDeLettres *arbre);

#endif