import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Scanner;

public class popo {

    public static void main(String[] args) {

        InputReader in=new InputReader(System.in);
        PrintWriter out=new PrintWriter(System.out);

        int n=in.nextInt();
        int m=in.nextInt();
        int s=in.nextInt();
        int f=in.nextInt();
        int count=0;
        if(f>s)
        {
            while (m > 0) {
                m--;
                int t = in.nextInt();
                int l = in.nextInt();
                int r = in.nextInt();
                for (int i = 0; ; i++) {
                    if(count==t-1) {

                        if ((s >= l && s <= r) || (s + 1 == l)) {
                            out.print('X');
                        } else {
                            out.print('R');
                            s++;
                            //out.println(s);
                            if (s == f) {
                                //out.print(s);
                                break;
                            }
                        }
                        count++;
                        break;
                    }else{
                        out.print('R');
                        s++;
                        if (s == f) {
                            //out.print(s);
                            break;
                        }
                    }
                    count++;
                }
                if(s==f)
                {
                    break;
                }
            }
            if(m==0 && s!=f){
                while(s!=f){
                    s++;
                    out.print('R');
                }
                 
            }
        }
        else {
            while (m > 0) {
                m--;
                int t = in.nextInt();
                int l = in.nextInt();
                int r = in.nextInt();
                for (int i = 0; ; i++) {
                    if(count==t-1) {
                        if ((s >= l && s <= r) || (s - 1 == r)) {
                            out.print('X');
                        } else {
                            out.print('L');
                            s--;
                            if (s == f) {
                                break;
                            }
                        }
                        count++;
                        break;
                    }else
                    {
                        out.print("L");
                        s--;
                       // out.println(s);
                        if (s == f) {
                            //out.print(s);
                            break;
                        }
                    }
                    count++;

                   // System.out.println(count);
                }
                if (s == f) {
                    break;
                }
            }
            if(m==0 && s!=f){
                while(s!=f){
                    s--;
                    out.print('L');
                }

            }
        }

        out.close();
    }
    
    static class InputReader {

        private InputStream stream;
        private byte[] buf = new byte[8192];
        private int curChar, snumChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int snext() {
            if (snumChars == -1)
                throw new InputMismatchException();
            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = snext();
            while (isSpaceChar(c))
                c = snext();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = snext();
            while (isSpaceChar(c))
                c = snext();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public String readString() {
            int c = snext();
            while (isSpaceChar(c))
                c = snext();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
}