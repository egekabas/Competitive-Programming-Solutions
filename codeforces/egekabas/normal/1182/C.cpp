#include <bits/stdc++.h>
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
struct word{
    int last, tot;
    string s;
};
char vow[] = {'a', 'e', 'i', 'o', 'u'};
word transform(string s){
    char c = 0; int count = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'){
            c = s[i]-'a';
            ++count;
        }
    }
    return {c, count, s};
}
void out(pair<word, word> p1, pair<word, word> p2){
    cout << p1.ff.s << " " << p2.ff.s << endl;
    cout << p1.ss.s << " " << p2.ss.s << endl;
}
vector<word> v, imp;
vector<pair<word, word>> perf;
vector<pair<word, word>> imperf;
int func(word a, word b){
    if(a.tot != b.tot) return a.tot < b.tot;
    else return a.last < b.last;
}
int n;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n;
    string s; word tmp;
    for(int i = 0; i < n; ++i){
        cin >> s;
        tmp = transform(s);
        v.pb(tmp);    
    }
    sort(v.begin(), v.end(), func);
    for(int i = 0; i < v.size(); ++i){
        if(i != v.size()-1 && v[i].tot == v[i+1].tot && v[i].last ==v[i+1].last){
            perf.pb({v[i], v[i+1]});
            //cout << v[i].s << " " << v[i+1].s << endl;
            ++i;
        }
        else{
            //cout << v[i].s << endl;
            imp.pb(v[i]);
        }
    }
    sort(imp.begin(), imp.end(), func);
    for(int i = 0; i < imp.size(); ++i){
        if(i != imp.size()-1 && imp[i].tot == imp[i+1].tot){
            imperf.pb({imp[i], imp[i+1]});
            ++i;
        }
    }
    cout << min(imperf.size(), perf.size())+(perf.size()-min(imperf.size(), perf.size()))/2
    << endl;
    int i = 0; int j = 0;
    while(i != perf.size()){
        if(j == imperf.size()){
            if(i == perf.size()-1) break;
            out(perf[i], perf[i+1]);
            i+=2;
        }
        else{
            out(imperf[j], perf[i]);
            ++i; ++j;
        }
    }
}