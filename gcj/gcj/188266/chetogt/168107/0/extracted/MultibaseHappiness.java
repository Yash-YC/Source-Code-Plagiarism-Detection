package gt.jl.jam.roundone;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class MultibaseHappiness {
	static Writer output;

	public String convertirNumero(int n, int base) {
		StringBuffer numero = new StringBuffer();

		boolean completado = false;

		while(!completado) {
			int mod = n % base;
			numero.append(mod);
			n = (n / base);
			if(n == 0) {
				completado = true;
			}
		}

		return numero.reverse().toString();
	}

	public int sumaNumeroFeliz(String numeroConvertido, int casos, int base) {
		int sumar = 0;
		for (int i = 0; i < numeroConvertido.length(); i++) {
			// multiplicar digito * digito
			int multiplicado = Integer.parseInt(numeroConvertido.substring(i, i+1));
			multiplicado *= multiplicado;
			sumar += multiplicado;
			// sumar += multiplicar
		}
		if(sumar == 1) {
			return sumar;
		} else {
			if(casos < 30) {
				numeroConvertido = convertirNumero(sumar, base);
				return sumaNumeroFeliz(numeroConvertido, ++casos, base);
			} else {
				return 0;
			}
		}
	}

	public boolean evaluarNumero(int n, int base) {
		// convertir numero a base n
		String numeroConvertido = convertirNumero(n, base);
		int sumar = 0;
		//System.out.println(numeroConvertido);
		// para cada digito que forma parte de n
		sumar = sumaNumeroFeliz(numeroConvertido, 1, base);
		if(sumar == 1) {
			return true;
		} else {
			return false;
		}
	}

	public int encontrarNumeroFeliz(List<Integer> bases) {
		int satisfecho = 0;
		int n = 2;
		Iterator iterBases = bases.iterator();

		//System.out.println(bases);

		while(satisfecho < bases.size()) {
			while(iterBases.hasNext()) {
				int base = ((Integer) iterBases.next()).intValue();
				boolean cumple = evaluarNumero(n, base);
				if(cumple) {
					satisfecho++;
				}
			}
			if(satisfecho == bases.size()) {
				break;
			} else {
				satisfecho = 0;
				iterBases = bases.iterator();
			}
			n++;
		}

		return n;
	}

	public static void main(String[] args) {
		MultibaseHappiness app = new MultibaseHappiness();

		String name = "A-small-attempt1";
		String path = "";
		int valueT = 0;
		int valueD = 0;
		int valueN = 0;

		try {
			File archivoEntrada = new File(path + name + ".in");
			File archivoSalida = new File(path + name + ".out");

			output = new BufferedWriter(new FileWriter(archivoSalida));

			BufferedReader entrada = new BufferedReader(new FileReader(
					archivoEntrada));
			try {
				String linea = null;
				int nLinea = 0;
				List<Integer> bases = null;

				while ((linea = entrada.readLine()) != null) {
					// procesar cada linea y agregarla al Collection
					// los casos
					Scanner scanner = new Scanner(linea);
					scanner.useDelimiter(" ");
					if (scanner.hasNext()) {
						if (nLinea == 0) {
							// los datos iniciales
							valueT = scanner.nextInt();
						} else {
							// las bases
							bases = new ArrayList<Integer>();
							String strBase = linea;
							String[] arrStrBase = strBase.split(" ");
							for (int i = 0; i < arrStrBase.length; i++) {
								bases.add(new Integer(arrStrBase[i]));
							}
							int numeroFeliz = app.encontrarNumeroFeliz(bases);
							output.write("Case #" + nLinea + ": "
									+ numeroFeliz + "\n");
							System.out.println("Case #" + nLinea + ": "
									+ numeroFeliz + "\n");
						}
						nLinea++;

					} else {
						System.out.println("Error al procesar la linea: "
								+ linea);
					}

					scanner.close();
				}
			} finally {
				System.out.println("Finalizado el proceso!!!");
				output.close();
				entrada.close();
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}

}
