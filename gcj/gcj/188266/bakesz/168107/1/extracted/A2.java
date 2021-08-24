import java.io.BufferedReader;
import java.io.*;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.HashMap;
import java.util.HashSet;
import java.util.*;
import java.util.Dictionary;

public class A2
{

static boolean isgood(int n,int base)
{
int n2=1;
int a;
HashSet<Integer> kk=new HashSet();
//while (n2!=n)
while (!kk.contains(new Integer(n) ))
{
kk.add(new Integer(n) );
//System.err.printf("19::%d %d %d\n",n,n2,base);
n2=n;
a=n;
n=0;
//c=1;
while (a!=0)
{
int k=a%base;
a/=base;
//n=(n*base+k*k);
//n=n+k*k*c;
n=n+k*k;

//c=c*base;
}

}
//System.err.printf("34::%d\n",n);
if (n==1) return true;else return false;
}

static int megold(int[] bases)
{
int i;
boolean ok=false;
for (i=2;!ok;i++)
	{
//	System.err.printf("43::%d\n",i);
	ok=true;
	for (int j=0;(j<bases.length) && (ok);j++)
		if (!isgood(i,bases[j] ) ) ok=false;  
	}
return i;	
}

static public void main(String[] args)
{
BufferedReader in=null;
int c_n=0;
try{
in=new BufferedReader(new FileReader(args[0]) );
c_n=Integer.parseInt( in.readLine() );
} catch (Exception e) {System.err.printf("problem at opening\n"); }
int c_n_i;
Hashtable ww=new Hashtable();
for (c_n_i=0;c_n_i<c_n;c_n_i++)
	{
	System.out.printf("Case #%d: ",c_n_i+1);
	String[] elemek=null;
	try{
	elemek=in.readLine().split(" ");	
	}catch (Exception e) {}
	int[] bases=new int[elemek.length];
	for (int i=0;i<elemek.length;i++)
		bases[i]=Integer.parseInt(elemek[i]);
	Arrays.sort(bases);	
	int szam=0;
	for (int i=0;i<elemek.length;i++)
		szam=szam*10+bases[i];
	
	if (null==ww.get(new Integer(szam) ) ) ww.put(new Integer(szam) ,new Integer(megold(bases)-1 ) );
	System.out.println(ww.get(new Integer(szam) ) );	
	
	}
}
}
