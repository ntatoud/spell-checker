#ifndef __CORRECTEUR_ORTHOGRAPHIQUE__
#define __CORRECTEUR_ORTHOGRAPHIQUE__
#include "Mot.h"

Mot CO_remplacerIemeLettre(Mot mot, unsigned int i);
Mot CO_supprimerIemeLettre(Mot mot, unsigned int i);
Mot CO_inverserDeuxLettresConsecutives(Mot mot, unsigned int i);
Mot CO_insererLettre(Mot mot, unsigned int i, char c);
Mot CO_decomposerMot(Mot mot, unsigned int i);  //pas sûr
Mot CO_reduireLaCasse(Mot mot);

#endif