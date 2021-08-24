import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.*;
import java.util.regex.*;
import java.math.*;

/**
 * Google Code Jam problems solved (sometimes incorrectly) by Lev. A. Neiman.
 * @author Entheogen
 * 
 */
public class Problems
{
	
	public interface problem
	{
		public void solve(String in_file, PrintStream out) throws FileNotFoundException;
	}
	
	public static class CrossingTheRoad implements problem
	{
		
		@Override
		public void solve(String inFile, PrintStream out) throws FileNotFoundException
		{
			
		}
		
	}
	
	public static class MultiBaseHappiness implements problem
	{
		
		HashMap< Integer, String > conv_mem = new HashMap<Integer,String>();
		
		String convert( int i, int base )
		{
			int pos = base * 10 + i;
			//if( conv_mem.containsKey(pos)) return conv_mem.get(pos);
			
			String ret = "";
			
			while( i > 0 )
			{
				ret = i % base + ret;
				i /= base;
			}
			conv_mem.put( pos, ret);
			return ret;			
		}
		
		int convert( String numb, int base )
		{
			int ret= 0;
			int c = 0;
			for( int i = numb.length() - 1; i >= 0; --i )
			{
				ret += Math.pow(base, c) * (numb.charAt(i)-48);
				++c;
			}
			return ret;
		}
		
		String next_step( String str, int base)
		{
			int sum = 0;
			for( int i = 0;i < str.length();++i )
			{
				char [] t = {str.charAt(i)};
				int k = convert( new String(t), base );
				sum += k * k;			
			}
			return convert( sum, base );
		}
		
		//String step
		
		boolean isHappy( int i, int base )
		{
			String t = convert( i, base );
			HashSet<String> set = new HashSet<String>();
			while( !t.equals("1") && !set.contains(t) )
			{
				set.add(t);
				t = next_step( t, base );				
			}
			return t.equals("1");
		}
		
		static int lim = (int)1e5;
		static boolean [][] happiness = new boolean[lim][11];
		
		void precomptue()
		{
			for( int base = 2; base <=10; ++base )
			{
				for( int i = 2; i < lim; ++i )
				{
					happiness[i][base]=isHappy(i,base);
				}
			}
			System.out.println( "done precomputing");
		}
		
		int findHappy( ArrayList<Integer> bases )
		{
			int ret = 0;
			
			for( int i = 2; i < lim; ++i )
			{
				boolean isgood = true;
				for( Integer k : bases )
				{
					if( ! happiness[i][k])
					{
						isgood=false;
						break;
					}
				}
				if( isgood ) return i;
			}
			
			return ret;
		}
		
		
		@Override
		public void solve(String inFile, PrintStream out) throws FileNotFoundException
		{
			precomptue();
			Scanner in = new Scanner(new File(inFile));
			int T = in.nextInt();
			in.nextLine();
			for( int case_num = 1; case_num <= T; ++case_num )
			{
				String line = in.nextLine();
				ArrayList<Integer> bases = new ArrayList<Integer>();
				StringTokenizer tokenizer = new StringTokenizer(line, " ");
				while (tokenizer.hasMoreTokens())
				{
					bases.add(Integer.parseInt(tokenizer.nextToken()));
				}
				out.println( "Case #" + case_num + ": " + findHappy( bases ));
				System.out.println( convert( 82, 10 ));
			//    System.out.println( convert( "82", 10 ));
				//System.out.println( isHappy( 51, 2));
			//	System.out.println( next_step( "82",10));
			}
			
		}
		
	}
	
	public static class CollectingCards implements problem
	{
		
		@Override
		public void solve(String inFile, PrintStream out) throws FileNotFoundException
		{
			Scanner in = new Scanner(new File(inFile));
			
		}
		
	}
	
	public static class CheatingABooleanTree implements problem
	{
		
		public static class node
		{
			int op;
			boolean change;
			node left = null, right = null;
			node parent = null;
			boolean leaf;
			int leaf_val;
			
			int min_flips[] = new int[2];
			
