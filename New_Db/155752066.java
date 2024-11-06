




import java.util.*;
import java.io.*;


public class Main {
	
	
//##############################FAST READER###################################
	
	
   static class FastReader{
	   BufferedReader br;
	   StringTokenizer st;
	   FastReader(){
		  br=new BufferedReader(new InputStreamReader(System.in));
	   }
	   String next() {
		 while(st==null||!st.hasMoreElements()) {
		   try {
			  st=new StringTokenizer(br.readLine());
		   }catch(IOException e) {
		  e.printStackTrace();
		  }
		 }
		 return st.nextToken();
	   }
	   
	  int nextInt() {
		  return Integer.parseInt(next());
	  }
	  long nextLong() {
		  return Long.parseLong(next());
	  }
	  double nextDouble() {
		  return Double.parseDouble(next());
	  }
	  String nextLine() {
		  String str="";
		  try {
			  str=br.readLine();
		  } catch(IOException e) {
			  e.printStackTrace();
		  }
		  return str;
	  }
   }

 //###########################################################################  
   
	static class Pair
	implements Comparable<Pair>
	{
		  int x;
		  int y;
		  Pair(int x,int y){
			  this.x=x;
			  this.y=y;
		  }
		  @Override
		  public int compareTo(Pair o) {
			return this.x-o.x;  
		  }
		}

 //##############################USEFUL FUNCTIONS#####################################
	
  static long gcd(long a,long b) {
	  if(b==0) return a;
	else
	  return gcd(b,a%b);
   }
  
  
  static List primeFactors(int n){
     List<Integer> ar=new ArrayList<>();
     int ct=0;
      for(int i=2;i*i<=n;i++) {
	    if(n%i==0) {
		  ar.add(i);
		  ct++;
	     while(n%i==0) {
	       n/=i;
	     }
       }
     }
    if(n>1) {
    	ct++;
	 ar.add(n);
    }
    return ar;
   }
  
  static long powM(long x,long y,long mod) {
		if(y==0)
			return 1;
		long k=powM(x,y/2,mod);
		
		if(y%2==1) {
			return (((((long)1*k*k)%mod)*x)%mod);
		}
		else {
			return (((long)1*k*k)%mod);
		}
  }
  
  
  static int ub(ArrayList<Integer>ar,int k) {
	int s=0;
	int e=ar.size();
	while(s!=e) {
	  int mid=s+e>>1;
	  if(ar.get(mid)<=k)
		 s=mid+1;
	  else
		 e=mid;
     }
	if(s==ar.size())
		return -1;
    return s;
  }
  
   
  
 static boolean isPrime(long n) {
	 boolean flag=true;
	 if(n<2)
		 flag=false;
	 else {
		 for(int i=2;i*i<=n;i++){
			if(n%i==0) {
			 flag=false;
			 break;
			}
		 }
	 }
	 return flag;
 }
 
 static void print(int a[]) {
	 for(int i=0;i<a.length;i++) {
		 System.out.print(a[i]+" ");
     }
	 System.out.println();
 }
 
 static void print(long a[]) {
	 for(int i=0;i<a.length;i++) {
		 System.out.print(a[i]+" ");
     }
	 System.out.println();
 }
 
 
 static int[] read(int[] a,FastReader sc) {
	 for(int i=0;i<a.length;i++) {
		 a[i]=sc.nextInt();
	 }
	 return a;
 }
 
 static long[] read(long[] a,FastReader sc) {
	 for(int i=0;i<a.length;i++) {
		 a[i]=sc.nextLong();
	 }
	 return a;
 }
 
 static void printL(List<Integer>li) {
	for(int i=0;i<li.size();i++) {
		System.out.print(li.get(i)+" ");
	}
	System.out.println();
 }
 
 static void print(List<Long>li) {
		for(int i=0;i<li.size();i++) {
			System.out.print(li.get(i)+" ");
		}
		System.out.println();
 }
 
 static String sort(String s) {
	 char ch[]=s.toCharArray();
	 Arrays.sort(ch);
	 return new String(ch);
 }

 static boolean isPalindrome(long a) {
    String s=Long.toString(a);
    StringBuilder rev=new StringBuilder(s);
    rev.reverse();
    String s1=rev.toString();
    
    return s.equals(s1);
    
 }
 
 static int[] swap(int a[],int i,int j) {
	 int temp=a[i];
	 a[i]=a[j];
	 a[j]=temp;
	 return a;
 }
 
 static long[] swap(long a[],int i,int j) {
	 long temp=a[i];
	 a[i]=a[j];
	 a[j]=temp;
	 return a;
 }
 
 
 public static String addCharToString(String str, char c, int pos)
 {

    StringBuffer stringBuffer = new StringBuffer(str);
    stringBuffer.insert(pos, c);
    return stringBuffer.toString();
 }
 
 static int BigMod(String num, int a)
 {
    int res = 0;
    for (int i = 0; i < num.length(); i++)
         res = (res * 10 + (int)num.charAt(i)); 
    return res;

 }
 static boolean isSquare(int n) {
		for(int i=1;i*i<=n;i++) {
			if((i*i)==n)
				return true;
		}
		return false;
 }

 static long firstsetBitPower(long n)
 {
     int k = (int)(Math.log(n) / Math.log(2));
    
     return 1 << k;
 }

 static boolean inrange(int key,int l,int r,int n) {
	 boolean flag=false;
	 if(key==0) {
		if(key+1>=l&&key+1<=r) {
			flag=true;
		}
	 }
	 else if(key==n+1) {
		if(key-1>=l&&key+1<=r) {
			flag=true;
		}
	 }
	 else {
		if(key>=l&&key<=r) {
			flag=true;
		}
	 }
	 return flag;
 }
 //#############################MAIN FUNCTION##################################
 
 
 public static void main(String[] args) {
 try {
 
 
   FastReader sc = new FastReader();
  
//   int t=sc.nextInt();
//   
//   while(t-->0) {
//     	 
//   }
    
   
   
   
     int n=sc.nextInt();
     int m=sc.nextInt();
     int s=sc.nextInt();
     int f=sc.nextInt();
     
     Map<Integer,Pair>mp=new HashMap<>();
     
     for(int i=0;i<m;i++) {
    	 int t=sc.nextInt();
    	 int l=sc.nextInt();
    	 int r=sc.nextInt();
    	 mp.put(t, new Pair(l,r));
     }
        
    
     StringBuilder ans=new StringBuilder(""); 
    
     int step=1;
     
     while(s!=f) {
    	 
       if(mp.get(step)!=null) {
    	  int l=mp.get(step).x;
    	  int r=mp.get(step).y;
    	 if(s<f) {
    	  if(inrange(s,l,r,n)||inrange(s+1,l,r,n)) {
    		ans.append('X');
    		
    	 }
    	 else {
    	    s++;
    	    ans.append('R');
    	  }
        }
    	else {
    	  if(inrange(s,l,r,n)||inrange(s-1,l,r,n)) {
    		  ans.append('X');
    	  }
    	  else {
    		  s--;
    		  ans.append('L');
    	  }
    	}
    }
       else {
    	  if(s<f) {
    		s++;
    		ans.append('R');
    	  }
    	  else {
    	    s--;
    	    ans.append('L');
    	  }
       }
       step++;
     }
  System.out.println(ans);
 
 }catch(Exception e) {return;}

 }
 
}


//https://www.codechef.com/MP3TO401?order=desc&sortBy=successful_submissions
   





























































































































































