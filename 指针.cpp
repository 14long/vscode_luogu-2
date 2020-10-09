#include <bits/stdc++.h>
using namespace std;
int s1[40];
int s2[5][10]={{1,2,2,2,2,2,2,2,2,2},
{3,3,3,3,3,3,3,3,3,3},
{2,2,2,2,2,2,2,2,2,3},
{5,5,5,5,5,5,5,5,5,5},
{9,9,9,9,9,9,9,9,9,9}
};
long long d1[10];
void ans(int a[],int v)
{
    for(int i=1;i<=v;i++)
    {
        cout<<(a[i])<<endl;
    }
}

void ans2(int *a1,int a2)
{
    for(int i=1;i<=a2;i++)
    {
        cout<<*(a1+i)<<endl;
    }
}
int main()
{
    s1[0]=1;
    cout<<s2[0][0]<<endl;
    for(int j=0;j<5;j++)
    {
        for(int i=0;i<10;i++)
        {
            cout<<s2[j][i]<<endl;
        }
    }
    long long *a2,*a3;
    a2=d1;
    a3=d1+1;
    *a2=30;*a3=100;
    cout<<*a2<<endl<<endl;
    int *a1;
    a1=s1;/////需要先定一数组位置
    *a1=1;
    printf("%p %d",a1,*a1);
    a1=s1;
    printf(" %p",a1);
    a1=a1+10;
    printf(" %p %ld",a1,a2-a3);//地址差值??

    cout<<s1[0]<<endl<<s1[3]<<endl<<s1[30]<<endl;

    int *d1=s2[4]+1;
    ans(s2[1],9);
    ans2(d1,9);
    //int *d2=s2;
    int* d4=s1;
    d4=s1+3;
    cout<<*d4<<endl;
    int* d2=(*(s2+1)+3);
    cout<<"\n\n\n";
    
    cout<<((s2+1)+1)<<endl;
    cout<<**((s2+1)+1)<<endl;
    cout<<*(*(s2+1)+4)<<endl;
    cout<<*(*(s2+3)+2)<<endl;
    cout<<(*(s2+3)+2)<<endl;
    cout<<"\n\n\n\n";

    //指向指针的指针
    int** p1;
    *p1=d2;
    cout<<**p1<<endl;
    cout<<*d2<<endl;
    int* p2;
    *p2=144;
    cout<<*p2<<endl;
    p2=(*(s2+2)+1);
    cout<<*p2<<endl;
    *p1=p2;
    if(**p1==*p2) cout<<"true"<<endl;

    *p2=10;
    cout<<*p2<<endl;
    
    cout<<endl;
    cout<<*d2<<endl;
    cout<<*(*(s2+3)+9)<<endl;
    cout<<**s2<<endl;
    return 0;
}
