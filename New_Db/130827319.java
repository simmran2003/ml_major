/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."

*/

import java.util.*;
import java.lang.*;
import java.io.*;

public class CodeChef {
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
        int n = sc.nextInt();
        int p = sc.nextInt();
        List<Integer> buyers = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            if (s.equals("half")) {
                buyers.add(0);
            }else {
                buyers.add(1);
            }
        }
        Collections.reverse(buyers);
        long totalApples = 0;
        for (int i = 0; i < n; i++) {
            totalApples *= 2;
            if (buyers.get(i) == 1) {
                totalApples++;
            }
        }
        long money = 0;
        Collections.reverse(buyers);
        for (int i = 0; i < n; i++) {
            money += p * (totalApples / 2);
            if ((totalApples & 1) == 1) {
                money += p / 2;
            }
            totalApples >>= 1;
        }
        out.println(money);
    }


    public static FastReader sc;
    public static PrintWriter out;
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer segTree;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (segTree == null || !segTree.hasMoreElements())
            {
                try
                {
                    segTree = new StringTokenizer(br.readLine());
                }
                catch (IOException  end)
                {
                    end.printStackTrace();
                }
            }
            return segTree.nextToken();
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
            catch (IOException end)
            {
                end.printStackTrace();
            }
            return str;
        }
    }
}