			public node()
			{
				min_flips[0] = min_flips[1] = -1;
			}
			
			public void addChild(node n)
			{
				if (left == null)
					left = n;
				else
					right = n;
				n.parent = this;
			}
			
			public int comp()
			{
				if (leaf)
					return leaf_val;
				return op == 1 ? left.comp() & right.comp() : left.comp() | right.comp();
			}
			
			public int min_flips(int desired)
			{
				if (comp() == desired)
					return 0;
				if (leaf && desired != leaf_val)
					return 1;
				else if (leaf)
					return 0;
				
				int ret = 0;
				int left_min = left.min_flips(desired);
				int right_min = right.min_flips(desired);
				int n_left_min = left.min_flips(desired == 0 ? 1 : 0);
				int n_right_min = left.min_flips(desired == 0 ? 1 : 0);
				
				if (desired == 0 && op == 0)
				{
					if (!change)
					{
						ret = left_min + right_min;
					}
					else
					{
						ret = Math.min(1 + left_min, 1 + right_min);
					}
				}
				if (desired == 0 && op == 1)
				{
					ret = Math.min(left_min, right_min);
				}
				if (desired == 1 && op == 1)
				{
					if (!change)
					{
						ret = left_min + right_min;
					}
					else
					{
						ret = Math.min(1 + left_min, 1 + right_min);
					}
				}
				if (desired == 1 && op == 0)
				{
					ret = Math.min(left_min, right_min);
				}
				
				//	if( ret == 0) return Integer.MAX_VALUE;
				return ret;
			}
			
		}
		
		@Override
		public void solve(String inFile, PrintStream out) throws FileNotFoundException
		{
			Scanner in = new Scanner(new File(inFile));
			int N = in.nextInt();
			for( int case_num = 1; case_num <= N; ++case_num )
			{
				System.out.println("Case # " + case_num);
				int M, V;
				M = in.nextInt();
				V = in.nextInt();
				node[] nodes = new node[M];
				node V_NODE;
				node cur = null;
				int i;
				for( i = 0; i < (M - 1) / 2; ++i )
				{
					nodes[i] = new node();
					
					nodes[i].leaf = false;
					
					int G, C;
					G = in.nextInt();
					C = in.nextInt();
					
					nodes[i].change = C == 1 ? true : false;
					nodes[i].op = G;
					
					if (i > 0)
					{
						int parent = (i - 1) / 2;
						nodes[parent].addChild(nodes[i]);
					}
				}
				for( ; i < M; ++i )
				{
					nodes[i] = new node();
					nodes[i].leaf = true;
					nodes[i].leaf_val = in.nextInt();
					int parent = (i - 1) / 2;
					nodes[parent].addChild(nodes[i]);
				}
				
				int ret = nodes[0].min_flips(V);
				out.println("Case #" + case_num + ": " + (ret == Integer.MAX_VALUE ? "IMPOSSIBLE" : ((ret - 1) % Integer.MAX_VALUE)));
			}
			
		}
		
	}
	
	public static class UglyNumbers implements problem
	{
		
		@Override
		public void solve(String inFile, PrintStream out) throws FileNotFoundException
		{
			Scanner in = new Scanner(new File(inFile));
			int N = in.nextInt();
			in.nextLine();
			for( int case_num = 1; case_num <= N; ++case_num )
			{
				String num = in.nextLine();
				System.out.println(num);
			}
		}
		
	}
	
	public static class TextMessagingOutrage implements problem
	{
		
		@Override
		public void solve(String inFile, PrintStream out) throws FileNotFoundException
		{
			Scanner in = new Scanner(new File(inFile));
			int N = in.nextInt();
			for( int case_num = 1; case_num <= N; ++case_num )
			{
				int P = in.nextInt();
				int K = in.nextInt();
				int L = in.nextInt();
				long[] freq = new long[L];
				for( int i = 0; i < L; ++i )
					freq[i] = in.nextLong();
				long min_presses = 0;
				Arrays.sort(freq);
				int mult = 1;
				int k = 0;
				for( int i = freq.length - 1; i >= 0; --i )
				{
					min_presses += freq[i] * mult;
					
					if (++k % K == 0)
						mult++;
				}
				out.println("Case #" + case_num + ": " + min_presses);
			}
			
		}
		
	}
	
