
import java.util.*;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class HappyLarge {

    public static void main(String[] args) {
        Scanner sc = null, sc2=null;
        PrintWriter out = null;

        try {
            sc = new Scanner(new File("A-large.in"));
            sc2 = new Scanner(new File("Awaa.out"));
            out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));

        } catch (IOException ex) {
            Logger.getLogger(AlienLanguage.class.getName()).log(Level.SEVERE, null, ex);
        }
        //generate(); used to generate hashmap
        HashMap<String,Integer> h = new HashMap<String,Integer>();
        Vector<String> v = new Vector<String>();
        while(sc2.hasNext()){
            String st=sc2.next();
            int eger = sc2.nextInt();
            if(!h.containsKey(st)) {
                h.put(st, eger);
                v.add(st);
            }       
        }
        int cas = sc.nextInt();
        sc.nextLine();
        for (int zz = 0; zz < cas; zz++) {
            String s = sc.nextLine();
            int ans = 0;
            StringTokenizer st = new StringTokenizer(s);
            int[] b = new int[st.countTokens()];
            for (int i = 0; st.hasMoreTokens(); i++) {
                b[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 0; i < v.size(); i++) {
                int ct=0; String stt=v.get(i);
                for (int j = 0; j < b.length; j++) {
                    int e=(b[j]-2);
                    char c = (char)((int)'0' + e);
                    if(stt.contains(""+c)) ct++;

                }
                if(ct==b.length) { ans=h.get(stt); break;}
                
            }
            out.println("Case #" + (zz + 1) + ": " + ans);
        }
        out.close();
    }

    private static boolean happy(int i, int bs) {
        Vector<String> v = new Vector<String>();
        String st = Integer.toString(i, bs);
        while (true) {
            if (v.contains(st)) {
                return false;
            }
            v.add(st);
            int tot = 0;
            for (int j = 0; j < st.length(); j++) {

                int cs = Integer.parseInt("" + st.charAt(j), bs);
                tot += cs * cs;
            }
            st = Integer.toString(tot, bs);
            if (st.equals("1")) {
                return true;
            }

        }
    }

    private static int generate() {
        HashMap<String,Integer> h = new HashMap<String,Integer>();
        PrintWriter out = null;
        try {
            out = new PrintWriter(new BufferedWriter(new FileWriter("Awaa.out")));
        } catch (IOException ex) {
            Logger.getLogger(AlienLanguage.class.getName()).log(Level.SEVERE, null, ex);
        }
        int ans = 0;
        int[] b = new int[]{2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < b.length; i++) {
        }
        for (int i = 2; 1 < 2; i++) {
            if (i % 100000 == 0) {
                System.out.print(i + " "+ h.size());
                System.out.println("");
            }

            int c = 0;
            String s="";
            for (int j = 0; j < b.length; j++) {
                if (happy(i, b[j])) {
                    c++;
                    s+=""+j;
                }
            }
            if(!h.containsKey(s)){
                h.put(s,i);
                out.println(s+" "+i);
                out.flush();
            }
            if (c == b.length) {
                ans = i;
                break;
            }
        }
        Set<String> s=h.keySet();
        Object[] ar=s.toArray();
        for (int i = 0; i < h.size(); i++) {
            System.out.println(ar.toString());
        }
        return ans;

    }
}
