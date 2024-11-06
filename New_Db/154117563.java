import java.util.Scanner;
public class Gcd {
	public static long res=0;
	public static long great(long a, long b) {
		if(a<b) {
			long temp=a;
			a=b;
			b=temp;
		}
		while(b!=0) {
			long temp=a;
			a=b;
			b=temp%b;
		}
		return a;
	}
	public static void add(int n, int i) {
		while(n>0) {
			res+=n%i;
			n=n/i;
		}
	}
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=2;i<=n-1;i++) {
			add(n,i);
		}
		long r=great(res,(n-2));
		System.out.printf("%d/%d\n", res/r,(n-2)/r);
	}
}
