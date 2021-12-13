#ifndef __CORRECTEUR_ORTHOGRAPHIQUE__
#define __CORRECTEUR_ORTHOGRAPHIQUE__
#include "Mot.h"



Mot CO_remplacerIemeLettre(Mot, unsigned int, char);
Mot CO_supprimerIemeLettre(Mot, unsigned int );
Mot CO_inverserDeuxLettresConsecutives(Mot, unsigned int );
Mot CO_insererLettre(Mot, unsigned int, char);
Mot CO_decomposerMot(Mot*, unsigned int); 
Mot CO_reduireLaCasse(Mot);

#endif