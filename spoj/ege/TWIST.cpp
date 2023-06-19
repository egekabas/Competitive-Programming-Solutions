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
struct node{
    int pri, key, id, lazy1, lazy2, l, r;
    node(){
        pri = key = id = lazy1 = lazy2 = l = r = 0;
    }
    node(int k, int i){
        key = k;
        id = i;
        pri = rand();
        l = r = lazy1 = lazy2 = 0;
    }
};
int cur = 0;
node ar[200009];
int newnode(int key, int id){
    ++cur;
    ar[cur] = node(key, id);
    return cur;
}
void addlazy1(int t, int lazy){
    if(ar[t].lazy1 != 0){
        ar[t].lazy2 = lazy-ar[t].lazy1;
        ar[t].lazy1 = 0;
    }
    else{
        ar[t].lazy1 = lazy-ar[t].lazy2;
        ar[t].lazy2 = 0;
    }
}
void addlazy2(int t, int lazy){
    if(ar[t].lazy1 != 0)
        ar[t].lazy1 += lazy;
    else
        ar[t].lazy2 += lazy;
}
void push(int t){
    if(ar[t].lazy1 != 0){
        addlazy1(ar[t].l, ar[t].lazy1);
        addlazy1(ar[t].r, ar[t].lazy1);
        ar[t].key = ar[t].lazy1-ar[t].key;
        swap(ar[t].l, ar[t].r);
    }
    else{
        addlazy2(ar[t].l, ar[t].lazy2);
        addlazy2(ar[t].r, ar[t].lazy2);
        ar[t].key += ar[t].lazy2;
    }
    ar[t].lazy1 = ar[t].lazy2 = 0;
}
void split(int t, int key, int &tl, int &tr){
    push(t);
    if(!t){
        tl = tr = 0;
        return;
    }
    if(ar[t].key > key){
        split(ar[t].l, key, tl, ar[t].l);
        tr = t;
    }
    else{
        split(ar[t].r, key, ar[t].r, tr);
        tl = t;
    }
}
void insert(int &t, int nn){
    push(t);
    if(!t){
        t = nn;
        return;
    }
    if(ar[t].pri > ar[nn].pri){
        if(ar[t].key < ar[nn].key)
            insert(ar[t].r, nn);
        else
            insert(ar[t].l, nn);
    }
    else{
        split(t, ar[nn].key, ar[nn].l, ar[nn].r);
        t = nn;
    }
}
void merge(int &t, int tl, int tr){
    push(tl);
    push(tr);
    if(tl == 0){
        t = tr;
        return;
    }
    if(tr == 0){
        t = tl;
        return;
    }
    if(ar[tl].pri > ar[tr].pri){
        merge(ar[tl].r, ar[tl].r, tr);
        t = tl;
    }
    else{
        merge(ar[tr].l, tl, ar[tr].l);
        t = tr;
    }
}
void dfs(int t){
    if(t == 0) return;
    push(t);
    dfs(ar[t].l);
    cout << ar[t].id << ' ';
    dfs(ar[t].r);
}
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    srand(time(NULL));
    cin >> n >> m;
    int root = 0;
    for(int i = 1; i <= n; ++i){
        insert(root, newnode(i, i));
    }
    while(m--){
        int l, r;
        cin >> l >> r;
        int left, mid, right;
        split(root, l-1, left, mid);
        split(mid, r, mid, right);
        addlazy1(mid, r+l);
        merge(mid, left, mid);
        merge(root, mid, right);
    }
    dfs(root);
