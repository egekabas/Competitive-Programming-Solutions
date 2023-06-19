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
int a[2009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = n; i >= 1; --i)
        for(int j = i-1; j >= 1; --j)
            a[j] -= a[i]*(i-j+1);
    char cur = 'a';
    for(int i = 1; i <= n; ++i){
        while(a[i]--){
            for(int j = 0; j < i; ++j)
                cout << cur;
            if(cur == 'a')
                cur = 'b';
            else
                cur = 'a';
        }
    }
}