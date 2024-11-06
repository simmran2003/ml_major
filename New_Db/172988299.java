import java.util.HashMap;
import java.util.*;

public class MyPractise1 {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        HashMap<Integer,Integer>hm=new HashMap<>();
        for(int i=0;i<n;i++) {
            arr[i] = sc.nextInt();
            hm.put(arr[i],hm.getOrDefault(arr[i],0)+1);
        }
        int one=0,two=0,three=0,four=0,six=0;
        if(hm.containsKey(1))
            one=hm.get(1);
        if(hm.containsKey(2))
            two=hm.get(2);
        if(hm.containsKey(3))
            three=hm.get(3);
        if(hm.containsKey(4))
            four=hm.get(4);
        if(hm.containsKey(6))
            six=hm.get(6);
        int sum=0;
        int min=(Math.min(one,Math.min(two,four)));
        one-=min;two-=min;four-=min;
        sum+=min;
        StringBuilder str=new StringBuilder();
        for(int i=0;i<min;i++) {
            str.append("1 2 4 ");
            str.append("\n");
        }
        min=(Math.min(one,Math.min(two,six)));
        one-=min;two-=min;six-=min;
        sum+=min;
        for(int i=0;i<min;i++) {
            str.append("1 2 6");
            str.append("\n");
        }
        min=(Math.min(one,Math.min(three,six)));
        one-=min;three-=min;six-=min;
        sum+=min;
        for(int i=0;i<min;i++) {
            str.append("1 3 6");
            str.append("\n");
        }
        if(sum<n/3)
            System.out.println(-1);
        else
            System.out.println(str);


    }
}