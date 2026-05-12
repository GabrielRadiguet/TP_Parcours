#include <iostream>
#include <cmath>

#include "test.hpp"

#include "../include/point.hpp"

void check_assert(bool exp, const char* fichier, int nb_ligne, const char* ligne)
{
    if (!exp) {
        std::cerr << "Failed: " << ligne << " in " << fichier << ' ' << nb_ligne << std::endl;
    }
}

void test()
{
    std::cout << "--- Debut Tests Point ---" << std::endl;

    Point A(1, 2);
    Point B(4, 6);
    ASSERT(comp_double(A.distance(B), 5));
    ASSERT(comp_double(B.distance(A), 5));
    ASSERT(comp_double(B.distance(B), 0));
    ASSERT(comp_double(A.distance(A), 0));

    ASSERT(B.equals(B));
    ASSERT(A.equals(A));

    Point C(0, 0);
    Point D(1, 1);
    ASSERT(comp_double(C.distance(D), std::sqrt(2)));

    Point E(67, 89);
    Point F(-50, -30);
    ASSERT(comp_double(E.distance(F), std::sqrt(27850)));

    std::cout << "--- Fin Tests Point ---" << std::endl << std::endl;

    test_circle();
    test_square();
    test_triangle();
}