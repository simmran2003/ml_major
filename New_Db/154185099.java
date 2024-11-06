import java.util.Scanner;

public class Numbers {

	public static void main(String[] args) {
		
		short a;
		short a_clone;
		int i_sumDigits;
		int i_GCD;
		Scanner sc;
		
		sc = new Scanner(System.in);
		a = sc.nextShort();
		sc.close();
		
		i_sumDigits = 0;
		for(int i = 2; i < a; i++) {
			a_clone = a;
			while(a_clone != 0) {
				a_clone /= (short) Math.pow(i, NumOfDivisorA(a_clone, i));
				i_sumDigits += a_clone % i;
				a_clone /= i;
			}
		}
		
		i_GCD = GCD(i_sumDigits, a - 2);
		System.out.print((i_sumDigits / i_GCD) + "/" + ((a - 2) / i_GCD));
	}

	static double logaN(int a, int n) {
		return Math.log(n) / Math.log(a);
	}
	
	static int NumOfDivisorA(int n, int a) {
		int i = (int) Math.ceil(logaN(a, n));
		while(n % Math.pow(a, i) != 0) {
			i--;
		}
		
		return i;
	}
	
	static int GCD(int a, int b) {
		while(a != b) {
			if(a > b) {
				a -= b;
			}
			else {
				b -= a;
			}
		}
		
		return a;
	}
}
