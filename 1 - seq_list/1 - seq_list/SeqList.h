#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__
#include "Assistance.h"

template <typename ElemType>
class SeqList 
{
public:
	SeqList(int size = DEFAULT_SIZE);
	SeqList(ElemType v[], int n, int size = DEFAULT_SIZE);
	virtual ~SeqList();
	int GetLength() const; 
	bool IsEmpty() const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType &)) const;
	int LocateElem(const ElemType &e) const;
	Status GetElem(int i, ElemType &e) const;
	Status SetElem(int i, const ElemType &e);
	Status DeleteElem(int i, ElemType &e);
	Status InsertElem(int i, const ElemType &e);
 	Status InsertElem(const ElemType &e);
	SeqList(const SeqList<ElemType> &sa);
	SeqList<ElemType> &operator =(const SeqList<ElemType> &sa);
	void max() const;
	void min() const;
	int InsertNew(const ElemType &e); 
	void SortElem(); 
	void deleteRange(ElemType s,ElemType t); 
	void merge(SeqList<ElemType> *sa,SeqList<ElemType> *sb);

protected:
	int length;
	int maxLength;
	ElemType* elems;
};


template <class ElemType>
void SeqList<ElemType>::SortElem()
{
	sort(elems,elems+length); 
} 
template <class ElemType>
SeqList<ElemType>::SeqList(int size)
{
	elems = new ElemType[size];
	assert(elems);
	maxLength = size;
	length = 0;
}

template <class ElemType>
SeqList<ElemType>::SeqList(ElemType v[], int n, int size)
{	
	elems = new ElemType[size];
	assert(elems);
	maxLength = size;
	length = n;
	for (int i = 0; i < length; i++)
		elems[i] = v[i]; 
}
 
template <class ElemType>
SeqList<ElemType>::~SeqList()
{
	delete []elems;
}

template <class ElemType>
int SeqList<ElemType>::GetLength() const
{
	return length;
}

template <class ElemType>
bool SeqList<ElemType>::IsEmpty() const
{
	return length == 0;
}

template <class ElemType>
void SeqList<ElemType>::Clear()
{
	length = 0;
}

template <class ElemType>
void SeqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
	for (int i = 0; i < length; i++)
		(*visit)(elems[i]);
}

template <class ElemType>
int SeqList<ElemType>::LocateElem(const ElemType &e) const
{
	int i = 0;
    while (i < length && elems[i] != e)
         i++;	
    return i < length ? i+1 : 0;
}

template <class ElemType>
Status SeqList<ElemType>::GetElem(int i, ElemType &e) const
{
	if(i < 1 || i > length)
		return NOT_PRESENT;
	else{
		e = elems[i - 1];
		return ENTRY_FOUND;
	}
}

template <class ElemType>
Status SeqList<ElemType>::SetElem(int i, const ElemType &e)
{
	if (i < 1 || i > length)
		return RANGE_ERROR;
	else	{
		elems[i - 1] = e;
		return SUCCESS;
	}
}

template <class ElemType>
Status SeqList<ElemType>::DeleteElem(int i, ElemType &e)
{
	if (i < 1 || i > length)		
		return RANGE_ERROR;
	else	{
		e = elems[i - 1];
		for (int j = i; j < length; j++)
			elems[j-1] = elems[j]; 
		length--;
		return SUCCESS;
	}
}

template <class ElemType>
Status SeqList<ElemType>::InsertElem(int i, const ElemType &e)
{
	if (length == maxLength)
		return OVER_FLOW;
	else if (i < 1 || i > length + 1)
		return RANGE_ERROR;
	else	{
		for (int j = length; j >= i; j--)
			elems[j] = elems[j - 1]; 
		elems[i - 1] = e;
   		length++;
     	return SUCCESS;
	}
}

template <class ElemType>
Status SeqList<ElemType>::InsertElem(const ElemType &e)
{
	if (length==maxLength)
		return OVER_FLOW;	
	else{
		elems[length] = e;
   		length++;
     	return SUCCESS;
	}
}

