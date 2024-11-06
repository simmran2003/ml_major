#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define str to_string
#define in binary_search
#define vll vector<ll>
#define sll set<ll>
#define vstr vector<string>
#define ll long long
#define ld long double
#define pb push_back
#define add insert
#define rall(x) rbegin(x),rend(x)
#define all(x) (x).begin(),(x).end()
#define sum(a) accumulate(all(a),0)
#define index(a,e) find(all(a),e)-begin(a);
#define rotr(a,s) rotate(a.begin(),a.begin()+a.size()-s,a.end());
#define rotl(a,s) rotate(a.begin(),a.begin()+s,a.end());
#define rindex(a,e) find(rall(a),e)-rbegin(a);
#define replace(a,m,t) replace(a.begin(), a.end(), m, t)
#define rec(a,x)    reverse_copy (all(a), x.begin());
#define sortr(a) sort(rall(a))
#define mp make_pair
#define ff first
#define ss second
#define debug(a) cerr<<#a<<" == "<<a<<endl;
#define Code  ios_base::sync_with_stdio(false); 
#define Faisal cout.tie(NULL);
#define By cin.tie(NULL);
template<typename T1> inline ostream& operator << (ostream& out, vector<T1> a) { for(auto i:a){out<<i<<" ";};; return out; }

template<typename T1> inline istream& operator >> (istream& in, vector<T1>& a){ for(auto& i:a){in>>i;};return in;}

vstr split(string s, char del){
	stringstream ss(s);
	string word;
	vstr b;
	while (!ss.eof()) {
		getline(ss, word, del);
		b.pb(word);
	}
	return b;
}

bool Prime(ll n){
    if (n <= 1)
        return false;
    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

void co(ll fg){
	cout<<"Case #"<<fg<<':'<<" ";
}
ll powmod(ll a,ll b,ll modulo)
{
	if(b==0){
		return 1;
	}
	ll temp=powmod(a,b/2,modulo);
	if(b%2==0){
		return (temp*temp)%modulo;
	}
	else{
		return (a*((temp*temp)%modulo))%modulo;
	}
}
const ll MAXN=1e5+5;
const int inf = (int)1e9;
map<int, int> dis[MAXN];
int ans[MAXN];
bool centriod[MAXN];
int siz[MAXN];
bool visited[MAXN];
set<int> adj[MAXN];
int par[MAXN];
void dfs2(int u, int p, int c, int d) { // build distance 
	dis[c][u] = d;
	for(auto v : adj[u]) if(v != p) {
		dfs2(v, u, c, d + 1);
	}
}
void dfs(int x,int p=-1)
{
	siz[x]=1;
	for(auto i:adj[x])
	{
		if(!centriod[i] and p!=i)
		{
			dfs(i,x);
			siz[x]+=siz[i];
		}
	}
}
int find_centriod(int n,int p,int toz)
{
	// cout<<"dfs"<<endl;
	for(auto m:adj[n])
	{
		if(siz[m]>toz/2 and p!=m)
		{
			return find_centriod(m,n,toz);
		}
	}
	// cout<<"end"<<endl;
	return n;
}
 // void build(int u, int p) {
 //    int n = dfs(u, p);
 //    int c = centroid(u, p, n);
 //    if(p == -1) p = c;
 //    pa[c] = p;
    // dfs2(c, p, c, 0);
 //    vector<int> tmp(adj[c].begin(), adj[c].end());
 //    for(auto v : tmp) {
 //      adj[c].erase(v); adj[v].erase(c);
 //      build(v, c);
 //    }
 //  }
ll root=0;
void build(int u=1,int p=-1)
{
	dfs(u);
	// cout<<"hello"<<endl;
	int c=find_centriod(u,p,siz[u]);
	// cout<<"hello"<<endl;
	centriod[c]=1;
	if(p==-1)
	{
		root=c;
		p=c;
	}
	// cout<<"root == ";
	// cout<<g<<endl;
	par[c]=p;
    dfs2(c, p, c, 0);
    vector<int> tmp(adj[c].begin(), adj[c].end());
    for(auto v : tmp) {
      adj[c].erase(v); adj[v].erase(c);
      build(v, c);
    }
}
void init(ll n) {
	for(int i = 1 ; i <= n ; ++i) ans[i] = inf;
}
void modify(int u) {
	for(int v = u ; v != 0 ; v = par[v]) ans[v] = min((ll)ans[v], (ll)dis[v][u]);
}
int query(int u) {
	int mn = inf;
	for(int v = u ; v != 0 ; v = par[v]) mn = min((ll)mn, (ll)ans[v] + (ll)dis[v][u]);
	return mn;
}
int main(){
	// Code By Faisal
	ll t=1;
	while(t--){
		ll n;
		cin>>n;	
		init(n);
		ll m=n-1;
		cin>>m;
		for(int i=0;i<n-1;i++)
		{
			ll a,b;
			cin>>a>>b;
			adj[a].add(b);
			adj[b].add(a);
		}
		build();//workin
		par[root]=0;
		modify(1);
		ll u,t;
		  while(m--) {
		    cin >> t >> u;
		    if(t == 1) modify(u);
		    else cout << query(u) << '\n';
		  }
	}
	return 0;
}
//1 sec 10^7
//debug use g++ -g I.cpp
//gdb ./a.out