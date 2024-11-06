import java.math.*;
import java.util.*;


public class Test {
    static class convertBases{
        public static int convertBase(int n, int b){
            int p = 0;
            int fn = n;
            
            int pow = 0;
            while(fn/b != 0){
                fn = fn/b;
                pow++;
            }
            
            while(n != 0){
                int d = n/(int)(Math.pow(b, pow));
                n -= d * (int)Math.pow(b, pow);
                pow--;
                p += d;
            }
            
            return p;
        }
    }
    static class reduceFrac{
        public static String reduceFrac(int n, int d){
                BigInteger n1 = new BigInteger("" + n);
                BigInteger d1 = new BigInteger("" + d);
                BigInteger gcd = n1.gcd(d1);
                n1 = n1.divide(gcd);
                d1 = d1.divide(gcd);
                return n1 + "/" + d1;
            }
        }
 
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int t = 0;
        for(int i = 2; i <= n-1; i++){
            t += convertBases.convertBase(n, i);
        }
        System.out.print(reduceFrac.reduceFrac(t, n-2));
                
        
        
        
        
        
    }
    
}
