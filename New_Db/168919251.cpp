#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#define endl '\n';
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10, mod = 1e9 + 7;


LL h, r;
LL cnt = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   
    cin >> r >> h;
    cnt += h / r * 2;
    if (h % r >= (double)r / 2)
    {
        if (h % r < sqrt(3.0) * (double)r / 2.0) cnt += 2;
        else cnt += 3;
    }
    else cnt++;

    cout << cnt << endl;

    return 0;
}
	 			 			 	  				  			 	  	