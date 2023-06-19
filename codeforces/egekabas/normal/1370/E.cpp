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
int n;
string s, t;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> s >> t;
    int bal = 0;
    for(int i = 0; i < n; ++i)
        if(s[i] != t[i]){
            v.pb(s[i] == '1');
            bal += (s[i] == '1') - (s[i] != '1');
        }
    if(bal != 0){
        cout << -1;
        return 0;
    }
    int zer = 0;
    int one = 0;
    for(auto u : v){
        if(u){
            if(zer)
                --zer;
            ++one;
        }
        else{
            if(one)
                --one;
            ++zer;
        }
    }
    cout << one + zer;
}