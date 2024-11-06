import java.util.*;
import java.io.*;
 
public class XeniaAndSpies {
    static final int M = 1000000007;
		static FastReader in = new FastReader();
		static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) {
        int n=in.nextInt();
        int m=in.nextInt();
        int x=in.nextInt();
        int y=in.nextInt();
        StringBuilder ans=new StringBuilder();boolean flag=true;
        int diff;
        if (y>x)
        {
        for(int i=0;i<m&&x!=y;i++)
        {
        int t=in.nextInt();
        int s1=in.nextInt();
        int s2=in.nextInt();
        while(t!=i+1&&i<m&&x!=y)
        {
        ans.append('R');
        x++;
        i++;
        }
        if(i<m&&x!=y)
        {
        if((x>=s1&&x<=s2)||(x+1>=s1&&x+1<=s2))
        {
        ans.append('X');
        }
        else
        {
        ans.append('R');
        x++;
        }
        }}
        if (x!=y)
        {
        diff=y-x;
        char arr[]=new char[diff];
        Arrays.fill(arr, 'R');
        ans.append(arr);
        }

        }
        else if(x>y)
        {
        for(int i=0;i<m&&x!=y;i++)
        {
        int t=in.nextInt();
        int s1=in.nextInt();
        int s2=in.nextInt();
        while(t!=i+1&&i<m&&x!=y)
        {
        ans.append('L');
        x--;
        i++;
        }
        if(i<m&&x!=y){
         if((x>=s1&&x<=s2)||(x-1>=s1&&x-1<=s2))
        {
        ans.append('X');
        }
        else
        {
        ans.append('L');
        x--;
        }
        
        }}
        if (x!=y)
        {
        diff=x-y;
        char arr[]=new char[diff];
        Arrays.fill(arr, 'L');
        ans.append(arr);
        }
        }
        else
        {out.print("X");
        flag=false;}
        
        if (flag)
        out.print(ans);
        out.close(); 
        }static int gcd(int a, int b) {
    	if(b==0) return a;
    	return gcd(b, a%b);
    }
static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
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
} 