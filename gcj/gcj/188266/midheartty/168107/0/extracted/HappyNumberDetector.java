import java.util.List;


public class HappyNumberDetector {

	private final List<Integer> bases;
	
	public HappyNumberDetector(List<Integer> bases) {
		this.bases = bases;
	}
	
	public int getHappyNumber() {
		int number = 2;

		boolean found = false;
		while (!found) {
			boolean result = false;
			for (number = 2; !result; number++) {
				result = true;
				//System.err.println("testing num:"+number);
				for (Integer base :  bases) {
					HappyNumber hn = new HappyNumber(number, base);
					result = result && hn.isHappy();
					//System.err.println("num:"+number+",base:"+base+",result="+result);
				}
				if (result) {
					found = true;
					break;
				}
			}
		}
		
		return number;
	}
}
