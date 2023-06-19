#include <bits/stdc++.h>
using namespace std;
pair<char,int> ar[500009];
int n, k;
int ans;
void solve(int bef, int aft, int z){
    if(ar[bef].first != ar[z].first && ar[aft].first != ar[z].first)
        return;
    for(int i = 0; i < k; ++i){
        if(i != ar[bef].first-'A' && i != ar[aft].first-'A'){
            ar[z].first = i + 'A';
            ar[z].second = 0;
            --ar[bef].second;
            --ar[aft].second;
            ++ans;
            return;
        }
    }
}
int main(){
    cin >> n >> k;
    int x;
    for(int i = 0; i < n; ++i)
        cin >> ar[i].first;
        if( k == 2){
            int one = 0;
            int two = 0;
            for (int i = 0; i < n; ++i){
                if(i % 2 == 0){
                    if(ar[i].first == 'A') ++one;
                    else ++two;
                }
                if(i % 2 == 1){
                    if(ar[i].first == 'A') ++two;
                    else ++one;
                }
            }
                if(one <= two){
                    cout << one << endl;
                    for(int i = 0; i < n; ++i){
                        if(i % 2 == 1)
                            cout << "A";
                        else
                            cout << "B";
                        }
                    }
                else{
                    cout << two << endl;
                    for(int i = 0; i < n; ++i){
                        if(i % 2 == 1)
                            cout << "B";
                        else
                            cout << "A";
                        }
                    }

            return 0;
        }
    for(int i = 0; i < n; ++i){
        if(i == 0)
            ar[i].second = (ar[i].first == ar[i+1].first);
        else if(i == n-1)
            ar[i].second = (ar[i].first == ar[i-1].first);
        else
            ar[i].second = (ar[i].first == ar[i-1].first) + (ar[i].first == ar[i+1].first);
    }


    for(int i = 1; i < n; ++i){
        if(i == n-1){
            if(ar[i].second == 1){
                if(ar[i-1].first == 'A') ar[i].first = 'B';
                else ar[i].first = 'A';
                ++ans;
            }
        }
        else if(ar[i].second == 1 && ar[i-1].second != 2 && ar[i+1].second !=2)
            solve(i-1, i+1, i);
        else if(ar[i].second == 2)
            solve(i-1, i+1, i);
    }
    cout << ans << endl;
    for(int i = 0; i < n; ++i)
        cout << ar[i].first;

}