template <class ElemType>
SeqList<ElemType>::SeqList(const SeqList<ElemType> &sa)
{
	int saLength = sa.GetLength();
	ElemType e;

	maxLength = sa.maxLength;
	elems = new ElemType[maxLength];
	assert(elems);
	length = 0;

	for (int i = 1; i <= saLength; i++)	{
		sa.GetElem(i, e);
		InsertElem(e);
	}
	
}

template <class ElemType>
SeqList<ElemType> &SeqList<ElemType>::operator =(const SeqList<ElemType> &sa)
{
	if (&sa != this){
		int saLength = sa.GetLength();
		ElemType e;

        maxLength = sa.maxLength;
        delete []elems;
        elems = new ElemType[maxLength];
	    assert(elems);
        length = 0;
        for (int i = 1; i <= saLength; i++)	{
			sa.getElem(i, e);
			insert(e);
		}
	}
	return *this;
}

template <class ElemType>
void SeqList<ElemType>::max() const
{
	ElemType maxx = elems[0];

	for (int i = 0; i < length; i++){
		if (elems[i] > maxx) {
			maxx = elems[i];
		}
	}
	cout << "最大值为: " << maxx << endl; 
	cout << "元素位置为:"; 
	for (int i = 0; i < length; i++) {
		if (elems[i] == maxx) {
			cout << " " << i + 1;
		}
	}
	cout << endl; 
	return;
}


template <class ElemType>
void SeqList<ElemType>::min() const
{
	ElemType minx = elems[0];
	for (int i = 0; i < length; i++) {
		if (elems[i] < minx) {
			minx = elems[i];
		}
	}
	cout << "最小值为: " << minx << endl; 
	cout << "元素位置为:"; 
	for (int i = 0; i < length; i++) {
		if (elems[i] == minx) {
			cout << " " << i + 1;
		}
	}
	cout << endl; 
	return;
}


template <class ElemType>
int SeqList<ElemType>::InsertNew(const ElemType &e)
{
	if (length == maxLength)
		return OVER_FLOW;
	sort(elems,elems+length);

	int i = 0;
	while (i < length - 1)
	{
		if (elems[i] <= e && elems[i + 1] >= e)
		{
			InsertElem(i + 2, e);
			break;
		}
		i++;
	}
	if(i == length-1 && elems[length] < e)
		InsertElem(length+1 , e); 

	cout << "当前顺序表元素值依次为:"; 
	for (int i = 0; i < length; i++)
		cout << " " << elems[i];
	cout << endl; 
	return 0;
}


template <class ElemType>
void SeqList<ElemType>::deleteRange(ElemType s,ElemType t)
{
	sort(elems,elems+length); 
	int p = 0;  
	for (int i = 0; i < length; i++) {
		if (s >= elems[i] || elems[i] >= t)
		{
			elems[p] = elems[i];
			p++;
		}
	}
	length = p; 
}


template <class ElemType>
void SeqList<ElemType>::merge(SeqList<ElemType> *sa,SeqList<ElemType> *sb)
{
	sort(sa->elems,sa->elems+sa->length);
	sort(sb->elems,sb->elems+sb->length);
	length = sa->length + sb->length;
	maxLength = length;
	int la = 0;
	int lb = 0;
	for(int i = 0; i < length; i++)
	{
		if(la == sa->length)
		{
			elems[i] = *(sb->elems);
			lb++;
			sb->elems++;
			continue;
		}
		if(lb == sb->length)
		{
			elems[i] = *(sa->elems);
			la++;
			sa->elems++;
		}
		if(la < sa->length && lb < sb->length)
		{
			if(*(sa->elems) < *(sb->elems) )
			{
				elems[i] = *(sa->elems);
				sa->elems++;
				la++;
			}else
			{
				elems[i] = *(sb->elems);
				sb->elems++;
				lb++;
			}
		}
	}
}

#endif
