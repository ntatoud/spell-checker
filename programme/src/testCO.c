#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include <stdbool.h>
#include "Mot.h"
#include "CorrecteurOrthographique.h"
#include "EnsembleDeMot.h"
#include "Dictionnaire.h"


int init_suite_success(void){
    return 0;
}

int clean_suite_success(void){
    return 0;
}

char** creer_tableau_mot(){
    char** lesMots=(char**)malloc((sizeof(char)*5)*50);
    lesMots[0] = "bvec";
    lesMots[1] = "avec";
    lesMots[2] = "avac";
    lesMots[3] = "avem";
    lesMots[4] = "arride";
    lesMots[5] = "attaque";
    return lesMots;
}



Dictionnaire creer_dictionnaire(){
    char** lesChaines = creer_tableau_mot();
    Mot* lesMots = (Mot*)malloc(((sizeof(char)*7)+sizeof(int))*54);
    for(int i=0;i<6;i++){
        lesMots[i]=M_creerUnMot(lesChaines[i]);
    }
    Dictionnaire dico = D_genererArbreAvecTableauDeMots(lesMots,6);
    free(lesChaines);
    return dico;
}


char** creer_ensemble_solution(){
    char** lesMots=(char**)malloc((sizeof(char)*5)*61);
    lesMots[0] = "aveö";
    lesMots[1] = "avea";
    lesMots[2] = "aveb";
    lesMots[3] = "avec";
    lesMots[4] = "aved";
    lesMots[5] = "avee";
    lesMots[6] = "avef";
    lesMots[7] = "aveg";
    lesMots[8] = "aveh";
    lesMots[9] = "avei";
    lesMots[10] = "avej";
    lesMots[11] = "avek";
    lesMots[12] = "avel";
    lesMots[13] = "avem";
    lesMots[14] = "aven";
    lesMots[15] = "aveo";
    lesMots[16] = "avep";
    lesMots[17] = "aveq";
    lesMots[18] = "aver";
    lesMots[19] = "aves";
    lesMots[20] = "avet";
    lesMots[21] = "aveu";
    lesMots[22] = "avev";
    lesMots[23] = "avew";
    lesMots[24] = "avex";
    lesMots[25] = "avey";
    lesMots[26] = "avez";
    lesMots[27] = "aveà";
    lesMots[28] = "aveé";
    lesMots[29] = "aveè";
    lesMots[30] = "aveë";
    lesMots[31] = "aveù";
    lesMots[32] = "aveû";
    lesMots[33] = "aveê";
    lesMots[34] = "aveî";
    lesMots[35] = "aveï";
    lesMots[36] = "aveç";
    lesMots[37] = "aveô";
    return lesMots;
}

char** creer_ensemble_solution_inserer(){
    char** lesMots=(char**)malloc((sizeof(char)*6)*100);
    lesMots[0] = "aveöc";
    lesMots[1] = "aveac";
    lesMots[2] = "avebc";
    lesMots[3] = "avecc";
    lesMots[4] = "avedc";
    lesMots[5] = "aveec";
    lesMots[6] = "avefc";
    lesMots[7] = "avegc";
    lesMots[8] = "avehc";
    lesMots[9] = "aveic";
    lesMots[10] = "avejc";
    lesMots[11] = "avekc";
    lesMots[12] = "avelc";
    lesMots[13] = "avemc";
    lesMots[14] = "avenc";
    lesMots[15] = "aveoc";
    lesMots[16] = "avepc";
    lesMots[17] = "aveqc";
    lesMots[18] = "averc";
    lesMots[19] = "avesc";
    lesMots[20] = "avetc";
    lesMots[21] = "aveuc";
    lesMots[22] = "avevc";
    lesMots[23] = "avewc";
    lesMots[24] = "avexc";
    lesMots[25] = "aveyc";
    lesMots[26] = "avezc";
    lesMots[27] = "aveàc";
    lesMots[28] = "aveéc";
    lesMots[29] = "aveèc";
    lesMots[30] = "aveëc";
    lesMots[31] = "aveùc";
    lesMots[32] = "aveûc";
    lesMots[33] = "aveêc";
    lesMots[34] = "aveîc";
    lesMots[35] = "aveïc";
    lesMots[36] = "aveçc";
    lesMots[37] = "aveôc";

    return lesMots;

}

void test_remplacer_ieme_lettre(){
    char* chaine = "avek";
    Mot motACorriger = M_creerUnMot(chaine);
    EnsembleDeMot ensemble = CO_remplacerIemeLettreEnBoucle(motACorriger,4);
    char** solution = creer_ensemble_solution();
    for(int i=0;i<38;i++){
        Mot mot = M_creerUnMot(solution[i]);
        CU_ASSERT_TRUE(EDM_estPresent(ensemble,mot));
        M_supprimerMot(&mot);
    }
    M_supprimerMot(&motACorriger);
    while(!EDM_cardinalite(ensemble)==0){
        Mot tmp = EDM_obtenirMot(ensemble);
        EDM_retirer(&ensemble,tmp);
        M_supprimerMot(&tmp);
    }
    EDM_vider(&ensemble);
    free(solution);
}

