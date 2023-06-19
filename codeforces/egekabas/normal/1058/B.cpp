#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;
int n, d, m;

int main(){
    cin >> n >> d;
    cin >> m;
    int x, y;
    while(m--){
        cin >> x >> y;
        if(y >= abs(x-d)){
            if(x+d <= n){
                if(y <= x+d){
                    cout << "YES\n";
                    continue;
                }
                else{
                    cout << "NO\n";
                    continue;
                }
            }
            else{
                if(y <= 2*n-x-d){
                    cout << "YES\n";
                    continue;
                }
                else{
                    cout << "NO\n";
                    continue;
                }
            }
        }
        else{
            cout << "NO\n";
            continue;
        }
    }
}