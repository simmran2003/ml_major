// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(r.readLine());
		
		int N = Integer.parseInt(st.nextToken());

		Str[] arr = new Str[N];

		for (int i = 0; i < N; i++){
			st = new StringTokenizer(r.readLine());
			String s = st.nextToken();
			arr[i] = new Str(s);
		}

		Arrays.sort(arr);

		for (int i = 0; i < arr.length; i++){
			pw.print(arr[i].s);
		}

		pw.println();
		
		/*
		 * Make sure to include the line below, as it
		 * flushes and closes the output stream.
		 */
		pw.close();
	}
}

class Str implements Comparable<Str> {
	String s;

	public Str(String _s){
		s = _s;
	}

	public int compareTo(Str other){
		return (s + other.s).compareTo(other.s + s);
	}
}

//'aaabbaaabbabaacaccccbbccbbaabb...ccaaabcaccabccbcccbbaacaaccbbcc'
//'aaabbaaabbabaacaccccbbccbbaabb...ccaaabcaccabccbcccbbaacaaccbbcc'