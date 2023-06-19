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
vector<pii> v;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        v.clear();
        for(int i = 0; i < n; ++i){
            int t1;
            cin >> t1;
            if(v.empty() || t1 != (*(v.end()-1)).ss)
                v.pb({1, t1});
            else
                ++(*(v.end()-1)).ff;
        }
        int g = 0, s = 0, b = 0;
        for(int i = 0; i < n; ++i){
            //cout << i << " "
            if(g == 0){
                g += v[i].ff;
            }
            else if(s <= g){
                s += v[i].ff;
            }
            else{
                b += v[i].ff;
            }
            if(b+s+g > n/2){
                b -= v[i].ff;
                break;
            }
        }
        if(g == 0 || s <= g || b <= g || b+s+g > n/2){
            cout << "0 0 0\n";
        }
        else{
            cout << g << " " << s << " " << b << "\n";
        }
    }
}