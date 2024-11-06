// HOPE

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////                                                                                                       //////////
///////                                                                                                       //////////
///////            RRRRRRRRRRRRR     YY          YY         AA               NN          NN                   //////////
///////            RR         RR      YY        YY        AA  AA             NN NN       NN                   //////////
///////            RR        RR         YY     YY        AA    AA            NN  NN      NN                   //////////
///////            RRRRRRRRRR            YY   YY       AAAAAAAAAAAA          NN    NN    NN                   //////////
///////            RR RR                   YY         AAAAAAAAAAAAAA         NN      NN  NN                   //////////
///////            RR   RR                 YY        AA            AA        NN       NN NN                   //////////
///////            RR     RR               YY       AA              AA       NN          NN                   //////////
///////            RR       RR_____________________________________________________________________________   //////////
////////                                                                                                      //////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


import java.io.*;
import java.util.*;

public class Codeforces2 {
    static PrintWriter out = new PrintWriter(System.out);
    static final int mod = 1_000_000_007;

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
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

        int[] readIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] readLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
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

    //Try seeing general case
    public static void main(String[] args) {
        FastReader s = new FastReader();
        int n = s.nextInt();
        int m = s.nextInt();
        int start = s.nextInt();
        int finish = s.nextInt();

        StringBuilder sb = new StringBuilder();

        int step = 1;//Ongoing step
        if (start < finish) {
            for (int i = 0; i < m; i++) {
                int t = s.nextInt();
                int l = s.nextInt();
                int r = s.nextInt();
                while (step < t && start != finish)//I can pass note nobody is watching at this step
                {
                    sb.append("R");
                    start++;
                    step++;
                }

                if (start == finish)//If equal then return
                    break;

                //Now current step -> If I'm being looked  then X otherwise R
                if (start + 1 < l || start > r) {
                    sb.append("R");
                    start++;
                    step++;
                } else {
                    sb.append("X");
                    step++;
                }
            }
            while (start != finish) {
                sb.append("R");
                start++;
            }
        } else {
            for (int i = 0; i < m; i++) {
                int t = s.nextInt();
                int l = s.nextInt();
                int r = s.nextInt();
                while (step < t && start != finish)//I can pass note nobody is watching at this step
                {
                    sb.append("L");
                    start--;
                    step++;
                }

                if (start == finish)//If equal then return
                    break;

                //Now current step -> If I'm being looked  then X otherwise L
                if (start < l || start-1 > r) {
                    sb.append("L");
                    start--;
                    step++;
                } else {
                    sb.append("X");
                    step++;
                }
            }
            while (start != finish) {
                sb.append("L");
                start--;
            }
        }
        out.println(sb);




        out.close();
    }












































































































































    /////////////////////////////////////////////////THE END///////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    public static int gcd(int x,int y)
    {
        return y==0?x:gcd(y,x%y);
    }
    public static long gcd(long x,long y)
    {
        return y==0L?x:gcd(y,x%y);
    }

    public static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    public static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    public static long pow(long a,long b)
    {
        if(b==0L)
            return 1L;
        long tmp=1;
        while(b>1L)
        {
            if((b&1L)==1)
                tmp*=a;
            a*=a;
            b>>=1;
        }
        return (tmp*a);
    }

    public static long modPow(long a,long b,long mod)
    {
        if(b==0L)
            return 1L;
        long tmp=1;
        while(b>1L)
        {
            if((b&1L)==1L)
                tmp*=a;

            a*=a;
            a%=mod;
            tmp%=mod;
            b>>=1;
        }
        return (tmp*a)%mod;
    }

    static long mul(long a, long b) {
        return a*b%mod;
    }

    static long fact(int n) {
        long ans=1;
        for (int i=2; i<=n; i++) ans=mul(ans, i);
        return ans;
    }

    static long fastPow(long base, long exp) {
        if (exp==0) return 1;
        long half=fastPow(base, exp/2);
        if (exp%2==0) return mul(half, half);
        return mul(half, mul(half, base));
    }

    static void debug(int ...a)
    {
        for(int x: a)
            out.print(x+" ");
        out.println();
    }

    static void debug(long ...a)
    {
        for(long x: a)
            out.print(x+" ");
        out.println();
    }

    static void debugMatrix(int[][] a)
    {
        for(int[] x:a)
            out.println(Arrays.toString(x));
    }
    static void debugMatrix(long[][] a)
    {
        for(long[] x:a)
            out.println(Arrays.toString(x));
    }

    static void reverseArray(int[] a) {
        int n = a.length;
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = a[n - i - 1];
        for (int i = 0; i < n; i++)
            a[i] = arr[i];
    }

    static void reverseArray(long[] a) {
        int n = a.length;
        long[] arr = new long[n];
        for (int i = 0; i < n; i++)
            arr[i] = a[n - i - 1];
        for (int i = 0; i < n; i++)
            a[i] = arr[i];
    }

    static void sort(int[] a)
    {
        ArrayList<Integer> ls = new ArrayList<>();
        for(int x: a) ls.add(x);
        Collections.sort(ls);
        for(int i=0;i<a.length;i++)
            a[i] = ls.get(i);
    }

    static void sort(long[] a)
    {
        ArrayList<Long> ls = new ArrayList<>();
        for(long x: a) ls.add(x);
        Collections.sort(ls);
        for(int i=0;i<a.length;i++)
            a[i] = ls.get(i);
    }

    static class Pair{
        int x, y;
        Pair(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }
    static class MyCmp implements Comparator<Pair>
    {
        public int compare(Pair p1, Pair p2)
        {
            return p1.x-p2.x;
        }
    }


}
