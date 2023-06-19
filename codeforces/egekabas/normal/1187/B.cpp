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
int n, m;
string s;
string a;
int sum[100][500009];
int v[100];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    cin >> s;

    sum[s[0]-'a'][0] = 1;
    for(int i = 1; i < n; ++i)
        for(int k = 0; k <= 'z'-'a'; ++k){
            if(s[i] == ((char)k)+'a') 
                sum[k][i] = sum[k][i-1]+1;
            else
                sum[k][i] = sum[k][i-1];
        }
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> a;
        for(int k = 0; k <= 'z'-'a'; ++k)
            v[k] = 0;
        
        for(auto u : a){
            ++v[u-'a'];
        }
        int ans = -1;
        for(int k = 0; k <= 'z'-'a'; ++k){
            int tmp = lower_bound(sum[k], sum[k]+n, v[k])-sum[k]+1;
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
}