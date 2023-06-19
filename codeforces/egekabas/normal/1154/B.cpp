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
set<int> s;
int n;
int a[150];

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        s.insert(a[i]);    
    }
    int cnt = 0;
    int tot = 0;
    for(auto u : s){
        tot += u;
        ++cnt;
    }
    if(cnt == 1){
        cout << 0;
        return 0;    
    }
    if(tot % cnt != 0 && cnt > 2){
        cout << -1;
        return 0;
    }
    if(tot % cnt != 0 && cnt == 2){
        auto u = s.begin();
        int tmp1 = *u;
        ++u;
        int tmp2 = *u;
        cout << abs(tmp1-tmp2);
        return 0;
    
    }
    tot /= cnt;
    int val = -1;
    for(auto u : s){
        if(u == tot)
            continue;
        if(val == -1)
            val = abs(u-tot);
        else if(val != abs(u-tot) ){
            cout << -1;
            return 0;
        }
    }
    cout << val << endl;
}