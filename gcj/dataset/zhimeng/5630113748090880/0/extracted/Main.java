import java.util.*;
import java.io.*;


public class Main {
	
  public static void main(String[] args) {
	  try {
		System.setIn(new FileInputStream("g:/B-small-attempt2.in"));
	} catch (FileNotFoundException e) {
		e.printStackTrace();
	}
	  
	  Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	  int line = in.nextInt();
	  int t = 1;
	  int[] s;
	  int i;
	  int n;
	  String string = "";
	  while (t <= line) {
		  n = in.nextInt();
		  s = lost(loadCase(in, n), n);
		  i = 0;
		  string = "";
		  while (i < s.length) {
			  string = string + " " + s[i];
			  i++;
		  }
		  System.out.println("Case #" + t + ":" + string);
		  t++;
	  }
	  in.close();
  }
  
  public static int[] lost(int[][] t, int n) {
	  int[][] mt = copy(t, n);
	  int i = 0;
	  int m = 0;
	  int[] s = new int[n];
	  int si = 0;
	  int x;
	  while (m < 2 * n - 1) {
		  i = 0;
		  while (i < n) {
			  x = mt[m][i];
			  if (!find(mt, n, m, i)) {
				  s[si] = x;
				  si++;
			  }
			  i++;
		  }
		  m++;
	  }
	  quicksort(s, 0, s.length - 1);
	  return s;
  }
  
  public static boolean find(int[][] t, int n, int toFindL, int toFindP) {
	  int i = 0;
	  int m = 0;
	  while (m < 2 * n - 1) {
		  i = 0;
		  while (i < n) {
			  if ((toFindL != m || toFindP != i) && t[m][i] == t[toFindL][toFindP]) {
				  t[m][i] = -1;
				  t[toFindL][toFindP] = -1;
				  return true;
			  }
			  i++;
		  }
		  m++;
	  }
	  return false;
  }
  
  public static int[][] copy(int[][] t, int n) {
	  int[][] mt = new int[2 * n - 1][n];
	  int i = 0;
	  int m = 0;
	  while (m < 2 * n - 1) {
		  i = 0;
		  while (i < n) {
			  mt[m][i] = t[m][i];
			  i++;
		  }
		  m++;
	  }
	  return mt;
  }
  
  public static int[][] loadCase(Scanner in, int n) {
	  int[][] s = new int[2 * n - 1][n];
	  int i = 0;
	  int m = 0;
	  while (m < 2 * n - 1) {
		  i = 0;
		  while (i < n) {
			  s[m][i] = in.nextInt();
			  i++;
		  }
		  m++;
	  }
	  return s;
  }
  
  public static void quicksort(int n[], int left, int right) {
	  if (left >= right) return;
	  int l = left, r = right, m = n[left];
      while (l < r) {
          while (l < r && n[r] >= m) r--;
          if (l < r) n[l++] = n[r];
          while (l < r && n[l] <= m) l++;
          if (l < r) n[r--] = n[l];
      }
      n[l] = m;
      quicksort(n, left, l - 1);
      quicksort(n, l + 1, right);
  }

}