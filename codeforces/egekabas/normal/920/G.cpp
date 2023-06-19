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
vector<int> v;
int get(int x){
    int ans = x;
    for(int i = 1; i < (1<<v.size()); ++i){
        int cur = 1;
        for(int j = 0; j < v.size(); ++j)
            if(i&(1<<j))
                cur *= v[j];
        if(__builtin_popcount(i)%2)
            ans -= x/cur;
        else
            ans += x/cur;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        int x, p, k;
        cin >> x >> p >> k;
        v.clear();
        for(int i = 2; i*i <= p; ++i){
            if(p%i) continue;
            v.pb(i);
            while(p%i == 0)
                p /= i;
        }
        if(p > 1) v.pb(p);
        int beg = get(x);
        int l = x+1, r = 1e9;
        while(l < r){
            int m = (l+r)/2;
            if(get(m)-beg < k)
                l = m+1;
            else
                r = m;
        }
        cout << l << '\n';
    }
}