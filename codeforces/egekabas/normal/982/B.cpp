#include <bits/stdc++.h>
using namespace std;
int n;
stack <int> hold;
char pas[400009];
pair <int, int> st[200009];

int calc(pair<int, int> a, pair<int, int> b){
    return (a.first < b.first);
}

int main(){
    cin >> n;
    int k;
    for(int i = 0; i < n; ++i){
        cin >> k;
        st[i].first = k;
        st[i].second = i+1;
    }
    sort(st, st + n, calc);
    cin >> pas;
    int beg = 0;
    for(int i = 0; i < 2*n; ++i){
        if(pas[i] == '0'){
            cout << st[beg].second << " ";
            hold.push(beg);
            ++beg;
        }
        if(pas[i] == '1'){
            int tmp = hold.top();
            hold.pop();
            cout << st[tmp].second << " ";
        }
    }


}