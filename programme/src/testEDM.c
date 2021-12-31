#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "EnsembleDeMot.h"
#include "Mot.h"

#define TRUE 1
#define FALSE 0

int init_suite_success(void){
    return 0;
}

int clean_suite_success(void){
    return 0;
}

void creer_mots_A(Mot *mot1, Mot *mot2, Mot *mot3){
    *mot1 = M_creerUnMot("test");
    *mot2 = M_creerUnMot("unitaires");
    *mot3 = M_creerUnMot("ensembleDeMot");
}

void creer_mots_B(Mot *mot1, Mot *mot2, Mot *mot3){
    *mot1 = M_creerUnMot("test");
    *mot2 = M_creerUnMot("sans");
    *mot3 = M_creerUnMot("problèmes");
}

void test_ensemble_vide(void){
    EnsembleDeMot e = ensembleDeMot();

    CU_ASSERT_TRUE(EDM_cardinalite(e) == 0);

    EDM_vider(&e);
}

void test_ajouter_non_present(void){
    int c1, c2;
    Mot mot4 = M_creerUnMot("sans");
    EnsembleDeMot e = ensembleDeMot();
    Mot mot1, mot2, mot3;
    creer_mots_A(&mot1, &mot2, &mot3);
    EDM_ajouter(&e, mot1);
    EDM_ajouter(&e, mot2);
    EDM_ajouter(&e, mot3);

    c1 = EDM_cardinalite(e);
    EDM_ajouter(&e, mot4);
    c2 = EDM_cardinalite(e);

    CU_ASSERT_TRUE(c1 + 1 == c2);
    EDM_vider(&e);
    M_supprimerMot(&mot1);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
    M_supprimerMot(&mot4);
}

void test_ajouter_present(void){
    int c1, c2;
    EnsembleDeMot e = ensembleDeMot();
    Mot mot1, mot2, mot3;
    creer_mots_A(&mot1, &mot2, &mot3);
    EDM_ajouter(&e, mot1);
    EDM_ajouter(&e, mot2);
    EDM_ajouter(&e, mot3);

    c1 = EDM_cardinalite(e);
    EDM_ajouter(&e, mot1);
    c2 = EDM_cardinalite(e);

    CU_ASSERT_TRUE(c1 == c2);

    EDM_vider(&e);
    M_supprimerMot(&mot1);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
}

void test_present_apres_ajout(void){
    Mot mot5 = M_creerUnMot("problèmes");
    EnsembleDeMot e = ensembleDeMot();
    Mot mot1, mot2, mot3;
    creer_mots_A(&mot1, &mot2, &mot3);
    EDM_ajouter(&e, mot1);
    EDM_ajouter(&e, mot2);
    EDM_ajouter(&e, mot3);

    EDM_ajouter(&e, mot5);

    CU_ASSERT_TRUE(EDM_estPresent(e, mot5));

    EDM_vider(&e);
    M_supprimerMot(&mot5);
    M_supprimerMot(&mot1);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
}

void test_retirer_present(void){
    int c1, c2;
    EnsembleDeMot e = ensembleDeMot();
    Mot mot1, mot2, mot3;
    creer_mots_A(&mot1, &mot2, &mot3);
    EDM_ajouter(&e, mot1);
    EDM_ajouter(&e, mot2);
    EDM_ajouter(&e, mot3);

    c1 = EDM_cardinalite(e);
    EDM_retirer(&e, mot2);
    c2 = EDM_cardinalite(e);

    CU_ASSERT_TRUE(c1 - 1 == c2);

    EDM_vider(&e);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot1);
    M_supprimerMot(&mot3);
}

void test_retirer_non_present(void){
    int c1, c2;
    Mot mot4 = M_creerUnMot("sans");
    EnsembleDeMot e = ensembleDeMot();
    Mot mot1, mot2, mot3;
    creer_mots_A(&mot1, &mot2, &mot3);
    EDM_ajouter(&e, mot1);
    EDM_ajouter(&e, mot2);
    EDM_ajouter(&e, mot3);

    c1 = EDM_cardinalite(e);
    EDM_retirer(&e, mot4);
    c2 = EDM_cardinalite(e);

    CU_ASSERT_TRUE(c1 == c2);

    EDM_vider(&e);
    M_supprimerMot(&mot1);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
    M_supprimerMot(&mot4);
}

void test_absent_apres_retrait(void){
    EnsembleDeMot e = ensembleDeMot();
    Mot mot1, mot2, mot3;
    creer_mots_A(&mot1, &mot2, &mot3);
    EDM_ajouter(&e, mot1);
    EDM_ajouter(&e, mot2);
    EDM_ajouter(&e, mot3);

    EDM_retirer(&e, mot2);
    CU_ASSERT_FALSE(EDM_estPresent(e, mot2));

    EDM_vider(&e);
    M_supprimerMot(&mot1);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
}

