import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.*;

/**
 * @author Tran Anh Tai
 * @template for CP codes
 * What a trick prob!
 */
public class ProbC {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }
    // main solver
    static class Task{
        static int MOD = 1000000007;
        public void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long a[] = new long[n];
            for (int i = 0; i < n; i++){
                a[i] = in.nextInt();
            }
            long b[] = a.clone();
            Arrays.sort(b);
            long[][] dp = new long[2][n];
            for (int i = 1; i <= n; i++){
                for (int j = 0; j < n; j++){
                    dp[(i & 1)][j] = dp[(i + 1) & 1][j] + Math.abs(a[i - 1]- b[j]);
                    if (j > 0){
                        dp[(i & 1)][j] = Math.min(dp[(i & 1)][j], dp[(i & 1)][j - 1]);
                    }
                }
            }
            out.println(dp[n & 1][n - 1]);
        }
    }
    // fast input reader class;
    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }
        public long nextLong(){
            return Long.parseLong(nextToken());
        }
    }
}