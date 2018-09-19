#ifndef NODE_HPP
#define NODE_HPP
#include <memory>

template <typename T>
class CNode
{
private:
    T m_Data;
    std::shared_ptr <CNode<T>> m_RC;
    std::shared_ptr <CNode<T>> m_LC;
public:
    //constructor
    CNode (const T &  val = T(), std::shared_ptr <CNode<T>> RC = nullptr, std::shared_ptr <CNode<T>> LC = nullptr );
    //destructor

    //getter / setter
    const T &GetData () const;
    std::shared_ptr <CNode<T>> GetRC () const;
    std::shared_ptr <CNode<T>> GetLC () const;
    void SetData (const T & val);
    void SetRC (const std::shared_ptr <CNode<T>>&);
    void SetLC (const std::shared_ptr <CNode<T>>&);
};


template <typename T>
CNode<T>::CNode (const T & val, std::shared_ptr <CNode<T>> RC, std::shared_ptr <CNode<T>> LC) : m_Data (val), m_RC (RC), m_LC (LC)
{
}

template <typename T>
const T & CNode<T>::GetData () const
{
    return m_Data;
}

template <typename T>
std::shared_ptr <CNode<T>> CNode<T>::GetRC () const
{
    return m_RC;
}

template <typename T>
std::shared_ptr <CNode<T>> CNode<T>::GetLC () const
{
    return m_LC;
}


template <typename T>
void CNode<T>::SetData (const T & val)
{
    m_Data = val;
}

template <typename T>
void CNode<T>::SetRC (const std::shared_ptr <CNode<T>> & RC)
{
    m_RC = RC;
}

template <typename T>
void CNode<T>::SetLC (const std::shared_ptr <CNode<T>> & LC)
{
    m_LC = LC;
}

#endif // NODE_HPP
