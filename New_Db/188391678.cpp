#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int ll
#define fr first
#define se second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Rep(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
typedef pair<int,int> pii;
#ifdef OVAL
const ll N = 2e3+10;
#else
const ll N = 2e5+10;
#endif
#define db ll
#define EPS 0
#define PI acos(-1)
// 判断a的符号 返回值为 -1,0,1
inline int sign(db a) { return a < -EPS ? -1 : a > EPS; }
// 比较 a 和 b 的大小(带eps) a<b -1; a==b 0; a>b 1
inline int cmp(db a, db b) { return sign(a - b); }
// 点/向量
struct P{
	db x, y;
	int id;
	P(db _x = 0, db _y = 0) : x(_x), y(_y) {}

	P operator+(P p) const{ return P(x + p.x, y + p.y); }
	P operator-(P p) const{ return P(x - p.x, y - p.y); }
	P operator*(db a) { return P(x * a, y * a); }
	P operator/(db a) { return P(x / a, y / a); }
	// 两点重叠(带eps)
	bool operator==(P p) const { return cmp(x, p.x) == 0 && cmp(y, p.y) == 0; }
	bool operator!=(P p)const{return !((*this)==p);}
	db abs2() { return x * x + y * y; }
	double abs() { return sqrt(abs2()); }
	double disTo(P p) { return (*this - p).abs(); }
	double disTo2(P p) { return (*this - p).abs2(); }
	void read(){cin >> x >> y;}
};
db dotmul(P p1, P p2, P p3) {
	return (p2.x - p1.x) * (p3.x - p1.x) + (p2.y - p1.y) * (p3.y - p1.y);
}
db xmul(P p1, P p2, P p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}
int xmulOP(P p1, P p2, P p3) { return sign(xmul(p1, p2, p3)); }
bool isInside(db a, db b, db m){
	if (a > b) swap(a, b);
	return cmp(a, m) <= 0 && cmp(m, b) <= 0;
}
bool isInside(P a, P b, P m){
	return isInside(a.x, b.x, m.x) && isInside(a.y, b.y, m.y);
}
bool isonSeg(P a, P b, P m){
	return xmulOP(a, b, m) == 0 && isInside(a, b, m);
}
struct Line{
	P a, b;
	void read(){a.read(), b.read();}
	double len(){return a.disTo(b);}
};
bool isonSeg(Line l, P m){
	return xmulOP(l.a, l.b, m) == 0 && isInside(l.a, l.b, m);
}
Line ls[10];
bool chk(Line x, P p)
{
	ll d1 = p.disTo2(x.a), d2 = p.disTo2(x.b);
	if(d1>d2)swap(d1, d2);
	if(16*d1 >= d2)return true;
	return false;
}
bool check(Line l1, Line l2, Line l3)
{
	if(l1.a!=l2.a){
		if(l1.a==l2.b)swap(l2.a, l2.b);
		else if(l1.b==l2.a)swap(l1.a, l1.b);
		else if(l1.b==l2.b){
			swap(l1.a, l1.b);
			swap(l2.a, l2.b);
		}
		else return false;
	}
	double angle = 1.0*dotmul(l1.a, l1.b, l2.b);
	if(angle<0)return false;
	if(isonSeg(l1, l3.b) && isonSeg(l2, l3.a))swap(l3.a, l3.b);
	if(!(isonSeg(l1, l3.a) && isonSeg(l2, l3.b)))return false;
	return chk(l1, l3.a)&&chk(l2, l3.b);
}
void solve()
{
	vector<int> v;
	For(i,1,3){
		ls[i].read();
		v.push_back(i);
	}
	do{
		if(check(ls[v[0]], ls[v[1]], ls[v[2]])){
			// for(auto c:v)cout << c << " ";
			cout << "YES\n";
			return ;
		}
	}while(next_permutation(v.begin(), v.end()));
	cout << "NO\n";
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int tt = 1;
	cin >> tt;
	For(tc,1,tt){
		solve();
	}
	return 0;
}
/*
3 53 25
100 25 
20 5 
40 10

*/
       		  		 				  		 	 	 				