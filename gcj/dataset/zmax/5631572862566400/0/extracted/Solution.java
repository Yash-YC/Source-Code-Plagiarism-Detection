package bestFriendForever;

import java.util.*;

public class Solution {

	public static int maxCircle(int N, int[] bff){
		
		HashSet<Integer> checkedID = new HashSet<Integer>();
		HashSet<Integer> idInCircle = new HashSet<Integer>();
		ArrayList<Integer> circle = new ArrayList<Integer>();
		int maxCircleLength = 0;
		int currentCircleLength = 0;
		int currentMaxLength = 0;
		
		for(int i=1;i<=N;i++){
			if(checkedID.contains(i)){
				continue;
			}
			if(currentCircleLength == 0){
				circle = new ArrayList<Integer>();
				idInCircle = new HashSet<Integer>();
			}
			
			int id = i;
			
			while(true){
				//System.out.println("id: " + id);
				circle.add(id);
				currentCircleLength++;
				idInCircle.add(id);
				//checkedID.add(i);
				int bffid = bff[id-1];
				//System.out.println("bff id: " + bffid);
				if(idInCircle.contains(bffid)){
					if(bffid == circle.get(0)){
						//the circle finishes
						for(int elem: idInCircle){
							checkedID.add(elem);
						}
						if(currentCircleLength > maxCircleLength){
							maxCircleLength = currentCircleLength;
						}
						currentCircleLength = 0;
						break;
					}
					else if(currentCircleLength-2>=0 && bffid == circle.get(currentCircleLength-2)){
						currentMaxLength = currentCircleLength;
						if(currentMaxLength > maxCircleLength){
							maxCircleLength = currentMaxLength;
						}
						for(int elem: idInCircle){
							checkedID.add(elem);
						}
						break;
					}
					else{
						if(currentMaxLength ==0){
							currentCircleLength = 0;
						}
						else{
							for(int k=0;k<currentCircleLength-currentMaxLength;k++){
								int e = circle.remove(circle.size()-1);
								idInCircle.remove(e);
							}
							currentCircleLength = currentMaxLength;
						}
						break;
					}
				}
				else{
					id = bffid;
				}
				
			}
			
			
			
		}
		
		
		return maxCircleLength;
	}
	/*
	public static int maxCircleStartFrom(int N, int[] bff, int start){
		//start is from 1 to N
		int id = start;
		int checkNum = 0;
		int numInCircle = 0;
		HashSet<Integer> checkedID = new HashSet<Integer>();
		ArrayList<Integer> circle = new ArrayList<Integer>();
		
		while(checkNum < N){
			if((id%N)==0){
				id = N;
			}
			else{
				id = id%N;
			}
			checkNum++;
			
			if(numInCircle == 0){
				
			}
		}
		
		
		return 0;
	}
	*/
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for(int i=1;i<=testNum;i++){
			int N = scan.nextInt();
			int[] bff = new int[N];
			for(int j=0;j<N;j++){
				bff[j] = scan.nextInt();
			}
			int maxSize = Solution.maxCircle(N, bff);
			System.out.printf("Case #%d: %d\n", i, maxSize);
		}
		scan.close();

	}

}
