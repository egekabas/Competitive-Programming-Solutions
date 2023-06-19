#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

typedef long long   ll;
typedef long double ld;

typedef pair<ll, ll>    pll;
typedef pair<ll, int>   pli;
typedef pair<int, int>  pii;

typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll>  vll;

const int Inf = (int) 1e9;
const ll  InfL = (ll)  1e18;

struct node{
    int maxi;
    int beg;//sayi
    int end;//sayi
    int fir;//deger
    int sec;//deger
};

struct node merge(node a, node b){
    node x;
    int tmp;
    if(a.end == b.beg)
        tmp = a.sec + b.fir;
    else
        tmp = max(a.sec, b.fir);
    x.beg = a.beg;
    if(a.beg != a.end || a.beg != b.beg)
        x.fir = a.fir;
    else
        x.fir = a.fir + b.fir;
    x.end = b.end;
    if(b.end != b.beg || b.end != a.end)
        x.sec = b.sec;
    else
        x.sec = a.sec + b.sec;
    x.maxi = max(max(x.fir, x.sec), max(a.maxi, max(b.maxi,tmp)));
    return x;
}

int a[100009];
int n, q;
node t[400009];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].beg = t[v].end = a[tl];
        t[v].maxi = t[v].fir = t[v].sec = 1;
    }
    else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = merge(t[2*v], t[2*v+1]);
    }
}

node sum(int v, int tl, int tr, int l, int r) {
    if (l > r){
        node tmp;
        tmp.beg = tmp.end = int(-1e6);
        tmp.fir = tmp.sec = tmp.maxi = 0;
        return tmp;
    }
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    node a = sum(v*2, tl, tm, l, min(r, tm));
    node b = sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    return merge(a, b);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    while (1) {
        int n, q;
        cin >> n;

        if(n == 0)
            break;

        cin >> q;
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        build(1, 0, n-1);

        int l, r;
        for(int i = 0; i < q; ++i){
            cin >> l >> r;
            cout << sum(1, 0, n-1, l-1, r-1).maxi << endl;
        }
    }

    return 0;
}
