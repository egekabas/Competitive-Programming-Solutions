#include <bits/stdc++.h>
using namespace std;
vector <int> a((int) 1e6, 0);
int T, n, l;
int LIS(std::vector<int> &v) {
    int ans = (int) 1e9;
    if (v.size() == 0)
        return -1;
    vector<int> tail(n, 0);
    int length = 1;
    tail[0] = v[0];
    if(l == 1)
        ans = min(ans, v[0]);
    for (int i = 1; i < n; i++) {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > max(tail[length-1],tail[l-1])){
            tail[length++] = v[i];
            if(length == l)
                ans = min(ans, tail[--length]);
        }
        else{
            int tmp = upper_bound(tail.begin(), tail.begin() + length, v[i]) - tail.begin();
            if(tail[tmp-1] == v[i])
                continue;
            tail[tmp] = v[i];
            if (tmp == l-1)
                ans = min(ans, v[i]);
        }
        //cout << "==> ";
        //for(int x = 0; x < l; ++x)
        //    cout << tail[x] << " ";
        //cout << endl;

    }
    if(ans == (int)1e9)
        return -1;
    else
        return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        cin >> l;
        int ans = LIS(a);
        if(l > n)
            ans = -1;
        cout << ans << endl;
    }

}
