#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
struct edge{
	ll w, c, leaf;
};
ll n, s;
vector<pii> g[100009];
edge e[100009];
ll curcost;
void dfs(ll v, ll prt){
	e[prt].leaf = 0;
	for(auto u : g[v])
		if(u.ss != prt){
			dfs(u.ff, u.ss);
			e[prt].leaf += e[u.ss].leaf;
		}
	if(v != 1 && g[v].size() == 1)
		e[prt].leaf = 1;
	curcost += e[prt].leaf*e[prt].w;
}
int sf(int x, int y){
	return e[x].leaf*(e[x].w-e[x].w/2) > e[y].leaf*(e[y].w-e[y].w/2);
}
vector<int> v[2];
vector<ll> go(ll val){
	ll cur = 0;
	set<pll, greater<pll>> s;
	for(ll i = 0; i < n-1; ++i)
		if(e[i].c == val){
			s.insert({e[i].leaf*(e[i].w-e[i].w/2), i});
			cur += e[i].leaf*e[i].w;
		}
	vector<ll> ret;
	ret.pb(cur);
	while(s.size() && s.begin()->ff){
		int idx = s.begin()->ss;
		cur -= s.begin()->ff;
		s.erase(s.begin());
		ret.pb(cur);
		e[idx].w /= 2;
		s.insert({e[idx].leaf*(e[idx].w-e[idx].w/2), idx});
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	ll t;
	cin >> t;
	while(t--){
		cin >> n >> s;
		for(ll i = 1; i <= n; ++i)
			g[i].clear();
		for(ll i = 0; i < n-1; ++i){
			ll x, y;
			cin >> x >> y;
			cin >> e[i].w >> e[i].c;
			g[x].pb({y, i});
			g[y].pb({x, i});
		}
		dfs(1, 1e5+3);
		vector<ll> v1 = go(1), v2 = go(2);
		ll ans = 1e18;
		ll idx = v2.size()-1;
		for(ll i = 0; i < v1.size(); ++i){
			while(idx > 0 && v1[i]+v2[idx-1] <= s) --idx;
			if(v1[i]+v2[idx] <= s)
				ans = min(ans, i+2*idx);
		}
		cout << ans << '\n';
	}
	
}