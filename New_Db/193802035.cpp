/**
 * Surly
 * 16.02.2023
**/

#include<bits/stdc++.h>
 
#define pb push_back
#define nw cout<<"\n";
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define mpr make_pair
#define memset(v,x) memset(v,x,sizeof(v))
#define len(v) int(v.size())
#define put(v,x) v.insert(begin(v),x)
#define wis(x) std::cerr <<"Line"<<__LINE__<<": "<<#x<<" is "<<x<<std::endl

using namespace std;
  
typedef int_fast64_t ll; 
typedef vector<int> vi;
typedef vector<ll> vll;

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] --> [", _debug(__VA_ARGS__);
#endif

template<typename type>istream& operator>>(istream& istream , vector<type> &v) {
if(v.size()) { for(auto &i : v) { istream>> i; } return istream; }
istream>>ws;  string str; getline(istream , str); stringstream  stream(str);
move(istream_iterator<type>(stream),istream_iterator<type>(),back_inserter(v));
return istream;}template<typename type>ostream& operator<<(ostream& ostream , vector<type> &
v){move(all(v),ostream_iterator<type>(ostream," ")); nw; return ostream;}
 

  int main ( void )
{                 
                         time_t Time;
                          time(&Time);
                   cerr<<ctime(&Time);
             ios_base::sync_with_stdio(false);
               cin.tie(NULL),cout.tie(NULL);
               cout<<fixed<<setprecision(2);
    auto starttime=chrono::steady_clock::now();
    
    int n; cin>> n;
    int count[8]{0};
    for(int i=0;i<n;i++) {
     int x; cin>> x;
     assert(x<=8);
     count[x]++;
    }
    if(count[5] or count[7]) {
     cout<< -1;
     exit(0);
    }
    else if(count[1]!=count[2]+count[3] or count[1]!=count[4]+count[6] or count[4]>count[2]) {
     cout<< -1;
     nw;
     exit(0);
    }
    while(count[4]) {
     cout<<"1 2 4\n";
     count[1]--,count[2]--,count[4]--;
    }
    while(count[2]) {
     cout<<"1 2 6\n";
     count[1]--,count[2]--,count[6]--;
    }
    while(count[6]) {
     cout<<"1 3 6\n";
     count[1]--,count[3]--,count[6]--;
    }
    
    
    
    auto endtime=chrono::steady_clock::now(); 
    cerr<<endl<<"Elapsed Time: "
         <<chrono::duration_cast<chrono::milliseconds> (endtime-starttime).count()
          <<" milliseconds"<<endl;
    return 0;
 }

