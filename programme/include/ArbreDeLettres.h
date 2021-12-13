#ifndef __ARBRE_DE_LETTRES__
#define __ARBRE_DE_LETTRES__
#endif

typedef struct ADL *ArbreDeLettres;

typedef struct ADL{
	ArbreDeLettres fils, frere;
	char lettre;
	int estFinDeMot;
} ADL;