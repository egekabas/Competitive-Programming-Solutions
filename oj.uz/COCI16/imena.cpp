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
int n;
int cur;
int ans[10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    while(cur < n){
        string s;
        cin >> s;
        int upper = 0;
        int size = s.size();
        int next = 0;
        if(s[size-1] == '!' || s[size-1] == '.' || s[size-1] == '?'){
            --size;
            next = 1;
        }
        if(s[0] <= 'Z' && s[0] >= 'A')
            upper = 1;
        for(int i = 1; i < size; ++i)
            if(s[i] > 'z' || s[i] < 'a')
                upper = 0;
        if(upper)
            ++ans[cur];
        cur += next;
    }
    for(int i = 0; i < n; ++i)
        cout << ans[i] << "\n";
}
