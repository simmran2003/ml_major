import java.util.*;
import java.io.*;
public class stringalbaphabet {
	static class City{
		String s;
	}
	static class comp implements Comparator <City> { 
		public int compare(City c1, City c2) {
			return((c1.s + c2.s).compareTo(c2.s + c1.s));
		}
	}

	public static void main(String[]args) throws IOException{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer tokenizer = new StringTokenizer(in.readLine());
	int n = Integer.parseInt(tokenizer.nextToken());
	City[]arr = new City[n];
	for(int i = 0; i < n; i++) {
		arr[i] = new City();
		arr[i].s = in.readLine();
	}
	Arrays.sort(arr, new comp());
	for(int i = 0; i < n; i++) {
		System.out.print(arr[i].s);
	}
	}
}