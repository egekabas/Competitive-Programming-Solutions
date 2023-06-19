#include <bits/stdc++.h>
using namespace std;

int n, m, q;
string big;
string small;
int que[100005][3];
int ar[1005];

int main(){
    cin >> n >> m >> q;
    cin >> big;
    cin >> small;
    for(int i = 0; i < q; ++i){
        cin >> que[i][0] >> que[i][1];
        --que[i][0];
        --que[i][1];

    }
    int cnt = 0;
    for(int i = 0; i < n - m + 1 ; ++i){
        string temp;
        temp = big.substr(i,m);
        if(!strcmp(temp.c_str(), small.c_str()))
            ++cnt;
        ar[i] = cnt;

    }
    //for(int i = 0; i < n - m + 1; ++i)
    //    cout << i << " " << ar[i] << endl;
    for(int i = 0; i < q; ++i){
        if(que[i][1]-que[i][0]+1<m)
            que[i][2] = 0;
        else
            que[i][2] = ar[que[i][1]-m+1] - ar[que[i][0]-1];

    }
    for(int i = 0; i < q; ++i)
        cout  <<  que[i][2] << endl;
}