#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include <stdbool.h>
#include "Mot.h"

int init_suite_success(void)
{
    return 0;
}

int clean_suite_success(void)
{
    return 0;
}

Mot creer_un_mot()
{
    Mot mot;
    mot.chaine = "lala";
    mot.longueur = strlen(mot.chaine);
    return mot;
}

Mot creer_mot_vide()
{
    Mot mot;
    mot.chaine = "";
    mot.longueur = 0;
    return mot;
}

char creer_cara_alpha_accent()
{
    return 'é';
}

char creer_cara_alpha_sans_accent()
{
    return 'a';
}

char creer_cara_pas_alpha()
{
    return '!';
}

char *creer_mot_valide_avec_accent()
{
    return "fatiguée";
}

char *creer_mot_valide_sans_accent()
{
    return "valide";
}

char *creer_mot_non_valide()
{
    return "val!de";
}

void test_caractere_alpha_accent()
{
    char c = creer_cara_alpha_accent();
    CU_ASSERT_TRUE(M_estUnCaractereAlphabetique(c));
}

void test_caractere_alpha_sans_accent()
{
    char c = creer_cara_alpha_sans_accent();
    CU_ASSERT_TRUE(M_estUnCaractereAlphabetique(c));
}

void test_pas_caractere_alpha()
{
    char c = creer_cara_pas_alpha();
    CU_ASSERT_TRUE(!M_estUnCaractereAlphabetique(c));
}

void test_mot_valide_avec_accent()
{
    char *c = creer_mot_valide_avec_accent();
    CU_ASSERT_TRUE(M_estUnMotValide(c));
}

void test_reduire_la_casse()
{
    char *c = creer_mot_valide_avec_accent();
    char *c1 = "FAtiguÉe";
    Mot mot = M_creerUnMot(c);
    Mot mot1 = M_creerUnMot(c1);
    CU_ASSERT_TRUE(M_sontIdentiques(mot, mot1));
    M_supprimerMot(&mot);
    M_supprimerMot(&mot1);
}

void test_mot_valide_sans_accent()
{
    char *c = creer_mot_valide_sans_accent();
    CU_ASSERT_TRUE(M_estUnMotValide(c));
}

void test_mot_non_valide()
{
    char *c = creer_mot_non_valide();
    CU_ASSERT_TRUE(!M_estUnMotValide(c));
}

void test_copier_mot()
{
    Mot mot = M_creerUnMot(creer_mot_valide_avec_accent());
    Mot mot2 = M_copierMot(mot);
    CU_ASSERT_TRUE(M_sontIdentiques(mot, mot2));
    M_supprimerMot(&mot);
    M_supprimerMot(&mot2);
}

void test_ieme_caractere()
{
    Mot mot = M_creerUnMot(creer_mot_valide_avec_accent());
    CU_ASSERT_TRUE(M_iemeCaractere(mot, 1) == 'f');
    CU_ASSERT_TRUE(M_iemeCaractere(mot, 2) == 'a');
    CU_ASSERT_TRUE(M_iemeCaractere(mot, 3) == 't');
    CU_ASSERT_TRUE(M_iemeCaractere(mot, 7) == 'é');
    M_supprimerMot(&mot);
}

void test_sont_identiques()
{
    Mot mot = M_creerUnMot(creer_mot_valide_avec_accent());
    Mot mot2 = M_copierMot(mot);
    CU_ASSERT_TRUE(M_sontIdentiques(mot, mot2));
    M_supprimerMot(&mot);
    M_supprimerMot(&mot2);
}

void test_supprimer_ieme_lettre()
{
    char *c = "fatguée";
    Mot mot = M_creerUnMot(creer_mot_valide_avec_accent());
    Mot mot3 = M_copierMot(mot);
    Mot mot2 = M_creerUnMot(c);
    M_supprimerIemeLettre(&mot, 4);
    CU_ASSERT_TRUE(M_sontIdentiques(mot, mot2));
    CU_ASSERT_TRUE(!M_sontIdentiques(mot, mot3));
    M_supprimerMot(&mot);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
}

void test_inverser_deux_lettres_consecutives()
{
    char *c = "fatiguée";
    char *c1 = "fatgiuée";
    Mot mot = M_creerUnMot(c);
    Mot mot2 = M_creerUnMot(c1);
    M_inverserDeuxLettresConsecutives(&mot, 4);
    CU_ASSERT_TRUE(M_sontIdentiques(mot, mot2));
    M_supprimerMot(&mot);
    M_supprimerMot(&mot2);
}

void test_inserer_lettre()
{
    char *c = "faiguée";
    char *c1 = "fatiguée";
    Mot mot = M_creerUnMot(c);
    Mot mot2 = M_creerUnMot(c1);
    M_insererLettre(&mot, 3, 't');
    CU_ASSERT_TRUE(M_sontIdentiques(mot, mot2));
    M_supprimerMot(&mot);
    M_supprimerMot(&mot2);
}

void test_decomposer_mot()
{
    char *c = "fati";
    char *c1 = "guée";
    Mot mot = M_creerUnMot(c);
    Mot mot1 = M_creerUnMot(c1);
    Mot mot2 = M_creerUnMot(creer_mot_valide_avec_accent());
    Mot mot3 = M_decomposerMot(&mot2, 5);
    CU_ASSERT_TRUE(M_sontIdentiques(mot3, mot));
    CU_ASSERT_TRUE(M_sontIdentiques(mot2, mot1));
    M_supprimerMot(&mot);
    M_supprimerMot(&mot1);
    M_supprimerMot(&mot2);
    M_supprimerMot(&mot3);
}

int main(int argc, char **argv)
{
    CU_pSuite pSuite = NULL;

    /* initialisation du registre de tests */
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }
    /* ajout d'une suite de test */
    pSuite = CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Ajout des tests � la suite de tests boite noire */
    if ((NULL == CU_add_test(pSuite, "un caractere avec accent est un caractere alphabetique", test_caractere_alpha_accent)) || (NULL == CU_add_test(pSuite, "un caractere sans accent est un caractere alphabetique", test_caractere_alpha_sans_accent)) || (NULL == CU_add_test(pSuite, "un caractere non alphabetique ne l'est pas", test_pas_caractere_alpha)) || (NULL == CU_add_test(pSuite, "un mot non valide n'est pas valide", test_mot_non_valide)) || (NULL == CU_add_test(pSuite, "un mot valide avec accent est valide", test_mot_valide_avec_accent)) || (NULL == CU_add_test(pSuite, "un mot valide sans accent est valide", test_mot_valide_sans_accent)) || (NULL == CU_add_test(pSuite, "creer un mot reduit la casse", test_reduire_la_casse)) || (NULL == CU_add_test(pSuite, "la copie est identique au mot", test_copier_mot)) || (NULL == CU_add_test(pSuite, "la copie et le mot sont identiques", test_sont_identiques)) || (NULL == CU_add_test(pSuite, "ieme caractere renvoie bien le ieme caractere", test_ieme_caractere)) || (NULL == CU_add_test(pSuite, "supprimer ieme caractere supprimer bien le ieme caractere", test_supprimer_ieme_lettre)) || (NULL == CU_add_test(pSuite, "inverser deux lettres fontionne", test_inverser_deux_lettres_consecutives)) || (NULL == CU_add_test(pSuite, "inserer une lettre a la bonne place", test_inserer_lettre)) || (NULL == CU_add_test(pSuite, "decompo ok", test_decomposer_mot))

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