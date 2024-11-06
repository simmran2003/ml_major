import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine()), num = 0, dem = n - 2;
        for (int i = 2; i < n; i++)
            for (int x : inBase(n, i))
                num += x;
        while (true) {
            int gcd = gcd(num, dem);
            if (gcd == 1)
                break;
            num /= gcd;
            dem /= gcd;
        }
        out.println(num + "/" + dem);
        out.flush();
        in.close();
        out.close();
    }

    private static List<Integer> inBase(int n, int b) {
        List<Integer> list = new ArrayList<>();
        while (n > 0) {
            list.add(n % b);
            n /= b;
        }
        return list;
    }

    private static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}