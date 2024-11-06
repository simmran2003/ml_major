import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;

public class SmallConcat {
	static class Comp implements Comparator<String>{

		@Override
		public int compare(String o1, String o2) {
			
			return o1.concat(o2).compareTo(o2.concat(o1));
		}
		
	}
	public static void main(String[] args) throws IOException {
		
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(r.readLine());
		ArrayList<String> strs = new ArrayList<>();
		for(int i = 0; i < N;i++) {
			strs.add(r.readLine());
		}
		strs.sort(new Comp());
		StringBuilder s = new StringBuilder();
		for(String str:strs) {
			s.append(str);
		}
		System.out.println(s.toString());

	}

}
