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

void TestFind(){
    CRDTree<int> Arbre (0);

    for(unsigned i (0); i < 6 ; ++i){
        Arbre.add(i);
    }
    Arbre.show();
    cout << endl;
    cout << "on cherche 3" << endl;
    if(Arbre.find(3)){
        cout << "3 trouvé :)" << endl;
    }
    else {
        cout << "3 trouvé pas trouvé :(" << endl;
    }

    cout << "on cherche 10" << endl;
    if(Arbre.find(10)){
        cout << "10 trouvé :)" << endl;
    }
    else {
        cout << "10 trouvé pas trouvé :(" << endl;
    }
}

int main (void)
{
    TestFind();
    return 0;
}
