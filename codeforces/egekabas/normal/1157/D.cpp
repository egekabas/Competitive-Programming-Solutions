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
ll ar[100009];
ll n, k;
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> k;
    ll a = (n-(k+1)*k/2)/k;
    ll need = n-(k+1)*k/2-a*k;
    if(n < k*(k+1)/2){
        cout << "NO\n";
        return 0;
    }
    for(int i = k; i >= 1; --i){
        if(need == 0) break;
        ar[i] = i+a+min(need, i+a-2);
        need -= min(need, i+a-2);
    }   
    if(need != 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i = 1; i <= k; ++i){
        if(ar[i] == 0)
            cout << i+a << " ";
        else
            cout << ar[i] << " ";
    }
}