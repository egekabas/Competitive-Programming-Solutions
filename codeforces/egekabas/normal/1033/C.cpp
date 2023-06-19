#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;

int b[100009];
int n;
int func[100009];

int dp(int l){
    if(func[l] != -1)
        return func[l];
    for(int i = l-b[l]; i >= 0; i -= b[l]){
        //cout << b[l] <<" "<< b[i] << endl;
        if(b[i] > b[l] && dp(i) == 0){
            func[l] = 1;
            return 1;
        }
    }
    for(int i = l+b[l]; i < n; i += b[l]){
        if(b[i] > b[l] && dp(i) == 0){
            func[l] = 1;
            return 1;
        }
    }
    func[l] = 0;
    return 0;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    for(int i = 0; i < n; ++i){
        if(b[i] == n){
            func[i] = 0;
            break;
        }
    }
    for(int i = 0; i < n; ++i)
        func[i] = -1;
    for(int i = 0; i < n; ++i){
        if(!dp(i))
            cout << "B";
        else
            cout << "A";
    }
}