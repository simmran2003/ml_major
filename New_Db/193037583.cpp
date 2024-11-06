#include <bits/stdc++.h>
using namespace std;
#define ulol unsigned long long int
#define ui unsigned int
#define lol long long int
#define plol pair<lol,lol>
#define vi vector<long long>
#define UMP unordered_map<long long,long long>
#define MP map<long long,long long>
#define f(i, a, b) for (lol i = a; i < b; i++)
#define yes write_string("YES",true);
#define no write_string("NO",true);
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
const lol MOD = 1e9 + 7;

// const double pi = 3.14159265358979323846;
// const lol MOD = 998244353;
// const lol N = 1e7 + 1;
const int BUF_SZ = 1 << 15;

inline namespace Input {
char buf[BUF_SZ];
int pos;
int len;
char next_char() {
	if (pos == len) {
		pos = 0;
		len = (int)fread(buf, 1, BUF_SZ, stdin);
		if (!len) {
			return EOF;
		}
	}
	return buf[pos++];
}

lol read_int() {
	lol x;
	char ch;
	int sgn = 1;
	while (!isdigit(ch = next_char())) {
		if (ch == '-') {
			sgn *= -1;
		}
	}
	x = ch - '0';
	while (isdigit(ch = next_char())) {
		x = x * 10 + (ch - '0');
	}
	return x * sgn;
}
} // namespace Input
inline namespace Output {
char buf[BUF_SZ];
int pos;

void flush_out() {
	fwrite(buf, 1, pos, stdout);
	pos = 0;
}

void write_char(char c) {
	if (pos == BUF_SZ) {
		flush_out();
	}
	buf[pos++] = c;
}
void write_string(string s,bool e){
  f(i,0,s[i]){
    write_char(s[i]);
  }
  if(e)write_char('\n');
}
void write_int(lol x,bool En = false) {
	static char num_buf[100];
	if (x < 0) {
		write_char('-');
		x *= -1;
	}
	int len = 0;
	for (; x >= 10; x /= 10) {
		num_buf[len++] = (char)('0' + (x % 10));
	}
	write_char((char)('0' + x));
	while (len) {
		write_char(num_buf[--len]);
	}
  if(En)
	write_char('\n');
}

// auto-flush output when program exits
void init_output() { assert(atexit(flush_out) == 0); }
} // namespace Output
lol binpow(lol a, lol b, lol m) {
  a %= m;
  lol res = 1;
        while (b > 0) {
          if (b & 1)
            res = res * a % m;
          a = a * a % m;
          b >>= 1;
        }   
  return res;
}
lol modInv(lol a,lol m){
  return binpow(a,m-2,m);
}

