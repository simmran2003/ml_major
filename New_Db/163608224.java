import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

/*
getOrDefault

valueOf

toCharArray()

System.out.println();

*/

public class HelloWorld{
     public static void main(String []args) throws Exception
     {  
        BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(infile.readLine());
        int T=Integer.parseInt(st.nextToken());
        int[] arr=new int[T];
        st = new StringTokenizer(infile.readLine());
        build(arr,st,0);
        PriorityQueue<Integer> pq=new PriorityQueue<>((a,b)->b-a);
        long res=0;
        for(int i=0;i<T;i++){
            if(!pq.isEmpty() && arr[i]<pq.peek()){
                res+=pq.poll()-arr[i];
                pq.add(arr[i]);
            }
            pq.add(arr[i]);
        }
        System.out.println(res);
     }
     
     public static void build(int[] arr, StringTokenizer st, int lo){
         for(int i=lo;i<arr.length;i++){
             arr[i]=Integer.parseInt(st.nextToken());
         }
     }
}
