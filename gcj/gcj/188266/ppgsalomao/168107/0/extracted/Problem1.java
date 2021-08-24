import java.util.Scanner;


public class Problem1 {
	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		int numeroCasos = s.nextInt();
		s.nextLine();
		
		for (int i = 0; i < numeroCasos; i++) {
			String linha = s.nextLine();
			String[] numeros = linha.split(" ");
			
			int numero = 2;
			while(true) {
				boolean todosSao = true;

				for (int j = 0; j < numeros.length; j++) {
					if(!isHappyOnBase(numero, Integer.parseInt(numeros[j]))) { todosSao = false; numero++; break; }
				}

				if(!todosSao) { continue; } 
				
				break;
			}
			
			if(i != 0) System.out.print("\nCase #" + (i + 1) + ": " + numero);
			else System.out.print("Case #" + (i + 1) + ": " + numero);
		}
	}

	private static boolean isHappyOnBase(int numero, int base) {
		boolean isHappy = false;
		char[] stringN = toBase((long) numero, (short) 10, (short) base, "");

		for(int i = 0; i < 1000; i++) {
			int soma = 0;
			for (int j = 0; j < stringN.length; j++) {
				int n = Integer.valueOf(String.valueOf(stringN[j]));
				soma += n*n;
			}

			if(soma == 1) {
				isHappy = true;
				break;
			} else {
				stringN = toBase((long) soma, (short) 10, (short) base, "");
			}
		}
		
		return isHappy;
	}
	
	private static char[] toBase(final long i, final short base, final short radix, String nullCharacter) {
		long value = i;

		if (value == 0) {
			return nullCharacter.toCharArray();
		}

		String result = "";
		while (value > 0) {
			long mod = value % radix;
			result = mod + result;
			value -= mod;
			if (value > 0) value /= radix;
		}

		return result.toCharArray();
	}
}
