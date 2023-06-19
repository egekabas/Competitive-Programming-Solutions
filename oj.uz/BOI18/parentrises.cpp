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
///////////////////////////////////////////burayi degistir
void solve1(){
    string s;
    cin >> s;
    int n = s.size();
    int cur = 0;
    int mini = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '(')
            cur++;
        else
            cur--;
        mini = min(mini, cur);
    }
    vector<int> ans(n);
    mini *= -1;
    for(int i = 0; i < n; ++i){
        if(mini > 0 && s[i] == '('){
            ans[i] = 1;
            --mini;
            ++cur;
        }
    }
    if(mini > 0){
        cout << "impossible\n";
        return;
    }
    for(int i = n-1; i >= 0; --i){
        if(s[i] == '(')
            continue;
            
        if(cur > 0){
            ans[i] = 1;
            --cur;
        }
    }
    if(cur > 0){
        cout << "impossible\n";
        return;
    }
    cur = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '(')
            cur++;
        else
            cur--;
        if(ans[i]){
            if(s[i] == '(')
                cur++;
            else
                cur--;    
        }
        if(cur < 0){
            cout << "impossible\n";
            return;
        }
    }
    int val[2] = {0, 0};
    char c[3] = {'R', 'B', 'G'};
    for(int i = 0; i < n; ++i){
        //cout << '\n' << val[0] << ' ' << val[1] << '\n';
        if(ans[i]){
            cout << c[2];
            if(s[i] == '('){
                ++val[0];
                ++val[1];
            }
            else{
                --val[0];
                --val[1];
            }
        }
        else{
            if(s[i] == '('){
                if(val[0] < val[1]){
                    ++val[0];
                    cout << c[0];
                }
                else{
                    ++val[1];
                    cout << c[1];
                }
            }
            else{
                if(val[0] > val[1]){
                    --val[0];
                    cout << c[0];
                }
                else{
                    --val[1];
                    cout << c[1];
                }
            }
        }
    }
    cout << '\n';
}
ll dp[309][309];
ll ndp[309][309];
ll ans[309];
const ll mod = 1e9+7;
ll mx = 300;
void solve2(){
    int n;
    cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].ff;
        a[i].ss = i; 
    }
    sort(all(a));
    dp[0][0] = 1;
    int idx = 0;
    for(ll i = 1; i <= mx; ++i){
        for(ll j = 0; j <= mx; ++j)
            for(ll k = 0; k <= mx; ++k){
                ndp[j+1][k+1] = (ndp[j+1][k+1]+dp[j][k])%mod;
                if(k > 1)
                    ndp[j+1][k-2] = (ndp[j+1][k-2]+dp[j][k])%mod;
                else if(k)
                    ndp[j][k-1] = (ndp[j][k-1]+dp[j][k])%mod;
                else if(j)
                    ndp[j-1][k] = (ndp[j-1][k]+dp[j][k])%mod;
            }
        ll curans = 0;
        for(ll j = 0; j <= mx; ++j){
            for(ll k = 0; k <= mx; ++k){
                dp[j][k] = ndp[j][k];
                ndp[j][k] = 0;
            }
            curans = (curans+dp[j][0])%mod;
        }
        //if(i == 3)
        //    cout << curans << '\n';
        while(idx < n && a[idx].ff == i){
            ans[a[idx].ss] = curans;
            idx++;
        }
    }
    for(int i = 0; i < n; ++i)
        cout << ans[i] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    /*for(int bit = 0; bit < (1<<3); ++bit){
        string s;
        for(int i = 0; i < 4; ++i){
            if((1<<i)&bit)
                s.pb('(');
            else
                s.pb(')');
        }
        if(solve1(s))
            cout << s << '\n';
    }*/
 
    int p;
    cin >> p;
    if(p == 1){
        int t;
        cin >> t;
        while(t--)
            solve1();
    }
    else
        solve2();
}