// lol x,n;
// vector<lol> v;
// lol minRides(lol isAvail,lol curr,lol i){
//   if(isAvail == 0){
//     return 0;
//   }
//   lol ans = INT_MAX;
//   if(curr + v[i] > x){
//     ans = min(ans,minRides(isAvail^(1<i),curr,i++));
//   }
//   else{
//     ans = min(ans,minRides(isAvail^()))
//   }
// }
// lol n,q,l,r,v,ans,l1,r1;
// pair<lol,lol> a;
// vector<lol> preSum,preXor,idx;
// lol n,m;
// string ans;
// lol len = INF;
// void solve() {
//   cin>>n>>m;
//   vector<string> grid(n);
//   f(i,n){
//     cin>>grid[i];
//   }
//   int x,y;
//   vector<vector<bool>> visited(n,vector<bool>(m));
//   vector<vector<string>> shPath(n,vector<string>(m));
//   f(i,n){
//     f(j,m){
//       if(grid[i][j] == 'A'){
//         x = i, y = j;
//       }
//       if(grid[i][j] == '#'){
//         visited[i][j] = true;
//       }
//     }
//   }
//   queue<pair<lol,lol>> q;
//   q.push({x,y});
//   lol i,j;
//   while(!q.empty()){
//     pair<lol,lol> t = q.front();
//     q.pop();
//     i = t.first;
//     j = t.second;
//     visited[i][j] = true;
//     if(grid[i][j] == 'B'){
//       yes
//       cout<<shPath[i][j].size()<<endl;
//       cout<<shPath[i][j]<<endl;
//       return;
//     }
//     if(i + 1 < n && !visited[i+1][j]){
//       if(shPath[i+1][j] == "" || shPath[i+1][j].size() > shPath[i][j].size()){
//         shPath[i+1][j] = shPath[i][j]+"D";
//       }
//       q.push({i+1,j});
//     }
//     if(j + 1 < m && !visited[i][j+1]){
//       if(shPath[i][j+1] == "" || shPath[i][j+1].size() > shPath[i][j].size()){
//         shPath[i][j+1] = shPath[i][j] + "R";
//       }
//       q.push({i,j+1});
//     }
//     if(i - 1 >= 0 && !visited[i-1][j]){
//       if(shPath[i-1][j] == "" || shPath[i-1][j].size() >= shPath[i][j].size()+1){
//         shPath[i-1][j] = shPath[i][j] + "U";
//       }
//       q.push({i-1,j});
//     }
//     if(j-1 >= 0 && !visited[i][j-1]){
//       if(shPath[i][j-1] == "" || shPath[i][j-1].size() >= shPath[i][j].size() + 1){
//         shPath[i][j-1] = shPath[i][j] + "L";
//       }
//       q.push({i,j-1});
//     }
//   }
//   no
// }}
// }
bool containNegativeCycle(lol curr,vector<bool> &visited1,vector<bool> &visited2,vector<vector<lol>> adj[],lol weight){
  if(visited1[curr]){
    if(weight < 0){
      return true;
    }
    return false;
  }
  visited1[curr] = true;
  visited2[curr] = true;
  for(lol i = 0;i<adj[curr].size();i++){
    if(containNegativeCycle(adj[curr][i][0],visited1,visited2,adj,weight+adj[curr][i][1])){
      return true;
    }
  }
  visited1[curr] = false;
  return false;
}
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> ans(V, INT_MAX);
    ans[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < V; i++)
    {
        if (i == S)
            pq.push({0, i});
        else
            pq.push({INT_MAX, i});
    }
    vector<bool> visited(V,0);
    int currW=0,edg=0,next=0;
    while (!pq.empty())
    {
        int w = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        for (int i = 0; i < adj[idx].size(); i++)
        {
            next = adj[idx][i][0];
            edg = adj[idx][i][1];
            ans[next] = ans[idx] + adj[idx][i][1];
            pq.push({ans[idx] + edg,next});
        }
    }
    return ans;
}
void dfs(vector<vector<lol>> &adj, stack<int> &st, vector<bool> &visited, int curr)
{
    if (visited[curr])
        return;
    visited[curr] = true;
    for (int i = 0; i < adj[curr].size(); i++)
    {
        dfs(adj, st, visited, adj[curr][i]);
    }
    st.push(curr);
}

