

import java.util.*;
import java.io.*;
import java.util.Arrays;

public class Main {
	static Kattio cin = new Kattio();
	public static void main(String[] args) {
		// int a = io.nextInt();
		// int b = io.nextInt();
		// int c = io.nextInt();
		// io.print("sum is ");
		// io.println(a + b + c);
		int n = cin.nextInt();
		int k = cin.nextInt();
		int[] arr = new int[n];
		int mina = 10000;
		for(int i = 0;i<n;i++){
			arr[i] = cin.nextInt();
			mina = Math.min(mina, arr[i]);
		}
		for(int i = 0;i<n;i++){
			arr[i] -= mina;
		}
		int[] dp = new int[1000001];
		Arrays.fill(dp , k+2);
		dp[0] = 0;
		for(int i = 0;i<n;i++){
			if(arr[i] == 0){
				continue;
			}
			for(int j = 0;j<=1000000;j++){
				if(j >= arr[i]){
					dp[j] = Math.min(dp[j] , dp[j - arr[i]] + 1);
				}
			}
		}
		for(int i = 0;i<=1000000;i++){
			if(dp[i] <= k){
				cin.print(i + mina * k + " ");
			}
		}
		cin.close(); // make sure to include this line -- closes io and flushes the output
	}
}

class Kattio extends PrintWriter {
	private BufferedReader r;
	private StringTokenizer st = new StringTokenizer("");
	private String token;

	// standard input
	public Kattio() { this(System.in,System.out); }
	public Kattio(InputStream i, OutputStream o) {
		super(o);
		r = new BufferedReader(new InputStreamReader(i));
	}
	// USACO-style file input
	public Kattio(String problemName) throws IOException { 
		super(new FileWriter(problemName+".out"));
		r = new BufferedReader(new FileReader(problemName+".in"));
	}

	private String peek() {
		if (token == null)
			try {
				while (!st.hasMoreTokens()) {
					String line = r.readLine();
					if (line == null) return null;
					st = new StringTokenizer(line);
				}
				token = st.nextToken();
			} catch (IOException e) { }
		return token;
	}
	public boolean hasMoreTokens() { return peek() != null; }
	public String next() {
		String ans = peek(); 
		token = null;
		return ans;
	}
	
	public int nextInt() { return Integer.parseInt(next()); }
	public double nextDouble() { return Double.parseDouble(next()); }
	public long nextLong() { return Long.parseLong(next()); }
}

