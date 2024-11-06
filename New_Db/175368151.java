/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc = new Scanner(System.in);
	    int n = sc.nextInt();
	    int a[] = new int[n], b[] = new int[8];
	    for(int i=0;i<n;i++){
	        a[i] = sc.nextInt();
	        b[a[i]]++;
	    }
	    int res[] = new int[3];
	    boolean f = true;
	        for(int i=0;i<n/3;i++){
	        if((b[1]>0 && b[2]>0 && b[4]>0)){
	            res[0]++;
	            b[1]--;b[2]--;b[4]--;
	            continue;
	        }
	        
	        if((b[1]>0 && b[2]>0 && b[6]>0)){
	        res[1]++;
	        b[1]--;b[2]--;b[6]--;
	        continue;
	        }
	        
	        if((b[1]>0 && b[3]>0 && b[6]>0)){
	        res[2]++;
	        b[1]--;b[3]--;b[6]--;
	        continue;
	        
	        }
	        f=false;break;
	        }
	        if(f==false)
	        System.out.println("-1");
	        else{
	        for(int i = 0; i < res[0]; i++)
			System.out.println("1 2 4");
		    for(int i = 0; i < res[1]; i++)
			System.out.println("1 2 6");
		    for(int i = 0; i < res[2]; i++)
			System.out.println("1 3 6");
	        }
	    
	    
// 		your code goes here
	}
}
