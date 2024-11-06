import java.io.*;
import java.util.*;

public class Main{
	public static int n;
	public static void main(String[] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(input.readLine());
		
		String[] data = new String[n];
		for(int i = 0;i<n;i++) {
			String word = input.readLine();
			data[i] = word;
		}
		
		Arrays.sort(data, (String a, String b)->{
			return (a+b).compareTo(b + a);
		});
		
		for(int i = 0;i<n;i++) {
			System.out.print(data[i]);
		}
	}
}
