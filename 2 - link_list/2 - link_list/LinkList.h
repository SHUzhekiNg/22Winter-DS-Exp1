#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"				// 辅助软件包
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
// 单链表类
class LinkList 
{
protected:
//  单链表的数据成员
	Student *head;				// 头结点指针
	int length;							// 单链表长度 

public:
//  单链表的函数成员 
	LinkList();							// 无参数的构造函数
	LinkList(Student v[], int n);		// 有参数的构造函数
	virtual ~LinkList();				// 析构函数
	int GetLength() const;				// 求单链表长度			 
	bool IsEmpty() const;	 			// 判断单链表是否为空
	void Clear();						// 将单链表清空
	void Traverse(void (*Visit)(const string &)) const;// 遍历单链表
	void LocateElem(const int e) const;	         // 元素定位 
	void GetElem(int position) const;	 // 求指定位置的元素	
	void SetElem(int position, const Student &e);	 // 设置指定位置的元素值
	Status DeleteElem(int position);		 // 删除元素		
	Status InsertElem(int position, const Student &e);	 // 在制定位置插入元素
	Status InsertElem(const Student &e);	             // 在表尾插入元素
	LinkList(const LinkList &la);            // 复制构造函数
	void SortInsert(Student *e);
	void Reversal();
	void Merge(LinkList *a,LinkList *b);
};


// 单链表类的实现部分


LinkList::LinkList()
// 操作结果：构造一个空链表
{
	head = new Student;		// 构造头结点
	assert(head);                   // 构造头结点失败，终止程序运行 
	length = 0;						// 初始化单链表长度为0 
}

LinkList::LinkList(Student v[], int n)
// 操作结果：根据数组v中的元素构造单链表
{
    Student *p;
	p = head = new Student();	// 构造头结点 
	assert(head != 0);              // 构造头结点失败，终止程序运行 
	for (int i = 0; i < n; i++) {
		string na = v[i].name;
		string s = v[i].sex;
		int I = v[i].id;
		int c = v[i].Class;
		int ph = v[i].phone;
	    p->next = new Student(na,s,I,c,ph,NULL);
	    //assert(p->next);            // 构造元素结点失败，终止程序运行 
	    p = p->next;
    }		
	length = n;						// 初始化单链表长度为n
}

LinkList::~LinkList()
// 操作结果：销毁单链表
{
	Clear();			// 清空单链表
	delete head;		// 释放头结点所指空间
}

int LinkList::GetLength() const
// 操作结果：返回单链表的长度 
{
	return length;
}

bool LinkList::IsEmpty() const
// 操作结果：如单链表为空，则返回true，否则返回false
{
	return head->next == NULL;
}

void LinkList::Clear()
// 操作结果：清空单链表,删除单链表中所有元素结点 
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
// 操作结果：依次对单链表的每个元素调用函数(*visit)访问
{
    Student *p = head->next;
	while (p != NULL) {
		(*Visit)(p->name);
		p = p->next;
	}
}

void LinkList::LocateElem(const int e) const
// 元素定位 
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
// 操作结果：当单链表存在第i个元素时，用e返回其值，函数返回ENTRY_FOUND,
//	否则函数返回NOT_PRESENT
{
	if (i < 1 || i > length)
		cout << "不符合查找";
 	else	{
		Student *p = head->next;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	            // p指向第i个结点
		//e = p->data;				// 用e返回第i个元素的值
		cout << "姓名：" << p->name << "学号：" << p->id << "性别：" << p->sex << "班级：" << p->Class << "电话：" << p->phone;
	}
	return;
}

void LinkList::SetElem(int i, const Student &e)
// 操作结果：将单链表的第i个位置的元素赋值为e,
{
	if (i < 1 || i > length)
		cout << "不符合";
	else	{	
		Student *p = head->next;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	           // 取出指向第i个结点的指针	
		p->Class = e.Class;			   // 修改第i个元素的值为e 
		p->id = e.id;
		p->name = e.name;
		p->phone = e.phone;
		p->sex = e.sex;
		cout << "修改成功";
	}
	return;
}

Status LinkList::DeleteElem(int i)
// 操作结果：删除单链表的第i个位置的元素, 并用e返回其值,
//	i的取值范围为1≤i≤length,
//	i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
	if (i < 1 || i > length)		
		return RANGE_ERROR;   // i范围错		 
 	else	{
		Student *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	      // p指向第i-1个结点	
		q = p->next;	      // q指向第i个结点
		p->next = q->next;	  // 删除结点
		//e = q->data;		  // 用e返回被删结点元素值	
		length--;			  // 删除成功后元素个数减1 
		delete q;			  // 释放被删结点
		return SUCCESS;
	}
}

Status LinkList::InsertElem(int i, const Student &e)
// 操作结果：在单链表的第i个位置前插入元素e
//	i的取值范围为1≤i≤length+1
//	i合法时返回SUCCESS, 否则函数返回RANGE_ERROR
{
	if (i < 1 || i > length+1)
		return RANGE_ERROR;   			 
 	else	{
		Student *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	                    // p指向第i-1个结点
		string na = e.name;
		string s = e.sex;
		int I = e.id;
		int c = e.Class;
		int ph = e.phone;
	    q = new Student(na,s,I,c,ph,p->next);
        assert(q);                          // 申请结点失败，终止程序运行 
		p->next = q;				        // 将q插入到链表中
		length++;							// 插入成功后，单链表长度加1 
		return SUCCESS;
	}
}

Status LinkList::InsertElem(const Student &e)
// 操作结果：在单链表的表尾位置插入元素e
{
	Student *p, *q;
	string na = e.name;
	string s = e.sex;
	int I = e.id;
	int c = e.Class;
	int ph = e.phone;
    q = new Student(na,s,I,c,ph,NULL);   // 生成新结点q
    assert(q);                          // 申请结点失败，终止程序运行 
	for (p = head; p->next != NULL; p = p->next) ;	// p指向表尾结点	
    p->next = q;                        // 在单链表的表尾位置插入新结点 
	length++;							// 插入成功后，单链表长度加1 
	return SUCCESS;
}

LinkList::LinkList(const LinkList &la)
// 操作结果：复制构造函数，由单链表la构造新单链表
{
	int laLength = la.GetLength();	// 取被复制单链表的长度
	Student e;
	head = new Student;		// 构造头指针
	assert(head);                   // 构造头指针失败，终止程序运行 
	length = 0;						// 初始化元素个数

	for (int i = 1; i <= laLength; i++)	{	// 复制数据元素
		la.GetElem(i);	       // 取出第i个元素的值放在e中 
		InsertElem(e);		       // 将e插入到当前单链表的表尾 
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

