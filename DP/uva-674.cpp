#include <bits/stdc++.h>
using namespace std;

/*inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
*/
int dp[6][7500],coin[]={1,5,10,25,50};
int value;

int exchange(int i, int amount)
{

    if(i > 4)
    {
        if(amount == 0)return 1;
        else return 0;
    }

    if(dp[i][amount]!= -1)return dp[i][amount];

    int ret1=0,ret2=0;

    if(amount-coin[i] >= 0)ret1=exchange(i, amount-coin[i]);

    ret2=exchange(i+1, amount);

    dp[i][amount]=ret1+ret2;

    return dp[i][amount];
}

int main()
{
    memset(dp, -1 , sizeof(dp));
    while(cin >>value)
    {
        if(value==0)
        {
            dp[0][0]=1;
            cout << "1" << endl;
        }
        else cout << exchange(0, value) << endl;
    }
    return 0;
}

