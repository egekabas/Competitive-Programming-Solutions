#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,m,i,k;
vector<pii> bases;
pii hehe;
vector<int> powers;
int arr[(int)1e6];

bool func(pii e,pii r){
    return r.ff > e.ff;
}

bool comp(pii e,int i){
    return e.ff < powers[i];
}


int main(){ 

ios_base::sync_with_stdio(false);
cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;

    for(i=0;i<n;i++){
        cin >> k;
        powers.pb(k);
    }

    for(i = 0 ; i < m ; i++){
        cin >> hehe.ff;
        cin >> hehe.ss;
        bases.pb(hehe); 
    }

    sort(bases.begin(),bases.end(),func);
    


    for(i=0;i<m;i++){
        arr[i+1] = arr[i]+bases[i].ss;
    }


    for(i = 0; i < n ; i++){

    auto up = upper_bound(bases.begin(),bases.end(),make_pair(powers[i],INT_MAX));
    cout << arr[up-bases.begin()] << " ";
    }


}