#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int n, k, m;

int lazy[1600009];
int seg[1600009];
void push(int v){
	lazy[2*v] += lazy[v];
	lazy[2*v+1] += lazy[v];
	seg[2*v] += lazy[v];
	seg[2*v+1] += lazy[v];
	lazy[v] = 0;
}
void build(int v, int tl, int tr){
	if(tl == tr){
		seg[v] = n-tl+1;
		return;
	}
	build(2*v, tl, (tl+tr)/2);
	build(2*v+1, (tl+tr)/2+1, tr);
	seg[v] = min(seg[2*v], seg[2*v+1]);
}
void upd(int v, int tl, int tr, int l, int r, int val){
	if(r < tl || l > tr)
		return;
	else if(l <= tl && tr <= r){
		seg[v] += val;
		lazy[v] += val;
	}
	else{
		push(v);
		int tm = (tl+tr)/2;
		upd(2*v, tl, tm, l, r, val);
		upd(2*v+1, tm+1, tr, l, r, val);
		seg[v] = min(seg[2*v], seg[2*v+1]);
	}
}
int get(int v, int tl, int tr, int l, int r){
	if(r < tl || l > tr)
		return 1e9;
	else if(l <= tl && tr <= r)
		return seg[v];
	else{
		push(v);
		int tm = (tl+tr)/2;
		return min(get(2*v, tl, tm, l, r), get(2*v+1, tm+1, tr, l, r));
	}
}
multiset<int, greater<int>> s;
map<pii, int> mpp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

	cin >> n >> k >> m;
	build(1, 1, 2*n);
	while(m--){
		int x, y;
		cin >> x >> y;
		int dis = abs(x-k)+y;
		if(mpp[{x, y}]){
			mpp[{x, y}] = 0;
			s.erase(s.lower_bound(dis));
			upd(1, 1, 2*n, 1, dis, 1);
		}
		else{
			mpp[{x, y}] = 1;
			s.insert(dis);
			upd(1, 1, 2*n, 1, dis, -1);
		}
		int ans = max(0, -get(1, 1, 2*n, 1, *s.begin()));
		cout << ans << '\n';
	}
}