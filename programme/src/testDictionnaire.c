#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "Dictionnaire.h"
#include "Mot.h"

#define TRUE 1
#define FALSE 0
#define FIC_DICO_TEST "dicoTest.txt"

int init_suite_success(void)
{
    return 0;
}

int clean_suite_success(void)
{
    return 0;
}

Mot *creer_tableau_mots_du_fichier()
{
    int nbMots = 5;
    Mot *lesMots = (Mot *)malloc((sizeof(Mot) * nbMots));
    lesMots[0] = M_creerUnMot("non");
    lesMots[1] = M_creerUnMot("je");
    lesMots[2] = M_creerUnMot("suis");
    lesMots[3] = M_creerUnMot("ton");
    lesMots[4] = M_creerUnMot("père");

    return lesMots;
}

void test_absent_si_non_insere(void)
{
    Dictionnaire unDico = ADL_creerADLVide();
    Mot unMot = M_creerUnMot("delestre");

    CU_ASSERT_FALSE(D_estUnMotDuDictionnaire(unDico, M_copierMot(unMot)));

    ADL_supprimer(&unDico);
    M_supprimerMot(&unMot);
}

void test_present_si_insere(void)
{
    Dictionnaire unDico = ADL_creerADLVide();
    Mot unMot = M_creerUnMot("gaüzère");
    Mot copie = M_copierMot(unMot);

    D_insererMot(&unDico, unMot); // on met une copie du mot car insererMot modife le mot

    CU_ASSERT_TRUE(D_estUnMotDuDictionnaire(unDico, copie));

    ADL_supprimer(&unDico);
    M_supprimerMot(&unMot);
}

void test_arbre_depuis_mots(void)
{
    Mot *lesMots = creer_tableau_mots_du_fichier();
    int nbMots = 5;
    Dictionnaire unDico = D_genererDicoAvecTableauDeMots(lesMots, nbMots);

    for (int i = 0; i < nbMots; i++)
    {
        CU_ASSERT_TRUE(D_estUnMotDuDictionnaire(unDico, M_copierMot(lesMots[i])));
    }

    supprimerTabMots(&lesMots, nbMots);
    ADL_supprimer(&unDico);
}

int main(int argc, char **argv)
{
    CU_pSuite pSuite = NULL;

    /* initialisation du registre de tests */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* ajout d'une suite de test */
    pSuite = CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Ajout des tests à la suite de tests boite noire */
    if ((NULL == CU_add_test(pSuite, "1 - Un mot n'est pas dans le dictionnaire s'il n'a pas été inséré", test_absent_si_non_insere)) || (NULL == CU_add_test(pSuite, "2 - Un mot est dans le dictionnaire s'il a été inséré", test_present_si_insere)) || (NULL == CU_add_test(pSuite, "3 - Un dictionnaire rempli avec un tableau de mots contient bien tous les mots", test_arbre_depuis_mots)))
    {
        // Pas de tests des fonctions avec des fichiers car c'est juste de la lecture et de l'affichage
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Lancement des tests */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    /* Nettoyage du registre */
    CU_cleanup_registry();
    return CU_get_error();
}
