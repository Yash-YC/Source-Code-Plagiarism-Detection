import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Hashtable;


public class G1C {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		
		//testdata:
//		System.out.println("1");
//		System.out.println("800");
//		for (int i=0;i<800;i++)
//		{
//			System.out.print("100000 ");
//		}
//		System.out.println();
//		for (int i=0;i<800;i++)
//		{
//			System.out.print("100000 ");
//		}
		
		
		
		BufferedReader in = new BufferedReader(new FileReader("c:/Dokumente und Einstellungen/Administrator/Eigene Dateien/Downloads/input.txt"));
        String str;
//        while ((str = in.readLine()) != null) {
//        	System.out.println(str);
//        }

        str = in.readLine();
        String[] strs;
//        strs = str.split(" ");
        int a,b,c;
        int cases; // <=1000
        cases = Integer.parseInt(str);
//        b = Integer.parseInt(strs[1]);
//        c = Integer.parseInt(strs[2]);
        
        for (int i=0; i< cases; i++)
        {
        	str = in.readLine();
        	strs = str.split(" ");
        	int[] bases = new int[strs.length]; 
        	for (int j=0; j<strs.length; j++)
        	{
//        		System.out.println("j:"+strs[j]);
        		bases[j]=Integer.parseInt(strs[j]);
        	}
        	
        	int cc=2;
        	while (1==1)
        	{
//        		System.out.println(cc);
        		Boolean found=true;
        		for (int j=0; j<strs.length; j++)
        		{
        			Hashtable happytest = new Hashtable();
        			if (!IsHappy(cc,bases[j], happytest))
        			{
        				found =false;
        				break;
        			}
        				
        		}
        		if (found)
        			break;
        		cc++;
        	}
        	
          	
        	
        	
        	
        	
        	System.out.println("Case #" + (i + 1) + ": " + cc);
        	
        
        	
        	
        }
        
	}

	private static boolean IsHappy(Integer cc, int j, Hashtable happytest) {
		
		if(happytest.contains(cc))
			return false;
		else
			happytest.put(cc, cc);
		
		String ccstr = Integer.toString(cc,j);
		
//		System.out.println("IsHappy:"+ccstr);
		
//		if (ccstr.length() ==1 && cc!=1)
//		{
//			return false;
//		}
		
		Integer sum=0;
		for(int k=0; k< ccstr.length(); k++)
		{
			Integer d =Integer.parseInt(ccstr.substring(k, k+1)); 
			sum += d*d; 
		}
//		if (sum ==0)
//			return false;
		if (sum == 1)
			return true;
//		if (sum == cc)
//			return false;
		
		return IsHappy(sum, j, happytest);
	}

}
