#include <stdio.h>
#include<CUnit/Basic.h>
#include <string.h>
#include "EnsembleDeMot.h"
#include "Mot.h"

#define TRUE 1
#define FALSE 0

int init_suite_success(void) { 
  return 0; 
}

int clean_suite_success(void) { 
  return 0; 
}

void creer_mots_A(Mot *mot1, Mot *mot2, Mot *mot3){
  mot1->chaine = "test";
  mot1->longueur = strlen("test");
  mot2->chaine = "unitaires";
  mot2->longueur = strlen("unitaires");
  mot3->chaine = "ensembledemot";
  mot3->longueur = strlen("ensembledemot");


/*  *mot1 = M_creerUnMot("test");
  *mot2 = M_creerUnMot("unitaires");
  *mot3 = M_creerUnMot("ensembleDeMot");
*/
}

void creer_mots_B(Mot *mot1, Mot *mot2, Mot *mot3){
  mot1->chaine = "test";
  mot1->longueur = strlen("test");
  mot2->chaine = "sans";
  mot2->longueur = strlen("sans");
  mot3->chaine = "problèmes";
  mot3->longueur = strlen("problèmes");
/*  
  *mot1 = M_creerUnMot("test");
  *mot2 = M_creerUnMot("sans");
  *mot3 = M_creerUnMot("problèmes");
*/
}

EnsembleDeMot creer_ensemble_A() {
  EnsembleDeMot a = ensembleDeMot();
  Mot mot1, mot2, mot3;
  creer_mots_A(&mot1, &mot2, &mot3);

  EDM_ajouter(&a, mot1);
  EDM_ajouter(&a, mot2);
  EDM_ajouter(&a, mot3);  
  return a;
}

EnsembleDeMot creer_ensemble_B() {
  EnsembleDeMot b = ensembleDeMot();
  Mot mot1, mot4, mot5;
  creer_mots_B(&mot1, &mot4, &mot5);
  EDM_ajouter(&b,mot1);
  EDM_ajouter(&b,mot4);
  EDM_ajouter(&b,mot5);  
  return b;
}

void test_ensemble_vide(void){
  EnsembleDeMot e = ensembleDeMot();

  CU_ASSERT_TRUE(EDM_cardinalite(e)==0);

  EDM_vider(&e);
}

void test_ajouter_non_present(void){
  int c1,c2;
  Mot mot1, mot4, mot5;
  creer_mots_B(&mot1, &mot4, &mot5);
  EnsembleDeMot e = creer_ensemble_A();

  c1 = EDM_cardinalite(e);
  EDM_ajouter(&e,mot4);
  c2 = EDM_cardinalite(e);  

  CU_ASSERT_TRUE(c1+1==c2);

  EDM_vider(&e);
}

void test_ajouter_present(void){
  int c1,c2;
  Mot mot1, mot4, mot5;
  creer_mots_B(&mot1, &mot4, &mot5);

  EnsembleDeMot e = creer_ensemble_A();
  c1 = EDM_cardinalite(e);
  EDM_ajouter(&e, mot1);
  c2 = EDM_cardinalite(e); 

  CU_ASSERT_TRUE(c1==c2);

  EDM_vider(&e);
}

void test_present_apres_ajout(void){
  Mot mot1, mot4, mot5;
  creer_mots_B(&mot1, &mot4, &mot5);
  

  EnsembleDeMot e = creer_ensemble_A();
  EDM_ajouter(&e, mot5); 

  CU_ASSERT_TRUE(EDM_estPresent(e,mot5));

  EDM_vider(&e);
}

void test_retirer_present(void){
  int c1,c2;
  Mot mot1, mot2, mot3;
  creer_mots_A(&mot1, &mot2, &mot3);
  EnsembleDeMot e = creer_ensemble_A();

  c1 = EDM_cardinalite(e);
  EDM_retirer(&e, mot2);
  c2 = EDM_cardinalite(e);  

  CU_ASSERT_TRUE(c1-1==c2);

  EDM_vider(&e);
}

void test_retirer_non_present(void){
  int c1,c2;
  Mot mot1, mot4, mot5;
  creer_mots_B(&mot1, &mot4, &mot5);
  EnsembleDeMot e = creer_ensemble_A();
  c1 = EDM_cardinalite(e);
  EDM_retirer(&e, mot4);
  c2 = EDM_cardinalite(e); 

  CU_ASSERT_TRUE(c1==c2);

  EDM_vider(&e);
}

void test_absent_apres_retrait(void){
  Mot mot1, mot2, mot3;
  creer_mots_A(&mot1, &mot2, &mot3);
  EnsembleDeMot e = creer_ensemble_A();
  EDM_retirer(&e, mot2); 
  CU_ASSERT_FALSE(EDM_estPresent(e, mot2));
  EDM_vider(&e);
}

