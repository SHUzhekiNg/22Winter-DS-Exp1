#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"				// ���������
struct Student
{
	string name, sex;
	int id,Class,phone;	
	Student *next;
	Student();
	Student(string n,string s,int i,int c,int p,Student *link = NULL);
}; 
Student::Student()
{
	next = NULL;
}
Student::Student(string n,string s,int i,int c,int p,Student *link)
{
	name = n;
	sex = s;
	id = i;
	Class = c;
	phone = p;
	next = link;
} 
// ��������
class LinkList 
{
protected:
//  ����������ݳ�Ա
	Student *head;				// ͷ���ָ��
	int length;							// �������� 

public:
//  ������ĺ�����Ա 
	LinkList();							// �޲����Ĺ��캯��
	LinkList(Student v[], int n);		// �в����Ĺ��캯��
	virtual ~LinkList();				// ��������
	int GetLength() const;				// ��������			 
	bool IsEmpty() const;	 			// �жϵ������Ƿ�Ϊ��
	void Clear();						// �����������
	void Traverse(void (*Visit)(const string &)) const;// ����������
	void LocateElem(const int e) const;	         // Ԫ�ض�λ 
	void GetElem(int position) const;	 // ��ָ��λ�õ�Ԫ��	
	void SetElem(int position, const Student &e);	 // ����ָ��λ�õ�Ԫ��ֵ
	Status DeleteElem(int position);		 // ɾ��Ԫ��		
	Status InsertElem(int position, const Student &e);	 // ���ƶ�λ�ò���Ԫ��
	Status InsertElem(const Student &e);	             // �ڱ�β����Ԫ��
	LinkList(const LinkList &la);            // ���ƹ��캯��
	void SortInsert(Student *e);
	void Reversal();
	void Merge(LinkList *a,LinkList *b);
};


// ���������ʵ�ֲ���


LinkList::LinkList()
// �������������һ��������
{
	head = new Student;		// ����ͷ���
	assert(head);                   // ����ͷ���ʧ�ܣ���ֹ�������� 
	length = 0;						// ��ʼ����������Ϊ0 
}

LinkList::LinkList(Student v[], int n)
// �����������������v�е�Ԫ�ع��쵥����
{
    Student *p;
	p = head = new Student();	// ����ͷ��� 
	assert(head != 0);              // ����ͷ���ʧ�ܣ���ֹ�������� 
	for (int i = 0; i < n; i++) {
		string na = v[i].name;
		string s = v[i].sex;
		int I = v[i].id;
		int c = v[i].Class;
		int ph = v[i].phone;
	    p->next = new Student(na,s,I,c,ph,NULL);
	    //assert(p->next);            // ����Ԫ�ؽ��ʧ�ܣ���ֹ�������� 
	    p = p->next;
    }		
	length = n;						// ��ʼ����������Ϊn
}

LinkList::~LinkList()
// ������������ٵ�����
{
	Clear();			// ��յ�����
	delete head;		// �ͷ�ͷ�����ָ�ռ�
}

int LinkList::GetLength() const
// ������������ص�����ĳ��� 
{
	return length;
}

bool LinkList::IsEmpty() const
// ����������絥����Ϊ�գ��򷵻�true�����򷵻�false
{
	return head->next == NULL;
}

void LinkList::Clear()
// �����������յ�����,ɾ��������������Ԫ�ؽ�� 
{
    Student *p = head->next;
	while (p != NULL) {
		head->next = p->next;
        delete p; 
		p = head->next;
	}
	length = 0;
}

void LinkList::Traverse(void (*Visit)(const string &)) const 
// ������������ζԵ������ÿ��Ԫ�ص��ú���(*visit)����
{
    Student *p = head->next;
	while (p != NULL) {
		(*Visit)(p->name);
		p = p->next;
	}
}

void LinkList::LocateElem(const int e) const
// Ԫ�ض�λ 
{
    Student *p = head->next;
    int count = 1;
	while (p != NULL && p->id != e) {
	    count++;
		p = p->next;
	}
	if (p != NULL)
	{
		cout << "��" << count << "��";
	}
	else {
		cout << "û�и�ѧ��";
	}
	return;
}

void LinkList::GetElem(int i) const
// �������������������ڵ�i��Ԫ��ʱ����e������ֵ����������ENTRY_FOUND,
//	����������NOT_PRESENT
{
	if (i < 1 || i > length)
		cout << "�����ϲ���";
 	else	{
		Student *p = head->next;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	            // pָ���i�����
		//e = p->data;				// ��e���ص�i��Ԫ�ص�ֵ
		cout << "������" << p->name << "ѧ�ţ�" << p->id << "�Ա�" << p->sex << "�༶��" << p->Class << "�绰��" << p->phone;
	}
	return;
}

void LinkList::SetElem(int i, const Student &e)
// �����������������ĵ�i��λ�õ�Ԫ�ظ�ֵΪe,
{
	if (i < 1 || i > length)
		cout << "������";
	else	{	
		Student *p = head->next;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	           // ȡ��ָ���i������ָ��	
		p->Class = e.Class;			   // �޸ĵ�i��Ԫ�ص�ֵΪe 
		p->id = e.id;
		p->name = e.name;
		p->phone = e.phone;
		p->sex = e.sex;
		cout << "�޸ĳɹ�";
	}
	return;
}

