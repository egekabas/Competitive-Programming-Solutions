#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int n, m;
int sq = 300;
int a[100009];
struct node{
    int cnt, lst, go;
};
node val[100009];
void upd(int gr){
    int l = gr*sq;
    int r = (gr+1)*sq-1;
    for(int i = min(r, n-1); i >= l; --i){
        if((i+a[i])/sq != gr || i+a[i] >= n)
            val[i] = {1, i, i+a[i]};
        else
            val[i] = {1+val[i+a[i]].cnt, val[i+a[i]].lst, val[i+a[i]].go};
    }
}
void get(int idx){
    int cnt = 0;
    int lst = idx;
    while(idx < n){
        lst = val[idx].lst;
        cnt += val[idx].cnt;
        idx = val[idx].go;
    }
    cout << lst+1 << ' ' << cnt << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i*sq < n; ++i)
        upd(i);
    while(m--){
        int t;
        cin >> t;
        if(t == 0){
            int x, y;
            cin >> x >> y;
            --x;
            a[x] = y;
            upd(x/sq);
        }
        else{
            int x;
            cin >> x;
            --x;
            get(x);
        }
    }
}