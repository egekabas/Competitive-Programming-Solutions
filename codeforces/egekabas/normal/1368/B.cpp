#include <bits/stdc++.h>
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
ll k;
string str = "codeforces";
ll vals[100];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> k;
    ll cur = 1;
    for(ll i = 0; i < str.size(); ++i)
        vals[i] = 1;
    while(cur < k)
        for(ll i = 0; i < str.size() && cur < k; ++i){
            cur = cur/vals[i]*(vals[i]+1);
            ++vals[i];
        }
    for(ll i = 0; i < str.size(); ++i)
        while(vals[i]--)
            cout << str[i];
}