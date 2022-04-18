#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int dig(int x, int y){
    cout << "DIG " << x << ' ' << y << endl;
    int ret;
    cin >> ret;
    return ret;
}
int scan(int x, int y){
    cout << "SCAN " << x << ' ' << y << endl;
    int ret;
    cin >> ret;
    return ret;
}
int n, m;
void calc(){
    cin >> n >> m;

    int posall = scan(1, 1)+4;
    int negxposy = scan(n, 1)+2-2*n;

    int sumy = (posall+negxposy)/2;
    int sumx = posall-sumy;

    
    int difx = scan(sumx/2, 1)-(sumy-2);
    int x1 = (sumx+difx)/2;
    int x2 = sumx-x1;

    int dify = scan(1, sumy/2)-(sumx-2);
    int y1 = (sumy+dify)/2;
    int y2 = sumy-y1;
    


    if(dig(x1, y1))
        dig(x2, y2);
    else{
        dig(x1, y2);
        dig(x2, y1);
    }

}


int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--)
        calc();
}