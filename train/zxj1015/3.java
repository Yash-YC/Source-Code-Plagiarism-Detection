import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.BigDecimal;

public class Main {
	
	public static void main(String[] args) {
		init();
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		int[] nexts = new int[1100];
		for (int i = 0; i < cases; ++i) {
			int n = scanner.nextInt();
			for (int j = 0; j < n; ++j) {
				nexts[j + 1] = scanner.nextInt();
			}
			int result = Math.max(process(nexts, n), process2(nexts, n));
			System.out.printf("Case #%d: %d\n", i + 1, result);
		}
	}
	
	public static int process(int[] nexts, int n) {
		int max = 0;
		for (int i = 1; i <= n; ++i) {
			Map<Integer, Integer> map = new HashMap<Integer, Integer>();
			int start = i;
			int step = 1;
			map.put(start, step);
			while (true) {
				start = nexts[start];
				++step;
				//System.out.println(start + " " + step);
				if (map.containsKey(start)) {
					max = Math.max(step - map.get(start), max);
					break;
				}
				map.put(start, step);
			}
		}
		return max;
	}
	
	public static int process2(int[] nexts, int n) {
		Map<Integer, Integer> friends = new HashMap<Integer, Integer>();
		for (int i = 1; i <= n; ++i) {
			if (i == nexts[nexts[i]]) {
				friends.put(i, nexts[i]);
				//System.out.println(i + "===" + nexts[i]);
			}
		}
		Map<Integer, LinkedList<Integer>> prev = new HashMap<Integer, LinkedList<Integer>>();
		for (int i = 1; i <= n; ++i) {
			if (friends.containsKey(i) && friends.get(i).equals(nexts[i])) {
				continue;
			}
			if (prev.containsKey(nexts[i])) {
				prev.get(nexts[i]).add(i);
			} else {
				LinkedList<Integer> list = new LinkedList<Integer>();
				list.add(i);
				prev.put(nexts[i], list);
			}
		}
		int[] length = new int[1100];
		boolean[] visited = new boolean[1100];
		for (int i = 1; i <= n; ++i) {
			if (visited[i] == true) {
				continue;
			}
			//System.out.println("========" + i);
			Dfs(i, prev, length, visited);
		}
		
		/*for (Map.Entry<Integer, LinkedList<Integer>> entry : prev.entrySet()) {
			System.out.println(entry.getKey() + "=" + entry.getValue().toString());
		}*/
		
	/*	for (int i = 1; i <= n; ++i) {
			System.out.println(i + "=" + length[i]);
		}*/
		
		int max = 0;
		for (Map.Entry<Integer, Integer> ele : friends.entrySet()) {
			max = Math.max(length[ele.getKey()] + length[ele.getValue()], max);
		}
		return max;
	}
	
	public static void Dfs(int start, Map<Integer, LinkedList<Integer>> prev, 
			               int[] length, boolean[] visited) {
		visited[start] = true;
		if (!prev.containsKey(start)) {
			length[start] = 1;
		} else {
			int max = 1;
			LinkedList<Integer> fx = prev.get(start);
			for (int i = 0; i < fx.size(); ++i) {
				if (!visited[fx.get(i)]) {
					Dfs(fx.get(i), prev, length, visited);
				}
			}
			for (int i = 0; i < fx.size(); ++i)  {
				max = Math.max(max, length[fx.get(i)] + 1);
			}
			length[start] = max;
		}
	}

	
	
	
	
	
	public static void init() {
		FileInputStream fis = null;
		try {
			fis = new FileInputStream("/Users/zxj/Documents/workspace/Algorithm/src/test.in");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}  
        System.setIn(fis); 
	}
}

