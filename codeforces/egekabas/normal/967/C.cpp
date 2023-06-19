#include <bits/stdc++.h>
using namespace std;
long long n,m,l,e,v,q;
long long lad[100009];
long long el[100009];
long long quer[100009][4];
long long diff(long long a, long long b){
    if(a >= b)
        return a-b;
    else
        return b-a;
}
long long solvel(long long y1, long long x1, long long y2, long long x2){
    if(x1 > lad[l-1])
        return diff(x1, lad[l-1]) + diff(x2, lad[l-1]) + diff(y1,y2);
    if(x1 < lad[0])
        return diff(x1, lad[0]) + diff(x2, lad[0]) + diff(y1,y2) ;
    long long *tmp1, *tmp2, result=0;
    tmp1 = upper_bound(lad, lad + l - 1, x1);
    tmp2 = lower_bound(lad, lad + l - 1, x1);
    --tmp1;
    result += min(diff(*tmp1,x1) + diff(*tmp1,x2), diff(*tmp2,x1) + diff(*tmp2,x2));
    result += diff(y2,y1);
    return result;
}
long long solvee(long long y1, long long x1, long long y2, long long x2){
    if(x1 > el[e-1])
        return diff(x1, el[e-1]) + diff(x2, el[e-1]) +  (diff(y1,y2) +v-1)/v;
    if(x1 < el[0])
        return diff(x1, el[0]) + diff(x2, el[0]) +  (diff(y1,y2) +v-1)/v;

    long long *tmp1, *tmp2, result=0;
    tmp1 = upper_bound(el, el + e - 1, x1);
    tmp2 = lower_bound(el, el + e - 1, x1);
    --tmp1;
    result += min(diff(*tmp1,x1) + diff(*tmp1,x2), diff(*tmp2,x1) + diff(*tmp2,x2));
    result += (diff(y2,y1) + v - 1)/v;
    return result;
}

long long solve(long long y1, long long x1, long long y2, long long x2){
    if(y1 == y2)
        return diff(x1, x2);
    if(l==0)
        return solvee(y1, x1, y2, x2);
    if(e==0)
        return solvel(y1, x1, y2, x2);
    return min(solvee(y1, x1, y2, x2), solvel(y1, x1, y2, x2));
}

int main(){
    cin >> n >> m >> l >> e >> v;
    for(long long i = 0; i < l; ++ i)
        cin >> lad[i];
    for(long long i = 0; i < e; ++ i)
        cin >> el[i];
    cin >> q;
    for(long long i = 0; i < q; ++ i )
        cin >> quer[i][0] >> quer[i][1] >> quer[i][2] >> quer[i][3];
    for(long long i = 0; i < q; ++ i )
        cout << solve(quer[i][0],quer[i][1],quer[i][2],quer[i][3]) << endl;
}