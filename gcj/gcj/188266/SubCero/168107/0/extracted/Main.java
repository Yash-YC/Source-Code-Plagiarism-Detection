package googleronda1;
import java.io.*;
import java.util.*;

//----------------------------------------------------------------------------------------------------------------
class NumeroFeliz{
    ArrayList<Integer> pasarABase(int numero, int base){
        ArrayList<Integer> digitos = new ArrayList<Integer>();
        //calculo
        while (numero>=base){
            digitos.add(numero%base);
            numero = numero/base;
        }
        digitos.add(numero);
        //Invierto
        ArrayList<Integer> digitosAux = new ArrayList<Integer>();
        for (int i=digitos.size()-1;i>=0;i--) digitosAux.add(digitos.get(i));
        return digitosAux;
    }
    int cuadrado(ArrayList<Integer> digitos, int base){
        int res = 0;
        for (int i=0;i<digitos.size();i++) 
            res += digitos.get(i)*digitos.get(i);
        return res;
    }
    int reducir(int numero, int base){
        HashSet<Integer> yaUsados = new HashSet<Integer>();
        ArrayList<Integer> digitos = pasarABase(numero, base);
        int res = cuadrado(digitos,base);
        yaUsados.add(res);
        //int res = numero;
        boolean cortar = true;
        while (
                /*(    (digitos.size()>1) || ( (digitos.size()==1) && (res>=base) ) )
                &&*/
                (cortar)
                ){
            digitos = pasarABase(res, base);
            res = cuadrado(digitos,base);
            if (yaUsados.contains(res))
                cortar = false;
            if (res==1)
                cortar = false;
            yaUsados.add(res);
        }
        return res;
    }
    
}
//----------------------------------------------------------------------------------------------------------------
public class Main {
    public static void main  (String[] args) throws Exception {
        String nombreArchivo = "entrada";
        File f = new File( nombreArchivo+".in" );
        BufferedReader entrada = new BufferedReader( new FileReader( f ) );
        PrintWriter stdOut = new PrintWriter(new FileWriter(nombreArchivo+".out"));
        
        NumeroFeliz nf = new NumeroFeliz();
       // ArrayList<Integer> res = nf.pasarABase(82,10);
        //int paso1 = nf.cuadrado(res);
        //int res = nf.reducir(91,9);
        //System.err.println(res);
        ArrayList<Integer> bases;
        int totalCasos = Integer.parseInt(entrada.readLine().trim());
        for (int caso=1;caso<=totalCasos;caso++){
            String linea = entrada.readLine().trim();
            StringTokenizer tk = new StringTokenizer(linea);
            bases = new ArrayList<Integer>();
            while (tk.hasMoreTokens()){
                bases.add(Integer.parseInt(tk.nextToken().trim()));
            }
            int numero = 2;
            boolean seguir = true;
            while (seguir){
                boolean cortar = true;
                for (int i=0;(i<bases.size())&&(cortar);i++){
                    int resParcial = nf.reducir(numero, bases.get(i));
                    if (resParcial != 1) 
                        cortar = false;
                }
                if (!cortar){
                    numero++;
                    //System.err.println(numero);
                }
                else
                    seguir = false;
            }
            
            stdOut.println("Case #" + caso +": "+ numero);
            System.err.println("Case #" + caso +": " + numero);
        }
        stdOut.flush();
        stdOut.close();
        System.err.println("Fin");
    }
}
