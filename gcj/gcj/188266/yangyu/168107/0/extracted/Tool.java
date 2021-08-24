
import java.util.Vector;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Administrator
 */
public class Tool {

    public static Integer[] toInt(String str[]){
        Integer[] intarr=new Integer[str.length];
        for (int i = 0; i < str.length; i++) {
            intarr[i]=Integer.parseInt(str[i]);
        }
        return intarr;
    }
    public static Vector<Integer> toVec(Integer str[]){
        Vector<Integer> vec=new Vector<Integer>();
        for (int i = 0; i < str.length; i++) {
            vec.add(str[i]);
        }
        return vec;
    }
}
