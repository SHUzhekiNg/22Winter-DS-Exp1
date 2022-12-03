#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"
#include "Node.h"

template <class ElemType>
class LinkList
{
public:
    LinkList();
    LinkList(ElemType v[], int n);
    ~LinkList();
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();
    void Traverse(void (*Visit)(const ElemType &)) const;
    int LocateElem(const ElemType &e) const;
    Status GetElem(int position, ElemType &e) const;
    Status SetElem(int position, const ElemType &e);
    Status DeleteElem(int position, ElemType &e);
    Status InsertElem(int position, const ElemType &e);
    Status InsertElem(const ElemType &e);
    LinkList(const LinkList<ElemType> &la);
    LinkList<ElemType> &operator =(const LinkList<ElemType> &la);
    void tempPrint();
    void reversal();

private:
    Node<ElemType>* head;
    int length;
};


template <class ElemType>
LinkList<ElemType>::LinkList()
{
    head = NULL;
    length = 0;
}

template <class ElemType>
LinkList<ElemType>::LinkList(ElemType v[], int n)
{
    Node<ElemType> *p;
    p = head = new Node<ElemType>(v[0],NULL);
    assert(head != 0);
    for (int i = 1; i < n; i++) {
        p->next = new Node<ElemType>(v[i],NULL);
        p = p->next; 
        if(i == n-1)
		{
			p->next = head;
		} 
    }
    length = n;
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
{
    Clear();
    delete head;
}

template <class ElemType>
int LinkList<ElemType>::GetLength() const
{
    return length;
}

template <class ElemType>
bool LinkList<ElemType>::IsEmpty() const
{
    return head == NULL;
}

template <class ElemType>
void LinkList<ElemType>::Clear()
{
    Node<ElemType> *p = head;

    while(length > 0) {
        if (length > 1)
            head = p->next;
        delete p;
        --length;
        if (length != 0)
            p = head;
    }
    head = nullptr;
}

template <class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    Node<ElemType> *p = head;
    (*Visit)(p->data);
    p = p->next;
    while (p != head) {
        (*Visit)(p->data);
        p = p->next;
    }
    cout<<endl;
}

template <class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &e) const
// ÔªËØ¶¨Î»
{
    Node<ElemType> *p = head;
    int count = 1;
    if(p->data == e) return 1;
    while (p != NULL && p->data != e) {
        count++;
        p = p->next;
        if(p == head) break;
    }
    return  (p != NULL) ? count : 0;
}

template <class ElemType>
Status LinkList<ElemType>::GetElem(int i, ElemType &e) const
{
    if (i < 1 || i > length)
        return RANGE_ERROR;
    else	{
        Node<ElemType> *p = head;
        int count;
        for (count = 1; count < i; count++)
            p = p->next;
        e = p->data;
        return ENTRY_FOUND;
    }
}

template <class ElemType>
Status LinkList<ElemType>::SetElem(int i, const ElemType &e)
{
    if (i < 1 || i > length)
        return RANGE_ERROR;
    else	{
        Node<ElemType> *p = head;
        int count;
        for (count = 1; count < i; count++)
        {
            p = p->next;
        }
        p->data = e;
        return SUCCESS;
    }
}

template <class ElemType>
Status LinkList<ElemType>::DeleteElem(int i, ElemType &e)
{
    if (i < 1 || i > length)
        return RANGE_ERROR;
    else{
        Node<ElemType> *p = head, *q;
        if (i==1)
        {
            e=p->data;
            q=p->next;
            head->data=q->data;
            head->next=q->next;
        }
        else
        {
            for (int count = 1; count < i-1; count++)
            {
                p = p->next;
            }
            q=p->next;
            q->data=p->next->data;
            e=q->data;
            p->next=q->next;
        }
        length--;
        delete q;
        return SUCCESS;
    }
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(int i, const ElemType &e)
{
    if (i < 1 || i > length+1)
        return RANGE_ERROR;
    else	{
        if (length >= 1) {
            if (i == 1){
                ElemType data = head->data;
                head->data = e;
                auto * node = new Node<ElemType>;
                node->data = data;
                node->next = head->next;
                head->next = node;
            }
            else {
                Node<ElemType> *p = head;
                int count;
                for (count = 1; count < i-1; count++)
                    p = p->next;
                auto *node = new Node<ElemType>;
                node->data = e;
                node->next = p->next;
                p->next = node;
            }
        }
        else
        {
            head = new Node<ElemType>;
            head->data = e;
            head->next = head;
        }
        length++;
        return SUCCESS;
    }
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(const ElemType &e)
{
    if (length >= 1) {
        Node<ElemType> * ptr = head;
        for (int i = 0; i < length - 1; ++i) {
            ptr = ptr->next;
        }
        auto * node = new Node<ElemType>;
        node->data = e;
        node->next = ptr->next;
        ptr->next = node;
    }
    else{
        head = new Node<ElemType>;
        head->data = e;
        head->next = head;
    }
    length++;
    return SUCCESS;
}

template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &la)
{
    int laLength = la.GetLength();
    ElemType e;
    head = new Node<ElemType>(la.head->data, NULL);
    length = 0;

    for (int i = 2; i <= laLength; i++)	{
        la.GetElem(i, e);
        InsertElem(e);
    }
}

template <class ElemType>
LinkList<ElemType> &LinkList<ElemType>::operator =(const LinkList<ElemType> &la)
{
    if (&la != this)	{
        int laLength = la.GetLength();
        ElemType e;
        Clear();
        head = new Node<ElemType>(la.head->data, NULL);
        for (int i = 2; i <= laLength; i++)		{
            la.GetElem(i, e);
            InsertElem(e);
        }
    }
    return *this;
}

template <class ElemType>
void LinkList<ElemType>::reversal() {
    if (head->next != head && head->next->next!= head){
        Node<ElemType> * p = head;
        Node<ElemType> * q = p->next;
        Node<ElemType> * r = q->next;
        for (int i = length; i > 0; --i) {
            q->next = p;
            if (i == 1)
                break;
            p = q;
            q = r;
            r = r->next;
        }
        head = p;
    }
    else if(head->next->next == head){
        head = head->next;
    }
}
#endif

