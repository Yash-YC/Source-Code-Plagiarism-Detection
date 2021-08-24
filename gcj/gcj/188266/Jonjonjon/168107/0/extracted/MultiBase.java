package src;
import java.util.*;

public class MultiBase {
	private int num;
	public MultiBase(String number, int base) {
		int cnum;
		String tchar = "";
		num = 0;
		int numlen = number.length();
		for(int i=0; i<numlen-1; i++) {
			tchar = number.substring(numlen-1-i, numlen-i);
			cnum = Integer.parseInt(tchar);
			num += cnum * (int)Math.pow((double)base, (double)i);
		}
		if(number.substring(0, 1).equals("-")) {
			num *= -1;
		} else {
			tchar = number.substring(0, 1);
			cnum = Integer.parseInt(tchar);
			num += cnum * (int)Math.pow((double)base, (double)numlen-1);
		}
	}
	
	// base must be <= 10
	public String getInBase(int base) {
		return Integer.toString(num, base);
	}
	
	public boolean isHappy(int base) {
		String cn = getInBase(base);
		int h = 0;
		int nu;
		String cu;
		boolean hap = true;
		HashMap<String, String> seenNums = new HashMap<String, String>();
		while(!cn.equals("1")) {
			h = 0;
			
			for(int i=0; i<cn.length(); i++) {
				cu = cn.substring(i, i+1);
				nu = Integer.parseInt(cu);
				h += nu * nu;
			}
			cn = getInBase(h, base);
			if(seenNums.containsKey(cn)) {
				hap = false;
				break;
			}
			seenNums.put(cn, cn);
		}
		return hap;
	}
	private String getInBase(int numbe, int base) {
		return Integer.toString(numbe, base);
	}
}
