import java.util.*;
import java.util.Map.Entry;
import java.lang.*;
import java.io.*;
 
public class AliceChoco {
	

	
	public static void main(String[] args) {
 
		Scanner input=new Scanner(System.in);
		int n=input.nextInt();
		int arr[]=new int[n];
		HashMap<Integer, Integer> hm=new HashMap<Integer, Integer>();
		hm.put(1, 0);
		hm.put(2, 0);
		hm.put(3, 0);
		hm.put(4, 0);
		hm.put(5, 0);
		hm.put(6, 0);
		hm.put(7, 0);
		
		for (int i = 0; i < arr.length; i++) {
			arr[i]=input.nextInt();
			hm.put(arr[i] , hm.get(arr[i])+1);
		}
		int count=n/3;
//		if(hm.get(1)==count) {
//			int count4=hm.get(4);
////			System.out.println(count4);
//			
//			int rest= hm.get(2)-count4;
//			if(rest<0) {
//				System.out.println(-1);
//			}
//			else {
//			if(rest + hm.get(3) == hm.get(6)) {
//				for(int i=0;i<count4;i++) {
//					System.out.print(1 + " " + 2 + " " + 4 + " ");
//				}
//				for(int i=0;i<rest;i++) {
//					System.out.print(1 + " " + 2 + " " + 6 + " ");
//				}
//				for(int i=0;i<hm.get(3);i++) {
//					System.out.print(1 + " " + 3 + " " + 6 + " ");
//				}
//			}
//			
//			else {
//				System.out.println(-1);
//			}
//			}
//		}
//		else {
//			System.out.println(-1);
//		}

		if(hm.get(5)==0 && hm.get(7)==0 && hm.get(2)>=hm.get(4) && hm.get(1)==hm.get(4) + hm.get(6) && hm.get(2)+hm.get(3) == hm.get(4) + hm.get(6)) {
			for(int i=0;i<hm.get(4);i++) {
				System.out.println(1 + " " + 2 + " " + 4 );
			}
			hm.put(2, hm.get(2)-hm.get(4));
			for(int i=0;i<hm.get(2);i++) {
				System.out.println(1 + " " + 2 + " " + 6 );
			}
			for(int i=0;i<hm.get(3);i++) {
				System.out.println(1 + " " + 3 + " " + 6 );
			}
		}
		else {
			System.out.println(-1);
		}
	}
}