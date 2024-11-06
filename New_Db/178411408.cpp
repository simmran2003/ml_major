#include "bits/stdc++.h"
using namespace std;

typedef double ld;
typedef long long ll;
#define f first
#define s second

const int N=500;
int n,m;

struct pt{
  int x,y;
};

pt R[N], B[N];
int cnt[N][N];

int main(){
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> R[i].x >> R[i].y;
  }
  for(int i=0; i<m; i++){
    cin >> B[i].x >> B[i].y;
  }
  sort(R, R+n, [&](pt a, pt b){ return a.y<b.y; });
  sort(B, B+m, [&](pt a, pt b){ return a.y<b.y; });

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<m; k++){
        if(!(R[i].y<=B[k].y && B[k].y<R[j].y)) continue;
        pair<int,int> u={R[j].x-R[i].x, R[j].y-R[i].y};
        pair<int,int> v={B[k].x-R[j].x, B[k].y-R[j].y};
        cnt[i][j]+=ll(u.f)*v.s-ll(u.s)*v.f>0;
      }
    }
  }

  int ans=0;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      for(int k=j+1; k<n; k++){
        ans+=cnt[i][j]+cnt[j][k]==cnt[i][k];
      }
    }
  }
  cout << ans;
}


	 			  	 	   				 		  	 	 					
			 	    	 	    	 	 	  	