#include <iostream>
#include <vector>
#include <cmath>
#define int long long
using namespace std;
bool c(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {return ((x1==x3 && y1==y3) || (x1==x4 && y1==y4) || (x2==x3 && y2==y3) || (x2==x4 && y2==y4));}
bool b(int x1, int y1, int x2, int y2, int x3, int y3) {return abs(sqrtl((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3))+sqrtl((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3))-sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))<1e-9;}
long double f(int x1, int y1, int x2, int y2, int x3, int y3) {return 16.0*(long double)min((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3),(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3))/(long double)max((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3),(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));}
long double ang(int x1, int y1, int x2, int y2) {return atan2(y2-y1,x2-x1);}
main()
{
int t;
cin >> t;
while (t--)
{
int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
if (c(x1,y1,x2,y2,x5,y5,x6,y6)) swap(x3,x5),swap(y3,y5),swap(x4,x6),swap(y4,y6);
else if (c(x3,y3,x4,y4,x5,y5,x6,y6)) swap(x1,x5),swap(y1,y5),swap(x2,x6),swap(y2,y6);
if (!c(x1,y1,x2,y2,x3,y3,x4,y4)) cout << "NO\n";
else
{
if (x1==x3 && y1==y3) swap(x1,x2),swap(y1,y2);
else if (x1==x4 && y1==y4) swap(x1,x2),swap(y1,y2),swap(x3,x4),swap(y3,y4);
else if (x2==x4 && y2==y4) swap(x3,x4),swap(y3,y4);
long double a=abs(ang(x3,y3,x4,y4)-ang(x2,y2,x1,y1));
a=min(a,2*acos(-1)-a);
if (a>0 && a<=acos(-1)/2)
{
if (b(x1,y1,x2,y2,x6,y6) && b(x3,y3,x4,y4,x5,y5)) swap(x5,x6),swap(y5,y6);
if (!(b(x1,y1,x2,y2,x5,y5) && b(x3,y3,x4,y4,x6,y6))) cout << "NO\n";
else
{
if (sqrt(f(x1,y1,x2,y2,x5,y5))>=1 && sqrt(f(x3,y3,x4,y4,x6,y6))>=1) cout << "YES\n";
else cout << "NO\n";
}
}
else cout << "NO\n";
}
}
}