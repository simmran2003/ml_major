import java.util.*;
import java.io.*;
public class SmallestString {
	
	public static void main(String[] args) throws IOException{
		BufferedReader f=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out=new PrintWriter(System.out);
		int n=Integer.parseInt(f.readLine());
		ArrayList<String> arr=new ArrayList<String>();
		for(int i=0;i<n;i++) {
			arr.add(f.readLine());
		}
		Collections.sort(arr,new comp());
		for(int i=0;i<n;i++) {
			out.print(arr.get(i));
		}
		out.close();
		f.close();
	}
	static class comp implements Comparator<String>{
		public int compare(String a,String b) {
			return (a+b).compareTo(b+a);
		}
	}
	
}
