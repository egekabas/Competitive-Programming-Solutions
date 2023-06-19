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

int n;
int a[100009];
int b[100009];
int ans0[100009];
int ans1[100009];
int ans2[100009];
int ans3[100009];

int main(){
    cin >> n;
    for(int i = 0; i < n-1; ++i)
        cin >> a[i];
    for(int i = 0; i < n-1; ++i)
        cin >> b[i];
    bool one = 1;
    bool two = 1;
    bool three = 1;
    bool zero = 1;
    ans0[n-1] = 0;
    ans1[n-1] = 1;
    ans2[n-1] = 2;
    ans3[n-1] = 3;
    for(int i = n-2; i >= 0; --i){
        if(a[i] < b[i]){
            cout << "NO\n";
            return 0;
        }
        int tmp = -1;
        for(int j = 0; j < 4; ++j){
            if( ((j|ans0[i+1]) == a[i]) && ((j&ans0[i+1]) == b[i]) ){
                ans0[i] = j;
                tmp = 1;
            }
        }
        if(tmp == -1){
            zero = 0;
        }
        tmp = -1;
        for(int j = 0; j < 4; ++j){
            if( ((j|ans1[i+1]) == a[i]) && ((j&ans1[i+1]) == b[i])){
                ans1[i] = j;
                tmp = 1;
            }
        }
        if(tmp == -1){
            one = 0;
        }
        tmp = -1;
        for(int j = 0; j < 4; ++j){
            if(((j|ans2[i+1]) == a[i]) && ((j&ans2[i+1]) == b[i])){
                ans2[i] = j;
                tmp = 1;
            }
        }
        if(tmp == -1){
            two = 0;
        }
        tmp = -1;
        for(int j = 0; j < 4; ++j){
            if(((j|ans3[i+1]) == a[i]) && ((j&ans3[i+1]) == b[i])){
                ans3[i] = j;
                tmp = 1;
            }
        }
        if(tmp == -1){
            three = 0;
        }
    }
    if(zero){
        cout << "YES\n";
        for(int i = 0; i < n; ++i){
            cout << ans0[i] << " ";
        }
    }
    else if(one){
        cout << "YES\n";
        for(int i = 0; i < n; ++i){
            cout << ans1[i] << " ";
        }
    }
    else if(two){
        cout << "YES\n";
        for(int i = 0; i < n; ++i){
            cout << ans2[i] << " ";
        }
    }
    else if(three){
        cout << "YES\n";
        for(int i = 0; i < n; ++i){
            cout << ans3[i] << " ";
        }
    }
    else{
        cout << "NO\n";
    }
}