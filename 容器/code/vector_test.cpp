#include <iostream>
#include <algorithm>
#include <cassert>
#include <iterator> //Need ostream_iterator


using namespace std;

/*realloc increase length*/
enum WALK_LEN{NORMAL = 64} capacity_len = NORMAL;

template <typename T>
class MyVector
{
private:
    T *_array; //the start address of the Vector
    unsigned int _size;
    unsigned int _capacity;

private: /*class inner utility method*/
    T *allocator(unsigned int size);
    void deallocator(T *arr);

public:
    MyVector(); /*init memeber to zero*/
    MyVector(const T &t, unsigned int n); // push_back(t) into the vector n times
    MyVector(const MyVector<T>& other); //copy constructor
    ~MyVector();

public:
    /*operators*/
    MyVector<T> &operator=(const MyVector<T> &other);
    T &operator[](unsigned int pos); //subscript

    inline unsigned int size(){return this->_size;}
    inline unsigned int capacity(){return this->_capacity;}
    inline bool empty(){return _size==0;}

    void clear(); /*free the capacity*/
    void erase(unsigned int pos);

    void push_back(const T&t);
    void push_front(const T&t); //... u the better not

    void insert_after(unsigned int pos, const T &t);
    void insert_before(unsigned int pos, const T &t);


    void shrink_to_fit();

    /*tells the info in the vector*/
    void print_myvector();

};


template <typename T>
MyVector<T>::MyVector():_size(0), _capacity(0), _array(0){}

template <typename T>
MyVector<T>::MyVector(const T &t, unsigned int n):_size(0), _capacity(0), _array(0)
{
    /*push n times t*/
    while(n--){
        push_back(t);
    }
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> &other):_size(0), _capacity(0), _array(0){
    /*just call operator=(): before we new, we clear first*/
    *this = other;
}

template <typename T>
MyVector<T>::~MyVector(){clear();}


/*Utilities Methods*/
template <typename T>
T *MyVector<T>::allocator(unsigned int size){
    return new T[size];
}

template <typename T>
void MyVector<T>::deallocator(T *arr){
    if(arr){
        delete[] arr;
    }
}


/*operators*/
template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &other){
    if(this != &other){
        clear();  /*clear the old space when it was not null*/

        this->_size = other._size;
        //this->_capacity = other._capacity;
        this->_capacity = other._size;// give it enough but not waste

        this->_array = allocator(this->_capacity);
        for(unsigned int i = 0; i < this->_size; i++){
            _array[i] = other._array[i];
        }
    }

    return *this;
}

template <typename T>
T &MyVector<T>::operator[](unsigned int pos){//subscript
    assert(pos < _size);
    return _array[pos];
}

template <typename T>
void MyVector<T>::clear(){ /*free the capacity*/
    deallocator(this->_array);
    _array = 0;
    _capacity = 0;
    _size = 0;
}



/*all inset*(), push*() using insert_before(pos, const T &t)
  cause insert_before() insert elem exactly the position, and let the old elem move backward.
*/
template <typename T>
void MyVector<T>::push_back(const T&t){
    //insert_after(_size-1, t);
    insert_before(_size, t);
}

template <typename T>
void MyVector<T>::push_front(const T&t){ //... u the better not, less effective
    insert_before(0, t);
}

template <typename T>
void MyVector<T>::insert_after(unsigned int pos, const T &t){
    insert_before(pos+1, t);
}

template <typename T>
void MyVector<T>::insert_before(unsigned int pos, const T &t){
    /*plz consider capacity first*/
    if(_size == _capacity){ //Need reallocate.
        //before u deallocate the old space , u must ensure enough new space
        T *old_array = _array;
        _capacity += capacity_len;// + 64


        _array = allocator(_capacity);
        /*
        for(int i = 0; i < _size; i++){
            _array[i] = old_array[i];
        }*/

        memcpy(_array, old_array, _size*sizeof(T));

        deallocator(old_array);
    }

    //just insert and other elem
    for(unsigned int i = _size; i > pos; i--){
        /*[0]... [pos] [pos+1] ... [_size-1] [_size]*/
        _array[i] = _array[i-1];
    }

    _array[pos] = t;
    _size++;
}



template <typename T>
void MyVector<T>::erase(unsigned int pos){
    if(pos < _size){
        _size--;
        for(int i=pos; i<_size; i++){
            _array[pos] = _array[pos+1];
        }
    }
}

/*resize the capacity to size*/
template <typename T>
void MyVector<T>::shrink_to_fit(){
    MyVector<T> tmp(*this);
    *this = tmp;
}

/*tells the info in the vector*/
template <typename T>
void MyVector<T>::print_myvector(){
    cout << "current vector:" << endl;
    if(_array){
        //for_each(_array, _array+_size, ostream_iterator<T>(cout, ", "));//wrong
        copy(_array, _array+_size, ostream_iterator<int>(cout, ", "));
    }

    cout <<endl << "capacity = " << _capacity << "; size = " << _size << endl;
}



int main(void)
{
    MyVector<int> v;
    v.print_myvector();
    cout << "-------------------" <<endl;

    v.push_back(1);
    v.push_front(0);
    v.print_myvector();
    cout << "-------------------" <<endl;

    MyVector<int> v1(v); /*0, 1*/
    v1.print_myvector(); /*size 2, capacity 2*/
    v1.push_front(-1); /*size 3, capacity 65*/
    v1.erase(2); /*-1, 0; size 2, capacity 65*/
    v1.insert_after(1,1);/*size 3, capacity 66*/
    v1.print_myvector();

    MyVector<int> v2(1, 65); //1, 1, 1, 1
    v2.print_myvector(); //capacity = 128; size = 65
    v2.shrink_to_fit();
    v2.print_myvector();


    return 0;
}
