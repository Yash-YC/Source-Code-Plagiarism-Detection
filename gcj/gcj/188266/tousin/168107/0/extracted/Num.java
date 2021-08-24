package Round1A.Num;

import java.io.IOException;
import java.util.HashSet;
import java.util.Set;



public class Num {
	
	public String analysis(TestCase test){
		int currenNum;
		int currenBase;
		boolean isfind = false;
		for(int i=2;;i++){
			int n = 0;
			for(n = 0;n<test.base.length;n++){
				if(!isHappy(Integer.parseInt(test.base[n]),i)){
					break;
				}
			}
			if(n == test.base.length){
				return i+"";
			}
		}
	}
	
	public boolean isHappy(int base,int num){
		
		int sum = 0;
		int temp = 1;
		int n = 0;
		Set s = new HashSet();
		while(!s.contains(sum)){
			temp =1;
			s.add(sum);
			if(sum != 0){
				num = sum;
			}
			sum = 0;
			
			n=0;
			while(temp >= 1){	
				
				int t = (int)Math.pow((double)base, (double)n);
				temp = num/t;
				sum += (temp%base)*(temp%base);
				n++;
			}
			
			if(sum == 1){
				return true;
			}
		}
		return false;
	}
	
	public static void main(String[] args) {
		try {
			final String filename = "A-small-attempt1";
			StringBuffer ans = new StringBuffer();
			
			InputData data = FileCenter.read("./src/Round1A/Num/"+filename+".in");
			Num p  = new Num();
			String answer = "";
			for(int n=0;n<data.num;n++){
				answer = p.analysis(data.testcase[n]);
				System.out.println("Case #"+(n+1)+": "+answer);
				ans.append("Case #"+(n+1)+": "+answer+"\r\n");
			}
			FileCenter.write("./src/Round1A/Num/"+filename+".out", ans.toString());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
