import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;

public class XeniaAndSpies {


    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr=new PrintWriter(System.out);
        solve(br,pr);
        pr.flush();
        pr.close();
    }


    public static void solve(BufferedReader br,PrintWriter pr) throws IOException{
        String[] temp=br.readLine().split(" ");
        int n=Integer.parseInt(temp[0]);
        int m=Integer.parseInt(temp[1]);
        int s=Integer.parseInt(temp[2]);
        int f=Integer.parseInt(temp[3]);
        Map<Integer,int[]> map=new HashMap<>();
        for(int i=0;i<m;i++){
            temp=br.readLine().split(" ");
            int t=Integer.parseInt(temp[0]);
            int l=Integer.parseInt(temp[1]);
            int r=Integer.parseInt(temp[2]);
            map.put(t,new int[]{l,r});
        }
        int step=1;
        int currentPos=s;
        StringBuffer res=new StringBuffer();
        while(currentPos!=f){
            if(map.containsKey(step)==false){
                res.append(f>currentPos?'R':'L');
                currentPos+=f>currentPos?1:-1;
            }
            else if(map.containsKey(step)){
                int[] watch=map.get(step);
                if(currentPos<watch[0]||currentPos>watch[1]){
                    int next=f>currentPos?currentPos+1:currentPos-1;
                    if(next<watch[0]||next>watch[1]){
                        res.append(f>currentPos?'R':'L');
                        currentPos+=f>currentPos?1:-1;
                    }
                    else{
                        res.append('X');
                    }
                }
                else{
                    res.append('X');
                }
            }
            step++;
        }
        pr.println(res);
    }
}
