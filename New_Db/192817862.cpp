#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

int n;
string s, Chars;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  vector<int> vt(n + 1);
  for(int i = 1; i <= n; i++) cin >> vt[i];
  cin >> s;
  s = "*" + s;
  int res = 0;
  for(int i = 1; i <= n; i++){
    if(s[i] == 'B') res += vt[i];
  }
  priority_queue<int, vector<int> , less<int> >p1, p2;
  int ans1 = res, ans2 = res;
  p1.push(res), p2.push(res);
  for(int i = 1; i <= n; i++){
    if(s[i] == 'A'){
        ans1 += vt[i];
    }
    else{
        ans1 -= vt[i];
    }
    p1.push(ans1);
  }
  for(int i = n; i >= 1; i--){
    if(s[i] == 'A'){
        ans2 += vt[i];
    }
    else{
        ans2 -= vt[i];
    }
    p2.push(ans2);
  }
  cout << max(p1.top(), p2.top()) << endl;
  return 0;
}
 	  				 	     	  			   				 	