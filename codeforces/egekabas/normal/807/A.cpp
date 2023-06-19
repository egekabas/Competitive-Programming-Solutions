#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n][2];
    for(int i = 0; i < n; ++i)
        cin >> arr[i][0] >> arr[i][1];
    int previous=5000;
    int maybe=0;
    for(int i = 0;i < n; ++i){
        if(arr[i][0] != arr[i][1]){
            cout << "rated";
            return 0;
        }
        if(arr[i][1] > previous)
            --maybe;
        previous = arr[i][1];
    }
    if(maybe == 0){
        cout << "maybe";
    }
    else
        cout << "unrated";
}