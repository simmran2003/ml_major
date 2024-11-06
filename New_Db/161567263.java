import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

import org.w3c.dom.css.CSSCharsetRule;




public class Main {
	static final long MOD1=1000000007;
	static final long MOD=998244353;
	static final int NTT_MOD1 = 998244353;
	static final int NTT_MOD2 = 1053818881;
	static final int NTT_MOD3 = 1004535809;
	static int size = 0;
	static long MAX = 1000000000000000000l;
	public static void main(String[] args){
		PrintWriter out = new PrintWriter(System.out);
		InputReader sc=new InputReader(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] a = sc.nextIntArray(n);
		int[][] conv = new int[10][];
		conv[0] = new int[1001];
		for (int i = 0; i < n; i++) {
			conv[0][a[i]]=1;
		}
		for (int i = 1; i < 10; i++) {
			conv[i] = Convolution.convolution(conv[i-1], conv[i-1], NTT_MOD1);
			for (int j = 0; j < conv[i].length; j++) {
				conv[i][j] = Math.min(1, conv[i][j]);
			}
		}
		int[] ans = new int[1];
		ans[0] = 1;
		for (int i = 9; i >= 0; i--) {
			if(((k>>i)&1)==0) continue;
			ans = Convolution.convolution(ans, conv[i], NTT_MOD1);
			for (int j = 0; j < ans.length; j++) {
				ans[j] = Math.min(1, ans[j]);
			}
		}
		for (int i = 0; i < ans.length; i++) {
			if (ans[i] > 0) {
				out.println(i);
			}
		}
		out.flush();
   	}
	static class InputReader { 
		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;
		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}
		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}
 
		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}
 
		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}
 
		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}
 
		public boolean hasNext() {
			skip();
			return hasNextByte();
		}
 
		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
 
		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public double nextDouble() {
			return Double.parseDouble(next());
		}
 
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
		public double[] nextDoubleArray(int n) {
			double[] a = new double[n];
			for (int i = 0; i < n; i++)
				a[i] = nextDouble();
			return a;
		}
		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
}
class Convolution {
	 
	/**
	 * 畳み込み<br>
	 * 制約：n = |a|+|b|として、n - 1 ≦ 2^c かつ (mod - 1)が2^cで割り切れる<br>
	 * O(n log n + log mod)
	 *
	 * @param a 数列
	 * @param b 数列
	 * @param mod NTT用素数（998244353, 1053818881, 1004535809, ...）
	 * @return ret[i] = sum(j=0～i) {a[j] * b[i-j]}
	 */
	static int[] convolution(int[] a, int[] b, int mod) {
		int n = a.length;
		int m = b.length;
		if (n == 0 || m == 0) {
			return new int[0];
		}
 
		int z = 1 << ceilPow2(n + m - 1);
		{
			int[] na = new int[z];
			int[] nb = new int[z];
			System.arraycopy(a, 0, na, 0, n);
			System.arraycopy(b, 0, nb, 0, m);
			a = na;
			b = nb;
		}
 
		int g = primitiveRoot(mod);
		int[] sume = sumE(mod, g);
		int[] sumie = sumIE(mod, g);
 
		butterfly(a, sume, mod);
		butterfly(b, sume, mod);
		for (int i = 0; i < z; i++) {
			a[i] = (int) ((long) a[i] * b[i] % mod);
		}
		butterflyInv(a, sumie, mod);
		a = Arrays.copyOf(a, n + m - 1);
 
		long iz = powMod(z, mod - 2, mod);
		for (int i = 0; i < n + m - 1; i++)
			a[i] = (int) (a[i] * iz % mod);
		return a;
	}
 
	/**
	 * 畳み込み<br>
	 * 制約：n = |a|+|b|として、n - 1 ≦ 2^24<br>
	 * O(n log n)
	 *
	 * @param a 数列
	 * @param b 数列
	 * @param mod 任意のmod
	 * @return ret[i] = sum(j=0～i) {a[j] * b[i-j]}
	 */
	static int[] convolution2(int[] a, int[] b, int mod) {
		int n = a.length;
		int m = b.length;
		if (n == 0 || m == 0)
			return new int[0];
 
		int mod1 = 754974721;
		int mod2 = 167772161;
		int mod3 = 469762049;
 
		int[] c1 = convolution(a, b, mod1);
		int[] c2 = convolution(a, b, mod2);
		int[] c3 = convolution(a, b, mod3);
 
		int retSize = c1.length;
		int[] ret = new int[retSize];
		int[] mods = { mod1, mod2, mod3, mod };
		for (int i = 0; i < retSize; ++i) {
			ret[i] = garner(new int[] { c1[i], c2[i], c3[i] }, mods);
		}
		return ret;
	}
 
