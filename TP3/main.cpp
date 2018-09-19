#include <iostream>
#include "node.hpp"
#include "list.hpp"
using namespace std;


void ListeSimple (void)
{
    std::cout << "ListeSimple : \n\n";

    std::shared_ptr <CNode<int>> Tete = NULL;

    // Le dernier element cree est toujours le premier de la liste


    for (unsigned i (0); i < 5; ) {
        //Tete = new CNode<int> (i++, Tete);
        Tete = std::shared_ptr <CNode<int>> (new CNode<int> (i++, Tete));
        std::cout << Tete << endl;
    }

    for (std::shared_ptr <CNode<int>> Ptr (Tete); Ptr; Ptr = Ptr->GetNextNode ())
        std::cout << Ptr->GetData() << "; ";

    std::cout << '\n';

    // Dans cette version, le destructeur de C1Link detruit son
    //   suivant donc la destruction de la liste est recursive


}// ListeSimple ()


void ListeSimpleLRU ()
{
    cout << "ListeSimpleV2 : \n\n";

    CList<int> AList;

    // Le dernier element cree est toujours le premier de la liste    
    for (unsigned i (0); i < 5; ) {
        AList.push_front (i++);
    }


    AList.Show ();

    cout << "0"<< endl;
    AList.Find(0);

    AList.Show ();

    cout << "2"<< endl;
    AList.Find(2);
    AList.Show ();
    cout << "8"<< endl;
    AList.Find(8);
    AList.Show ();

    cout << endl;

}

int main (void)
{
    std::cout << "Hello World!" << std::endl;
    /*   * / ListeSimple();    /*    */
    ListeSimpleLRU ();
    return 0;
}
