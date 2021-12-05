#ifndef __TAD_MOT__
#define __TAD_MOT__

typedef struct {
  char c[]; 
  unsigned int longueur; 
} CO_Mot;

bool CO_estUnMotValide(char c[]);

CO_Mot CO_CreerUnMot(char c[]);

unsigned int CO_longueurMot(CO_Mot mot);

char CO_IemeCaractere(CO_Mot mot);

bool CO_SontIdentiques(CO_Mot mot1, CO_Mot mot2);

#endif
