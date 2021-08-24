import java.util.*;
class Main{
	public static void main(String [] argv){
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for(int t = 1; t <= tests; t++){
			int c = sc.nextInt();
			int n = sc.nextInt();
			double [][] direct = new double[c + 1][c + 1];
			direct[0][n] = 1.;
			for(int i = n; i < c; i++){
				for(int j = 1; j <= n; j++){
					if(i + j <= c){
						double base = 1;
						for(int k = 0; k < n; k++){
							base /= (c - k);
						}
						for(int k = 0; k < j; k++){
							base *= (c - i - k);
						}
						for(int k = 0; k < n - j; k++){
							base *= (i - k);
						}
						direct[i][i+j] = base;
						//System.out.printf("%d %d %f\n", i, i+j, base);
					}
				}
			}
			double [] num = new double[c + 1];
			for(int i = c-1; i >= n; i--){
				double sum = 0;
				for(int j = 0; j <= n && i + j <= c; j++){
					sum += direct[i][i + j];
				}
				//System.out.println("sum" + i + ":" + sum);
				double move_ave = 1. / (sum);
				double tmp = 0;
				for(int j = 1; j <= n; j++){
					if(i + j <= c)
						tmp += direct[i][i + j] * num[i + j];
				}
				tmp /= sum;
				num[i] = move_ave + tmp;
			}
			System.out.printf("Case #%d: %.07f\n", t, (num[n] + 1));
		}
	}

}
