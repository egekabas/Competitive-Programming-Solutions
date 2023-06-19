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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
int cnt[35];
int a[100009];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 35; ++i) cnt[i] = 0;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            int cur = 0;
            while(a[i]){
                cnt[cur] += a[i]%2;
                a[i] /= 2;
                ++cur;
            }
        }
        for(int i = 34; i >= 0; --i){
            if(cnt[i]%2){
                int st = !((cnt[i]/2)%2);
                if(st == 0){
                    if(n%2 == 0 || cnt[i] == 1)
                        cout << "WIN\n";
                    else
                        cout << "LOSE\n";
                }
                else{
                    cout << "WIN\n";
                }
                break;
            }
            else if(i == 0){
                cout << "DRAW\n";
            }
        }
    }
}