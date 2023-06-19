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
pii seg[200009];
int maxi[200009];
int pre[200009];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> seg[i].ff >> seg[i].ss;
        sort(seg, seg+n);
        //n = unique(seg, seg+n)-seg;
        maxi[0] = seg[0].ss;
        for(int i = 1; i < n; ++i)
            maxi[i] = max(maxi[i-1], seg[i].ss);
        vector<int> v = {seg[0].ss};
        pre[0] = 1;
        for(int i = 1; i < n; ++i){
            if(*(v.end()-1) >= seg[i].ff)
                *(v.end()-1) = max(*(v.end()-1), seg[i].ss);
            else
                v.push_back(seg[i].ss);
            pre[i] = v.size();
        }
        v.clear();
        v.pb(seg[n-1].ff);
        int ans = pre[n-2];
        for(int i = n-2; i >= 1; --i){
            int curans = lower_bound(v.begin(), v.end(), maxi[i-1],greater<int>())-v.begin();
            curans += pre[i-1];
            ans = max(ans, curans);
            while(!v.empty() && *(v.end()-1) <= seg[i].ss)
                v.pop_back();
            v.push_back(seg[i].ff);
        }  
        ans = max(ans, (int)v.size());
        cout << ans << "\n";
    }
}