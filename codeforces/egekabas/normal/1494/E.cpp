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

int n, m;
map<int, int> mpp[200009];
int edge = 0;
int perf = 0;
void calc(int x, int y, int add){
    if(mpp[x][y] && mpp[y][x]){
        edge += add;
        if(mpp[x][y] == mpp[y][x])
            perf += add;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    while(m--){
        char type;
        cin >> type;
        if(type == '+'){
            int x, y;
            char c;
            cin >> x >> y >> c;
            mpp[x][y] = (c-'a'+1);
            calc(x, y, 1);
        }
        else if(type == '-'){
            int x, y;
            cin >> x >> y;
            calc(x, y, -1);
            mpp[x][y] = 0;
        }
        else{
            int k;
            cin >> k;
            if((k%2 && edge) || perf)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}