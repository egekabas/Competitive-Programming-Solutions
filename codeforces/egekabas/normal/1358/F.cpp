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
ll n;
ll a[200009];
int suma;
ll b[200009];
string ans;

inline ll check1(){
    for(ll i = 0; i < n; ++i)
        if(a[i] != b[i])
            return 0;
    return 1;
}
inline ll check2(){
    for(ll i = 0; i < n; ++i)
        if(a[i] != b[n-i-1])
            return 0;
    return 1;
}
ll type = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < n; ++i)
        cin >> b[i];
    if(n == 1){
        if(a[0] == b[0])
            cout << "SMALL\n0\n";
        else
            cout << "IMPOSSIBLE\n";
        return 0;
    }
    while(1){
        if(check1()) break;
        if(check2()){
            if(type <= 200000)
                ans.pb('R');
            break;
        }
        for(ll i = 1; i < n; ++i)   
            if(b[i] <= b[i-1]){
                reverse(b, b+n);
                if(type <= 200000)
                    ans.pb('R');
                break;
            }
        for(ll i = 1; i < n; ++i)
            if(b[i] <= b[i-1]){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        if(n == 2){
            ll times;
            ll rev = 0;
            if(a[0] == b[0] && b[1] > a[1] && (b[1]-a[1])%a[0] == 0)
                times = (b[1]-a[1])/a[0];
            else if(a[1] == b[0] && b[1] > a[0] && (b[1]-a[0])%a[1] == 0){
                times = (b[1]-a[0])/a[1];  
            }
            else
                times = b[1]/b[0]-!(b[1]%b[0]);
            b[1] -= b[0]*times;
            type += times;
            if(type <= 200000)
                while(times--)
                    ans.pb('P');
            continue;
        }
        if(type <= 200000)
            ans.pb('P');
        ++type;
        
        for(ll i = n-1; i >= 1; --i)
            b[i] = b[i]-b[i-1];
    }
    reverse(ans.begin(), ans.end());
    if(type <= 200000){
        cout << "SMALL\n";
        cout << ans.size() << '\n';
        cout << ans;
    }
    else{
        cout << "BIG\n";
        cout << type << '\n';    
    }
}