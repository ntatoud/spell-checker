#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include <stdbool.h>
#include "Mot.h"
#include "ListeChaineeDeMot.h"

int init_suite_success(void){
    return 0;
}

int clean_suite_success(void){
    return 0;
}

ListeChaineeDeMot creer_liste_avec_un_mot(){
    ListeChaineeDeMot l = LCDM_listeChaineeDeMot();
    char *chaine1="chaine1";
    Mot unMot = M_creerUnMot(chaine1);
    LCDM_ajouter(&l, unMot);
    return l;
}

ListeChaineeDeMot creer_liste_avec_deux_mot(){
    ListeChaineeDeMot l = LCDM_listeChaineeDeMot();
    char *chaine1="chaine1";
    char *chaine2="chaine2";
    Mot unMot = M_creerUnMot(chaine1);
    Mot unAutreMot = M_creerUnMot(chaine2);
    LCDM_ajouter(&l, unMot);
    LCDM_ajouter(&l, unAutreMot);
    return l;
}

void test_liste_vide(void){
    ListeChaineeDeMot l = LCDM_listeChaineeDeMot();
    CU_ASSERT_TRUE(LCDM_estVide(l));
    LCDM_supprimer(&l);
}

void test_liste_non_vide(void){
    ListeChaineeDeMot l = creer_liste_avec_un_mot();
    CU_ASSERT_TRUE(!LCDM_estVide(l));
    LCDM_supprimer(&l);
}

void test_mot_ajoute_en_tete(void){
    ListeChaineeDeMot l = LCDM_listeChaineeDeMot();
    char *chaine1="chaine1";
    Mot unMot = M_creerUnMot(chaine1);
    LCDM_ajouter(&l, unMot);
    CU_ASSERT_EQUAL(M_sontIdentiques(LCDM_obtenirMot(l), unMot),true);
    LCDM_supprimer(&l);
}

void test_supprimer_mot(void){
    ListeChaineeDeMot l1 = LCDM_listeChaineeDeMot();
    ListeChaineeDeMot l2 = LCDM_listeChaineeDeMot();
    char *chaine1="chaine1";
    char *chaine2="chaine2";
    char *chaine3="chaine3";
    Mot unMot = M_creerUnMot(chaine1);
    Mot unAutreMot = M_creerUnMot(chaine2);
    Mot toujoursPlusDeMot = M_creerUnMot(chaine3);
    LCDM_ajouter(&l1, unMot);
    LCDM_ajouter(&l1, unAutreMot);
    LCDM_ajouter(&l1, toujoursPlusDeMot);
    LCDM_ajouter(&l2, unMot);
    LCDM_ajouter(&l2, unAutreMot);
    LCDM_supprimerMot(&l1,toujoursPlusDeMot);
    CU_ASSERT_TRUE(LCDM_egale(l1, l2));
}

void test_obtenir_liste_suivante(void){
    ListeChaineeDeMot lSuivante;
    ListeChaineeDeMot l = LCDM_listeChaineeDeMot();
    char *chaine1="chaine1";
    char *chaine2="chaine2";
    Mot unMot = M_creerUnMot(chaine1);
    Mot unAutreMot = M_creerUnMot(chaine2);
    LCDM_ajouter(&l, unMot);
    lSuivante = l;
    LCDM_ajouter(&l, unAutreMot);
    CU_ASSERT_PTR_EQUAL(LCDM_obtenirListeSuivante(l), lSuivante);
    LCDM_supprimer(&l);
}

void test_fixer_liste_suivante(void){
    ListeChaineeDeMot l1 = LCDM_listeChaineeDeMot();
    ListeChaineeDeMot l2 = LCDM_listeChaineeDeMot();
    ListeChaineeDeMot temp = LCDM_listeChaineeDeMot();
    char *chaine1="chaine1";
    char *chaine2="chaine2";
    char *chaine3="chaine3";
    Mot unMot = M_creerUnMot(chaine1);
    Mot unAutreMot = M_creerUnMot(chaine2);
    Mot toujoursPlusDeMot = M_creerUnMot(chaine3);
    LCDM_ajouter(&l1, unMot);
    temp = l1;
    LCDM_ajouter(&l1, unAutreMot);
    LCDM_ajouter(&l2, toujoursPlusDeMot);
    LCDM_fixerListeSuivante(&l1, l2);
    CU_ASSERT_PTR_EQUAL(LCDM_obtenirListeSuivante(l1), l2);
    LCDM_supprimer(&l1);
    LCDM_supprimer(&temp);
}

void test_copie_egale(void){
    ListeChaineeDeMot l1 = creer_liste_avec_deux_mot();
    ListeChaineeDeMot l2 = LCDM_copier(l1);
    CU_ASSERT_TRUE(LCDM_egale(l1, l2));
    LCDM_supprimer(&l1);
    LCDM_supprimer(&l2);
}

void test_differente(void){
    ListeChaineeDeMot l1 = creer_liste_avec_deux_mot();
    ListeChaineeDeMot l2 = creer_liste_avec_un_mot();
    CU_ASSERT_FALSE(LCDM_egale(l1, l2));
    LCDM_supprimer(&l1);
    LCDM_supprimer(&l2);
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
    if ((NULL == CU_add_test(pSuite, "la creation d'une liste qui doit etre vide", test_liste_vide)) 
    || (NULL == CU_add_test(pSuite, "une liste contenant un element n'est pas vide", test_liste_non_vide)) 
    || (NULL == CU_add_test(pSuite, "un element ajoute est en tete de liste", test_mot_ajoute_en_tete)) 
    || (NULL == CU_add_test(pSuite, "supprimer un mot", test_supprimer_mot))
    || (NULL == CU_add_test(pSuite, "obtenir liste suivante", test_obtenir_liste_suivante)) 
    || (NULL == CU_add_test(pSuite, "fixer liste suivante", test_fixer_liste_suivante)) 
    || (NULL == CU_add_test(pSuite, "une liste et sa copie sont egales", test_copie_egale)) 
    || (NULL == CU_add_test(pSuite, "deux listes differentes ne sont pas egales", test_differente))){
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