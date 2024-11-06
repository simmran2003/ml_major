import java.util.*;
import java.io.*;
public class concatenation {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        String[] parts = new String[n];
        for (int i = 0; i < n; i++) {
            parts[i] = scan.next();
        }
        // lines 12-18 is a one line statement
        Arrays.sort(parts, new Comparator<String>() {
            public int compare(String a, String b) {
                String ab = a + b;
                String ba = b + a;
                return ab.compareTo(ba);
            }
        });
        for (int i = 0; i < n; i++) {
            System.out.print(parts[i]);
        }
    }
}
