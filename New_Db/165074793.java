import java.util.*;
import java.io.*;
 
public class practice {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new PrintWriter(System.out)));
        StringBuilder sb = new StringBuilder();

        int a = Integer.parseInt(br.readLine());

        int sum = 0;
        int cnt = 0;

        for (int i = 2; i < a; i++) {

            int temp = a;

            while (temp > 0) {

                sum += temp % i;
                temp /= i;
            }

            cnt++;
        }

        int gcd = gcd(sum, cnt);

        while (gcd != 1) {

            sum /= gcd;
            cnt /= gcd;

            gcd = gcd(sum, cnt);
        }

        sb.append(sum + "/" + cnt);

        pw.println(sb.toString().trim());
        pw.close();
        br.close();
    }

    public static int gcd(int x, int y) {

        if (x == 0) return y;

        return gcd(y % x, x);
    }
}