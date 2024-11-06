import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Codeforces342B {
    public static void main(String[] args) {
        FastReader fastReader = new FastReader();
        int n = fastReader.nextInt();
        int m = fastReader.nextInt();
        int s = fastReader.nextInt();
        int f =  fastReader.nextInt();

        HashMap<Integer,Pair> hash = new HashMap<>();
        for (int i = 0 ; i < m; i++){
            int t  = fastReader.nextInt();
            int l = fastReader.nextInt();
            int r = fastReader.nextInt();
            Pair p = new Pair(l,r);
            hash.put(t,p);
        }

        int st = s;
        int end = f;
        StringBuilder ans = new StringBuilder();
        if (st <= end){
            int  time = 1;
            while (st < end ){
                boolean spec =false;
                if (hash.containsKey(time)){
                    Pair p = hash.get(time);

                    if (p.x <= st && st <= p.y   ||  p.x <= (st+1) && (st+1) <= p.y){
                        ans.append('X');
                        spec =true;
                    }
                }
                if (!spec){
                    ans.append('R');
                    st++;
                }
                time++;
            }
            System.out.println(ans);
        }else{
            int  time = 1;
            while (st > end ){
                boolean spec =false;
                if (hash.containsKey(time)){
                    Pair p = hash.get(time);
                    if (p.x <= st && st <= p.y   ||  p.x <= (st-1) && (st-1) <= p.y){
                        ans.append('X');
                        spec =true;
                    }

                }
                if (!spec){
                    ans.append('L');
                    st--;
                }
                time++;
            }
            System.out.println(ans);
        }



    }
    static class Pair{
        int x;
        int y;
        Pair(int x, int y){
            this.x = x;
            this.y =   y;
        }
    }

    static class FastReader {


        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
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
