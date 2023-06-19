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
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int n;
int a[4009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        n *= 2;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        stack<pii> st;
        for(int i = 0; i < n; ++i){
            int maxi = a[i];
            int sz = 1;
            while(st.size()){
                if(st.top().ff < maxi)
                    break;
                maxi = st.top().ff;
                sz += st.top().ss;
                st.pop();
            }
            st.push({maxi, sz});
        }


        bitset<4009> bt;
        bt[0] = 1;
        while(st.size()){
            int cur = st.top().ss;
            st.pop();
            bt = (bt<<cur)|bt;
        }
        if(bt[n/2])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}