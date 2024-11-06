//  A. Xenia and Divisors

import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    static FastScanner in = new FastScanner();
    static PrintWriter out = new PrintWriter(System.out);

    static void solve() {
        int n = in.nextInt();
        int[] cnt = new int[8];
        for(int i=0;i<n;i++){
            cnt[in.nextInt()]++;
        }

        List<String> ans = new ArrayList<>();
        // 6 3 1
        int max = Math.min(cnt[6], Math.min(cnt[3], cnt[1]));
        cnt[6] -= max;
        cnt[3] -= max;
        cnt[1] -= max;
        for(int i=0;i<max;i++) ans.add("1 3 6");

        // 6 2 1
        max = Math.min(cnt[6], Math.min(cnt[2], cnt[1]));
        cnt[6] -= max;
        cnt[2] -= max;
        cnt[1] -= max;
        for(int i=0;i<max;i++) ans.add("1 2 6");

        // 4 2 1
        max = Math.min(cnt[4], Math.min(cnt[2], cnt[1]));
        cnt[4] -= max;
        cnt[2] -= max;
        cnt[1] -= max;
        for(int i=0;i<max;i++) ans.add("1 2 4");

        if(ans.size() < n/3){
            out.print(-1);
        } else {
            for(String s : ans) out.println(s);
        }
    }

    public static void main(String[] args) {
//        int T = fs.nextInt();
        int T = 1;
        for (int i = 0; i < T; i++) {
            solve();
        }

        out.close();
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
