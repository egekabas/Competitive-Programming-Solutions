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
ll used[1000];
vector<char> g[1000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
                                                                                                                        
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);    
    
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        for(ll i = 'a'; i <= 'z'; ++i){
            used[i] = 0;
            g[i].clear();
        }
        deque<char> v;
        v.pb(s[0]);
        used[s[0]] = 1;
        ll i;

        for(i = 1; i < s.size(); ++i){
            if(used[s[i]]){
                ll ok = 0;
                for(auto u : g[s[i]]){
                    if(u == s[i-1])
                        ok = 1;
                }
                if(ok == 0){
                    cout << "NO\n";
                    goto FIN;
                }
            }
            else if(v.back() == s[i-1]){
                used[s[i]] = 1;
                g[s[i]].pb(s[i-1]);
                g[s[i-1]].pb(s[i]);
                v.push_back(s[i]);
            }
            else if(v.front() == s[i-1]){
                used[s[i]] = 1;
                g[s[i]].pb(s[i-1]);
                g[s[i-1]].pb(s[i]);
                v.push_front(s[i]);    
            }
            else{
                cout << "NO\n";
                goto FIN;
            }
        }
        cout << "YES\n";
        for(i = 'a'; i <= 'z'; ++i)
            if(used[i] == 0)
                v.pb(i);
        for(auto u : v)
            cout << u;
        cout << "\n";
        FIN:;
    }
}