import java.util.*;
import java.util.stream.Collectors;
import java.lang.*;
import java.security.KeyStore.Entry;
import java.io.*;

public class B_Xenia_and_Spies {
    private static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
	
	private static int mod = 1000003;
	
	private static FastReader sc = new FastReader();

	public static void main(String[] args) {
		int t = 1;
		while(t-->0)
			solve();

	}
	

	private static void solve() {
        int n  = sc.nextInt();
        int m  = sc.nextInt();
        int s  = sc.nextInt();
        int f  = sc.nextInt();
        int a[][] = new int[m][3];
        for(int i=0; i<m; i++){
            a[i][0] = sc.nextInt();
            a[i][1] = sc.nextInt();
            a[i][2] = sc.nextInt();
        }
        StringBuilder sb = new StringBuilder();
        if(s<f){
            int t = 1, tt=0;
            while(s!=f){
                if(tt<m && a[tt][0]!=t){
                    sb.append("R");
                    s++;
                }else if(tt<m && (s+1>=a[tt][1] && s<=a[tt][2])){
                    sb.append("X");
                    tt++;
                }else{
                    sb.append("R");
                    s++;
                    tt++;
                }
                t++;
            }
        }else{
            int t = 1, tt=0;
            while(s!=f){
                if(tt<m && a[tt][0]!=t){
                    sb.append("L");
                    s--;
                }else if(tt<m && (s>=a[tt][1] && s-1<=a[tt][2])){
                    sb.append("X");
                    tt++;
                }else{
                    sb.append("L");
                    s--;
                    tt++;
                }
                t++;
            }
        }
        System.out.println(sb);
    }
}

