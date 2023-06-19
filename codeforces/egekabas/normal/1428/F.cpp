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
int n;
string s;
int a[500009];
ll ans[500009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> s;
    for(int i = 0; i < n; ++i)
        a[i] = s[i]-'0';
    vector<pii> v;
    int last = n;
    for(int i = n-1; i >= 0; --i){
        ans[i] = ans[i+1];
        if(!a[i]){
            last = i;
        }
        else{
            pii cur;
            if(last == i+1)
                cur = {i, 0};
            else{
                cur = v.back();
                v.pop_back();
            }
            cur.ss++;
            int idx = i;
            while(v.size()){
                if(v.back().ss < cur.ss){
                    ans[i] += v.back().ff-idx+1;
                    idx = v.back().ff+1;
                    v.pop_back();
                }
                else{
                    ans[i] += v.back().ff-idx+1-(v.back().ss-cur.ss+1);
                    break;
                }
            }
            if(v.empty())
                ans[i] += n-idx;
            v.pb(cur);
        }

    }
    ll fin = 0;
    for(int i = 0; i < n; ++i)
        fin += ans[i];
    cout << fin << '\n';
}