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
int n;
map<ll, ll> mpp;
string s;
vector<int> v;
void change(string s){
    v.clear();
    for(auto u : s){
        if(u == 'a')
            v.pb(2);
        if(u == 'b'){
            v.pb(2);
            //v.pb(2);
        }
        if(u == 'c'){
            v.pb(2);
        }
        if(u == 'd')
            v.pb(3);
        if(u == 'e'){
            v.pb(3);
        }
        if(u == 'f'){
            v.pb(3);
        }
        if(u == 'g')
            v.pb(4);
        if(u == 'h'){
            v.pb(4);
        }
        if(u == 'i'){
            v.pb(4);
        }
        if(u == 'j')
            v.pb(5);
        if(u == 'k'){
            v.pb(5);
        }
        if(u == 'l'){
            v.pb(5);
        }
        if(u == 'm')
            v.pb(6);
        if(u == 'n'){
            v.pb(6);
        }
        if(u == 'o'){
            v.pb(6);
        }
        if(u == 'p')
            v.pb(7);
        if(u == 'q'){
            v.pb(7);
        }
        if(u == 'r'){
            v.pb(7);
        }
        if(u == 's'){
            v.pb(7);
        }
        if(u == 't')
            v.pb(8);
        if(u == 'u'){
            v.pb(8);
        }
        if(u == 'v'){
            v.pb(8);
        }
        if(u == 'w')
            v.pb(9);
        if(u == 'x'){
            v.pb(9);
        }
        if(u == 'y'){
            v.pb(9);
        }
        if(u == 'z'){
            v.pb(9);
        }
    }
}
ll calc(){
    ll mod = 1e9+7;
    ll p = 31;
    ll mult = 31;
    ll ret = 0;
    for(auto u : v){
        ret += u*mult%mod;
        mult *= p;
        ret %= mod;
    }
    return ret;
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> s;
        change(s);
        ++mpp[calc()];
    }
    char c;
    v.clear();
    while(scanf("%c", &c) != EOF){
        if(c >= '0' && c <= '9')
            v.pb((int)c-(int)'0');
    }
    cout << mpp[calc()] << "\n";
}
