
import java.io.*;
import java.util.*;
import java.math.*;
 
public class A { 
    
    static boolean ONLINE_JUDGE = false;//change before submit
    static Fast f = new Fast();
    static PrintWriter out = new PrintWriter(System.out); 
    static boolean TEST_CASES = false;
    
    
    static void solve(int TC_NO) {

      
      int n = ri();
      int p = ri();
      long ans = 0;
      String[] a = new String[n];
      for(int i = 0; i < n; i++){
          a[i] = rs();
      }
      
      long start = 1;
      ans += start*p/2;
      for(int i = n-2; i > -1; i--){
           if("half".equals(a[i])){
              start = 2*start;
           }
           else {
              start = 2*start+1;
           }

           ans += (start*p/2);
      }

      out.println(ans);
      /*-----WARNING : change [ONLINE_JUDGE = false] before SUBMIT-----*/ 
    }

    
    public static void main(String[] args)throws Exception{

      out = ONLINE_JUDGE? new PrintWriter(new BufferedWriter(new FileWriter("output.txt"))): new PrintWriter(System.out);
      

     
      if(TEST_CASES){
          
          int t = ri();
          int i = 1;
          while(i<=t){
            solve(i);
            i++;
          }

      }

      else {

        solve(1);
      
      }
      
      out.close();

    }

    static int ri() {

      return f.nextInt();
    
    }

    static long rl() {
 
      return f.nextLong();
    
    }

    static double rd() {

       return f.nextDouble();
    
    }

    static char rc() {
      
       return rs().charAt(0);

    }

    static String rs() {

      return f.next();

    }

    static String rS() {
      
       return f.nextLine();
    
    }

    static int[] ra(int n) {
        
      int[] a = new int[n];
      for(int i = 0;i<n;i++) a[i] = ri();
      return a;
        
    }

    static long[] ral(int n) {
        
      long[] a = new long[n];
      for(int i = 0;i<n;i++) a[i] = rl();
      return a;
        
    }

    static double[] rad(int n) {

      double[] a = new double[n];
      for(int i = 0;i<n;i++) a[i] = rd();
      return a;

    }

    static char[] rac() {

        char[] c = rs().toCharArray();

        return c;

    }
    
    static int[][] rm(int n, int m) {
       
       int[][] mat = new int[n][m];

       for(int i = 0; i < n; i++) mat[i] = ra(m);
       
       return mat;

    }

    static char[][] rmc(int n) {
      
      char[][] cmat = new char[n][];
      
      for(int i = 0; i < n; i++) cmat[i] = rac();

      return cmat;

    }

    static void sort(int[] a) {

      ArrayList<Integer> list=new ArrayList<>();
      for (int i:a) list.add(i);
      Collections.sort(list);
      for (int i=0; i<a.length; i++) a[i]=list.get(i);

    }

    static String gcc(int TC_NO) {

         return "Case #"+TC_NO+": ";

    }

    static boolean isLetter(char c){

      return (64<c && c<91) || (96<c && c<123);
    
    }
  
    static class Fast{

       public BufferedReader br;
       public StringTokenizer st;
       
       public Fast(){
            try{
                br = ONLINE_JUDGE? (new BufferedReader(new FileReader("input.txt"))):(new BufferedReader(new InputStreamReader(System.in)));
            }
            catch(Exception e){
              throw new RuntimeException(e);
            }
       }
       
       String next(){
            while(st==null || !st.hasMoreTokens()){
                 try{
                      st=new StringTokenizer(br.readLine());
                 }
                 catch(IOException e){
                      throw new RuntimeException(e);
                 }
                 
            }
                 return st.nextToken();
            }
       int nextInt(){
            return Integer.parseInt(next());
       }
   
       long nextLong(){
            return Long.parseLong(next());
       }
   
       double nextDouble(){
            return Double.parseDouble(next());
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
   
    }

}


