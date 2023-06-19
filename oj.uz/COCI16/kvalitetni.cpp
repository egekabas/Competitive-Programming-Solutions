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
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll k;
ld z[100];
string s;
ld func(ll l, ll r){
    if(l == r)
        return z[1];
    ld depth = 0;
    vector<ld> v;
    char op;
    int l1;
    int cnt = 0;
    for(int i = l; i <= r; ++i){
        if(s[i] == '('){
            depth++;
            if(depth == 1)
                l1 = i;
        }
        else if(s[i] == ')'){
            --depth;
            if(depth == 0)
                v.pb(func(l1+1, i-1));
        }
        else if(depth == 0)
            op = s[i];
    }
    if(op == '+'){
        ld ret = 0;
        for(auto u : v)
            ret += u;
        return min(z[v.size()], ret);        
    }
    else{
 
        sort(v.begin(), v.end());
        ld ans = 1;
        ld maxisum = z[v.size()];
        for(ll i = 0; i < v.size(); ++i){
            //cout << v[i] << "\n";
            if(v[i] <= maxisum/((ld)v.size()-(ld)i)){
                ans *= v[i];
                maxisum -= v[i];
            }
            else{
                ans *= (maxisum/((ld)v.size()-(ld)i));
                maxisum -= maxisum/((ld)v.size()-(ld)i);
            }
        }
        return ans;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> k;
    for(ll i = 1; i <= k; ++i)
        cin >> z[i];
    cin >> s;    
    cout << fixed << setprecision(10) << func(1, s.size()-2) << "\n";
}
