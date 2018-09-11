#ifndef CNODE_HPP
#define CNODE_HPP

#include <iostream>


template <typename T>
class CNode
{

private:
    T m_Data;
    CNode* m_Next;

public:
    //constructor
    CNode (const T  & _m_Data, CNode*  _m_Next);
    //destructor
    ~CNode ();

    //getter / setter
    const T & GetData() const;
    void setData(const T & _m_Data);

    CNode* GetNextNode() const;
    void setNext( CNode*  _m_Next);

};



template<typename T>
CNode<T>::CNode(const T & _m_Data,  CNode *_m_Next) : m_Data(_m_Data), m_Next(_m_Next){}

template<typename T>
CNode<T>::~CNode()
{

  delete m_Next;
  std::cout << m_Data << std::endl;
}


template<typename T>
const T & CNode<T>::GetData() const {
    return this->m_Data;
}


template<typename T>
void CNode<T>::setData(const T & _m_Data) {
    m_Data = _m_Data;
}


template<typename T>
CNode<T> *CNode<T>::GetNextNode() const {
    return this->m_Next;
}


template<typename T>
void CNode<T>::setNext( CNode *_m_Next) {
    m_Next = _m_Next;
}


#endif // CNODE_HPP
