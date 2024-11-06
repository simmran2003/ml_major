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
        int[] strength = new int[n];
        for (int i = 0; i < n; i++) {
            strength[i] = sc.nextInt();
        }
        char[] arr = sc.next().toCharArray();
        long totalAlice = 0, totalBob = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'A') {
                totalAlice += strength[i];
            }else {
                totalBob += strength[i];
            }
        }
        long alice = 0, bob = 0;
        long res = Math.max(totalAlice, totalBob);
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'A') {
                alice += strength[i];
            }else {
                bob += strength[i];
            }
            long leftAlice = totalAlice - alice;
            long leftBob = totalBob - bob;
            res = Math.max(res, Math.max(leftAlice + bob, leftBob + alice));
        }
        out.println(res);
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