/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner s=new Scanner(System.in);
	    int n=s.nextInt();
	    int count[]=new int[8];
	    for(int q=0;q<n;q++){
	        int num=s.nextInt();
	        count[num]++;
	    }
	    if(count[7]!=0 || count[4]+count[6]!=n/3 || count[4]+count[6]>count[1] || count[4]>count[2]){
	        System.out.println(-1);
	        return;
	    }
	    int left=count[2]-count[4];
	    if(left+count[3]<count[6]){
	        System.out.println(-1);
	        return;
	    }
	    while(count[4]>0){
	        System.out.println("1 2 4");
	        count[4]--;
	        count[2]--;
	        count[1]--;
	    }
	    while(count[2]>0){
	        System.out.println("1 2 6");
	        count[2]--;
	        count[6]--;
	    }
	    while(count[6]>0){
	        System.out.println("1 3 6");
	        count[6]--;
	    }
		// your code goes here
	}
}
