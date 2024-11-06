import java.util.*;
import java.io.*;

public class File {
    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }

            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
	
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		
		
		
		
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		int s = sc.nextInt(); // Start spy (current pos)
		int f = sc.nextInt(); // End spy
		int currT = 1;
		StringBuilder sb = new StringBuilder();
		
		for (int i = 0; i < m && s != f; i++) {
			int t = sc.nextInt();
			int L = sc.nextInt();
			int R = sc.nextInt();
			
			while (currT < t) {
				if (s > f) {
					s--;
					sb.append("L");
    			}
    			else if (s < f) {
					s++;
					sb.append("R");
    			}
    			else {
    			    break;
    			}
    			
    			currT++;
			}
			
			if (s == f) {
				break; // We've finished.
			}
			else if (L <= s && s <= R) {
			    sb.append("X");
			}
			else if (s > f && !(L <= s-1 && s-1 <= R)) {
				s--;
				sb.append("L");
			}
			else if (s < f && !(L <= s+1 && s+1 <= R)) {
				s++;
				sb.append("R");
			}
			else {
			    sb.append("X");
			}
			
			currT++;
		}
		
		if (s > f) {
		    for (int i = 0; i < s - f; i++) {
		        sb.append("L");
		    }
		}
		else if (s < f) {
			for (int i = 0; i < f - s; i++) {
			    sb.append("R");
			}
		}
		
		
		out.println(sb.toString());
		
		
		out.close();
	}
}











	