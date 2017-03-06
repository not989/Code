#include <bits/stdc++.h>
using namespace std;

inline long long int read()
{
    long long int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

long long int a, b, c, d, e, f;
long long int ar[100010];

long long int fn(long long int n )
{

    if( n == 0 ) return a;
    else if( n == 1 ) return b;
    else if( n == 2 ) return c;
    else if( n == 3 ) return d;
    else if( n == 4 ) return e;
    else if( n == 5 ) return f;

    if(ar[n]!=-1)return ar[n];

    else ar[n]=( fn(n-1) + fn(n-2) + fn(n-3)+ fn(n-4) + fn(n-5) + fn(n-6) )% 10000007;

    return ar[n];

}
int main()
{
    long long int n, caseno = 0, cases;

    cases=read();

    while( cases-- )
    {
        memset(ar, -1, sizeof(ar));

        a=read();
        b=read();
        c=read();
        d=read();
        e=read();
        f=read();
        n=read();

        long long int num = fn(n) ;
        num = num % 10000007;
        printf("Case %lld: %lld\n", ++caseno, num);

    }
    return 0;
}
