#include <stdlib.h>
#include <assert.h>
#include <string.h>


Fichier fichierTexte(char* nomDuFichier) {
	Fichier fichier;
	fichier.file = NULL;
	fichier.nom = nomDuFichier;
	
	return fichier;
}

void ouvrir(Fichier *fichier, Mode mode) {
	assert(!FichierTexte_estOuvert(*fichier));

	if (mode == ECRITURE) {
			fichier->file = fopen(fichier->nom, "w+");
			fichier->mode = mode;
	}
	else if (mode == LECTURE) {
			fichier->file = fopen(fichier->nom, "r");
			fichier->mode = mode;
	}
	else printf("ce n est pas le bon mode\n");

}

void fermer(Fichier *fichier) {
	if (FichierTexte_estOuvert(*fichier)) {
		fclose(fichier->file);
		fichier->file = NULL;
	}
}

unsigned int estOuvert(Fichier fichier) {
	return fichier.file != NULL;
}

Mode FichierTexte_mode(Fichier fichier) {
	return fichier.mode;
}

unsigned int finFichier(Fichier fichier) {
	unsigned int resultat;
	assert((fichier.mode == LECTURE) && FichierTexte_estOuvert(fichier));
	resultat = (fgetc(fichier.file)==EOF);  
	fseek(fichier.file, -1, SEEK_CUR);
	return (resultat);
}

void ecrireChaine(Fichier *fichier, char* chaine) {
	assert(FichierTexte_estOuvert(*fichier) && (FichierTexte_mode(*fichier) == ECRITURE));	
	fputs(chaine, fichier->file);
}

char* lireChaine(Fichier fichier) {
	assert(FichierTexte_estOuvert(fichier) && (FichierTexte_mode(fichier) == LECTURE) && !FichierTexte_finFichier(fichier));

	char* chaine = malloc(NB_LETTRES_MAX * sizeof(char) +1 );
	fgets(chaine, NB_LETTRES_MAX, fichier.file);
	return chaine;
}

void ecrireCaractere(Fichier *fichier, char caractere) {
	assert(FichierTexte_estOuvert(*fichier) && (FichierTexte_mode(*fichier) == ECRITURE));
	fputc(caractere, fichier->file);
}

char lireCaractere(Fichier fichier) {
	assert(FichierTexte_estOuvert(fichier) && (FichierTexte_mode(fichier) == LECTURE) && !FichierTexte_finFichier(fichier));
	return fgetc(fichier.file);
}



