#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;
string s;
int main(){


    int T;
    cin >> T;
    while(T--){
        cin >> s;
        int low = 0;
        int up = 0;
        int digit = 0;
        for(int i = 0; s[i] != '\0'; ++i){
            if(islower(s[i]))
                ++low;
            else if(isupper(s[i]))
                ++up;
            else if(isdigit(s[i]))
                ++digit;
        }
        //cout << low << " " << up << " " << digit << endl;
        string tmp;
        int mini = 10000;
        pair<int, int> ans = mp(0, 0);
        for(int i = 0; s[i] != '\0'; ++i){
            int l = low;
            int u = up;
            int d = digit;
            for(int j = i; s[j] != '\0'; ++j){
                if(l > 0 && u > 0 && d > 0){
                    //cout << i << " " << j << endl;
                    if(j-i <= mini){
                        mini = j-i;
                        ans = mp(i, j);
                    }
                }
                if(islower(s[i])){
                    if(l > 1){
                        if(u == 0){
                            ++u;
                            --l;
                        }
                        else if(d == 0){
                            ++d;
                            --l;
                        }
                    }
                }
                else if(isupper(s[i])){
                    if(u > 1){
                        if(l == 0){
                            ++l;
                            --u;
                        }
                        else if(d == 0){
                            ++d;
                            --u;
                        }
                    }
                }
                else if(isdigit(s[i])){
                    if(d > 1){
                        if(u == 0){
                            ++u;
                            --d;
                        }
                        else if(l == 0){
                            ++l;
                            --d;
                        }
                    }
                }

            }
        }
        int l = low;
        int u = up;
        int d = digit;
        //cout << ans.ff << " " << ans.ss << endl;
        for(int i = ans.ff; i < ans.ss; ++i){
            if(islower(s[i])){
                if(l > 1){
                    if(u == 0){
                        ++u;
                        --l;
                        s[i] = 'A';
                    }
                    else if(d == 0){
                        ++d;
                        --l;
                        s[i] = '1';
                    }
                }
            }
            else if(isupper(s[i])){
                if(u > 1){
                    if(l == 0){
                        ++l;
                        --u;
                        s[i] = 'a';
                    }
                    else if(d == 0){
                        ++d;
                        --u;
                        s[i] = '1';
                    }
                }
            }
            else if(isdigit(s[i])){
                if(d > 1){
                    if(u == 0){
                        ++u;
                        --d;
                        s[i] = 'A';
                    }
                    else if(l == 0){
                        ++l;
                        --d;
                        s[i] = 'a';
                    }
                }
            }

        }
        cout << s << endl ;
    }

}