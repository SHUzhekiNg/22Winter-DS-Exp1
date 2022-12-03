#include "SeqList.h"	// ˳�����

int n,num=1,numb;
double v[10000];
SeqList<double> *build[100];

void menu()
{
    cout << "�˵���" << endl << "1:�����˳���" << '\t' << '\t' << "2:�����������ݹ���˳���" << '\t';
	cout << "3:ɾ��˳���" << endl << "4:��ȡ˳�����" << '\t';
	cout << "5:�ж�˳����Ƿ�Ϊ��" << '\t' << '\t' << "6:���˳���" << endl;
	cout << "7:����˳������Ԫ��" << '\t' << "8:��λԪ��" << '\t' << '\t' << '\t';
	cout << "9:ȡ˳����е�i��Ԫ��" << endl << "10:�޸�˳����е�i��Ԫ�ص�ֵ" << '\t' << '\t';
	cout << "11:ɾ��˳����е�i��Ԫ��" << endl << "12:��˳����i��λ�ò���Ԫ��" << '\t' << '\t';
	cout << "13:��˳����β����Ԫ��" << endl << "14:�������ֵ��λ��" << '\t' << '\t' << '\t';
	cout << "15:������Сֵ��λ��" << endl << "16:���򲢲�����Ԫ��" << '\t' << '\t' << '\t';
	cout << "17:ɾ��ָ����С��Χ�ڵ�Ԫ��" << endl << "18:��˳��ϲ�����˳���" << '\t' << '\t' << '\t' << "�˳��밴0" << endl;
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
			cout << "��ѡ���˹����˳���,�������С: ";
			cin >> size;
			build[num] = new SeqList<double>(size);
			cout << "������ɣ�˳������Ϊ��" << num << endl;
			num++;
		}
		if(option == 2)
		{
			cout << "��ѡ���˸����������ݹ���˳���,�����������С: ";
			cin >> n;
			cout << "�����ô�С����:";
			cin >> size;
			cout << "������Ԫ��" << endl;
			for(int i = 0; i < n; i++)
			{
				cin >> v[i];
			}
			build[num] = new SeqList<double>(v,n,size);
			cout << "������ɣ�˳������Ϊ��" << num << endl;
			num++;
		}
		if(option == 3)
		{
			cout << "��ѡ����ɾ��˳���,����������Ҫɾ���ڼ���˳���: " << endl;
			cin >> numb; 
			build[numb]->~SeqList();
			cout << "ɾ���ɹ�" << endl;
		}
		if(option == 4)
		{
			int length;
			cout << "��ѡ���˻�ȡ˳�����,����������Ҫ��ȡ�ڼ���˳���:" << endl;
			cin >> numb;
			length = build[numb]->GetLength();
			cout << "����Ϊ:" << length << endl;
		}
		if(option == 5)
		{
			cout << "��ѡ�����ж�˳����Ƿ�Ϊ��,����������Ҫ�жϵڼ���˳���:" << endl;
			cin >> numb;
			if(build[numb]->IsEmpty())
			{
				cout << "��ǰ˳���Ϊ��";
			}else
			{
				cout << "��ǰ˳���ǿ�";
			}
			cout << endl;
		}
		if(option == 6)
		{
			cout << "��ѡ�������˳���,����������Ҫɾ���ڼ���˳���: " << endl;
			cin >> numb;
			build[numb]->Clear();
			cout << "������" << endl; 
		} 
		if(option == 7)
		{
			cout << "��ѡ���˷���˳������Ԫ��,����������Ҫ���ʵڼ���˳���: " << endl;
			cin >> numb;
			if(!build[numb]->GetLength())
			{
				cout << "���ǿ�˳���";
			}else
			{
				build[numb]->Traverse(Write);
			}
			cout << endl;
		}
		if(option == 8)
		{
			cout << "��ѡ���˶�λԪ��,����������Ҫʹ�õڼ���˳���: ";
			cin >> numb;
			cout << "����������Ҫ���ҵ�Ԫ��ֵ: " << endl;
			double e;
			cin >> e;
			int locate = build[numb]->LocateElem(e);
			if(locate)
			{
				cout << "λ��Ϊ��" << locate << endl;
			}else
			{
				cout << "������" << endl;
			} 
		} 
		if(option == 9)
		{
			cout << "��ѡ����ȡ˳����е�Ԫ�أ�����������Ҫʹ�õ�˳���";
			cin >> numb;
			cout << "����������Ҫȡ��Ԫ��λ��: ";
			int locate;
			double e = 0;
			cin >> locate;
			if(build[numb]->GetElem(locate, e) == NOT_PRESENT)
			{
				cout << "������";
			}else
			{
				cout << "��λ�õ�Ԫ��ֵΪ: " << e;
			}
			cout << endl;
		}
		if(option == 10)
		{
			cout << "��ѡ�����޸�˳����е�i��Ԫ�ص�ֵ������������Ҫʹ�õ�˳���";
			cin >> numb;
			cout << "����������Ҫ�޸ĵ�λ��: ";
			int locate;
			cin >> locate;
			cout << "����Ҫ�޸ĳ�:";
			double e;
			cin >> e;
			build[numb]->SetElem(locate, e); 
			cout << "�޸����" << endl;
		}
		if(option == 11)
		{
			cout << "��ѡ����ɾ��˳�����ָ��λ�õ�Ԫ�أ���������Ҫʹ�õ�˳���: ";
			cin >> numb;
			double temp = 0;
			int locate;
			cout << "������ָ��λ��: ";
			cin >> locate;
			if(build[numb]->DeleteElem(locate, temp) == RANGE_ERROR)
			{
				cout << "λ�ô���" << endl; 
			}else
			{
				cout << "ɾ���ɹ���ɾ����Ϊ��" << temp;
			}
		}
		if(option == 12)
		{
			cout << "��ѡ������˳���ָ��λ�ò���Ԫ�أ�����������Ҫʹ�õ�˳���";
			cin >> numb;
			cout << "������Ԫ�أ�";
			double e;
			cin >> e;
			int locate;
			cout << "������λ�ã�";
			cin >> locate;
			if(build[numb]->InsertElem(locate,e) == OVER_FLOW || build[numb]->InsertElem(locate,e) == RANGE_ERROR)
			{
				cout << "����ʧ��";
			}else
			{
				cout << "�������";
			}
			cout << endl;
		}
		if(option == 13)
		{
			cout << "��ѡ������˳����β����Ԫ�أ�����������Ҫʹ�õ�˳���";
			cin >> numb;
			cout << "������Ԫ�أ�";
			double e;
			cin >> e;
			if(build[numb]->InsertElem(e) == OVER_FLOW)
			{
				cout << "����ʧ��";
			}else
			{
				cout << "�������";
			}
		}
		if(option == 14)
		{
			cout << "��ѡ���˲���˳���Ԫ�����ֵ������������Ҫʹ�õ�˳���";
			cin >> numb;
			build[numb]->max();
		}
		if(option == 15)
		{
			cout << "��ѡ���˲���˳���Ԫ����Сֵ������������Ҫʹ�õ�˳���";
			cin >> numb;
			build[numb]->min();
		}
		if(option == 16) 
		{
			cout << "����������Ҫʹ�õ�˳���";
			cin >> numb;
			double e;
			cout << "����������Ҫ�����ֵ" << endl; 
			cin >> e;
			if(OVER_FLOW == build[numb]->InsertNew(e))
			{
				cout << "��ǰ���ɲ���Ԫ��" << endl; 
			}else
			{
				cout << "����ɹ�" << endl;
			}
		}
		if(option == 17)
		{
			double s,t;
			cout << "����������Ҫʹ�õ�����:";
			cin >> numb;
			if(!build[numb]->GetLength()) 
			{
				cout << "��˳���Ϊ��" << endl; 
				break;
			}
			cout << "������ɾ����Χ,С����ǰ������ں�:";
			cin >> s >> t;
			build[numb]->deleteRange(s,t);
			cout << "��˳�������Ԫ��Ϊ:";
			build[numb]->Traverse(Write);
			cout << endl;
		 } 
		if(option == 18)
		{
			int a,b;
			cout << "����������Ҫ�ϲ�������˳���: ";
			cin >> a >> b;
			build[num] = new SeqList<double>();
			build[num]->merge(build[a],build[b]);
			cout << "�ϲ���ɣ���˳���Ϊ��" << num << "��˳���Ԫ��Ϊ: ";
			build[num]->Traverse(Write);
			cout << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
		menu();
	}
   	return 0;               		// ���ز���ϵͳ
}


