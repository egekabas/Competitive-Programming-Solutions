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
int a[200009], ans[200009];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n;
    char c;
    for(int i = 0; i < n; ++i){
        cin >> c;
        if(c == '(')
            a[i] = 1;
        else
            a[i] = -1;
    }
    int f = 0;
    int s = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == 1){
            if(f < s){
                ans[i] = 0;
                ++f;
            }
            else{
                ans[i] = 1;
                ++s;    
            }
        }
        else if(a[i] == -1){
            if(f > s){
                ans[i] = 0;
                --f;
            }
            else{
                ans[i] = 1;
                --s;    
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout << ans[i];
    }

}