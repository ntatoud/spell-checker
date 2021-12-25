#ifndef __MOT__
#define __MOT__
#include <stdlib.h>
#include <assert.h>


typedef struct Mot{
  char * chaine;
  unsigned int longueur; 
} Mot;

/*!
*Dans tout mot, nous utilisons des char* de taille 1 pour les caractères : cela nous permet d'utiliser des caractères accentués
*fonction qui permet de savoir si un caractère est alphabétique
*\pre la chaine en entrée doit être de taille 1
*\param[in] c le caractère que l'on teste
*\return un entier 1 pour une réponse positive, 0 sinon
*/

int M_estUnCaractereAlphabetique(char* c);

/*!
*ieme lettre est au sens où on compte à partir de 1, il est à la "ieme place", indice i est au sens où on compte à partir de 0
*procédure qui permet décaler la partie droite de la chaine d'un mot d'un cran vers la droite à partir de la ieme lettre
*\pre i doit être inférieur à la longueur du mot
*\param[in] unMot le mot que l'on souhaite modifier
*\param[in] i place à partir de laquelle on décale
*/

void M_decalerVersLaDroite(Mot *unMot,unsigned int i);

/*!
*fonction qui permet créer une copie d'un mot
*\param[in] unMot le mot que l'on souhaite copier
*\return la copie du mot
*/

Mot M_copierMot(Mot unMot);

/*!
*fonction qui permet savoir si la chaine de caractères peut former un mot, c'est à dire ne contient ni espace ni caractère spécial
*\pre la chaine doit avoir une longueur non nulle
*\param[in] c la chaine à tester
*\return l'entier 1 si la réponse est positive, 0 sinon
*/


int M_estUnMotValide(char* c);

/*!
*fonction qui permet de créer un mot à partir d'une chaine de caractères
*\pre estUnMotValide de la chaine de caractères
*\param[in] c la chaine de caractères en entrée
*\return le mot créé
*/

Mot M_creerUnMot(char* c);

/*!
*fonction qui renvoie la longueur d'un mot
*\param[in] unMot le mot en entrée
*\return l'entier positif correspondant à la longueur du mot
*/

unsigned int M_longueurMot(Mot mot);

/*!
*fonction qui permet récupérer le caractère à la ieme place dans un mot
*\pre i doit être inférieur à la longueur du mot
*\param[in] unMot mot d'entrée
*\param[in] i emplacement du caractère recherché
*\return le mot créé
*/

char* M_iemeCaractere(Mot mot, unsigned int i);

/*!
*fonction qui permet savoir si deux mots sont strictements identiques
*\param[in] mot1 premier mot d'entrée
*\param[in] mot2 second mot d'entrée
*\return l'entier 1 ou 0 selon la réponse positive ou négative
*/

int M_sontIdentiques(Mot mot1, Mot mot2);
void M_fixerIemeCaractere(Mot*, unsigned int, char);
void M_fixerLongueur(Mot*, unsigned int);
Mot M_remplacerIemeLettre(Mot, unsigned int, char);
Mot M_supprimerIemeLettre(Mot, unsigned int );
Mot M_inverserDeuxLettresConsecutives(Mot, unsigned int);
Mot M_insererIemeLettre(Mot, unsigned int, char);
Mot M_decomposerMot(Mot*, unsigned int); 
Mot M_reduireLaCasse(Mot);

/*!
*procédure qui permet de changer le caractère de la ieme place dans la chaine d'un mot
*\pre i est inférieur à la longueur de la chaine, c est un caractère alphabétique
*\param[in] unMot mot d'entrée/sortie
*\param[in] i place du caractère à changer
*\param[in] c chaine de 1 caractère (pour autoriser les accents) à insérer
*/

void M_fixerIemeCaractere(Mot* unMot, unsigned int i, char* c);

/*!
*procédure qui permet de changer le parametre longueur de la structure d'un mot
*\param[in] unMot mot d'entrée/sortie
*\param[in] i nouvelle longueur
*/

void M_fixerLongueur(Mot* unMot, unsigned int i);

/*!
*procédure qui permet de supprimer le caractère de la ieme place dans la chaine d'un mot
*\pre i est inférieur à la longueur de la chaine
*\param[in] unMot mot d'entrée/sortie
*\param[in] i place du caractère à retirer
*/

void M_supprimerIemeLettre(Mot* unMot, unsigned int i);

/*!
*procédure qui permet de d'interchanger les caractères des places i et i+1 dans la chaine d'un mot
*\pre i est inférieur à la longueur de la chaine-1
*\param[in] unMot mot d'entrée/sortie
*\param[in] i place du premier des deux caractère
*/

void M_inverserDeuxLettresConsecutives(Mot* unMot, unsigned int i);

/*!
*procédure qui permet d'insérer un caractère à la ieme place dans la chaine d'un mot
*\pre i est inférieur à la longueur de la chaine+1
*\param[in] unMot mot d'entrée/sortie
*\param[in] i place du caractère à insérer
*/

void M_insererLettre(Mot* unMot, unsigned int i, char* c);

/*!
*fonction qui permet de couper un mot en deux à l'emplacement i (la lettre à la place i appartiendra au second mot)
*\pre i est inférieur à la longueur de la chaine+1
*\param[in] unMot mot d'entrée/sortie (en sortie il sera la partie droite)
*\param[in] i place de la coupure
*\return renvoie le mot de la parie gauche
*/

Mot M_decomposerMot(Mot* unMot, unsigned int i); //on modifie le mot et récupère le mot de sortie

/*!
*procédure qui permet de passer les majuscules d'une chaine de caractère en minuscules
*\pre chaine non vide
*\param[in] chaine chaine de caractère d'entrée 
*/

void M_reduireLaCasse(char** chaine);


Mot CO_remplacerIemeLettre(Mot, unsigned int, char);
EnsembleDeMot CO_supprimerIemeLettre(Mot, unsigned int );
Mot CO_inverserDeuxLettresConsecutives(Mot, unsigned int );
EnsembleDeMot CO_insererLettre(Mot, unsigned int, char);
Mot CO_decomposerMot(Mot*, unsigned int); 
Mot CO_reduireLaCasse(Mot);


#endif
