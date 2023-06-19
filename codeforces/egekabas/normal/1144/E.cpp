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
int k;
int s[200009];
int t[200009];
int arr[200009];
int fin[200009];
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    char c;
    cin >> k;
    for(int i = 0; i < k; ++i){
        cin >> c;
        s[i] = c - 'a';
    }
    for(int i = 0; i < k; ++i){
        cin >> c;
        t[i] = c - 'a';
    }
    for(int i = k-1; i >= 0; --i)
        arr[i] = s[i] + t[i];
    int tmp = 0;
    for(int i = 0; i < k; ++i){
        tmp += arr[i];
        fin[i] = tmp/2;
        tmp = (tmp%2)*26;
    }
    for(int i = k-1; i >= 1; --i){
        fin[i-1] += fin[i]/26;
        fin[i] %= 26;
    }
    for(int i = 0; i < k; ++i)
        cout << (char)(fin[i]+'a');
}