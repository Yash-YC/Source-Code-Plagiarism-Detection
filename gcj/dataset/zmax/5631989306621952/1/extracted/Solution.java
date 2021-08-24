package theLastWord;

import java.util.*;

public class Solution {

	public static String getLastWord(String s){
		int length = s.length();
		if(length == 1){
			return s;
		}
		
		String result = String.valueOf(s.charAt(0));
		for(int i=1;i<length;i++){
			if(s.charAt(i) < result.charAt(0)){
				result += String.valueOf(s.charAt(i));
			}
			else{
				result = String.valueOf(s.charAt(i)) + result;
			}
		}
		
		return result;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		
		for(int i=1;i<=testNum;i++){
			String s = scan.next();
			String lastWord = Solution.getLastWord(s);
			System.out.printf("Case #%d: %s\n", i, lastWord);
		}
		
		scan.close();

	}

}
