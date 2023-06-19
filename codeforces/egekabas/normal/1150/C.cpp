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
int ones;
int twos;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n;
    int tmp;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        if(tmp == 1)++ones;
        if(tmp == 2)++twos;
    }
    if(twos != 0){
        cout << "2 ";
        --twos;
    }
    if(ones != 0){
        cout << "1 ";
        --ones;
    }
    while(twos > 0){
        --twos;
        cout << "2 ";
    }
    while(ones > 0){
        --ones;
        cout << "1 ";
    }
}