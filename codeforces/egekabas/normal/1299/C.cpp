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
ll a[1000009];
ld ans[1000009];
ll n;
stack<pair<ld, ll>> st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];

    for(ll i = n-1; i >= 0; --i){
        ld av = a[i];
        ll cnt = 1;
        while(!st.empty()){
            if(st.top().ff > av)
                break;
            av = (av*cnt+st.top().ff*st.top().ss)/(cnt + st.top().ss);
            cnt += st.top().ss;
            st.pop();
        }
        st.push({av, cnt});
    }
    while(!st.empty()){
        for(ll i = 0; i < st.top().ss; ++i)
            cout << fixed << setprecision(9) << st.top().ff << "\n";
        st.pop();
    }
}