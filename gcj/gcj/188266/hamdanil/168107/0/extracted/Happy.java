import java.util.*;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;
public class Happy {


    public static void main(String[] args) {
        Scanner sc = null;
        PrintWriter out =null;

        try {
             sc = new Scanner(new File("A-small-attempt0.in"));
              out = new PrintWriter(new BufferedWriter(new FileWriter("A-small.out")));

        } catch (IOException ex) {
            Logger.getLogger(AlienLanguage.class.getName()).log(Level.SEVERE, null, ex);
        }
        int cas=sc.nextInt();
        sc.nextLine();
        for (int zz = 0; zz < cas; zz++) {
            String s=sc.nextLine();
            int ans=0;
            StringTokenizer st=new StringTokenizer(s);
            int[] b=new int[st.countTokens()];
            for (int i = 0; st.hasMoreTokens(); i++) {
                b[i]=Integer.parseInt(st.nextToken());
            }
            for (int i = 2; 1<2 ; i++) {
                int c=0;
                for (int j = 0; j < b.length; j++) {
                    if(happy(i,b[j])) c++;
                }
                if(c==b.length) { ans=i; break; }
            }
            out.println("Case #"+ (zz+1) +": "+ans);
        }
        out.close();
    }

    private static boolean happy(int i, int bs) {
        Vector<String> v = new Vector<String>();
        String st=Integer.toString(i,bs);
        while(true){
            if(v.contains(st)) return false;
            v.add(st);
            int tot=0;
            for (int j = 0; j < st.length(); j++) {

                int cs=Integer.parseInt(""+st.charAt(j),bs);
                tot+=cs*cs;
            }
            st=Integer.toString(tot, bs);
            if(st.equals("1")) return true;

        }
    }

}
