package google2009.round1;

import google.Arquivo;

import java.io.*;
import java.util.*;

public class Round1A {
	public static void main(String[] args) throws Exception {
		new Round1A();
		//System.out.println(Integer.toString(16, 5));
	}
	
	public Round1A() throws FileNotFoundException {
		Scanner sc = new Scanner(new File("2009/round1/a/A-large.in"));
		int T = sc.nextInt();
		StringBuffer resposta = new StringBuffer();
		sc.nextLine();
		Vector<Cell> cells = new Vector<Cell>();
		for (int i = 0; i < T; i++) {
			String line = sc.nextLine();
			String bases1[] = line.split(" ");
			int bases[] = new int[bases1.length];
			for (int j = 0; j < bases1.length; j++) {
				String b = bases1[j];
				bases[j] = Integer.parseInt(b);
			}
			//int n[] = new int[bases.length];
			int base = bases.length-1;
			long n = 1;
			long ret = 2;
			Cell c = new Cell(bases);
			for (Cell cell : cells) {
				//System.out.println(cell.v);
				if (cell.useThis(c)) {
					n = cell.v;
					System.out.println("usa "+n);
					break;
				}
			}
			while (ret != 1) {
				n++;
				for (base = bases.length - 1; base >= 0; base--) {
					int b = bases[base];
					hash = new Hashtable<Long, Long>();
					ret = r(n, b);
					if (ret != 1) {
						break;
					}
				}
			}
			c.v = n;
			if (!cells.contains(c)) {
				cells.add(c);
				Collections.sort(cells);
			}
			String out = "Case #"+(i+1)+": "+n+"\n";
			System.out.println(out);
			resposta.append(out);
		}
		Arquivo.escrever(resposta.toString(), "2009/round1/a/A-large.out");
		System.exit(0);
	}
	Hashtable<Long, Long> hash;
	
	long r(long n, int b) {
		String str = Long.toString(n, b);
		if (n==1) {
			return n;
		}
		long soma = 0;
		for (int i = 0; i < str.length(); i++) {
			char dig = str.charAt(i);
			int dig2 = dig-'0';
			//soma += Integer.parseInt(Integer.toString(dig2 << 2, b));
			soma += dig2 * dig2;
		}
		if (hash.put(soma, soma)!=null) return soma;
		return r(soma, b);
	}
	
	boolean fim(int n[], int b[]) {
		for (int i = 0; i < n.length; i++) {
			if (n[i] % b[i] >= b[i]) return false;
		}
		return true;
	}

	/*double a = 0.3463635654567474746;
	DecimalFormat df = new DecimalFormat("0.0000000", new DecimalFormatSymbols(Locale.US));
	System.out.println(df.format(a));*/
}
