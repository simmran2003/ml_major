#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

#define EPS 1e-9
#define PI acos(-1.0)
#define ll long long
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define pb push_back
#define ft first
#define sc second
#define pi pair<ll,ll>
#define vi vector<ll>
#define sz(s) s.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll N = 2e5+5, M = 200 + 10, MOD = 1e9+7, INF = 1e18;
int dx[] = {-1, 1, 0, 0}, Dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};;
int dy[] = {0, 0, 1, -1}, Dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll n, m,t;
struct point {

    long double x,  y;
    point(long double x, long double y) : x(x), y(y) {}

    point operator -(const point & other)const {
        return point(x - other.x, y - other.y);
    }

    point operator +(const point & other)const {
        return point(x + other.x, y + other.y);
    }

    point operator *(long double c) const {
        return point(x * c, y * c);
    }

    point operator = (const point & other)const {
        return point(other.x, other.y);
    }

    point operator /(long double c) const {
        return point(x / c, y / c);
    }

    bool operator == (const point other) const{
        return (x == other.x && y == other.y);
    }
};
long double mynorm(point a,point b)
{
    long double dx = fabs(a.x-b.x),dy = fabs(a.y-b.y);
    return (dx * dx + dy*dy);
}
long double cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

long double dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}
int dcmp(double a,double b)
{
    return fabs(a-b) <= EPS? 0: a < b ? -1 : 1;
}

point distToSegment(point p0, point p1, point p2 ) {
	double d1,d2;
	point v1 = p1 - p0, v2 = p2 - p0;
	if((d1 = dot(v1,v2)) <= 0) return p0;
	if((d2 = dot(v1,v1)) <= d1) return p1;
	double t = d1/d2;
	return (p0 + v1*t);
}

int ccw(point a,point b,point c)
{
    point v1 = b-a, v2 = c-a;
    if(cross(v1,v2) > EPS) return 1;
    if(cross(v1,v2) < -EPS) return -1;
    if(v1.x * v2.x < -EPS || v2.y * v2.y < -EPS) return -1;
    if(mynorm(a,b) < mynorm(a,c) - EPS) return 1;
    return 0;
}

bool twoSegmentIntersect(point a,point b,point c,point d)
{
    int x = (a == b), y = (c == d);
    if(x && y) return a == c;
    if(x) return ccw(c,d,a) == 0;
    if(y) return ccw(a,b,c) == 0;
    return (
            ccw(a,b,c) * ccw(a,b,d) <= 0 && ccw(c,d,a) * ccw(c,d,b)
            );
}

point lineLineIntersection(point A, point B, point C, point D)
{
    // Line AB represented as a1x + b1y = c1
    double a1 = B.y - A.y;
    double b1 = A.x - B.x;
    double c1 = a1*(A.x) + b1*(A.y);

    // Line CD represented as a2x + b2y = c2
    double a2 = D.y - C.y;
    double b2 = C.x - D.x;
    double c2 = a2*(C.x)+ b2*(C.y);

    double determinant = a1*b2 - a2*b1;

    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        return point(INF, INF);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return point(x, y);
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);//freopen("lines.in", "r", stdin);
    ll h, r;
    cin >> r >> h;
    if((h%r)*2 < r)
        cout << 1 + (h/r) * 2;
    else{
        long double rr = r;
        long double dis =  sqrt(r*r - r*r/4.0)  + ((h/r+1) * r);
        cout << (dis > (h+rr) ?2:3) + (h/r) * 2;
    }
    return 0;
}
/*
*/
