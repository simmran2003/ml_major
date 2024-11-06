import java.util.*;

public class Sequence {

	static void solve() {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong(), k=0;
		// Max queue
		Queue<Long> p = new PriorityQueue<Long>((int)n, new Comparator<Long>(){
			public int compare (Long a, Long b) {
				return b-a>0 ? 1 : b-a==0 ? 0 : -1 ;
			}
		});
		while (n-->0) {
			long c = sc.nextLong();
			p.add(c);
			if (p.peek()>c) {
				k+=p.poll()-c;
				p.add(c);
			}
		}
		System.out.println(k);
		sc.close();
	}

	public static void main(String[] args) {
		solve();
	}
}