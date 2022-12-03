#include "LinkList.h"

Student v[100];
LinkList *build[100];
int num = 1;
int numb,size;

void menu()
{
	cout << "�˵���" << endl << "1:���������" << '\t' << '\t' << "2:�����������ݹ�������" << '\t';
	cout << "3:ɾ������" << endl << "4:��ȡ������\t\t";
	cout << "5:�ж������Ƿ�Ϊ��" << '\t' << "6:�������" << endl;
	cout << "7:���������и���ѧ������" << '\t' << "8:��λԪ��" << '\t' << '\t' << '\t';
	cout << "9:ȡ�����е�i��Ԫ��" << endl << "10:�޸������е�i��Ԫ�ص�ֵ" << '\t' << '\t';
	cout << "11:ɾ�������е�i��Ԫ��" << endl << "12:�������i��λ�ò���Ԫ��" << '\t' << '\t';
	cout << "13:�������β����Ԫ��" << endl << "14:���򲢲�����Ԫ��" << '\t' << '\t' << '\t';
	cout << "15:��˳��ϲ���������" << endl << "16����������\t\t\t\t" << "0���˳�" << endl;
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
			cout << "������ɣ��������Ϊ��" << num << endl;
			num++; 
			menu();
		}
		if(option == 2)
		{
			cout << "���������ݸ���:";
			int n;
			cin >> n;
			for(int i = 0; i < n; i++)
			{
				cout << "������ѧ��������";
				cin >> v[i].name;
				cout << "������ѧ���Ա�";
				cin >> v[i].sex;
				cout << "������ѧ��ѧ�ţ�";
				cin >> v[i].id;
				cout << "������ѧ���༶��";
				cin >> v[i].Class;
				cout << "������ѧ���绰���룺";
				cin >> v[i].phone;
				cout << endl; 
			}
			build[num] = new LinkList(v, n);
			cout << "������ɣ��������Ϊ��" << num << endl;
			num++;
			menu();
		}
		if (option == 3)
		{
			cout << "����������Ҫɾ����������ţ�";
			cin >> numb;
			build[numb]->~LinkList();
			menu();
		}
		if (option == 4)
		{
			cout << "����������Ҫ��ȡ���ȵ�������ţ�";
			cin >> numb;
			cout << build[numb]->GetLength() << endl;
			menu();
		}
		if (option == 5)
		{
			cout << "����������Ҫ�жϵ�������ţ�";
			cin >> numb;
			if (build[numb]->IsEmpty())
			{
				cout << "������Ϊ��";
			}else{
				cout << "������ǿ�";
			}
			cout << endl;
			menu();
		}
		if (option == 6)
		{
			cout << "����������Ҫ��յ�������ţ�";
			cin >> numb;
			cout << build[numb]->GetLength() << endl;
			menu();
		}
		if(option == 7)
		{
			cout << "����������Ҫ����������:";
			cin >> numb;
			build[numb]->Traverse(Write);
			cout << endl;
			menu();
		}
		if (option == 8)
		{
			cout << "����������Ҫ���ҵ�����:";
			cin >> numb;
			cout << "����������Ҫ���ҵ�ѧ��ѧ�ţ�";
			int e;
			cin >> e;
			build[numb]->LocateElem(e);
			cout << endl;
			menu();
		}
		if (option == 9)
		{
			cout << "����������Ҫʹ�õ�����:";
			cin >> numb;
			cout << "������Ԫ�ص�λ��";
			int e;
			cin >> e;
			build[numb]->GetElem(e);
			cout << endl;
			menu();
		}
		if (option == 10)
		{
			cout << "����������Ҫʹ�õ�����:";
			cin >> numb;
			cout << "����������Ҫ�޸ĵ�Ԫ��λ��";
			int e;
			cin >> e;
			Student p;
			cout << "������ѧ������";
			cin >> p.name;
			cout << "������ѧ���Ա�";
			cin >> p.sex;
			cout << "������ѧ��ѧ��";
			cin >> p.id;
			cout << "������ѧ���༶";
			cin >> p.Class;
			cout << "������ѧ���绰";
			cin >> p.phone;
			build[numb]->SetElem(e, p);
			cout << endl;
			menu();
		}
		if (option == 11)
		{
			cout << "����������Ҫʹ�õ�����:";
			cin >> numb;
			cout << "����������Ҫɾ����Ԫ��λ��";
			int e;
			cin >> e;
			if(build[numb]->DeleteElem(e) == SUCCESS)
			{
				cout << "ɾ���ɹ�";
			}else
			{
				cout << "ʧ��";
			}
			cout << endl;
			menu();
		}
		if (option == 12)
		{
			cout << "����������Ҫʹ�õ�����:";
			cin >> numb;
			cout << "����������Ҫ�����Ԫ��λ��";
			int e;
			cin >> e;
			Student p;
			cout << "������ѧ������";
			cin >> p.name;
			cout << "������ѧ���Ա�";
			cin >> p.sex;
			cout << "������ѧ��ѧ��";
			cin >> p.id;
			cout << "������ѧ���༶";
			cin >> p.Class;
			cout << "������ѧ���绰";
			cin >> p.phone;
			if (build[numb]->InsertElem(e,p) == SUCCESS)
			{
				cout << "����ɹ�";
			}
			else
			{
				cout << "ʧ��";
			}
			cout << endl;
			menu();
		}
		if (option == 13)
		{
			cout << "����������Ҫʹ�õ�����:";
			cin >> numb;
			Student p;
			cout << "������ѧ������";
			cin >> p.name;
			cout << "������ѧ���Ա�";
			cin >> p.sex;
			cout << "������ѧ��ѧ��";
			cin >> p.id;
			cout << "������ѧ���༶";
			cin >> p.Class;
			cout << "������ѧ���绰";
			cin >> p.phone;
			if (build[numb]->InsertElem(p) == SUCCESS)
			{
				cout << "ɾ���ɹ�";
			}
			else
			{
				cout << "ʧ��";
			}
			cout << endl;
			menu();
		}
		if (option == 14)
		{
			Student *e;
			e = new Student;
			cout << "������ѧ��������";
			cin >> e->name;
			cout << "������ѧ���Ա�";
			cin >> e->sex;
			cout << "������ѧ��ѧ�ţ�";
			cin >> e->id;
			cout << "������ѧ���༶��";
			cin >> e->Class;
			cout << "������ѧ���绰���룺";
			cin >> e->phone;
			cout << "������������ţ�";
			cin >> numb;
			build[numb]->SortInsert(e);
			cout << endl;
			menu();
		}
		if (option == 15)
		{
			cout << "������Ҫ�ϲ��������������:";
			int a, b;
			cin >> a >> b;
			build[num] = new LinkList();
			build[num]->Merge(build[a], build[b]);
			num++;
			menu();
		}
		if (option == 16)
		{
			cout << "������������ţ�";
			cin >> numb;
			build[numb]->Reversal();
			cout << endl;
			menu();
		}
		if (option == 0) break;
	}

	return 0;               // ����ֵ0, ���ز���ϵͳ
}