	public static class Watersheds implements problem
	{
		//Map<Character,List<Character>> same_basins = new HashMap<Character,List<Character>>();
		Map<Character, Character> replace = new HashMap<Character, Character>();
		
		int D[][] =
		{
				{
						0, -1
				},
				{
						-1, 0
				},
				{
						1, 0
				},
				{
						0, 1
				}
		};
		
		void DFS(int[][] board, char[][] drains, int x, int y, char cur_char)
		{
			drains[x][y] = cur_char;
			int next_move[] = next_drain(board, drains, x, y);
			//System.out.println( x + " " + y);
			//System.out.println( next_move[0] + " " + next_move[1]);
			//System.out.println( " ============ ");
			if (next_move[0] == x && next_move[1] == y)
			{
				//System.out.println( "omg");
				return;
			}
			char drain = drains[next_move[0]][next_move[1]];
			if (drain == '.')
			{
				DFS(board, drains, next_move[0], next_move[1], cur_char);
			}
			else if (drain == cur_char)
				return;
			else
			{
				/*
				if( !same_basins.containsKey(drain)) {
					same_basins.put(drain, new ArrayList<Character>());
				}
				same_basins.get(drain).add(cur_char);
				*/
				//System.out.println( "")
				//drains[x][y]=drain;
				replace.put(cur_char, drain);
			}
		}
		
		void trim_replace()
		{
			Map<Character, Character> rep_replace = new HashMap<Character, Character>();
			for( Character c : replace.keySet() )
			{
				char new_replace = c;
				while (replace.containsKey(new_replace))
				{
					new_replace = replace.get(new_replace);
				}
				
				rep_replace.put(c, new_replace);
			}
			replace = rep_replace;
		}
		
		void sort_replace(char drains[][], int W, int H)
		{
			for( int y = 0; y < H; ++y )
			{
				for( int x = 0; x < W; ++x )
				{
					Character c = replace.get(drains[x][y]);
					c = c == null ? drains[x][y] : c;
					drains[x][y] = c;
				}
			}
			Map<Character, Character> rep_replace = new HashMap<Character, Character>();
			char largest = 'a';
			for( int y = 0; y < H; ++y )
			{
				for( int x = 0; x < W; ++x )
				{
					if (drains[x][y] > largest && !rep_replace.containsKey(drains[x][y]))
					{
						rep_replace.put(drains[x][y], ++largest);
					}
				}
			}
			replace = rep_replace;
		}
		
		int[] next_drain(int[][] board, char[][] drains, int x, int y)
		{
			int nx = x, ny = y;
			int min_drain = board[x][y];
			for( int d = 0; d < D.length; ++d )
			{
				int tx = x + D[d][0];
				int ty = y + D[d][1];
				
				if (tx < 0 || tx >= board.length || ty < 0 || ty >= board[0].length)
					continue;
				
				if (min_drain > board[tx][ty])
				{
					min_drain = board[tx][ty];
					nx = tx;
					ny = ty;
				}
			}
			//System.out.println( x + " " + y);
			//System.out.println( nx+ " " + ny);
			int[] ret =
			{
					nx, ny
			};
			return ret;
		}
		
