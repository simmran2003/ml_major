import java.io.IOException;
import java.util.Scanner;

public class LetterA {
    static class Point{
        int x,y;
        Point(int x, int y){
            this.x=x;
            this.y=y;
        }
    }
    static class Segment{
        Point p1,p2;
        Segment(Point p1, Point p2){
            this.p1=p1;
            this.p2=p2;
        }
    }
    static boolean acute(Point l, Point m, Point n){
        long area=(long)(l.x-n.x)*(m.y-n.y)-(long)(l.y-n.y)*(m.x-n.x);
        long a=(long)(l.x-n.x)*(l.x-n.x)+(long) (l.y-n.y)*(l.y-n.y);
        long b=(long)(m.x-n.x)*(m.x-n.x)+(long) (m.y-n.y)*(m.y-n.y);
        long c=(long)(m.x-l.x)*(m.x-l.x)+(long) (m.y-l.y)*(m.y-l.y);
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
        int x=Math.abs(s.p1.x-s.p2.x);
        int y=Math.abs(s.p1.y-s.p2.y);
        int xm=Math.min(Math.abs(s.p1.x-p.x),Math.abs(s.p2.x-p.x));
        int ym=Math.min(Math.abs(s.p1.y-p.y),Math.abs(s.p2.y-p.y));
        return x<=5*xm && y<=5*ym &&
                (long)(p.x-s.p2.x)*(s.p1.y-s.p2.y)==(long)(p.y-s.p2.y)*(s.p1.x-s.p2.x);
    }

    static boolean check(Segment a, Segment b, Segment c){
        return verticalSegment(a,b)&& (intersecting(a,c.p1)&&intersecting(b,c.p2)
                || intersecting(b,c.p1)&&intersecting(a,c.p2));
    }

    public static void main(String[] args) throws IOException {
        Scanner cin= new Scanner(System.in);
        int n= cin.nextInt();
        Segment[][] segments= new Segment[n][3];
        for(int i=0;i<n;i++) {
            for(int j=0; j<3;j++){
                int x1 = cin.nextInt();
                int y1 = cin.nextInt();
                int x2 = cin.nextInt();
                int y2 = cin.nextInt();
                segments[i][j]= new Segment(new Point(x1,y1),new Point(x2,y2));
            }
            System.out.println(check(segments[i][0],segments[i][1],segments[i][2])
                    ||check(segments[i][1],segments[i][2],segments[i][0])
                    ||check(segments[i][2],segments[i][0],segments[i][1])?"YES":"NO");
        }

    }
}
