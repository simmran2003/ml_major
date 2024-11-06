// practice with rainboy
import java.io.*;
import java.util.*;

public class CF342D extends PrintWriter {
	CF342D() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF342D o = new CF342D(); o.main(); o.flush();
	}

	static final int MD = 1000000007;
	boolean[] valid;
	void init() {
		valid = new boolean[1 << 6];
		for (int b = 0; b < 1 << 6; b++) {
			int a = b;
			if ((a & 1 << 0) != 0) {
				if ((a & 1 << 3) == 0)
					continue;
				a ^= 1 << 3;
			}
			if ((a & 1 << 1) != 0) {
				if ((a & 1 << 4) == 0)
					continue;
				a ^= 1 << 4;
			}
			if ((a & 1 << 2) != 0) {
				if ((a & 1 << 5) == 0)
					continue;
				a ^= 1 << 5;
			}
			if (a >> 3 == 0 || (a >> 3 & 1) != (a >> 5 & 1) && (a >> 4 & 1) != 0)
				valid[b] = true;
		}
	}
	int solve(byte[][] cc, int n) {
		int[][] dp = new int[n + 1][1 << 3]; dp[0][0] = 1;
		for (int i = 0; i < n; i++)
			for (int b = 0; b < 1 << 3; b++) {
				if ((b & 1 << 0) != 0 && cc[0][i] == 'X')
					continue;
				if ((b & 1 << 1) != 0 && cc[1][i] == 'X')
					continue;
				if ((b & 1 << 2) != 0 && cc[2][i] == 'X')
					continue;
				int a_ = 0;
				if ((b & 1 << 0) == 0 && cc[0][i] != 'X')
					a_ |= 1 << 0;
				if ((b & 1 << 1) == 0 && cc[1][i] != 'X')
					a_ |= 1 << 1;
				if ((b & 1 << 2) == 0 && cc[2][i] != 'X')
					a_ |= 1 << 2;
				a_ <<= 3;
				for (int a = 0; a < 1 << 3; a++) {
					int x = dp[i][a];
					if (x != 0 && valid[a | a_])
						dp[i + 1][b] = (dp[i + 1][b] + x) % MD;
				}
			}
		return dp[n][0];
	}
	void main() {
		init();
		int n = sc.nextInt();
		byte[][] cc = new byte[3][];
		for (int i = 0; i < 3; i++)
			cc[i] = sc.next().getBytes();
		int io = -1, jo = -1;
out:
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				if (cc[i][j] == 'O') {
					cc[i][j] = 'X';
					io = i; jo = j;
					break out;
				}
		int ans = solve(cc, n);
		if (io == 1 && jo - 1 >= 0 && jo + 1 < n) {
			for (int i = 0; i < 3; i++)
				for (int j = jo - 1; j <= jo + 1; j++)
					cc[i][j] = 'X';
			ans = (ans - solve(cc, n) * 2) % MD;
			if (ans < 0)
				ans += MD;
		}
		println(ans);
	}
}
