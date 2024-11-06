import java.io.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.StringTokenizer;

/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

public class Main {
   public static void main(String[] args) throws IOException {
      PrintWriter out = new PrintWriter(System.out);
      FastScanner fs = new FastScanner();
      long N, P;
      N = fs.nextLong();
      P = fs.nextLong();
      ArrayList<String> A = new ArrayList<String>();
      for(int i = 0; i < N; i++){
         A.add(fs.nextLine());
      }
      Collections.reverse(A);
      long currVal = 0;
      long ans = 0;
      for (String i:
           A) {
         ans += (currVal * P);
         if(i.equals("half")){
            currVal = (2L * currVal);
         }else{
            ans += (P / 2L);
            currVal = (2L * currVal) + 1;
         }
      }
      out.println(ans);
      out.close();
   }
   static class FastScanner {
      BufferedReader br;
      StringTokenizer st;

      public FastScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }

      public FastScanner(String filePath) throws FileNotFoundException {
         try {
            br = new BufferedReader(new FileReader(filePath));
         } catch (FileNotFoundException e) {
            e.printStackTrace();
         }
      }

      String next() throws IOException {
         while (st == null || !st.hasMoreTokens()) {
            try {
               st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
               e.printStackTrace();
               throw e;
            }
         }
         return st.nextToken();
      }

      String nextLine() throws IOException {
         String str;
         try {
            str = br.readLine();
         } catch (IOException e) {
            e.printStackTrace();
            throw e;
         }
         return str;
      }

      int nextInt() throws IOException {
         return Integer.parseInt(this.next());
      }

      long nextLong() throws IOException {
         return Long.parseLong(this.next());
      }
   }
}