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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, m;
char a[3009][3009];
int ans;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    char x = 'A';
    char y = 'A';
    char z = 'A';
    int l = 0;
    int s = 0;
    int cont = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= m; ++j){
            if(j == m)
                cont = 0;
            for(int k = 0;k < s; ++k)
                if(a[i+k][j] != x)
                    cont = 0;
            for(int k = s; k < 2*s; ++k)
                if(a[i+k][j] != y)
                    cont = 0;
            for(int k = 2*s; k < 3*s; ++k)
                if(a[i+k][j] != z)
                    cont = 0;
            
            if(cont == 0){
                //cout << i << " " << j << " " << l << endl;
                ans += l*(l+1)/2;
                l = 0;
                if(j == m)
                    goto END;   
                x = a[i][j];
                int k;
                for(k = 1; a[i+k][j] == x; ++k)
                    if(i+k >= n)
                        goto END;
                if(i+k >= n)
                        goto END;
                s = k;
                y = a[i+s][j];
                for(k = s+1; k < 2*s; ++k)
                    if(a[i+k][j] != y || i+k >= n)
                        goto END;
                if(i+k >= n)
                        goto END;
                z = a[i+2*s][j];
                if(y == z) goto END;
                for(k = 2*s+1; k < 3*s; ++k)
                    if(a[i+k][j] != z || i+k >= n)
                        goto END;
                

                ++l;
                cont = 1;
            }
            else{
                ++l;
            }
            END:;
            //cout << i << " " << j << " " << x << y << z << endl;
            
        }
    cout << ans << endl;
}