void test_inserer_lettre(){
    char* chaine = "avec";
    Mot motACorriger = M_creerUnMot(chaine);
    EnsembleDeMot ensemble = CO_insererIemeLettreEnBoucle(motACorriger,4);
    char **solution = creer_ensemble_solution_inserer();
    for(int i=0;i<38;i++){
        Mot mot = M_creerUnMot(solution[i]);
        CU_ASSERT_TRUE(EDM_estPresent(ensemble,mot));
        M_supprimerMot(&mot);
    }
    M_supprimerMot(&motACorriger);
    while(!EDM_cardinalite(ensemble)==0){
        Mot tmp = EDM_obtenirMot(ensemble);
        EDM_retirer(&ensemble,tmp);
        M_supprimerMot(&tmp);
    }
    EDM_vider(&ensemble);
    free(solution);
}

void test_strategie_remplacer_lettre(){
    Dictionnaire dico = creer_dictionnaire();
    char* chaine = "abec";
    char* chaine1 = "avec";
    Mot motACorriger = M_creerUnMot(chaine);
    Mot solution = M_creerUnMot(chaine1);
    CorrecteurOrthographique correcteur = CO_correcteur(dico,motACorriger);
    CO_strategieRemplacerLettres(&correcteur);
    CU_ASSERT_TRUE(EDM_estPresent(correcteur.lesCorrections,solution));
    //ADL_supprimer(&dico);
    //M_supprimerMot(&motACorriger);
    M_supprimerMot(&solution);
    CO_supprimerCO(&correcteur);
}

void test_strategie_supprimer_lettre(){
    Dictionnaire dico = creer_dictionnaire();
    char* chaine = "avvec";
    char* chaine1 = "avec";
    Mot motACorriger = M_creerUnMot(chaine);
    Mot solution = M_creerUnMot(chaine1);
    CorrecteurOrthographique correcteur = CO_correcteur(dico,motACorriger);
    CO_strategieSupprimerLettres(&correcteur);
    CU_ASSERT_TRUE(EDM_estPresent(correcteur.lesCorrections,solution));
    //ADL_supprimer(&dico);
    //M_supprimerMot(&motACorriger);
    M_supprimerMot(&solution);
    while(!EDM_cardinalite(correcteur.lesCorrections)==0){
        Mot tmp = EDM_obtenirMot(correcteur.lesCorrections);
        EDM_retirer(&correcteur.lesCorrections,tmp);
        M_supprimerMot(&tmp);
    }
    CO_supprimerCO(&correcteur);
}

void test_strategie_inverser_lettre(){
    Dictionnaire dico = creer_dictionnaire();
    char* chaine = "aevc";
    char* chaine1 = "avec";
    Mot motACorriger = M_creerUnMot(chaine);
    Mot solution = M_creerUnMot(chaine1);
    CorrecteurOrthographique correcteur = CO_correcteur(dico,motACorriger);
    CO_strategieInverserDeuxLettresConsecutives(&correcteur);
    CU_ASSERT_TRUE(EDM_estPresent(correcteur.lesCorrections,solution));
    //ADL_supprimer(&dico);
    //M_supprimerMot(&motACorriger);
    M_supprimerMot(&solution);
    CO_supprimerCO(&correcteur);
}

void test_strategie_inserer_lettre(){
    Dictionnaire dico = creer_dictionnaire();
    char* chaine = "avc";
    char* chaine1 = "avec";
    Mot motACorriger = M_creerUnMot(chaine);
    Mot solution = M_creerUnMot(chaine1);
    CorrecteurOrthographique correcteur = CO_correcteur(dico,motACorriger);
    CO_strategieInsererLettres(&correcteur);
    CU_ASSERT_TRUE(EDM_estPresent(correcteur.lesCorrections,solution));
    //ADL_supprimer(&dico);
    //M_supprimerMot(&motACorriger);
    M_supprimerMot(&solution);
    CO_supprimerCO(&correcteur);
}

void test_strategie_decomposer_mot(){
    Dictionnaire dico = creer_dictionnaire();
    char* chaine = "avecarride";
    char* chaine1 = "avec";
    Mot motACorriger = M_creerUnMot(chaine);
    Mot solution = M_creerUnMot(chaine1);
    CorrecteurOrthographique correcteur = CO_correcteur(dico,motACorriger);
    CO_strategieDecomposerMot(&correcteur);
    CU_ASSERT_TRUE(EDM_estPresent(correcteur.lesCorrections,solution));
    //ADL_supprimer(&dico);
    //M_supprimerMot(&motACorriger);
    M_supprimerMot(&solution);
    CO_supprimerCO(&correcteur);
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
    if ((NULL == CU_add_test(pSuite, "remplacer la bonne lettre", test_remplacer_ieme_lettre))
    ||  (NULL == CU_add_test(pSuite, "inserer a la bonne place", test_inserer_lettre))
    //||  (NULL == CU_add_test(pSuite, "test strategie remplacer", test_strategie_remplacer_lettre))
    //||  (NULL == CU_add_test(pSuite, "test strategie supprimer", test_strategie_supprimer_lettre))
    //||  (NULL == CU_add_test(pSuite, "test strategie inverser", test_strategie_inverser_lettre))
    //||  (NULL == CU_add_test(pSuite, "test strategie inserer", test_strategie_inserer_lettre))
    //||  (NULL == CU_add_test(pSuite, "test strategie decomposer", test_strategie_decomposer_mot))

    ){
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