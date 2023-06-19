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

int n;
int a[2009];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << n+1 << endl;
    int mod = n-1;
    int add = 0;
    for(int i = n; i > 0; --i){
        a[i] += add;
        cout << "1 " << i << " " << (mod+n-a[i]%n)%n << endl;
        add +=  (mod+n-a[i]%n)%n;
        --mod;
    }
    cout << "2 " << n << " " << n << endl;
}