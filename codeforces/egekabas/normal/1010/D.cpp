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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n;
int type[1000009];
int imp[1000009];
int val[1000009];
int down[1000009][2];
void calcval(int v){
    if(v == 0) return;
    calcval(down[v][0]);
    calcval(down[v][1]);
    if(type[v] == 0) return;
    else if(type[v] == 1)
        val[v] = !val[down[v][0]];
    else if(type[v] == 2)
        val[v] = val[down[v][0]]&val[down[v][1]];
    else if(type[v] == 3)
        val[v] = val[down[v][0]]|val[down[v][1]];
    else if(type[v] == 4)
        val[v] = val[down[v][0]]^val[down[v][1]];
}
void calcimp(int v){
    if(v == 0) return;
    imp[v] = 1;
    if(type[v] == 0) return;
    else if(type[v] == 1)
        calcimp(down[v][0]);
    else if(type[v] == 2){
        if(val[down[v][0]] == 1)
            calcimp(down[v][1]);
        if(val[down[v][1]] == 1)
            calcimp(down[v][0]);
    }
    else if(type[v] == 3){
        if(val[down[v][0]] == 0)
            calcimp(down[v][1]);
        if(val[down[v][1]] == 0)
            calcimp(down[v][0]);
    }
    else if(type[v] == 4){
        calcimp(down[v][1]);
        calcimp(down[v][0]);    
    }
    
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    string s;
    int x, y;
    for(int i = 1; i <= n; ++i){
        cin >> s;
        if(s == "IN"){
            type[i] = 0;
            cin >> val[i];
        }
        else if(s == "NOT"){
            type[i] = 1;
            cin >> x;
            down[i][0] = x;
        }
        else if(s == "AND"){
            type[i] = 2;
            cin >> x >> y;
            down[i][0] = x;
            down[i][1] = y;
        }
        else if(s == "OR"){
            type[i] = 3;
            cin >> x >> y;
            down[i][0] = x;
            down[i][1] = y;    
        }
        else if(s == "XOR"){
            type[i] = 4;
            cin >> x >> y;
            down[i][0] = x;
            down[i][1] = y;    
        }
    }
    calcval(1);
    calcimp(1);
    for(int i = 2; i <= n; ++i){
        if(type[i] != 0) continue;
        if(imp[i] == 1) cout << !val[1];
        else cout << val[1];
    }
}