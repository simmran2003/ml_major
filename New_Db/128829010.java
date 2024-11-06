import java.io.IOException;
import java.util.*;

public class Check1 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int p = sc.nextInt();
        long start = 0; long ans = 0;
        String[] vals = new String[n];
        for(int i=0;i<n;i++) vals[i]= sc.next();

        while (n-->0){
            String s = vals[n];
            ans+= start*p;
            start*=2;
            if(s.equals("halfplus")){
                start++;
                ans+=(p/2);
            }
        }
        System.out.println(ans);
    }
}