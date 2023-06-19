#include <bits/stdc++.h> //3 2 1
#define ff first
#define ss second
#define mp make_pair
using namespace std;
long long n;
long long a[1000009];
long long b[1000009];
long long f1[1000009];
long long f2[1000009];
map<long long, long long> m;
void upd(long long f[],long long x,long long val) {
	for(;x<=1000000;x+=x&-x)
		f[x]+=val;
}
long long que(long long f[],long long x) {
	long long ret=0;
	for(;x;x-=x&-x)
		ret+=f[x];
	return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(long long i = 0; i < n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    for(long long i = 0; i < n; ++i)
        m[b[i]] = i+1;
    for(long long i = 0; i <n; ++i)
        upd(f1, m[a[i]], 1);
    long long ans = 0;
    for(long long i = 0; i < n-1; ++i){
        upd(f1, m[a[i]], -1);
        ans += que(f1, m[a[i]])*(i - que(f2,m[a[i]]));
        upd(f2, m[a[i]], 1);
    }
    cout << ans;

}