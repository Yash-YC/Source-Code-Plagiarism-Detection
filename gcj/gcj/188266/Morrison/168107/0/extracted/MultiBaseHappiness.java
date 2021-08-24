import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class MultiBaseHappiness {
	
	public static String parse(int num, int base){
		int shou = num;
		String ret = "";
		while(shou != 0){
			ret = (shou % base) + ret;
			shou = shou / base;
		}
		
		return ret;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			int t = Integer.parseInt(br.readLine());
			for(int i=0;i<t;i++){
				String[] basesStrs = br.readLine().split(" ");
				int[] bases = new int[basesStrs.length];
				for(int j=0;j<basesStrs.length;j++){
					bases[j] = Integer.parseInt(basesStrs[j]);
				}
				int happyNum = 2;
				
				while(true){
					boolean isHappy = true;
					
					for(int base : bases){
						ArrayList<Integer> junkan = new ArrayList<Integer>();
						int searchNum = happyNum;
						while(true){
							char[] happyStrs = parse(searchNum,base).toCharArray();
							int temp = 0;
							for(char hc : happyStrs){
								temp += Integer.parseInt(hc + "") * Integer.parseInt(hc + "");
							}
							if(temp == 1){
								break;
							} else if(junkan.contains(temp)){
								isHappy = false;
								break;
							} else {
								junkan.add(temp);
								searchNum = temp;
							}
						}
						
						if(!isHappy){
							break;
						}
					}
					
					if(isHappy){
						break;
					} else {
						happyNum++;
					}
				}
				
				System.out.println("Case #"+(i+1)+": "+happyNum);
			}
			
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
