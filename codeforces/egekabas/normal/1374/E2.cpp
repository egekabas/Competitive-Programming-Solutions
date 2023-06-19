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
int n, m, k;
vector<pii> a, b, both, none;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i){
		int ti, ai, bi;
		cin >> ti >> ai >> bi;
		if(ai && bi)
			both.pb({ti, i});
		else if(ai)
			a.pb({ti, i});
		else if(bi)
			b.pb({ti, i});
		else
			none.pb({ti, i});
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(none.begin(), none.end());
	sort(both.begin(), both.end());
	int ans = 2e9+9;
	int ansa, ansb, ansnone, ansboth;
	int curans = 0;
	for(int i = 0; i < min(m, int(both.size())); ++i)
		curans += both[i].ff;
	int ai, bi, nonei;
	ai = bi = nonei = 0;
	for(int bothi = min(m, int(both.size())); bothi >= 0; --bothi){
		if(bothi != min(m, int(both.size())))
			curans -= both[bothi].ff;
		
		while(ai+bothi < k && ai != a.size()){
			curans += a[ai].ff;
			++ai;
		}
		while(bi+bothi < k && bi != b.size()){
			curans += b[bi].ff;
			++bi;
		}

		if(ai + bothi < k || bi + bothi < k)
			break;
		while(ai+bothi+bi+nonei > m && nonei > 0){
			--nonei;
			curans -= none[nonei].ff;
		}

		while(ai+bothi+bi+nonei < m){
			if(ai != a.size() && (bi == b.size() || a[ai].ff <= b[bi].ff) && (nonei == none.size() || a[ai].ff <= none[nonei].ff)){
				curans += a[ai].ff;
				++ai;
			}
			else if(bi != b.size() && (nonei == none.size() || b[bi].ff <= none[nonei].ff)){
				curans += b[bi].ff;
				++bi;
			}
			else if(nonei != none.size()){
				curans += none[nonei].ff;
				++nonei;
			}
			else
				break;
		}
		
		if(ai+bothi+bi+nonei != m)
			continue;
		if(curans <= ans){
			ans = curans;
			ansa = ai;
			ansb = bi;
			ansboth = bothi;
			ansnone = nonei;
		}
	}
	if(ans == 2e9+9){
		cout << -1;
		return 0;
	}
	cout << ans << '\n';
	for(int i = 0; i < ansa; ++i)
		cout << a[i].ss << ' ';
	for(int i = 0; i < ansb; ++i)
		cout << b[i].ss << ' ';
	for(int i = 0; i < ansboth; ++i)
		cout << both[i].ss << ' ';
	for(int i = 0; i < ansnone; ++i)
		cout << none[i].ss << ' ';
	
}