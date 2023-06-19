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

int main(){
    string s;
    int n;
    cin >> n >> s;
    int l = 0;
    for(int i = 1; i < n; ++i){
        if(s[i] > s[l])
            l = i;
        else if(s[i] < s[l]){
            cout << "YES\n";
            cout << l+1 << " " << i+1 << endl;
            return 0;
        }
    }
    cout << "NO\n"; 
}