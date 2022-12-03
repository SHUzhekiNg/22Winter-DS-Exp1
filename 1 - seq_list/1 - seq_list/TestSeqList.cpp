#include "SeqList.h"	// 顺序表类

int n,num=1,numb;
double v[10000];
SeqList<double> *build[100];

void menu()
{
    cout << "菜单：" << endl << "1:构造空顺序表" << '\t' << '\t' << "2:根据数组内容构造顺序表" << '\t';
	cout << "3:删除顺序表" << endl << "4:获取顺序表长度" << '\t';
	cout << "5:判断顺序表是否为空" << '\t' << '\t' << "6:清空顺序表" << endl;
	cout << "7:访问顺序表各个元素" << '\t' << "8:定位元素" << '\t' << '\t' << '\t';
	cout << "9:取顺序表中第i个元素" << endl << "10:修改顺序表中第i个元素的值" << '\t' << '\t';
	cout << "11:删除顺序表中第i个元素" << endl << "12:在顺序表第i个位置插入元素" << '\t' << '\t';
	cout << "13:在顺序表表尾插入元素" << endl << "14:查找最大值的位置" << '\t' << '\t' << '\t';
	cout << "15:查找最小值的位置" << endl << "16:排序并插入新元素" << '\t' << '\t' << '\t';
	cout << "17:删除指定大小范围内的元素" << endl << "18:按顺序合并两个顺序表" << '\t' << '\t' << '\t' << "退出请按0" << endl;
}