		@Override
		public void solve(String inFile, PrintStream out) throws FileNotFoundException
		{
			Scanner in = new Scanner(new File(inFile));
			
			int num_maps = in.nextInt();
			for( int case_num = 1; case_num <= num_maps; ++case_num )
			{
				replace.clear();
				//System.out.println( "==============");
				int H, W;
				int[][] board;
				char[][] drains;
				H = in.nextInt();
				W = in.nextInt();
				board = new int[W][H];
				drains = new char[W][H];
				for( int h = 0; h < H; ++h )
				{
					for( int w = 0; w < W; ++w )
					{
						board[w][h] = in.nextInt();
						drains[w][h] = '.';
					}
				}
				//drains[0][0] = 'a';
				char cur_drain = '`';
				for( int y = 0; y < H; ++y )
				{
					for( int x = 0; x < W; ++x )
					{
						if (drains[x][y] != '.')
							continue;
						DFS(board, drains, x, y, ++cur_drain);
						
					}
					
				}
				
				trim_replace();
				sort_replace(drains, W, H);
				
				out.println("Case #" + case_num + ":");
				for( int y = 0; y < H; ++y )
				{
					for( int x = 0; x < W; ++x )
					{
						Character p_char = replace.get(drains[x][y]);
						p_char = p_char == null ? drains[x][y] : p_char;
						out.print(p_char + " ");
						//System.out.println( drains[x][y] + "==>" + p_char);
					}
					out.print("\n");
					
				}
				
			}
			
		}
		
	}
	
	public static class WelcomeToCodeJam implements problem
	{
		public static final String welcome = "welcome to code jam";
		
		long mem[][];
		
		long dfs(String text, int pos, int cons)
		{
			if (mem[pos][cons] != -1)
				return mem[pos][cons];
			if (cons == welcome.length() - 1 && text.charAt(pos) == 'm')
				return 1;
			long ret = 0;
			for( int i = pos + 1; i < text.length(); ++i )
			{
				if (text.charAt(i) == welcome.charAt(cons + 1))
				{
					//System.out.println( "yay");
					ret += dfs(text, i, cons + 1) % 10000;
				}
			}
			ret = ret % 10000;
			mem[pos][cons] = ret % 10000;
			return ret;
		}
		
		long solve(String text)
		{
			long ret = 0;
			mem = new long[text.length()][welcome.length()];
			for( int i = 0; i < mem.length; ++i )
				for( int j = 0; j < welcome.length(); ++j )
					mem[i][j] = -1;
			for( int i = 0; i < text.length(); ++i )
			{
				if (text.charAt(i) == 'w')
				{
					ret += dfs(text, i, 0);
					
				}
			}
			return ret;
		}
		
		long solve_iterative(String text)
		{
			long ret = 0;
			
			mem = new long[text.length()][welcome.length()];
			for( int i = 0; i < text.length(); ++i )
				for( int j = 0; j < welcome.length(); ++j )
					mem[i][j] = 0;
			for( int i = 0; i < text.length(); ++i )
				if (text.charAt(i) == 'w')
					mem[i][0] = 1;
			
			for( int i = 0; i < text.length(); ++i )
			{
				for( int j = 1; j < welcome.length(); ++j )
				{
					if (text.charAt(i) == welcome.charAt(j))
					{
						for( int k = 0; k < i; ++k )
						{
							mem[i][j] += mem[k][j - 1] % 10000;
						}
						if (j == welcome.length() - 1)
							ret += mem[i][j] % 10000;
						ret = ret % 10000;
					}
				}
			}
			for( int i = 0; i < text.length(); ++i )
			{
				for( int j = 0; j < welcome.length(); ++j )
				{
					//System.out.print( mem[i][j] + " ");
				}
				//System.out.print( "\n");
			}
			return ret;
		}
		
		String beautify(Long num)
		{
			String ret = num.toString();
			if (ret.length() > 4)
				return ret.substring(ret.length() - 4);
			
			while (ret.length() != 4)
				ret = '0' + ret;
			
			return ret;
		}
		
		@Override
		public void solve(String inFile, PrintStream out) throws FileNotFoundException
		{
			Scanner in = new Scanner(new File(inFile));
			
			String t;
			t = in.nextLine();
			int num_cases = Integer.parseInt(t);
			for( int case_num = 1; case_num <= num_cases; ++case_num )
			{
				System.out.println("========== " + case_num + " ===========");
				String line = in.nextLine();
				out.println("Case #" + case_num + ": " + beautify(solve_iterative(line)));
			}
			
		}
		
	}
	
	public static class AlienLanguage implements problem
	{
		
