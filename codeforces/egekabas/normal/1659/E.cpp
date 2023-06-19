#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
int n, m, q;
struct node{
    int x, y, val;
};

node edges[100009];
pii qu[100009];
int ans[100009];



int prt[30][100009];
int sp[100009];

int find(int x, int prt[]){
    if(prt[x] == x)
        return x;
    return prt[x] = find(prt[x], prt);
}
void merge(int x, int y, int prt[]){
    x = find(x, prt);
    y = find(y, prt);
    prt[x] = y;
}


int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < m; ++i)
        cin >> edges[i].x >> edges[i].y >> edges[i].val;
    
    cin >> q;
    for(int i = 0; i < q; ++i){
        cin >> qu[i].ff >> qu[i].ss;
        ans[i] = -1;
    }

    for(int bit = 0; bit < 30; ++bit){
        for(int i = 1; i <= n; ++i)
            prt[bit][i] = i;
        for(int i = 0; i < m; ++i)
            if(edges[i].val&(1<<bit))
                merge(edges[i].x, edges[i].y, prt[bit]);
    }


    for(int cur = 0; cur < 30; ++cur){
        
        

        for(int bit = 0; bit < 30; ++bit){
            if(cur&(1<<bit))
                continue;
            
            for(int i = 1; i <= n; ++i)
                sp[i] = 0;

            for(int i = 0; i < m; ++i){
                if((edges[i].val&cur) != cur){
                    sp[find(edges[i].x, prt[bit])] = 1;
                    sp[find(edges[i].y, prt[bit])] = 1;
                }
            }
            
            
            for(int i = 0; i < q; ++i)
                if(ans[i] == -1 && (find(qu[i].ff, prt[bit]) == find(qu[i].ss, prt[bit]) || sp[find(qu[i].ff, prt[bit])] == 1))
                    ans[i] = cur;
        }

        /////////////////////////
        //if(cur == 1)
        //    break;
    }
    for(int i = 0; i < q; ++i){
        if(ans[i] == -1)
            cout << "30\n";
        else
            cout << ans[i] << '\n';
    }
}