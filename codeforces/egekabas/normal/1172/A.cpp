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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n;
int a[200009], b[200009];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n;

    int tmp;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        a[tmp] = 1;
    }

    for(int i = 0; i < n; ++i)
        cin >> b[i];

    int cr = 1;
    int sp = 0;
    for(int i = 0; i < n; ++i){
        if(b[i] == 1){
            cr = 2;
        }   
        else if(b[i] == cr)
            ++cr;
        else if(b[i] != cr){
            cr = 1;
        }
    }
    if(cr > 1) sp = 1;
    int moves = 0;
    for(int i = 0; i < n; ++i){
        if(cr == n+1){
            cout << moves << endl;
            return 0;
        }
        if(a[cr] == 1){
            ++cr;
            ++moves;
        }
        else{
            ++moves;
            if(sp == 1){
                sp = 0;
                cr = 1;
            }
        }
        a[b[i]] = 1;
    }
    cout << n+1-cr+moves << endl;
}