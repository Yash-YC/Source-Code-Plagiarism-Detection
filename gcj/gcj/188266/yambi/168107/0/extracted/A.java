import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
    public static void main(String[] args) {
        new A().run();
    }
    void run() {
        Scanner sc = new Scanner(System.in);
        boolean[][] isHappy = new boolean[11][1000000];
        for(int base = 2;base<=10;++base){
            isHappy[base][1]=true;
            for(int i=1;i<1000000;i++){
                TreeSet<Integer> set = new TreeSet<Integer>();
                set.add(i);
                int num = next(i,base);
                while(true){
                    if(set.contains(num))break;
                    if(isHappy[base][num]){
                        isHappy[base][i]=true;
                    }
                    set.add(num);
                    num = next(num,base);
                }
            }
        }
        
        int N = sc.nextInt();sc.nextLine();
        for(int cases=1;cases<=N;++cases){
            int num = 0;
            String[] line = sc.nextLine().split(" ");
            int result;
            for(result=2;;result++){
                boolean flag = true;
                for(String s : line)if(!isHappy[Integer.parseInt(s)][result])flag=false;
                if(flag)break;
            }
            System.out.println("Case #"+cases+": "+result);
        }
    }
    int next(int num, int base){
        int tmp = 0;
        while(num>0){
            tmp+=(num%base)*(num%base);
            num/=base;
        }
        return tmp;
    }
}

