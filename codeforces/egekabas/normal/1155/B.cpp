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
string s;
int a[200000];

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> s;
    int eights = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '8'){
            a[eights++] = i;
        }
    }
    int moves = (n-11)/2;
    for(int i = moves; i < eights; ++i){
        if( moves >= a[i]-i){ 
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}