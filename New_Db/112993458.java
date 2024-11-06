import java.util.*;


public class Books {
        
	public static void main(String[] args) {
           
		Scanner sc=new Scanner(System.in);
                int n=sc.nextInt();
                int m=sc.nextInt();
                int s=sc.nextInt();
                int f=sc.nextInt();
               
                int arr[][]=new int[m][3];
                for(int i=0;i<m;i++){
                    for(int j=0;j<3;j++){
                        arr[i][j]=sc.nextInt();
                    }
                }
                char move;
                int inc=0;
                int c=0;
                int step=1;
                if(f>s){
                    move='R';
                    inc=1;
                }
                else{
                    move='L';
                    inc=-1;
                }
                StringBuilder str=new StringBuilder();
                while(s!=f){
                    if(c<m && step==arr[c][0]){
                        if(s>=arr[c][1]&&s<=arr[c][2])
                             str.append('X');
                        else if(s+inc>=arr[c][1] && s+inc<=arr[c][2]){
                            str.append("X");
                        }
                        else{
                            str.append(move);
                            s+=inc;
                        }
                        c++;
                    }
                    else{
                       str.append(move);
                       s+=inc;
                    }
                    step++;
                }
                System.out.print(str);
}
       
}