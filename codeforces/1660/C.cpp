#include <bits/stdc++.h>
using namespace std;
const int sz = 'z'-'a'+1;

int ar[sz];

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        for(int i = 0; i < sz; ++i)
            ar[i] = 0;

        int ans = 0;

        for(auto u : s){
            int val = u-'a';
            if(ar[val] == 1){
                ans += 2;
                for(int i = 0; i < sz; ++i)
                    ar[i] = 0;
            }
            else
                ar[val] = 1;
        }

        cout << s.size()-ans << '\n';

    }
}
