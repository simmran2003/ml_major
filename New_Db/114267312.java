import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.math.BigInteger;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Dragons {
	 
    static class Pair {
        int a;
        int b;
        public Pair(int a, int b){
            this.a=a;
            this.b=b;
        }
    }
	public static void main(String[] args) throws IOException {
	
//	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	HashMap<Integer,Pair> hm=new HashMap<Integer,Pair>();
	Scanner sc=new Scanner(System.in);
	
	
	int a=sc.nextInt();
	int b=sc.nextInt();
	int c=sc.nextInt();
	int d=sc.nextInt();
	int mum=0;
	for(int i=0;i<b;i++) {
		mum=sc.nextInt();
		hm.put(mum, new Pair(sc.nextInt(),sc.nextInt()));
	}
	
	int y=c;
	StringBuilder sb=new StringBuilder();
	
		if(c<d) {
			int i=1;
			while(i>0) {
				if(hm.containsKey(i)) {
					Pair ab=hm.get(i);
					if((ab.a<=c && ab.b>=c) || (ab.a<=c+1 && ab.b>=c+1)) {
						sb.append('X');
						
					}else {
						sb.append('R');
						c++;
					}
					
				}else {
					sb.append('R');	
					c++;
				}
				if(c==d) {
					break;
				}
				i++;
			}
			
		}else {
			int i=1;
			while( i>0) {
				if(hm.containsKey(i)) {
					Pair ab=hm.get(i);
					if((ab.a<=c && ab.b>=c) || (ab.a<=c-1 && ab.b>=c-1)) {
						sb.append('X');
						
					}else {
						sb.append('L');
						c--;
					}
					
				}else {
					sb.append('L');	
					c--;
				}
				if(c==d) {
					break;
				}
				i++;
			}
			
		}
	
	System.out.println(sb);
	
}
    public static int prog(List<Integer> list){
        if(list.isEmpty()) return -1;
        if(list.size()==1) return 0;
        int p = list.get(1)-list.get(0);
        for(int i = 0; i < list.size()-1; ++i){
            if(list.get(i+1) - list.get(i) != p)
                return -1;
        }
        return p;
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
	
	
	
	
	static int gcd(int a, int b) {
		return a%b == 0 ? b : gcd(b,a%b);
	}
	
	static boolean[] sieve(int n) {
		
		boolean isPrime[] = new boolean[n+1];
		for(int i = 2; i <= n; i++) {
			if(isPrime[i]) continue;
			for(int j = 2*i; j <= n; j+=i) {
				isPrime[j] = true;
			}
		
		}
		return isPrime;
		
	}
}