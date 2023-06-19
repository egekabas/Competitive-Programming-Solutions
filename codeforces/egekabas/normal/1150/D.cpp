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

int n, q;
string s;
int ar[30][100009];
int dp[260][260][260];
string rel[3];

int f(int a, int b, int c){
    if(a == 0 && b == 0 && c == 0)
        return -1;
    if(dp[a][b][c] != -1)
        return dp[a][b][c];
    int ret = 100009;
    if(a > 0){
        int fi = f(a-1, b, c);
        fi = ar[rel[0][a-1]-'a'][fi+1]; 
        ret = min(ret, fi);
    }
    if(b > 0){
        int fi = f(a, b-1, c);
        fi = ar[rel[1][b-1]-'a'][fi+1];
        ret = min(ret, fi);
    }
    if(c > 0){
        int fi = f(a, b, c-1);
        fi = ar[rel[2][c-1]-'a'][fi+1];
        ret = min(ret, fi);
    }
    //cout << a << " " << b << " " << c << " " << ret << endl;
    return dp[a][b][c] = ret;
}



int main() {
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> q >> s;
    for(int i = 0; i <= 255; ++i)
        for(int j = 0; j <= 255; ++j)
            for(int k = 0; k <= 255; ++k)
                dp[i][j][k] = -1;
    
    for(int i = 0; i <= 'z'-'a'; ++i)
        ar[i][n+2] = ar[i][n+1] = ar[i][n] = n;
    for(int i = n-1; i >= 0; --i){
        for(int j = 0; j <= 'z'-'a'; ++j){
            if(j == s[i]-'a')
                ar[j][i] = i;
            else
                ar[j][i] = ar[j][i+1];
        }
    }

    char tmp1, tmp3;
    int tmp2;

    while(q--){
        cin >> tmp1 >> tmp2;
        --tmp2;
        if(tmp1 == '+'){
            cin >> tmp3;
            rel[tmp2].push_back(tmp3);
        }
        if(tmp1 == '-'){
            for(int i = 0; i <= 255; ++i)
                for(int j = 0; j <= 255; ++j){    
                    if(tmp2 == 0)
                        dp[rel[tmp2].size()][i][j]=-1;
                    if(tmp2 == 1)
                        dp[i][rel[tmp2].size()][j]=-1;
                    if(tmp2 == 2)
                        dp[j][i][rel[tmp2].size()]=-1;
                }
            rel[tmp2].erase(rel[tmp2].end()-1);
        }
        int ans = f(rel[0].size(), rel[1].size(), rel[2].size());
        if(ans < n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}