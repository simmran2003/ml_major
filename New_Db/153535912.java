import java.util.Scanner;
public class CF_13A {
	static int a,sum;
	public static int gcd(int x, int y) 
	{
		int max = 0;
		int r = 0;
		if (x == y) 
		{
			return x;
		}
		if (x < y) 
		{
			x = r;
			x = y;
			y = r;
		}
		while (true) 
		{
			max = x%y;
			x = y;
			y = max;
			if (max == 0) 
			{
				return x;
			}
		}
	}
	public static void add(int x, int y) 
	{
		while (x>0) 
		{
			sum += x%y;
			x = x/y;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		sum = 0;
		for (int i = 2; i<a; i++) 
		{
			add(a,i);
		}
		int g = gcd(sum,(a-2));
		System.out.print((sum/g)+"/"+((a-2)/g));
	}
}