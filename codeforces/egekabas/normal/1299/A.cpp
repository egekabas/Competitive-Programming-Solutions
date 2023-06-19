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
int a[100009];
map<int, int> cnt;
set<int> s;
int pre[100009];
int suf[100009];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(ll i = 1; i <= n; ++i)
        pre[i] = (a[i]|pre[i-1]);
    
    for(ll i = n; i >= 1; --i)
        suf[i] = (a[i]|suf[i+1]);
    
    int id = 0, max = 0;
    for(int i = 1; i <= n; ++i){
        int cur = (((pre[i-1]|suf[i+1])^a[i])&a[i]);
        if(cur >= max){
            max = cur;
            id = i;
        }
    }
    cout << a[id] << " ";
    for(int i = 1; i <= n; ++i)
        if(i != id)
            cout << a[i] << " ";
}