#include <iostream>

namespace edu
{
template <typename T>
class vector
{
private:
    T* m_data;
    unsigned int m_maxSize;
    unsigned int m_size;
    
public:
    vector();
    ~vector();

public:
    T& operator[]( unsigned int size );
    T* begin();
    T* end();

public:
    void reserve( unsigned int size );
    void resize( unsigned int size );

public:
    unsigned int size();
    bool empty();
};

template <typename T>
vector<T>::vector()
    : m_data( nullptr )
{}

template <typename T>
vector<T>::~vector()
{
    if ( m_data )
        delete[] m_data;
}

template <typename T>
T& vector<T>::operator[]( unsigned int size )
{
    return *(m_data + size);
}

template <typename T>
T* vector<T>::begin()
{
    return m_data;
}

template <typename T>
T* vector<T>::end()
{
    return m_data + m_size;
}

template <typename T>
void vector<T>::reserve( unsigned int size )
{
    for ( unsigned int i = 0; i < m_size; ++i )
        m_data[i].~T();

    if ( m_data )
        delete[] m_data;

    m_maxSize = size;
    m_size = 0;

    m_data = static_cast<T*>( operator new[] (size * sizeof(T)) );
}

template <typename T>
void vector<T>::resize( unsigned int size )
{
    reserve(size);
    
    m_size = size;
    for ( unsigned int i = 0; i < size; ++i )
        new (m_data + i) T();
}

template <typename T>
unsigned int vector<T>::size()
{
    return m_size;
}

template <typename T>
bool vector<T>::empty()
{
    return m_size == 0;
}

}  //  edu

int main()
{
    edu::vector<int> v;
    v.reserve(10);
    v.resize(5);
    for ( int i = 0; i < 5; ++i )
        v[i] = 5 - i;
    
    for ( int* iter = v.begin(); iter < v.end(); ++iter )
    {
        std::cout << *iter << ' ';
    }
    std::cout << v.size();
}
