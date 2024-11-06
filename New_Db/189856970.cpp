#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n,m,s,f;
    int i;
    cin>>n>>m>>s>>f;
    std::vector<std::vector<int>> v;
    for(i = 0;i<m;i++){
        int a,b,c;
        std::vector<int> v1;
        cin>>a>>b>>c;
        v1.push_back(a);
        v1.push_back(b);
        v1.push_back(c);
        v.push_back(v1);
    }
    int t = 1;i = 0;
    while(s!=f){
        if(i < v.size() and t==v[i][0]){
            if((s>=v[i][1] and s<=v[i][2]) || (f>s and s+1>=v[i][1] and s+1<=v[i][2]) || ((s>f)and s-1>=v[i][1] and s-1<=v[i][2])){
                // cout<<s<<endl;
              cout<<'X';  
            }
            else if(f>s){
                cout<<'R';
                s++;
            }
            else{
                cout<<'L';
                s--;
            }
            i++;
        }
        else{
            if(f>s){
                cout<<'R';
                s++;
            }
            else{
                cout<<'L';
                s--;
            }       
            
        }
        t++;
    }




       

        cout << "\n";
    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}