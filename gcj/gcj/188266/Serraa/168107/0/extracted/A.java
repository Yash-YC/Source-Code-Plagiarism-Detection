import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

public class A {

	static Map<String, Boolean> magica = new HashMap<String, Boolean>();

	static boolean calcula(int base, String numero) {
		if (numero.equals("1")) return true;
		//System.out.println(numero);

		String chave = new String(numero).concat(new Integer(base).toString());
		if (!magica.containsKey(chave)) {
			String novoNumero = "0";
			for (int i = 0; i < numero.length(); i++) {
				int k = (numero.charAt(i) - '0') * (numero.charAt(i) - '0');
				novoNumero = soma(novoNumero, Integer.toString(k, base), base);
			}

			magica.put(chave, false);
			magica.put(chave, calcula(base, novoNumero));
		}
		return magica.get(chave);
	}

	private static String soma(String a, String b, int base) {
		String ma = (a.length()>b.length())?(a):(b);
		String me = (a.length()>b.length())?(b):(a);
		while (me.length()<ma.length()) {
			me = "0".concat(me);
		}
		String soma ="";
		int sf = 0;
		for (int i=ma.length()-1;i>-1;i--) {
			int sm = (ma.charAt(i)-'0') + (me.charAt(i)-'0') + sf;
			sf = sm / base;
			sm %= base;
			soma = new Integer(sm).toString().concat(soma);
		}
		if (sf>0) {
			soma = new Integer(sf).toString().concat(soma);
		}
		return soma;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader entrada = new BufferedReader(new InputStreamReader(
				System.in));
		String linha = entrada.readLine();
		int t = Integer.parseInt(linha);
		for (int k = 1; k <= t; k++) {
			linha = entrada.readLine();
			String[] tokens = linha.split(" ");
			int bases = tokens.length;
			int base[] = new int[bases];
			for (int i = 0; i < bases; i++) {
				base[i] = Integer.parseInt(tokens[i]);
			}
			boolean achou;
			for (int i = 2;; i++) {
				achou = true;
				for (int j = 0; j < bases; j++) {
					if (!calcula(base[j], Integer.toString(i, base[j]))) {
						achou = false;
						break;
					}
				}
				if (achou) {
					System.out.println("Case #" + k + ": " + i);
					break;
				}
			}

		}

	}

}
