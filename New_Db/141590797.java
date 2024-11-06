import java.io.*;
import java.util.*;

public class teams {
    public static void main (String[] args) throws IOException {
        // set up/read in input
        //BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream("test.in")));
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(input.readLine());
        StringTokenizer st = new StringTokenizer(input.readLine());
        long[] strengths = new long[N];
        for (int i=0;i<N;i++) strengths[i] = Long.parseLong(st.nextToken());
        String[] inputStr = input.readLine().split("");
        int[] assignments = new int[N];
        for (int i=0;i<N;i++) {
            assignments[i] = (int) inputStr[i].charAt(0) - 65;
        }
        //System.out.println(Arrays.toString(strengths));
        //System.out.println(Arrays.toString(assignments));
        // calculate prefix sum arrays
        //int[] currP = new int[N+1];
        long[] flipP = new long[N+1];
        long sum = 0;
        for (int i=1;i<=N;i++) {
            //currP[i] = currP[i-1];
            flipP[i] = flipP[i-1];
            if (assignments[i-1]==0) flipP[i] += strengths[i-1];
            else {
                sum += strengths[i-1];
                //currP[i] += strengths[i-1];
                flipP[i] -= strengths[i-1];
            }
        }
        long[] flipS = new long[N+1];
        for (int i=N-1;i>=0;i--) {
            flipS[i] = flipS[i+1];
            if (assignments[i]==0) flipS[i] += strengths[i];
            else {
                flipS[i] -= strengths[i];
            }
        }
        //System.out.println(Arrays.toString(currP));
        //System.out.println(Arrays.toString(flipP));
        //System.out.println(Arrays.toString(flipS));
        // find optimal prefix/suffix
        long maxStrength = 0;
        for (int i=0;i<=N;i++) {
            long strength = flipP[i] + sum;
            maxStrength = Math.max(strength, maxStrength);
            strength = flipS[i] + sum;
            maxStrength = Math.max(strength, maxStrength);
        }
        System.out.println(maxStrength);
    }
}
