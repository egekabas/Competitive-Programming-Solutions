#include <bits/stdc++.h>
#include "popa.h"
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
/*int ar[10009];
int query(int a, int b, int c, int d){
    int v1 = 0, v2 = 0;
    for(int i = a; i <= b; ++i)
        v1 = __gcd(v1, ar[i]);
    for(int i = c; i <= d; ++i)
        v2 = __gcd(v2, ar[i]);
    return v1 == v2;
}*/
 
int solve(int N, int *Left, int *Right){
    for(int i = 0; i < N; ++i)
        Left[i] = Right[i] = -1;
    vector<int> vec;
    for(int i = 0; i < N; ++i){
        vector<int> vals;
        while(vec.size()){
            if(query(vec.back(), i, i, i) == 1){
                vals.pb(vec.back());
                vec.pop_back();
            }
            else
                break;
        }
        reverse(all(vals));
        if(vals.size())
            Left[i] = vals[0];
        for(int i = 1; i < vals.size(); ++i)
            Right[vals[i-1]] = vals[i];
        vec.pb(i);
    }
    for(int i = 1; i < vec.size(); ++i)
        Right[vec[i-1]] = vec[i];
    return vec[0];
}
/*int L[1009], R[1009];
int main(){
    
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
 
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> ar[i];
    cout << solve(n, L, R) << '\n';
    for(int i = 0; i < n; ++i)
        cout << i << ' ' << L[i] << ' ' << R[i] << '\n';
}*/
