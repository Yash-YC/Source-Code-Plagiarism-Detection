package problemB;


import java.util.ArrayList;
import java.util.Random;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class TestCase {
	
	int N, C;
	
	public TestCase(int n, int c) {
		this.N = n;
		this.C = c;
	}
	
	public Double getAnswer() {
		if(this.C == this.N) return 1.0;
		double tryCount = 0.0;
	    Random randomGenerator = new Random();
		for(int i=0; i<100000; i++) {
			Set n = new HashSet<Integer>();
			while(n.size() != this.C) {
				tryCount++;
				Set temp = new HashSet<Integer>();
				while(temp.size() < this.N) {
					temp.add(randomGenerator.nextInt(C));
				}
				n.addAll(temp);
			}
		}
		return (tryCount / 100000);
	}
	
//	public Double getAnswer() {
//		double combinations = this.combination(N, C);
//		double ev = 0.0;
//		for(int i=0; i<100000; i++) {
//			
//		}
//		
//		return 0.0;
//	}
		
	public double factorial(int n)
	{
		int i;
		double a = 1;
		if (n > 1)
			for (i = 2; i <= n; i++)
				a *= i;
		return(a);
	}
	
	public double combination(int n, int r)
	{
		double a,b,value;
		a=factorial(n);
		b=factorial(r)*factorial(n-r);
		value=a/b;
		return value;
	}
}

