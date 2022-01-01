/**
 * \file FichierTexte.h
 * \brief Implantation du type FichierTexte pour le Projet Algo de correcteur orthographique
 * \authors N. Tatoud
 * \version 1.1
 * \date 01/01/2022
 *
 */

#ifndef _FICHIER_TEXTE__
#define _FICHIER_TEXTE__
#include<stdio.h>

typedef enum {LECTURE, ECRITURE} Mode;


/**
 * \brief Le type FichierTexte permet d'effectuer des opérations sur un fichier texte de façon simplifiée
 *
*/
/* Partie privée */
typedef struct FichierTexte {
	FILE* fichier; /**< le fichier >*/
	char* nom; /**< le nom du fichier >*/
	Mode mode; /**< le mode fu fichier : lecture ou ecriture >*/
} FichierTexte;


/**
 * \fn void supprimerRetourChariot(char *);
 * \brief Fonction de transformation de chaine de caractère pour retirer le '\n'
 *
 * \param chaine : la chaine à transformer
*/
void supprimerRetourChariot(char *chaine);

/* Partie publique */

/**
 * \fn FT_fichierTexte(char*);
 * \brief Fonction de création d'un FichierTexte
 *
 * \param nomFichier : le nom du fichier
 * \return FichierTexte
*/
FichierTexte FT_fichierTexte(char *nomDuFichier);

/**
 * \fn void FT_ouvrir(FichierTexte*, Mode);
 * \brief Fonction d'ouverture de fichier, doit exister si mode = lecture, est créé sinon
 * \attention : assertion sur mode
 *
 * \param fichier : un pointeur sur un fichier texte
 * \return mode : le mode d'ouverture désiré (lecture ou ecriture)
*/
void FT_ouvrir(FichierTexte *fichier, Mode mode);

/**
 * \fn void FT_fermer(FichierTexte*);
 * \brief Fonction de fermeture d'un fichier
 *
 * \param nomFichier : le nom du fichier
*/
void FT_fermer(FichierTexte *fichier);

/**
 * \fn unsigned int FT_estOuvert(FichierTexte);
 * \brief Fonction de vérification de l'état d'un fichier
 *
 * \param fichier : un fichier texte
 * \return 1 si le fichier est ouvert, 0 sinon
*/
unsigned int FT_estOuvert(FichierTexte fichier);
Mode FT_obtenirMode(FichierTexte fichier);

/**
 * \fn unsigned int FT_estEnFinDeFichier(FichierTexte);
 * \brief Fonction de vérification de la position du curseur dans le fichier
 *
 * \param fichier : un fichier texte
 * \return 1 si le curseur est en fin de fichier, 0 sinon
*/
unsigned int FT_estEnFinDeFichier(FichierTexte fichier);

/**
 * \fn char* FT_lireChaineSansLeRetourChariot(FichierTexte);
 * \brief Fonction de lecture d'une chaine de caractère dans un fichier en supprimant le retour chariot en fin de ligne
 *
 * \param fichier : un fichier texte
 * \return char* : la chaine lue sans le retour chariot
*/
char* FT_lireChaineSansLeRetourChariot(FichierTexte fichier);

/**
 * \fn char* FT_lireChaine(FichierTexte);
 * \brief Fonction de lecture d'une chaine de caractère dans un fichier
 * \attention : assertion sur fichier.mode et la position du curseur dans fichie
 * 
 * \param fichier : un fichier texte
 * \return char* : la chaine lue
*/
char* FT_lireChaine(FichierTexte fichier);

/**
 * \fn void FT_ecrireCaractere(FichierTexte*, char);
 * \brief Fonction d' écriture d'un caractère dans un fichier
 * \attention : assertion sur fichier.mode et la position du curseur dans fichier
 * 
 * \param fichier : un pointeur sur un fichier texte
 * \param caractere : le caractère à écrire dans le fichier
*/
void FT_ecrireCaractere(FichierTexte *fichier, char caractere);

/**
 * \fn char FT_lireCaractere(FichierTexte);
 * \brief Fonction de lecture d'un caratère dans un fichier texte
 * \attention : assertion sur fichier.mode et la position du curseur dans fichier
 * 
 * \param fichier : un fichier texte
 * \return char : le caractère lu
*/
char FT_lireCaractere(FichierTexte fichier);

/**
 * \fn char* FT_lireElement(FichierTexte);
 * \brief Fonction de lecture d'un élément de la forme <lettre, estFinDeMot, aUnFils, aUnFrere> dans un fichier texte
 * \attention : assertion sur fichier.mode et la position du curseur dans fichier
 * 
 * \param fichier : un fichier texte
 * \return char* : l'élèment lu
*/
char* FT_lireElement(FichierTexte fichier);

/**
 * \fn int FT_verifierIdDico(FichierTexte)
 * \brief Fonction de vérification de l'identité d'un dictionnaire, pour s'assurer de sa compatibilité avec le programme
 * \attention : assertion sur fichier.mode et la position du curseur dans fichier
 * 
 * \param fichier : un fichier texte
 * \return 1 si l'identifiant est le bon, 0 sinon
*/
int FT_verifierIdDico(FichierTexte fichier);

/**
 * \fn void FT_ecrireChaine(FichierTexte*)
 * \brief Fonction d' écriture d'une chaine de caractères dans un fichier
 * \attention : assertion sur fichier.mode et la position du curseur dans fichier
 * 
 * \param fichier : un pointeur sur un fichier texte
*/
void FT_ecrireChaine(FichierTexte *fichier, char *chaine);

/**
 * \fn void FT_ecrireID(FichierTexte*)
 * \brief Fonction d' écriture de l'identité d'un fichier pour assurer sa compatibilité avec le programme
 * \attention : assertion sur fichier.mode et la position du curseur dans fichier
 * 
 * \param fichier : un pointeur sur un fichier texte
*/
void FT_ecrireID(FichierTexte *fichier);

#endif
