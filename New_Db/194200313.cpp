  #include <bits/stdc++.h>
  using namespace std;
  #define mod 1000000007

  /*bool isprime(int n){
    for (int i=2;i*i<=n;i++){
      if (n%i==0) return 0;
    }
    return 1;
  }*/

  bool cmp(long long a, long long b){
        return a>b;
  }

  int main()
  {
    long long n,x=0,y;
    cin >> n;
    y=n-2;
    for (int i=2;i<n;i++){
      long long faken=n;
      while (faken){
        x+=faken%i;
        faken/=i;
      }
    }

    cout << x/__gcd(x,y) << "/" << y/__gcd(x,y);

  }
