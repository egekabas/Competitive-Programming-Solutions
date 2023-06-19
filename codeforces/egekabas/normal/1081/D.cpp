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
int n, m, k;
int disc[200009];
int a[200009];
vector<pair<int, pii>> edge;

int func(pair<int, pii> a, pair<int, pii> b){
    return a.ff < b.ff;
}

int prt[200009];
int sz[200009];
int maxi[200009];
int sp[200009];


void crt(int a){
    if(disc[a] == 1)
        sp[a] = 1;
    prt[a] = a;
    sz[a] = 1;
}

int find(int a){
    if(prt[a] == a)
        return a;
    return find(prt[a]);
}

int getans(int a){
    if(prt[a] == a)
        return maxi[a];
    return max(maxi[a], getans(prt[a]));
}

void merge(int a, int b){
    if(sz[b] > sz[a])
        swap(b, a);
    prt[b] = a;
    sz[a] += sz[b];
    if(sp[b] == 1)
        sp[a] = 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m >> k;
    for(int i = 0; i < k; ++i){
        cin >> a[i];
        disc[a[i]] = 1;
    }
    int t1, t2, t3;
    for(int i = 0; i < m; ++i){
        cin >> t1 >> t2 >> t3;
        edge.pb({t3, {t1, t2}});
    }
    for(int i = 0; i <= n; ++i)
        crt(i);
    sort(edge.begin(), edge.end(), func);

    for(int i = 0; i < edge.size(); ++i){
        int w = edge[i].ff;
        int v1 = edge[i].ss.ff;
        int v2 = edge[i].ss.ss;
        v1 = find(v1);
        v2 = find(v2);
        //cout << v1 << " " << v2 << endl;
        if(v1 == v2) continue;
        else if(sp[v1] == 1 && sp[v2] == 1){
            merge(v1, v2);
            maxi[find(v1)] = w;
        }
        else{
            merge(v1, v2);
        }
    }
    for(int i = 0; i < k; ++i){
        cout << getans(a[i]) << " ";
    }
}