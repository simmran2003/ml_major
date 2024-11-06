import com.sun.security.jgss.GSSUtil;

import java.math.BigInteger;
import java.util.*;
   public class Snuke {
        static Scanner scan = new Scanner(System.in);
        static ArrayList<String> ar=new ArrayList<>();
        public static void main(String[] args) {

            int N=1;
//            N=scan.nextLong();
            while(N-->0){
                solve();
            }
        }
        public static void solve(){
            int N=scan.nextInt();
            int arr[]=new int[7];
            int val=0;
            for(int i=0;i<N;i++){
                    val= scan.nextInt();
                    if(val==5 || val==7){
                        System.out.println(-1);
                        return;
                    }
                    arr[val-1]++;
            }
//            printArr(arr);
            int count=Math.min(arr[0],Math.min(arr[2],arr[5]));

                // 1 3 6
                arr[0]-=count;     arr[2]-=count;     arr[5]-=count;

            int count2=Math.min(arr[0],Math.min(arr[1],arr[3]));

            // 1 2 4
            arr[0]-=count2;     arr[1]-=count2;     arr[3]-=count2;
            int count3=Math.min(arr[0],Math.min(arr[1],arr[5]));

            // 1 2 6
            arr[0]-=count3;     arr[1]-=count3;     arr[5]-=count3;

            for(int i=0;i<7;i++){
                if(arr[i]>0 ){
                    System.out.println(-1);
                    return;
                }
            }

            for(int i=0;i<count;i++){
                System.out.println("1 3 6");
            }
            for(int i=0;i<count2;i++){
                System.out.println("1 2 4");
            }
            for(int i=0;i<count3;i++){
                System.out.println("1 2 6");
            }

        }


       public static int maxRow(int arr[][],int index,int no){
        int max=0;
        int maxJ=0;
                for(int i=0;i<5;i++){
                    if(no!=i){
                        if(arr[index][i]+arr[i][index]>max){
                            max=arr[index][i]+arr[i][index];
//                            maxI=index;
                            maxJ=i;
                        }
                    }
                }
return maxJ;
    } public static int maxRow(int arr[][],int index,int no,int no2){
           int max=0;
           int maxJ=0;
           for(int i=0;i<5;i++){
               if(no==i || no2==i){
                    continue;
               }
                   if(arr[index][i]+arr[i][index]>max){
                       max=arr[index][i]+arr[i][index];
//                            maxI=index;
                       maxJ=i;
                   }

           }
           return maxJ;
       }
        /*
        19 -172106364 -468680119 -172106365 -468680119
SSEEESSSESESWSEESSS

         * */
        public static void printHt(Hashtable ht){
            Set<Character> setOfKeys = ht.keySet();

            // Iterating through the Hashtable
            // object using for-Each loop
            for (Character key : setOfKeys) {
                // Print and display the Rank and Name
                System.out.println("Key: " + key
                        + "\tName: "
                        + ht.get(key));
            }
        }
       public static int nextNum(int arr[],int from,int num) {
                    for(int i=from;i<arr.length;i++){
                        if(arr[i]==num){
                            return i;
                        }
                    }
                    return -1;
       }
        public static   void  printArr(int arr[]){
                for(int i=0;i<arr.length;i++){
                    System.out.print(arr[i]+" ");
                }
        }
       public static   void  printMulArr(char arr[][]){
           for(int i=0;i<arr.length;i++){
               for(int j=0;j<arr[i].length;j++){
                   System.out.print(arr[i][j]);

               }
               System.out.println();
           }
       }
        public static  int[] reverseArr(int arr[]){
            for(int i=0,j=arr.length-1;i<j;i++,j--){
                int temp=arr[i];arr[i]=arr[j];arr[j]=temp;}
            return  arr; }

        public static boolean checkArr(int arr[]){
            for(int i=0;i<arr.length;i++){
                if(arr[i]!=0){return true;}}
            return false;}

    }











    //TODo CODECHEF
//    int N=scan.nextLong();
//        int X=scan.nextLong();
//    if(N<24){
//            System.out.println((int)Math.pow(2,N-1)*X);
//            return;
//            }
//            int i=1;
//            int ans=1;
//            while(i<=N-1){
//
//            if(ans*4>1000000007){
////                if((ans*2)%1000000007==0){
////                    System.out.println(i);
////                }
//            ans=(ans*4)%1000000007;
//            }else{
//            ans=ans*4;
//            }
//
//            i+=2;
//
//            }
//            System.out.println((ans*X)%1000000007);

/*
*  int mt[]=new int[M];
            int tempMt[]=new int[M];
         for(int i=0;i<M;i++){tempMt[i]=mt[i]= scan.nextLong();}

         int miAns=0;
         Arrays.sort(mt);
         int i=0;
         int tempN=N;

         while(i<mt.length && N!=0){
             miAns+=mt[i];
             mt[i]--;
             N--;
             if(mt[i]==0){
                 i++;
             }
         }

            Arrays.sort(tempMt);
         tempMt=reverseArr(tempMt);

         int maxAns=0;
         i=0;
            while( tempN!=0){
                maxAns+=tempMt[i];
                tempMt[i]--;
                tempN--;
                if(tempMt[i]===)
//                if(tempMt[i]==0){
                    i=(i+1)%(tempMt.length-1);
//                }
            }

            System.out.println(maxAns+" "+miAns);
* */