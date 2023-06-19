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
int querry(vector<int> v1, vector<int> v2){
    cout << "? " << v1.size() << ' ' << v2.size() << '\n';
    for(auto u : v1)
        cout << u+1 << ' ';
    cout << '\n';
    for(auto u : v2)
        cout << u+1 << ' ';
    cout << endl;
    string str;
    cin >> str;
    if(str == "FIRST")
        return 0;
    else if(str == "SECOND")
        return 1;
    else if(str == "EQUAL")
        return 2;
    assert(0);
}
int equal(int l1, int r1, int l2, int r2){
    vector<int> v1, v2;
    for(int i = l1; i <= r1; ++i)
        v1.pb(i);
    for(int i = l2; i <= r2; ++i)
        v2.pb(i);
    if(querry(v1, v2) == 2)
        return 1;
    return 0;
}
void finish(int l, int r){
    if(l == r){
        cout << "! " << l+1 << '\n';
        return;
    }
    int m = (l+r)/2;
    if(equal(0, m-l, l, m))
        finish(m+1, r);
    else
        finish(l, m);
}
int n, k;
int main() {    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    srand(time(NULL));
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int heavy = 0;
        vector<int> rv;
        for(int i = 0; i < n; ++i)
            rv.pb(i);
        random_shuffle(rv.begin(), rv.end());
        for(int i = 0; i < min(25, n); ++i){
            int idx = rv[i];
            if(heavy != idx && querry({heavy}, {idx}) == 1)
                heavy = idx;
        }
        if(heavy != 0 && querry({0}, {heavy}) != 2){
            cout << "! 1\n";
            continue;
        }
        int l = 1, r = 1;
        while(l < n){
            if(equal(0, r-l, l, r)){
                l = r+1;
                r = min(l+r, n-1);
            }
            else{
                finish(l, r);
                break;
            }
        }
    }   
}