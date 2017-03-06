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

int main(){

long long int ar[200][200],dp[200][200];

    int test;
    cin >> test;

    for(int i=1; i <= test; i++){
        int p=1,n;
        cin >> n;

        memset(dp, -1, sizeof(dp));

        for(int j=0; j < n; j++){
            for(int k=0; k < p; k++){

                inp(ar[j][k]);

                if(j==0 && k==0)dp[j][k] = ar[j][k];
                else if(k==0){dp[j][k] = ar[j][k] + dp[j-1][k];}
                else {
                    dp[j][k] = ar[j][k] + max(dp[j-1][k], dp[j-1][k-1]);
                }
            }
            p++;
        }

        p=(n-1);
        for(int j=n; j <= (2*n)-1 ; j++){
            for(int k=0; k < p; k++){
                inp(ar[j][k]);

                dp[j][k] = ar[j][k] + max(dp[j-1][k], dp[j-1][k+1]);
            }
            p--;
        }
        printf("Case %d: %d\n",i, dp[(2*n) -2][0]);
    }

    return 0;
}
