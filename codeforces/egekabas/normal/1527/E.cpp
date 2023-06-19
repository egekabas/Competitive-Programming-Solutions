#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int n, k;
int a[35009];
int dp[35009][109];
vector<int> vec[35009];
int fl[35009], fr[35009];
int curans, curl, curr;
void addl(int i){
    i = a[i];
    curans -= max(vec[i][fr[i]]-vec[i][fl[i]], 0);
    --fl[i];
    curans += max(vec[i][fr[i]]-vec[i][fl[i]], 0);
    
}
void addr(int i){
    i = a[i];
    curans -= max(vec[i][fr[i]]-vec[i][fl[i]], 0);
    ++fr[i];
    curans += max(vec[i][fr[i]]-vec[i][fl[i]], 0);

}
void erasel(int i){
    i = a[i];
    curans -= max(vec[i][fr[i]]-vec[i][fl[i]], 0);
    ++fl[i];
    curans += max(vec[i][fr[i]]-vec[i][fl[i]], 0);

}
void eraser(int i){
    i = a[i];
    curans -= max(vec[i][fr[i]]-vec[i][fl[i]], 0);
    --fr[i];
    curans += max(vec[i][fr[i]]-vec[i][fl[i]], 0);

}

void calc(int l, int r, int tl, int tr, int k){
    if(l > r) return;
    int m = (l+r)/2;
    pii mini = {1e9, 1e9};
    while(curr < m){
        //cout << "BEG " << curl << ' ' << curr << ' '  << vec[6][fl[6]] << ' ' << vec[6][fr[6]] << ' ' << curans<< '\n';

        ++curr;
        addr(curr);
    }
    while(curl > m){
        --curl;
        addl(curl);

    }
    while(curr > m){
        eraser(curr);
        --curr;

    }
    if(abs(curl - min(tr, m)) <= abs(curl - tl)){
        while(curl > min(tr, m)){
            --curl;
            addl(curl);
        }
        while(curl < min(tr, m)){
            erasel(curl);
            ++curl;
        }

        for(int i = min(tr, m); i >= tl; --i){
            if(curl != i){
                --curl;
                addl(curl);
            }
            //cout << curl << ' ' << curr << ' ' << curans << ' ' << k  << '\n';
            
            mini = min(mini, {curans+dp[i-1][k-1], i});
        }
    }
    else{

        while(curl > tl){
            --curl;
            addl(curl);

        }
        while(curl < tl){
            erasel(curl);
            ++curl;

        }
        
        for(int i = tl; i <= min(tr, m); ++i){
            if(curl != i){
                erasel(curl);
                ++curl;
            }
            mini = min(mini, {curans+dp[i-1][k-1], i});
        }

    }

    dp[m][k] = mini.ff;
    if(mini.ss > (tl+tr)/2){
        calc(l, m-1, tl, mini.ss, k);
        calc(m+1, r, mini.ss, tr, k);
    }
    else{
        calc(m+1, r, mini.ss, tr, k);
        calc(l, m-1, tl, mini.ss, k);    
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        vec[i].pb(0);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        vec[a[i]].pb(i);
        //a[i] = rand()%n+1;
    }
    for(int i = 1; i <= n; ++i)
        vec[i].pb(n+1);
    
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= k; ++j)
            dp[i][j] = 1e9+7;
    
    for(int j = 1; j <= k; ++j){
        curans = curr = 0;
        curl = 1;
        for(int i = 1; i <= n; ++i){
            fl[i] = 1;
            fr[i] = 0;
        }
        calc(1, n, 1, n, j);
    }
    //for(int i = 1; i <= n; ++i)
    //    for(int j = 0; j <= k; ++j)
    //        cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
    cout << dp[n][k] << '\n';   
    //cout << counter << '\n';
}