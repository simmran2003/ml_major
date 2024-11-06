/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."

*/


import java.util.*;
import java.lang.*;
import java.io.*;


public class CodeChef {
    static int n, m;
    static int MAX = 1000005;
    static int[] arr = new int[MAX];
    static int[] freq = new int[MAX];
    static int[] divisors = new int[MAX];
    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();

        int test = 1;
        for (int t = 0; t < test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        n = sc.nextInt();
        m = sc.nextInt();

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            if (arr[i] < MAX) {
                freq[arr[i]]++;
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= m; j += i) {
                divisors[j] += freq[i];
            }
        }

        int maxDiviors = 0, lcm = 1;
        for (int i = 1; i <= m; i++) {
            if (divisors[i] > maxDiviors) {
                maxDiviors = divisors[i];
                lcm = i;
            }
        }

        List<Integer> subsequence = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (lcm % arr[i] == 0) {
                subsequence.add(i + 1);
            }
        }
        out.println(lcm + " " + subsequence.size());
        for (int val : subsequence) {
            out.print(val + " ");
        }
        out.println();
    }


    public static FastReader sc;
    public static PrintWriter out;
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}