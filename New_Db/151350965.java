import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
/**
 *
 * @author eslam
 */
public class IncreaseSubarraySums {

    public static long pow(long n, int l) {
        if (l == 0) {
            return 1;
        }
        long t = n;
        for (int i = 1; i < l; i++) {
            n = (n * t);
        }
        return n;
    }

    static class FastReader {

        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
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

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    static FastReader input = new FastReader();

    public static void main(String[] args) throws IOException {
        BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = input.nextInt();
        long a[] = new long[n];

        for (int i = 0; i < n; i++) {
            a[i] = input.nextInt();
        }
        String w = input.next();
        long s1 = 0;
        long s2 = 0;
        for (int i = 0; i < n; i++) {
            if (w.charAt(i) == 'A') {
                s1 += a[i];
            } else {
                s2 += a[i];
            }
        }
        long max = s2;
        long ts1 = s1;
        long ts2 = s2;
        for (int i = 0; i < n; i++) {
            if (w.charAt(i) == 'A') {
                ts2 += a[i];
            } else {
                ts2 -= a[i];
            }
            max = Math.max(ts2, max);
        }
        for (int i = n-1; i > -1; i--) {
            if (w.charAt(i) == 'A') {
                s2 += a[i];
            } else {
               s2 -= a[i];
            }
            max = Math.max(s2, max);
        }
        log.write(max+"\n");
        log.flush();
    }
}
