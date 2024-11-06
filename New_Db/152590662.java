import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        int div;
        int radix = 2;
        int res = 0;
        while(radix <= num-1){
            div = num;
            while(div >= radix){
                res += div%radix;
                div /= radix;
            }
            res += div;
            radix += 1;
        }

        int count = num-2;
        int gcd = BigInteger.valueOf(res).gcd(BigInteger.valueOf(count)).intValue();
        System.out.println(res/gcd + "/" + count/gcd);
    }
}
