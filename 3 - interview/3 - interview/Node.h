#ifndef __NODE_H__
#define __NODE_H__

template <class ElemType>
struct Node
{
	Node();
	Node(ElemType e, Node<ElemType>* link = NULL);

	ElemType data;
	Node<ElemType>* next;
	Node<ElemType>* prior;
    bool IsVisited; 
};

template<class ElemType>
Node<ElemType>::Node()
{
    prior = nullptr;
	next = nullptr;
    IsVisited = false;
}

template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType>* link)
{
	data = e;
	next = link;
    IsVisited = false;
}

#endif