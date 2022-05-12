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

int len, n;
int a[100009];

int checkmin(int minlen){
    int prev = 0;

    for(int i = 1; i <= n; ++i){
        prev = max(a[i], prev+minlen);
        if(prev > a[i+1])
            return 0;
    }
    return 1;
}

int minlen;

int l[100009], r[100009];

int checkmax(int maxlen){

    l[0] = r[0] = 0;

    for(int i = 1; i <= n; ++i){
        int cur = a[i]-r[i-1];
        if(cur > maxlen)
            return 0;
        
        l[i] = r[i-1];
        r[i] = min(a[i+1], l[i]+maxlen);
        if(i == n)
            r[i] = a[i+1];
        
        if(r[i]-l[i] > maxlen || r[i] < a[i])
            return 0;
    }

    int relax = 0;

    for(int i = n; i >= 1; --i){
        r[i] -= relax;
        relax = 0;
        if(r[i] < a[i])
            return 0;
        
        if(r[i]-l[i] < minlen){
            int need = minlen-(r[i]-l[i]);
            l[i] -= need;
            relax = need;
        }
    }

    if(relax)
        return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> len >> n;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    a[0] = 0;
    a[n+1] = len;

    
    int lef = 0, rig = len;
    while(lef < rig){
        int m = (lef+rig+1)/2;
        if(checkmin(m))
            lef = m;
        else
            rig = m-1;
    }
    

    minlen = lef;

    //cout << checkmax(minlen+8) << '\n'; return 0;

    lef = 0, rig = len;
    while(lef < rig){
        int m = (lef+rig)/2;
        if(checkmax(m))
            rig = m;
        else
            lef = m+1;
    }

    checkmax(lef);
    for(int i = 1; i <= n; ++i)
        cout << l[i] << ' ' << r[i] << '\n';
}