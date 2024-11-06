import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Codeforces {


    public  void solve() {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = fs.nextInt(), p = fs.nextInt()/2;
        boolean[]ok = new boolean[n];
        for(int i=0;i<n;i++){
            ok[n-1-i] = fs.nextLine().equals("halfplus");
        }
        long a = 0,apples = 0;
        for(int i=0;i<n;i++){
            a *= 2;
            if(ok[i])a++;
            apples += a;
        }
        long money = apples*p;
        out.println(money);
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