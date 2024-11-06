import java.util.Scanner;

public class Main {
    public static int converter(int val,int base){
        int res = 0;
        while(val > 0){
            int d = val%base;
            val = val/base;
            res += d;
        }
        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int finalans = 0;
        int count = 0;
        for(int i = 2;i<n;i++){
            finalans += converter(n,i);
            count++;
        }
        for(int i = count-1;i>=2;i--){
            if(finalans %i == 0 && count%i == 0){
                finalans = finalans/i;
                count = count/i;
            }
        }
        System.out.println(finalans + "/" + count);
    }
}
