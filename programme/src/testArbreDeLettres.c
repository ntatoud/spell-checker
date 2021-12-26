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




void test_arbre_vide(void){
    ArbreDeLettres a = ADL_creerADLVide();
    CU_ASSERT_TRUE(ADL_estVide(a));
    free(a);
}

void test_arbre_non_vide(void){
    ArbreDeLettres a = ADL_creerADL(NULL,NULL,"a",0);
    CU_ASSERT_TRUE(!ADL_estVide(a));
    ADL_supprimer(a);
}

void test_presence_fils_et_frere(void){
    ArbreDeLettres a = ADL_creerADL(NULL,NULL,"a",0);
    ArbreDeLettres b = ADL_creerADL(NULL,NULL,"b",0);
    ArbreDeLettres c = ADL_creerADL(NULL,NULL,"c",0);
    ADL_fixerElement(&a,"A",0);
    ADL_fixerFrere(&a,b);
    ADL_fixerFils(&a,c);
    CU_ASSERT_TRUE(!ADL_estVide(ADL_obtenirFils(a)) && !ADL_estVide(ADL_obtenirFrere(a)));
    ADL_supprimer(a);
}

void test_fixerElement(void){
    ArbreDeLettres a = ADL_creerADL(NULL,NULL,"a",0);
    ADL_fixerElement(&a,"A",0);
    CU_ASSERT_TRUE(strcmp("A",ADL_obtenirLettre(a))==0 && ADL_obtenirEstFinDeMot(a)==0);
    ADL_supprimer(a);
}


void test_fixerEstFinDeMot(void){
    ArbreDeLettres a = ADL_creerADL(NULL,NULL,"a",0);
    ADL_fixerElement(&a,"A",0);
    ADL_fixerEstFinDeMot(&a,1);
    CU_ASSERT_TRUE(a->estFinDeMot==1);
    ADL_supprimer(a);
}

void test_fixerLettre(void){
    ArbreDeLettres a = ADL_creerADL(NULL,NULL,"a",0);
    ADL_fixerLettre(&a,"A");
    CU_ASSERT_TRUE(strcmp((a->lettre),"A")==0);
    ADL_supprimer(a);
}

void test_fixerFrere(void){
    ArbreDeLettres a = ADL_creerADL(NULL,NULL,"a",0);
    ArbreDeLettres b = ADL_creerADL(NULL,NULL,"b",0);
    ADL_fixerElement(&a,"A",0);
    ADL_fixerElement(&b,"B",1);
    ADL_fixerFrere(&a,b);
    CU_ASSERT_TRUE(strcmp(ADL_obtenirLettre(a->frere),"B")==0);
    ADL_supprimer(a);
}


void test_fixerFils(void){
    ArbreDeLettres a = ADL_creerADL(NULL,NULL,"a",0);
    ArbreDeLettres b = ADL_creerADL(NULL,NULL,"b",0);
    ADL_fixerElement(&a,"A",0);
    ADL_fixerElement(&b,"B",1);
    ADL_fixerFils(&a,b);
    CU_ASSERT_TRUE(strcmp(ADL_obtenirLettre((a->fils)),"B")==0);
    ADL_supprimer(a);
}

void test_obtenirLettre(void){    
    ArbreDeLettres a = ADL_creerADL(NULL,NULL,"a",0);
    ADL_fixerLettre(&a,"A");
    CU_ASSERT_TRUE(strcmp(ADL_obtenirLettre(a),"A")==0);
    ADL_supprimer(a);
}

void test_obtenirFrere(void){
    ArbreDeLettres a = ADL_creerADL(NULL,NULL,"a",0);
    ArbreDeLettres b = ADL_creerADL(NULL,NULL,"b",0);
    ADL_fixerLettre(&b,"A");
    ADL_fixerFrere(&a,b);
    CU_ASSERT_TRUE(strcmp(ADL_obtenirLettre(ADL_obtenirFrere(a)),"A")==0);
    ADL_supprimer(a);
}

void test_obtenirFils(void){
    ArbreDeLettres a = ADL_creerADL(NULL,NULL,"a",0);
    ArbreDeLettres b = ADL_creerADL(NULL,NULL,"b",0);
    ADL_fixerElement(&a,"A",0);
    ADL_fixerElement(&b,"B",1);
    ADL_fixerFils(&a,b);
    CU_ASSERT_TRUE(strcmp(ADL_obtenirLettre(ADL_obtenirFils(a)),"B")==0);
    ADL_supprimer(a);
}

void test_estFinDeMot(void){
    ArbreDeLettres a = ADL_creerADL(NULL,NULL,"a",0);
    ADL_fixerElement(&a,"a",0);
    ADL_fixerEstFinDeMot(&a,1);
    CU_ASSERT_TRUE(ADL_obtenirEstFinDeMot(a)==1);
    ADL_supprimer(a);
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

    /* Ajout des tests à la suite de tests boite noire */
    if ((NULL == CU_add_test(pSuite, "1 - la creation d'une liste qui doit etre vide", test_arbre_vide)) 
    || (NULL == CU_add_test(pSuite, "2 - une liste contenant un element n'est pas vide", test_arbre_non_vide))
    || (NULL == CU_add_test(pSuite, "3 - creation d'un arbre avec fils et frere fonctionne", test_presence_fils_et_frere))
    || (NULL == CU_add_test(pSuite, "4 - fixation d'un élément d'arbre de lettres", test_fixerElement))
    || (NULL == CU_add_test(pSuite, "5 - fixer le parametre fin de mot d'un arbre ", test_fixerEstFinDeMot))
    || (NULL == CU_add_test(pSuite, "6 - fixation de la lettre d'un élément d'arbre de lettres ", test_fixerLettre))
    || (NULL == CU_add_test(pSuite, "7 - fixer le fere d'un arbre ", test_fixerFrere))
    || (NULL == CU_add_test(pSuite, "8 - fixer le fils d'un arbre ", test_fixerFils))
    || (NULL == CU_add_test(pSuite, "9 - test pour obtenir la lettre de l'élément dans l'arbre ", test_obtenirLettre))
    || (NULL == CU_add_test(pSuite, "10 - test pour obtenir le frere de l'élément dans l'arbre ", test_obtenirFrere))
    || (NULL == CU_add_test(pSuite, "11 - test pour obtenir le fils de l'élément dans l'arbre ", test_obtenirFils))
    || (NULL == CU_add_test(pSuite, "12 - test pour obtenir l'etat de fin de mot ou non d'un element d'arbre'", test_estFinDeMot))

    )
    {
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