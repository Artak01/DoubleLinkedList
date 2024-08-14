#include <iostream>
#include "d_linked_list.h"

DLinkedList::Node::Node(int val)
    :prev {nullptr}
    ,value {val}
    ,next {nullptr}
{}

DLinkedList::DLinkedList()
    :head {nullptr}
    ,tail {nullptr}
{}

DLinkedList::~DLinkedList()
{
    clear();
}

DLinkedList::DLinkedList(const DLinkedList& other)
    :head {nullptr}
    ,tail {nullptr}
{
    Node* nextNode = other.head;
    Node* thisNode = nullptr;
    while(nextNode != nullptr){
        Node* newNode = new Node(nextNode -> value);
        if (thisNode == nullptr){
            head = newNode;
        } else {
            thisNode -> next = newNode;
            newNode -> prev = thisNode;
        }
        nextNode = nextNode -> next;
        thisNode = newNode;
    }
    tail = thisNode;
}

DLinkedList::DLinkedList(DLinkedList&& other)
    :head {other.head}
    ,tail {other.tail}
{
    other.head = nullptr;
    other.tail = nullptr;
}

DLinkedList& DLinkedList::operator= (const DLinkedList& other)
{
    if (this != &other){
        clear();

    Node* nextNode = other.head;
    Node* thisNode = nullptr;
    while(nextNode != nullptr){
        Node* newNode = new Node(nextNode -> value);
        if (thisNode == nullptr){
            head = newNode;
        } else {
            thisNode -> next = newNode;
            newNode -> prev = thisNode;
        }
        nextNode = nextNode -> next;
        thisNode = newNode;
    }
    tail = thisNode;
    }
    return *this;
}

DLinkedList& DLinkedList::operator= (DLinkedList&& other)
{
    if (this != &other){
        clear();

        head = std::exchange(other.head, nullptr); 
        tail = std::exchange(other.tail, nullptr); 
    }
    return *this;
}


void DLinkedList::clear()
{
    Node* current = head;
    Node* nextNode = nullptr;
    while(current) {
        nextNode = current -> next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

bool DLinkedList::empty()
{
    if(head){
        return  false;
    }
    return true;
}

void DLinkedList::push_back(int val) 
{
    Node* tmp = new Node (val);
    if(!head){
        head = tmp;
        tail = tmp;
    } 
    else {
        tail -> next = tmp;
        tmp -> prev = tail;
        tail = tmp;
    }
}

void DLinkedList::push_front(int val)
{
    Node* tmp = new Node (val);
    if(!head){
        head = tmp;
        tail = tmp;
    }
    else {
        tmp -> next = head;
        head -> prev = tmp;
        head = tmp;
    }
}

void DLinkedList::display () const{
    if(!head){
        std::cout << "Empty list" << std::endl;
    }
    Node* current = head;
    while(current) {
        std::cout << current -> value << " ";
        current = current -> next;
    }
}

void DLinkedList::pop_back(){
    if(!tail) {
        return;
    }
    if(tail){
        Node* tmp = tail -> prev;
        delete tail;
        tail = tmp;
        tail -> next = nullptr;
    }

}

void DLinkedList::pop_front()
{
    if(!head) {
        return;
    }
    if(head){
        head = head -> next;
        delete head -> prev;
        head -> prev = nullptr;
    }
}

size_t DLinkedList::size(){
    size_t count = 0;
    if(head == nullptr){
        return 0;
    }
    Node* current = head;
    while(current){
        ++count;
        current = current -> next;
    }
    return count;
}

void DLinkedList::insert(size_t index, int val){
    size_t s = size();
    if(s < index || index < 0){
        throw std::invalid_argument("Out of range");
    }

    Node* tmp = new Node (val);
    if(index == 0){
        tmp -> next = head;
        head -> prev = tmp;
        head = tmp;
        return;
    }
    
    Node* current = head;
    for(int i = 0; i < index - 1; ++i){
        current = current -> next;
    }
    tmp -> next = current -> next;
    current -> next = tmp;
    tmp -> prev = current;
    current = current -> next -> next;
    current -> prev = tmp;
}


int DLinkedList::get(size_t index) {
    size_t s = size();
    if(s < index){
        throw std::invalid_argument("Out of range");
    }
    Node* current = head;
    for(size_t i = 0; i < index; ++i) {
        current = current -> next;
    }
    return current -> value;
}

int DLinkedList::front(){ 
    return head -> value;
}

int DLinkedList::back(){
    return tail -> value;
}

void DLinkedList::remove(int val){
    Node* current = head;
    while(current){
        if(current -> value == val){
            if(current == head){
                pop_front();
            } else if(current == tail){
                pop_back();
            } else{
                current -> prev -> next = current -> next;
                current -> next -> prev = current -> prev;
                delete current ;
            }
        }
        current = current -> next;
    }
}

void DLinkedList::splice(int ind, DLinkedList& other)
{
    size_t s = size();
    if (s < ind){
        std::cout << "Out of Renge" << std::endl;
        return;
    } 
    if (ind == 0){
        other.tail -> next = head;
        head -> prev = other.tail;
        head = other.head; 
    } else if (ind == s){
        tail -> next = head;
        other.head -> prev = tail;
        tail = other.tail;
    } else {
        Node* current = head;
        for(size_t i = 0; i < ind; ++i){
            current = current -> next;
        }
        current -> next -> prev = other.tail;
        other.tail -> next = current -> next;
        current -> next = other.head;
        other.head -> prev = current;
    }
}








