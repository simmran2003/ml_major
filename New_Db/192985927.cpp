//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define ll long long 
#define ff first
#define ss second
#define pb push_back 
#define pf push_front
#define UseOFF ios_base::sync_with_stdio(0);cin.tie(0), cout.tie(0);
#define sz size
using namespace std ;
const ll N = 1e5 + 111 ;
const ll mod = 1e9 + 7 ;
ll sum ;
deque < ll > v2 ;
vector < ll > v ;
ll a[ N ] ;
map < ll, ll > mp ;
int main()
{
    UseOFF ;
    ll n ;
    cin >> n ;
    for( int i = 1 ; i <= n ; i++ )
    {
        cin >> a[ i ] ;
        mp[ a[ i ] ]++ ;
    }
    sort( a + 1, a + n + 1 ) ;
    vector < ll > ans ;
    for( int i = 1 ; i <= n ; i++ )
    {
        if( mp[ a[ i ] ] <= 0 ) continue ;
        mp[ a[ i ] ]-- ;
        ans.pb( a[ i ] ) ;
        ll cnt = 0 ;
        ll x = a[ i ] ;
        for( int j = a[ i ] + 1 ; j <= 7 ; j++ )
        {
            //cout << i << " " << j << " || " << a[ i ] << " " << mp[ j ] << " " << x << '\n' ;
            if( cnt == 2 ) break ;
            if( mp[ j ] > 0 && j % x == 0 && x < j )
            {
                mp[ j ]-- ;
                x = j ;
                cnt++ ;
                ans.pb( j ) ;
            }
        }
        if( cnt < 2 ) 
        {
            //cout << i << " || " ;
            cout << -1 ;
            return 0 ;
        }
    }
    if( ans.sz() == 0 ) cout << -1 ;
    for( int i = 0 ; i + 2 < ans.sz() ; i++ )
    {
        cout << ans[ i ] << " " << ans[ i + 1 ] << " " << ans[ i + 2 ] << '\n' ;
        i += 2 ;
    }
}