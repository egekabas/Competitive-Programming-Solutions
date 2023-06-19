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
int n, k;
int t;
int q(int x){
    ++t;
    t = min(t, n/3);
    cout << "? " << x+1 << endl;
    int ans;
    cin >> ans;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;

    int curidx = n-1;
    while(1){
        if(q(curidx) < k){
            int i = (curidx+1)%n;
            while(1){
                if(q(i) == k){
                    cout << "! " << i+1 << endl;
                    return 0;
                }
                i = (i+1)%n;
            }
        }
        else{
            curidx = ((curidx-t)%n+n)%n;
        }
    }
}