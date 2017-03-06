#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

inline void inp(long long int  &n )//fast input function
{
        n=0;
        int ch=getchar();int sign=1;
        while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}

        while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
        n=n*sign;
}

unsigned long long int dp[25][10010];
unsigned long long int coin[30];

unsigned long long int call(long long int  i,long long int amount){

    unsigned long long int ret1,ret2;

    if(i >= 21){
        if(amount == 0)return 1;
        else return 0;
    }

    else if(dp[i][amount] != -1)return dp[i][amount];

    if(amount >= coin[i]){
            ret1 = call(i, amount - coin[i]);
            ret2 = call(i+1, amount);
    }
    else {
        if(amount == 0)return 1;
        else return 0;
    }

    return dp[i][amount] = ret1 + ret2;
}

int main(){

    unsigned long long int make,i=1,ans;
    for(long long int j=0; j < 21; i++,j++){
        coin[j] = (i*i*i);
    }

    memset(dp, -1, sizeof(dp));

    while(scanf("%llu", &make)==1){
        ans = call(0, make);
        printf("%llu\n", ans);
    }

    return 0;
}
