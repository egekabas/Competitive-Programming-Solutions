#include <bits/stdc++.h>
using namespace std;
map<string,int> mapp;
char s[1000];
int n;
int main(){
    cin >> n >> s;
    string tmp = "   ";
    for(int i = 0; i < n - 1; ++i){
        tmp[0] = s[i];
        tmp[1] = s[i+1];
        tmp[2] = '\0';
        ++mapp[tmp];
    }

    int ans;
    int big = 0;
    for(int i = 0; i < n - 1; ++i){
        tmp[0] = s[i];
        tmp[1] = s[i+1];
        tmp[2] = '\0';
        if(mapp[tmp] >= big){
            big = mapp[tmp];
            ans = i;
        }
    }
    cout << s[ans] << s[ans+1];
}