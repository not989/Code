#include <bits/stdc++.h>
using namespace std;

inline void inp( int &n )//fast input function
{
        n=0;
        int ch=getcx();int sign=1;
        while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
        while(  ch >= '0' && ch <= '9' )
                n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
        n=n*sign;
}



long long int dp[210][110];
long long int ar[210][110];
int n;

long long int call(int row, int col){

    long long int sum = -1;

    if(row < (n-1) && (col >= 0 && col < n )  && ar[row][col] !=0){
        if(dp[row][col] != -1 ) return dp[row][col];

        sum = max(sum, call(row+1, col) + ar[row][col]);
        sum = max(sum,  call(row+1, col+1) + ar[row][col]);
    }
   else if(row < (2*n - 1) && (col >=0 && col < n ) &&  ar[row][col] !=0){
        if(dp[row][col] != -1 ) return dp[row][col];

        sum = max(sum, call(row+1, col) + ar[row][col]);
        sum = max(sum,  call(row+1, col-1) + ar[row][col]);
    }
    else return 0;

    return dp[row][col] = sum;
}



int main(){
    int test;
    cin >> test;

    for(int i=1; i <= test; i++){
        int p=1;
        cin >> n;

        memset(ar, 0 , sizeof(ar));
        memset(dp, -1, sizeof(dp));

        for(int j=0; j < n; j++){
            for(int k=0; k < p; k++){
                cin >> ar[j][k];
            }
            p++;
        }

        p=(n-1);
        for(int j=n; j <= (2*n)-1 ; j++){
            for(int k=0; k < p; k++){
                cin >> ar[j][k];
            }
            p--;
        }
        cout <<"Case " << i << ": " << call (0,0) << endl;
    }

    return 0;
}
