import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class CollectingCards {
	
	public static void main(String[] args) throws Exception {
		int i,j,k,m;
		int T,N,C;
		String line;
		
		// first we calculate the combinations
		
		long comb[][] = new long[12][12];

		for (j=0;j<12;j++) {
		  comb[0][j]=1;
		  comb[j][j]=1;
		  for (i=1;i<j;i++) {
		       comb[i][j]=comb[i-1][j-1]+comb[i][j-1];
		  }
		}
		
		BufferedReader br = new BufferedReader(new FileReader("C-small.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C-small.out")));
		
		StringTokenizer st;
		
		line = br.readLine();
		st = new StringTokenizer(line);
		T = Integer.parseInt(st.nextToken());
		
		double opt[][];
		double one;
		double res;
		String num;
		int sum;
		
		// I NEED TO CHANGE INTO T
		
		for (k=1;k<=T;k++) {
			line = br.readLine();
			st = new StringTokenizer(line);
			C = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			
			opt = new double[1024][100];
			boolean valid[] = new boolean[1024];
			
			for (j=0;j<(1<<C);j++) {
				// we get the subset j in the last step
				
				num = Integer.toBinaryString(j);
				
				// we calculate the sum of bits
				sum = 0;
				for (m=0;m<num.length();m++) {
					if (num.charAt(m) == '1') sum++;
				}
				
				if (sum == N) {
					valid[j] = true;
				}
			}
			
			one = 1.0/comb[N][C];
			
			//System.out.println("TEST: "+N+" "+C+" "+one);
			
			int step;
			
			// we take from 0, and write to 1
			
			if (N == C) {
				res = 1.0;
			} else {
				
				// every combination from the start has same probability
				
				for (i=0;i<(1<<C);i++) {
					// valid are the ones that have sum of their bits N
					
					//System.out.println(i);
					
					num = Integer.toBinaryString(i);
					// we calculate the sum of bits
					sum = 0;
					for (j=0;j<num.length();j++) {
						if (num.charAt(j) == '1') sum++;
					}
					
					if (sum == N) {
						// every combination has the same chances at the beginning (at step 1)
						
						opt[i][1] = one;
					}
					
				}
				
				/*
				for (i=0;i<4;i++) {
					System.out.println("opt["+i+"]["+1+"] = "+opt[i][1]);
				}
				*/
				
				res = 0.0;
				int new_subset;
				
				for (step=2;step<100;step++) {
					
					
					
					//System.out.println("STEP: "+step);
					
					// we don't include the last subset because it is already full
					for (i=0;i<(1<<C)-1;i++) {
						
						//System.out.println(i);
						
						// all are valid numbers
						
						for (j=0;j<(1<<C);j++) {
							if (valid[j] == true) {
								
								//System.out.println("SUBSET: "+j);
								
								new_subset = (i|j);
								
								opt[new_subset][step] += (opt[i][step-1]*one);
								
							}
							
							
						}
						
					}
					
					res += (opt[(1<<C)-1][step]*(double)step);
					
				}
				
			}
			
			System.out.println("Case #"+k+": "+res);
			out.println("Case #"+k+": "+res);
			
		}
		
		
		out.close();
		System.exit(0);	
		
	}
	
}

