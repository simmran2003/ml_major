import java.util.*;
import java.lang.*;
import java.io.*;

// Created by @thesupremeone on 19/05/21
public class Queen {
    static class Assignment{
        long as, bs;

        public Assignment(long as, long bs) {
            this.as = as;
            this.bs = bs;
        }
    }
    void solve() throws IOException {
        int n = getInt();
        long[] p = new long[n];
        for (int i = 0; i < n; i++){
            p[i] = getLong();
        }
        String s = getLine();
        Assignment[] prefix = new Assignment[n];
        long a = 0, b =0;
        for (int i = 0; i < n; i++) {
            if(s.charAt(i)=='A')
                a+=p[i];
            else
                b+=p[i];
            prefix[i] = new Assignment(a, b);
        }
        Assignment[] suffix = new Assignment[n];
        a = 0;
        b = 0;
        for (int i = n-1; i >=0; i--) {
            if(s.charAt(i)=='A')
                a+=p[i];
            else
                b+=p[i];
            suffix[i] = new Assignment(a, b);
        }
        long maxBob = Math.max(prefix[n-1].as, prefix[n-1].bs);
        for (int i = 0; i < n-1; i++) {
            Assignment pre = prefix[i];
            Assignment suf = suffix[i+1];
            maxBob = Math.max(maxBob, Math.max(pre.bs+suf.as, pre.as+suf.bs));
        }
        println(maxBob);
    }

    public static void main(String[] args) throws Exception {
        if (isOnlineJudge()) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
            new Queen().solve();
            out.flush();
        } else {
            localJudge = new Thread();
            in = new BufferedReader(new FileReader("input.txt"));
            out = new BufferedWriter(new FileWriter("output.txt"));
            localJudge.start();
            new Queen().solve();
            out.flush();
            localJudge.suspend();
        }
    }
    static boolean isOnlineJudge(){
        try {
            return System.getProperty("ONLINE_JUDGE")!=null
                    || System.getProperty("LOCAL")==null;
        }catch (Exception e){
            return true;
        }
    }
    // Fast Input & Output
    static Thread localJudge = null;
    static BufferedReader in;
    static StringTokenizer st;
    static BufferedWriter out;
    static String getLine() throws IOException{
        return in.readLine();
    }
    static String getToken() throws IOException{
        if(st==null || !st.hasMoreTokens())
            st = new StringTokenizer(getLine());
        return st.nextToken();
    }
    static int getInt() throws IOException {
        return Integer.parseInt(getToken());
    }
    static long getLong() throws IOException {
        return Long.parseLong(getToken());
    }
    static void print(Object s) throws IOException{
        out.write(String.valueOf(s));
    }
    static void println(Object s) throws IOException{
        out.write(String.valueOf(s));
        out.newLine();
    }
}