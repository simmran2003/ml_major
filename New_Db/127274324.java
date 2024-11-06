import static java.util.stream.Collectors.joining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class D {
	
	public static void main(String[] args) throws IOException {
		
		int[] line = readIntArray(2);
		int n = line[0];
		int m = line[1];
		
		int[] arr = readIntArray(n);
		
		int max = (int) 1e6;
		int[] count = new int[max + 1];
		for (int x : arr) {
			if (x <= m) {
				count[x]++;
			}
		}
		
		int[] res = new int[m + 1];
		for (int i = 1; i <= max; ++i) {
			for (int j = i; j <= m; j += i) {
				res[j] += count[i];
			}
		}
		int maxRes = 0;
		int lcm = 1;
		
		for (int i = 1; i <= m; ++i) {
			if (res[i] > maxRes) {
				maxRes = res[i];
				lcm = i;
			}
		}
		List<Integer> ints = new ArrayList<>();
		for (int i = 0; i < n; ++i) {
			if (lcm % arr[i] == 0) {
				ints.add(i + 1);
			}
		}
		println(lcm + " " + ints.size());
		println(ints.stream().map(Object::toString).collect(joining(" ")));
		flush();
	}

	
	
	static String[] splitLine(int limit) throws IOException {
		return splitLine(" ", limit);
	}

	static String[] splitLine(String regex, int limit) throws IOException {
		return readLine().split(regex, limit);
	}
	
	static String readLine() throws IOException {
		return reader.readLine();
	}
	
	static int readInt() throws IOException {
		String line = readLine();
		
		return parseInt(line, 0, line.length());
	}
	
	static int[] readIntArray(int n) throws IOException {
		String line = readLine();
		int off = 0;
		int[] arr = new int[n];
		--n;
		for (int i = 0; i < n; ++i) {
			int next = line.indexOf(' ', off);
			
			arr[i] = parseInt(line, off, next);
			off = ++next;
		}
		arr[n] = parseInt(line, off, line.length());
		
		return arr;
	}
	
	static int parseInt(String s, int low, int high) {
		boolean neg = false;
		if (s.charAt(low) == '-') { // fail-fast
			neg = true;
			++low;
		}
        int res = 0;
        while (low < high) {
            res = res * 10 - s.charAt(low++) + '0';
        }
        return neg ? res : -res;
	}
	
	static int capacity(int n) {
		return n < 3 ? ++n : (int) (n / 0.75F + 1F);
	}
	
	static void println(Object o) throws IOException {
		writer.write(String.valueOf(o));
		writer.write('\n');
	}
	
	static void println(int i) throws IOException {
		println(String.valueOf(i));
	}
	
	static void println(long l) throws IOException {
		println(String.valueOf(l));
	}
	
	static void flush() throws IOException {
		writer.flush();
	}
	
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static Writer writer = new BufferedWriter(new OutputStreamWriter(System.out));
	
	// =============================== DEBUG =============================== //
	
	static void debugln(Object o) throws IOException {
		debugln("%s", o);
	}
	
	static void debugln(String format, Object... args) throws IOException {
		for (int i = 0, len = args.length; i < len; ++i) {
			args[i] = deepToString(args[i]);
		}
		println("[DEBUG] " + String.format(format, args));
		flush();
	}
	
	static Object deepToString(Object o) {
		if (o == null || !o.getClass().isArray()) {
			return o;
		}
		int len = Array.getLength(o);
		if (len == 0) {
			return "[]";
		}
		StringBuilder sb = new StringBuilder(len << 2);
		sb.append('[');
		--len;
		for (int i = 0; i < len; ++i) {
			Object x = deepToString(Array.get(o, i));
			sb.append(x).append(',').append(' ');
		}
		Object x = deepToString(Array.get(o, len));
		sb.append(x).append(']');
		
		return sb.toString();
	}	
}
