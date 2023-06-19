    #include <bits/stdc++.h>
    #define ff first
    #define ss second
    #define pb push_back
    #define mp make_pair
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
    typedef pair<ll, ll>    pll;
    typedef pair<ull, ull>    pull;
    typedef pair<int, int>  pii;
    typedef pair<ld, ld>  pld;
    int n, k;
    string s;
    vector<int> v[3];
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
     
        //freopen("in.txt", "r", stdin);                                                                                             
        //freopen("out.txt", "w", stdout);
        
        cin >> n >> k >> s;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'J')
                v[0].pb(i);
            else if(s[i] == 'O')
                v[1].pb(i);
            else
                v[2].pb(i);
        }
        int ans = 1e9;
        for(int i = 0; i < n; ++i){
            int cur = i;
            for(int j = 0; j < 3 && cur != 1e9; ++j){
                int idx = lower_bound(v[j].begin(), v[j].end(), cur)-v[j].begin();
                if(idx+k-1 < v[j].size())
                    cur = v[j][idx+k-1]+1;
                else
                    cur = 1e9;
            }
            //cout << i << ' ' << cur << '\n';
            if(cur != 1e9)
                ans = min(ans, cur-i-3*k);
            
        }
        if(ans == 1e9)
            cout << -1;
        else
            cout << ans;
    }
