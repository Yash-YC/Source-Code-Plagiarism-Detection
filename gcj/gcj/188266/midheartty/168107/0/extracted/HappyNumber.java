import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;


public class HappyNumber {

	private final int target;
	private final int base;
	
	public HappyNumber(int i, int base) {
		target = i;
		this.base = base;
		//System.err.println("HappyNumber "+target+",base:"+base);
	}

	private List<Integer> getDigits(int p) {
		List<Integer> digits = new ArrayList<Integer>();
		int value = p;
		while (value>=base) {
			int r = value / base;
			int m = value % base;
			//System.err.println("r="+r+",m="+m);
			digits.add(m);
			value = r;
		}
		digits.add(value);
		//System.err.println("digits for "+p+" base:"+base+"="+digits);
		return digits;
	}
	
	private int getHappyNumber(int p) {
		List<Integer> digits = getDigits(p);
		int number = 0;
		for (Integer digit : digits) {
			number += (digit*digit);
		}
		//System.err.println("happy number="+number);
		return number;
	}
	
	boolean isHappy() {
		boolean result = false;
		int number = target;
		//System.err.println("number="+number+" base="+base);
		HashSet<Integer> sequences = new HashSet<Integer>();
		sequences.add(target);
		while (true) {
			int nextnumber = getHappyNumber(number);
			if (nextnumber==1||nextnumber==base) {
				result = true;
				break;
			}
			if (sequences.contains(nextnumber)) {
				break; // avoid infinite loop
			}
			//System.err.println("nextnumber="+nextnumber+" base="+base);
			number = nextnumber;
			sequences.add(nextnumber);
		}
		return result;
	}
}
