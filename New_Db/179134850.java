import java.io.*;
import java.util.*;
 public class Main {
	static BufferedReader br;
	//static long  res=0;
	static int mod=1000000007;
	//static ArrayList<ArrayList<Integer>> arr=new ArrayList<>();
	static StringBuilder ans=new StringBuilder("");
	static int INF=10000000;
	static int c0=0,c1=0;
	static long total=0;
	public static void main(String args[]) throws IOException {
		br=new BufferedReader(new InputStreamReader(System.in));
		int inp[]=readInt(1);
		int n=inp[0];
		String str[]=new String[n];
		int i;
		for(i=0;i<n;i++)
		str[i]=br.readLine();
		Arrays.sort(str,(x,y)->{
			return ((x+""+y).compareTo(y+""+x));
			
		});
		for(i=0;i<n;i++)
		ans.append(str[i]);
		//ans.append(dp[n-1]);
		printString(ans.toString());
	}
	public static int fk(int arr[],int d,int m){
		int n=arr.length;
		int i;
		for(i=0;i<n;i++){
			if(i%2==0&&arr[i]==d)
			return 0;
			if(i%2==1&&arr[i]!=d)
			return 0;
		}
		long sum=0;
		for(i=0;i<n;i++){
			sum=(sum*10+arr[i])%m;
		}
		if(sum==0)
		return 1;
		return 0;
		
	}
	public static long rec(int i,int j,int t,long dp[][][],int a[],int b[],int m,int d,boolean bool){
		if(i==a.length){
			if(j==0)
			return 1;
			return 0;
		}
		if(dp[i][j][t]!=-1)
		return dp[i][j][t];
		int ub=(t==1)?a[i]:9;
		long res=0;
		if(i%2==1){
			if(ub<d)
			return 0;
			res+=rec(i+1,(j*10+d)%m,(ub==d&&t==1)?1:0,dp,a,b,m,d,bool);
		}
		else{
			int st=1;
			if(bool==false){
				st=0;
			}
			for(int k=st;k<=ub;k++){
				if(k==d)
				continue;
				if(t==0||k<ub)
				res=(res+rec(i+1,(j*10+k)%m,0,dp,a,b,m,d,false))%mod;
				else
				res=(res+rec(i+1,(j*10+k)%m,1,dp,a,b,m,d,false))%mod;
				
			}
		}
		return dp[i][j][t]=res%mod;
	}
	public static int find(int parent[],int x){
		if(parent[x]!=x)
		return parent[x]=find(parent,parent[x]);
		return parent[x];
	}
	public static void merge(int parent[],int rank[],int x,int y){
		x=find(parent,x);
		y=find(parent,y);
		if(x==y)
		return ;
		if(rank[x]>rank[y]){
			parent[y]=x;
		}
		else{
			parent[x]=y;
			rank[y]++;
		}
	}
	public static boolean fuck(int arr[],int m){
		TreeMap<Integer,Integer> map=new TreeMap<>();
		for(int g:arr){
			if(map.containsKey(g))
			map.put(g,map.get(g)+1);
			else
			map.put(g,1);
		}
		int cnt=m+1;
		
		int q=0;
		while(true&&cnt>=0){
			cnt--;
			Integer x=map.floorKey(cnt);
			//System.out.println(x+" "+m);
			if(map.floorKey(cnt)==null){
				//System.out.println("fff");
				break;
			}
			//System.out.println(map.get(x));
			map.put(x,map.get(x)-1);
			if(map.get(x)==0)
			map.remove(x);
			//System.out.println(map.get(x));
			//System.out.println(map.floor(cnt)+" "+map.remove(map.floor(cnt)));
			if(map.size()>0){
				int p;
				p=map.firstKey();
				map.put(p,map.get(p)-1);
				//System.out.println(map.get(p));
			    //System.out.println(map.get(p));
				if(map.get(p)==0)
				map.remove(p);
				p=p+cnt;
				map.put(p,map.getOrDefault(p,0)+1);
			}
			else{
				break;
			}
			
			q++;
		}
		//System.out.println(m+" "+q);
		return q>=m;
		
		
		
	}
	public static int fun(int dp[],int i,int k,int arr[]){
		if(i>=arr.length)
		return 0;
		if(dp[i]!=-1)
		return dp[i];
		int res=fun(dp,i+1,k,arr);//-10^9
		for(int j=i+1;j<=Math.min(arr.length-1,(i+k));j++){
			if(arr[j]>=arr[i]){
				res=Math.max(res,(arr[j]-arr[i])+fun(dp,j+1,k,arr));
			}
			
				//res=Math.max(res,fun(dp,j,k-(j-i),arr));
				
		}
		return dp[i]=res;
		
	}
	public static boolean kjs(int n,int u,int p,boolean vis[],int color[],int c,ArrayList<Integer> graph[]){
		vis[u]=true;
		color[u]=c;
		if(u<=n&&c%2==0){
			c0++;
		}
		else if(u<=n){
			c1++;
		}
		for(int v:graph[u]){
			if(v==p)
			continue;
			if(vis[v]==false){
				kjs(n,v,u,vis,color,1-c,graph);
			}
			else if(color[v]==c)
			return false;
		}
		return true;
	}
	
	public static boolean check4(int arr[]){
		int i;
		int n=arr.length;
		for(i=1;i<n;i++){
			if(arr[i]>=arr[i-1]){
				continue;
			}
			return false;
		}
		return true;
	}
	public static void prs(int u,int p,long res[],ArrayList<Integer> graph[],long sub_sum[]){
		for(int v:graph[u]){
			if(v==p)
			continue;
			res[v]=res[u]-sub_sum[v];
			res[v]+=(total-sub_sum[v]);
			prs(v,u,res,graph,sub_sum);
		}
	}
	public static void bfs(int u,int p,long sub[],ArrayList<Integer> graph[],int val[],int level){
		sub[u]=val[u];
		for(int v:graph[u]){
			if(v==p)
			continue;
			bfs(v,u,sub,graph,val,level+1);
			sub[u]+=sub[v];
			total+=(long)level*(long)val[v];
		}
		
	}
	public static int check(int a[],int m){
		int n=a.length;
		int res=0;
		int q=2*m-1;
		for(int i=0;i<n;i++){
			int p=a[i];
			int x=1;
			while(p>q){
				res+=x;
				p=p/2;
				x=2*x;
			}
			//System.out.println(res-1);
		}
		return res;
		
		
	}
	public static  void rec(int n,int k,int dp[][],int a[],int b[],int curr){
		
		
	}
	static int bitcount(int x){
		int y=0;
		while(x>0){
			if(x%2==1)
			y++;
			x=x>>1;
		}
		return y;
	}
	public static boolean countf(int x){
		int c=0;
		while(x>0){
			if(x%2==1)
			c++;
			x=x>>1;
		}
		return c<=1;
	}
	public static long[][] mul(long a[][],long c[][]){
		int n=a.length;
		long b[][]=new long[n][n];
		for(int i=0;i<n;i++){
			Arrays.fill(b[i],0);
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					b[i][j]+=(a[i][k]*c[k][j])%mod;
				}
				b[i][j]=b[i][j]%mod;
			}
		}
		return b;
	}
	public static long[][] pow(long mat[][],long p){
		if(p==1)
		return mat;
			int n=mat.length;
		long res[][]=new long[n][n];
	
		int i;
		for(i=0;i<n;i++)
		res[i][i]=1;
		while(p>0){
			if((p&1) >0){
				res=mul(res,mat);
			}
			mat=mul(mat,mat);
			p=p>>1;
		}
		return res;	
	}
	public static void dfs(int u,int p,int val[],ArrayList<Integer> graph[],boolean vis[],int sub[]){
		vis[u]=true;
		int val_parent=0;
		if(p!=-1)
		val_parent=val[p];
		int min=Integer.MAX_VALUE;
		if(val[u]==-1){
			for(int v:graph[u]){
				min=Math.min(min,val[v]);
		}
		if(graph[u].size()==0)
		min=val_parent;
		val[u]=min;
		}
		for(int v:graph[u]){
			if(vis[v]==false)
			dfs(v,u,val,graph,vis,sub);
		}
		
		sub[u]=val[u]-val_parent;
		
		
	}
	public static int fun(int dp[],int a[],int mask,int j,int n){
		if(count(mask)==0)
		return 0;
		if(dp[mask]!=-1)
		return dp[mask];
		int c=n-count(mask)+1;
		int ans=10000000;
		for(int k=0;k<n;k++){
			if((mask&(1<<k))>0){
				int moves=(a[k]+c-1)/c;
				ans=Math.min(ans,moves +fun(dp,a,(mask)^(1<<k),j,n));
			}
		}
		return dp[mask]=ans;
	}
	public static int count(int x){
		int c=0;
		while(x>0){
			c+=x%2;
			x=x/2;
		}
		return c;
	}
	
	public static boolean isPalindrome(String str)
    {
        // Initializing an empty string to store the reverse
        // of the original str
        String rev = "";
 
        // Initializing a new boolean variable for the
        // answer
        boolean ans = false;
 
        for (int i = str.length() - 1; i >= 0; i--) {
            rev = rev + str.charAt(i);
        }
 
        // Checking if both the strings are equal
        if (str.equals(rev)) {
            ans = true;
        }
        return ans;
    }
	
	public static long memo(long dp[][],int i,int j,long arr[]){
		if(j==dp[0].length)
		return 0;
		if(i>=arr.length)
		return -1*(long)Math.pow(10,15);
		if(dp[i][j]!=-1)
		return dp[i][j];
		dp[i][j]=Math.max(memo(dp,i+1,j+1,arr)+arr[i]*(j+1),memo(dp,i+1,j,arr));
		return dp[i][j];
	}
	public static int gcd(int a, int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
	public static void fun(int curr,int count,int x,int y,ArrayList<Integer> pres){
		
	}
	// public static mine min(mine x,mine y){
	// 	if(x.a>y.a)
	// 	return y;
	// 	if(y.a>x.a)
	// 	return x;
	// 	if(x.b>y.b)
	// 	return y;
	// 	return x;
	// }
	public static int[] readInt(int n) throws IOException {
		String str[]=br.readLine().split(" ");
		int a[]=new int[n];
		for(int i=0;i<n;i++)
		a[i]=Integer.parseInt(str[i]);
		return a;
	}
	public static ArrayList<Integer> readList(int n) throws IOException {
		String str[]=br.readLine().split(" ");
		ArrayList<Integer> arr=new ArrayList<>();
		for(int i=0;i<n;i++)
		arr.add(Integer.parseInt(str[i]));
		return arr;
	}
	public static char[] readChar(int n) throws IOException {
		String str=br.readLine();
		char a[]=new char[n];
		for(int i=0;i<n;i++)
		a[i]=str.charAt(i);
		return a;
	}
	public static long[] readLong(int n) throws IOException {
		String str[]=br.readLine().split(" ");
		long a[]=new long[n];
		for(int i=0;i<n;i++)
		a[i]=Long.parseLong(str[i]);
		return a;
	}
	public static void printString(String str){
		System.out.println(str);
	}
	public static void printInt(int str){
		System.out.println(str);
	}
	
	public static void printLong(long str){
		System.out.println(str);
	}
	public static int Int() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	public static long Long() throws IOException {
		return Long.parseLong(br.readLine());
	}
	public static String[] readString() throws IOException {
		return br.readLine().split(" ");
	}
}
class mine{
	long num;
	int index;
	public mine(long x,int y){
		num=x;
		index=y;
	}
}