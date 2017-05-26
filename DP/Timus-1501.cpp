#include <bits/stdc++.h>
using namespace std;

struct next_path{
    int a,b,c;
    next_path(int _a, int _b, int _c){a=_a,b=_b,c=_c;}
    next_path(){}
}direction[10001][10001];

int N;
char s1[1001],s2[1001];
bool done[1001][1001][2],memo[1001][1001][2];

bool solve(int n, int m, int next){
    if(n==N && m==N) return true;

    bool &ret = memo[n][m][next];

    if(!done[n][m][next]){
        ret = false;

        if((n+m) & 1){
            if(n<N && s1[n]=='0'+next && solve(n+1,m,1-next)){
                ret = true;
                direction[n][m]=next_path(n+1,m,1);
            }
            if(m<N && s2[m]=='0'+next && solve(n,m+1,1-next)){
                ret = true;
                direction[n][m]=next_path(n,m+1,2);
            }
        }else{
            if(n<N && solve(n+1,m,s1[n]=='0'? 1 : 0)){
                direction[n][m]=next_path(n+1,m,1);
                ret = true;
            }
            if(m<N && solve(n,m+1,s2[m]=='0'? 1 : 0)){
                direction[n][m]=next_path(n,m+1,2);
                ret = true;
            }
        }

        done[n][m][next] = true;
    }

    return ret;
}

void go(int a,int b){
        if(direction[a][b].c == 1 || direction[a][b].c == 2){
        int next_a=direction[a][b].a;
        int next_b=direction[a][b].b;
        cout << direction[a][b].c;
        go(next_a, next_b);
    }
    return;
}


int main(){
    scanf("%d",&N);
    scanf("%s %s",s1,s2);

    memset(done,false,sizeof(done));

    if(solve(0,0,0) || solve(0,0,1)){
        go(0,0);
        cout << endl;
    }else{
        puts("Impossible");
    }

    return 0;
}