vector<int> topoSort(int V, vector<vector<lol>> &adj)
{
    stack<int> st;
    vector<bool> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(adj, st, visited, i);
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<lol> spf(10000001,-1);
 lol primes = 0;
void seive(int n) {
 spf[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (spf[i] == -1) {
      primes++;
    spf[i] = i;
      for (int j = 2 * i; j <= n; j += i) {
        spf[j] = i;
      }
    }
  }
}
void dfs(vector<int> adj[], vector<bool> &visited, stack<int> &st, int curr)
{
    if (visited[curr])
        return;
    visited[curr] = true;
    for (int i = 0; i < adj[curr].size(); i++)
    {
        dfs(adj, visited, st, adj[curr][i]);
    }
    st.push(curr);
}
void dfs(vector<int> adj[], vector<bool> &visited, int curr)
{
    if (visited[curr])
        return;
    visited[curr] = true;
    for (int i = 0; i < adj[curr].size(); i++)
    {
        dfs(adj, visited, adj[curr][i]);
    }
}
int kosaraju(int V, vector<int> adj[])
{
    stack<int> st;
    vector<bool> visited(V);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(adj, visited, st, i);
    vector<int> Tadj[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); i++)
        {
            Tadj[adj[i][j]].push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < V; i++)
        visited[i] = false;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!visited[top])
        {
            ans++;
            dfs(Tadj, visited, top);
        }
    }
    return ans;
}
class STRINGHASHING{
  lol n;
  string s;
  vector<lol> HASH1,HASH2,ModInv1,ModInv2;
  public:
  STRINGHASHING(string s){
    this->n = s.size();
    this->s = s;
    HASH1.assign(n,0);
    HASH2.assign(n,0);
     lol p1 = 31,p2 = 53;
      lol MOD = 1000000007;
      lol P1 = p1,P2 = p2;
      HASH1[0] = s[0];
      HASH2[0] = s[0];
      ModInv1.push_back(1);
      ModInv2.push_back(1);
      f(i,0,n-1){
        HASH1[i] = (HASH1[i-1] + s[i]*P1)%MOD;
        HASH2[i] = (HASH2[i-1] + s[i]*P2)%MOD;
        ModInv1.push_back(modInv(P1,MOD));
        ModInv2.push_back(modInv(P2,MOD));
        P1 =(p1 * P1)%MOD;
        P2 = (p2 * P2)%MOD;
      }
  }
  pair<lol,lol> HashValue(lol i,lol j){
    if(i == 0){
      return {HASH1[j],HASH2[j]};
    }
    return {((HASH1[j] - HASH1[i-1] + MOD)%MOD*ModInv1[i])%MOD,((HASH2[j] - HASH2[i-1] + MOD)%MOD*ModInv2[i])%MOD};
  }
};
lol fact(lol n){
  if(n == 0 || n == 1){
    return 1;
  }
  return (n*fact(n-1))%MOD;
}
vector<vector<lol>> adj;
vector<bool> visited;
vector<lol> parent;
lol getRepresentative(lol ver){
  if(parent[ver] == -1){
    return ver;
  }
  lol a = getRepresentative(parent[ver]);
  return parent[ver] = a;
}
void dfs(long curr,vector<long> &p,vector<long> adj[],vector<long> &dis,vector<long> &leastDis,long &time,vector<bool> &visited){
  visited[curr] = true;
  leastDis[curr] = dis[curr] = time++;
  for(auto i : adj[curr]){
      if(i == p[curr])continue;
    if(!visited[i]){
      p[i] = curr;
      dfs(i,p,adj,dis,leastDis,time,visited);
      leastDis[curr] = min(leastDis[curr],leastDis[i]);
    }
    else{
      leastDis[curr] = min(leastDis[curr],dis[i]);
    }
  }
}
bool dfs(lol i,lol j,vector<bool> &visited,vector<vector<int>>& grid){
    lol n = grid.size();
    lol m = grid[0].size();
    if(visited[m * i + j] || grid[i][j] == false){
        return false;
    }
    if(i == n -1 && j == m- 1)return true;
    visited[m*(i) + j] = true;
    if(dfs(i,j+1,visited,grid)){
        return true;
    } 
    if(dfs(i+1,j,visited,grid)){
        return true;
    }
    visited[m*(i) + j] = false;
    return false;
}
bool isPossibleToCutPath(vector<vector<int>>& grid) {
        lol n = grid.size();
        lol m = grid[0].size(); 
        vector<bool> visited(n*m);
        if(!dfs(0,0,visited,grid))return true;
        visited[0] = false;
        if(!dfs(0,0,visited,grid))return true;
        return false;
    }
