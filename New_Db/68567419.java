import java.io.*;
import java.util.*;
public class  Main{
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt(),m=sc.nextInt();
		int[]in=sc.takearr(n);
		int sqrt=0;
		while(sqrt*sqrt<n) {
			sqrt++;
		}
		int []next=new int[n],cnt=new int[n];
		int []rep=new int[n];
		for(int i=n-1;i>=0;i--) {
			if(in[i]+i>=n) {
				next[i]=n;
				cnt[i]=1;
				rep[i]=i;
			}
			else {
				int curPortion=i/sqrt,nextPortion=(in[i]+i)/sqrt;
				if(curPortion==nextPortion) {
					next[i]=next[i+in[i]];
					cnt[i]=cnt[i+in[i]]+1;
					rep[i]=rep[i+in[i]];
				}
				else {
					next[i]=i+in[i];
					cnt[i]=1;
					rep[i]=i;
				}
				
			}
		}
		while(m-->0) {
			if(sc.nextInt()==0) {
				int a=sc.nextInt()-1,p=sc.nextInt();
				in[a]=p;
				for(int i=a;i>=0;i--) {
					if(in[i]+i>=n) {
						next[i]=n;
						cnt[i]=1;
						rep[i]=i;
					}
					else {
						int curPortion=i/sqrt,nextPortion=(in[i]+i)/sqrt;
						if(curPortion==nextPortion) {
							next[i]=next[i+in[i]];
							cnt[i]=cnt[i+in[i]]+1;
							rep[i]=rep[i+in[i]];
						}
						else {
							next[i]=i+in[i];
							cnt[i]=1;
							rep[i]=i;
						}
						
					}
					if(i%sqrt==0) {
						break;
					}
					
				}
				
			}
			else {
				int ans=0,last=sc.nextInt()-1;
				while(true) {
					ans+=cnt[last];
					if(next[last]==n) {
						last=rep[last];
						break;
					}
					last=next[last];
					
				}
				pw.println((last+1)+" "+ans);
			}
		}
		pw.flush();
	}	
	static class MScanner {
		StringTokenizer st;
		BufferedReader br;
		public MScanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}
 
		public MScanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public int[] takearr(int n) throws IOException {
	        int[]in=new int[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public long[] takearrl(int n) throws IOException {
	        long[]in=new long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public Integer[] takearrobj(int n) throws IOException {
	        Integer[]in=new Integer[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public Long[] takearrlobj(int n) throws IOException {
	        Long[]in=new Long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public String nextLine() throws IOException {
			return br.readLine();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
 
		public char nextChar() throws IOException {
			return next().charAt(0);
		}
 
		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}