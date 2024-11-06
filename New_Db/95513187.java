import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class holes {
    static int[] arr;
    static int[] nxt;
    static int[] cnt;
    static int[] nxtseg;
    static int n,m;
    static int sqrt;
    public static void main(String[] args) {
        FastScanner fs=new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        n = fs.nextInt() ; m = fs.nextInt();
        sqrt = (int)Math.sqrt(n);
        arr = fs.readArray(n);
        nxt = new int[n];
        cnt = new int[n];
        nxtseg = new int[n];//yaha se next segment me pehla kon milega
        for(int i=n-1 ;i>=0 ;i--){
            update(i);
        }
//        System.out.println("here");
        while(m-->0){
            if(fs.nextInt()==1){
                int ind = fs.nextInt()-1;
                int ans=0,last=ind;
                while(ind!=n){
                    ans += cnt[ind];
                    last = nxtseg[ind];
                    ind = nxt[ind];
                }
                out.println(last+1 +" " + ans);
            }else{
                int ind = fs.nextInt()-1;
                arr[ind] = fs.nextInt();
                for(int j = ind ; j/sqrt == ind/sqrt && j>=0; j--){
                    update(j);
                }
            }
//            System.out.println("wh "+ m);
        }
        out.close();
    }
    public static void update(int ind){
        int nextind = ind + arr[ind];
        if(nextind>=n){
            nxt[ind] = n;
            cnt[ind] = 1;
            nxtseg[ind] = ind;
        }else if(ind/sqrt == nextind/sqrt){
            nxtseg[ind] = nxtseg[nextind];
            cnt[ind] = 1 + cnt[nextind];
            nxt[ind] = nxt[nextind];
        }else{
            nxt[ind] = nxtseg[ind] = nextind;
            cnt[ind] = 1;
        }
    }

    static class FastScanner {
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

        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
