#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[500009];
vector<int> t[500009];

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int len = (int) sqrt(n + .0) + 1;
    int numBlocks = ceil((double)n/len);

    for(int i = 0; i < n; ++i)
        t[i/len].push_back(a[i]);
    for(int i = 0; i < numBlocks; ++i)
        sort(t[i].begin(), t[i].end());

    int k, x, y, z;
    cin >> q;
    while(q--){
        cin >> k;
        if(k == 0){
            cin >> x >> y >> z;
            --x;
            --y;
            int ans = 0;
            for(int i = x; i <= y;){
                if(i % len == 0 && i + len - 1 <= y){
                    ans += t[i/len].end() - lower_bound(t[i/len].begin(), t[i/len].end(), z);
                    i += len;
                }
                else{
                    if(a[i] >= z)
                        ++ans;
                    ++i;
                }
            }
            cout << ans << endl;
        }
        if(k == 1){
            cin >> x >> y;
            --x;
            auto it = lower_bound(t[x/len].begin(), t[x/len].end(), a[x]);
            *it = y;
            sort(t[x/len].begin(), t[x/len].end());
            a[x] = y;
        }
    }
}
