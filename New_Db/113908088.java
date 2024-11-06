import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();

        int n = fs.nextInt();
        long p = fs.nextLong();
        long ans = 0;
        long apples = 1;

        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = fs.next();
        }

        for (int i = n-2; i >= 0; i--) {
            if (arr[i].equals("half")) {
                apples *= 2;
            } else {
                apples = apples * 2 + 1;
            }
        }

        while (apples > 0) {
            if (apples % 2 == 0) {
                ans += apples / 2 * p;
                apples /= 2;
            } else {
                ans += (double) apples / 2.0 * p;
                apples /= 2;
            }
        }

        System.out.println(ans);

        // end main
    }

    static class FastScanner {
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

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble() { return Double.parseDouble(next()); }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
