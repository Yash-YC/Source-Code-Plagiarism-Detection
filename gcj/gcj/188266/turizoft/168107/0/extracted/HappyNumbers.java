/**
 * @(#)HappyNumbers.java
 *
 *
 * @author 
 * @version 1.00 2009/9/11
 */
 
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.util.ArrayList;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;


public class HappyNumbers {

	File source;
	public ArrayList<String> words = new ArrayList<String>();
	public ArrayList<String> cases = new ArrayList<String>();
	int n;

    public HappyNumbers() {
    	
    	source = LoadFile();
    	ReadFile();
    	WriteFile();
    	    	    	    	    	
    }
    
    public File LoadFile(){

    	JFileChooser Picker = new JFileChooser();
    	Picker.setFileSelectionMode(JFileChooser.FILES_ONLY);
       	File temp = null;

        if (Picker.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {

    	 	temp = Picker.getSelectedFile();

    	}

    	return temp;

    }
    
    public void WriteFile() {
    	
    	try {

            File dest = new File("output.txt");
            Writer output = new BufferedWriter(new FileWriter(dest));
            
            for (int i = 0; i < n; i++) {
    		
    			output.write(TestCase(cases.get(i), i) + "\n");
    			
    		}
            
            output.close();

        } catch (Exception ex) {ex.printStackTrace();}
    	
    }
    
    public void ReadFile() {
    	
    	try {

            BufferedReader Input = new BufferedReader(new FileReader(source));
            String s = Input.readLine();
			
			n = Integer.parseInt(s);
			System.out.println(n);
			for (int i = 0; i < n; i++) {
				
				s = Input.readLine();
				cases.add(s);
				
			}
			
    	}
    	
    	catch (Exception ex) {ex.printStackTrace();}
    	
    }
    
    public boolean isHappy(int n, int base) {
    	
    	ArrayList<String> numbersWeTried = new ArrayList<String>();
    	String sum = sumOfSquares(Integer.toString(n, base), base);
    	  
    	while (!sum.equals("1") && !numbersWeTried.contains(sum)) {
    	 
    	 	numbersWeTried.add(sum);
       		sum = sumOfSquares(sum, base);  
   	
    	}  
    	
    	return sum.equals("1");	
    	
    }
    
    public String sumOfSquares(String n, int base) {
    	
    	int sum = 0;
    	
    	for (int i = 0; i < n.length(); i++) {
    		
    		String s = n.substring(i, i + 1);
    		int k = Integer.parseInt(s);
    		sum = sum + k * k;
    		    		
    	}
    	
    	return Integer.toString(sum, base);
    	
    }
    
    public String TestCase(String s, int index) {
    	
    	int num = 2;
    	
    	boolean[] test = new boolean[11];
    	
    	for (int i = 2; i <= 10; i++) {
    		
    		test[i] = false;
    		
    	}
    	
    	String[] tok = s.split(" ");
    	
    	System.out.print("testing bases: ");
    		
    	for (int i = 0; i < tok.length; i++) {
    		
    		test[Integer.parseInt(tok[i])] = true;
    		    		
    	}
    	
    	for (int i = 2; i <= 10; i++) {
    		
    		System.out.print(test[i] + " ");
    		
    	}
    	    
    	System.out.println();
    	
    	boolean allMatch = false;
    	
    	while (!allMatch) {
    		
    		allMatch = true;
    		
	    	for (int i = 2; i <= 10; i++) {
	    		
	    		if (test[i]) {
	    			
	    			allMatch = allMatch && isHappy(num, i);
	    			
	    		}
	    		
	    	}
	    	
	    	if (!allMatch) {
	    	
    			num = num + 1;
    			
	    	}
    		
    	}
    	     	
    	return "Case #" + (index + 1) + ": " + num;
    	
    }
    
    public static void main(String[] args) {
    	
    	new HappyNumbers();
    	
    }
    
    
}