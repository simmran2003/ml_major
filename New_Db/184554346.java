import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Holes {

    public static void main(String[] args) throws IOException {

        BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));

        Solution sol = new Solution();
        sol.solve(log);

        log.close();
    }
}

class Solution {
    int blk_sz;

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                if (st.hasMoreTokens()) {
                    str = st.nextToken("\n");
                } else {
                    str = br.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    private boolean check(int i, int j) {
        return (i / blk_sz) == (j / blk_sz);
    }

    public void solve(BufferedWriter log) throws IOException {
        FastReader fr = new FastReader();
        int n = fr.nextInt();
        int m = fr.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = fr.nextInt();

        int[] jumps = new int[n];
        int[] next = new int[n];
        int[] last = new int[n];

        blk_sz = (int) Math.round(Math.sqrt(n));

        for (int i = n - 1; i >= 0; i--) {
            if ((i + arr[i]) >= n) {
                jumps[i] = 1;
                next[i] = -1;
                last[i] = i;
            } else if (check(i, i + arr[i])) {
                jumps[i] = jumps[i + arr[i]] + 1;
                next[i] = next[i + arr[i]];
                last[i] = last[i + arr[i]];
            } else {
                jumps[i] = 1;
                next[i] = i + arr[i];
                last[i] = i;
            }
        }

        // block_start[i] = Starting index of block to which i belongs to
        int[] block_start = new int[n];

        block_start[0] = 0;
        for (int i = 1; i < n; i++) {
            if (check(i, i - 1)) {
                block_start[i] = block_start[i - 1];
            } else {
                block_start[i] = i;
            }
        }

        for (int i = 0; i < m; i++) {
            int type = fr.nextInt();
            if (type == 0) {
                // update
                int idx = fr.nextInt();
                idx--;
                int val = fr.nextInt();

                arr[idx] = val;
                int beg = block_start[idx];
                while (idx >= beg) {
                    if ((idx + arr[idx]) >= n) {
                        jumps[idx] = 1;
                        next[idx] = -1;
                        last[idx] = idx;
                    } else if (check(idx, idx + arr[idx])) {
                        jumps[idx] = jumps[idx + arr[idx]] + 1;
                        next[idx] = next[idx + arr[idx]];
                        last[idx] = last[idx + arr[idx]];
                    } else {
                        jumps[idx] = 1;
                        next[idx] = idx + arr[idx];
                        last[idx] = idx;
                    }
                    idx--;
                }

            } else {
                // query
                int idx = fr.nextInt();
                idx--;

                int numJumps = 0, lastIndex = -1;

                while (idx != -1) {
                    numJumps += jumps[idx];
                    lastIndex = last[idx];
                    idx = next[idx];
                }
                lastIndex++;
                log.write(lastIndex + " " + numJumps + "\n");
            }
        }

    }
}