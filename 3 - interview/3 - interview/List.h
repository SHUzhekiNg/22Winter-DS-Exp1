#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"				// 辅助软件包
#include "Node.h"					// 结点类

// 单链表类
template <class ElemType>
class LinkList
{
protected:
    //  单链表的数据成员
    Node<ElemType>* head;				// 头结点指针
    Node<ElemType>* tail;               // 尾结点指针
    int length;							// 单链表长度

public:
    //  单链表的函数成员
    LinkList();							// 无参数的构造函数
    LinkList(int n);		// 有参数的构造函数
    virtual ~LinkList();				// 析构函数
    int GetLength() const;				// 求单链表长度
    void Traverse(void (*Visit)(const ElemType&)) const;// 遍历单链表
    Node<ElemType> * VisitElemX(int n);
    Node<ElemType> * VisitElemY(int m);
    void Visited(Node<ElemType>* &node);
    bool AllTrue();
};


// 单链表类的实现部分

template <class ElemType>
LinkList<ElemType>::LinkList()
// 操作结果：构造一个空链表
{
    head = NULL;		// 构造头结点
    //assert(head);                   // 构造头结点失败，终止程序运行
    length = 0;						// 初始化单链表长度为0
}

template <class ElemType>
LinkList<ElemType>::LinkList(int n)
// 操作结果：根据数组v中的元素构造单链表
{
    Node<ElemType>* p;
    p = head = new Node<ElemType>(1,NULL);	// 构造头结点
    assert(head != 0);              // 构造头结点失败，终止程序运行
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
    length = n;						// 初始化单链表长度为n
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
// 操作结果：销毁单链表
{
    delete head;		// 释放头结点所指空间
}

template <class ElemType>
int LinkList<ElemType>::GetLength() const
// 操作结果：返回单链表的长度
{
    return length;
}

template <class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType&)) const
// 操作结果：依次对单链表的每个元素调用函数(*visit)访问
{
    Node<ElemType>* p = head;
    (*Visit)(p->data);
    p = p->next;
    while (p != head) {
        (*Visit)(p->data);	// 对单链表中每个元素调用函数(*visit)访问
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
