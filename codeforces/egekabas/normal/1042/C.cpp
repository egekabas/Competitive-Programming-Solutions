#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ll, int>   pli;
typedef pair<int, int>  pii;

vector<int> v;
int n;
int a[200009];

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    pii minneg = mp(int(1e9), -1);
    pii minpos = mp(int(1e9), -1);
    int neg = 0;
    int zero = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < 0){
            ++neg;
            if(abs(a[i]) <= minneg.ff){
                minneg.ff = abs(a[i]);
                minneg.ss = i;
            }
        }
        else if(a[i] == 0){
            ++zero;
            v.pb(i);
        }
    }
    int idx;

    if(neg % 2 == 1 && zero == 0){
        idx = minneg.ss;
        if(n == 1)
            idx = -1;
    }
    else if(zero > 0){
        idx = v[0];
        for(auto i = v.begin()+1; i < v.end(); ++i){
            cout << "1 " << *i+1 << " " << idx+1 << endl;
            a[*i] = int(1e9)+1;
        }
        if(neg % 2 == 1){
            cout << "1 " << minneg.ss + 1 << " " << idx+1 << endl;
            a[minneg.ss] = int(1e9)+1;
        }
        if(zero == n || (zero == n-1 && neg%2==1))
            idx = -1;
    }
    else
        idx = -1;

    if(idx >= 0)
        cout << "2 " << idx+1 << endl;
    int other = 0;
    while(1){
        if(idx == other || a[other] == int(1e9)+1)
            ++other;
        else
            break;
    }
    for(int i = 0; i < n; ++i){
        if(i == other || i == idx || a[i] == int(1e9)+1 )
            continue;
        else
            cout << "1 " << i+1 << " " << other+1 << endl;
    }

}