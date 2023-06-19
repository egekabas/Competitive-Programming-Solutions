#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

typedef long long   ll;
typedef long double ld;

typedef pair<ll, ll>    pll;
typedef pair<ll, int>   pli;
typedef pair<int, int>  pii;

typedef vector<int> vii;
typedef vector<ll>  vll;

const int Inf = (int) 1e9;
const ll  InfL = (ll)  1e18;

const int MaxN = (int) 2e5 + 5;

ll n, m, a[MaxN], b[MaxN];
pll ans, score;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i < n + 1; i++)
        cin >> a[i];

    cin >> m;
    for (int i = 1; i < m + 1; i++)
        cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    ans.ff = 0;
    ans.ss = InfL;

    a[n + 1] = InfL;

    for (int i = 0; i <= n; i++) {

        while(i < n && a[i+1] == a[i]) i++;
        score.ff = 2*i + 3*(n - i);

        int pos = upper_bound(b + 1, b + m + 1, a[i + 1] - 1) - b;
        score.ss = 2*(pos - 1) + 3*(m - pos + 1);

        if (score.ff - score.ss > ans.ff - ans.ss) {
            ans.ff = score.ff;
            ans.ss = score.ss;
        }
        else if ( (score.ff - score.ss == ans.ff - ans.ss) && score.ff > ans.ff) {
            ans.ff = score.ff;
            ans.ss = score.ss;
        }
    }

    cout << ans.ff << ':' << ans.ss << endl;
	return 0;
}