import java.util.*;
import java.io.*;
public class A342 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastReader fs = new FastReader();
		int T = 1;
		while (T-- > 0) {
			int n = fs.nextInt();
			int[] a = fs.nextArr(n);
			int one,two,three,six,four;
			one=two=three=six=four=0;
			for(int num:a) {
				switch(num) {
					case 1: one++; break;
					case 2: two++; break;
					case 3: three++; break;
					case 4: four++; break;
					case 6: six++; break;
				}
			}
			//println(three);
			if(one==n/3 && six>=three && two>=four && (six+four==n/3) && (two+three==n/3)) {
				while(three>0) {
					println("1 3 6");
					one--;
					three--;
					six--;
				}
				while(four>0) {
					println("1 2 4");
					one--;
					two--;
					four--;
				}
				while(two>0) {
					println("1 2 6");
					two--;	
				}
			}
			else println(-1);
		}
	}

	static void println(Object a) {
		System.out.println(a);
	}

	static void newln() {
		System.out.print("\n");
	}

	static void print(Object a) {
		System.out.print(a);
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer("");
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
				if (st.hasMoreTokens()) {
					str = st.nextToken("\n");
				} else {
					str = br.readLine();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

		int[] nextArr(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = this.nextInt();
			}
			return arr;
		}

		long[] nextLongArr(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++) {
				arr[i] = this.nextLong();
			}
			return arr;
		}

	}
}
