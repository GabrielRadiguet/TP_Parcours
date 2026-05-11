#include <iostream>
#include "test.hpp"

void check_assert(bool exp, const char* fichier, int nb_ligne, const char* ligne)
{
    if (!exp) {
        std::cerr << "Failed: " << ligne << " in " << fichier << ' ' << nb_ligne << std::endl;
    }
}
void test()
{   
    ASSERT(1==0);
    ASSERT(2==0);
}