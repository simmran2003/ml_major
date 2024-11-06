import java.util.*;
import java.io.*;

public class prog {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        ArrayList<String> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) arr.add(br.readLine());
        Collections.sort(arr, new Comparator<String>() {
            public int compare(String a, String b) {
                return (a+b).compareTo(b+a);
            } 
        });
        for (String i: arr) System.out.print(i);
        System.out.println();
    }
}