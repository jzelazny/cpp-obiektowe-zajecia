#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
    unsigned int m_size;
    T *arr;
public:
    Array(int size);
    ~Array();
    int size();
    T& operator[](int index);
    T* begin(){
        return arr;
    }
    T* end(){
        return arr+m_size-1;
    }

    class iterator{
            typedef T* pointer;
            pointer ptr;
        public:
            iterator (){
                iterator(arr);
            }
            iterator(pointer ptr){
                this->ptr=ptr;
            }

            iterator operator= (iterator it){
                it=this;
                return *this;
            }

            iterator operator++(){
                ptr++;
                return *this;
            }
            iterator operator -- (){
                ptr--;
                return *this;
            }
            pointer operator ->(){
                return ptr;
            }
            T operator *(){
                return *ptr;
            }
            bool operator !=(const iterator& it){
                return ptr!=it.ptr;
            }
            bool operator ==(const iterator& it){
                return ptr==it.ptr;
            }
            
    };
};

template <typename T>
Array<T>::Array(int size) {
    this->m_size=size;
    this->arr=new T[size];
    for(int i=0;i<size;i++)
        arr[i]=i;
}

template <typename T>
Array<T>::~Array() {
    delete [] arr;
}

template <typename T>
int Array<T>::size() {
    return m_size;
}

template <typename T>
T& Array<T>::operator[](int index) {
    return arr[index];
}





#endif // ARRAY_H