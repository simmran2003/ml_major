/**
 * author: derrick20
 * created: 7/6/21 11:11 PM
 */
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class E_XeniaAndTreeRedo {
    static FastScanner sc = new FastScanner();
    static PrintWriter out = new PrintWriter(System.out);
    
    public static void main(String[] args) {
        N = sc.nextInt();
        int Q = sc.nextInt();
        adjList = new ArrayDeque[N];
        Arrays.setAll(adjList, i -> new ArrayDeque<>());
        for (int i = 0; i < N - 1; i++) {
            int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
            adjList[u].add(v);
            adjList[v].add(u);
        }
        sub = new int[N];
        centroidParent = new int[N];
        parent = new int[N];
        blocked = new boolean[N];
        decompose(0, -1);
        LOG = Integer.numberOfTrailingZeros(Integer.highestOneBit(N - 1));
        jump = new int[LOG + 1][N];
        depth = new int[N];
        depth[0] = 0;
        jump[0][0] = 0;
        dfs(0);
        minDist = new int[N];
        Arrays.fill(minDist, oo);
        update(0);
        while (Q-->0) {
            int type = sc.nextInt();
            int u = sc.nextInt() - 1;
            if (type == 1) {
                update(u);
            } else if (type == 2) {
                out.println(query(u));
            }
        }
        out.close();
    }

    static ArrayDeque<Integer>[] adjList;
    static int[] depth, sub, centroidParent;
    static int[] parent;
    static int[][] jump;
    static boolean[] blocked;
    static int N, LOG;
    static int oo = (int) 1e9;
    static int[] minDist;

    static int query(int node) {
        int curr = node;
        int ans = oo;
        while (curr != -1) {
            ans = min(ans, minDist[curr] + dist(node, curr));
            curr = centroidParent[curr];
        }
        return ans;
    }
    
    static void update(int node) {
        int curr = node;
        while (curr != -1) {
            minDist[curr] = min(minDist[curr], dist(curr, node));
            curr = centroidParent[curr];
        }
    }
    
    static int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
    }

    static int LCA(int u, int v) {
        if (depth[u] > depth[v]) {
            int temp = u;
            u = v;
            v = temp;
        }
        int diff = depth[v] - depth[u];
        for (int k = 0; k <= LOG; k++) {
            if ((diff & (1 << k)) > 0) {
                v = jump[k][v];
            }
        }
        if (u == v) return u;
        for (int k = LOG; k >= 0; k--) {
            if (jump[k][u] != jump[k][v]) {
                u = jump[k][u];
                v = jump[k][v];
            }
        }
        return jump[0][u];
    }

    static void dfs(int node) {
        for (int k = 1; k <= LOG; k++) {
            jump[k][node] = jump[k - 1][jump[k - 1][node]];
        }
        for (int adj : adjList[node]) {
            if (adj != jump[0][node]) {
                jump[0][adj] = node;
                depth[adj] = depth[node] + 1;
                dfs(adj);
            }
        }
    }

    static void decompose(int node, int par) {
        parent[node] = -1;
        flood(node);
        ArrayDeque<Integer> q = new ArrayDeque<>(List.of(node));
        int centroid = -1;
        int bestBalance = oo;
        HashSet<Integer> vis = new HashSet<>();
        while (q.size() > 0) {
            int curr = q.pollFirst();
            int balance = sub[node] - sub[curr]; // key bug, wrong component size
            for (int adj : adjList[curr]) {
                if (blocked[adj]) continue;
                if (adj != parent[curr]) {
                    balance = max(balance, sub[adj]);
                }
                if (!vis.contains(adj)) {
                    vis.add(adj);
                    q.add(adj);
                }
            }
            if (balance < bestBalance) {
                bestBalance = balance;
                centroid = curr;
            }
        }
        blocked[centroid] = true;
        centroidParent[centroid] = par;
        for (int adj : adjList[centroid]) {
            if (!blocked[adj]) {
                decompose(adj, centroid);
            }
        }
    }

    static void flood(int node) {
        sub[node] = 1;
        for (int adj : adjList[node]) {
            if (!blocked[adj] && adj != parent[node]) {
                parent[adj] = node;
                flood(adj);
                sub[node] += sub[adj];
            }
        }
    }

    static class FastScanner {
        private int BS = 1 << 16;
        private char NC = (char) 0;
        private byte[] buf = new byte[BS];
        private int bId = 0, size = 0;
        private char c = NC;
        private double cnt = 1;
        private BufferedInputStream in;
    
        public FastScanner() {
            in = new BufferedInputStream(System.in, BS);
        }
    
        public FastScanner(String s) {
            try {
                in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
            } catch (Exception e) {
                in = new BufferedInputStream(System.in, BS);
            }
        }
    
        char getChar() {
            while (bId == size) {
                try {
                    size = in.read(buf);
                } catch (Exception e) {
                    return NC;
                }
                if (size == -1) return NC;
                bId = 0;
            }
            return (char) buf[bId++];
        }
    
        int nextInt() {
            return (int) nextLong();
        }
    
        long nextLong() {
            cnt = 1;
            boolean neg = false;
            if (c == NC) c = getChar();
            for (; (c < '0' || c > '9'); c = getChar()) {
                if (c == '-') neg = true;
            }
            long res = 0;
            for (; c >= '0' && c <= '9'; c = getChar()) {
                res = (res << 3) + (res << 1) + c - '0';
                cnt *= 10;
            }
            return neg ? -res : res;
        }
    
        double nextDouble() {
            boolean neg = false;
            if (c == NC) c = getChar();
            for (; (c < '0' || c > '9'); c = getChar()) {
                if (c == '-') neg = true;
            }
            double cur = nextLong();
            if (c != '.') {
                return neg ? -cur : cur;
            } else {
                double frac = nextLong() / cnt;
                return neg ? -cur - frac : cur + frac;
            }
        }
    
        String next() {
            StringBuilder res = new StringBuilder();
            while (c <= 32) c = getChar();
            while (c > 32) {
                res.append(c);
                c = getChar();
            }
            return res.toString();
        }
    
        String nextLine() {
            StringBuilder res = new StringBuilder();
            while (c <= 32) c = getChar();
            while (c != '\n') {
                res.append(c);
                c = getChar();
            }
            return res.toString();
        }
    
        boolean hasNext() {
            if (c > 32) return true;
            while (true) {
                c = getChar();
                if (c == NC) return false;
                else if (c > 32) return true;
            }
        }
    }
    
    static void ASSERT(boolean assertion, String message) {
        if (!assertion) throw new AssertionError(message);
    }
    
    static void ASSERT(boolean assertion) {
        if (!assertion) throw new AssertionError();
    }
}