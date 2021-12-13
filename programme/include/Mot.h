#ifndef __MOT__
#define __MOT__

typedef struct Mot{
  char chaine; 
  unsigned int longueur; 
} Mot;

int M_estUnMotValide(char c);
Mot M_creerUnMot(char c);
unsigned int M_longueurMot(Mot mot);
char M_iemeCaractere(Mot mot);
int M_sontIdentiques(Mot mot1, Mot mot2);

#endif
