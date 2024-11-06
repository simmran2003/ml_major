import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class TheSmallestStringConcatenation {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int n = io.nextInt();
        String[] as = new String[n];
        for (int i = 0; i < n; i++) {
            as[i] = io.next();
        }
        Arrays.sort(as, new Comp());
        for (int i = 0; i < n; i++) {
            io.print(as[i]);
        }
        io.close();
    }
//    static class Comp implements Comparator<String> {
//        public int compare(String a, String b) {
//            int aLength = a.length();
//            int bLength = b.length();
//            if (aLength == bLength) {
//                for (int i = 0; i < aLength; i++) {
//                    if (a.charAt(i) < b.charAt(i)) {
//                        return -1;
//                    }
//                    else if (a.charAt(i) > b.charAt(i)) {
//                        return 1;
//                    }
//                }
//                return 0;
//            }
//            else if (aLength > bLength) {
//                for (int i = 0; i < bLength; i++) {
//                    if (a.charAt(i) < b.charAt(i)) {
//                        return -1;
//                    }
//                    else if (a.charAt(i) > b.charAt(i)) {
//                        return 1;
//                    }
//                }
//                int subtraction = bLength;
//                for (int i = bLength; i < aLength; i++) {
//                    if (i == subtraction + bLength) subtraction+=bLength;
//                    if (a.charAt(i) < b.charAt(i - subtraction)) {
//                        return -1;
//                    }
//                    else if (a.charAt(i) > b.charAt(i - subtraction)) {
//                        return 1;
//                    }
//                }
//                int k = a.charAt(aLength - 1 - subtraction);
//                if (k < b.charAt(0)) {
//                    return -1;
//                }
//                else if (k > b.charAt(0)){
//                    return 1;
//                }
//                else {
//                    return 1;
//                }
//            }
//            else {
//                for (int i = 0; i < aLength; i++) {
//                    if (b.charAt(i) < a.charAt(i)) {
//                        return 1;
//                    } else if (b.charAt(i) > a.charAt(i)) {
//                        return -1;
//                    }
//                }
//                int subtraction = aLength;
//                for (int i = aLength; i < bLength; i++) {
//                    if (i == subtraction + aLength) subtraction += aLength;
//                    if (b.charAt(i) < a.charAt(i - subtraction)) {
//                        return 1;
//                    } else if (b.charAt(i) > a.charAt(i - subtraction)) {
//                        return -1;
//                    }
//                }
//                int k = b.charAt(bLength - 1 - subtraction);
//                if (k < a.charAt(0)) {
//                    return 1;
//                } else if (k > a.charAt(0)) {
//                    return -1;
//                } else {
//                    return 1;
//                }
//            }
//        }
//    }
    static class Comp implements Comparator<String> {
        public int compare(String a, String b) {
            String first = a + b;
            String second = b + a;
            if (!first.equals(second)) {
                return first.compareTo(second);
            }
            else {
                return 0;
            }
        }
    }


    static class Kattio extends PrintWriter {
        private BufferedReader r;
        private StringTokenizer st;

        // standard input
        public Kattio() {
            this(System.in, System.out);
        }

        public Kattio(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }

        // USACO-style file input
        public Kattio(String problemName) throws IOException {
            super(problemName + ".out");
            r = new BufferedReader(new FileReader(problemName + ".in"));
        }

        // returns null if no more input
        public String next() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (Exception e) {
            }
            return null;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}
