import java.util.*;
import java.util.regex.*;
import java.io.*;
	


public class One{

    HashMap<Integer, Integer> h =  new HashMap<Integer, Integer>();
    static HashSet<Integer> s = new HashSet<Integer>();
    public static int divideByBase(int number, int base){
	
	if (number < base){
	    return number * number;
	}
	else {
	    int answer = number / base;
	    int remainder = number % base;
	    //System.out.println(remainder);
	    //System.out.println(firstdigit);
	    //int rest = number - (firstdigit * base);
	    return (remainder * remainder) + divideByBase(answer, base);
	}
    }


    
    public static boolean findMagicNumber(int number, int base){
        
	int x = divideByBase(number, base);
	
	//System.out.println(x);
	if (x == 1){
	    return true;
	}
	if (s.contains(x)){
	    //System.out.println(x);
	    return false;
	}
	s.add(x);
	return findMagicNumber(x, base);
    }
    /*
    public static int findHappyNumber(int lowerBound, int base){
	int start = lowerBound+1;
	while (true){
	    if (findMagicNumber(start, base) == 1){
		return start;
	    }
	    start++;
	}
    }
    */
    public static boolean isHappy(int number, int base){
	s = new HashSet<Integer>();
	return findMagicNumber(number, base);
    }

    /*
    public static int compareBases(ArrayList<Integer> bases){
        if (h.contains(bases.get(0))){
	    int number = h.get(bases.get(0));
	    if (h.contains(bases.get(1))){
		int nextnumber = h.get(bases.get(0));
		if (number == nextnumber){
		    return compareBases(bases.remove(0));
		}
	    }
	}
	else {
	    
	}
    }
    */

    public static int findHappy(ArrayList<Integer> bases){
	int i = 2;
	while (true) {
	    if (checkBases(i, bases)){
		return i;
	    }
	    i++;
	}
    }

    public static boolean checkBases(int number, ArrayList<Integer> bases){
	for (int i = 0; i < bases.size(); i++){
	    s = new HashSet<Integer>();
	    if (isHappy(number, bases.get(i))){
	    }
	    else {
		return false;
	    }
	}
	return true;
    }
    public static void main(String[] args){

	File file = new File(args[0]);
	try {
	    Scanner scanner = new Scanner(file);

	    String s = scanner.nextLine();
	    int L = Integer.parseInt(s);
	    
	    ArrayList<ArrayList<Integer>> cases = new ArrayList<ArrayList<Integer>>();
	    while (scanner.hasNextLine()){
		String p = scanner.nextLine();
		StringTokenizer st = new StringTokenizer(p);

		ArrayList<Integer> a = new ArrayList<Integer>();

		while (st.hasMoreTokens()){
		    a.add(Integer.parseInt(st.nextToken()));
		}
		
		cases.add(a);

		
	    }

	    //System.out.println(cases);
	    
	    //System.out.println(findMagicNumber(9, 9));
	    
	    //System.out.println(findMagicNumber(7, 7));
	    //System.out.println(findMagicNumber(91, 10));
	    

	    //System.out.println(findHappy(cases.get(1)));
	    
	     for (int i = 0; i < cases.size(); i++){
		ArrayList<Integer> bases = cases.get(i);
		
		
		System.out.println("Case #" + (i + 1) + ": " + findHappy(bases));
	    }
	    

	}
	catch (Exception e) {
	    System.out.println(e);
	}


    }
}