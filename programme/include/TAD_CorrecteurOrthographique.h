#ifndef __TAD_CORRECTEURORTHOGRAPHIQUE__
#define __TAD_CORRECTEURORTHOGRAPHIQUE__
#include "TAD_Mot.h"

/*               TODO
i devrait être non nul en général, j'ai mis unsigned, on pourra mettre une précond
idem comment renvoyer plusieurs éléments?
*/

CO_Mot CO_remplacerIemeLEttre(CO_Mot mot, unsigned int i);

CO_Mot CO_supprimerIemeLEttre(CO_Mot mot, unsigned int i);

CO_Mot CO_inverserDeuxLettresConsecutives(CO_Mot mot, unsigned int i);

CO_Mot CO_insérerLettre(CO_Mot mot, unsigned int i, char c);

(CO_Mot,CO_Mot) CO_decomposerMot(CO_Mot mot, unsigned int i);  //pas sûr

CO_Mot CO_reduireLaCasse(CO_Mot mot);
