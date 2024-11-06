import java.util.*;

public class c {
    static long res = Long.MIN_VALUE;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int[] count = new int[8];
        boolean b = false;
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            if (x == 5 || x == 7)
                b = true;
            else
                count[x] += 1;
        }
        int x = count[6] - count[3];
        if (b || (count[2] != x + count[4]) || count[6] < count[3] || (count[4] + count[6] != count[1])) {

            System.out.println(-1);
        } else {
            while (count[4] > 0) {
                System.out.println("1 2 4");
                count[4]--;
                count[2]--;
            }
            while (count[3] > 0) {
                System.out.println("1 3 6");
                count[3]--;
                count[6]--;
            }
            while (count[2] > 0) {
                System.out.println("1 2 6");
                count[2]--;
                count[6]--;
            }

        }

    }
}