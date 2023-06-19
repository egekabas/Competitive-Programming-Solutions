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
int k;
vector<int> first;
vector<int> second;
vector<int> both;
vector<int> none;
//int ft, sd, bh;
void end(int a , int b, int c, int d){
    for(int i = 0; i < a; ++i)
        cout << first[i]+1 << " ";
    for(int i = 0; i < b; ++i)
        cout << second[i]+1 << " ";
    for(int i = 0; i < c; ++i)
        cout << both[i]+1 << " ";
    for(int i = 0; i < d; ++i)
        cout << none[i]+1 << " ";
}

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> k;
    string tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    for(int i = 0; i < k; ++i){
        if(tmp1[i]=='1' && tmp2[i]=='1')
            both.pb(i);
        else if(tmp1[i]=='1' && tmp2[i]=='0')
            first.pb(i);
        else if(tmp1[i]=='0' && tmp2[i]=='1')
            second.pb(i);
        else if(tmp1[i]=='0' && tmp2[i]=='0')
            none.pb(i);    
    }
    int f = first.size();
    int s = second.size();
    int b = both.size();
    int n = none.size();
    for(int i = 0; i <= f && i <= k/2; ++i){
        for(int j = 0; j <= b && i+j <= k/2; ++j){
            int v = i+j-(b-j);
            if(v < 0 || v > s)continue;
            int anss = s-v;
            if(anss < 0 || anss + i + j > k/2)continue;
            int ansn = k/2-(anss + i + j);
            if(ansn > n || ansn < 0)continue;
            end(i, anss, j, ansn);
            return 0;
        }
    }
    cout << "-1\n";

}