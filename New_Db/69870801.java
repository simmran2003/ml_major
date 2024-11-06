import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LetterA {
    static class Point{
        long x,y;
        Point(long x, long y){
            this.x=x;
            this.y=y;
        }
    }
    static class Segment{
        long x1,y1,x2,y2;
        Point p1,p2;
        Segment(String sr){
            StringTokenizer st= new StringTokenizer(sr);
            this.x1=Integer.parseInt(st.nextToken());
            this.y1=Integer.parseInt(st.nextToken());
            this.x2=Integer.parseInt(st.nextToken());
            this.y2=Integer.parseInt(st.nextToken());
            this.p1= new Point(x1,y1);
            this.p2=new Point(x2,y2);
        }
    }
    static boolean acute(Point p1, Point p2, Point p3){
        long area=(long)(p1.x-p3.x)*(p2.y-p3.y)-(long)(p1.y-p3.y)*(p2.x-p3.x);
        long a=(long)(p1.x-p3.x)*(p1.x-p3.x)+(long) (p1.y-p3.y)*(p1.y-p3.y) ;
        long b=(long)(p2.x-p3.x)*(p2.x-p3.x)+(long) (p2.y-p3.y)*(p2.y-p3.y);
        long c=(long)(p2.x-p1.x)*(p2.x-p1.x)+(long) (p2.y-p1.y)*(p2.y-p1.y);
        return area!=0 && c<=a+b;
    }
    static boolean verticalSegment(Segment a, Segment b){
        if(a.p1.x==b.p1.x && a.p1.y==b.p1.y){
            return acute(a.p2,b.p2,a.p1);
        }
        if(a.p2.x==b.p2.x && a.p2.y==b.p2.y){
            return acute(a.p1,b.p1,a.p2);
        }
        if(a.p1.x==b.p2.x && a.p1.y==b.p2.y){
            return acute(a.p2,b.p1,a.p1);
        }
        if(a.p2.x==b.p1.x && a.p2.y==b.p1.y){
            return acute(a.p1,b.p2,a.p2);
        }
        return false;
    }
    static boolean intersecting(Segment s,Point p){
        if(p.x<Math.min(s.p1.x,s.p2.x) || p.x>Math.max(s.p1.x,s.p2.x) ||
                p.y<Math.min(s.p1.y,s.p2.y)|| p.y>Math.max(s.p1.y,s.p2.y))
            return false;
        int x=(int) Math.abs(s.p1.x-s.p2.x);
        int y= (int) Math.abs(s.p1.y-s.p2.y);
        int xm= (int) Math.min(Math.abs(s.p1.x-p.x),Math.abs(s.p2.x-p.x));
        int ym= (int) Math.min(Math.abs(s.p1.y-p.y),Math.abs(s.p2.y-p.y));
        return x<=5*xm && y<=5*ym &&
                (long)(p.x-s.p2.x)*(s.p1.y-s.p2.y)==(long)(p.y-s.p2.y)*(s.p1.x-s.p2.x);
    }

    static boolean check(Segment a, Segment b, Segment c){
        return verticalSegment(a,b) && (intersecting(a,c.p1) && intersecting(b,c.p2)
                || intersecting(b,c.p1) && intersecting(a,c.p2));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        int n= Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++) {
            Segment a=new Segment(br.readLine());
            Segment b= new Segment(br.readLine());
            Segment c= new Segment(br.readLine());
            System.out.println(check(a,b,c)||check(b,c,a)||check(c,a,b)?"YES":"NO");
        }

    }
}