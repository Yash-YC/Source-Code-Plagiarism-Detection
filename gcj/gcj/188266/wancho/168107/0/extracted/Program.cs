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
using System.Text.RegularExpressions;
namespace CodeJam
{
	class Program
	{
		
public static long f(long n , int rdx)
{
	long k = 0,m;
	while(n!=0){
		m = n % rdx;   
		n = n / rdx;
		k += m*m;
	}
	return k;
    }


	public static bool is_happy(long n, int rdx)
{
	long j,old_n,loops=10;	

	while(true){
		old_n = n;
		for(j=loops;j>0;j--)
			if((n = f(n,rdx))== old_n)break;
		if(n==old_n)break;
		loops += 10;
	}
	return n == 1 ? true : false;
}
		
	public static long process(String []arr)
	{
		int n=arr.Length;
		bool ok;
		long j=2;
		while (true)
		{
			    ok = true;
				for(int i=0;i<n;i++)
					if(!is_happy(j,Convert.ToInt16(arr[i])))ok=false;
				if(ok)
					return j;
		   j++;
		}
		return 0;
	}



		public static void Main(string[] args)
		{
	        long T,res;
	        
	        TextReader tr=new StreamReader(args[0]);
			String line;
			line=tr.ReadLine();
			T=Convert.ToInt32(line);
			
			String []arr;
			for (long i=0;i<T;i++)
			{
			   line=tr.ReadLine();
			   arr=line.Split(' ');
			   res=process(arr);
			   Console.WriteLine("Case #"+(i+1)+": "+res);
		
			}
			
			tr.Close();
		}
	}
	
}
