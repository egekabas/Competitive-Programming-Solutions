#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
string s;
int q;
int check[5006][5006];
int f[5006][5006];
int pal(int x, int y){
    if(x>= y)
        return 1;
    if(check[x][y] != -1)
        return check[x][y];
    if (s[x] != s[y])
        return check[x][y] ;
    return check[x][y] = pal(x+1,y-1);
}

int dp(int x, int y){
    if(x > y) return 0;
    if(x == y) return 1;
    if(f[x][y] != -1) return f[x][y];
    f[x][y] = dp(x+1, y) + dp(x, y-1) - dp(x+1, y-1);
    if(pal(x, y) == 1)
        f[x][y]++;
    return f[x][y];
}
int main(){
    cin >> s >> q;
    memset(check,-1,sizeof(check));
    memset(f,-1,sizeof(f));

    int l, r;
    while(q--){
        scanf("%d %d",&l,&r);
        --l;--r;
        printf("%d\n",dp(l,r));

    }
}