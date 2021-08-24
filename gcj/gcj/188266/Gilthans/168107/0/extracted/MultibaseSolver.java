package multibase;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;

public class MultibaseSolver extends Solver {

	Map<Integer, Collection<Integer>> unHappy = new HashMap<Integer, Collection<Integer>>();
	Map<Integer, Collection<Integer>> Happy = new HashMap<Integer, Collection<Integer>>();
	MultibaseSolver(BufferedReader input_stream){
		super(input_stream);
	}


	public String solve() throws IOException{
		Integer $ = 0;
		String l = input.readLine();
		String[] basesArr = l.split(" ");
		int[] allBases = new int[basesArr.length];
		for(int i=0;i<basesArr.length;i++){
			allBases[i] = Integer.parseInt(basesArr[i]);
		}
		$ = findLowestBiggerThan(1, allBases);
		return $.toString();
	}


	private Integer findLowestBiggerThan(int min, int[] allBases) {
		while(true){
			min++;
			if(isHappyInAll(min, allBases))
				return min;
		}
	}


	private boolean isHappyInAll(int i, int[] allBases) {
		for(int base : allBases){
			if(!isHappy(i, base))
				return false;
		}
		return true;
	}


	private boolean isHappy(int i, int base) {
		if(isUnhappy(i, base))
			return false;
		if(Happy.get(base) != null && Happy.get(base).contains(i))
			return true;
		Collection<Integer> digits = new LinkedList<Integer>();
		int temp = i;
		while(temp != 0){
			int digit = temp%base;
			digits.add(digit);
			temp/=base;
		}
		temp = sumSquares(digits);
		if(temp == 1){
			if(Happy.get(base) == null) Happy.put(base, new HashSet<Integer>());
			Happy.get(base).add(i);
			return true;
		}
		createUnhappy(i, base);
		if( isHappy(temp, base)){
			unHappy.get(base).remove(i);
			if(Happy.get(base) == null) Happy.put(base, new HashSet<Integer>());
			Happy.get(base).add(i);
			return true;
		}
		return false;
	}


	private void createUnhappy(int i, int base) {
		if(unHappy.get(base) == null)
			unHappy.put(base, new HashSet<Integer>());

		unHappy.get(base).add(i);
	}


	private boolean isUnhappy(int i, int base) {
		if(unHappy.get(base) == null)
			return false;
		return unHappy.get(base).contains(i);
	}


	private int sumSquares(Collection<Integer> digits) {
		int $=0;
		for(int i : digits){
			$ += i*i;
		}
		return $;
	}

}
