#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define el '\n'
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef unsigned long long ull;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e4 + 5, mod = 1e9 + 7;

int n, cx, cy;
int blocked[N];
int dp[N][1 << 3][2];

int add(int a, int b)
{
    return (a + b) % mod;
}

bool mnwr(int msk, int bit)
{
    return msk & (1 << bit);
}

int solve(int col, int msk, bool move)
{
    if(col == n)
        return move && (msk == 0); // lazm ma7ot4 7aga bra el board

    int &ret = dp[col][msk][move];
    if(~ret)
        return ret;

    ret = 0;
    for(int row = 0; row < 3; row++)
    {
        if(mnwr(msk, row) && mnwr(blocked[col], row))
            return ret = 0; // fy cell blocked w ma7tot fyha domino (invalid state)
        else if(mnwr(blocked[col], row))
            msk |= (1 << row); // el cell dy blocked asln
    }

    bool newMove = move;
    
    for(int row = 0; row < 3; row++)
        newMove |= (mnwr(msk, row) && !mnwr(blocked[col], row) && cx == row && (cy == col + 1 || cy == col - 2)); 

    ret = add(ret, solve(col + 1, msk ^ 7, newMove)); // fill unfilled cells with horizontal tiles

    if((msk & 3) == 0) // awl etnin empty
        ret = add(ret, solve(col + 1, (msk | 3) ^ 7, newMove | (cx == 2 && cy == col)));
    if((msk & 6) == 0) // a5r etnin empty
        ret = add(ret, solve(col + 1, (msk | 6) ^ 7, newMove | (cx == 0 && cy == col)));
    return ret;
}

void doWork()
{
    char in;
    cin >> n;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> in;
            if(in == 'O')
                cx = i, cy = j;
            if(in != '.')
                blocked[j] |= (1 << i);
        }
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0);
}

int main()
{
    FIO
    int T = 1;
//    cin >> T;
    while(T--)
        doWork();
}