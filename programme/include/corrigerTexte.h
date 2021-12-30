#ifndef __CORRIGER_TEXTE__
#define __CORRIGER_TEXTE__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Dictionnaire.h"
#include "CorrecteurOrthographique.h"
#include "Mot.h"
#include "EnsembleDeMot.h"

void CT_corrigerTexte(char*, Dictionnaire);

int CT_estUnSeparateur(char);

char* CT_creerSousChaine(char*,unsigned int,unsigned int);

CorrecteurOrthographique CT_trouverCorrections(Dictionnaire dico,Mot unMot);

void CT_afficherCorrection(int indiceDebutMot,CorrecteurOrthographique correcteur);

void CT_trouverEtAfficherCorrection(char* chaine, int indiceDebutMot,int position, Dictionnaire dico);

#endif