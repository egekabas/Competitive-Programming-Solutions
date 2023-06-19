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
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
struct st{
	set<pii> s;
	void add(pii x){
		auto it = s.lower_bound({x.ff, 1e9});
		if(it != s.begin() && (--it)->ss >= x.ss)
			return;
		while((it = s.lower_bound({x.ff, 0})) != s.end()){
			if(it->ss <= x.ss)
				s.erase(it);
			else
				break;
		}
		s.insert(x);
	}
	int querry(int x){
		auto it = s.lower_bound({x, 0});
		if(it == s.begin()) return 0;
		return (--it)->ss;
	}
};
pii a[3009];
vector<int> g[3009];
int vis[3009];
int cnt[3009];
vector<int> ord;
void top(int v){
	vis[v] = 1;
	for(auto u : g[v])
		if(vis[u] == 0)
			top(u);
	ord.pb(v);
}

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i].ff >> a[i].ss;
		vis[i] = 0;
		g[i].clear();
	}
	++n;
	a[n-1] = {-1e9, 1e9};
	vis[n-1] = 0;
	g[n-1].clear();
	sort(a, a+n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(i != j && a[i].ff <= a[j].ff && a[j].ss <= a[i].ss)
				g[i].pb(j);
	ord.clear();
	for(int i = 0; i < n; ++i)
		if(vis[i] == 0)
			top(i);
	int ans = 0;
	for(auto v : ord){
		st s;
		cnt[v] = 0;
		for(auto u : g[v]){
			int cur = cnt[u]+s.querry(a[u].ff);
			cnt[v] = max(cnt[v], cur);
			s.add({a[u].ss, cur});
		}
		cnt[v]++;
		ans = max(ans, cnt[v]);
	}
	cout << ans-1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--){
		solve();
	}
}