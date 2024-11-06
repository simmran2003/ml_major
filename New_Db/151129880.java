
import java.util.*;

public class SmallestStringConcatenation {

	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		int N = in.nextInt();
		String [] strings = new String [N];
		
		for (int i = 0; i < N; i++) {
			strings [i] = in.next();
		}
		in.close();
		
		Arrays.sort(strings, new Comp ());
		
		for (int i = 0; i < N; i++) {
			System.out.print(strings [i]);
		}
	}
	
	static class Comp implements Comparator <String> {

		@Override
		public int compare(String o1, String o2) {
			String s1 = o1 + o2;
			String s2 = o2 + o1;
			return s1.compareTo(s2);
		}
		
	}
	

}
