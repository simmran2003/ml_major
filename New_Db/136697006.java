import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class XeniaTree {
    static ArrayList<Integer>[] adj;
    static int memo[][], lev[], log;
    //memo[u][0] = parent node
    static void dfs(int u, int p) {
        memo[u][0] = p;
        for (int i = 1; i <= log; i++)
            memo[u][i] = memo[memo[u][i - 1]][i - 1];
        for (int v : adj[u]) {
            if (v != p) {
                lev[v] = lev[u] + 1;
                dfs(v, u);
            }
        }
    }
    static int lca(int u, int v) {
        if (lev[u] < lev[v]) {
            int temp = u;
            u = v;
            v = temp;
        }
        for (int i = log; i >= 0; i--) {
            if ((lev[u] - (int)Math.pow(2, i)) >= lev[v])
                u = memo[u][i];
        }
        if (u == v) return u;
        for (int i = log; i >= 0; i--) {
            if (memo[u][i] != memo[v][i]) {
                u = memo[u][i];
                v = memo[v][i];
            }
        }
        return memo[u][0];
    }

    static boolean[] vis;
    static int[] sz;
    static int[] parent;
    static int subTree(int node, int parent){
        if(vis[node]) return 0;
        sz[node] = 1;
        for (int c : adj[node]) {
            if (c == parent) continue;
            sz[node] += subTree(c, node);
        }
        return sz[node];
    }
    static int centroid(int node, int parent, int tot){
        for (int k : adj[node]) {
            if(k != parent && !vis[k] && sz[k] > tot/2){
                return centroid(k, node, tot);
            }
        }
        return node;
    }
    static void findAll(int node, int p){
        subTree(node, -1);
        int c = centroid(node, -1, sz[node]);
        vis[c] = true;
        parent[c] = p;
        for (int k : adj[c]) {
            if(!vis[k]) findAll(k, c);
        }
    }

    static int[] depth;
    static int curh = 0;
    static void depthDFS(int node, int parent){
        depth[node] = curh;
        for (int k : adj[node]) {
            if(k == parent) continue;
            curh++;
            depthDFS(k, node);
            curh--;
        }
    }

    static int[] mndis;
    static void update(int node) {
        //update node color to red
        mndis[node] = Math.min(mndis[node], 0);
        int curnode = node;
        while (parent[curnode] != -1){
            curnode = parent[curnode];
            int lca = lca(node, curnode);
            int d = depth[node] + depth[curnode] - (depth[lca] * 2);
            mndis[curnode] = Math.min(mndis[curnode], d);
        }
    }

    static int query(int node){
        //query closest red node
        int out = mndis[node];
        int curnode = node;
        while (parent[curnode] != -1){
            curnode = parent[curnode];
            if(mndis[curnode] == Integer.MAX_VALUE) continue;
            int lca = lca(node, curnode);
            int d = depth[node] + depth[curnode] - (depth[lca] * 2);
            out = Math.min(out, d + mndis[curnode]);
        }
        return out;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        adj = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) adj[i] = new ArrayList<Integer>();
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            adj[a].add(b);
            adj[b].add(a);
        }
        log = (int)Math.ceil(Math.log(n) / Math.log(2));
        memo = new int[n + 1][log + 1];
        lev = new int[n + 1];
        vis = new boolean[n + 1];
        for (int i = 0; i <= n; i++) Arrays.fill(memo[i], -1);
        dfs(1, 1);
        sz = new int[n + 1];
        subTree(1, 1);
        parent = new int[n + 1];
        findAll(1, -1);
        depth = new int[n + 1];
        depthDFS(1, -1);
        mndis = new int[n + 1];
        for (int i = 0; i <= n; i++) mndis[i] = Integer.MAX_VALUE;
        update(1);
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken());
            if(t == 1){
                update(v);
            }else{
                System.out.println(query(v));
            }
        }
    }
}
