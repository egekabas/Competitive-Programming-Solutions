#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[300005];
int b[300005];
map<pair<int,int>, int > mapp;
int n;

int cmp1(pair<int,int> x, pair<int,int> y ){
    if(x.first == y.first)
        return x.second > y.second; 
    return x.first < y.first;
}


int main(){
    cin >> n;
    int x, y;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        a[i] = make_pair(x, y);
        if(mapp[a[i]] != 0)
            mapp[make_pair(a[i].first-100000000,a[i].second-100000000)] = i;
        else
            mapp[a[i]] = i;

    }
    sort(a, a + n, cmp1);
    for(int i = 0;i < n; ++i )
        b[i] = a[i].second;
    int *tmp;
    for(int i = 0; i < n - 1; ++i){
        tmp = upper_bound(b+i+1,b+n,a[i].second);
        if(tmp != b + i + 1){
            if(a[tmp-1-b].first == a[i].first && a[tmp-1-b].second == a[i].second){
                cout << mapp[a[tmp-1-b]]+1 << " " << mapp[make_pair(a[i].first-100000000,a[i].second-100000000)]+1 ;
                return 0;
            }
            cout << mapp[a[tmp-1-b]]+1 << " " << mapp[a[i]]+1 ;
            return 0;
        }
    }
    cout << "-1 -1";
}