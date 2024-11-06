/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
 
/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
   
     static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 

        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 

        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 

        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 

        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 

        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 

        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }
    int binary(int arr[], int x)
    {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == x)
                return m;
            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
    static int[] segment,parent,rank;
    static void constructSt(int n, int[] arr){
        segment = new int[n*4+1];
        formSt(arr, 1,0,n-1);
    }
    public static void formSt(int[] arr, int node, int s, int e){
        if(s==e){
            segment[node]= arr[s];
            return;
        }
        formSt(arr, node*2,s,s+(e-s)/2);
        formSt(arr, node*2+1,s+(e-s)/2+1,e);
        segment[node]=Math.max(segment[node*2],segment[node*2+1]);
    }
    public static int findMax( int node, int s, int e,int l , int r){
        if(l>e||s>r) return -1;
        if(s==e) return segment[node];
        if(l<=s&&r>=e) return segment[node];
        int mid = s+(e-s)/2;
        return Math.max(findMax(node*2,s,mid,l,r),findMax(node*2+1,mid+1,e,l,r));
    }
    public static void dsu(int n){
        parent = new int[n]; rank = new int[n];
        for(int i =0;i<n;i++) parent[i]=i;
    }
    public static int find(int i){
        if(i==parent[i] ) return i;
        return parent[i]=find(parent[i]);
    }
    public static void merge(int i, int j){
        if(rank[i]>=rank[j]){
            rank[i]+=rank[j];
            parent[j]=i;
        }
        else {
            rank[j]+=rank[i];
            parent[i]=j;
        }
    }
    static int count =0;
    static boolean[] v;
    public static  int solve(List<List<Integer>> a , int n, char[] c){
        v=new boolean[n+1];
        help(a,n,c,1);
        count=0;
       // System.out.println(a)
        for(boolean e:v) if(e) count++;
        return count;
    }
    public static int[] help(List<List<Integer> >a , int n , char[] c , int i ){
        int[] arr = new int[2];
        arr[c[i-1]=='W'?0:1]++;
        for(int e:a.get(i)){
            int[] x = help(a,n,c,e);
            arr[0]+=x[0]; arr[1]+=x[1];
        }
        v[i]= arr[0]==arr[1];
        return arr;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
	 OutputStream outputStream =System.out;
        PrintWriter out =new PrintWriter(outputStream);
        FastReader sc =new FastReader();
        int n =sc.nextInt();
        String[] s = new String[n];
        for(int i =0;i<n;i++) s[i] = sc.nextLine();
        Arrays.sort(s,(x,y)->(x+y).compareTo(y+x));
        for(String e: s) out.print(e);
	    out.close();
		// your code goes here"
	}
}
 class pair
    {
        long r;
        long d;
        public pair(long r , long d)
        {
            this.r= r;
            this.d= d;
        }
    }
class solution{
    
    }
