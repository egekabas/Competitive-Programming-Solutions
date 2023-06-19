#include <bits/stdc++.h>
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const int INF = (int) 1e9;
const int mod = (int) 1e9+7;
const int MAXN = (int) 3e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    #ifdef Local
        freopen("../IO/int.txt","r",stdin);
        freopen("../IO/out.txt","w",stdout);
    #endif

    cin>>n;

    if(n % 2 && n > 4){
        cout<<"1 "<<(n - 5)/2 + 1<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    #ifdef Local
        cout<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
    #endif
}