#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int price[1005],weight[1005],profit[1005][35];
int max_weight,item;

int np_scak(int i, int w)
{
    if(i > item )return 0;

    int &a = profit[i][w];

    if(a !=-1)return a;

    else
    {
        int pro1,pro2;

        pro2=np_scak(i+1, w);

        if(w+weight[i] <= max_weight)pro1=price[i] + np_scak(i+1, w+weight[i]);
        else pro1=0;

        int val= max(pro1, pro2);

        a=val;
        return val;
    }
}

int main()
{
    int test=read();

    for(int i=0; i < test; i++)
    {
        item=read();
        int total=0;

        for(int j=1; j<=item; j++)
        {
            price[j]=read();
            weight[j]=read();
        }

        int person_num=read();


        for(int j=0; j<person_num; j++)
        {
            max_weight=read();

            memset(profit, -1, sizeof(profit));

            int val = np_scak(1, 0);

            total+=val;
        }
        printf("%d\n", total);
    }
    return 0;
}