void test_union(void){
  EnsembleDeMot e1 = creer_ensemble_A();
  EnsembleDeMot e2 = creer_ensemble_B();
  EnsembleDeMot e3 = EDM_union(e1,e2);
  Mot mot1, mot2, mot3, mot4, mot5;
  creer_mots_A(&mot1, &mot2, &mot3);
  creer_mots_B(&mot1, &mot4, &mot5);
  CU_ASSERT_TRUE(EDM_estPresent(e3, mot1) 
                && EDM_estPresent(e3, mot2) 
                && EDM_estPresent(e3, mot3) 
                && EDM_estPresent(e3, mot4) 
                && EDM_estPresent(e3, mot5));

  EDM_vider(&e1);
  EDM_vider(&e2);
  EDM_vider(&e3);
}

void test_intersection(void){
  EnsembleDeMot e1 = creer_ensemble_A();
  EnsembleDeMot e2 = creer_ensemble_B();
  EnsembleDeMot e3 = EDM_intersection(e1,e2);
  Mot mot1, mot2, mot3, mot4, mot5;
  creer_mots_A(&mot1, &mot2, &mot3);
  creer_mots_B(&mot1, &mot4, &mot5);
  CU_ASSERT_TRUE(EDM_estPresent(e3, mot1) 
                && !(EDM_estPresent(e3, mot2) 
                && EDM_estPresent(e3, mot3) 
                && EDM_estPresent(e3, mot4)  
                && EDM_estPresent(e3, mot5)));

  EDM_vider(&e1);
  EDM_vider(&e2);
  EDM_vider(&e3);
}

void test_soustraction(void){
  EnsembleDeMot e1 = creer_ensemble_A();
  EnsembleDeMot e2 = creer_ensemble_B();
  EnsembleDeMot e3 = EDM_soustraction(e1,e2);
  Mot mot1, mot2, mot3, mot4, mot5;
  creer_mots_A(&mot1, &mot2, &mot3);
  creer_mots_B(&mot1, &mot4, &mot5);

  CU_ASSERT_TRUE(!EDM_estPresent(e3, mot1)
                && EDM_estPresent(e3, mot2) 
                && EDM_estPresent(e3, mot3));

  EDM_vider(&e1);
  EDM_vider(&e2);
  EDM_vider(&e3);
}

void test_egalite_meme_ensemble(void){
  EnsembleDeMot e1 = creer_ensemble_A();

  CU_ASSERT_TRUE(EDM_egale(e1,e1));

  EDM_vider(&e1);
}

void test_egalite_ensembles_differents(void){
  EnsembleDeMot e1 = creer_ensemble_A();
  EnsembleDeMot e2 = creer_ensemble_B();

  CU_ASSERT_FALSE(EDM_egale(e1, e2));

  EDM_vider(&e1);
  EDM_vider(&e2);
}

void test_copier(void){
  EnsembleDeMot e1 = creer_ensemble_A();
  EnsembleDeMot e2 = EDM_copier(e1);

  CU_ASSERT_TRUE(EDM_egale(e1, e2));

  EDM_vider(&e1);
  EDM_vider(&e2);
}

void test_obtenir_element(){
  EnsembleDeMot e1 = creer_ensemble_A();
  Mot mot1, mot2, mot3, mot3test;
  creer_mots_A(&mot1, &mot2, &mot3);
  mot3test = EDM_obtenirMot(e1);
  //pritnf("%s, %s", mot3.chaine, )
  CU_ASSERT_TRUE(M_sontIdentiques(mot3, mot3test));

  EDM_vider(&e1);
}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "1 - la creation d'un ensemble doit etre vide", test_ensemble_vide)) 
      || (NULL == CU_add_test(pSuite, "2 - ajouter un mot non present incrémente la cardinalite", test_ajouter_non_present))  
      || (NULL == CU_add_test(pSuite, "3 - ajouter un mot present n'incremente pas la cardinalite", test_ajouter_present)) 
      || (NULL == CU_add_test(pSuite, "4 - un element ajoute est present", test_present_apres_ajout)) 
      || (NULL == CU_add_test(pSuite, "5 - retirer un lement non present decremente la cardinalite", test_retirer_non_present))  
      || (NULL == CU_add_test(pSuite, "6 - retirer un element present ne decremente pas la cardinalite", test_retirer_present)) 
      || (NULL == CU_add_test(pSuite, "7 - un element retire n'est plus present", test_absent_apres_retrait)) 
      || (NULL == CU_add_test(pSuite, "8 - union", test_union)) 
      || (NULL == CU_add_test(pSuite, "9 - intersection", test_intersection)) 
      || (NULL == CU_add_test(pSuite, "10 - soustraction", test_intersection)) 
      || (NULL == CU_add_test(pSuite, "11 - un ensemble est égal a lui meme", test_egalite_meme_ensemble))
      || (NULL == CU_add_test(pSuite, "12 - un ensemble est different d'un autre ensemble", test_egalite_ensembles_differents))
      || (NULL == CU_add_test(pSuite, "13 - un ensemble est égal a une de ses copies", test_copier)) 
      || (NULL == CU_add_test(pSuite, "14 - obtenir un élément d'un ensemble renvoie le dernier élément ajouté", test_obtenir_element))
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
