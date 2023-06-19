#include <bits/stdc++.h>
using namespace std;
long long n, m;
pair<long double, long double> par[100009];
long long maxi, mini;
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
        cin >> par[i].first >> par[i].second;
    if(n % 2 == 1){
        maxi = n*(n-1)/2;
        mini = (n+1)/2*(n-1)/2;
    }
    if(n % 2 == 0){
        maxi = n*(n-1)/2;
        mini = n/2*(n/2-1)/2 + n/2*(n/2+1)/2;
    }
    long double answer = 0;
    for(int i = 0; i < m; ++i){
        answer += par[i].first*n;
        answer += max(par[i].second*maxi, par[i].second*mini) ;
    }
    answer = answer/n;
    cout << setprecision(10) << fixed << answer;

}