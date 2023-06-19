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

int main(){
    cin >> n;
    cin >> s;
    int ans = n-1;
    for(int i = 0; i < n-1; ++i){
        if( (int)s[i] > (int)s[i+1]){
            ans = i;
            break;
        }
    }
    for(int i = 0; i < n; ++i){
        if(i != ans)
            cout << s[i];
    }
}