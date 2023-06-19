#include <bits/stdc++.h>
using namespace std;

int a1[200000+5];
int a2[200000+5];
string s;
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a1[i];
    cin >> s;
    for(int i = 0; i < n; ++i){
        a2[i] = s[i]-'0';
    }
    a2[n-1]=0;
    int begin = -1, end = -1;
    for(int i = 0; i < n; ++i){
        if(a2[i] == 1 && begin == -1){
            begin = i;
            end = -1;
        }
        else if(a2[i] == 0 && end == -1 && begin != -1){
            end = i;

    //        cout << begin << " " << end << "\n";

            sort(a1 + begin , a1 + end + 1);
            begin = -1;
        }
    }
    for(int i = 0; i<n; ++i)
        if(a1[i] != i+1){
            cout << "NO";
            return 0;
        }
    cout << "YES" << "\n";
    //for(int i = 0; i<n; ++i)
    //    cout << a1[i] << " ";
    return 0;
}