import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int testCaseCount = Integer.parseInt(input.nextLine());
		for(int testCase=1; testCase <= testCaseCount; testCase++) {			
			String[] values = input.nextLine().split(" ");
			
			int kinds = Integer.parseInt(values[0]);
			int kindsPerPack = Integer.parseInt(values[1]);
			
			double packs = 0;
			double collected = 0;
			while(collected < kinds) {
				double probOfUniqueCard = (kinds - collected) *  kindsPerPack / kinds;
				double pack = 1 / probOfUniqueCard;
				
				packs += pack;
				collected += pack * kindsPerPack;
			}
			
			System.out.println("Case #"+testCase+": "+packs);
		}
	}
}
