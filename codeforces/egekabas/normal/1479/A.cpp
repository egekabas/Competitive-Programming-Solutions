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
void get(int idx){
    if(a[idx]) return;
    cout << "? " << idx << endl;
    cin >> a[idx];
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    a[0] = a[n+1] = 1e9+7;
    int l = 1, r = n;
    while(l < r){
        int m1 = (l+r)/2;
        int m2 = m1+1;
        
        get(m1);
        get(m2);

        if(a[m1] < a[m2])
            r = m1;
        else
            l = m2;
    }
    cout << "! " << l << endl;
}