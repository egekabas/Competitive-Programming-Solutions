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
int pwr[10];
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << pwr[a-1]+pwr[c-1] << ' ' << pwr[b-1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    pwr[0] = 1;
    for(int i = 1; i < 10; ++i)
        pwr[i] = pwr[i-1]*10;
    int t;
    cin >> t;
    while(t--)
        solve();
    
}