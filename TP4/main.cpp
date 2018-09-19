#include <iostream>
#include "node.hpp"
#include "rdtree.hpp"
using namespace std;

void TestArbre (){
    CRDTree<int> Arbre (0);

    for(unsigned i (0); i < 6 ; ++i){
        Arbre.add(i);
    }
    Arbre.show();
}


int main (void)
{
    TestArbre();
    return 0;
}
