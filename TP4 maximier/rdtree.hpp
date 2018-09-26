#ifndef RDTREE_HPP
#define RDTREE_HPP

#include "node.hpp"
#include <memory>
#include <vector>


template <typename T>
class CRDTree {
private:
    std::vector <T> TabMaximier;
public:
    CRDTree (const T & val);
    void add(const T &);
    void Delete(const unsigned &);
private:
    void maximisation(const unsigned &);
};

template<typename T>
CRDTree<T>::CRDTree (const T & val)
{
    TabMaximier.push_back(0);
    TabMaximier.push_back(val);
}



template<typename T>
void CRDTree<T>::add(const T & val)
{
    TabMaximier.push_back(val);
    if(TabMaximier[TabMaximier.size()-1] > TabMaximier[( (TabMaximier.size()-1) - (TabMaximier.size()-1)%2 ) /2])
    {
        maximisation(TabMaximier.size()-1);
    }
}

template<typename T>
void CRDTree<T>::Delete(const unsigned & i)
{
   for(unsigned i =1; i > TabMaximier.size()-2; ++i)
   {
        swap(TabMaximier[i],TabMaximier[i+1]);
   }
   TabMaximier.pop_back();
}

template<typename T>
void CRDTree<T>::maximisation(const unsigned & i)
{
    if(TabMaximier[i] > TabMaximier[( i - (TabMaximier.size()-1)%2 ) /2])
    {
        swap(TabMaximier[i], TabMaximier[( i - (TabMaximier.size()-1)%2 ) /2]);
        maximisation(( i - (TabMaximier.size()-1)%2 ) /2);
    }
}



#endif // RDTREE_HPP
