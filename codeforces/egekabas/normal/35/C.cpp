#include <bits/stdc++.h>
using namespace std;
int n,m,k,maxi=0,cor[2];
pair<int,int> fire[10];
int diff(int a, int b){
    if(a>=b)return a-b;
    else return b-a;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> m >> n >> k;
    //if((n == 10 && m == 1) || (n == 1 && m == 10)) {
    //    cout << "1 1";
    //    return 0;
    //}
    int x,y;
    for(int i = 0; i < k ; ++i){
        cin >> x >> y;
        --x;
        --y;
        fire[i] = make_pair(x,y);
    }
    int tmp;
    for(int a = 0; a < n; ++a)
        for(int b = 0; b < m; ++b){
            tmp = 100000000;
            for(int i = 0; i < k; ++i){
                tmp = min(tmp, diff(fire[i].first,b) + diff(fire[i].second,a));
            }
            if(tmp >= maxi){
                maxi = tmp;
                cor[1] = b;
                cor[0] = a;
            }
        }
    cout << cor[1]+1 << " " << cor[0]+1 << endl;
}