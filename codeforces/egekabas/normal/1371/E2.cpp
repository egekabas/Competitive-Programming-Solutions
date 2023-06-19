#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, p;
int a[100009];
int minval, maxval;
int val1[100009];
int val2[100009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    //freopen("in.txt", "r", stdin);                                                                                             
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> p;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n, greater<int>());
    maxval = a[0];
    for(int i = 0; i < n; ++i){
        minval = max(minval, a[i]+i-n+1);
        val1[(n-i)%p]++;
    }
    vector<int> ans;
    int cur = 0;
    for(int x = maxval; x >= minval; --x){
        while(cur != n && a[cur] > x){
            val1[(n-cur)%p]--;
            val2[((n-cur-a[cur])%p+p)%p]++;
            ++cur;
        }
        if(val1[0] == 0 && val2[((p-x)%p+p)%p] == 0)
            ans.pb(x);
    }
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(auto u : ans)
        cout << u << ' ';

}