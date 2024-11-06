import java.util.*;
import java.io.*;
public class B{
	public static void main(String[] args)
	{
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = fs.nextInt();
		long[] arr = new long[n+1];
		long[] prealice = new long[n+1];
		long[] prebob = new long[n+1];
		
		long[] suffalice = new long[n+2];
		long[] suffbob = new long[n+2];
		
		for(int i=1;i<=n;i++)arr[i] = fs.nextLong();
		
		String str = fs.next();
		
		for(int i=0;i<str.length();i++)
		{
			if(str.charAt(i) == 'A')prealice[i+1] = suffalice[i+1] = arr[i+1];
			else prebob[i+1] = suffbob[i+1] =  arr[i+1];
		}
		
		for(int i=1;i<=n;i++)
		{
			prealice[i] += prealice[i-1];
			prebob[i] += prebob[i-1];
		}
		
		for(int i=n-1;i>=1;i--)
		{
			suffalice[i] += suffalice[i+1];
			suffbob[i] += suffbob[i+1];
		}
		long ans = 0;
		for(int i=0;i<=n;i++)
		{
			long my = prebob[i];
			long his = prealice[i];
			ans = Math.max(ans,Math.max(prebob[n],prebob[n]-my+his));
		}
		
		for(int i=n+1;i>=1;i--)
		{
			long my = suffbob[i];
			long his = suffalice[i];
			ans = Math.max(ans,Math.max(suffbob[1],suffbob[1]-my+his));
		}
		
		out.println(ans);
		
		out.close();
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
	public static int[] sort(int[] arr)
	{
		List<Integer> temp = new ArrayList();
		for(int i:arr)temp.add(i);
		Collections.sort(temp);
		int start = 0;
		for(int i:temp)arr[start++]=i;
		return arr;
	}
	public static String rev(String str)
	{
		char[] arr = str.toCharArray();
		char[] ret = new char[arr.length];
		int start = arr.length-1;
		for(char i:arr)ret[start--] = i;
		String ret1 = "";
		for(char ch:ret)ret1+=ch;
		return ret1;
	}
}