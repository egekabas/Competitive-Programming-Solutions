#include <bits/stdc++.h>
using namespace std;
long long x, y;
int main(){
    cin >> x >> y;
    if(x == 1 && y != 1)
        cout << "<";
    else if(y == 1 && x != 1)
        cout << ">";
    else if(x == y)
        cout << "=";
    else if((x == 2 && y == 4) || (x == 4 && y == 2))
        cout << "=";
    else if(x == 2 && y == 3)
        cout << "<";
    else if(x == 3 && y == 2)
        cout << ">";
    else if(x < y)
        cout << ">";
    else if(x > y)
        cout << "<";

}