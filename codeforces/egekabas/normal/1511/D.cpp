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
int cnt[26][26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;

    string ans;
    while(ans.size() < n){
        for(int i = 0; i < k; ++i){
            if(ans.size() < n)
                ans.pb(i+'a');
            for(int j = i+1; j < k; ++j){
                if(ans.size() < n)
                    ans.pb(i+'a');
                if(ans.size() < n)
                    ans.pb(j+'a');
            }
        }
    }
    cout << ans << '\n';
}
// aabacadbbcbdccdd aabacadbbcbdccdd aabacadbbcbdccdd aabacadbbcbdccdd