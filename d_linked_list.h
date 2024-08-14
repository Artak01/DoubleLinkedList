#ifndef D_LINKED_LIST_H
#define D_LINKED_LIST_H


class DLinkedList
{
public:
    DLinkedList();
    ~DLinkedList();
    DLinkedList(const DLinkedList& other);
    DLinkedList(DLinkedList&& other);

    DLinkedList& operator= (const DLinkedList& other);
    DLinkedList& operator= (DLinkedList&& other);

public:
    void clear();    
    bool empty();
    void push_back(int);
    void push_front(int);
    void display() const;
    void pop_back();
    void pop_front();
    size_t size();
    void insert(size_t, int);
    int get(size_t);
    void remove(int);
    int front();
    int back();
    void splice(int pos, DLinkedList&);
private:
    struct Node
    {
        Node* prev;
        int value;
        Node* next;
        Node(int);
    };
    Node* head;
    Node* tail;
};
#endif
