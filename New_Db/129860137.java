import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
    static class Triplet{
        int t;
        int l;
        int r;
        public Triplet(int t,int l,int r){
            this.t=t;
            this.l=l;
            this.r=r;
        }
    }
    public static boolean surveilled(int s,Triplet t){
        return s>=t.l && s<=t.r;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		int n=Integer.parseInt(st.nextToken());
		int m=Integer.parseInt(st.nextToken());
		int s=Integer.parseInt(st.nextToken());
		int f=Integer.parseInt(st.nextToken());
		ArrayList<Triplet>a=new ArrayList<>();
		HashMap<Integer,Triplet>h=new HashMap<>();
		for(int i=0;i<m;i++){
		    st=new StringTokenizer(br.readLine());
		    int ti=Integer.parseInt(st.nextToken());
		    int li=Integer.parseInt(st.nextToken());
		    int ri=Integer.parseInt(st.nextToken());
		    a.add(new Triplet(ti,li,ri));
		    h.put(ti,new Triplet(ti,li,ri));
		}
		if(s<f){
		    for(int i=1;i<=a.get(m-1).t && s!=f;i++){
		        if(h.containsKey(i)){
		            if(surveilled(s,h.get(i)) || surveilled(s+1,h.get(i))){
		                System.out.print('X');
		            }
		            else{
		                System.out.print('R');
		                s++;
		            }
		        }
		        else{
		            System.out.print('R');
		            s++;
		        }
		    }
		    while(s!=f){
		        System.out.print('R');
		        s++;
		    }
		}
		else{
		    for(int i=1;i<=a.get(m-1).t && s!=f;i++){
		        if(h.containsKey(i)){
		            if(surveilled(s,h.get(i)) || surveilled(s-1,h.get(i))){
		                System.out.print('X');
		            }
		            else{
		                System.out.print('L');
		                s--;
		            }
		        }
		        else{
		            System.out.print('L');
		            s--;
		        }
		    }
		    while(s!=f){
		        System.out.print('L');
		        s--;
		    }
		}
	}
}
