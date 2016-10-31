namespace edu
{
template <typename T>
class vector
{
private:
    T* m_data;
    
public:
    vector();
    ~vector();

public:
    void reserve( unsigned int size );
    
};

template <typename T>
vector<T>::vector()
    : m_data( nullptr )
{}

template <typename T>
vector<T>::~vector()
{
    if ( m_data )
        delete m_data;
}

template <typename T>
void vector<T>::reserve( unsigned int size )
{
    m_data = new T[size];
}

}  //  edu

int main()
{
    edu::vector<int> v;
    v.reserve(10);
}
