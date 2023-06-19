#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<int, int>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
pii seg[100009];
int n, m, k;
vector<pii> add;
vector<pii> er;
int segtobit[100009];
int bittoseg[100009];

int dp[(1<<9)];
void addnew(int x){
    for(int i = 0; i < 8; ++i)
        if(bittoseg[i] == 0){
            bittoseg[i] = x;
            segtobit[x] = i;
            break;
        }
    for(int bit = 0; bit < (1<<8); ++bit)
        if((bit&(1<<(segtobit[x]))) > 0)
            dp[bit] = dp[bit-(1<<(segtobit[x]))];
}

void erase(int x){
    for(int bit = 0; bit < (1<<8); ++bit)
        if((bit&(1<<(segtobit[x]))) > 0){
            dp[bit-(1<<(segtobit[x]))] = max(dp[bit-(1<<(segtobit[x]))], dp[bit]);
            dp[bit] = -1e9;
        }
    bittoseg[segtobit[x]] = 0;
    segtobit[x] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        cin >> seg[i].ff >> seg[i].ss;
        add.pb({seg[i].ff, i});
        er.pb({seg[i].ss+1, i});
    }
    sort(add.begin(), add.end());
    sort(er.begin(), er.end());
    
    int addcur = 0;
    int ercur = 0;
    int bef = 1;
    for(int bit = 1; bit < (1<<8); ++bit)
        dp[bit] = -1e9;
    while(addcur < add.size() || ercur < er.size()){
        if(addcur == add.size() || er[ercur].ff <= add[addcur].ff){
            for(int bit = 0; bit < (1<<8); ++bit)
                dp[bit] += (er[ercur].ff-bef)*(__builtin_popcount(bit)%2);
            erase(er[ercur].ss);
            bef = er[ercur].ff;
            ercur++;
        }
        else{
            for(int bit = 0; bit < (1<<8); ++bit)
                dp[bit] += (add[addcur].ff-bef)*(__builtin_popcount(bit)%2);
            addnew(add[addcur].ss);
            bef = add[addcur].ff;
            addcur++;
        }
        /*for(int bit = 0; bit < (1<<cnt); ++bit)
            cout << bit << ' ' << dp[bit] << '\n';
        cout << '\n';*/
    }
    for(int bit = 0; bit < (1<<8); ++bit)
        dp[bit] += (m+1-bef)*(__builtin_popcount(bit)%2);
    int ans = 0;
    for(int bit = 0; bit < (1<<8); ++bit){
        ans = max(ans, dp[bit]);
        //cout << bit << ' ' << dp[bit] << '\n';
    }
    cout << ans << '\n';    
}