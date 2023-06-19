#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
void fin(int a, int b){
    while(a > 0){
        --a;
        cout << "0";
    }
    while(b > 0){
        --b;
        cout << "1";
    }

    exit(0);
}


int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    string s, t;
    cin >> s >> t;
    int pr = 0;
    for(int i = 1;t[i] != '\0'; ++i){
        if(t[i] == t[pr]) ++pr;
        else if(t[i] == t[0]) pr = 1;
        else pr = 0; 
    }
    int ones = 0;
    int zeros = 0;
    for(int i = 0; s[i] != '\0'; ++i){
        if(s[i] == '0') ++zeros;
        else if(s[i] == '1') ++ones;
    }

    for(int i = 0; t[i] != '\0'; ++i){
        if(t[i] == '0' && zeros > 0){
            cout << "0";
            --zeros;
        }
        else if(t[i] == '1' && ones > 0){
            cout << "1";
            --ones;
        }
        else{
            fin(zeros, ones);
        }
    }

    while(true){
        for(int i = pr; t[i] != '\0'; ++i){
            if(t[i] == '0' && zeros > 0){
                cout << "0";
                --zeros;
            }
            else if(t[i] == '1' && ones > 0){
                cout << "1";
                --ones;
            }
            else
                fin(zeros, ones);
        }    
    }
}