#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
int n;
int a[2009];
int predp[2009][3];
int sufdp[2009][3];
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    predp[0][a[0]] = 1;
    for(int i = 1; i < n; ++i){
        predp[i][1] = predp[i-1][1];
        predp[i][2] = max(predp[i-1][2] ,predp[i-1][1]);
        predp[i][a[i]]++;
    }
    sufdp[n-1][a[n-1]] = 1;
    for(int i = n-2; i >= 0; --i){
        sufdp[i][1] = max(sufdp[i+1][1], sufdp[i+1][2]);
        sufdp[i][2] = sufdp[i+1][2];
        sufdp[i][a[i]]++;
    }
    for(int i = 0; i < n; ++i){
        int one = 0;
        int two = 0;
        for(int j = i; j >= 0; --j){
            int newone = one;
            int newtwo = max(two, one);
            if(a[j] == 1)
                ++newone;
            if(a[j] == 2)
                ++newtwo;
            if(j > 0){
                ans = max(predp[j-1][1]+newone+max(sufdp[i+1][1], sufdp[i+1][2]), ans);
                ans = max(max(predp[j-1][1], predp[j-1][2])+newtwo+sufdp[i+1][2], ans);
            }
            else{
                ans = max(newone+max(sufdp[i+1][1], sufdp[i+1][2]), ans);
                ans = max(newtwo+sufdp[i+1][2], ans);                
            }
            one = newone;
            two = newtwo;
        }
    }
    ans = max(ans, max(predp[n-1][1], predp[n-1][2]));
    cout << ans << "\n";
}