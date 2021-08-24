package google;


/*
Possui dois métodos básicos de escrita e leitura de arquivo
Melhorar a interface
*/

import java.io.*;

public class Arquivo extends File {
	static final long serialVersionUID=1;
	Arquivo (String arq) {super(arq);}
	//Escreve no arquivo
	void escrever (String texto) {escrever (texto, this.getName());}
	public static void escrever (String texto, String nome) {
	        File arquivo;
	        FileOutputStream stream;
	        OutputStreamWriter writer;
	
	        try {
	                arquivo = new File(nome);
	                stream = new FileOutputStream(arquivo);
	                writer = new OutputStreamWriter(stream);
	
	                writer.write (texto, 0, texto.length());
	
	                writer.close();
	                stream.close();
	        }
	        catch (FileNotFoundException e) {
	                System.out.println ("Arquivo " + nome + " não encontrado.");
	        }
	        catch (IOException e) {
	                System.out.println ("Erro de escrita no arquivo " + nome);
	        }
	}
	
	//Lê o arquivo de entrada e passa os dados para o programa
	String ler () {return ler (this.getName());}
	public static String ler (String arq) {
	        File arquivo;
	        FileInputStream stream;
	        InputStreamReader reader;
	        LineNumberReader LNReader;
	        String retorno = new String();
	        try {
	                arquivo = new File(arq);
	                stream = new FileInputStream(arquivo);
	                reader = new InputStreamReader(stream);
	                LNReader = new LineNumberReader(reader);
	
	                String linha = LNReader.readLine();
	                while (linha != null) {
	                        retorno += linha + "\n";
	                        linha = LNReader.readLine();
	                }
	                LNReader.close();
	                reader.close();
	                stream.close();
	        }
	        catch (FileNotFoundException e) {
	                System.out.println ("Arquivo " + arq + " não encontrado.");
	        }
	        catch (IOException e) {
	                System.out.println ("Erro de leitura no arquivo " + arq);
	        }
	        return retorno;
	}
	
	/** Não esquecer de fechar o reader (.close()) */
	static BufferedReader obterReader (String arq) {
	        BufferedReader reader = null;
	
	        try {
	                //Em caso de querer ler bytes (ser mais específico)
	                //reader = new BufferedReader(new InputStreamReader(new FileInputStream(new File(arq))));
	                reader = new BufferedReader(new FileReader(arq));
	        }
	        catch (FileNotFoundException e) {
	                System.out.println ("Arquivo " + arq + " não encontrado.");
	        }
	        /*catch (IOException e) {
	                System.out.println ("Erro de leitura no arquivo " + arq);
	        }*/
	        return reader;
	}
}
