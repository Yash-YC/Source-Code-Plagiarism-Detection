/*
 * Creado por SharpDevelop.
 * Usuario: Juan Fajardo Barrero 
 * juanfbarrero@gmail.com
 * Fecha: 14/07/2008
 * Hora: 9:50
 * CodeJam - Round 1B - A
 * 
 */
using System;
using System.IO;

namespace CodeJam
{
	class Program
	{
		
		
	public static double process(int c,int n)
	{
		double recolectados=n;
		double resultado=1;
		while (recolectados<c)
		{
			resultado=resultado+Convert.ToDouble(c-recolectados)/n;
		    recolectados+=recolectados+Convert.ToDouble(c-recolectados)/n;
		}
		return resultado+1;
	}

		public static void Main(string[] args)
		{
	        long T;
	        double res;
	        int c,n;
	        TextReader tr=new StreamReader(args[0]);
			String line;
			line=tr.ReadLine();
			T=Convert.ToInt32(line);
			String s;
			String []arr;
			for (long i=0;i<T;i++)
			{
 			   line=tr.ReadLine();
			   arr=line.Split(' ');
			   c=Convert.ToInt16(arr[0]);
			   n=Convert.ToInt16(arr[1]);
			   
			   res=process(c,n);
			   s=res.ToString("0.0000000");
			   s=s.Replace(',','.');
			   Console.WriteLine("Case #"+(i+1)+": "+s);
		
			}
			
			tr.Close();
		}
	}
	
}
