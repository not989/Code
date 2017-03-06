#include <bits/stdc++.h>
using namespace std;

long long int dp[100][1010];
long long  int coin_num[100];
long long  int coin_val[100];
long long int num, make;

long long int call (long long int i,  long long int amount_remain){
    long long int sum=0;

    if(amount_remain ==0)return 1;

    if(i > num)return 0;

    else if(dp[i][amount_remain] != -1)return dp[i][amount_remain];


    for(int j=0;j <= coin_num[i] && (amount_remain - (j * coin_val[i]))>=0 ; j++){
        sum+= call(i+1, (amount_remain - (j * coin_val[i])));
        sum=sum % 100000007;
    }
    return dp[i][amount_remain] = sum;
}

int main(){
    int test;

    cin  >> test;

    for(int k=1; k <= test; k++){
        cin >> num >> make;

        for(int i=1; i <= num; i++)cin >>  coin_val[i];
        for(int i=1; i <= num; i++)cin >> coin_num[i];

        memset(dp, -1, sizeof(dp) );

        cout << "Case " << k << ": "<< call(1, make) << endl;
    }
    return 0;
}
