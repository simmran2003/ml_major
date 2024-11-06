import java.util.*;
import java.io.*;
 
public class XeniaAndSpies {
    public static void main(String[] args) {
        Scanner in=new Scanner (System.in);
        int n=in.nextInt();
        int m=in.nextInt();
        int x=in.nextInt();
        int y=in.nextInt();
        StringBuilder ans=new StringBuilder();boolean flag=true;
        int diff;
        if (y>x)
        {
        for(int i=0;i<m&&x!=y;i++)
        {
        int t=in.nextInt();
        int s1=in.nextInt();
        int s2=in.nextInt();
        while(t!=i+1&&i<m&&x!=y)
        {
        ans.append('R');
        x++;
        i++;
        }
        if(i<m&&x!=y)
        {
        if((x>=s1&&x<=s2)||(x+1>=s1&&x+1<=s2))
        {
        ans.append('X');
        }
        else
        {
        ans.append('R');
        x++;
        }
        }}
        if (x!=y)
        {
        diff=y-x;
        char arr[]=new char[diff];
        Arrays.fill(arr, 'R');
        ans.append(arr);
        }

        }
        else if(x>y)
        {
        for(int i=0;i<m&&x!=y;i++)
        {
        int t=in.nextInt();
        int s1=in.nextInt();
        int s2=in.nextInt();
        while(t!=i+1&&i<m&&x!=y)
        {
        ans.append('L');
        x--;
        i++;
        }
        if(i<m&&x!=y){
         if((x>=s1&&x<=s2)||(x-1>=s1&&x-1<=s2))
        {
        ans.append('X');
        }
        else
        {
        ans.append('L');
        x--;
        }
        
        }}
        if (x!=y)
        {
        diff=x-y;
        char arr[]=new char[diff];
        Arrays.fill(arr, 'L');
        ans.append(arr);
        }
        }
        else
        {System.out.print("X");
        flag=false;}
        
        if (flag)
        System.out.print(ans);
        //out.close(); 
        }}