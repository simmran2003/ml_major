import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static long mod = 1000000007;
    public static long mod2 = 998244353;

    public static void main(String[] args) throws java.lang.Exception {
        Reader sc = new Reader();
        FastNum in = new FastNum(System.in);
        PrintWriter out = new PrintWriter(System.out);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

//        int tests = in.nextInt();
//        for (int test = 1; test <= tests; test++) {
//
//        }

            int n = in.nextInt();
            int m = in.nextInt();
            int s = in.nextInt();
            int f = in.nextInt();
            int[][] a = new int[m][3];
            for (int i = 0; i < m; i++) {
                a[i][0] = in.nextInt();
                a[i][1] = in.nextInt();
                a[i][2] = in.nextInt();
            }
            StringBuilder sb = new StringBuilder();
            int currStep = 1;
            int currSpy = s;
            int move = (s < f) ? 1 : -1;
            String build = (move == 1) ? "R" : "L";
            int i = 0;
            while (currSpy != f) {
                if(i < m && currStep == a[i][0]) {
                    int l = a[i][1];
                    int r = a[i][2];
                    if(l <= currSpy && currSpy <= r) {
                        sb.append("X");
                    } else if (l <= currSpy + move && currSpy + move <= r) {
                        sb.append("X");
                    } else {
                        sb.append(build);
                        currSpy += move;
                    }
                    i++;
                } else {
                    sb.append(build);
                    currSpy += move;
                }
                currStep++;
            }
            out.println(sb.toString());


        out.flush();
    }

    public static int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    public static long power(long a, long b) {
        if (b == 0)
            return 1;
        long answer = power(a, b / 2) % mod;
        answer = (answer * answer) % mod;
        if (b % 2 != 0)
            answer = (answer * a) % mod;
        return answer;
    }

    public static void swap(int x, int y) {
        int t = x;
        x = y;
        y = t;
    }

    public static long min(long a, long b) {
        if (a < b) return a;
        return b;
    }

    public static long divide(long a, long b) {
        return (a % mod * (power(b, mod - 2) % mod)) % mod;
    }

    public static long nCr(long n, long r) {
        long answer = 1;
        long k = min(r, n - r);
        for (long i = 0; i < k; i++) {
            answer = (answer % mod * (n - i) % mod) % mod;
            answer = divide(answer, i + 1);
        }
        return answer % mod;
    }

    public static boolean plaindrome(String str) {
        StringBuilder sb = new StringBuilder();
        sb.append(str);
        return (str.equals((sb.reverse()).toString()));
    }

    public static class Pair {
        int a;
        int b;

        Pair(int s, int e) {
            a = s;
            b = e;
        }
    }

    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new AssertionError();
            }
        }
    }

    static class FastNum implements AutoCloseable {

        InputStream is;
        byte buffer[] = new byte[1 << 16];
        int size = 0;
        int pos = 0;

        FastNum(InputStream is) {
            this.is = is;
        }

        int nextChar() {
            if (pos >= size) {
                try {
                    size = is.read(buffer);
                } catch (IOException e) {
                    throw new IOError(e);
                }
                pos = 0;
                if (size == -1) {
                    return -1;
                }
            }
            Assert.check(pos < size);
            int c = buffer[pos] & 0xFF;
            pos++;
            return c;
        }

        int nextInt() {
            int c = nextChar();
            while (c == ' ' || c == '\r' || c == '\n' || c == '\t') {
                c = nextChar();
            }
            if (c == '-') {
                c = nextChar();
                Assert.check('0' <= c && c <= '9');
                int n = -(c - '0');
                c = nextChar();
                while ('0' <= c && c <= '9') {
                    int d = c - '0';
                    c = nextChar();
                    Assert.check(n > Integer.MIN_VALUE / 10
                            || n == Integer.MIN_VALUE / 10 && d <= -(Integer.MIN_VALUE % 10));
                    n = n * 10 - d;
                }
                return n;
            } else {
                Assert.check('0' <= c && c <= '9');
                int n = c - '0';
                c = nextChar();
                while ('0' <= c && c <= '9') {
                    int d = c - '0';
                    c = nextChar();
                    Assert.check(
                            n < Integer.MAX_VALUE / 10 || n == Integer.MAX_VALUE / 10 && d <= Integer.MAX_VALUE % 10);
                    n = n * 10 + d;
                }
                return n;
            }
        }

        @Override
        public void close() {
        }
    }


    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private final DataInputStream din;
        private final byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
}
