import java.util.Scanner;

public class Main {

    public static int n;
    public static int b;
    public static int a;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        b = n-2;
        a = 0;
        for (int i = 2; i < n; i++) {
            for (int j = n; j > 0 ; j = j / i) {
                a += j % i;
            }
        }
        fix();
        System.out.println(a + "/" + b);
        System.out.flush();
    }

    public static void fix() {
        for (int i = 2; i <= b; i++) {
            if (b % i == 0 && a % i == 0) {
                b /= i;
                a /= i;
                fix();
            }
        }
    }

}
