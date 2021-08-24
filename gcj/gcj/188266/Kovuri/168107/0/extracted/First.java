package Round1;

import java.io.*;
import java.util.Vector;


public class First {

    File file = new File("F:\\Srikanth\\input.txt");
    FileInputStream fis = null;
    BufferedInputStream bis = null;
    DataInputStream dis = null;
    int T=0;
   
    public First() {
    
    }

    public void open_files() {
        try {
            fis = new FileInputStream(file);
            bis = new BufferedInputStream(fis);
            dis = new DataInputStream(bis);
        } catch (FileNotFoundException x) {
            x.printStackTrace();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    public void close_files() throws IOException {
        fis.close();
        bis.close();
        dis.close();
    }

    public void read_language() throws IOException {
        String line;
        String[] line_split;
        line = dis.readLine();

       T = Integer.parseInt(line);
       System.out.println("T = " + T);

    }

    private int check_square(int current_number, int current_base) {
       String in_curren_base = Integer.toString(current_number, current_base);
       int i,t;
       int square = 0;
       for(i = 0 ; i < in_curren_base.length(); i++)
       {
           char c = in_curren_base.charAt(i);
           t = Integer.parseInt("" + c);
           square += (t*t);
       }
       return square;
    }

    private boolean is_already_present(int new_number, Vector<Integer> nos_generated) {
        int i;
        for(i = 0; i < nos_generated.size();i++)
        {
            if( (new_number) == nos_generated.elementAt(i) )
                    return true;
        }
        return false;
    }

  private boolean is_happy(int current_number,int current_base,Vector<Integer> nos_generated)
  {
      int new_number;
      if((new_number = check_square(current_number,current_base)) ==1)
      {
          return true;
      }
      else
      {
          if(is_already_present(new_number,nos_generated))
              return false;
          nos_generated.add(new_number);
          return(is_happy(new_number, current_base, nos_generated));
      }
  }

    private void action() throws IOException {
        
        int itr = 0;
        String testcase;
        String[] str_bases;
        int[] bases;
        Vector<Integer> nos_generated ;
        for(itr = 0; itr < T ; itr++){
            testcase = dis.readLine();
            str_bases = testcase.split(" ");
            bases = new  int[str_bases.length];
            int itr2 = 0;
            for(itr2 = 0; itr2 < str_bases.length;itr2++){
                bases[itr2] = Integer.parseInt(str_bases[itr2]);
            }
            
            
            
            int current_number = 2,current_base;
            for(itr2 = bases.length -1 ; itr2 >= 0;itr2--){
                current_base = bases[itr2];
                nos_generated = new Vector<Integer>();
                if(is_happy(current_number,current_base,nos_generated))
                {
                    continue;
                }
                else{
                    itr2 = bases.length;
                    current_number++;
                }
                    
            }
            System.out.println("Case #" + (itr+1) + ": " + current_number);
           
        }
     
    }

    public static void main(String[] args) throws IOException {
        
        First f = new First();

        f.open_files();
        f.read_language();
        f.action();
        f.close_files();

    }
}