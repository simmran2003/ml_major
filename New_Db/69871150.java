import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

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
    static long cross(long x1, long y1, long x2, long y2) {
        return x1*y2-x2*y1;
    }
    static long length(long x, long y){
        return x*x+y*y;
    }
    static boolean acute(Point l, Point m, Point n){
        long area= cross(l.x-n.x,l.y-n.y,m.x-n.x,m.y-n.y);
        long a=length(l.x-n.x,l.y-n.y);
        long b=length(m.x-n.x,m.y-n.y);
        long c=length(m.x-l.x,m.y-l.y);
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
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        int n= Integer.parseInt(br.readLine());
        Segment[][] segments= new Segment[n][3];
        for(int i=0;i<n;i++) {
            for(int j=0; j<3;j++){
                StringTokenizer st= new StringTokenizer(br.readLine());
                int x1 = Integer.parseInt(st.nextToken());
                int y1 = Integer.parseInt(st.nextToken());
                int x2 = Integer.parseInt(st.nextToken());
                int y2 = Integer.parseInt(st.nextToken());
                segments[i][j]= new Segment(new Point(x1,y1),new Point(x2,y2));
            }
            System.out.println(check(segments[i][0],segments[i][1],segments[i][2])
                    ||check(segments[i][1],segments[i][2],segments[i][0])
                    ||check(segments[i][2],segments[i][0],segments[i][1])?"YES":"NO");
        }

    }
}
