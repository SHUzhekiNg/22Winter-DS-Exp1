#include "LinkList.h"
LinkList<int> L;

int main()
{
    while (1)
    {
        int n;
        cout<<"��������ͷ�ڵ�ĵ�ѭ��������ģ�壺"<<endl;
        cout<<"1.��������"<<endl<<"2.�жϵ������Ƿ�Ϊ��"<<endl;
        cout<<"3.�����������"<<endl<<"4.������������������Ԫ��"<<endl;
        cout<<"5.Ԫ�ض�λ����ָ��Ԫ����˳����е�λ��"<<endl;
        cout<<"6.��ָ��λ�õ�Ԫ��"<<endl<<"7.����ָ��λ�õ�Ԫ��ֵ"<<endl;
        cout<<"8.ɾ��������ĵ�i��λ�õ�Ԫ��"<<endl<<"9.��ָ��λ�ò���Ԫ��"<<endl;
        cout<<"10.�ڵ�����ı�βλ�ò���Ԫ��"<<endl<<"11.��������Ԫ�ؽ���������"<<endl;
        cout<<"0.�˳�"<<endl;
        cin>>n;
        switch (n)
        {
            case 1:
            {
                //��������
                cout<<"Ŀǰ������ĳ���Ϊ��"<<L.GetLength()<<endl;
                break;
            }
            case 2:
            {
                //�жϵ������Ƿ�Ϊ��
                if (L.IsEmpty())
                    cout<<"Ŀǰ˳���Ϊ��"<<endl;
                else
                    cout<<"Ŀǰ������Ϊ��"<<endl;
                break;
            }
            case 3:
            {
                //�����������
                L.Clear();
                cout<<"�����������"<<endl;
                break;
            }
            case 4:
            {
                //������������������Ԫ��
                L.Traverse(Write);
                break;
            }
            case 5:
            {
                //Ԫ�ض�λ����ָ��Ԫ����˳����е�λ��
                int location;
                int result;
                cout<<"��������Ҫ���ҵ�Ԫ�أ�"<<endl;
                cin>>location;
                result=L.LocateElem(location);
                if (result==0)
                    cout<<"˳����в�����Ԫ��"<<endl;
                else
                    cout<<location<<"��˳����е����Ϊ��"<<result<<endl;
                break;
            }
            case 6:
            {
                //��ָ��λ�õ�Ԫ��
                int location;
                int Data;
                Status result;
                cout<<"��������Ҫ���ҵ�Ԫ�����i��"<<endl;
                cin>>location;
                result=L.GetElem(location,Data);
                if (result==RANGE_ERROR)
                    cout<<"���������Ϊ"<<location<<"��Ԫ��"<<endl;
                else
                    cout<<"���Ϊ"<<location<<"��Ԫ��Ϊ"<<Data<<endl;
                break;
            }
            case 7:
            {
                //����ָ��λ�õ�Ԫ��ֵ
                int location;
                int Data;
                Status result;
                cout<<"��������Ҫ����Ԫ�ص����λ�ã�"<<endl;
                cin>>location;
                cout<<"��������Ҫ����Ϊ��Ԫ�أ�"<<endl;
                cin>>Data;
                result=L.SetElem(location,Data);
                if(result==RANGE_ERROR)
                    cout<<"���������������ʧ��"<<endl;
                else
                    cout<<"�����óɹ������Ϊ"<<location<<"Ԫ��Ϊ"<<Data<<endl;
                break;
            }
            case 8:
            {
                //ɾ��������ĵ�i��λ�õ�Ԫ��
                int location;
                int Data;
                cout<<"��������Ҫɾ����λ����ţ�"<<endl;
                cin>>location;
                Status result;
                result =L.DeleteElem(location,Data);
                if (result==RANGE_ERROR)
                    cout<<"���������������ʧ��"<<endl;
                else
                    cout<<"�Ѿ�ɾ�����Ϊ"<<location<<"��Ԫ�أ�"<<Data<<endl;
                break;
            }
            case 9:
            {
                //��ָ��λ�ò���Ԫ��
                int location;
                int Data;
                Status result;
                cout<<"��������Ҫ����Ԫ�ص����λ��i��"<<endl;
                cin>>location;
                cout<<"��������Ҫ����Ԫ�أ�"<<endl;
                cin>>Data;
                result=L.InsertElem(location,Data);
                if (result==RANGE_ERROR)
                    cout<<"�����i��Χ���󣬲���ʧ�ܡ�"<<endl;
                else
                    cout<<"����ɹ���"<<endl;
                break;
            }
            case 10:
            {
                //�ڵ�����ı�βλ�ò���Ԫ��e
                int Data;
                Status result;
                cout<<"��������Ҫ�����Ԫ�أ�"<<endl;
                cin>>Data;
                result=L.InsertElem(Data);
                if (result==SUCCESS)
                    cout<<"����ɹ�"<<endl;
                break;
            }
            case 11:
            {
                //��������Ԫ�ؽ���������
                cout<<"����ǰ������Ϊ��"<<endl;
                L.Traverse(Write);
                L.reversal();
                cout<<"���ú������Ϊ��"<<endl;
                L.Traverse(Write);
                break;
            }
            case 0:
            {
                return 0;
            }
        }
    }
}
