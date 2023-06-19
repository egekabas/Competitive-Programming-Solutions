    #include "tickets.h"
    #include <bits/stdc++.h>
    #define all(x) (x).begin(), (x).end()
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
     
    long long find_maximum(int k, vector<vector<int>> x) {
    	int n = x.size();
    	int m = x[0].size();
    	vector<int> beg(n), fin(n);
    	for(int i = 0; i < n; ++i){
    		beg[i] = k-1;
    		fin[i] = m-1;
    	}
    	set<pii, greater<pii>> s;
    	for(int i = 0; i < n; ++i)
    		s.insert({x[i][beg[i]]+x[i][fin[i]], i});
    	for(int i = 0; i < n*k/2; ++i){
    		int idx = s.begin()->ss;
    		s.erase(s.begin());
    		//cout << idx << ' ' << ' ' << beg[idx] << ' ' << fin[idx] << '\n';
    		--fin[idx];
    		--beg[idx];
    		if(beg[idx] >= 0)
    			s.insert({x[idx][beg[idx]]+x[idx][fin[idx]], idx});
    	}
    	ll ans = 0;
    	for(int i = 0; i < n; ++i){
    		++fin[i];
    		for(int j = 0; j <= beg[i]; ++j)
    			ans -= x[i][j];
    		for(int j = fin[i]; j < m; ++j)
    			ans += x[i][j];
    	}
     
    	vector<vector<int>> ret(n, vector<int>(m, -1));
    	for(int round = 0; round < k; ++round){
    		int curbig = 0;
    		for(int i = 0; i < n; ++i)
    			if(beg[i] < 0){
    				ret[i][fin[i]] = round;
    				++fin[i];
    				++curbig;
    			}
    		for(int i = 0; i < n; ++i)
    			if(beg[i] >= 0){
    				if(curbig < n/2 && fin[i] < m){
    					ret[i][fin[i]] = round;
    					++fin[i];
    					++curbig;
    				}
    				else{
    					ret[i][beg[i]] = round;
    					--beg[i];
    				}
    			}
    	}
     
    	
    	allocate_tickets(ret);
    	return ans;
    }
