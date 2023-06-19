#include <bits/stdc++.h>
using namespace std;

int n, a[200009];
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        
        if(n == 1){
            if(a[0] <= 1)
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }

        int maxi1 = 0, maxi2 = 0;

        for(int i = 0; i < n; ++i){
            if(a[i] >= maxi1){
                maxi2 = maxi1;
                maxi1 = a[i];
            }
            else if(a[i] >= maxi2)
                maxi2 = a[i];
        }
        if(maxi1-maxi2 <= 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }   
}