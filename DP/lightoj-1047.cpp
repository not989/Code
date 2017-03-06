#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    getchar();

    for(int i=1; i <= test; i++){
        int dp[20][3],a,b,c, n;

        scanf("%d", &n);

        for(int j=0; j < n ; j++){

            scanf("%d %d %d", &a, &b, &c);

            if(j==0){
                dp[0][0] = a;
                dp[0][1] = b;
                dp[0][2] = c;
            }
            else {
                dp[j][0] =a + min(dp[j-1][1], dp[j-1][2]);
                dp[j][1] = b + min(dp[j-1][0], dp[j-1][2]);
                dp[j][2] = c + min(dp[j-1][1], dp[j-1][0]);
            }
        }
        sort (dp[n-1], dp[n-1]+3);
        printf("Case %d: %d\n", i, dp[n-1][0]);
    }
    return 0;
}
