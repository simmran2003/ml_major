#include<bits/stdc++.h>

using namespace std;

int BLK_SIZE;

bool check(int i, int j) {
    return (i / BLK_SIZE) == (j / BLK_SIZE);
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    int a[n];

    for(int i=0; i<n; i++) cin>>a[i];

    int jumps[n], next[n], last[n];
    int begin_block[n]; // beginning of the block in which i belongs

    BLK_SIZE = sqrt(n);

    for(int i=n-1; i>=0; i--) {
        if((i + a[i]) >= n) {
            jumps[i] = 1;
            next[i] = -1;
            last[i] = i;
        } else if(check(i, i+a[i])) {
            jumps[i] = jumps[i+a[i]] + 1;
            next[i] = next[i+a[i]];
            last[i] = last[i+a[i]];
        } else {
            jumps[i] = 1;
            next[i] = i + a[i];
            last[i] = i;
        }
    }

    begin_block[0] = 0;
    for(int i=1; i<n; i++) {
        if(check(i, i-1)) {
            begin_block[i] = begin_block[i-1];
        } else {
            begin_block[i] = i;
        }
    }

    while(m--) {
        int type;
        cin>>type;
        if(type == 0) {
            //update
            int idx, val;
            cin>>idx>>val;
            idx-=1;
            int beg = begin_block[idx];
            a[idx] = val;
            while(idx >= beg) {
                if((idx + a[idx]) >= n) {
                    jumps[idx] = 1;
                    next[idx] = -1;
                    last[idx] = idx;
                } else if(check(idx, idx+a[idx])) {
                    jumps[idx] = jumps[idx+a[idx]] + 1;
                    next[idx] = next[idx+a[idx]];
                    last[idx] = last[idx+a[idx]];
                } else {
                    jumps[idx] = 1;
                    next[idx] = idx + a[idx];
                    last[idx] = idx;
                }
                idx--;
            }
        } else {
            // query
            int idx;
            cin>>idx;
            idx-=1;
            int numJumps = 0;
            int lastVisited = idx;
            while(idx != -1) {
                numJumps += jumps[idx];
                lastVisited = last[idx];
                idx = next[idx];
            }

            cout<<lastVisited+1<<" "<<numJumps<<"\n";
        }
    }


    return 0;
}















