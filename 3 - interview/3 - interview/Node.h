#ifndef __NODE_H__
#define __NODE_H__

// 结点类
template <class ElemType>
struct Node
{
	// 数据成员:
	ElemType data;				// 数据域
	Node<ElemType>* next;		// 指针域
	Node<ElemType>* prior;      // 指针指向上一个
    bool IsVisit;               // bool判断，默认为false
// 构造函数:
	Node();						// 无参数的构造函数
	Node(ElemType e, Node<ElemType>* link = NULL);	// 已知数数据元素值和指针建立结构
};

// 结点类的实现部分
template<class ElemType>
Node<ElemType>::Node()
// 操作结果：构造指针域为空的结点
{
    prior = nullptr;
	next = nullptr;
    IsVisit = false;
}

template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType>* link)
// 操作结果：构造一个数据域为e和指针域为link的结点
{
	data = e;
	next = link;
    IsVisit = false;
}

#endif