#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"
#include "Node.h"

template <class ElemType>
class LinkList
{
public:
    LinkList();
    LinkList(int n);
    virtual ~LinkList();
    int GetLength() const;
    void Traverse(void (*Visit)(const ElemType&)) const;
    Node<ElemType> * VisitElemX(int n);
    Node<ElemType> * VisitElemY(int m);
    void Visited(Node<ElemType>* &node);
    bool AllTrue();

private:
    Node<ElemType>* head;
    Node<ElemType>* tail;
    int length;
};


template <class ElemType>
LinkList<ElemType>::LinkList()
{
    head = NULL;
    length = 0;
}

template <class ElemType>
LinkList<ElemType>::LinkList(int n)
{
    Node<ElemType>* p;
    p = head = new Node<ElemType>(1,NULL);
    assert(head != 0);
    for (int i = 2; i <= n; i++) {
        p->next = new Node<ElemType>(i, NULL);
        p->next->prior = p;
        p = p->next;
        if (i == n)
        {
            p->next = head;
            tail = p;
            head->prior = tail;
        }
    }
    length = n;
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
{
    delete head;
}

template <class ElemType>
int LinkList<ElemType>::GetLength() const
{
    return length;
}

template <class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType&)) const
{
    Node<ElemType>* p = head;
    (*Visit)(p->data);
    p = p->next;
    while (p != head) {
        (*Visit)(p->data);
        p = p->next;
    }
    cout << endl;
}

template<class ElemType>
bool LinkList<ElemType>::AllTrue() {
    auto * ptr = head;
    for (int i = 0; i < length; ++i,ptr = ptr->next) {
        if (ptr->IsVisited == false)
            return false;
    }
    return true;
}

template<class ElemType>
void LinkList<ElemType>::Visited(Node<ElemType>* &node) {
    node->IsVisited = true;
    cout<<node->data;
}


template<class ElemType>
Node<ElemType> * LinkList<ElemType>::VisitElemX(int n) {
    int i = 0;
    if (head->IsVisited == false)
        i = 1;
    for (; i < n; ++i) {
        while (head->next->IsVisited == true){
            head = head->next;
        }
        head = head->next;
    }
    return head;
}


template<class ElemType>
Node<ElemType> * LinkList<ElemType>::VisitElemY(int m) {
    int i = 0;
    if (tail->IsVisited == false)
        i = 1;
    for (; i < m; ++i) {
        while (tail->prior->IsVisited != false){
            tail = tail->prior;
        }
        tail = tail->prior;
    }
    return tail;
}

template<class ElemType>
void Print(LinkList<ElemType> &list,int &count){
    count++;
    if (count == 1)
        cout<<",";
    else if(count == 2) {
        if (!list.AllTrue()) {
            cout << ";";
            count = 0;
        }
    }
}

#endif
