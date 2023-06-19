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
int beh[15];
string s;
char place[15][15];
vector<int> v;
int push[15];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    place[2][1] = 'a';
    place[2][2] = 'b';
    place[2][3] = 'c';
    
    place[3][1] = 'd';
    place[3][2] = 'e';
    place[3][3] = 'f';
    
    place[4][1] = 'g';
    place[4][2] = 'h';
    place[4][3] = 'i';
    
    place[5][1] = 'j';
    place[5][2] = 'k';
    place[5][3] = 'l';
    
    place[6][1] = 'm';
    place[6][2] = 'n';
    place[6][3] = 'o';
    
    place[7][1] = 'p';
    place[7][2] = 'q';
    place[7][3] = 'r';
    place[7][4] = 's';
 
    place[8][1] = 't';
    place[8][2] = 'u';
    place[8][3] = 'v';
 
    place[9][1] = 'w';
    place[9][2] = 'x';
    place[9][3] = 'y';
    place[9][4] = 'z';
    for(int i = 1; i <= 9; ++i){
        int t1;
        cin >> t1;
        push[t1] = i;
    }
    cin >> s;
    int last = 0;
    for(auto u: s){
        int i, j;
        for(i = 2; i <= 9; ++i) 
            for(j = 1; j <= 4; ++j) 
                if(place[i][j] == u)
                    goto END;
        END:;
        if(last == i)
            v.pb(-1);
        for(int k = 0; k < j; ++k)
            v.pb(i);
        last = i;
    }
    for(auto u : v){
        if(u == -1)
            cout << '#';
        else
            cout << push[u];
    }
}