void solve(){
  // lol n;cin>>n;
  // string s;cin>>s;
  // unordered_map<char,lol> mp;
  // unordered_map<char,vector<lol>> indvexs;
  // f(i,n){
  //   mp[s[i]]++;
  //   indexs[s[i]-'a'].push_back(i);
  // }
  // vector<lol> freq;
  // for(auto it : mp){
  //   freq.push_back(it.second);
  // }
  // sort(freq.begin(),freq.end(),greater<lol>());
  // lol Freq;
  // lol Mindiff = INF;
  // f(i,26){
  //   if(n % (i+1) != 0){ 
  //     continue;
  //   }
  //   lol curr_freq = n / (i+1);
  //   lol diff = 0;
  //   if(i+1 >= freq.size()){
  //     f(j,freq.size()){
  //       diff+=abs(freq[j] - curr_freq);
  //     }
  //     f(j,i+1-freq.size()){
  //       diff += abs(curr_freq);
  //     }
  //   }
  //   else{
  //     f(j,i+1){
  //       diff += abs(freq[j] - curr_freq);
  //     }
  //     f(j,n){
  //       diff+= abs(freq[j]);
  //     }
  //   }
  //   diff /= 2;
  //   if(diff < Mindiff){
  //     Mindiff = diff;
  //     Freq = curr_freq;
  //   }
  // }
  // if(Mindiff == 0){
  //   cout<<0<<endl<<s<<endl;
  //   return;
  // } 
  // cout<<Mindiff<<endl;
  // lol chars = n/Freq;
  // if(chars > freq.size()){
  //   for(int i = 0;i<26;i++){
  //     if(mp.find(s[i]) == mp.end()){
  //       indexs[s[i]].push_back(-1);
  //       if(freq.size() == chars){break;}
  //     }

  //   }
  // }
  // lol n;cin>>n;
  // lol a;cin>>a;
  // Node* root = new Node(a);
  // F(i,n){
  //   cin>>a;
  //   lol parent = -1;
  //   root = insert(root,parent,a);
  //   cout<<parent<<" ";
  // }
  // cout<<endl;
  lol n = read_int();
  lol m = read_int();
  lol s = read_int();
  lol f = read_int();
  vector<char> v;
  vector<vector<lol>> steps(m,vector<lol> (3));
  f(i,0,m){
    steps[i][0] = read_int();
    steps[i][1] = read_int();
    steps[i][2] = read_int();
  }
  lol curr = s;
  bool fl = false;
  f(i,0,m){
    while(steps[i][0] > v.size() + 1){
      if(f < s){
        v.EB('L');
        curr--;
      }
      else{
        v.EB('R');
        curr++;
      }
      // deb(curr,f);
      if(curr == f){fl=true;break;}
    }
    if(fl)break;
    if(f < s){
      if(steps[i][1] > curr || steps[i][2] < curr - 1){
        v.EB('L');
        curr--;
      }
      else{
        v.EB('X');
      }
    } 
    else{
      if(steps[i][1] > curr + 1 || steps[i][2] < curr){
        v.EB('R');
        curr++;
      }
      else{
        v.EB('X');
      }
    }
    if(curr == f)break;
  }
  while(curr != f){
    if(f < s){
      v.EB('L');
      curr--;
    }
    else{
      v.EB('R');
      curr++;
    }
  }
  for(auto i : v){
    write_char(i);
  }
  write_char('\n');
}

// vector<lol> fact(101);
// lol ncr(lol n,lol r){
//   if(n <= 0){
//     return 1;
//   }
//   if(r <= 0){
//     return 1;
//   }
//   return fact[n]*modInv(fact[r],MOD)*modInv(fact[n-r],MOD);
// }
// lol crt(vector<pair<lol,lol>> v){
//   lol n = v.size();
//   lol pp = 1;
//   f(i,n){
//     pp *= v[i].first;
//   }
//   vector<lol> INV(n);
//   f(i,n){
//     INV[i] = modInv(pp/v[i].first,v[i].first);
//   }
//   lol ans = 0;
//   f(i,n){
//     ans = (ans + (pp/v[i].first)*INV[i]*v[i].second)%pp;
//   }
//   return ans;
// }
int main() {
  init_output();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  lol t = 1;
  // t = read_int();
  f(z,0,t) {
    // cout<<"Case #"<<i+1<<": "<<solve()<<endl;
    solve();
    // if (solve())
    //   yes
    //  else no
  }
}
const string picture = R"(
                    ┌-──┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
                    │Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
                    └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
                    ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
                    │~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │N L│ / │ * │ - │
                    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
                    │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
                    ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
                    │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
                    ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
                    │ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │     │ 1 │ 2 │ 3 │   │
                    ├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤E│ │
                    │ Ctrl│    │Alt │         Space         │ Alt│    │    │Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │←┘ │
                    └─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
)";
