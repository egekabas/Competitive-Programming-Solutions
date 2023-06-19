#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;

ll area(pll a, pll b, pll c){
    pll x = mp(b.ff-a.ff, b.ss-a.ss);
    pll y = mp(c.ff-a.ff, c.ss-a.ss);
    return (abs(x.ff*y.ss-x.ss*y.ff));
}
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

ll n, m, k;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    if(2.0*(ld)n*(ld)m/(ld)k != 2*n*m/k){
        cout << "NO";
        return 0;
    }
    pll a, b, c;
    a = mp(0,0);
    if(k <= 1){
        cout << "NO";
        return 0;
    }
    else{
        b.ss = 0;
        c.ff = 0;
    }

/*
    for(int i = 1; i <= sqrt(tmp); ++i){
        if(tmp%i == 0 && tmp/i <= max(n, m) && i <= min(n, m)){
            if(n >= m){
                b.ff = tmp/i;
                c.ss = i;
            }
            else{
                c.ss = tmp/i;
                b.ff = i;
            }
            break;
        }
    }
*/
    bool ctrl = 1;
    b.ff = n;
    c.ss = m;

    if(k % 2 == 0){
        k = k/2;
        ctrl = 0;
    }

    ll tmp = gcd(k, b.ff);
    k = k/tmp;
    b.ff = b.ff/tmp;
     tmp = gcd(k, c.ss);
    k = k/tmp;
    c.ss = c.ss/tmp;

    if(b.ff*2 <= n && ctrl )
        b.ff = b.ff*2;
    else if(c.ss*2 <= m && ctrl)
        c.ss = c.ss*2;


    //cout << area(a, b, c)/2 << endl;
    cout << "YES\n";
    cout << a.ff << " " << a.ss << endl;
    cout << b.ff << " " << b.ss << endl;
    cout << c.ff << " " << c.ss << endl;
}