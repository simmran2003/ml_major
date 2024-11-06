#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array
#define db double
#define str string
#define bg begin()
#define en end()
#define fr front()
#define ba back()
#define pb push_back
#define pf push_front
#define mp make_pair
#define ins insert
#define sz(x) (int)x.size()
#define all(a) (a).begin(), (a).end()
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define lb lower_bound
#define ub upper_bound
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define each(a,x) for (auto& a: x)

const int mx = 2e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

int n,m,s,f,a,b,c,d,e;//d vi tri to giay e stt buoc abc 3 so cin

int main()
{
	cin.tie(0);
    ios_base::sync_with_stdio(0);
	cin>>n>>m>>s>>f;
	d=s;
	e=1;
	cin>>a>>b>>c;
	if (s<f){
		while (d!=f){
			if (e!=a){
				cout<<'R';
				d++;
			}
			else {
				if (d+1<b||d>c){
					cout<<'R';
					d++;
				}
				else cout<<'X';
				cin>>a>>b>>c;
			}
			e++;
		}
		return 0;
	}
	else {
		while (d!=f){
			if (e!=a){
				cout<<'L';
				d--;
			}
			else {
				if (d<b||d-1>c){
					cout<<'L';
					d--;
				}
				else cout<<'X';
				cin>>a>>b>>c;
			}
			e++;
		}
		return 0;
	}
}
