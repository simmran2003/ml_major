import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Check1 {
    public static void main(String[] args) throws IOException {
        BufferedReader bu = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bu.readLine());
        int[] val = Arrays.stream(bu.readLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
        String s = bu.readLine();
        long[] originalB = new long[n];
        long[] originalA = new long[n];
        originalB[0] = s.charAt(0)=='B' ?  val[0] : 0;
        originalA[0] = s.charAt(0)=='A' ?  val[0] : 0;
        for(int i=1;i<n;i++){
            if(s.charAt(i)=='B'){
                originalB[i] = originalB[i-1]+val[i];
                originalA[i] = originalA[i-1];
            }else{
                originalB[i] = originalB[i-1];
                originalA[i] = originalA[i-1] + val[i];
            }
        }
        long ans = Math.max(originalA[n-1],originalB[n-1]);
        for(int i=1;i<n;i++){
            long suffixA = originalA[n-1]-originalA[i-1];
            long suffixB = originalB[n-1]-originalB[i-1];

            ans = Math.max(ans, Math.max(originalB[i-1]+suffixA, originalA[i-1]+suffixB));
        }
        System.out.println(ans);
    }
}