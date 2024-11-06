import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Codeforces {


    public  void solve() {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = fs.nextInt();
        int[]ar = new int[n];
        for(int i=0;i<n;i++)ar[i] = fs.nextInt();
        char[]str = fs.nextLine().toCharArray();
        long[]preA = new long[n+1], preB = new long[n+1];
        long[]sufA = new long[n+1], sufB = new long[n+1];
        for(int i=0;i<n;i++){
            preA[i] = (str[i] =='A'?ar[i]:0);
            preB[i] = (str[i] == 'B'?ar[i]:0);
            if(i > 0){
                preA[i] += preA[i-1];
                preB[i] += preB[i-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            sufA[i] = (str[i] =='A'?ar[i]:0);
            sufB[i] = (str[i] == 'B'?ar[i]:0);
            if(i < n-1 ){
                sufA[i] += sufA[i+1];
                sufB[i] += sufB[i+1];
            }
        }
        long max = preB[n-1];
        for(int i=0;i<n;i++){
            if(str[i] == 'A'){
                max = Math.max(max,preA[i]+sufB[i+1]);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(str[i] == 'A'){
                max = Math.max(max,sufA[i]+(i>0?preB[i-1]:0));
            }
        }
        out.println(max);
        out.flush();
    }
    public static void main(String[]args){
        try{
            new Codeforces().solve();
        }catch (Exception e){
            e.printStackTrace();
        }

    }
    class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }

}