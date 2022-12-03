#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"
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

class LinkList 
{
public:
	LinkList();
	LinkList(Student v[], int n);
	~LinkList();
	int GetLength() const;
	bool IsEmpty() const;
	void Clear();
	void Traverse(void (*Visit)(const string &)) const;
	void LocateElem(const int e) const;
	void GetElem(int position) const;
	void SetElem(int position, const Student &e);
	Status DeleteElem(int position);
	Status InsertElem(int position, const Student &e);
	Status InsertElem(const Student &e);
	LinkList(const LinkList &la);
	void SortInsert(Student *e);
	void Reversal();
	void Merge(LinkList *a,LinkList *b);
	LinkList& operator[] (int index);

private:
	Student* head;
	int length;
};


LinkList::LinkList()
{
	head = new Student;
	assert(head);
	length = 0;
}

LinkList::LinkList(Student v[], int n)
{
    Student *p;
	p = head = new Student();
	assert(head != 0);
	for (int i = 0; i < n; i++) {
		string na = v[i].name;
		string s = v[i].sex;
		int I = v[i].id;
		int c = v[i].Class;
		int ph = v[i].phone;
	    p->next = new Student(na,s,I,c,ph,NULL);
	    //assert(p->next);
	    p = p->next;
    }		
	length = n;
}

LinkList::~LinkList()
{
	Clear();
	delete head;
}

int LinkList::GetLength() const
{
	return length;
}

bool LinkList::IsEmpty() const
{
	return head->next == NULL;
}

void LinkList::Clear()
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
{
    Student *p = head->next;
	while (p != NULL) {
		(*Visit)(p->name);
		p = p->next;
	}
}

void LinkList::LocateElem(const int e) const
{
    Student *p = head->next;
    int count = 1;
	while (p != NULL && p->id != e) {
	    count++;
		p = p->next;
	}
	if (p != NULL)
	{
		cout << "第" << count << "个";
	}
	else {
		cout << "没有该学生";
	}
	return;
}

void LinkList::GetElem(int i) const
{
	if (i < 1 || i > length)
		cout << "不符合查找";
 	else	{
		Student *p = head->next;
		int count;
		for (count = 1; count < i; count++)
			p = p->next;
		cout << "姓名：" << p->name << " "
			<< "学号：" << p->id << " "
			<< "性别：" << p->sex << " "
			<< "班级：" << p->Class << " "
			<< "电话：" << p->phone;
	}
	return;
}

void LinkList::SetElem(int i, const Student &e)
{
	if (i < 1 || i > length)
		cout << "不符合";
	else	{	
		Student *p = head->next;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;
		p->Class = e.Class;
		p->id = e.id;
		p->name = e.name;
		p->phone = e.phone;
		p->sex = e.sex;
		cout << "修改成功";
	}
	return;
}

Status LinkList::DeleteElem(int i)
{
	if (i < 1 || i > length)		
		return RANGE_ERROR;
 	else	{
		Student *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		length--;
		delete q;
		return SUCCESS;
	}
}

Status LinkList::InsertElem(int i, const Student &e)
{
	if (i < 1 || i > length+1)
		return RANGE_ERROR;   			 
 	else	{
		Student *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
			p = p->next;
		string na = e.name;
		string s = e.sex;
		int I = e.id;
		int c = e.Class;
		int ph = e.phone;
	    q = new Student(na,s,I,c,ph,p->next);
        assert(q);	
		p->next = q;	
		length++;	
		return SUCCESS;
	}
}

Status LinkList::InsertElem(const Student &e)
{
	Student *p, *q;
	string na = e.name;
	string s = e.sex;
	int I = e.id;
	int c = e.Class;
	int ph = e.phone;
    q = new Student(na,s,I,c,ph,NULL);
    assert(q);
	for (p = head; p->next != NULL; p = p->next)
		;
    p->next = q;
	length++;
	return SUCCESS;
}

LinkList::LinkList(const LinkList &la)
{
	int laLength = la.GetLength();
	Student e;
	head = new Student;
	assert(head);
	length = 0;

	for (int i = 1; i <= laLength; i++)	{
		la.GetElem(i);
		InsertElem(e);
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
inline LinkList& LinkList::operator[](int index)
{
	assert(index < 0 || index > length-1);
	return *this;
}
#endif

