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
int n, s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> s;
    int maxi = 1 + s-n;
    if(n-1 < s/2 && (s+1)/2 < maxi){
        cout << "YES\n";
        for(int i = 0; i < n-1; ++i)
            cout << "1 ";
        cout << maxi << '\n';
        cout << s/2;
    }
    else{
        cout << "NO\n";
    }
    
}