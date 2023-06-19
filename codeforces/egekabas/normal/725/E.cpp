#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
int cnt[200009];
int nxt[200009];
int c, n;
int check(int x){
    int curval = c;
    int curcoin = nxt[c];
    bool used = 1;
    while(curcoin > 0){
        if(x >= curcoin && used){
            used = 0;
            if(curval >= x)
                curval -= x;
            curcoin = nxt[min(curcoin, curval)];
            if(curcoin == 0)
                break;
        }    
        curval = max(curval%curcoin, curval-curcoin*cnt[curcoin]);
        curcoin = nxt[min(curcoin-1, curval)];
    }
    if(curval == 0)
        return 0;
    else
        return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> c >> n;
    for(int i = 0; i < n; ++i){
        int t1;
        cin >> t1;
        cnt[t1]++;
    }
    for(int i = 1; i <= c; ++i){
        if(cnt[i] > 0)
            nxt[i] = i;
        else
            nxt[i] = nxt[i-1];
    }
    
    for(int i = 0; i <= c; ++i){
        if(check(i)){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "Greed is good\n";
    return 0;
}