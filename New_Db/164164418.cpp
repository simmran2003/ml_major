//https://codeforces.com/problemset/problem/13/D
#include<bits/stdc++.h>
#define VI vector<int>
typedef long double db;
using namespace std;
const db eps=1e-20;
const db PI = acos(-1.);
int sign(db x) {return x<-eps?-1:x>eps;}
int cmp(db x, db y) {return sign(x-y);}
struct Point{
    db x,y;
    Point(){}
    Point(db _x, db _y):x(_x),y(_y){}
    Point operator+(Point p) const { return {x+p.x,y+p.y}; }
    Point operator-(Point p) const { return {x-p.x,y-p.y}; }
    // Point operator*(db d) const{ return {1.*x*d,1.*y*d}; }
    // Point operator/(db d) const{ return {1.*x/d,1.*y/d}; }
    db det(Point p) { return x*p.y-y*p.x; }
    db dot(Point p) { return x*p.x+y*p.y; }
    db abs2() {return x*x+y*y;}
    db abs() {return sqrt(abs2());}
    db dist(Point p) {return (*this-p).abs(); }
    // Point unit() {return *this/abs();}
    // Point rot90() {return {y,-x};}
    bool quad() {return sign(y)==0?sign(x)>=0:sign(y)>0;}
}center;
int n,m;
struct P{
    Point p;
    int col;
}a[1005];
bool ang(P a, P b) {
    if ((a.p-center).quad()^(b.p-center).quad()) {
        return (a.p-center).quad();
    }
    return sign((a.p-center).det(b.p-center))>0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        cin>>a[i].p.x>>a[i].p.y;
        a[i].col=1;
    }
    for (int i=n+1; i<=n+m; ++i){
        cin>>a[i].p.x>>a[i].p.y;
        a[i].col=0;
    }
    vector<P> v;
    for (int i=n+m; i; i--) {
        v.push_back(a[i]);
    }
    int ans=0;
    for (int i=1; i<=n; ++i) {
        center=v.back().p;
        v.pop_back();
        auto b=v;
        sort(b.begin(),b.end(),ang);
        b.insert(b.end(),b.begin(),b.end());
        for (int j=0; j<n+m-i; ++j) {
            if (b[j].col) {
                // cout << "the" << j << "th point:" << b[j].p.x << ' ' << b[j].p.y << endl;
                Point mx = b[j].p-center;
                for (int k=j+1; k<b.size(); ++k) {
                    if (sign((b[j].p-center).det(b[k].p-center))<0 || k-j==n+m-i) break;
                    if (b[k].col) {
                        if (mx.det(b[k].p-b[j].p)>0) ++ans;
                    }
                    else {
                        if (mx.det(b[k].p-b[j].p)>0) mx=b[k].p-b[j].p;
                    }
                }
                // cout << j << ": "  << ans << endl;
            }
        }
        // cout << ans << endl;
    }
    cout << ans << '\n';
}