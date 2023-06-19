#include <bits/stdc++.h>
using namespace std;
int n;
int tmp, hold;
int ar[100005];
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> ar[i];
    int col = -1;
    for(int i = 0; i < n; ++i){
        if(col != ar[i]){
            col = ar[i];
            if(tmp != hold && hold != 0){
                cout << "NO ";
                return 0;
            }
            hold = tmp;
            tmp = 1;
        }
        else
            ++tmp;
    }
    if(tmp != hold && hold != 0){
        cout << "NO ";
        return 0;
    }
    cout << "YES";
    return 0;
}