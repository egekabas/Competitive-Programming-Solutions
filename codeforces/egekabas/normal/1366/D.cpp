#include <bits/stdc++.h>
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
int a1[500009];
int a2[500009];
int n;
vector<int> primes;
int notprime[10000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    for(int i = 2; i < 10000; ++i){
        if(notprime[i])continue;
        primes.pb(i);
        for(int j = i*i; j < 10000; j += i)
            notprime[j] = 1;
    }
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        int mult = 1;
        int mini = 1e9;
        for(int j = 0; primes[j]*primes[j] <= x; ++j){
            if(x%primes[j]) continue;
            mult *= primes[j];
            mini = min(mini, primes[j]);
            while(x % primes[j] == 0)
                x /= primes[j];
        }
        if(x > 1){
            mult *= x;
            mini = min(mini, x);
        }
        if(mult == mini)
            a1[i] = a2[i] = -1;
        else{
            a1[i] = mini;
            a2[i] = mult/mini;
        }
    }
    for(int i = 0; i < n; ++i)
        cout << a1[i] << ' ';
    cout << '\n';
    for(int i = 0; i < n; ++i)
        cout << a2[i] << ' ';
}