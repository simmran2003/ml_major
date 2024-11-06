//ackage cf;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public final class Cf {
    static long n;
    public static void main(String[] args) throws Exception {
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(java.io.FileDescriptor.out), "ASCII"), 512);        
        FastReader sc = new FastReader();
        long tc=1,p,no;
        int n;
        double cost=0;
        while(tc-->0)
        {  
          n=sc.nextInt();
          p=sc.nextInt();
          String a[]=new String[(int)n];
         
          for(int i=0;i<n;i++)a[i]=sc.next();
          if(a[n-1].equals("halfplus")){no=1;}
          else no=2;
          cost+=(no/2.0)*p;
          for(int i=n-2;i>=0;i--)
          {
              if(a[i].equals("halfplus"))no=2*no+1;
              else no=2*no;
              cost+=(no/2.0)*p;
          }
          out.write((long)cost+" ");
        }
               
        out.flush();
        
    }
public static long go(long s,long e){
    long mid=(s+e)/2;
    if(s>e)return s;
    if((mid*(mid+1))/2==n)return mid;
    else if(((mid)*(mid+1))/2>n)return go(s,mid-1);
    else return go(mid+1,e);
}
    
    public static void debug(String s)
    {
        System.out.println(s);
    }

    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////
    static class FastReader {        
        
        BufferedReader br;        
        StringTokenizer st;        
        
        public FastReader() {            
            br = new BufferedReader(new InputStreamReader(System.in));            
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
    //////////////////////////////////////////////////////////////////

    static class Reader {        

        final private int BUFFER_SIZE = 1 << 16;        
        private DataInputStream din;        
        private byte[] buffer;        
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
            byte[] buf = new byte[1002]; // line length 
            int cnt = 0, c;            
            while ((c = read()) != -1) {                
                if (c == '\n') {
                    break;
                }                
                buf[cnt++] = (byte) c;                
            }            
            return new String(buf, 0, cnt);            
        }        
        
        public int nextInt() throws IOException {            
            int ret = 0;            
            byte c = read();            
            while (c <= ' ') {
                c = read();
            }            
            boolean neg = (c == '-');            
            if (neg) {
                c = read();
            }            
            do {                
                ret = ret * 10 + c - '0';                
            } while ((c = read()) >= '0' && c <= '9');            
            
            if (neg) {
                return -ret;
            }            
            return ret;            
        }        
        
        public long nextLong() throws IOException {            
            long ret = 0;            
            byte c = read();            
            while (c <= ' ') {
                c = read();
            }            
            boolean neg = (c == '-');            
            if (neg) {
                c = read();
            }            
            do {                
                ret = ret * 10 + c - '0';                
            } while ((c = read()) >= '0' && c <= '9');            
            if (neg) {
                return -ret;
            }            
            return ret;            
        }        
        
        public double nextDouble() throws IOException {            
            double ret = 0, div = 1;            
            byte c = read();            
            while (c <= ' ') {
                c = read();
            }            
            boolean neg = (c == '-');            
            if (neg) {
                c = read();
            }            
            
            do {                
                ret = ret * 10 + c - '0';                
            } while ((c = read()) >= '0' && c <= '9');            
            
            if (c == '.') {                
                while ((c = read()) >= '0' && c <= '9') {                    
                    ret += (c - '0') / (div *= 10);                    
                }                
            }            
            
            if (neg) {
                return -ret;
            }            
            return ret;            
        }        
        
        private void fillBuffer() throws IOException {            
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);            
            if (bytesRead == -1) {
                buffer[0] = -1;
            }            
        }        
        
        private byte read() throws IOException {            
            if (bufferPointer == bytesRead) {
                fillBuffer();
            }            
            return buffer[bufferPointer++];            
        }        
        
        public void close() throws IOException {            
            if (din == null) {
                return;
            }            
            din.close();            
        }        
    }    
}
