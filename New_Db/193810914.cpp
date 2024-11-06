#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void read_input_to_vec_ll(string& input, vector<long long>& v) {
    string curr = "";
    for (auto i : input) {
        if (i == ' ') {
            if (curr.size() > 0) v.push_back(stoll(curr));
            curr = "";
        }
        else curr += i;
    }
    if (curr.size() > 0) v.push_back(stoll(curr));
}

void read_input_to_vec_int(string& input, vector<int>& v) {
    string curr = "";
    for (auto i : input) {
        if (i == ' ') {
            if (curr.size() > 0) v.push_back(stoi(curr));
            curr = "";
        }
        else curr += i;
    }
    if (curr.size() > 0) v.push_back(stoll(curr));
}

class CentroidDecomposition {
public:
    int n;
    vector<int> num, removed;
    vector<vector<int>> e;
    vector<vector<pair<int, int>>> parents, descendents;
    CentroidDecomposition(int numNodes, vector<vector<int>>& edges) {
        n = numNodes; 
        num = vector<int>(n); 
        removed = vector<int>(n);
        e = edges;          
        parents = vector<vector<pair<int, int>>>(n);
        dfs(0,0);
        buildtree(centroid(0,0,n));
        gen_descendents();
    }
    int dfs(int curr, int p) {
        // Find the size of the subtree
        num[curr] = 1;
        for (int node : e[curr]) {
            if (node != p && removed[node] == 0) num[curr] += dfs(node, curr);
        }
        return num[curr];
    }
    
    int centroid(int curr, int p, int total) {
        // Find the centroid of the current component
        for (int node : e[curr]) {
            if (node != p && removed[node] == 0 && num[node]>total/2) return centroid(node, curr, total);
        }
        return curr;
    }
    
    void buildtree(int curr) {
        // Process the component with centroid equal to v
        removed[curr] = 1;
        queue<pair<int, int>> q;
        q.push({curr, 0});
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            parents[node].emplace_back(curr, dist);
            for (int next : e[node]) {
                if (removed[next] == 0 && (parents[next].empty() || parents[next].back().first != curr)) q.push({next, dist+1});
            }
        }
        for (int node : e[curr]) {
            if (removed[node] == 0) buildtree(centroid(node, node, dfs(node, node)));
        }
    }
    vector<vector<pair<int, int>>> get_centroid_parents() {
        return parents;
    }
    void gen_descendents() {
        descendents = vector<vector<pair<int, int>>>(n);
        for (int curr = 0; curr < n; curr++) {
            for (auto &p : parents[curr]) {
                int node = p.first;
                int dist = p.second;
                descendents[node].push_back({curr,dist});
            }
        }
    }
    vector<vector<pair<int, int>>> get_centroid_desc() {
        return descendents;
    }
};


vector<vector<pair<int, int>>> parents;
vector<int> best;

void update(int curr) {
    best[curr] = 0;
    for (auto &p : parents[curr]) {
        int node = p.first;
        int dist = p.second;
        best[node] = min(best[node], best[curr] + dist);
    }
}

int query(int curr) {
    int ans = best[curr];
    for (auto &p : parents[curr]) {
        int node = p.first;
        int dist = p.second;
        ans = min(ans, best[node] + dist);
    }
    return ans;
}


int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    int totalTests = 1;
    for (int testNumber = 0; testNumber < totalTests; testNumber++) {
        int n, m; cin >> n >> m;
        vector<vector<int>> e(n);

        for (int i = 0; i < n-1; i++) {
            int n1,n2; cin >> n1 >> n2;
            n1--; n2--;
            e[n1].push_back(n2);
            e[n2].push_back(n1);
        }

        CentroidDecomposition cd = CentroidDecomposition(n, e);

        best = vector<int>(n, INT_MAX-10000000);
        parents = cd.get_centroid_parents();

        /*
        for (int i = 0; i < n; i++) {
            int node = i;
            cout << "Node parents of: " << node << endl;
            for (auto &p : parents[node]) {
                cout << p.first << "," << p.second << endl;
            }
        }
        cout << "\n\n\n";*/
        
        update(0);
        for (int i = 0; i < m; i++) {
            int type, node; cin >> type >> node; node--;
            if (type == 1) {
                update(node);
            }
            else {
                int dist = query(node);
                cout << dist << endl;
            }
        }
    }
    return 0;
}