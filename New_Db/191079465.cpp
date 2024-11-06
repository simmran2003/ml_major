#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>
#include <stdio.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long
#define ld long double
#define fi(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define f(e,v) for(auto e:v)
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vld vector<ld>
#define vvld vector<vld>
#define vvvld vector<vvld>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vc>
#define vb vector<bool>
#define vvb vector<vb>
#define pii pair<int,int>
#define ppii pair<int,pii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vppii vector<ppii>
#define pb push_back
#define all(v) v.begin(),v.end()
#define sva(v) sort(all(v)) // sort vector(or vector pair) in ascending order(acc to the first ele of pair)
#define rev(v) reverse(all(v))
#define svd(v) sva(v);rev(v) // sort vector(or vector pair) in descending order(acc to the first ele of pair)
#define svpa(v) sort(v.begin(),v.end(),comp)
#define Max(v) *max_element(all(v))
#define Min(v) *min_element(all(v)) 
#define print(flag) (flag)?cout<<"YES"<<endl:cout<<"NO"<<endl
#define endl '\n'
#define MAXN 650005
#define sinf string::npos
const int inf=9123372036854775807;
int mod=1e9+7;
const int N=101;
 
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// hash_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
 
 
int getbit(int n,int pos){ // bit at idx=pos in n
    pos++;
    return ((n & (1 << (pos - 1))) >> (pos - 1));
}
int setbits(int n){ // # set bits in n
    return __builtin_popcountll(n);
}
int msb(int n){ // pos of MSB in n
    return 63-__builtin_clzll(n);
}
 
bool comp(pii p1,pii p2){
    if(p1.first!=p2.first) return p1.first<p2.first;
    return p1.second>p2.second; 
}
 
int rangeand(int a, int b) {
    int shiftcount = 0;
    while(a != b and a > 0) {
        shiftcount++;a = a >> 1;b = b >> 1;
    }
    return (int)(a << shiftcount);
}
 
void rvl(vi &v,int steps,int start,int end){
    int len=end-start+1;
    vi temp(len);
    fi(i,start,end+1){
        int idx=i+steps;if(idx>end) idx=idx-end-1+start;
        temp[i-start]=v[idx];
    }
    fi(i,start,end+1){
        v[i]=temp[i-start];
    }
}
void rvr(vi &v,int steps,int start,int end){
    rvl(v,end-start+1-steps,start,end);
}
 
int le(set<int,greater<int>>&s,int x){ // return max y : y<=x, -inf if no such y
    auto it=s.lower_bound(x);
    if(it==s.end()) return -inf;
    return *it; 
}

int power(int a,int b){
    if(a>=mod) a%=mod;
    if(!b) return 1;
    int temp=power(a,b/2);
    if(temp>=mod) temp%=mod;
    int res=temp*temp;
    if(res>=mod) res%=mod;
    if(b%2) res*=a;
    if(res>=mod) res%=mod;
    return res;
}
int fact(int n){ // dont use this : use the build_fact using arrays
    int ans=1;
    fi(i,1,n+1){
        if(i>=mod){
            ans=(ans*(i%mod));
            if(ans>=mod) ans%=mod;
        }
        else{
            ans=(ans*i);
            if(ans>=mod) ans%=mod;
        }
    }
    return ans;
}
int add(int a,int b){
    if(a>=mod) a%=mod;
    if(b>=mod) b%=mod;
    int res=a+b;
    if(res>=mod) res%=mod;
    return res;
}
int sub(int a,int b){
    if(a>=mod) a%=mod;
    if(b>=mod) b%=mod;
    int res=a-b;
    if(res<0) res+=mod;
    return res;
}
int mul(int a,int b){
    if(a>=mod) a%=mod;
    if(b>=mod) b%=mod;
    int res=a*b;
    if(res>=mod) res%=mod;
    return res;
}
int divide(int a,int b){
    if(a>=mod) a%=mod;
    int ans=a*power(b,mod-2);
    if(ans>=mod) ans%=mod;
    return ans;
}
int ncr(int n,int r){
    if(n<0 or r<0 or n<r) return 0;
    if(r==0 or r==n) return 1;
    int ans=ncr(n-1,r-1)+ncr(n-1,r);
    if(ans>=mod) ans%=mod;
    return ans;
}

// 1)primes upto n(<=1e7+10) using sieve
vi prime(MAXN+5,1);
vi pr;
void sieve(){
    prime[1]=0;
    for (int p = 2; p * p <= MAXN; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= MAXN; i += p)
                prime[i]=0;
        }
    }
    int n=sqrt(1000000000)+5;
    for(int i=2;i<=n;i++) if(prime[i]) pr.pb(i);
}
 
