#include <bits/stdc++.h>
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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
int g[30][30];
int cnt[30];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 20; ++i)
            for(int j = 0; j < 20; ++j)
                g[i][j] = 0;
        for(int i = 0; i < 20; ++i)
            cnt[i] = 0;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int no = 0;
        for(int i = 0; i < n; ++i){
            if(b[i] < a[i]){
                no = 1;
                break;
            }
            cnt[a[i]-'a']++;
            if(b[i] == a[i])
                cnt[a[i]-'a']--;
            else 
                g[a[i]-'a'][b[i]-'a']++;
        }
        if(no){
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        for(int i = 0; i < 20; ++i){
            if(!cnt[i]) continue;
            for(int j = i+1; j < 20; ++j)
                if(g[i][j]){
                    for(int k = j+1; k < 20; ++k)
                        g[j][k] += g[i][k];
                    cnt[j] += cnt[i]-g[i][j];
                    ++ans;
                    break;
                }
        }
        cout << ans << '\n';
    }
}