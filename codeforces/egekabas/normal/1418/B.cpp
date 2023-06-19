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
int a[1009];
int b[1009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> v;
        for(int i = 0; i < n; ++i){
            cin >> b[i];
            if(b[i] == 0)
                v.pb(a[i]);
        }
        sort(all(v));
        for(int i = 0; i < n; ++i){
            if(b[i])
                cout << a[i] << ' ';
            else{
                cout << v.back() << ' ';
                v.pop_back();
            }
        }
        cout << '\n';
    }
}