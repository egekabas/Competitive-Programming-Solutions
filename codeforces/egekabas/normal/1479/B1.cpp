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
int a[100009];
int notneed[100009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n-2;){
        int j;
        for(j = i+1; j < n-1; ++j)
            if(a[j] == a[j+1])
                break;
        for(int k = i; k < j; ++k)
            notneed[k] = a[j];
        i = j;
    }
    int val[2];
    val[0] = val[1] = 1e9;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(val[0] == a[i] && val[1] == a[i]) continue;
        ++ans;
        if(val[0] != a[i] && (val[1] == a[i] || val[0] == notneed[i]))
            val[0] = a[i];
        else
            val[1] = a[i];
        //cout << notneed[i] << '\n';
    }
    cout << ans << '\n';
}