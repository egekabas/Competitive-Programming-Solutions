#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
struct node{
    int k, p, cnt, l, r;
    node(){k = 0, p = 0, cnt = 0, l = 0, r = 0;};
    node(int val){k = val, p = rand(), cnt = 0, l = 0, r = 0;};
};
node ar[200009];
void calc(int id){
    if(id == 0)
        ar[id].cnt = 0;
    else
        ar[id].cnt = 1+ar[ar[id].l].cnt+ar[ar[id].r].cnt;
}
void split(int t, int key, int &l, int &r){
    if(t == 0)
        l = r = 0;
    else if(ar[t].k >= key){
        split(ar[t].l, key, l, ar[t].l);
        r = t;
    }
    else{
        split(ar[t].r, key, ar[t].r, r);
        l = t;    
    }
    calc(t);
        
}
void insert(int &t, int it){
    if(t == 0)
        t = it;
    else if(ar[t].p > ar[it].p){
        insert((ar[it].k >= ar[t].k) ? ar[t].r : ar[t].l , it);
    }
    else{
        int l, r;
        split(t, ar[it].k, ar[it].l, ar[it].r);
        t = it;
    }
    calc(t);
}
int smaller(int t, int x){
    if(t == 0) return 0;
    if(ar[t].k > x)
        return smaller(ar[t].l, x);
    else{
        return ar[t].cnt-ar[ar[t].r].cnt + smaller(ar[t].r, x);
    }
}
int getid(int t, int x){
    if(t == 0) 
        return -1;
    else if(ar[t].cnt-ar[ar[t].r].cnt == x)
        return ar[t].k;
    else if(ar[t].cnt-ar[ar[t].r].cnt > x)
        return getid(ar[t].l, x);
    else
        return getid(ar[t].r, x-(ar[t].cnt-ar[ar[t].r].cnt));
}
int n, q;
int curnode = 0;
int root = 0;
void add(int x){
    ar[++curnode] = node(x);
    insert(root, curnode);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    srand(time(NULL));
    cin >> n >> q;
    while(n--){
        int tmp;
        cin >> tmp;
        add(tmp);
        calc(root);
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        if(x == 1)
            add(smaller(root, y)+y);
        else if(x == 2)
            cout << smaller(root, y) << '\n';
        else{
            int tmp = getid(root, y);
            if(tmp == -1)
                cout << "invalid\n";
            else
                cout << tmp << '\n'; 
        }   

    }
