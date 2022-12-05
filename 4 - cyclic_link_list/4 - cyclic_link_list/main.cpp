#include "LinkList.h"
LinkList<int> L;

int main()
{
    while (1)
    {
        int n;
        cout<<"三、不带头节点的单循环链表类模板："<<endl;
        cout<<"1.求单链表长度"<<endl<<"2.判断单链表是否为空"<<endl;
        cout<<"3.将单链表清空"<<endl<<"4.遍历单链表并输入所有元素"<<endl;
        cout<<"5.元素定位，求指定元素在顺序表中的位置"<<endl;
        cout<<"6.求指定位置的元素"<<endl<<"7.设置指定位置的元素值"<<endl;
        cout<<"8.删除单链表的第i个位置的元素"<<endl<<"9.在指定位置插入元素"<<endl;
        cout<<"10.在单链表的表尾位置插入元素"<<endl<<"11.将链表中元素结点进行逆置"<<endl;
        cout<<"0.退出"<<endl;
        cin>>n;
        switch (n)
        {
            case 1:
            {
                //求单链表长度
                cout<<"目前单链表的长度为："<<L.GetLength()<<endl;
                break;
            }
            case 2:
            {
                //判断单链表是否为空
                if (L.IsEmpty())
                    cout<<"目前顺序表为空"<<endl;
                else
                    cout<<"目前单链表不为空"<<endl;
                break;
            }
            case 3:
            {
                //将单链表清空
                L.Clear();
                cout<<"单链表已清空"<<endl;
                break;
            }
            case 4:
            {
                //遍历单链表并输入所有元素
                L.Traverse(Write);
                break;
            }
            case 5:
            {
                //元素定位，求指定元素在顺序表中的位置
                int location;
                int result;
                cout<<"请输入想要查找的元素："<<endl;
                cin>>location;
                result=L.LocateElem(location);
                if (result==0)
                    cout<<"顺序表中不存在元素"<<endl;
                else
                    cout<<location<<"在顺序表中的序号为："<<result<<endl;
                break;
            }
            case 6:
            {
                //求指定位置的元素
                int location;
                int Data;
                Status result;
                cout<<"请输入想要查找的元素序号i："<<endl;
                cin>>location;
                result=L.GetElem(location,Data);
                if (result==RANGE_ERROR)
                    cout<<"不存在序号为"<<location<<"的元素"<<endl;
                else
                    cout<<"序号为"<<location<<"的元素为"<<Data<<endl;
                break;
            }
            case 7:
            {
                //设置指定位置的元素值
                int location;
                int Data;
                Status result;
                cout<<"请输入想要设置元素的序号位置："<<endl;
                cin>>location;
                cout<<"请输入想要设置为的元素："<<endl;
                cin>>Data;
                result=L.SetElem(location,Data);
                if(result==RANGE_ERROR)
                    cout<<"序号输入有误，设置失败"<<endl;
                else
                    cout<<"已设置成功在序号为"<<location<<"元素为"<<Data<<endl;
                break;
            }
            case 8:
            {
                //删除单链表的第i个位置的元素
                int location;
                int Data;
                cout<<"请输入想要删除的位置序号："<<endl;
                cin>>location;
                Status result;
                result =L.DeleteElem(location,Data);
                if (result==RANGE_ERROR)
                    cout<<"序号输入有误，设置失败"<<endl;
                else
                    cout<<"已经删除序号为"<<location<<"的元素："<<Data<<endl;
                break;
            }
            case 9:
            {
                //在指定位置插入元素
                int location;
                int Data;
                Status result;
                cout<<"请输入想要插入元素的序号位置i："<<endl;
                cin>>location;
                cout<<"请输入想要插入元素："<<endl;
                cin>>Data;
                result=L.InsertElem(location,Data);
                if (result==RANGE_ERROR)
                    cout<<"输入的i范围错误，插入失败。"<<endl;
                else
                    cout<<"插入成功。"<<endl;
                break;
            }
            case 10:
            {
                //在单链表的表尾位置插入元素e
                int Data;
                Status result;
                cout<<"请输入想要插入的元素："<<endl;
                cin>>Data;
                result=L.InsertElem(Data);
                if (result==SUCCESS)
                    cout<<"插入成功"<<endl;
                break;
            }
            case 11:
            {
                //将链表中元素结点进行逆置
                cout<<"逆置前的链表为："<<endl;
                L.Traverse(Write);
                L.reversal();
                cout<<"逆置后的链表为："<<endl;
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