Status LinkList::DeleteElem(int i)
// ���������ɾ��������ĵ�i��λ�õ�Ԫ��, ����e������ֵ,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
	if (i < 1 || i > length)		
		return RANGE_ERROR;   // i��Χ��		 
 	else	{
		Student *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	      // pָ���i-1�����	
		q = p->next;	      // qָ���i�����
		p->next = q->next;	  // ɾ�����
		//e = q->data;		  // ��e���ر�ɾ���Ԫ��ֵ	
		length--;			  // ɾ���ɹ���Ԫ�ظ�����1 
		delete q;			  // �ͷű�ɾ���
		return SUCCESS;
	}
}

Status LinkList::InsertElem(int i, const Student &e)
// ����������ڵ�����ĵ�i��λ��ǰ����Ԫ��e
//	i��ȡֵ��ΧΪ1��i��length+1
//	i�Ϸ�ʱ����SUCCESS, ����������RANGE_ERROR
{
	if (i < 1 || i > length+1)
		return RANGE_ERROR;   			 
 	else	{
		Student *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	                    // pָ���i-1�����
		string na = e.name;
		string s = e.sex;
		int I = e.id;
		int c = e.Class;
		int ph = e.phone;
	    q = new Student(na,s,I,c,ph,p->next);
        assert(q);                          // ������ʧ�ܣ���ֹ�������� 
		p->next = q;				        // ��q���뵽������
		length++;							// ����ɹ��󣬵������ȼ�1 
		return SUCCESS;
	}
}

Status LinkList::InsertElem(const Student &e)
// ����������ڵ�����ı�βλ�ò���Ԫ��e
{
	Student *p, *q;
	string na = e.name;
	string s = e.sex;
	int I = e.id;
	int c = e.Class;
	int ph = e.phone;
    q = new Student(na,s,I,c,ph,NULL);   // �����½��q
    assert(q);                          // ������ʧ�ܣ���ֹ�������� 
	for (p = head; p->next != NULL; p = p->next) ;	// pָ���β���	
    p->next = q;                        // �ڵ�����ı�βλ�ò����½�� 
	length++;							// ����ɹ��󣬵������ȼ�1 
	return SUCCESS;
}

LinkList::LinkList(const LinkList &la)
// ������������ƹ��캯�����ɵ�����la�����µ�����
{
	int laLength = la.GetLength();	// ȡ�����Ƶ�����ĳ���
	Student e;
	head = new Student;		// ����ͷָ��
	assert(head);                   // ����ͷָ��ʧ�ܣ���ֹ�������� 
	length = 0;						// ��ʼ��Ԫ�ظ���

	for (int i = 1; i <= laLength; i++)	{	// ��������Ԫ��
		la.GetElem(i);	       // ȡ����i��Ԫ�ص�ֵ����e�� 
		InsertElem(e);		       // ��e���뵽��ǰ������ı�β 
	}
}

void LinkList::SortInsert(Student *e)
{
	Student* p = head->next;
	Student* q = NULL;
	int count = length-1;
	while (count--)
	{
		q = p->next;
		while (q)
		{
			if (q->id < p->id)
			{
				Swap(q->id, p->id);
				Swap(q->Class, p->Class);
				Swap(q->name, p->name);
				Swap(q->phone, p->phone);
				Swap(q->sex, p->sex);
			}
			q = q->next;
		}
		p = p->next;
	}
	p = head->next;
	if (p->id > e->id)
	{
		e->next = p;
		head->next = e;
		return;
	}
	while (p->next)
	{
		if(p->id < e->id && p->next->id > e->id)
		{
			e->next = p->next;	
			p->next = e;
			length++;
			return;
		}
		p = p->next;
	}
	p->next = e;
	e->next = NULL;
	return;
}

void LinkList::Reversal()
{
	if (length <= 1) return;
	Student* p = head->next, * pre = NULL, * t = NULL;
	while (p)
	{
		t = p;
		p = p->next;
		t->next = pre;
		pre = t;
	}
	head->next = pre;
}

void LinkList::Merge(LinkList *a,LinkList *b)
{
	Student* p = a->head->next;
	Student* q = NULL;
	int count = a->length - 1;
	while (count--)
	{
		q = p->next;
		while (q)
		{
			if (q->id < p->id)
			{
				Swap(q->id, p->id);
				Swap(q->Class, p->Class);
				Swap(q->name, p->name);
				Swap(q->phone, p->phone);
				Swap(q->sex, p->sex);
			}
			q = q->next;
		}
		p = p->next;
	}
	p = b->head->next;
	q = NULL;
	count = b->length - 1;
	while (count--)
	{
		q = p->next;
		while (q)
		{
			if (q->id < p->id)
			{
				Swap(q->id, p->id);
				Swap(q->Class, p->Class);
				Swap(q->name, p->name);
				Swap(q->phone, p->phone);
				Swap(q->sex, p->sex);
			}
			q = q->next;
		}
		p = p->next;
	}
	p = a->head->next;
	q = b->head->next;
	Student* t = head;
	length = a->length + b->length;
	for (int i = 0; i < length; i++)
	{
		if (!p)
		{
			t->next = q;
			q = q->next;
			t = t->next;
			continue;
		}
		if (!q)
		{
			t->next = p;
			p = p->next;
			t = t->next;
			continue;
		}
		if (p->id < q->id)
		{
			t->next = p;
			p = p->next;
			t = t->next;
		}
		else
		{
			t->next = q;
			q = q->next;
			t = t->next;
		}
	}
}
#endif

