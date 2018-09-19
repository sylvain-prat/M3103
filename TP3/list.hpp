#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"
#include <memory>

template <typename T>
class CList
{
private:
    //CNode<T>* m_fictionaHead;
    //CNode<T>* m_realTail;

    std::shared_ptr <CNode<T>> m_fictionaHead;
    std::shared_ptr <CNode<T>> m_realTail;
public:
    CList ();
    ~CList ();
    void push_front (const T & val);
    void Show () const;
    std::shared_ptr <CNode<T>> Find (const T & val) ;
    //void Add (const T & val, CNode<T>*);
   // void Add (const T & val);
    void Delete (std::shared_ptr <CNode<T>>);
    //void push_back (const T & val);
    std::shared_ptr <CNode<T>> Begin () const;
   // void AddAfter (std::shared_ptr <CNode<T>>, const T & val);
   // void AddBefore (std::shared_ptr <CNode<T>>, const T & val);
};

template <typename T>
std::shared_ptr <CNode<T>> CList<T>::Begin () const
{
    return m_fictionaHead;
}


/*
template <typename T>
void CList<T>::AddAfter (std::shared_ptr <CNode<T>> ptr, const T & val)

{
    ptr -> SetNextNode (std::shared_ptr <CNode<int>> (new CNode<T> (val, ptr-> GetNextNode(), ptr)));
    if (ptr == m_realTail) m_realTail = ptr->GetNextNode ();
}

template <typename T>
void CList<T>::AddBefore (std::shared_ptr <CNode<T>> ptr, const T & val)
{
    ptr -> SetPrevNode (std::shared_ptr <CNode<int>> (new CNode<T> (val, ptr, ptr-> GetPrevNode())));
    if (ptr == m_fictionaHead) m_fictionaHead = ptr->GetPrevNode ();
}

*/


/*
template <typename T>
void CList<T>::Add (const T & val, CNode<T>* ptr)
{
    CNode<T>* ptrTmp = new CNode<T> (val, ptr -> GetNextNode ());
    ptr -> SetNextNode (ptrTmp);
    if (ptr == m_realTail) m_realTail = ptr->GetNextNode ();
}
*/

/*
template <typename T>
void CList<T>::Add (const T & val)
{
    m_fictionaHead->SetPrevNode(new CNode<T>(val, m_fictionaHead));
    m_fictionaHead = m_fictionaHead->GetPrevNode();

}
*/

/*Ptr_t AjoutApres (Ptr_t Tete, int NewVal, Ptr_t PtrElem)
{
    if (! PtrElem) PtrElem = Tete;

    PtrElem->SetSuivant
           (new C1Link (NewVal, PtrElem->GetSuivant()));

    return PtrElem->GetSuivant();

} // AjoutApres()
*/

template <typename T>
CList<T>::CList () : m_fictionaHead (new CNode<T> ()), m_realTail (m_fictionaHead) {}

template <typename T>
CList<T>::~CList () {
}

template <typename T>
std::shared_ptr <CNode<T>> CList<T>::Find (const T & val) {
    std::shared_ptr <CNode<T>> Ptr (m_fictionaHead->GetNextNode ());
    for (; Ptr != nullptr && Ptr -> GetData () != val ; Ptr = Ptr->GetNextNode ());
    if (Ptr == nullptr) return Ptr;


    if(Ptr != m_fictionaHead->GetNextNode ()) {

        Ptr->GetPrevNode()->SetNextNode (Ptr->GetNextNode ());

        if(Ptr == m_realTail) {
            m_realTail = Ptr->GetPrevNode();
        }


        else {
            Ptr->GetNextNode()->SetPrevNode(Ptr->GetPrevNode());
        }

        Ptr->SetPrevNode(m_fictionaHead);
        Ptr->SetNextNode(m_fictionaHead->GetNextNode());
        m_fictionaHead->GetNextNode()->SetPrevNode(Ptr);
        m_fictionaHead->SetNextNode(Ptr);


    }

        return Ptr;
}



template <typename T>
void CList<T>::push_front (const T & val)
{

    //m_fictionaHead->GetNextNode()->SetPrevNode(std::shared_ptr <CNode<T>> (new CNode<T> (val, m_fictionaHead->GetNextNode(), m_fictionaHead)));
    m_fictionaHead->SetNextNode ( std::shared_ptr <CNode<T>> (new CNode<T> (val, m_fictionaHead->GetNextNode (), m_fictionaHead)));
    if (m_realTail == m_fictionaHead)
        m_realTail = m_fictionaHead->GetNextNode ();
    else
        m_fictionaHead->GetNextNode()->GetNextNode()->SetPrevNode(m_fictionaHead->GetNextNode());

}

template <typename T>
void CList<T>::Show () const
{
    //for (CNodeInt* Ptr (m_Head); Ptr; ++*Ptr)
    for (std::shared_ptr <CNode<T>> Ptr (m_fictionaHead -> GetNextNode()); Ptr; Ptr = Ptr->GetNextNode ())
            std::cout << Ptr->GetData() << "; ";
    std::cout << std::endl;
}

template <typename T>
void CList<T>::Delete (std::shared_ptr<CNode<T> > pDelete)
{

    pDelete->GetPrevNode() -> SetNextNode (pDelete -> GetNextNode ());
    pDelete -> GetNextNode()->SetPrevNode(pDelete->GetPrevNode());

    if (pDelete == m_realTail) m_realTail = pDelete->GetPrevNode();

    pDelete -> SetNextNode (nullptr);
    pDelete -> SetPrevNode (nullptr);

    pDelete->~CNode();
}

/*
template <typename T>
void CList<T>::push_back (const T & val)
{
    std::shared_ptr <CNode<T>> pTmp (new CNode<T> (val, NULL));
    m_realTail -> SetNextNode (pTmp);
    m_realTail = pTmp;
}
*/

#endif // LIST_HPP
