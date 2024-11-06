import java.util.*;
import java.lang.*;
import java.io.*;

public class Eshan {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        // int t = readInt();
        // while(t-- > 0){

        // }
        int n = readInt(), price = readInt();
        boolean[] gift = new boolean[n];
        for (int i = 0; i < n; i++)
            if (readLine().equals("halfplus"))
                gift[i] = true;
        long money = 0L, apples = 0L;
        for (int i = n - 1; i >= 0; i--) {
            if (gift[i]) {
                money += apples * price + price / 2;
                apples = apples * 2 + 1;
            } else {
                money += apples * price;
                apples *= 2;
            }
        }
        out.println(money);
        out.flush();
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(readLine());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

    private static boolean isInteger(String s) {
        try {
            Integer.parseInt(s);
        } catch (NumberFormatException e) {
            return false;
        } catch (NullPointerException e) {
            return false;
        }
        return true;
    }

    private static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    private static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    private static int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    private static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    private static long mod_power(long a, long b, int mod) {
        if (b == 0)
            return 1L;
        long temp = mod_power(a, b / 2, mod);
        temp %= mod;
        temp = (temp * temp) % mod;
        if ((b & 1) == 1)
            temp = (temp * a) % mod;
        return temp;
    }
}