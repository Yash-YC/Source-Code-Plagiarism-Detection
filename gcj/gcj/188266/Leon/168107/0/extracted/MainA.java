import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class MainA {

	
	public static void main(String[] args) {
		try{
			BufferedReader fin = new BufferedReader(new FileReader("A-small.in"));
			fin.readLine();
			String sin;
			int i = 1;
			while ((sin = fin.readLine()) != null) {
				List<Integer> inList = toIntegerList(sin);
				System.out.println("Case #"+i+": "+process(inList));
				i ++;
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		
//		BufferedReader fin = new BufferedReader(new FileReader("B-test.in"));
		
		
		
		
	}
	
	public static long process (List<Integer> inList) {
		
		List<Search> sList = new ArrayList<Search>();
//		sList.add(new Search(2));
//		sList.add(new Search(3));
//		sList.add(new Search(7));

//		sList.add(new Search(9));
//		sList.add(new Search(10));
//		sList.add(new Search(7));
		for (int in: inList) {
			sList.add(new Search(in));
		}
		
		long current = 2;
		while (true) {
			long max = 0;
			for (Search s : sList) {
				long sCurrent = s.findNext(current);
				if (sCurrent > max) {
					max = sCurrent;				
				}
//System.out.println(s);				
			}
//System.out.println();			
			boolean result = true;
			long r = sList.get(0).current;
			for (int i = 1; i < sList.size(); ++i) {
				if (sList.get(i).current != r) {
					result = false;
					break;
				}
			}
			if (result == true) {
				break;
			} else {
				current = max;
			}
		}
		
//		System.out.println(sList.get(0).current);
		return sList.get(0).current;
//		Search s = new Search(3);
//		s.current = 142;
//		System.out.println("==> "+s.findNext());
//		System.out.println("==> "+s.findNext());
//		System.out.println("==> "+s.findNext());
//		System.out.println("==> "+s.findNext());
	}
	
	public static List<Integer> toIntegerList(String sin) {
		List<Integer> result = new ArrayList<Integer>();
		String[] s = sin.split(" ");
		for (int i = 0; i < s.length; ++i) {
			result.add(Integer.parseInt(s[i]));
		}
		return result;
	}	
	
}

// Happy searcher
class Search {
	int base;
	long current = 1;	
	Set<String> set = new HashSet<String>(); 
	boolean success = false;
	
	Search(int base) {
		this.base = base;
	}
	
	long findNext(long min) {
		while (current < min) {
			findNext();
		}
		return current;
	}
	
	long findNext() {
		success = false;
		while (true) {
			set.clear();
			current ++;
//System.out.println("current: "+current);			
			if (cal(current)) {
				return current;
			} else {
				continue;
			}
		}				
	}
	
	boolean cal(long num) {
		String nStr = Long.toString(num, base);
		
		if (set.contains(nStr)) {
			success = false;
			return false;
		}		
		long sum = 0;
		for (int i = 0; i < nStr.length(); i++) {			
			sum += Math.pow(Long.valueOf(nStr.substring(i, i+1)), 2); 
		}
//System.out.println(sum);		
		if (sum != 1) {
			set.add(nStr);
			return cal(sum);
		} else {
			return true;
		}
	}
	
	public String toString() {
		return "base: "+base+", current: "+current;
	}
}