	private static int primitiveRoot(int m) {
		if (m == 2) return 1;
		if (m == 167772161) return 3;
		if (m == 469762049) return 3;
		if (m == 754974721) return 11;
		if (m == 998244353) return 3;
 
		int[] divs = new int[20];
		divs[0] = 2;
		int cnt = 1;
		int x = (m - 1) / 2;
		while (x % 2 == 0) {
			x /= 2;
		}
		for (int i = 3; (long) (i) * i <= x; i += 2) {
			if (x % i == 0) {
				divs[cnt++] = i;
				while (x % i == 0) {
					x /= i;
				}
			}
		}
		if (x > 1) {
			divs[cnt++] = x;
		}
		for (int g = 2;; g++) {
			boolean ok = true;
			for (int i = 0; i < cnt; i++) {
				if (powMod(g, (m - 1) / divs[i], m) == 1) {
					ok = false;
					break;
				}
			}
			if (ok) return g;
		}
	}
 
	private static int powMod(int x, int n, int m) {
		if (m == 1) return 0;
		long r = 1;
		long y = x % m;
		while (n > 0) {
			if ((n & 1) != 0) r = (r * y) % m;
			y = (y * y) % m;
			n >>= 1;
		}
		return (int) r;
	}
 
	private static int ceilPow2(int n) {
		int x = 0;
		while ((1L << x) < n) {
			x++;
		}
		return x;
	}
 
	private static int[] sumE(int mod, int g) {
		int[] sum_e = new int[30];
		int[] es = new int[30];
		int[] ies = new int[30];
		int cnt2 = Integer.numberOfTrailingZeros(mod - 1);
		int e = powMod(g, (mod - 1) >> cnt2, mod);
		int ie = powMod(e, mod - 2, mod);
		for (int i = cnt2; i >= 2; i--) {
			es[i - 2] = e;
			ies[i - 2] = ie;
			e = (int) ((long) e * e % mod);
			ie = (int) ((long) ie * ie % mod);
		}
		long now = 1;
		for (int i = 0; i < cnt2 - 2; i++) {
			sum_e[i] = (int) (es[i] * now % mod);
			now = now * ies[i] % mod;
		}
		return sum_e;
	}
 
	private static int[] sumIE(int mod, int g) {
		int[] sum_ie = new int[30];
		int[] es = new int[30];
		int[] ies = new int[30];
 
		int cnt2 = Integer.numberOfTrailingZeros(mod - 1);
		int e = powMod(g, (mod - 1) >> cnt2, mod);
		int ie = powMod(e, mod - 2, mod);
		for (int i = cnt2; i >= 2; i--) {
			es[i - 2] = e;
			ies[i - 2] = ie;
			e = (int) ((long) e * e % mod);
			ie = (int) ((long) ie * ie % mod);
		}
		long now = 1;
		for (int i = 0; i < cnt2 - 2; i++) {
			sum_ie[i] = (int) (ies[i] * now % mod);
			now = now * es[i] % mod;
		}
		return sum_ie;
	}
 
	private static void butterfly(int[] a, int[] sumE, int mod) {
		int n = a.length;
		int h = ceilPow2(n);
 
		for (int ph = 1; ph <= h; ph++) {
			int w = 1 << (ph - 1), p = 1 << (h - ph);
			long now = 1;
			for (int s = 0; s < w; s++) {
				int offset = s << (h - ph + 1);
				for (int i = 0; i < p; i++) {
					int l = a[i + offset];
					int r = (int) (a[i + offset + p] * now % mod);
					a[i + offset] = (l + r) % mod;
					a[i + offset + p] = (l - r + mod) % mod;
				}
				int x = Integer.numberOfTrailingZeros(~s);
				now = now * sumE[x] % mod;
			}
		}
	}
 
	private static void butterflyInv(int[] a, int[] sumIE, int mod) {
		int n = a.length;
		int h = ceilPow2(n);
 
		for (int ph = h; ph >= 1; ph--) {
			int w = 1 << (ph - 1), p = 1 << (h - ph);
			long inow = 1;
			for (int s = 0; s < w; s++) {
				int offset = s << (h - ph + 1);
				for (int i = 0; i < p; i++) {
					int l = a[i + offset];
					int r = a[i + offset + p];
					a[i + offset] = (l + r) % mod;
					a[i + offset + p] = (int) ((mod + l - r) * inow % mod);
				}
				int x = Integer.numberOfTrailingZeros(~s);
				inow = inow * sumIE[x] % mod;
			}
		}
	}
 
	private static int garner(int[] c, int[] mods) {
		int n = c.length + 1;
		int[] cnst = new int[n];
		int[] coef = new int[n];
		Arrays.fill(coef, 1);
		for (int i = 0; i < n - 1; i++) {
			int m1 = mods[i];
			long v = ((long) c[i] - cnst[i] + m1) % m1;
			v = v * powMod(coef[i], m1 - 2, m1) % m1;
 
			for (int j = i + 1; j < n; j++) {
				int m2 = mods[j];
				cnst[j] = (int) ((cnst[j] + (long) coef[j] * v) % m2);
				coef[j] = (int) (((long) coef[j] * m1) % m2);
			}
		}
		return cnst[n - 1];
	}
}
