/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."

*/



import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {
    static int MAX = 100005, DEPTH = 20, INF = 1000000007;
    static Map<Integer, Set<Integer>> graph = new HashMap<>();
    static int[] tin = new int[MAX];
    static int[] tout = new int[MAX];
    static int[] level = new int[MAX];
    static int[] subtreeSize = new int[MAX];
    static int[] parentNode = new int[MAX];
    static int[] ans = new int[MAX];
    static int[][] ancestor = new int[MAX][DEPTH];
    static int n, q, time;
    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();

        int test = 1;
        for (int t = 0; t < test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        n = sc.nextInt();
        q = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            graph.put(i, new HashSet<>());
        }
        for (int i = 1; i < n; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        Arrays.fill(ans, INF);

        dfs_lca(1, 1, 0);

        decompose(1, -1);

        update(1);
        for (int i = 0; i < q; i++) {
            int type = sc.nextInt();
            int node = sc.nextInt();
            if (type == 1) {
                update(node);
            }else {
                out.println(query(node));
            }
        }
    }

    private static void update(int currNode) { // paint a specified blue node in red
        int node = currNode;
        while (true) {
            ans[node] = Math.min(ans[node], distance(node, currNode)); // update the shortest distance to a red node from node
            if (node == parentNode[node]) {
                break;
            }
            node = parentNode[node]; // update min distance to a red node for ancestors nodes
        }
    }

    private static int query(int currNode) {
        int res = INF, node = currNode;
        while (true) {
            res = Math.min(res, ans[node] + distance(node, currNode)); // distance to move to an ancestor node + shortest distance between a red node and the ancestor node
            if (node == parentNode[node]) {
                break;
            }
            node = parentNode[node];
        }
        return res;
    }

    private static int distance(int u, int v) { // distance between nodes u and v
        return level[u] + level[v] - 2 * level[lca(u, v)];
    }

    private static int lca(int u, int v) { // find lca of node u and v using binary lifting in O(N log(N)) time
        if (isAncestor(u, v)) {
            return u;
        }
        if (isAncestor(v, u)) {
            return v;
        }
        for (int i = DEPTH - 1; i >= 0; i--) {
            if (!isAncestor(ancestor[u][i], v)) {
                u = ancestor[u][i];
            }
        }
        return ancestor[u][0];
    }

    private static boolean isAncestor(int u, int v) { // node u is the ancestor of node u and v
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    private static void decompose(int currNode, int parent) { // centroid decomposition
        dfs_size(currNode, -1);
        int centroidNode = dfs_centroid(currNode, currNode, subtreeSize[currNode]); // find the centroid
        if (parent == -1) {
            parent = centroidNode;
        }
        parentNode[centroidNode] = parent; // link to parent, used to form the decomposed tree
        for (int adjacentNode : graph.get(centroidNode)) { // decompose all children of centroid
            graph.get(adjacentNode).remove(centroidNode);
            decompose(adjacentNode, centroidNode);
        }
        graph.get(centroidNode).clear(); // remove edges connecting the centroid, forming a forest of trees
    }

    private static int dfs_centroid(int currNode, int parent, int totalSize) { // find the centroid.
        // centroid of a tree or graph, is a node whose removal from a forest of trees , where each of the resulting tree contains no more than totalSize / 2 nodes.
        // to do so, we start dfs from a node, and keep moving to a child with subtreeSize[child] >= subtreeSize[currNode].
        for (int adjacentNode : graph.get(currNode)) {
            if (adjacentNode == parent) {
                continue;
            }
            if (subtreeSize[adjacentNode] > totalSize / 2) {
                return dfs_centroid(adjacentNode, currNode, totalSize);
            }
        }
        return currNode;
    }

    private static void dfs_size(int currNode, int parent) { // find the subtree Size
        subtreeSize[currNode] = 1;
        for (int adjacentNode : graph.get(currNode)) {
            if (adjacentNode == parent) {
                continue;
            }
            dfs_size(adjacentNode, currNode);
            subtreeSize[currNode] += subtreeSize[adjacentNode];
        }
    }

    private static void dfs_lca(int currNode, int parent, int depth) {
        level[currNode] = depth;
        tin[currNode] = time++; // time of visiting this node in dfs
        ancestor[currNode][0] = parent; // link to 0th ancestor of currNode

        for (int i = 1; i < DEPTH; i++) {
            ancestor[currNode][i] = ancestor[ancestor[currNode][i - 1]][i - 1]; // set the links from currNode to ith ancestor
        }

        for (int adjacentNode : graph.get(currNode)) {
            if (adjacentNode == parent) {
                continue;
            }
            dfs_lca(adjacentNode, currNode, depth + 1);
        }
        tout[currNode] = time++; // time of visiting this node returning from dfs
    }


    public static FastReader sc;
    public static PrintWriter out;
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer str;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (str == null || !str.hasMoreElements())
            {
                try
                {
                    str = new StringTokenizer(br.readLine());
                }
                catch (IOException  end)
                {
                    end.printStackTrace();
                }
            }
            return str.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException end)
            {
                end.printStackTrace();
            }
            return str;
        }
    }
}