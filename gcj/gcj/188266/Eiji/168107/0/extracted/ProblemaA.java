package gcj.gcj2009.round1.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class ProblemaA {

	private static final String ARQ_IN = "src/gcj/gcj2009/round1/a/entradaA.txt";
	private static final String ARQ_OUT = "src/gcj/gcj2009/round1/a/saidaA.txt";
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File(ARQ_IN));
		PrintWriter printer = new PrintWriter(new File(ARQ_OUT));
		
		long numTestCases = Long.parseLong(sc.nextLine().trim());
		
		for (long i = 0; i < numTestCases; i++) {
			long[] entradas = converteArrayParaLong(sc.nextLine().trim().split(" "));
			long result = resolve(entradas);
			System.out.printf("Case #%d: %s\n", i + 1, result);
			printer.printf("Case #%d: %s\n", i + 1, result);

		}
		printer.close();
		sc.close();
	}
	
	private static long[] converteArrayParaLong(String[] array) {
		long[] result = new long[array.length];
		for (int i = 0; i < array.length; i++) {
			result[i] = Long.parseLong(array[i]);
		}
		return result;
	}

	private static long resolve(long[] numeros) {
		long result = 2;
		map = new HashMap<Long, Boolean>();
		while (!ehMagico(numeros, result)) {
			result++;
		}
		return result;
	}
	
	private static boolean ehMagico(long[] numeros, long numeroDaVez) {
		for (int i = 0 ; i < numeros.length; i++) {
			set = new HashSet<Long>();
			if (!isMagicNumber(numeros[i], numeroDaVez)) {
				return false;
			}
		}
		return true;
	}
	
	static Map<Long, Boolean> map;
	static Set<Long> set;
	
	private static boolean isMagicNumber(long base, long number) {
//		if (set.contains(number)) {
//			if (map.containsKey(number)) {
//				return map.get(number);
//			} else {
//				return false;
//			}
//		}
//		if (map.containsKey(number)) {
//			return map.get(number);
//		} 
		
		if (set.contains(number)) {
			return false;
		}
		
		long novoNumero = novoNumero(base, number);
		if (novoNumero == 1) {
			return true;
		}
		set.add(number);
		if (isMagicNumber(base, novoNumero)) {
			map.put(novoNumero, true);
			return true; 
		} else {
			map.put(novoNumero, false);
			return false;
		}
	}

	private static long novoNumero(long base, long number) {
		return getSomaDecimal(base, number);
	}

	private static long getSomaDecimal(long base, long number) {
		long result = 0;
		long temp = number;
		while (temp != 0) {
			long menor = (temp % base);
			result += (menor * menor);
			temp = temp / base;
		}
		return result;
	}
}
