import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int num = cin.nextInt();
        int radix = 2;
        int div;
        int res = 0;
        int cur_res;
        while(radix <= num-1){
            div = num;
            cur_res = 0;
            while(div >= radix){
                cur_res += div % radix;
                div /= radix;
            }
            cur_res += div;
            res += cur_res;
            radix += 1;
        }
        int add = radix-(num%2);
        while(radix <= num-1){
            res += add;
            add -= 1;
            radix += 1;
        }
        
        int gcd = BigInteger.valueOf(res).gcd(BigInteger.valueOf(radix-2)).intValue();
        System.out.println(res/gcd + "/" + (radix-2)/gcd);
    }
}
