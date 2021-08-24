/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejam;

/**
 *
 * @author Ishani
 */
import java.util.*;
public class MultiBase {

    public static boolean isLucky(String s , int b){
        long sum = 0;int k = 0;
        String ss= s;
        while(k<2000){
            sum = 0;
            for(char ch:ss.toCharArray()){
                sum +=( (ch-'0')*(ch-'0'));

            }
            if(sum==1)return true;
            ss = Long.toString(sum, b);
            k++;

        }
        return false;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = Integer.parseInt(sc.nextLine());

        int tt = 0;
         while(T-- > 0){
            tt++;
            String take = sc.nextLine();
            take = take.trim();
             
            int[] bases = isplit(take);
            int k = 1;
            loop:while(true){
                k++;
                for(int b=0;b<bases.length;b++){
                    String ks = Integer.toString(k, bases[b]);
                    if(!isLucky(ks,bases[b])) continue loop;
                }
                System.out.println("Case #"+(tt)+": "+k);
                break;
            }


        }
    }

    final static int[] isplit(String s){
        String[] sa = s.trim().split("\\s+");
     
        int n = sa.length;
        int[] ar = new int[n];
        for(int i=0;i<n;i++) ar[i]=ival(sa[i]);
        return ar;
    }
     final static int ival(String o) { return Integer.parseInt(o);  }
   

    final static void print(Object... ob) {
        System.out.println(Arrays.deepToString(ob));
    }

}
