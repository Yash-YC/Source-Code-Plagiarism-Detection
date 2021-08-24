package round1a.a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Vector;

public class Round1AA {

	public static void main(String[] args) {
		String fileName = "src\\round1a\\a\\A-small-attempt0.in";

		String str;
		String[] strs;

		int N;
		int[] bases ={2};

		int answer;

		try{
			FileReader fr = new FileReader(fileName);
			BufferedReader br = new BufferedReader(fr);

			str = br.readLine();

			N = Integer.parseInt(str);

			for (int i=0; i<N; i++) {
				str = br.readLine();
				strs = str.split(" ");

				bases = new int[strs.length];
				for (int j=0; j<strs.length; j++) {
					bases[j] = Integer.parseInt(strs[j]);
				}

				answer = calculate(bases);
				System.out.println("Case #" + (i+1) + ": " + answer);
			}

			br.close();

		}
		catch(IOException e){
			e.printStackTrace();
			System.out.println("file error.");
		}
	}

	private static int calculate(int[] bases) {
		int n = bases.length;
		Vector vec;

		int num = 2;
		while(true) {
			int flag = 0;
			for (int i=0; i<n; i++) {
//				System.out.println("base:" + bases[i]);
				vec = new Vector();
				int num2 = num;
//				System.out.println("num2:" + num2);
				vec.add(num2);
				while(true) {
					num2 = calcHappy(num2, bases[i]);
//					System.out.println("num2:" + num2);
					if (num2 == 1) {
//						System.out.println("OK!");
//						System.out.println();
						break;
					} else if (check(num2, vec)) {
					flag = 1;
//					System.out.println("NG");
//					System.out.println();
					break;
					} else {
						vec.add(num2);
					}
				}
			}
			if (flag == 0) {
				return num;
			} else {
				num++;
			}
		}
	}

	private static int base10toBaseB(int num, int B) {
		StringBuffer answer = new StringBuffer();

		while (num >= B) {
			int amari = num % B;
			int syou = num / B;

			answer.insert(0, amari);
			num = syou;
		}

		answer.insert(0, num);

		return Integer.parseInt(answer.toString());
	}

	private static int baseBtoBase10(int num, int B) {
		String temp = "" + num;
		char[] chars = temp.toCharArray();

		int c = 0;
		int answer = 0;
		for (int i=chars.length-1; i>-1; i--) {
			answer += (int) Math.pow(B, c) * Integer.parseInt("" + chars[i]);
			c++;
		}
		return answer;
	}

	private static int calcHappy (int num, int base) {
		int answer = 0;
		String temp = "" + base10toBaseB(num, base);
		char[] chars = temp.toCharArray();

		for (int i=0; i<chars.length; i++) {
			answer += (int) Math.pow(Integer.parseInt("" + chars[i]), 2);
		}

		return answer;
	}

	private static boolean check (int num, Vector vec) {
		for (int i=0; i<vec.size(); i++) {
			int a = (Integer) vec.get(i);
			if (a == num) {
				return true;
			}
		}
		return false;
	}

}


