#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<long long, long long>  pll;
typedef pair<ld, ld>  pld;

long long n;
pll p[200009];
vector<pll> v;
long long dp[200009];

long long sorter(pll x, pll y){
    if(max(x.ff, x.ss) != max(y.ff, y.ss))
        return max(x.ff, x.ss) < max(y.ff, y.ss);
    else{
        return x.ff + (max(x.ff, x.ss)-x.ss) < y.ff + (max(y.ff, y.ss)-y.ss);
    }
}
long long lev(pll x){
    return max(x.ff, x.ss);
}

int main(){
    cin >> n;
    for(long long i = 0; i < n; ++i){
        cin >> p[i].ff >> p[i].ss;
    }
    sort(p, p+n, sorter);
    //for(long long i = 0; i < n; ++i )
    //    cout << "==> " << p[i].ff << " " << p[i].ss << endl;
    long long h = lev(p[0]);
    v.pb(p[0]);
    for(long long i = 1; i < n; ++i){
        if(lev(p[i]) != h){
            h = lev(p[i]);
            v.pb(p[i]);
        }
        else if(i == n-1 || lev(p[i+1]) != h){
            v.pb(p[i]);
        }
    }
    //for(long long i = 0; i < v.size(); ++i )
    //    cout << "==> " << v[i].ff << " " << v[i].ss << endl;

    long long i = 1;
    dp[0] = v[0].ff + v[0].ss;
    if(lev(v[1]) == lev(v[0])){
        dp[0] = v[1].ff + v[1].ss + abs(v[1].ff-v[0].ff) + abs(v[1].ss-v[0].ss);
        dp[1] = v[0].ff + v[0].ss + abs(v[0].ff-v[1].ff) + abs(v[0].ss-v[1].ss);
        ++i;
    }

    long long tmp;
    for(; i < v.size(); ++i){
        if(lev(v[i-1]) == lev(v[i])){
            tmp = dp[i-2] + abs(v[i-2].ff-v[i-1].ff) + abs(v[i-2].ss-v[i-1].ss);
            if(lev(v[i-3]) == lev(v[i-2])){
                tmp = min(tmp,  dp[i-3] + abs(v[i-3].ff-v[i-1].ff) + abs(v[i-3].ss-v[i-1].ss) );
            }
            tmp += abs(v[i-1].ff-v[i].ff) + abs(v[i-1].ss - v[i].ss);
        }
        else if(lev(v[i+1]) == lev(v[i])){
            tmp = dp[i-1] + abs(v[i-1].ff-v[i+1].ff) + abs(v[i-1].ss-v[i+1].ss);
            if(lev(v[i-2]) == lev(v[i-1])){
                tmp = min(tmp,  dp[i-2] + abs(v[i-2].ff-v[i+1].ff) + abs(v[i-2].ss-v[i+1].ss) );
            }
            tmp += abs(v[i+1].ff-v[i].ff) + abs(v[i+1].ss - v[i].ss);
        }
        else{
            tmp = dp[i-1] + abs(v[i-1].ff-v[i].ff) + abs(v[i-1].ss-v[i].ss);
            if(lev(v[i-2]) == lev(v[i-1])){
                tmp = min(tmp,  dp[i-2] + abs(v[i-2].ff-v[i].ff) + abs(v[i-2].ss-v[i].ss));
            }
        }
        dp[i] = tmp;
    }
    //for(long long i = 0; i < v.size(); ++i )
    //    cout << "==> "<< v[i].ff << " " << v[i].ss << " " << dp[i] << endl;
    if(lev(v[v.size()-1]) == lev(v[v.size()-2]))
        cout << min(dp[v.size()-1], dp[v.size()-2]);

    else
        cout << dp[v.size()-1] << endl;

}