import java.io.*;
import java.util.StringTokenizer;

public class O {
    Scanner in;
    PrintWriter out;
    public static void main(String[] args)throws IOException {
        new O().run();
    }

    void run() throws IOException{
        out = new PrintWriter(System.out);
        in = new Scanner(System.in);
        int n = in.nextInt();
        int p = in.nextInt();
        int[] num = new int[n];
        long count = 0;
        for (int i = 0; i < n; i++) {
            String s = in.next();
            if (s.equals("halfplus")) {
                num[i] = 1;
                count++;
            }
        }
        long sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (num[i] == 1) {
                sum = sum * 2 + 1;
            } else {
                sum *= 2;
            }
        }
        sum = sum * p - count * p / 2;
        out.println(sum);
        out.flush();

    }

    long gcd(long a, long b) {return (b == 0) ? a : gcd(b, a % b);}
    int gcd(int a, int b) {return (b == 0) ? a : gcd(b, a % b);}

    long pow(long a, long b) {
        if (b == 0 || a == 1) {
            return 1;
        }
        long o = 1;
        int mod = (int) (1e9 + 7);
        for (long p = b; p > 0; p >>= 1) {
            if ((p & 1) == 1) {
                o = (o * a) % mod;
            }
            a = (a * a) % mod;
        }
        return o;
    }
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            String x = next();
            StringBuilder sb = new StringBuilder("0");
            double res = 0, f = 1;
            boolean dec = false, neg = false;
            int start = 0;
            if (x.charAt(0) == '-') {
                neg = true;
                start++;
            }
            for (int i = start; i < x.length(); i++) {
                if (x.charAt(i) == '.') {
                    res = Long.parseLong(sb.toString());
                    sb = new StringBuilder("0");
                    dec = true;
                } else {
                    sb.append(x.charAt(i));
                    if (dec) {
                        f *= 10;
                    }
                }
            }
            res += Long.parseLong(sb.toString()) / f;
            return res * (neg ? -1 : 1);
        }

        public  boolean ready() throws IOException {
            return br.ready();
        }

        public long[] nextlongArray(int n)throws IOException {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextLong();
            }
            return a;
        }

        public int[] nextIntArray(int n)throws IOException {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }
    }//
}

			 	 		 	   	 		 	     	   	 	