		@Override
		public void solve(String inFile, PrintStream out) throws FileNotFoundException
		{
			Scanner in = new Scanner(new File(inFile));
			int L, D, N;
			
			L = in.nextInt();
			D = in.nextInt();
			N = in.nextInt();
			in.nextLine();
			ArrayList<String> words = new ArrayList<String>();
			
			for( int i = 0; i < D; ++i )
			{
				words.add(in.nextLine());
				//System.out.println( "Added word " + words.get(words.size() -1 ));
			}
			for( int i = 1; i <= N; ++i )
			{
				String pattern = in.nextLine();
				pattern = pattern.replace('(', '[');
				pattern = pattern.replace(')', ']');
				//System.out.println( "case pattern = " + pattern);
				Pattern p_pattern = Pattern.compile(pattern);
				
				int num_match = 0;
				for( int j = 0; j < words.size(); ++j )
				{
					Matcher m = p_pattern.matcher(words.get(j));
					boolean matches = m.matches();
					num_match += matches ? 1 : 0;
					//System.out.println( words.get(j) + " matches = " + matches);
				}
				out.println("Case #" + i + ": " + num_match);
			}
			
		}
		
	}
	
	public static class MinimumScalarProduct implements problem

	{
		
		@Override
		public void solve(String in_file, PrintStream out) throws FileNotFoundException
		{
			Scanner in = new Scanner(new File(in_file));
			int num_cases = in.nextInt();
			for( int i = 0; i < num_cases; ++i )
			{
				int n = in.nextInt();
				ArrayList<Long> x = new ArrayList<Long>(n);
				ArrayList<Long> y = new ArrayList<Long>(n);
				for( int k = 0; k < n; ++k )
				{
					x.add(in.nextLong());
				}
				for( int k = 0; k < n; ++k )
				{
					y.add(in.nextLong());
				}
				
				Collections.sort(x);
				Collections.sort(y);
				Collections.reverse(y);
				long ret = 0;
				for( int k = 0; k < n; ++k )
				{
					ret += x.get(k) * y.get(k);
				}
				out.println("Case #" + (i + 1) + ": " + ret);
			}
		}
		
	}
	
	public static class Numbers implements problem
	{
		
		@Override
		public void solve(String inFile, PrintStream out) throws FileNotFoundException
		{
			Scanner in = new Scanner(new File(inFile));
			int num_cases = in.nextInt();
			BigDecimal r = new BigDecimal(3 + Math.sqrt(5), new MathContext(1 << 30, RoundingMode.CEILING));
			double rd = 3 + Math.sqrt(5);
			for( int kase = 1; kase <= num_cases; ++kase )
			{
				int n = in.nextInt();
				
				BigDecimal ans = r.pow(n);
				double ansd = Math.pow(rd, (double) n);
				String ret = ans.toPlainString();
				//String ret = Double.toString(ansd);
				ret = ret.substring(0, ret.indexOf('.'));
				if (ret.length() == 1)
					ret = "00" + ret;
				if (ret.length() == 2)
					ret = "0" + ret;
				if (ret.length() > 3)
					ret = ret.substring(ret.length() - 3);
				out.println("Case #" + kase + ": " + ret);
			}
			
		}
		
	}
	
	public static class MilkShakes implements problem
	{
		
		public static class Customer
		{
			public Set<Integer> likes = new HashSet<Integer>();
			public int malt = -1;
			
			public boolean satisfies(boolean m[])
			{
				for( int i = 1; i <= m.length; ++i )
				{
					if (likes.contains(i) && malt == i && m[i - 1])
						return true;
					if (likes.contains(i) && malt != i && !m[i - 1])
						return true;
				}
				return false;
			}
			
			public boolean satisfies(int milkshake, boolean malted)
			{
				if (!likes.contains(milkshake))
					return false;
				
				if (malted)
				{
					if (malt == milkshake)
						return true;
					return false;
				}
				return true;
			}
			
			public String toString()
			{
				String ret = "";
				ret = "customer likes: ";
				for( Integer i : likes )
				{
					ret += i + " ";
				}
				ret += " malt: " + malt;
				return ret;
			}
		}
		
