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

pii dir[] = {{1, 0}, {0, 1}, {0, -1},  {-1, 0}};
int ex[15];
int ans[15];
int gr[1009][1009];
queue<pair<pii, int>> q[15];
int cnt;
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 1; i <= p; ++i)
        cin >> ex[i];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            char c;
            cin >> c;
            if(c == '.') gr[i][j] = 0;
            else if(c == '#') gr[i][j] = -1;
            else {
                gr[i][j] = c - '0';
                q[c - '0'].push({{i, j}, 0});
                ++ans[c - '0'];
            }
        }
    cnt = -1;
    for(int loop = 0; ; ++loop){
        if(cnt == 0) break;
        cnt = 0;
        for(int i = 1; i <= p; ++i){
            while(!q[i].empty()){
                pair<pii, int> tmp = q[i].front();
                //cout << tmp.ss << " " << loop << endl;
                if(tmp.ss-loop*ex[i] >= ex[i]){
                    break;
                }
                q[i].pop();
                pii cord = tmp.ff;
                for(int j = 0; j < 4; ++j){
                    if(dir[j].ff + cord.ff >= 0 && dir[j].ff + cord.ff < n &&
                    dir[j].ss + cord.ss >= 0 && dir[j].ss + cord.ss < m &&
                    gr[dir[j].ff + cord.ff][dir[j].ss + cord.ss] == 0){
                        ++cnt;
                        gr[dir[j].ff + cord.ff][dir[j].ss + cord.ss] = i;
                        q[i].push({{dir[j].ff + cord.ff, dir[j].ss + cord.ss}, tmp.ss+1});
                        ++ans[i];
                    }
                }
            }
        }
    }
    /*for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)
            cout << gr[i][j];
        cout << endl;    
    }*/
    for(int i = 1; i <= p; ++i)
        cout << ans[i] << " ";

}