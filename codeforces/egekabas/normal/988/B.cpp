#include <bits/stdc++.h>
using namespace std;
int n;
string arr[100];
int cmp(string a, string b){
    return (a.length() < b.length());
}

bool in(string a, string b){
    int x = b.find(a);
    if(x == -1)
        return 0;
    else
        return 1;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n-1; ++i){
        if(!in(arr[i], arr[i+1])){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; ++i)
        cout << arr[i] << endl;
}