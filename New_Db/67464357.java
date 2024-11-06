import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main {

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }


    public static void main(String[] args) throws IOException {
        FastReader ip = new FastReader();
        OutputStream output = System.out;
        PrintWriter out = new PrintWriter(output);
        int n=ip.nextInt();
        double p=ip.nextDouble();
        String s[]=new String[n];
        for(int i=0;i<n;i++){
            s[i]=ip.nextLine();
        }
        double ans=0;
        double apples=0;
        for(int i=n-1;i>=0;i--){
            if(s[i].equals("halfplus")){
                apples+=0.5;
                ans+=apples*p;
                apples*=2;
            }else{
                ans+=apples*p;
                apples*=2;
            }
        }
        out.println((long)ans);
        out.close();
    }
}