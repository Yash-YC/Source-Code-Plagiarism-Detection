package gt.jl.jam.roundone;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CollectingCards {
	static Writer output;

	public int factorial(int n) {
		int suma = n;
		if(n == 0) {
			return 1;
		}
		return suma * factorial(n-1);
	}

	public int calcularCombinacion(int tc, int cp) {
		return factorial(tc) / (factorial(tc - cp) * factorial(cp));
	}

	public double promedioPaquetes(int tiposCartas, int cartasPaquete) {
		double combinaciones = calcularCombinacion(tiposCartas, cartasPaquete);
		double promedio = combinaciones / cartasPaquete;
		promedio++;
		return promedio;
	}

	public static void main(String[] args) {
		CollectingCards app = new CollectingCards();

		String name = "C-small-attempt0";
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
							int tiposCartas = scanner.nextInt();
							int cartasPaquete = scanner.nextInt();
							double promedio = app.promedioPaquetes(tiposCartas, cartasPaquete);
							DecimalFormat df = new DecimalFormat("#0.0000000");
							output.write("Case #" + nLinea + ": "
									+ df.format(promedio) + "\n");
							System.out.println("Case #" + nLinea + ": "
									+ df.format(promedio) + "\n");
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
