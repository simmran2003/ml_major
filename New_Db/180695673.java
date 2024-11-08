
//package usacotraining;

import java.util.*;
import java.io.*;



public class ACSL4
{       
    public static void main(String[] args)throws IOException
    {
        Scanner bob = new Scanner(System.in);
        
        int N = bob.nextInt();
        bob.nextLine();
        
        ArrayList<str> set = new ArrayList<>();
        
        for(int i=0; i<N; i++)
        {
            set.add(new str(bob.nextLine()));
        }
        
        Collections.sort(set);
        
        String ans = "";
        
        for(str s: set)
        {
            ans+= s.s;
        }
        
        System.out.println(ans);
        
    }
    
    static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;
		// standard input
		public Kattio() { this(System.in, System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}
		// USACO-style file input
		public Kattio(String problemName) throws IOException {
			super(problemName + ".out");
			r = new BufferedReader(new FileReader(problemName + ".in"));
		}
		// returns null if no more input
		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) { }
			return null;
		}
		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
		public long nextLong() { return Long.parseLong(next()); }
	}
    
    

}
class str implements Comparable<str>
{
    String s;
    
    public str(String b)
    {
        s = b;
    }
    
    public int compareTo(str o)
    {
        
        return (s+o.s).compareTo(o.s+s);
    }
}
