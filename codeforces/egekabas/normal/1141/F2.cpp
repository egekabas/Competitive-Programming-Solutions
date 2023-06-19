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
int n, a[1509];
map<int, vector<pii>> mpp;
set<int> s;
int func(pii a, pii b){
    return a.ss < b.ss;
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
    int tmp;
    for(int i = 1; i <= n; ++i){
        cin >> tmp;
        a[i] = a[i-1]+tmp;
    }
    for(int i = 0; i < n; ++i)
        for(int j = i+1; j <= n; ++j){
            mpp[a[j]-a[i]].pb({i+1, j});
            s.insert(a[j]-a[i]);
        }
    int cur = -1;
    int maxi = -1;
    for(auto u : s){
        sort(mpp[u].begin(), mpp[u].end(), func);
        int right = 0;
        int count = 0;
        for(auto k : mpp[u]){
            if(k.ff <= right) continue;
            right = k.ss;
            ++count;
        }
        if(count > maxi){
            cur = u;
            maxi = count;
        }
    }
    cout << maxi << "\n";
    int right = 0;
    for(auto k : mpp[cur]){
        if(k.ff <= right) continue;
        right = k.ss;
        cout << k.ff << " " << k.ss << "\n";
    }
}