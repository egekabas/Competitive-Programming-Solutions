#include <bits/stdc++.h>
using namespace std;
map<int, int> bits[100009];
map<int, int> who;
void update(int number, int idx, int r){
    while(idx <= int(1e9)){
        bits[number][idx] += r;
        idx += (idx&(-idx));
    }
}
int sum(int number, int idx){
    int x = 0;
    while(idx > 0){
        x += bits[number][idx];
        idx -= (idx & (-idx));
    }
    return x;
}

int main(){
    int n;
    int x, y, z;
    cin >> n;
    int count = 1;
    for(int i = 0; i < n; ++i){
        cin >> x >> y >> z;
        if(who[z] == 0){
            who[z] = count;
            ++count;
        }
        if(x == 1)
            update(who[z], y, 1);
        else if(x == 2)
            update(who[z], y, -1);
        else if(x == 3)
            cout << sum(who[z], y) << endl;
    }
}