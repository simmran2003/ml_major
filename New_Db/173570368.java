
import java.util.*;
 
 
public class Main {
	
	public static void main(String[] args) {
		Scanner scr = new Scanner(System.in);
		int n = scr.nextInt();
		int[] a = new int[n];
		int[] rec = new int[8]; 
		for(int i = 0;i < n;i++) {
			a[i] = scr.nextInt();
			rec[a[i]]++;
		}
		ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
		while(rec[1] > 0) {
			boolean cont = true;
			if(rec[2] > 0) {
				if(rec[4] > 0) {
					ans.add(new ArrayList<>(Arrays.asList(1,2,4)));
					rec[1]--;
					rec[2]--;
					rec[4]--;
				}else if(rec[6] > 0) {
					ans.add(new ArrayList<>(Arrays.asList(1,2,6)));
					rec[1]--;
					rec[2]--;
					rec[6]--;
				}else {
					cont = false;
				}
			}else if(rec[3] > 0) {
				if(rec[6] > 0) {
					ans.add(new ArrayList<>(Arrays.asList(1,3,6)));
					rec[1]--;
					rec[3]--;
					rec[6]--;
				}else {
					cont = false;
				}
			}else {
				cont = false;
			}
			if(cont == false) {
				System.out.println(-1);
				return;
				
			}
		}
		if(ans.size() == 0 || ans.size()*3 != n) {
			System.out.println(-1);
			return;	
		}
		for(ArrayList<Integer> el:ans) 
			System.out.println(el.get(0) + " " + el.get(1) + " " + el.get(2));
		if(scr != null) scr.close();
	}
}
