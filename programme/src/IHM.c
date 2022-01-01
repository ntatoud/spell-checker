#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "IHM.h"
#include "FichierTexte.h"
#include "Dictionnaire.h"
#include "Mot.h"
#include "corrigerTexte.h"
#define LONGUEUR_MAX_ENTREE 100
#define F_AIDE "-h"
#define F_DICO "-d"
#define F_FICHIER "-f"
#define F_AIDE_ISO "-i"

char* lireChaineEntreeStandard(){
    char *buffer =(char*)malloc(sizeof(char)*LONGUEUR_MAX_ENTREE);
    if(fgets(buffer, LONGUEUR_MAX_ENTREE, stdin))
        return buffer;
    else
        return NULL;
}

void afficherAide(){
    printf("\n---Aide de asispell---\n\n");
    printf("asispell -h : cette aide\n\n");
    printf("asispell -d [nouveau dictionnaire] -f [fichier contenant les mots] : créer le dictionnaire dico a l'aide des mots du fichier (un mot par ligne)\n\n");
    printf("asispell -d [dico] : correction de l'entrée standard a l'aide du dictionnaire dico\n\n");
    printf("Si le programme ne fonctionne pas, vérifiez que l'encodage du terminal est bien : ISO8859-1\n\nasispell -i : aide pour configurer l'encodage du terminal\n\n");
}

void afficherAideISO(){
    printf("Pour Ubuntu 18 :\nonglet Terminal > Définir le codage des caractères > Western ISO8859-1)\n\n");
    printf("Pour Ubuntu 20 :\nonglet Préférences > Profils > Compatibilité > Codage > Codages obsolètes > Occidental-ISO-8859-1\n\n");
    printf("Ne pas oublier de sélectionner le nouveau profil une foisde retour dans le terminal\n");
}

void gererCommandeAide(char *commande){
    if((strcmp(commande, F_AIDE) != 0)&&(strcmp(commande, F_AIDE_ISO) != 0)){
        printf("invalide : commande non reconnue\n");     
    }
    else if(strcmp(commande, F_AIDE) == 0){
        afficherAide();
    }
    else if(strcmp(commande, F_AIDE_ISO) == 0){
        afficherAideISO();
    }
}

void gererCommandeCreerDico(char *commande1, char *fichier1, char *commande2, char *fichier2){
    if(strcmp(commande1, F_DICO) == 0 && (strcmp(commande2, F_FICHIER) == 0)){
        
        FichierTexte dicoSauvegarde = FT_fichierTexte(fichier1);
        FichierTexte dicoRef = FT_fichierTexte(fichier2);
        
        FT_ouvrir(&dicoRef, LECTURE);
        if(FT_estOuvert(dicoRef)){
            FT_fermer(&dicoRef);
            Dictionnaire unDico = D_genererDicoAvecFichierTexte(dicoRef);
            D_sauvegarderDico(&unDico, &dicoSauvegarde);
            printf("Fichier produit : '%s'\n", fichier1);
            ADL_supprimer(&unDico);
        }
        else{
            printf("invalide : le fichier n'existe pas '%s'\n",fichier2);
        }
    }
    else{
        printf("invalide : commande inconnue '%s'\n", commande1);
        afficherAide();
    }
}

void gererCommandeCorrection(char *commande, char *fichier){
    
    if(strcmp(commande, F_DICO) == 0){
        FichierTexte dicoSauvegarde = FT_fichierTexte(fichier);
        FT_ouvrir(&dicoSauvegarde, LECTURE);
        
        if(FT_estOuvert(dicoSauvegarde)){
            FT_fermer(&dicoSauvegarde);
            printf("Pour mettre un terme à la correction : tapez 'quit'\n");
            Dictionnaire leDico = D_chargerDico(dicoSauvegarde);
            int continuer = 1;
            while(continuer){
                char *phraseACorriger = lireChaineEntreeStandard();
                if(strcmp(phraseACorriger, "quit\n") ==0)
                    continuer = 0;
                else
                    CT_corrigerTexte(phraseACorriger, leDico);
                free(phraseACorriger);
            }
            ADL_supprimer(&leDico);
            
        }
        else{
            printf("invalide : le fichier n'existe pas '%s'\n", fichier);
        }
        
    }
    else{
         printf("invalide : commande inconnue '%s'\n", commande);
    }
        
}