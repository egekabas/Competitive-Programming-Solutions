#include <bits/stdc++.h>
using namespace std;
int n, x;
pair<int,int> a[2000009];
int cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){
    cin >> n >> x;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = 0;
    }
    int o = n;
    for(int i = 0; i < n; ++i){
        if(a[i].first != (a[i].first&x)){
            a[o].first = ((a[i].first)&x);
            a[o].second = 1;
            ++o;
        }
    }

    sort(a, a+o, cmp);

    //for(int i =0; i < o; ++i)
    //   cout << a[i].first << " " << a[i].second << endl;

    int hold = 10;
    for(int i = 1; i < o; ++i){
        if(a[i].first == a[i-1].first){
            hold = min(hold, a[i].second + a[i-1].second);
            //cout << a[i].first << " " <<  a[i-1].first << endl;
        }
    }
    if(hold == 10)
        cout << -1;
    else
        cout << hold;

}