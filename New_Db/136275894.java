import java.io.*;
import java.util.*;

public class Main {

	static List<Integer>[] adj, cen_adj;
	static boolean[] cen_m;
	static int n, m, LOG=17, INF;
	static int[] parent, best, depth;
	static int[][] up; // up[v][j] is 2^j-th ancestor of v
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();

		/******  CODE STARTS HERE  *****/
		//------------------------------------------------------------------------------------------------------------
		
		n=fs.nextInt(); m=fs.nextInt();
		INF = n*10;
		adj = new ArrayList[n];
		cen_adj = new ArrayList[n];
		for(int i=0; i<n; i++)adj[i]=new ArrayList<>();
		for(int i=0; i<n; i++)cen_adj[i]=new ArrayList<>();
		
		for(int i=0; i<n-1; i++) {
			int u=fs.nextInt()-1, v=fs.nextInt()-1;
			adj[u].add(v);
			adj[v].add(u);
		}
		cen_m = new boolean[n];
		parent = new int[n];
		
		int root = decompose(0, -1);
		
		best = new int[n];
		Arrays.fill(best, INF);
		
		depth = new int[n];
		up = new int[n][LOG];
		
		dfs(0, -1);
		
		update(0);
		
		for(int i=0; i<m; i++) {
			int t=fs.nextInt(), v=fs.nextInt()-1;
			if(t==1) {
				update(v);
			}else {
				System.out.println(query(v));
			}
		}
	}
	
	static void dfs(int a, int pa) {
		for(int b : adj[a]) {
			if(b == pa)continue;
			depth[b] = depth[a] + 1;
			up[b][0] = a; // a is parent of b
			for(int j = 1; j < LOG; j++) {
				up[b][j] = up[up[b][j-1]][j-1];
			}
			dfs(b, a);
		}
	}
	
	static int get_lca(int a, int b) { // O(log(N))
		if(depth[a] < depth[b]) {
			int temp = a;
			a = b;
			b = temp;
		}
		// 1) Get same depth.
		int k = depth[a] - depth[b];
		for(int j = LOG - 1; j >= 0; j--) {
			if((k & (1 << j)) != 0) {
				a = up[a][j]; // parent of a
			}
		}
		// 2) if b was ancestor of a then now a==b
		if(a == b) {
			return a;
		}
		// 3) move both a and b with powers of two
		for(int j = LOG - 1; j >= 0; j--) {
			if(up[a][j] != up[b][j]) {
				a = up[a][j];
				b = up[b][j];
			}
		}
		return up[a][0];
	}
	
	static void update(int v) {
		best[v] = 0;
		int u = v;
		while(parent[u] != -1) {
			u = parent[u];
			best[u] = Math.min(best[u], dist(u, v));
		}
	}
	
	static int query(int v) {
		int ans = best[v];
		int u = v;
		while(parent[u] != -1) {
			u = parent[u];
			ans = Math.min(ans, dist(u, v) + best[u]);
		}
		return ans;
	}
	
	static int dist(int u, int v) {
		  int lc = get_lca(u, v); // implement this
		  return depth[u] + depth[v] - 2 * depth[lc];
	}
	
	static int dfs(int root, int pa, int[] s){
		s[root] += 1;
		int no = 1;
		for(int nbr: adj[root]) {
			if(!cen_m[nbr] && nbr!=pa) {
				no += dfs(nbr, root, s);
				s[root] += s[nbr];
			}
		}
		return no;
	}
	
	static int get_centroid(int root, int pa, int no, int[] s) {
		
		boolean isCentroid = true;
		int heaviest_child = -1;
		
		for(int nbr: adj[root]) {
			if(!cen_m[nbr] && nbr!=pa) {
				
				if(s[nbr] > no/2)isCentroid = false;
				
				if(heaviest_child==-1 || s[heaviest_child] < s[nbr])
					heaviest_child = nbr;
				
			}
		}
		
		if(isCentroid && no-s[root] <= no/2)return root;
		
		return get_centroid(heaviest_child, root, no, s);
	}
	
	static int get_centroid(int root, int pa) {
		
		int[] s = new int[n];
		int no = dfs(root, pa, s);
		
		return get_centroid(root, pa, no, s);
	}
	
	static int decompose(int root, int pa) {
		int cen_tr = get_centroid(root, pa);
		parent[cen_tr] = pa;
		cen_m[cen_tr] = true;
		
		for(int nbr: adj[cen_tr]) {
			if(!cen_m[nbr] && nbr!=pa) {
				int cen_sbtr = decompose(nbr, cen_tr);
				cen_adj[cen_tr].add(cen_sbtr);
				cen_adj[cen_sbtr].add(cen_tr);
			}
		}
		
		return cen_tr;
	}
    
	//******  CODE ENDS HERE  *****
	//----------------------------------------------------------------------------------------------------------------
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	
	//----------- FastScanner class for faster input---------------------------
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}