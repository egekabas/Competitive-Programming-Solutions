#include <bits/stdc++.h>
#include <string> 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int l;
string s;

string top(string x, string y){
    string ans;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    auto it1 = x.begin();
    auto it2 = y.begin();
    int elde = 0;
    int tmp;
    while(it1 != x.end() && it2 != y.end()){
        tmp = *it1-'0'+*it2-'0';
        tmp += elde;
        elde = tmp/10;
        ans.push_back((char)tmp%10+'0');
        ++it1; ++it2;
    }
    if(it1 == x.end()){
        while(it2 != y.end()){
            tmp = *it2-'0';
            tmp += elde;
            elde = tmp/10;
            ans.push_back((char)tmp%10+'0');
            ++it2;
        }
    }
    else if(it2 == y.end()){
        while(it1 != x.end()){
            tmp = *it1-'0';
            tmp += elde;
            elde = tmp/10;
            ans.push_back((char)tmp%10+'0');
            ++it1;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
string mini(string x, string y){
    if(x.size() > y.size()){
        return y;
    }
    else if(x.size() < y.size()){
        return x;
    }
    auto it1 = x.begin();
    auto it2 = y.begin();
    while(it1 != x.end()){
        if(*it1 > *it2)
            return y;
        if(*it1 < *it2)
            return x;
         ++it1, ++it2;
    }
    return x;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> l;
    cin >> s;
    int it1 = (l/2);
    int it2 = (l/2);    
    while(s[it1] == '0') --it1;
    while(s[it2] == '0') ++it2;
    string s1 = s.substr(0, it1);
    string s2 = s.substr(it1, s.size()-it1);
    string a1 = top(s1, s2);
    
    string s3 = s.substr(0, it2);
    string s4 = s.substr(it2, s.size()-it2);
    string a2 = top(s3, s4);
    
    ++l;
    it1 = (l/2);
    it2 = (l/2);    
    while(s[it1] == '0') --it1;
    while(s[it2] == '0') ++it2;
    string s5 = s.substr(0, it1);
    string s6 = s.substr(it1, s.size()-it1);
    string a3 = top(s5, s6);

    string s7 = s.substr(0, it2);
    string s8 = s.substr(it2, s.size()-it2);
    string a4 = top(s7, s8);
    //cout << a1 << " " << a2 << " " << a3 << " " << a4 <<endl;
    cout << mini(mini(a1, a2),mini(a3, a4));
}