#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Mot.h"
#include <string.h>
#include <ctype.h>

int M_estUnCaractereAlphabetique(char c)
{
    char tmp = c;
    return (isalpha(tmp) || M_estUnCaractereAAccent(c));
}

int M_estUnCaractereAAccent(char c)
{
    return (c == '-' || c == 'ù' || c == 'à' || c == 'é' || c == 'è' || c == 'ç' || c == 'ï' || c == 'É' || c == 'È' || c == 'Ç' || c == 'À' || c == 'â' || c == 'Â' || c == 'ë' || c == 'Ë' || c == 'ô' || c == 'Ô' || c == 'î' || c == 'ê' || c == 'û' || c == 'ü' || c == 'ä' || c == 'ö');
}

int M_estUnMotValide(char *c)
{
    assert(strlen(c) > 0);
    int longueurChaine = strlen(c);
    int estValide = 1;
    int i = 0;
    while (estValide && i < longueurChaine - 1)
    {
        if (!M_estUnCaractereAlphabetique(c[i]))
        {
            estValide = 0;
        }
        i = i + 1;
    }
    return estValide;
}

Mot M_copierMot(Mot unMot)
{
    Mot copie;
    copie = M_creerUnMot(unMot.chaine);
    return copie;
}

Mot M_creerUnMot(char *c)
{
    assert(M_estUnMotValide(c));
    Mot unMot;
    unMot.chaine = M_reduireLaCasseDUneChaine(c);
    unMot.longueur = strlen(unMot.chaine);
    return unMot;
}

unsigned int M_longueurMot(Mot unMot)
{
    return unMot.longueur;
}

char *M_obtenirChaine(Mot unMot)
{
    return unMot.chaine;
}

char M_iemeCaractere(Mot unMot, unsigned int i)
{
    assert(i <= M_longueurMot(unMot) && i > 0);
    return unMot.chaine[i - 1];
}

int M_sontIdentiques(Mot mot1, Mot mot2)
{
    return mot1.longueur == mot2.longueur && strcmp(mot1.chaine, mot2.chaine) == 0;
}

void M_fixerIemeCaractere(Mot *unMot, unsigned int i, char c)
{
    assert(M_estUnCaractereAlphabetique(c) && i <= M_longueurMot(*unMot) + 1);
    unMot->chaine[i - 1] = c;
}

void M_fixerLongueur(Mot *unMot, unsigned int i)
{
    unMot->longueur = i;
}

void M_supprimerIemeLettre(Mot *unMot, unsigned int indiceLettreASupprimer)
{
    assert(indiceLettreASupprimer <= M_longueurMot(*unMot));

    int indiceLettreCourante = indiceLettreASupprimer;
    while (indiceLettreCourante < M_longueurMot(*unMot))
    {
        M_fixerIemeCaractere(unMot, indiceLettreCourante, M_iemeCaractere(*unMot, indiceLettreCourante + 1));
        indiceLettreCourante++;
    }
    unMot->chaine[indiceLettreCourante - 1] = '\0';
    M_fixerLongueur(unMot, M_longueurMot(*unMot) - 1);
}

void M_inverserDeuxLettresConsecutives(Mot *unMot, unsigned int i)
{
    assert(i < M_longueurMot(*unMot) && i > 0);
    char temp;
    temp = M_iemeCaractere(*unMot, i);
    M_fixerIemeCaractere(unMot, i, M_iemeCaractere(*unMot, i + 1));
    M_fixerIemeCaractere(unMot, i + 1, temp);
}

void M_insererLettre(Mot *unMot, unsigned int i, char c)
{
    assert(i <= M_longueurMot(*unMot) + 1);
    unMot->chaine = realloc(unMot->chaine, sizeof(char) * M_longueurMot(*unMot) + 2);
    for (int j = strlen(unMot->chaine); j > i - 1; j--)
    {
        M_fixerIemeCaractere(unMot, j + 1, M_iemeCaractere(*unMot, j));
    }
    M_fixerLongueur(unMot, M_longueurMot(*unMot) + 1);
    unMot->chaine[M_longueurMot(*unMot)] = '\0';
    unMot->chaine[i - 1] = c;
}

Mot M_decomposerMot(Mot *unMot, unsigned int i)
{ //le ieme caractere est dans la deuxième partie du mot
    assert(i <= M_longueurMot(*unMot) && i > 1);
    char *chaineGauche = (char *)malloc(i + 1);
    int j;
    for (j = 0; j < i - 1; j++)
    {
        chaineGauche[j] = M_iemeCaractere(*unMot, 1);
        M_supprimerIemeLettre(unMot, 1);
    }
    chaineGauche[j] = '\0';
    Mot motGauche = M_creerUnMot(chaineGauche);
    free(chaineGauche);
    return motGauche;
}

char M_reduireLaCasseDUnCaractere(char car)
{
    char c = car;
    switch (c)
    {

    case 'À':
        c = 'à';
        break;

    case 'Â':
        c = 'â';
        break;

    case 'É':
        c = 'é';
        break;

    case 'È':
        c = 'è';
        break;

    case 'Ç':
        c = 'ç';
        break;

    case 'Ê':
        c = 'ê';
        break;

    case 'Ô':
        c = 'ô';
        break;

    case 'Ï':
        c = 'à';
        break;

    case 'Î':
        c = 'à';
        break;

    case 'Û':
        c = 'û';
        break;

    case 'Ù':
        c = 'ù';
        break;

    default:
        c = (tolower((unsigned char)c));
    }
    return c;
}

char *M_reduireLaCasseDUneChaine(char *chaine)
{
    assert(strlen(chaine) > 0);
    char *minuscule = malloc(strlen(chaine) + 2);
    strcpy(minuscule, chaine);
    for (int i = 0; i < strlen(chaine); i++)
    {
        minuscule[i] = M_reduireLaCasseDUnCaractere((char)chaine[i]);
    }
    return minuscule;
}

void M_supprimerMot(Mot *unMot)
{
    if (M_longueurMot(*unMot) > 0)
        free(unMot->chaine);
    unMot->longueur = 0;
}