
import java.io.*;
import java.util.Scanner;
public class Main {
  public static void main(String[] args) throws IOException {
      BufferedReader br = null ;
      BufferedWriter bw= null;
      
      try {
          br = new   BufferedReader(   new FileReader ("in.in"));
      } catch (FileNotFoundException ex) {
        //  Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
      }
      
      try {
          bw= new BufferedWriter(new FileWriter("out.txt"));
      } catch (IOException ex) {
        //  Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
      }
      
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    
    
    
    int t = 0;
      try {
          t = Integer.parseInt(br.readLine() );
      } catch (IOException ex) {
        //  Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
      }
      
      
    unix_dir ud = new unix_dir();
    

    for (int i = 1; i <= t; i++) {
        
        String s= br.readLine();
        
        char arr[];
          
         
          try {
              
              System.out.println("Case #" + i + ": "+ud.MainEx(s.toCharArray())); 
             bw.write("Case #" + i + ": "+ud.MainEx(s.toCharArray()));
              bw.newLine();
              
           //   System.out.println("Case #" + i + ": "+l.setLine(br.readLine()) ); 
          } catch (IOException ex) {
            
          }
        
    }
    
    
      try {
          bw.close();
          br.close();
      } catch (IOException ex) {
          
      }
  }
  
      
}
