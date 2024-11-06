import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main { public static void main(String[] args) { new MainClass().execute(); } }

class MainClass extends PrintWriter {
	MainClass() { super(System.out, true); }

	boolean cases = false;

	// Solution

	void solveIt(int testCaseNo) {
		int n = sc.nextInt();
		int a[] = sc.readIntArray(n);
		Arrays.sort(a);
		List<String> ans = new ArrayList<>();
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int i : a) map.put(i, map.getOrDefault(i, 0) + 1);
		for (int i = n - 1; i >= 0; i--) {
			if (!map.containsKey(a[i])) continue;
			if (a[i] != 6 && a[i] != 4) {
				System.out.println(-1);
				return;
			}
			if (a[i] == 6) {
				if (map.containsKey(3) && map.containsKey(1)) {
					map.put(6, map.get(6) - 1);
					map.put(3, map.get(3) - 1);
					map.put(1, map.get(1) - 1);
					if (map.get(6) == 0) map.remove(6);
					if (map.get(3) == 0) map.remove(3);
					if (map.get(1) == 0) map.remove(1);
					ans.add(1 + " " + 3 + " " + 6);
				} else if (map.containsKey(2) && map.containsKey(1)) {
					map.put(6, map.get(6) - 1);
					map.put(2, map.get(2) - 1);
					map.put(1, map.get(1) - 1);
					if (map.get(6) == 0) map.remove(6);
					if (map.get(2) == 0) map.remove(2);
					if (map.get(1) == 0) map.remove(1);
					ans.add(1 + " " + 2 + " " + 6);
				} else {
					System.out.println(-1);
					return;
				}
			} else {
				if (map.containsKey(2) && map.containsKey(1)) {
					map.put(4, map.get(4) - 1);
					map.put(2, map.get(2) - 1);
					map.put(1, map.get(1) - 1);
					if (map.get(4) == 0) map.remove(4);
					if (map.get(2) == 0) map.remove(2);
					if (map.get(1) == 0) map.remove(1);
					ans.add(1 + " " + 2 + " " + 4);
				} else {
					System.out.println(-1);
					return;
				}
			}
		}
		for (String s : ans) println(s);
	}

	void solve() {
		int caseNo = 1;
		if (cases) for (int T = sc.nextInt(); T > 1; T--, caseNo++) { solveIt(caseNo); }
		solveIt(caseNo);
	}

	void execute() {
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		this.sc = new FastIO();
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		sc.tr(G - S + "ms");
	}

	class FastIO {
		private boolean endOfFile() {
			if (bufferLength == -1) return true;
			int lptr = ptrbuf;
			while (lptr < bufferLength) {
				// _|_
				if (!isThisTheSpaceCharacter(inputBufffferBigBoi[lptr++])) return false;
			}
			try {
				is.mark(1000);
				while (true) {
					int b = is.read();
					if (b == -1) {
						is.reset();
						return true;
					} else if (!isThisTheSpaceCharacter(b)) {
						is.reset();
						return false;
					}
				}
			} catch (IOException e) {
				return true;
			}
		}

		private byte[] inputBufffferBigBoi = new byte[1024];
		int bufferLength = 0, ptrbuf = 0;

		private int justReadTheByte() {
			if (bufferLength == -1) throw new InputMismatchException();
			if (ptrbuf >= bufferLength) {
				ptrbuf = 0;
				try {
					bufferLength = is.read(inputBufffferBigBoi);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (bufferLength <= 0) return -1;
			}
			return inputBufffferBigBoi[ptrbuf++];
		}

		private boolean isThisTheSpaceCharacter(int c) { return !(c >= 33 && c <= 126); }

		private int skipItBishhhhhhh() {
			int b;
			while ((b = justReadTheByte()) != -1 && isThisTheSpaceCharacter(b));
			return b;
		}

		private double nextDouble() { return Double.parseDouble(next()); }

		private char nextChar() { return (char) skipItBishhhhhhh(); }

		private String next() {
			int b = skipItBishhhhhhh();
			StringBuilder sb = new StringBuilder();
			while (!(isThisTheSpaceCharacter(b))) {
				sb.appendCodePoint(b);
				b = justReadTheByte();
			}
			return sb.toString();
		}

		private char[] readCharArray(int n) {
			char[] buf = new char[n];
			int b = skipItBishhhhhhh(), p = 0;
			while (p < n && !(isThisTheSpaceCharacter(b))) {
				buf[p++] = (char) b;
				b = justReadTheByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}

		private char[][] readCharMatrix(int n, int m) {
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++) map[i] = readCharArray(m);
			return map;
		}

		private int[] readIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) a[i] = nextInt();
			return a;
		}

		private long[] readLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++) a[i] = nextLong();
			return a;
		}

		private int nextInt() {
			int num = 0, b;
			boolean minus = false;
			while ((b = justReadTheByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
			if (b == '-') {
				minus = true;
				b = justReadTheByte();
			}

			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = justReadTheByte();
			}
		}

		private long nextLong() {
			long num = 0;
			int b;
			boolean minus = false;
			while ((b = justReadTheByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
			if (b == '-') {
				minus = true;
				b = justReadTheByte();
			}

			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = justReadTheByte();
			}
		}

		private void tr(Object... o) {

			if (INPUT.length() != 0) System.out.println(Arrays.deepToString(o));

		}
	}

	InputStream is;
	PrintWriter out;
	String INPUT = "";
	final int ima = Integer.MAX_VALUE, imi = Integer.MIN_VALUE;
	final long lma = Long.MAX_VALUE, lmi = Long.MIN_VALUE;
	final long mod = (long) 1e9 + 7;
	FastIO sc;

}

// And I wish you could sing along, But this song is a joke, and the melody I
// wrote, wrong