// // 2)PRIME FACTORISATION USING SIEVE
int spf[MAXN]; // spf[i]= smallest prime factor of i
void pf(){
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
set<int> primefactors(int x){ // prime factors of x
    set<int>ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
 
int nCr[N][N];
void get_nCr(){
    nCr[0][0]=1;
    for(int n=1; n<N; n++)
    {
        nCr[n][0]=1; nCr[n][n]=1;
        for (int r=1; r<n; r++){
            nCr[n][r] = (nCr[n-1][r-1]+nCr[n-1][r]);
            if(nCr[n][r]>=mod) nCr[n][r]%=mod;
        }
    }
}

int Fact[MAXN];
void get_fact(){
    Fact[0]=1;
    fi(i,1,N) Fact[i]=mul(Fact[i-1],i);
}

int Z[MAXN];
void z_function(string s) {
    int n = (int) s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            Z[i] = min (r - i + 1, Z[i - l]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            ++Z[i];
        if (i + Z[i] - 1 > r)
            l = i, r = i + Z[i] - 1;
    }
}

// *********************** Binary lifting and lca starts here ***********************
// uncomment this for Binary lifting or lca(a,b) or distance(a,b) using lca 
// Binary lifting and LCA(in log(n) TC per querry)
// vvi parent(MAXN,vi(log2(MAXN)+1));
// vi level(MAXN);vvi adj(MAXN);
// void dfs(int node,int par){ // sets the first parent of each node
//     parent[node][0]=par;
//     f(nbr,adj[node]){
//         if(nbr!=par) dfs(nbr,node);
//     }
// }
// void assign_level(int node,int par){ // to assign level to each node using dfs
//     if(par==-1) level[node]=0; // node is root
//     else level[node]=level[par]+1;
//     f(nbr,adj[node]){
//         if(nbr!=par) assign_level(nbr,node);
//     }
// }
// void build_parent(int root,int n){
//     dfs(root,-1);
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=log2(n);j++){
//             // 2^j th parent of i
//             if(parent[i][j-1]!=-1) parent[i][j] = parent[parent[i][j-1]][j-1];
//             else parent[i][j] = -1;
//         }
//     }
// }
// void binary_lifting(int root,int n){
//     build_parent(root,n);assign_level(root,-1);
// }
// int kth_parent(int node,int k){
//     if(!k) return node; // base case
//     int log_val=log2(k);
//     return kth_parent(parent[node][log_val],k-pow(2,log_val));
// }
// int lca(int a,int b,int n){ // finds lca(a,b) in log(n) TC
//     if(level[a]>level[b]) swap(a,b);
//     int d = level[b] - level[a];
//     b = kth_parent(b,d);
//     if(a==b) return a;
//     int limit = log2(n);
//     for(int i=limit;i>=0;i--){
//         if(parent[a][i]!=-1 and parent[a][i]!=parent[b][i]){
//             a = parent[a][i]; b = parent[b][i];
//         }
//     }
//     return parent[a][0];
// }
// int distance(int a,int b,int n){ // finds distance(a,b) using lca(a,b)
//     int LCA = lca(a,b,n);
//     return level[a]+level[b]-2*level[LCA];
// }
// *********************** Binary lifting and lca ends here ***********************

// *********************** Centroid Decomposition starts here ***********************
// uncomment this for Centroid Decomposition
// vi subtree_size(MAXN);vvi Tree(MAXN);
// vi removed(MAXN); // keeps track of all the removed nodes in the Tree while constructing Centroid-Tree
// vvpii ancestors(MAXN); // ancestors[i] stores pairs {anc,dist} where anc are all the ancestors of i
// vi dad(MAXN); // stores the parent[i] for each i in the formed Centroid Tree
// int find_subtree_size(int node,int par){ // find subtree_size of each node after any configuration
//     subtree_size[node]=1;
//     f(nbr,Tree[node]){
//         if(nbr!=par and !removed[nbr]) subtree_size[node]+=find_subtree_size(nbr,node);
//     }
//     return subtree_size[node];
// }
// int centroid(int node,int par,int n){ // finds the centroid of the tree
//     f(nbr,Tree[node]){
//         if(nbr!=par and !removed[nbr] and subtree_size[nbr]>n/2) return centroid(nbr,node,n);
//     }
//     return node;
// }
// void build_centroid_tree(int node,int par){
//     int n=find_subtree_size(node,par);
//     int Centroid=centroid(node,par,n);
//     removed[Centroid]=1;dad[Centroid]=par;
//     queue<pii>q; // {ancestor,distance};
//     q.push({Centroid,0});
//     while(!q.empty()){
//         pii p=q.front();q.pop();
//         int node=p.first,dist=p.second;
//         ancestors[node].pb({Centroid,dist});
//         f(nbr,Tree[node]){
//             if(!removed[nbr] and (ancestors[nbr].empty() or (ancestors[nbr].back()).first!=Centroid)) q.push({nbr,dist+1});
//         }
//     }
//     f(nbr,Tree[Centroid]){
//         if(!removed[nbr]){
//             build_centroid_tree(nbr,Centroid);
//         }
//     }
// }
// *********************** Centroid Decomposition ends here ***********************

void solve(){
    // write code here
    int n,mm,s,f;cin>>n>>mm>>s>>f;
    string ans="";
    // vppii v(m);
    map<int,pii>m;
    fi(i,0,mm){
        int t,l,r;cin>>t>>l>>r;
        // v[i]={t,{l,r}};
        m[t]={l,r};
    }
    int t=1;
    while(s!=f){
        if(m.find(t)==m.end()){
            if(f>s){ans+='R';s++;}
            else{ans+='L';s--;}
            t++;
        }
        else{
            pii p=m[t];int l=p.first,r=p.second;
            if(s<l or s>r){
                int target;
                if(f>s) target=s+1;
                else target=s-1;
                if(target<l or target>r){
                    if(f>s){ans+='R';s++;}
                    else{ans+='L';s--;}
                }
                else ans+='X';
                t++;
            }
            else{
                ans+='X';t++;
            }
        }
    }
    cout<<ans<<endl;
}
 
int32_t main(){
    fast
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // sieve();
    int t=1;
    // cin>>t;
    while(t--) solve();
}