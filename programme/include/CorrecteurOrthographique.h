#ifndef __CORRECTEURORTHOGRAPHIQUE__
#define __CORRECTEURORTHOGRAPHIQUE__
#include "Mot.h"

/*               TODO
i devrait être non nul en général, j'ai mis unsigned, on pourra mettre une précond
idem comment renvoyer plusieurs éléments?
*/

Mot CO_remplacerIemeLettre(Mot mot, unsigned int i);

Mot CO_supprimerIemeLettre(Mot mot, unsigned int i);

Mot CO_inverserDeuxLettresConsecutives(Mot mot, unsigned int i);

Mot CO_insererLettre(Mot mot, unsigned int i, char c);

Mot CO_decomposerMot(Mot mot, unsigned int i);  //pas sûr

Mot CO_reduireLaCasse(Mot mot);

#endif