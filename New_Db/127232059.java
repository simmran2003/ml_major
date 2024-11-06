import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.lang.reflect.Array;

public class A {
	
	public static void main(String[] args) throws IOException {
		
		int line[] = readIntArray(2);
		int n = line[0];
		int p = line[1];
		
		boolean[] withHalf = new boolean[n];
		for (int i = 0; i < n; ++i) {
			withHalf[n - i - 1] = readLine().length() > 4;
		}
		long res = 0;
		long count = 0;
		for (boolean wf : withHalf) {
			if (!wf) {
				res += count * p;
				count *= 2;
			} else {
				res += count * p + p / 2;
				count = count * 2 + 1;
			}
		}
		println(res);
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