int main(void)
{
    menu();
	int option,size;
	while(cin >> option)
	{
		if(option == 0) break;
		if(option == 1)
		{
			cout << "您选择了构造空顺序表,请输入大小: ";
			cin >> size;
			build[num] = new SeqList<double>(size);
			cout << "构造完成，顺序表序号为：" << num << endl;
			num++;
		}
		if(option == 2)
		{
			cout << "您选择了根据数组内容构造顺序表,请设置数组大小: ";
			cin >> n;
			cout << "请设置大小上限:";
			cin >> size;
			cout << "请输入元素" << endl;
			for(int i = 0; i < n; i++)
			{
				cin >> v[i];
			}
			build[num] = new SeqList<double>(v,n,size);
			cout << "构造完成，顺序表序号为：" << num << endl;
			num++;
		}
		if(option == 3)
		{
			cout << "您选择了删除顺序表,请输入您想要删除第几个顺序表: " << endl;
			cin >> numb; 
			build[numb]->~SeqList();
			cout << "删除成功" << endl;
		}
		if(option == 4)
		{
			int length;
			cout << "您选择了获取顺序表长度,请输入您想要获取第几个顺序表:" << endl;
			cin >> numb;
			length = build[numb]->GetLength();
			cout << "长度为:" << length << endl;
		}
		if(option == 5)
		{
			cout << "您选择了判断顺序表是否为空,请输入您想要判断第几个顺序表:" << endl;
			cin >> numb;
			if(build[numb]->IsEmpty())
			{
				cout << "当前顺序表为空";
			}else
			{
				cout << "当前顺序表非空";
			}
			cout << endl;
		}
		if(option == 6)
		{
			cout << "您选择了清空顺序表,请输入您想要删除第几个顺序表: " << endl;
			cin >> numb;
			build[numb]->Clear();
			cout << "清空完成" << endl; 
		} 
		if(option == 7)
		{
			cout << "您选择了访问顺序表各个元素,请输入您想要访问第几个顺序表: " << endl;
			cin >> numb;
			if(!build[numb]->GetLength())
			{
				cout << "这是空顺序表";
			}else
			{
				build[numb]->Traverse(Write);
			}
			cout << endl;
		}
		if(option == 8)
		{
			cout << "您选择了定位元素,请输入您想要使用第几个顺序表: ";
			cin >> numb;
			cout << "请输入您想要查找的元素值: " << endl;
			double e;
			cin >> e;
			int locate = build[numb]->LocateElem(e);
			if(locate)
			{
				cout << "位置为：" << locate << endl;
			}else
			{
				cout << "不存在" << endl;
			} 
		} 
		if(option == 9)
		{
			cout << "您选择了取顺序表中的元素，请输入您想要使用的顺序表：";
			cin >> numb;
			cout << "请输入您想要取的元素位置: ";
			int locate;
			double e = 0;
			cin >> locate;
			if(build[numb]->GetElem(locate, e) == NOT_PRESENT)
			{
				cout << "不存在";
			}else
			{
				cout << "该位置的元素值为: " << e;
			}
			cout << endl;
		}
		if(option == 10)
		{
			cout << "您选择了修改顺序表中第i个元素的值，请输入您想要使用的顺序表：";
			cin >> numb;
			cout << "请输入您想要修改的位置: ";
			int locate;
			cin >> locate;
			cout << "您想要修改成:";
			double e;
			cin >> e;
			build[numb]->SetElem(locate, e); 
			cout << "修改完成" << endl;
		}
		if(option == 11)
		{
			cout << "您选择了删除顺序表中指定位置的元素，请输入您要使用的顺序表: ";
			cin >> numb;
			double temp = 0;
			int locate;
			cout << "请输入指定位置: ";
			cin >> locate;
			if(build[numb]->DeleteElem(locate, temp) == RANGE_ERROR)
			{
				cout << "位置错误" << endl; 
			}else
			{
				cout << "删除成功，删除的为：" << temp;
			}
		}
		if(option == 12)
		{
			cout << "您选择了在顺序表指定位置插入元素，请输入您想要使用的顺序表：";
			cin >> numb;
			cout << "请输入元素：";
			double e;
			cin >> e;
			int locate;
			cout << "请输入位置：";
			cin >> locate;
			if(build[numb]->InsertElem(locate,e) == OVER_FLOW || build[numb]->InsertElem(locate,e) == RANGE_ERROR)
			{
				cout << "插入失败";
			}else
			{
				cout << "插入完成";
			}
			cout << endl;
		}
		if(option == 13)
		{
			cout << "您选择了在顺序表表尾插入元素，请输入您想要使用的顺序表：";
			cin >> numb;
			cout << "请输入元素：";
			double e;
			cin >> e;
			if(build[numb]->InsertElem(e) == OVER_FLOW)
			{
				cout << "插入失败";
			}else
			{
				cout << "插入完成";
			}
		}
		if(option == 14)
		{
			cout << "您选择了查找顺序表元素最大值，请输入您想要使用的顺序表：";
			cin >> numb;
			build[numb]->max();
		}
		if(option == 15)
		{
			cout << "您选择了查找顺序表元素最小值，请输入您想要使用的顺序表：";
			cin >> numb;
			build[numb]->min();
		}
		if(option == 16) 
		{
			cout << "请输入您想要使用的顺序表：";
			cin >> numb;
			double e;
			cout << "请输入您想要插入的值" << endl; 
			cin >> e;
			if(OVER_FLOW == build[numb]->InsertNew(e))
			{
				cout << "当前不可插入元素" << endl; 
			}else
			{
				cout << "插入成功" << endl;
			}
		}
		if(option == 17)
		{
			double s,t;
			cout << "请输入您想要使用的链表:";
			cin >> numb;
			if(!build[numb]->GetLength()) 
			{
				cout << "该顺序表为空" << endl; 
				break;
			}
			cout << "请输入删除范围,小的在前，大的在后:";
			cin >> s >> t;
			build[numb]->deleteRange(s,t);
			cout << "该顺序表现在元素为:";
			build[numb]->Traverse(Write);
			cout << endl;
		 } 
		if(option == 18)
		{
			int a,b;
			cout << "请输入您想要合并的两个顺序表: ";
			cin >> a >> b;
			build[num] = new SeqList<double>();
			build[num]->merge(build[a],build[b]);
			cout << "合并完成，该顺序表为第" << num << "个顺序表，元素为: ";
			build[num]->Traverse(Write);
			cout << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
		menu();
	}
   	return 0;               		// 返回操作系统
}


