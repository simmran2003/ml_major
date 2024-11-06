import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
 
public class AnotA {
 
	long x1,x2;
	long y1,y2;
	
	AnotA(String s){
		StringTokenizer st = new StringTokenizer(s);
		this.x1 =Integer.parseInt(st.nextToken());
		this.y1 =Integer.parseInt(st.nextToken());
		this.x2 =Integer.parseInt(st.nextToken());
		this.y2 =Integer.parseInt(st.nextToken());
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		for(int i=0; i<n; i++) {
			AnotA a = new AnotA(br.readLine());
			AnotA b = new AnotA(br.readLine());
			AnotA c = new AnotA(br.readLine());
			System.out.println(checkConstraints(a,b,c)||checkConstraints(b,c,a)||checkConstraints(c,a,b)?"YES":"NO");
		}
	}
	
	private static boolean checkIntersection(long x, long y, AnotA a) {
		//check if the point is lying outside the segment
		if(x<Math.min(a.x1, a.x2)||x>Math.max(a.x1, a.x2)||y<Math.min(a.y1, a.y2)||y>Math.max(a.y1, a.y2))
			return false;
		//check ratio between parts
		int xpart = (int) Math.abs(a.x1-a.x2);
		int ypart = (int) Math.abs(a.y1-a.y2);
		int xmin = (int) Math.min(Math.abs(a.x1-x), Math.abs(a.x2-x));
		int ymin = (int) Math.min(Math.abs(a.y1-y), Math.abs(a.y2-y));
		
		return xpart<=5*xmin&&ypart<=5*ymin&& (long) (x-a.x2)*(a.y1-a.y2)==(long)(y-a.y2)*(a.x1-a.x2);
	}
	public static boolean checkConstraints(AnotA a, AnotA b, AnotA c) {
		if(a.x1==b.x1&&a.y1==b.y1) {
			return getAngle(a.x2,a.y2,b.x2,b.y2,a.x1,a.y1)&&(
					checkIntersection(c.x1, c.y1,a)&&checkIntersection(c.x2, c.y2,b)||
					checkIntersection(c.x2, c.y2,a)&&checkIntersection(c.x1, c.y1,b));
		}
		if(a.x2==b.x1&&a.y2==b.y1) {
			return getAngle(a.x1, a.y1, b.x2, b.y2, a.x2, a.y2)&&(
					checkIntersection(c.x1, c.y1,a)&&checkIntersection(c.x2, c.y2,b)||
					checkIntersection(c.x2, c.y2,a)&&checkIntersection(c.x1, c.y1,b));
		}
		if(a.x1==b.x2&&a.y1==b.y2) {
			return getAngle(a.x2, a.y2, b.x1, b.y1, a.x1, a.y1)&&(
					checkIntersection(c.x1, c.y1,a)&&checkIntersection(c.x2, c.y2,b)||
					checkIntersection(c.x2, c.y2,a)&&checkIntersection(c.x1, c.y1,b));
		}
		if(a.x2==b.x2&&a.y2==b.y2) {
			return getAngle(a.x1, a.y1, b.x1, b.y1, a.x2, a.y2)&&(
					checkIntersection(c.x1, c.y1,a)&&checkIntersection(c.x2, c.y2,b)||
					checkIntersection(c.x2, c.y2,a)&&checkIntersection(c.x1, c.y1,b));
		}
		return false;
		
	}
	
	public static boolean getAngle(long x1, long y1, long x2, long y2, long x3, long y3) {
		boolean collinear =areCollinear( x1,  y1,  x2,  y2,  x3,  y3);
		//check angle <= 90
		long a13 = (long) (x1-x3) * (x1-x3) + (long) (y1-y3) *(y1-y3); 
		long a23 = (long) (x2-x3) * (x2-x3) + (long) (y2-y3) *(y2-y3);
		long a12 = (long) (x1-x2) * (x1-x2) + (long) (y1-y2) *(y1-y2); 
		return !collinear&&a13+a23>=a12;
	}
	
	private static boolean areCollinear(long x1, long y1, long x2, long y2, long x3, long y3) {
		long area = (long) (x1-x3)*(y2-y3) - (long) (x2-x3)*(y1-y3);
		return area==0?true:false;
		
	}
	
	public static long dotProduct(long x1, long y1, long x2, long y2)
	{
	 return x1*x2+y1*y2;
	}
}