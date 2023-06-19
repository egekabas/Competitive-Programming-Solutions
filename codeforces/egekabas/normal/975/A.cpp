#include <bits/stdc++.h>
using namespace std;
int n;

string arr[1009];
map <char,bool> roots[1009];
map<int,bool>final ;
int value[1009];


int main(){
    cin >> n;
    int i,x,y;
    for(i = 0; i < n; ++i)
        cin >> arr[i];
    for(i = 0; i < n; ++i)
        for(x = 0; arr[i][x] != '\0'; ++x)
            if(roots[i][arr[i][x]] == false ){
                roots[i][arr[i][x]] = true;
                value[i] += (arr[i][x]-'a'+199)*(arr[i][x]-'a'+199)*(arr[i][x]-'a'+199)*(arr[i][x]-'a'+199);
            }
    int result = n;
    for(x=0; x<n ; ++x){
        if(final[value[x]]==true)
            --result;
        else
            final[value[x]]=true;
    }
    cout << result;
}