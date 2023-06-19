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
int a[200009];
multiset<int> b;
int main(){
    #ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int tmp;
    int maxi = -1e9;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        b.insert(tmp);
        maxi = max(tmp, maxi);
    }
    for(int i = 0; i < n; ++i){
        auto itr = b.lower_bound(n-a[i]);
        if(itr == b.end()){
            cout << (a[i] + *b.begin())%n << " ";
            b.erase(b.begin());
        }
        else if((a[i]+(*itr))%n < (*b.begin()+a[i])%n){
            cout << (a[i] + (*itr))%n << " ";
            b.erase(itr);    
        }
        else{
            cout << (a[i] + *b.begin())%n << " ";
            b.erase(b.begin());
        }
    }
}