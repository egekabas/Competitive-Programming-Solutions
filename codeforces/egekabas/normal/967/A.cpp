#include <bits/stdc++.h>
using namespace std;
int n,s;
int arr[100];
int gaps[100];
int main(){
    cin >> n >> s;
    int h,m;
    for(int i = 0; i < n; ++ i){
        cin >> h >> m;
        arr[i] = h*60 + m;
    }
    gaps[0] = arr[0];
    int ans;
    for(int i = 1; i < n; ++ i)
        gaps[i] = arr[i] - arr[i-1];
    int i;
    if(gaps[0] >= s + 1){
        cout << 0 << " " << 0;
        return 0;
    }
    for( i = 1; i < n; ++ i)
        if(gaps[i] >= 2*s + 2){
            ans = arr[i-1] + s + 1;
            cout << ans/60 << " " << ans%60;
            return 0;
        }
    ans = arr[n-1] + s + 1;
    cout << ans/60 << " " << ans%60;

}