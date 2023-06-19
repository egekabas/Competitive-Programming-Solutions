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

ll a, b, c;
ll a1, b1, c1, tmp1, tmp2;

ll mini(ll a, ll b ,ll c){
    return min(min(a, b), c);
}
void calc1(ll *tmp, ll *x, ll *y, ll *z, ll days){
    if((*x) < 0 || (*y) < 0  || (*z) < 0 ) return;
    if(days < 1){--(*x);if((*x) < 0 )return;else ++(*tmp);}
    if(days < 2){--(*y);if((*y) < 0)return;else ++(*tmp);}
    if(days < 3){--(*z);if((*z) < 0)return;else ++(*tmp);}
    if(days < 4){--(*x);if((*x) < 0)return;else ++(*tmp);}
    if(days < 5){--(*z);if((*z) < 0)return;else ++(*tmp);}
    if(days < 6){--(*y);if((*y) < 0)return;else ++(*tmp);}
    if(days < 7){--(*x);if((*x) < 0)return;else ++(*tmp);}
}

int main(){
    cin >> a >> b >> c;
    ll ans = -1;

    for(int i = 0; i < 7; ++i){
        a1 = a; b1 = b; c1 = c; tmp1 = 0;
        calc1(&tmp1, &a1, &b1, &c1, i);
        a1 = max((ll)0, a1); b1 = max((ll)0, b1); c1 = max((ll)0, c1);
        tmp2 = mini(a1/3, b1/2, c1/2);
        //cout << tmp2 << " ";
        a1 -= tmp2*3; b1 -= tmp2*2; c1 -= tmp2*2;
        tmp1 += 7*tmp2;calc1(&tmp1, &a1, &b1, &c1, 0);calc1(&tmp1, &a1, &b1, &c1, 0); 
        ans = max(ans, tmp1);
        //cout << tmp1 << endl;
    }
    
    cout << ans;
}