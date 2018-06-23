#ifndef Lista_H
#define Lista_H
#include <iostream>
template<typename T>
class Lista{
private:
    struct Node{
      T data;
      Node* next;
    };
    Node *head, *tail;
public:
    class iterator{
    private:
        typedef Node* pointer;
        pointer ptr;
    public:
        iterator():ptr(nullptr){}
        iterator(pointer ptr):ptr(ptr){}
        iterator& operator ++(){
            ptr=ptr->next;
            return *this;
        }
        iterator operator ++(int i){
            iterator temp=*this;
            ptr=ptr->next;
            return temp;
        }
        T& operator *(){
            return ptr->data;
        }
        T* operator ->(){
            return ptr->data;
        }
        iterator operator= (const pointer ptr){
            this->ptr=ptr;
            return *this;
        }
        bool operator==(const iterator& it){
            return ptr==it.ptr;
        }
        bool operator!=(const iterator& it){
            return ptr!=it.ptr;
        }
    };

    Lista();
    ~Lista();
    bool empty();
    Node* first();
    Node* last();
    T front();
    T back();
    void push_back(T t);
    void push_front(T t);
    void pop_back();
    void pop_front();
    void insert(Node* n, T t);
    T& at(Node* n);
    void erase(Node* n);
    void printList();
    iterator begin();
    iterator end();

};


template<typename T>
Lista<T>::Lista(){
    head=new Node;
    head->next=nullptr;
}
template<typename T>
Lista<T>::~Lista(){
    Node* temp = head->next;
    while(temp!=nullptr){
        delete head;
        head=temp;
        temp = head->next;
    }
    delete head;
}
template<typename T>
bool Lista<T>::empty(){
    return (head->next==nullptr);
}
template<typename T>
typename Lista<T>::Node* Lista<T>::first(){
    return head;
}
template<typename T>
T Lista<T>::front(){
  return head->next->data;
}
template<typename T>
typename Lista<T>::Node* Lista<T>::last(){
    return tail;
}
template<typename T>
T Lista<T>::back(){
    return tail->data;
}
template<typename T>
void Lista<T>::insert(Node *n, T t){
    Node* temp = new Node;
    temp->data=t;
    temp->next=n->next;
    n->next=temp;
}
template <typename T>
T& Lista<T>::at(Node *n){
    return n->data;
}
template <typename T>
void Lista<T>::push_front(T t){
    Node* newN = new Node;
    newN->data=t;
    newN->next=head->next;
    head->next=newN;
}
template<typename T>
void Lista<T>::push_back(T t){
    Node* temp=head;
    while(temp->next!=nullptr)
        temp=temp->next;
    temp->next=new Node;
    temp->next->data=t;
    temp->next->next=nullptr;
    tail=temp->next;
}
template<typename T>
void Lista<T>::pop_front(){
    Node* temp = head->next;
    head->next=temp->next;
    delete temp;
}
template<typename T>
void Lista<T>::pop_back(){
    Node*temp=head;
    while(temp->next->next!=nullptr)
        temp=temp->next;
    delete temp->next;
    temp->next=nullptr;
    tail=temp;
}
template<typename T>
void Lista<T>::erase(Node *n){
    Node* temp=n->next;
    n->next=temp=temp->next;
    delete temp;
}

//pomocnicza
template<typename T>
void Lista<T>::printList(){
    Node* n=head;
    while(n->next!=nullptr){
        std::cout<<n->next->data << std::endl;
        n=n->next;
    }
}

template<typename T>
typename Lista<T>::iterator Lista<T>::begin(){
    return iterator(head->next);
}

template<typename T>
typename Lista<T>::iterator Lista<T>::end(){
    return iterator(tail->next);
}


#endif // Lista_H
