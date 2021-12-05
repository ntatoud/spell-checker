#ifndef __CORRIGERTEXTE__
#define __CORRIGERTEXTE__
#include "TAD_Mot.h"
#include "TAD_Dictionnaire.h"
/*			TODO
je ne savais pas comment mettre plusieurs élémnts en sortie, idem pour un ensemble

pour les opérations du bas de l'arbre que je n'ai pas écrites, est ce qu'on fait des fonctions ou des procédures ?

*/



(ensemble{CO_Mot},CO_Mot) corrigerTexte(char c[]);  //pas sûr

ensemble(CO_Mot) reconnaitreLesMots(char c[]);

char[] creerSousChaine(char c[]);

CO_Mot reconnaitreUnMot(char c[]);



bool estUnmotDuDictionnaire(CO_Dictionnaire dico,CO_Mot mot);

(ensemble{CO_Mot}, CO_Mot) trouverCorrectionsValides(CO_Mot mot);

ensemble{CO_Mot} verifierCorrections(CO_Dictionnaire dico,ensemble{CO_Mot} ensembleMots);

ensemble{CO_Mot} trouverCorrections(CO_Mot mot);

//void remplacerLesLettres(
