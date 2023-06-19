#include <bits/stdc++.h>
using namespace std;
long long n,k,m;
vector<int> temp;
map<string,long long> str_int;
int main(){
    vector<string>ve(int(1e5 +5));
    vector<long long>costs(int(1e5 +5));
    cin >> n >> k >> m;
    for(int i=0;i<n;++i)
        cin >> ve[i];
    for(int i=0;i<n;++i)
        cin >> costs[i];
    long long x,y,min;
    for(int i=0;i<k;++i){
        cin >> x;
        min=10000000000;
        for(int k=0;k<x;++k){
            cin >> y;
            --y;
            if(costs[y]<=min)
                min = costs[y];
            temp.push_back(y);
        }
        for(int i=0;i<x;++i)
            str_int[ve[temp[i]]]=min;
        temp.clear();
    }
    string s;
    long long result=0;
    for(int i=0;i<m;++i){
        cin >> s;
        result += str_int[s];
    }
    cout << result;
}