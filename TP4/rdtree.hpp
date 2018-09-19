#ifndef RDTREE_HPP
#define RDTREE_HPP

#include "node.hpp"
#include <memory>


template <typename T>
class CRDTree {
  private:
    std::shared_ptr <CNode<T>> myRacine;
  public:
    CRDTree (const T & val);
    void show (void) const;
    void add(const T &);
  private :
    void show(const std::shared_ptr <CNode<T>> &) const;

};

template<typename T>
CRDTree<T>::CRDTree (const T & val) :  myRacine (new CNode<T> (val))
{

}


template<typename T>
void CRDTree<T>::show(void) const
{
    show(myRacine);
}


template<typename T>
void CRDTree<T>::show(const std::shared_ptr <CNode<T>> & A) const
{
    if (!A) return;
    show(A->GetLC());
    show(A->GetRC());
    std::cout << A->GetData() << std::endl;
}

template<typename T>
void CRDTree<T>::add(const T & val)
{
    std::shared_ptr <CNode<T>> tmp = myRacine;

    while (true) {
        if(tmp->GetLC() == nullptr) {
            tmp->SetLC(std::shared_ptr <CNode<T>> (new CNode<T>(val)));
            return;
        }
        else if (tmp->GetRC() == nullptr) {
            tmp->SetRC(std::shared_ptr <CNode<T>> (new CNode<T>(val)));
            return;
        }
        else {
            int itmp = (rand () % 2);
            if(itmp == 0){
                tmp = tmp->GetRC();
            }
            else{
                tmp = tmp->GetLC();
            }
        }
    }
}


#endif // RDTREE_HPP
