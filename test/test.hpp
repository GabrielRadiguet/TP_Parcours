#ifndef TEST_HPP
#define TEST_HPP

// fonction d'assert pour les tests unitaires
void check_assert(bool exp, const char* fichier, int nb_ligne, const char* ligne);
// macro permettant d'appeler check_assert avec les informations de contexte
#define ASSERT(expression) check_assert((expression), __FILE__, __LINE__, #expression)

void test();
void test_circle();
void test_square();
void test_triangle();

#endif