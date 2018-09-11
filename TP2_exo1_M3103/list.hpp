#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "cnode.hpp"

template <typename T>
class CList
{
private:
    CNode<T>* m_Head;
    CNode<T>* m_Tail;
public:
    CList ();
    ~CList ();

   //ajout en tête de liste
    void push_front (const T & val);

   //affichage
    void Show () const;

    //recherche d'un élément dans la liste, renvoie le pointeur du maillon si l'élément est présent, nullptr sinon
    CNode<T>* Find (const T & val) const;

    //ajout d'une valeur après un maillon de la liste
    void Add (const T & val, CNode<T>*);

    //détache un maillon de la liste et le supprime
    void Delete (CNode<T>*);

    void push_back (const T & val);

    //redéfinis m_Tail
    void setTail();
};


template<typename T>
CList<T>::CList() : m_Head (nullptr), m_Tail (nullptr) {}

template<typename T>
CList<T>::~CList()
{
    delete m_Head;
}

template<typename T>
void CList<T>::push_front(const T &val)
{
    m_Head = new CNode<T> (val, m_Head);
    setTail();
}

template<typename T>
void CList<T>::Show() const
{
    for (CNode<T>* ptr (m_Head); ptr != nullptr; ptr = ptr->GetNextNode ())
        std::cout << ptr->GetData () << "; ";
}

template<typename T>
CNode<T> *CList<T>::Find(const T &val) const
{
    for (CNode<T>* ptr (m_Head); ptr != nullptr; ptr = ptr->GetNextNode ())
    {
        if(ptr->GetData() == val) return ptr;
    }
    return nullptr;
}

template<typename T>
void CList<T>::Add(const T &val, CNode<T> * A)
{

    CNode<T> Inserer = new CNode<T>( val,(A->GetNextNode()));
    A->setNext(Inserer);
    setTail();
}

template<typename T>
void CList<T>::Delete(CNode<T> * pDelete)
{
    for (CNode<T>* ptr (m_Head); ptr != nullptr; ptr = ptr->GetNextNode ())
    {
        if(ptr->GetNextNode() == pDelete){
            ptr->setNext(pDelete->GetNextNode());
            pDelete->setNext(nullptr);
            delete pDelete;
            setTail();
            return;
        }
    }

    pDelete->setNext(nullptr);
    delete pDelete;
    setTail();
}

template<typename T>
void CList<T>::push_back(const T &val)
{
    m_Tail->setNext(new CNode<T>(val,nullptr));
    setTail();
}

template<typename T>
void CList<T>::setTail()
{
    CNode<T>* ptr (m_Head);
    for (; ptr->GetNextNode () != nullptr; ptr = ptr->GetNextNode ());

    m_Tail = ptr;
}

#endif // LIST_HPP
