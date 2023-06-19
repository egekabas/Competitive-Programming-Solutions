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
typedef long double ld;
ll c, hr, hb, wr,wb;
ll ans = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> c >> hr >> hb >> wr >> wb;
    if(hr*wb > wr*hb){
        swap(hr, hb);
        swap(wr, wb);
    } 
    ll red = 0;
    ll blue = 0;
    if(wb >= 1000){
        for(blue = 0; blue*wb <= c; ++blue){
            red = (c-blue*wb)/wr;
            ans = max(ans, blue*hb+red*hr);
        }    
    }
    else{
        for(red = 0; red <= wb && red*wr <= c; ++red){
            blue = (c-red*wr)/wb;
            ans = max(ans, blue*hb+red*hr);
        }
    }
    cout << ans << "\n";
}