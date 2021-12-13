#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Mot.h"
#include "CorrecteurOrthographique.h"

Mot CO_remplacerIemeLettre(Mot unMot, unsigned int i, char uneLettre){ 
    CO_supprimerIemeLettre(unMot, i-1);
    CO_insererLettre(unMot, i-1, uneLettre);
    return unMot;
}

Mot CO_supprimerIemeLettre(Mot unMot, unsigned int i){
    assert(i > 1 && M_longueurMot(unMot) < i);
    
    unsigned int j;
    // Décalage de toutes les lettres vers la gauche (on écrase la lettre à supprimer)
    for(j=i+1; j < M_longueurMot(unMot); j++)
        M_fixerIemeCaractere(&unMot, j-1, M_iemeCaractere(unMot, j));
    // On oublie pas de vider la dernière qui a été dupliquée
    M_fixerIemeCaractere(&unMot, M_longueurMot(unMot) - 1, ' ');

    M_fixerLongueur(&unMot, M_longueurMot(unMot) - 1);
    return unMot;
}

Mot CO_inverserDeuxLettresConsecutives(Mot unMot, unsigned int i){
    assert(i > 1 && M_longueurMot(unMot) < i);
    char lettre1, lettre2; 
    lettre1 = M_iemeCaractere(unMot, i);
    lettre2 = M_iemeCaractere(unMot, i+1);
    CO_remplacerIemeLettre(unMot, lettre2, i);
    CO_remplacerIemeLettre(unMot, lettre1, i+1);
    return unMot;
}

Mot CO_insererLettre(Mot unMot, unsigned int i, char uneLettre){
    assert(i > 1 && M_longueurMot(unMot) < i);
    unsigned int j;
    // Décalage de toutes les lettres vers la droite (le mot contient une lettre de plus)
    for(j= M_longueurMot(unMot)+1; j > i; j--)
        M_fixerIemeCaractere(&unMot, j, M_iemeCaractere(unMot, j-1));
    // On oublie pas de vider la dernière qui a été dupliquée
    M_fixerIemeCaractere(&unMot, i , uneLettre);

    M_fixerLongueur(&unMot, M_longueurMot(unMot) + 1);
    return unMot;
}

Mot CO_decomposerMot(Mot *mot1, unsigned int i){
    Mot mot2; 
    mot2.chaine="a";
    mot2.longueur=1;
    return mot2;
}

Mot CO_reduireLaCasse(Mot mot){
    Mot unMot;
    unMot.chaine="a";
    unMot.longueur=1;
    return unMot;
}
