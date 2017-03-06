#include <bits/stdc++.h>
using namespace std;

long long int dp[505][505];

long long int call(int last_col, int rem){

    if(rem == 0)return 1;
    if(last_col >= rem)return 0;

    if(dp[last_col][rem] != -1)return dp[last_col][rem];

    long long int ret=0;
    for(int i = last_col +1; i <= rem; i++)ret = ret + call(i, rem-i);

    return dp[last_col][rem] = ret;
}

int main(){
    int n;
    memset(dp, -1, sizeof(dp));

    while(scanf("%d", &n)!=EOF){

        printf("%lld\n", call(0, n) -1);
    }
    return 0;
}
