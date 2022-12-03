#include "LinkList.h"

Student v[100];
LinkList *build[100];
int num = 1;
int numb,size;

void menu()
{
	cout << "菜单：" << endl << "1:构造空链表" << '\t' << '\t' << "2:根据数组内容构造链表" << '\t';
	cout << "3:删除链表" << endl << "4:获取链表长度\t\t";
	cout << "5:判断链表是否为空" << '\t' << "6:清空链表" << endl;
	cout << "7:访问链表中各个学生姓名" << '\t' << "8:定位元素" << '\t' << '\t' << '\t';
	cout << "9:取链表中第i个元素" << endl << "10:修改链表中第i个元素的值" << '\t' << '\t';
	cout << "11:删除链表中第i个元素" << endl << "12:在链表第i个位置插入元素" << '\t' << '\t';
	cout << "13:在链表表尾插入元素" << endl << "14:排序并插入新元素" << '\t' << '\t' << '\t';
	cout << "15:按顺序合并两个链表" << endl << "16：逆置链表\t\t\t\t" << "0：退出" << endl;
}

int main(void)
{
	int option;
	menu();
	while(cin >> option)
	{
		if(option == 1)
		{
			build[num] = new LinkList();
			cout << "构造完成，链表序号为：" << num << endl;
			num++; 
			menu();
		}
		if(option == 2)
		{
			cout << "请输入数据个数:";
			int n;
			cin >> n;
			for(int i = 0; i < n; i++)
			{
				cout << "请输入学生姓名：";
				cin >> v[i].name;
				cout << "请输入学生性别：";
				cin >> v[i].sex;
				cout << "请输入学生学号：";
				cin >> v[i].id;
				cout << "请输入学生班级：";
				cin >> v[i].Class;
				cout << "请输入学生电话号码：";
				cin >> v[i].phone;
				cout << endl; 
			}
			build[num] = new LinkList(v, n);
			cout << "构造完成，链表序号为：" << num << endl;
			num++;
			menu();
		}
		if (option == 3)
		{
			cout << "请输入您想要删除的链表序号：";
			cin >> numb;
			build[numb]->~LinkList();
			menu();
		}
		if (option == 4)
		{
			cout << "请输入您想要获取长度的链表序号：";
			cin >> numb;
			cout << build[numb]->GetLength() << endl;
			menu();
		}
		if (option == 5)
		{
			cout << "请输入您想要判断的链表序号：";
			cin >> numb;
			if (build[numb]->IsEmpty())
			{
				cout << "该链表为空";
			}else{
				cout << "该链表非空";
			}
			cout << endl;
			menu();
		}
		if (option == 6)
		{
			cout << "请输入您想要清空的链表序号：";
			cin >> numb;
			cout << build[numb]->GetLength() << endl;
			menu();
		}
		if(option == 7)
		{
			cout << "请输入您想要遍历的链表:";
			cin >> numb;
			build[numb]->Traverse(Write);
			cout << endl;
			menu();
		}
		if (option == 8)
		{
			cout << "请输入您想要查找的链表:";
			cin >> numb;
			cout << "请输入您想要查找的学生学号：";
			int e;
			cin >> e;
			build[numb]->LocateElem(e);
			cout << endl;
			menu();
		}
		if (option == 9)
		{
			cout << "请输入您想要使用的链表:";
			cin >> numb;
			cout << "请输入元素的位置";
			int e;
			cin >> e;
			build[numb]->GetElem(e);
			cout << endl;
			menu();
		}
		if (option == 10)
		{
			cout << "请输入您想要使用的链表:";
			cin >> numb;
			cout << "请输入您想要修改的元素位置";
			int e;
			cin >> e;
			Student p;
			cout << "请输入学生姓名";
			cin >> p.name;
			cout << "请输入学生性别";
			cin >> p.sex;
			cout << "请输入学生学号";
			cin >> p.id;
			cout << "请输入学生班级";
			cin >> p.Class;
			cout << "请输入学生电话";
			cin >> p.phone;
			build[numb]->SetElem(e, p);
			cout << endl;
			menu();
		}
		if (option == 11)
		{
			cout << "请输入您想要使用的链表:";
			cin >> numb;
			cout << "请输入您想要删除的元素位置";
			int e;
			cin >> e;
			if(build[numb]->DeleteElem(e) == SUCCESS)
			{
				cout << "删除成功";
			}else
			{
				cout << "失败";
			}
			cout << endl;
			menu();
		}
		if (option == 12)
		{
			cout << "请输入您想要使用的链表:";
			cin >> numb;
			cout << "请输入您想要插入的元素位置";
			int e;
			cin >> e;
			Student p;
			cout << "请输入学生姓名";
			cin >> p.name;
			cout << "请输入学生性别";
			cin >> p.sex;
			cout << "请输入学生学号";
			cin >> p.id;
			cout << "请输入学生班级";
			cin >> p.Class;
			cout << "请输入学生电话";
			cin >> p.phone;
			if (build[numb]->InsertElem(e,p) == SUCCESS)
			{
				cout << "插入成功";
			}
			else
			{
				cout << "失败";
			}
			cout << endl;
			menu();
		}
		if (option == 13)
		{
			cout << "请输入您想要使用的链表:";
			cin >> numb;
			Student p;
			cout << "请输入学生姓名";
			cin >> p.name;
			cout << "请输入学生性别";
			cin >> p.sex;
			cout << "请输入学生学号";
			cin >> p.id;
			cout << "请输入学生班级";
			cin >> p.Class;
			cout << "请输入学生电话";
			cin >> p.phone;
			if (build[numb]->InsertElem(p) == SUCCESS)
			{
				cout << "删除成功";
			}
			else
			{
				cout << "失败";
			}
			cout << endl;
			menu();
		}
		if (option == 14)
		{
			Student *e;
			e = new Student;
			cout << "请输入学生姓名：";
			cin >> e->name;
			cout << "请输入学生性别：";
			cin >> e->sex;
			cout << "请输入学生学号：";
			cin >> e->id;
			cout << "请输入学生班级：";
			cin >> e->Class;
			cout << "请输入学生电话号码：";
			cin >> e->phone;
			cout << "请输入链表序号：";
			cin >> numb;
			build[numb]->SortInsert(e);
			cout << endl;
			menu();
		}
		if (option == 15)
		{
			cout << "请输入要合并的两个链表序号:";
			int a, b;
			cin >> a >> b;
			build[num] = new LinkList();
			build[num]->Merge(build[a], build[b]);
			num++;
			menu();
		}
		if (option == 16)
		{
			cout << "请输入链表序号：";
			cin >> numb;
			build[numb]->Reversal();
			cout << endl;
			menu();
		}
		if (option == 0) break;
	}

	return 0;               // 返回值0, 返回操作系统
}
