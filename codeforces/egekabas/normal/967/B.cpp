#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int sizes[100009];
int si;
void reverse(int arr[]){
    int temp;
    for(int  i = 0; i < (n - 2)/2; ++i){
        temp = arr[n - 2 - i];
        arr[n - 2 - i] = arr[i];
        arr[i] = temp;
    }
}
int main(){
    cin >> n >> a >> b;
    cin >> si;
    for(int i = 0; i < n - 1; ++i)
        cin >> sizes[i];
    sort(sizes , sizes + n - 1);
    reverse(sizes);
    //cout << sizes[0] << endl;
    int sum = si;
    for(int i = 0; i < n - 1; ++i)
        sum += sizes[i];
    //cout << sum << endl;
    if((si*a)/sum >= b){
        cout << 0 ;
        return 0;
        }

    for(int i = 0; i < n - 1; ++i){
        sum -= sizes[i];
        if((si*a)/sum >= b){
            cout << i + 1;
            return 0;
        }
    }
}