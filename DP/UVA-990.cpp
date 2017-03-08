//**************************UVA-990: Diving for gold****************************
#include<bits/stdc++.h>
using namespace std;

#define reset(array, value) memset(array, -1, sizeof(array))
#define pii pair<int,int>
#define pb(val) push_back(val);

int tim,w,n;
long long int dp[1002][32];
vector < pii > item;
vector < int > dir;

struct path{
    int x,y;
    path(){};
    path(int a, int b){
        x=a;
        y=b;
    }
}direction[1002][32];

//   DP Function
int call(int rem, int i){
    if(i >= n ){
        direction[rem][i] = path(-1, -1);
        return 0;
    }
    if(dp[rem][i] != -1)return dp[rem][i];

    int d = item[i].first,a = item[i].second;
    int ret1=0,ret2=0;

    if(rem >= (3*w*d))ret1 = a + call(rem - (3*w*d), i+1);

    ret2 = call(rem, i+1);

    if(ret1 > ret2){
        direction[rem][i] = path(rem - (3*w*d), i+1);
        return dp[rem][i] = ret1;
    }
    else{
        direction[rem][i] = path(rem, i+1);
        return dp[rem][i] = ret2;
    }
}

//Path printing Function
void print_path(int i, int j){
    if(i==-1 && j==-1)return;

    int p = direction[i][j].x;
    int q = direction[i][j].y;
    if(p != i){
        if(j!= n)dir.pb(j);
    }
    print_path(p, q);
}

// Main Function
int main(){
    int a,b,flag=0;
    pii p;
    while(scanf("%d %d", &tim, &w)!=EOF){
        if(flag!=0)printf("\n");
        flag=1;
        scanf("%d", &n);
        for(int i=0; i <n; i++){
            scanf("%d %d",&a, &b);
            p.first=a;p.second=b;
            item.pb(p);
        }
        reset(dp, -1);
        printf("%d\n", call(tim,0));
        print_path(tim, 0);
        printf("%ld\n", dir.size());
        for(int k=0; k < dir.size(); k++)printf("%d %d\n",item[dir[k]].first, item[dir[k]].second);
        item.clear();
        dir.clear();
    }
    return 0;
}
