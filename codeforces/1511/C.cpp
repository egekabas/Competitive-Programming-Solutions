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
int n, q;
int a[55];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        int val;
        cin >> val;
        if(a[val] == 0)
            a[val] = i;
    }
    while(q--){
        int col;
        cin >> col;
        cout << a[col] << ' ';
        for(int i = 1; i <= 50; ++i)
            if(a[i] < a[col])
                ++a[i];
        a[col] = 1;
    }

}