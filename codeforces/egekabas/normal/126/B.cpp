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
int n;
string s;
int pi[1000009];
vector<int> v;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> s;
    n = s.size();
    pi[0] = 0;
    for(int i = 1; i < n; ++i){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j]) ++j;
        pi[i] = j;
    }
    int suf = pi[n-1];
    int j = suf;
    while(j > 0){
        v.pb(j);
        j = pi[j-1];
    }
    reverse(v.begin(), v.end());
    int mid = 0;
    for(int i = 1; i < n-1; ++i){
        auto j = lower_bound(v.begin(), v.end(), pi[i]);
        if(j == v.end()) continue;
        if(*j == pi[i])
            mid = max(mid, *j);
    }
    if(mid == 0){
        cout << "Just a legend\n";
        return 0;
    }
    cout << s.substr(0, mid) << endl;
    
}