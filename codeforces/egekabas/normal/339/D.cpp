#include <bits/stdc++.h>
using namespace std;
int t[400009];
int n,m;
bool check = true;


void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
            if(check == true){
                t[v] = ((t[v*2]) | (t[v*2+1]));
                check = false;
                //cout << (t[v*2]) << " | " << (t[v*2+1]) << "  " << v << endl;
            }
            else{
                t[v] = ((t[v*2]) ^ (t[v*2+1]));
                check = true;
                //cout << (t[v*2]) << " ^ " << (t[v*2+1]) << "  " << v << endl;
            }
    }
}

int main(){
    cin >> n >> m;
    int s;
    for(int i = 0; i < (1<<n); ++i){
        cin >> s;
        update(1, 0, (1<<n)-1, i, s);
        check = true;
    }
    //cout << t[1] << endl;
    check = true;
    int p, b;
    for(int i = 0; i < m; ++i){
        cin >> p >> b;
        update(1, 0, (1<<n)-1, p-1, b);
        check = true;
        cout << t[1] << endl;
    }

}