import java.util.*;
 
public class S {
 
	public static void main(String[] args) {
 
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] arr = new int[8];
		for(int i = 0; i<n; i++)
			arr[in.nextInt()]++;
		if(arr[7]!=0 || arr[5]!=0) {
			System.out.println(-1);
		}else {
			boolean ans = true;
			if(arr[3]!=0) {
				if(arr[3]>arr[6]) ans = false;
			}else {
				if(arr[3]==0 && arr[4]==0 && arr[6]==0) ans = false;
			}
			if((arr[1] != arr[2]+arr[3])&&(arr[1] != arr[4]+arr[6])) {
				ans = false;
			}
			
			if(ans) {
				while(arr[3]>0) {
					System.out.println(1+" "+3+" "+6);
					arr[6]--;
					arr[3]--;
					arr[1]--;
				}
				while(arr[4]>0) {
					System.out.println(1+" "+2+" "+4);
					arr[4]--;
					arr[2]--;
					arr[1]--;
				}
				while(arr[6]>0) {
					System.out.println(1+" "+2+" "+6);
					arr[6]--;
					arr[2]--;
					arr[1]--;
				}
				
			}else {
				System.out.println(-1);
			}
			
		}
		
		
	}
}