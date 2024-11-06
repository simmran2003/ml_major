import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int sum=0;
        for(int i=2;i<a;i++){
            int t=a;
            while(t>0){
                sum+=(t%i);
                t/=i;
            }
        }
        int g=gcd(sum,a-2);
        sum=sum/g;a=(a-2)/g;
        System.out.println(sum+"/"+a);
    }
    
    public static int gcd(int a,int b){
        if(b==0){
            return a;
        }
        else return gcd(b,a%b);
    }
}