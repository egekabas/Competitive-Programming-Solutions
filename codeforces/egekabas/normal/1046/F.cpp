#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long   ll;
typedef long double ld;

ll a[200000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    int N;
    cin>>N;
    for(int i = 0; i < N; i++)
        cin>>a[i];
    ll f, x;
    cin>>x>>f;
    ll ans = 0;
    ll tmp;
    for(int i = 0; i < N; i++){
        if(a[i] > x){
            ans += a[i]/(f+x)*f;
            if(a[i] % (f+x) > x)
                ans += f;
        }
    }
    cout<<ans<<endl;
}