		String printBoolean(boolean[] arr)
		{
			String ret = "";
			for( int i = 0; i < arr.length; ++i )
			{
				ret += arr[i] ? "1 " : "0 ";
			}
			return ret;
		}
		
		boolean[] solve(ArrayList<Customer> customers, int num_milkshakes)
		{
			int n = (1 << num_milkshakes) - 1;
			//System.out.println( n);
			boolean ret[] = new boolean[num_milkshakes];
			for( int i = 0; i <= n; ++i )
			{
				for( int k = 0; k < num_milkshakes; ++k )
				{
					ret[k] = (i & (1 << k)) != 0;
				}
				//System.out.println( i );
				//System.out.println( printBoolean(ret) );
				boolean good = true;
				for( Customer cust : customers )
				{
					boolean t = cust.satisfies(ret);
					//System.out.println( cust );
					//System.out.println( t );
					if (!t)
					{
						good = false;
						break;
					}
				}
				if (good)
					return ret;
			}
			return null;
		}
		
		boolean[] solve2(ArrayList<Customer> customers, int num_milkshakes)
		{
			/*
			HashSet<Integer> unmalted[] = new HashSet[num_milkshakes];
			HashSet<Integer> malted[] = new HashSet[num_milkshakes];
			
			for( int i = 0; i < num_milkshakes; ++i )
			{
				unmalted[i] =  new HashSet<Integer>();
				malted[i] = new HashSet<Integer>();
			}
			
			for( int i = 0; i < customers.size(); ++i )
			{
				for( int k = 0; k < num_milkshakes; ++k )
				{
					if( customers.get(i).satisfies(k, false) ) unmalted[k].add(i);
					if( customers.get(i).satisfies(k, true )) malted[k].add(i);
				}
			}
			*/

			boolean[] ret = new boolean[num_milkshakes];
			for( int i = 0; i < num_milkshakes; ++i )
				ret[i] = false;
			while (true)
			{
				boolean ok = true;
				for( int i = 0; i < customers.size(); ++i )
				{
					boolean s = customers.get(i).satisfies(ret);
					if (!s)
					{
						if (customers.get(i).malt == -1)
							return null;
						ret[customers.get(i).malt - 1] = true;
						customers.remove(i);
						ok = false;
						break;
						
					}
				}
				if (ok)
					break;
			}
			
			return ret;
			
		}
		
		@Override
		public void solve(String inFile, PrintStream out) throws FileNotFoundException
		{
			Scanner in = new Scanner(new File(inFile));
			
			int num_cases = in.nextInt();
			for( int kase = 1; kase <= num_cases; ++kase )
			{
				int N = in.nextInt();
				int M = in.nextInt();
				ArrayList<Customer> customers = new ArrayList<Customer>();
				for( int i = 0; i < M; ++i )
				{
					int T = in.nextInt();
					Customer cust = new Customer();
					for( int k = 0; k < T; ++k )
					{
						int m = in.nextInt();
						int mm = in.nextInt();
						cust.likes.add(m);
						if (mm == 1)
						{
							cust.malt = m;
						}
						else
						{
							if (cust.malt == m)
								cust.malt = -1;
						}
					}
					customers.add(cust);
				}
				boolean solution[] = solve2(customers, N);
				out.println("Case #" + kase + ": " + (solution == null ? "IMPOSSIBLE" : printBoolean(solution)));
				
			}
			
		}
		
	}
	
	public static String Stream2String(InputStream is) throws IOException
	{
		String ret = "";
		while (is.available() > 0)
		{
			byte[] buff = new byte[is.available()];
			is.read(buff);
			String t = new String(buff);
			ret += t;
		}
		return ret;
	}
	
	public static void solve(problem prob, String input_file, String output_file) throws IOException
	{
		FileOutputStream ofs = new FileOutputStream(output_file);
		PrintStream out = new PrintStream(ofs);
		
		prob.solve(input_file, out);
		
	}
	
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		try
		{
			solve(new MultiBaseHappiness(), "A-small-practice.in", "output.txt");
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		
	}
	
}
