import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.nextLine());
        int sum = 0;
        for(int i=2;i<=n-1;i++){
            int p = n;
            while(p > 0){
                sum += (p % i);
                p /= i;
            }
        }
        int a = sum, b = n - 2;
        while(b > 0){
            int pom = b;
            b = a % b;
            a = pom;
        }
        System.out.println((sum/a) + "/" + ((n - 2)/a));
    }
}