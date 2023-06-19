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
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        v.clear();
        int n;
        cin >> n;
        int maxi = 0;
        for(int i = 0; i < n; ++i){
            int tmp;
            cin >> tmp;
            if(v.size() && v.back() > tmp)
                v.pb(tmp);
            else if(v.empty())
                v.pb(tmp);
            else if(tmp < maxi){
                while(v.back() < tmp)
                    v.pop_back();
                v.pb(tmp);
            }
            else if(v.back() < maxi){
                while(v.back() < maxi)
                    v.pop_back();
            }
            maxi = max(maxi, v.back());
        }
        if(v.size() == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}