#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"				// ���������
#include "Node.h"					// �����

// ��������
template <class ElemType>
class LinkList
{
protected:
    //  ����������ݳ�Ա
    Node<ElemType>* head;				// ͷ���ָ��
    Node<ElemType>* tail;               // β���ָ��
    int length;							// ��������

public:
    //  ������ĺ�����Ա
    LinkList();							// �޲����Ĺ��캯��
    LinkList(int n);		// �в����Ĺ��캯��
    virtual ~LinkList();				// ��������
    int GetLength() const;				// ��������
    void Traverse(void (*Visit)(const ElemType&)) const;// ����������
    Node<ElemType> * VisitElemX(int n);
    Node<ElemType> * VisitElemY(int m);
    void Visited(Node<ElemType>* &node);
    bool AllTrue();
};


// ���������ʵ�ֲ���

template <class ElemType>
LinkList<ElemType>::LinkList()
// �������������һ��������
{
    head = NULL;		// ����ͷ���
    //assert(head);                   // ����ͷ���ʧ�ܣ���ֹ��������
    length = 0;						// ��ʼ����������Ϊ0
}

template <class ElemType>
LinkList<ElemType>::LinkList(int n)
// �����������������v�е�Ԫ�ع��쵥����
{
    Node<ElemType>* p;
    p = head = new Node<ElemType>(1,NULL);	// ����ͷ���
    assert(head != 0);              // ����ͷ���ʧ�ܣ���ֹ��������
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
    length = n;						// ��ʼ����������Ϊn
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
// ������������ٵ�����
{
    delete head;		// �ͷ�ͷ�����ָ�ռ�
}

template <class ElemType>
int LinkList<ElemType>::GetLength() const
// ������������ص�����ĳ���
{
    return length;
}

template <class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType&)) const
// ������������ζԵ������ÿ��Ԫ�ص��ú���(*visit)����
{
    Node<ElemType>* p = head;
    (*Visit)(p->data);
    p = p->next;
    while (p != head) {
        (*Visit)(p->data);	// �Ե�������ÿ��Ԫ�ص��ú���(*visit)����
        p = p->next;
    }
    cout << endl;
}

template<class ElemType>
bool LinkList<ElemType>::AllTrue() {
    auto * ptr = head;
    for (int i = 0; i < length; ++i,ptr = ptr->next) {
        if (ptr->IsVisit == false)
            return false;
    }
    return true;
}

template<class ElemType>
void LinkList<ElemType>::Visited(Node<ElemType>* &node) {
    node->IsVisit = true;
    cout<<node->data;
}


template<class ElemType>
Node<ElemType> * LinkList<ElemType>::VisitElemX(int n) {
    int i = 0;
    if (head->IsVisit == false)
        i = 1;
    for (; i < n; ++i) {
        while (head->next->IsVisit == true){
            head = head->next;
        }
        head = head->next;
    }
    return head;
}




template<class ElemType>
Node<ElemType> * LinkList<ElemType>::VisitElemY(int m) {
    int i = 0;
    if (tail->IsVisit == false)
        i = 1;
    for (; i < m; ++i) {
        while (tail->prior->IsVisit != false){
            tail = tail->prior;
        }
        tail = tail->prior;
    }
    return tail;
}

template<class ElemType>
void PrintFormat(LinkList<ElemType> &list,int &count){
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
