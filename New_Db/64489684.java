import java.util.*;
import java.io.*;
public class a {
    public static PrintWriter out;
    public static void main(String[] args) throws IOException {
        FS sc = new FS(System.in);
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        int p = sc.nextInt();
        int[] a = new int[n];
        for (int i=0;i<n;i++) {
            if (sc.next().equals("half"))
                a[i] = 0;
            else
                a[i] = 1;
        }

        long money = 0;
        money += p/2;
        long count = 1;
        for (int i=n-2;i>=0;i--) {
            if (a[i] == 0) {
                money += count*p;
                count *= 2;
            }
            else {
                count *= 2;
                count += 1;
                money += ((count/2) * p) + (p/2);
            }
        }
        out.println(money);
        out.close();
    }
    
    static class FS {
    	BufferedReader br;
        StringTokenizer st;

    	public FS(InputStream i) {
            br = new BufferedReader(new InputStreamReader(i));
	        st = new StringTokenizer("");
        }

        public String next() throws IOException {
            if(st.hasMoreTokens())
                return st.nextToken();
    	    else
                st = new StringTokenizer(br.readLine());
            return next();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
	
        public long nextLong() throws IOException {
            return Long.parseLong(next());
    	}

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}
