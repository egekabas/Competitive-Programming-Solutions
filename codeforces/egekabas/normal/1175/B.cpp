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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ull overflow = ((ull)1<<(ull)32) - 1;
stack<ull> s;
ull mult = 1;
ull cnt = 0;
ull tmp;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    ull lines;
    cin >> lines;
    string str;
    while(lines--){
        cin >> str;
        if(str == "add")
            cnt += mult;
        else if(str == "for"){
            cin >> tmp;
            mult *= tmp;
            s.push(tmp);
        }
        else if(str == "end"){
            mult /= s.top();
            s.pop();
        }
        if(mult > overflow){
            ull tmp2 = 1;
            while(lines-- && tmp2 > 0){
                cin >> str;
                if(str ==  "add"){
                    cout << "OVERFLOW!!!" << endl;
                    return 0;
                }
                else if(str ==  "end")
                    --tmp2;
                else if(str == "for"){
                    cin >> tmp;
                    ++tmp2;
                }                
            }
            mult /= s.top();
            s.pop();
            ++lines;
        }
        if(cnt > overflow){
            cout << "OVERFLOW!!!" << endl;
            return 0;
        }
   }
   cout << cnt << endl;
}