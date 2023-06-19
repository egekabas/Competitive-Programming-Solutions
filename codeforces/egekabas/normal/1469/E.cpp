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
ll n, k;
string s;
const ll mod = 1e16+7;
void solve(){
    cin >> n >> k >> s;
    map<ll, ll> vis;
    ll curhs = 0;
    ll pk = 1;
    for(ll i = 0; i < k; ++i){
        pk = (pk*2)%mod;
        curhs = (curhs*2)%mod;
        curhs = (curhs+s[i]-'0')%mod;
    }
    vis[curhs] = 1;
    for(ll i = k; i < n; ++i){
        curhs = (curhs*2)%mod;
        
        curhs -= (s[i-k]-'0')*pk%mod;
        curhs = (curhs+mod)%mod;
    
        curhs = (curhs+s[i]-'0')%mod;

        vis[curhs] = 1;
    }
    ll curval = 0;
    for(ll i = 0; i < k; ++i){
        curval = (curval*2)%mod;
        curval = (curval+1)%mod;
    }
    ll tot = 0;
    ll ans = ((1LL<<31)-1);
    while(vis[curval]){
        tot++;
        --ans;
        curval = (curval-1+mod)%mod;
    }

    //cout << ans << '\n';
    if(k <= 32 && tot >= (1LL<<k))
        cout << "NO\n";
    else{
        cout << "YES\n";
        //cout << ans << ' ' << curval << '\n';
        string s;
        for(ll i = 0; i < min(31LL, k); ++i){
            if(ans&(1LL<<i))
                s.pb('0');
            else
                s.pb('1');
        }
        for(ll i = 0; i < k-31; ++i)
               s.pb('0');
        reverse(all(s));
        cout << s << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--)
        solve();
}