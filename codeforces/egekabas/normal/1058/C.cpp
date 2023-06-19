#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;
int n;
int b[109];

int main(){
    cin >> n;
    char c;
    for(int i = 0; i < n; ++i){
        cin >> c;
        b[i] = (int)c - (int)'0';
    }

    int ctrl = 0, val = 0, x = 0;
    for(int i = 0; i < n-1; ++i){
        val += b[i];
        x = 0;
        ctrl = 0;
        for(int j = i+1; j < n; ++j){
            x += b[j];
            ctrl = 0;
            if(x == val){
                if(j == n-1 || b[j+1] != 0){
                    x = 0;
                    ctrl = 1;
                }
            }
            if(j == n-1){
                if(x == 0 && ctrl == 1){
                    cout << "YES\n";
                    return 0;
                }
            }
            else if(x > val)
                break;
        }
    }
    cout << "NO\n";
}