void test_union(void){
    EnsembleDeMot e1 = ensembleDeMot();
    Mot mot1, mot1bis, mot2, mot3, mot4, mot5;
    creer_mots_A(&mot1, &mot2, &mot3);
    EDM_ajouter(&e1, mot1);
    EDM_ajouter(&e1, mot2);
    EDM_ajouter(&e1, mot3);

    EnsembleDeMot e2 = ensembleDeMot();
    creer_mots_B(&mot1bis, &mot4, &mot5);
    EDM_ajouter(&e2, mot1);
    EDM_ajouter(&e2, mot4);
    EDM_ajouter(&e2, mot5);

    EnsembleDeMot e3 = EDM_union(e1, e2);

    CU_ASSERT_TRUE(EDM_estPresent(e3, mot1) 
                && EDM_estPresent(e3, mot2) 
                && EDM_estPresent(e3, mot3)
                && EDM_estPresent(e3, mot4) 
                && EDM_estPresent(e3, mot5));

    EDM_vider(&e1);
    EDM_vider(&e2);
    EDM_vider(&e3);
    M_supprimerMot(&mot1);
    M_supprimerMot(&mot1bis);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
    M_supprimerMot(&mot4);
    M_supprimerMot(&mot5);
}

void test_egalite_meme_ensemble(void){
    EnsembleDeMot e1 = ensembleDeMot();
    Mot mot1, mot2, mot3;
    creer_mots_A(&mot1, &mot2, &mot3);
    EDM_ajouter(&e1, mot1);
    EDM_ajouter(&e1, mot2);
    EDM_ajouter(&e1, mot3);

    CU_ASSERT_TRUE(EDM_egale(e1, e1));

    EDM_vider(&e1);
    M_supprimerMot(&mot1);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
}

void test_egalite_ensembles_differents(void){
    EnsembleDeMot e1 = ensembleDeMot();
    Mot mot1, mot1bis, mot2, mot3, mot4, mot5;
    creer_mots_A(&mot1, &mot2, &mot3);
    EDM_ajouter(&e1, mot1);
    EDM_ajouter(&e1, mot2);
    EDM_ajouter(&e1, mot3);

    EnsembleDeMot e2 = ensembleDeMot();
    creer_mots_B(&mot1bis, &mot4, &mot5);
    EDM_ajouter(&e2, mot1);
    EDM_ajouter(&e2, mot4);
    EDM_ajouter(&e2, mot5);

    CU_ASSERT_FALSE(EDM_egale(e1, e2));

    EDM_vider(&e1);
    EDM_vider(&e2);

    M_supprimerMot(&mot1);
    M_supprimerMot(&mot1bis);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
    M_supprimerMot(&mot4);
    M_supprimerMot(&mot5);
}

void test_copier(void){
    EnsembleDeMot e1 = ensembleDeMot();
    Mot mot1, mot2, mot3;
    creer_mots_A(&mot1, &mot2, &mot3);
    EDM_ajouter(&e1, mot1);
    EDM_ajouter(&e1, mot2);
    EDM_ajouter(&e1, mot3);

    EnsembleDeMot e2 = EDM_copier(e1);

    CU_ASSERT_TRUE(EDM_egale(e1, e2));

    EDM_vider(&e1);
    EDM_vider(&e2);
    M_supprimerMot(&mot1);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
}

void test_obtenir_element(){
    EnsembleDeMot e = ensembleDeMot();
    Mot mot1, mot2, mot3, mot3test;
    creer_mots_A(&mot1, &mot2, &mot3);
    EDM_ajouter(&e, mot1);
    EDM_ajouter(&e, mot2);
    EDM_ajouter(&e, mot3);

    mot3test = EDM_obtenirMot(e);
    CU_ASSERT_TRUE(M_sontIdentiques(mot3, mot3test));

    EDM_vider(&e);
    M_supprimerMot(&mot1);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
}

int main(int argc, char **argv){
    CU_pSuite pSuite = NULL;

    /* initialisation du registre de tests */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* ajout d'une suite de test */
    pSuite = CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
    if (NULL == pSuite){
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Ajout des tests à la suite de tests boite noire */
    if ((NULL == CU_add_test(pSuite, "1 - La création d'un ensemble doit etre vide", test_ensemble_vide)) 
    || (NULL == CU_add_test(pSuite, "2 - Ajouter un mot non present incrémente la cardinalité", test_ajouter_non_present)) 
    || (NULL == CU_add_test(pSuite, "3 - Ajouter un mot present n'incrémente pas la cardinalité", test_ajouter_present)) 
    || (NULL == CU_add_test(pSuite, "4 - un élément ajouté est present", test_present_apres_ajout)) 
    || (NULL == CU_add_test(pSuite, "5 - retirer un élement présent décrémente la cardinalité", test_retirer_non_present)) 
    || (NULL == CU_add_test(pSuite, "6 - retirer un élement present ne decremente pas la cardinalite", test_retirer_present)) 
    || (NULL == CU_add_test(pSuite, "7 - un element retire n'est plus present", test_absent_apres_retrait)) 
    || (NULL == CU_add_test(pSuite, "8 - union", test_union)) 
    || (NULL == CU_add_test(pSuite, "9 - un ensemble est égal a lui meme", test_egalite_meme_ensemble)) 
    || (NULL == CU_add_test(pSuite, "10 - un ensemble est different d'un autre ensemble", test_egalite_ensembles_differents)) 
    || (NULL == CU_add_test(pSuite, "11 - un ensemble est égal a une de ses copies", test_copier)) 
    || (NULL == CU_add_test(pSuite, "12 - obtenir un élément d'un ensemble renvoie le dernier élément ajouté", test_obtenir_element))){
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
