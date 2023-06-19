#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int query(string s);
int N;
string calc(int l, int r){
    if(l == r){
        string tmp;
        for(int i = 0; i < N; ++i)
            tmp.pb('a'+l);
        int cnt = query(tmp);
        return tmp.substr(0, cnt);
    }
    else{
        int m = (l+r)/2;
        string s1 = calc(l, m);
        string s2 = calc(m+1, r);
        string s;
        reverse(s1.begin(), s1.end());
        while(s1.size() || s2.size()){
            if(s1.empty()){
                s += s2;
                break;
            }
            if(s2.empty()){
                reverse(s1.begin(), s1.end());
                s += s1;
                break;
            }
            if(query(s+s1.back()+s2) == s.size()+s2.size()+1){
                s += s1.back();
                s1.pop_back();
            }
            else{
                reverse(s2.begin(), s2.end());
                s += s2.back();
                s2.pop_back();
                reverse(s2.begin(), s2.end());
            }
        }
        return s;
    }
}
 
string guess(int n, int s){
    N = n;
    return calc(0, s-1);
}
