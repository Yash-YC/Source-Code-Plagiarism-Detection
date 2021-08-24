import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class A {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		boolean b;
		String[] line;
		ArrayList<Integer> bases;
		int total = Integer.valueOf(in.readLine());
		int theOne;

		for (int o = 0; o < total; o++) {
			line = in.readLine().split(" ");
			bases = new ArrayList<Integer>();
			theOne = 2;
			b = false;
			for (int q = 0; q < line.length; q++) {
				if (Integer.valueOf(line[q]) != 2
						&& Integer.valueOf(line[q]) != 4) {
					bases.add(Integer.valueOf(line[q]));
				}
			}
			while (1 == 1) {
				b = true;
				for (int i = 0; i < bases.size(); i++) {
					b = check(bases.get(i), theOne);
					if (b == false) {
						theOne++;
						break;
					}
				}
				if (b) {
					System.out.println("Case #" + (o + 1) + ": " + theOne);
					break;
				}
			}
		}
	}

	public static boolean check(int base, int it) {
		boolean b = false;
		int auxiliar = it, total;
		ArrayList<Integer> respostas = new ArrayList<Integer>();
		String numero = Integer.toString(it, base);
		total = numero.length();

		while (1 == 1) {
			numero = Integer.toString(auxiliar, base);
			total = numero.length();
			auxiliar = 0;

			for (int i = 0; i < total; i++) {
				auxiliar += Integer.valueOf(numero.charAt(i) + "")
						* Integer.valueOf(numero.charAt(i) + "");
			}

			if (respostas.contains(auxiliar)) {
				break;
			} else {
				respostas.add(auxiliar);
				if (auxiliar == 1) {
					b = true;
					break;
				}
			}
		}

		return b;
	}

}
