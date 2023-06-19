#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ull;
typedef unsigned long long   uull;
typedef long double ld;
typedef pair<ull, ull>    pull;
typedef pair<uull, uull>    puull;
typedef pair<ull, ull>  pii;
typedef pair<ld, ld>  pld;
ull plh[1000009];
ull valh[1000009];
ull prt[1000009];
ull sz[1000009];
unordered_map<ull, ull> sfind;
ull n, q;
ull ar[1000009];
ull sr[1000009];
vector<ull> un;
ull pr = 0;
 
ull find(ull x){
    if(prt[x] == x)
        return x;
    return prt[x] = find(prt[x]);
}
void erase(ull x){
    ull tmp = plh[x]-valh[x];
    ull tmp2 = -tmp;
    sfind[tmp] -= sz[x];
    if(tmp != 0)
        pr -= sz[x]*sfind[tmp2];
    if(sfind[tmp] == 0) 
        sfind.erase(tmp);
    if(sfind[tmp2] == 0) 
        sfind.erase(tmp2);
}
void add(ull y){
    ull tmp = plh[y]-valh[y];
    ull tmp2 = -tmp;
    if(tmp != 0)
        pr += sz[y]*sfind[tmp2];
    sfind[tmp] += sz[y];
    if(sfind[tmp] == 0) 
        sfind.erase(tmp);
    if(sfind[tmp2] == 0) 
        sfind.erase(tmp2);
}
void merge(ull x, ull y){
    x = find(x);
    y = find(y);
    if(x == y)
        return;
    erase(x);
    erase(y);
    prt[x] = y;
    plh[y] =  (plh[y]+plh[x]);
    valh[y] = (valh[y]+valh[x]);
    sz[y] += sz[x];
    add(y);
}
 
ull pw(ull y){
    ull ret = 1;
    ull x = 331;
    ++y;
    while(y > 0){
        if(y%2)
            ret = ret*x;
        x = x*x;
        y /= 2;
    }
    return ret;
}
ull hashval(ull x){
    return pw(lower_bound(un.begin(), un.end(), x)-
    un.begin());
}
ull hashpl(ull x){
    return pw(lower_bound(un.begin(), un.end(), sr[x-1])-
    un.begin());
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> q;
    for(ull i = 1; i <= n; ++i){
        cin >> ar[i];
        sr[i-1] = ar[i];
        
    }
    sort(sr, sr+n);
    for(int i = 0; i < n; ++i){
        if(un.size() > 0 && *(un.end()-1) == sr[i])
            continue;
        un.pb(sr[i]);
    }
    
    for(ull i = 1; i <= n; ++i){
        prt[i] = i;
        sz[i] = 1;
        plh[i] = hashpl(i);
        valh[i] = hashval(ar[i]);
        //cout << i << " " << hashpl(i) << " " << hashval(ar[i]) << "\n";
        add(i);
    }
    while(q--){
        ull t;
        cin >> t;
        if(t == 1){
            ull a, b;
            cin >> a >> b;
            ull a1 = find(a);
            ull b1 = find(b);
            erase(a1);
            erase(b1);
            valh[a1] -= hashval(ar[a]);
            valh[b1] -= hashval(ar[b]);
            
            valh[a1] += hashval(ar[b]);
            valh[b1] += hashval(ar[a]);
            
 
            add(a1);
            add(b1);
            swap(ar[a], ar[b]);
        }
        if(t == 2){
            ull a, b;
            cin >> a >> b;
            merge(a, b);
        }
        if(t == 3){
            if(sfind[0] == n)
                cout << "DA\n";
            else
                cout << "NE\n";
        }
        if(t == 4){
            cout << pr << "\n";
        }
    }
}
