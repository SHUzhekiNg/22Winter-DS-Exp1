#include "List.h"

int main() {
    int n,a,b,count = 0;
    cout << "�������������";
    cin >> n;
    cout << "�����ȡ������ʽ��";
    cin >> a;
    cout << "������ȡ������ʽ��";
    cin >> b;
    LinkList<int> list(n);
    while (!list.AllTrue()){
        auto * x = list.VisitElemX(a);
        auto * y =list.VisitElemY(b);
        if (x == y) {
            list.Visited(x);
            PrintFormat(list,count);
        }
        else {
            list.Visited(x);
            PrintFormat(list,count);
            list.Visited(y);
            PrintFormat(list,count);
        }

    }
    cout<<"��"<<endl;
    return 0;
}
