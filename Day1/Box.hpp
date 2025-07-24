#include <cstddef>
#include <utility>


template<class T>
class Box{
public:
    // Constructors
    Box(): data(nullptr), _size(0), _capacity(0) {}

    Box(size_t initialSize): data(new T[initialSize]), _size(initialSize), _capacity(initialSize){}

    Box(size_t initialSize, const T& value){
        data = new T[initialSize];
        _size = initialSize;
        _capacity = initialSize;
        for(size_t i=0; i<_size; ++i){
            data[i]=value;
        }
    }

    // Rule of 5
    // Copy constructor
    Box(const Box& otherBox): _size(otherBox._size), _capacity(otherBox._capacity), data(new T[otherBox._size]) {
        for(size_t i=0; i<_size; ++i){
            data[i] = otherBox.data[i];
        }
    }

    // Move constructor
    Box(Box&& otherBox) noexcept;

    // Copy assignment operator
    Box& operator=(const Box& otherBox){
        if (this == &otherBox) return *this;
        _size = otherBox._size;
        _capacity = otherBox._capacity;
        delete[] data;
        data = new T[_size];
        for(size_t i=0; i<_size; ++i){
            data[i] = otherBox.data[i];
        }
        
    }

    // Move assignment operator
    Box& operator=(Box&& otherBox) noexcept;

    // Destructor
    ~Box(){
        delete[] data;
        data=nullptr;
        _size = 0;
        _capacity = 0;
    }

    // Access operator []
    T& operator[]();
    const T& operator[]() const;

    // resize
    void resize(size_t newSize){

    }

    // get size and capacity
    size_t size() const{
        return this->_size;
    }
    size_t capacity() const{
        return this->_capacity;
    }

private:
    T* data;
    size_t _size;
    size_t _capacity;

    void reallocate(size_t newCapacity){
        
    }
};