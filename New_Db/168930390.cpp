#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//#define d double
typedef long long ll;
const double eps = 1e-8;
int cmp(double a, double b)
{
    if (fabs(a - b) < eps) return 0;
    if (a > b) return 1;
    return -1;
}
int main()
{
    ll h, r;
    cin >> r >> h;
    if (h % r == 0)
    {
        cout << 2 * h / r + 1 << endl;
    }
    else {

        ll t = h / r;
        ll ans = t * 2;
        h %= r;
        if (h * 2 < r) ans += 1;
        else
        {
            ans += 2;
            if (4 * h * h >= 3 * r * r) ans++;
        }
        cout << ans;
    }
}
  			 	   	    	    	  				