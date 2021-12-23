#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include <stdbool.h>
#include "Mot.h"
#include "ArbreDeLettres.h"

int init_suite_success(void){
    return 0;
}

int clean_suite_success(void){
    return 0;
}

ArbreDeLettres creer_arbre_avec_une_lettre(){
    ArbreDeLettres fils = ADL_creerADLVide();
    ArbreDeLettres frere = ADL_creerADLVide();
    ArbreDeLettres a = ADL_creerADL(fils,frere,'c',1);
    return a;
}

ArbreDeLettres creer_arbre_avec_fils_frere(){
    ArbreDeLettres fils = ADL_creerADLVide();
    ArbreDeLettres frere = ADL_creerADLVide();
    ADL_fixerElement(fils,'a',0);
    ADL_fixerElement(frere,'b',0);
    ArbreDeLettres a = ADL_creerADL(fils,frere,'c',0);
    return a;
}

void test_arbre_vide(void){
    ArbreDeLettres a = ADL_creerADLVide();
    CU_ASSERT_TRUE(ADL_estVide(a));
    free(a);
}

void test_arbre_non_vide(void){
    ArbreDeLettres a = creer_arbre_avec_une_lettre();
    CU_ASSERT_TRUE(!ADL_estVide(a));
    ADL_supprimer(&a);
}




int main(int argc, char **argv){
    CU_pSuite pSuite = NULL;

    /* initialisation du registre de tests */
    if (CUE_SUCCESS != CU_initialize_registry()){
        return CU_get_error();
    }
    /* ajout d'une suite de test */
    pSuite = CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
    if (NULL == pSuite){
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Ajout des tests � la suite de tests boite noire */
    if ((NULL == CU_add_test(pSuite, "la creation d'une liste qui doit etre vide", test_arbre_vide)) || (NULL == CU_add_test(pSuite, "une liste contenant un element n'est pas vide", test_arbre_non_vide))){
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