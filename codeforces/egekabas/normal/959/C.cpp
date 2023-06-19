#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
  cin >> n;
  if(n <= 5)
    cout << -1 << endl;
  else if(n == 6)
    cout << "1 2\n" << "1 3\n" << "1 4\n" << "2 5\n" << "2 6\n";
  else if(n == 7)
    cout << "1 2\n" << "1 3\n" << "1 4\n" << "4 5\n" << "4 6\n" << "4 7\n";
  else{
    for(int i = 2; i <= n/2; ++i)
      cout << 1 << " " << i << endl;
    for(int i = n/2 + 1; i <= n-1; ++i )
      cout << n/2 << " " << i << endl;
    cout << n-1 << " " << n << endl;
  }
  for(int i = 2; i <= n; ++i)
    cout << 1 << " " << i << endl;
}