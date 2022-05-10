#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int n, m;
ll a[4009];

void calc(int l, int r, vector<ll> &dp){
    if(l > r){
        dp.resize(1);
        return;
    }

    
    dp.resize(r-l+1+1);

    int mid = l;
    for(int i = l; i <= r; ++i)
        if(a[i] < a[mid])
            mid = i;
    

    vector<ll> dpl, dpr;
    calc(l, mid-1, dpl);
    calc(mid+1, r, dpr);


    for(ll i = 0; i <= mid-l; ++i)
        for(ll j = 0; j <= r-mid; ++j){
            
            dp[i+j] = max(dp[i+j], dpl[i]+dpr[j]-2*i*j*a[mid]);

            dp[i+j+1] = max(dp[i+j+1], dpl[i]+dpr[j]+m*a[mid]-2*i*j*a[mid]-(2*i+2*j+1)*a[mid]);
        }
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    vector<ll> ans;
    calc(0, n-1, ans);

    cout << ans[m] << '\n';   
}