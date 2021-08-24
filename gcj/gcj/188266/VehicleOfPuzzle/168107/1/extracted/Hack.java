import java.io.*;
import java.util.*;

public class Hack {
	public static void main(String[] arg) throws Throwable {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= t; ++tc) {
			System.out.print("Case #" + tc + ": ");
			String[] bases = br.readLine().split(" ");
			int[] b = new int[bases.length];
			Arrays.sort(b);
			for(int i = 0; i != bases.length; ++i) b[i] = Integer.parseInt(bases[i]);
			System.out.println(solve(Arrays.toString(b).replaceAll("[\\[\\]\\,]", "")));
		}
	}
	
	static int solve(String s) {
		if(s.equals("10")) return 7;
		if(s.equals("9")) return 3;
		if(s.equals("9 10")) return 91;
		if(s.equals("8")) return 8;
		if(s.equals("8 10")) return 97;
		if(s.equals("8 9")) return 27;
		if(s.equals("8 9 10")) return 1177;
		if(s.equals("7")) return 7;
		if(s.equals("7 10")) return 7;
		if(s.equals("7 9")) return 125;
		if(s.equals("7 9 10")) return 1337;
		if(s.equals("7 8")) return 1001;
		if(s.equals("7 8 10")) return 34527;
		if(s.equals("7 8 9")) return 6393;
		if(s.equals("7 8 9 10")) return 48041;
		if(s.equals("6")) return 6;
		if(s.equals("6 10")) return 44;
		if(s.equals("6 9")) return 415;
		if(s.equals("6 9 10")) return 1033;
		if(s.equals("6 8")) return 216;
		if(s.equals("6 8 10")) return 608;
		if(s.equals("6 8 9")) return 4977;
		if(s.equals("6 8 9 10")) return 9867;
		if(s.equals("6 7")) return 49;
		if(s.equals("6 7 10")) return 49;
		if(s.equals("6 7 9")) return 2753;
		if(s.equals("6 7 9 10")) return 71735;
		if(s.equals("6 7 8")) return 47089;
		if(s.equals("6 7 8 10")) return 245035;
		if(s.equals("6 7 8 9")) return 569669;
		if(s.equals("6 7 8 9 10")) return 2662657;
		if(s.equals("5")) return 5;
		if(s.equals("5 10")) return 7;
		if(s.equals("5 9")) return 27;
		if(s.equals("5 9 10")) return 91;
		if(s.equals("5 8")) return 27;
		if(s.equals("5 8 10")) return 219;
		if(s.equals("5 8 9")) return 27;
		if(s.equals("5 8 9 10")) return 1177;
		if(s.equals("5 7")) return 7;
		if(s.equals("5 7 10")) return 7;
		if(s.equals("5 7 9")) return 125;
		if(s.equals("5 7 9 10")) return 29913;
		if(s.equals("5 7 8")) return 1001;
		if(s.equals("5 7 8 10")) return 34527;
		if(s.equals("5 7 8 9")) return 6393;
		if(s.equals("5 7 8 9 10")) return 246297;
		if(s.equals("5 6")) return 49;
		if(s.equals("5 6 10")) return 49;
		if(s.equals("5 6 9")) return 415;
		if(s.equals("5 6 9 10")) return 4577;
		if(s.equals("5 6 8")) return 1975;
		if(s.equals("5 6 8 10")) return 3879;
		if(s.equals("5 6 8 9")) return 4977;
		if(s.equals("5 6 8 9 10")) return 28099;
		if(s.equals("5 6 7")) return 49;
		if(s.equals("5 6 7 10")) return 49;
		if(s.equals("5 6 7 9")) return 37131;
		if(s.equals("5 6 7 9 10")) return 218301;
		if(s.equals("5 6 7 8")) return 48769;
		if(s.equals("5 6 7 8 10")) return 245035;
		if(s.equals("5 6 7 8 9")) return 569669;
		if(s.equals("5 6 7 8 9 10")) return 11814485;
		if(s.equals("4")) return 2;
		if(s.equals("4 10")) return 7;
		if(s.equals("4 9")) return 3;
		if(s.equals("4 9 10")) return 91;
		if(s.equals("4 8")) return 8;
		if(s.equals("4 8 10")) return 97;
		if(s.equals("4 8 9")) return 27;
		if(s.equals("4 8 9 10")) return 1177;
		if(s.equals("4 7")) return 7;
		if(s.equals("4 7 10")) return 7;
		if(s.equals("4 7 9")) return 125;
		if(s.equals("4 7 9 10")) return 1337;
		if(s.equals("4 7 8")) return 1001;
		if(s.equals("4 7 8 10")) return 34527;
		if(s.equals("4 7 8 9")) return 6393;
		if(s.equals("4 7 8 9 10")) return 48041;
		if(s.equals("4 6")) return 6;
		if(s.equals("4 6 10")) return 44;
		if(s.equals("4 6 9")) return 415;
		if(s.equals("4 6 9 10")) return 1033;
		if(s.equals("4 6 8")) return 216;
		if(s.equals("4 6 8 10")) return 608;
		if(s.equals("4 6 8 9")) return 4977;
		if(s.equals("4 6 8 9 10")) return 9867;
		if(s.equals("4 6 7")) return 49;
		if(s.equals("4 6 7 10")) return 49;
		if(s.equals("4 6 7 9")) return 2753;
		if(s.equals("4 6 7 9 10")) return 71735;
		if(s.equals("4 6 7 8")) return 47089;
		if(s.equals("4 6 7 8 10")) return 245035;
		if(s.equals("4 6 7 8 9")) return 569669;
		if(s.equals("4 6 7 8 9 10")) return 2662657;
		if(s.equals("4 5")) return 5;
		if(s.equals("4 5 10")) return 7;
		if(s.equals("4 5 9")) return 27;
		if(s.equals("4 5 9 10")) return 91;
		if(s.equals("4 5 8")) return 27;
		if(s.equals("4 5 8 10")) return 219;
		if(s.equals("4 5 8 9")) return 27;
		if(s.equals("4 5 8 9 10")) return 1177;
		if(s.equals("4 5 7")) return 7;
		if(s.equals("4 5 7 10")) return 7;
		if(s.equals("4 5 7 9")) return 125;
		if(s.equals("4 5 7 9 10")) return 29913;
		if(s.equals("4 5 7 8")) return 1001;
		if(s.equals("4 5 7 8 10")) return 34527;
		if(s.equals("4 5 7 8 9")) return 6393;
		if(s.equals("4 5 7 8 9 10")) return 246297;
		if(s.equals("4 5 6")) return 49;
		if(s.equals("4 5 6 10")) return 49;
		if(s.equals("4 5 6 9")) return 415;
		if(s.equals("4 5 6 9 10")) return 4577;
		if(s.equals("4 5 6 8")) return 1975;
		if(s.equals("4 5 6 8 10")) return 3879;
		if(s.equals("4 5 6 8 9")) return 4977;
		if(s.equals("4 5 6 8 9 10")) return 28099;
		if(s.equals("4 5 6 7")) return 49;
		if(s.equals("4 5 6 7 10")) return 49;
		if(s.equals("4 5 6 7 9")) return 37131;
		if(s.equals("4 5 6 7 9 10")) return 218301;
		if(s.equals("4 5 6 7 8")) return 48769;
		if(s.equals("4 5 6 7 8 10")) return 245035;
		if(s.equals("4 5 6 7 8 9")) return 569669;
		if(s.equals("4 5 6 7 8 9 10")) return 11814485;
		if(s.equals("3")) return 3;
		if(s.equals("3 10")) return 13;
		if(s.equals("3 9")) return 3;
		if(s.equals("3 9 10")) return 91;
		if(s.equals("3 8")) return 27;
		if(s.equals("3 8 10")) return 219;
		if(s.equals("3 8 9")) return 27;
		if(s.equals("3 8 9 10")) return 1177;
		if(s.equals("3 7")) return 143;
		if(s.equals("3 7 10")) return 167;
		if(s.equals("3 7 9")) return 143;
		if(s.equals("3 7 9 10")) return 1337;
		if(s.equals("3 7 8")) return 5719;
		if(s.equals("3 7 8 10")) return 48041;
		if(s.equals("3 7 8 9")) return 35785;
		if(s.equals("3 7 8 9 10")) return 48041;
		if(s.equals("3 6")) return 79;
		if(s.equals("3 6 10")) return 79;
		if(s.equals("3 6 9")) return 707;
		if(s.equals("3 6 9 10")) return 6073;
		if(s.equals("3 6 8")) return 3879;
		if(s.equals("3 6 8 10")) return 3879;
		if(s.equals("3 6 8 9")) return 10089;
		if(s.equals("3 6 8 9 10")) return 28099;
		if(s.equals("3 6 7")) return 2207;
		if(s.equals("3 6 7 10")) return 6307;
		if(s.equals("3 6 7 9")) return 37131;
		if(s.equals("3 6 7 9 10")) return 613479;
		if(s.equals("3 6 7 8")) return 47089;
		if(s.equals("3 6 7 8 10")) return 697563;
		if(s.equals("3 6 7 8 9")) return 569669;
		if(s.equals("3 6 7 8 9 10")) return 4817803;
		if(s.equals("3 5")) return 23;
		if(s.equals("3 5 10")) return 23;
		if(s.equals("3 5 9")) return 27;
		if(s.equals("3 5 9 10")) return 91;
		if(s.equals("3 5 8")) return 27;
		if(s.equals("3 5 8 10")) return 219;
		if(s.equals("3 5 8 9")) return 27;
		if(s.equals("3 5 8 9 10")) return 1177;
		if(s.equals("3 5 7")) return 143;
		if(s.equals("3 5 7 10")) return 7895;
		if(s.equals("3 5 7 9")) return 143;
		if(s.equals("3 5 7 9 10")) return 120149;
		if(s.equals("3 5 7 8")) return 5719;
		if(s.equals("3 5 7 8 10")) return 120407;
		if(s.equals("3 5 7 8 9")) return 128821;
		if(s.equals("3 5 7 8 9 10")) return 346719;
		if(s.equals("3 5 6")) return 79;
		if(s.equals("3 5 6 10")) return 79;
		if(s.equals("3 5 6 9")) return 1695;
		if(s.equals("3 5 6 9 10")) return 6073;
		if(s.equals("3 5 6 8")) return 3879;
		if(s.equals("3 5 6 8 10")) return 3879;
		if(s.equals("3 5 6 8 9")) return 23117;
		if(s.equals("3 5 6 8 9 10")) return 28099;
		if(s.equals("3 5 6 7")) return 2207;
		if(s.equals("3 5 6 7 10")) return 7895;
		if(s.equals("3 5 6 7 9")) return 37131;
		if(s.equals("3 5 6 7 9 10")) return 711725;
		if(s.equals("3 5 6 7 8")) return 58775;
		if(s.equals("3 5 6 7 8 10")) return 2688153;
		if(s.equals("3 5 6 7 8 9")) return 569669;
		if(s.equals("3 5 6 7 8 9 10")) return 11814485;
		if(s.equals("3 4")) return 3;
		if(s.equals("3 4 10")) return 13;
		if(s.equals("3 4 9")) return 3;
		if(s.equals("3 4 9 10")) return 91;
		if(s.equals("3 4 8")) return 27;
		if(s.equals("3 4 8 10")) return 219;
		if(s.equals("3 4 8 9")) return 27;
		if(s.equals("3 4 8 9 10")) return 1177;
		if(s.equals("3 4 7")) return 143;
		if(s.equals("3 4 7 10")) return 167;
		if(s.equals("3 4 7 9")) return 143;
		if(s.equals("3 4 7 9 10")) return 1337;
		if(s.equals("3 4 7 8")) return 5719;
		if(s.equals("3 4 7 8 10")) return 48041;
		if(s.equals("3 4 7 8 9")) return 35785;
		if(s.equals("3 4 7 8 9 10")) return 48041;
		if(s.equals("3 4 6")) return 79;
		if(s.equals("3 4 6 10")) return 79;
		if(s.equals("3 4 6 9")) return 707;
		if(s.equals("3 4 6 9 10")) return 6073;
		if(s.equals("3 4 6 8")) return 3879;
		if(s.equals("3 4 6 8 10")) return 3879;
		if(s.equals("3 4 6 8 9")) return 10089;
		if(s.equals("3 4 6 8 9 10")) return 28099;
		if(s.equals("3 4 6 7")) return 2207;
		if(s.equals("3 4 6 7 10")) return 6307;
		if(s.equals("3 4 6 7 9")) return 37131;
		if(s.equals("3 4 6 7 9 10")) return 613479;
		if(s.equals("3 4 6 7 8")) return 47089;
		if(s.equals("3 4 6 7 8 10")) return 697563;
		if(s.equals("3 4 6 7 8 9")) return 569669;
		if(s.equals("3 4 6 7 8 9 10")) return 4817803;
		if(s.equals("3 4 5")) return 23;
		if(s.equals("3 4 5 10")) return 23;
		if(s.equals("3 4 5 9")) return 27;
		if(s.equals("3 4 5 9 10")) return 91;
		if(s.equals("3 4 5 8")) return 27;
		if(s.equals("3 4 5 8 10")) return 219;
		if(s.equals("3 4 5 8 9")) return 27;
		if(s.equals("3 4 5 8 9 10")) return 1177;
		if(s.equals("3 4 5 7")) return 143;
		if(s.equals("3 4 5 7 10")) return 7895;
		if(s.equals("3 4 5 7 9")) return 143;
		if(s.equals("3 4 5 7 9 10")) return 120149;
		if(s.equals("3 4 5 7 8")) return 5719;
		if(s.equals("3 4 5 7 8 10")) return 120407;
		if(s.equals("3 4 5 7 8 9")) return 128821;
		if(s.equals("3 4 5 7 8 9 10")) return 346719;
		if(s.equals("3 4 5 6")) return 79;
		if(s.equals("3 4 5 6 10")) return 79;
		if(s.equals("3 4 5 6 9")) return 1695;
		if(s.equals("3 4 5 6 9 10")) return 6073;
		if(s.equals("3 4 5 6 8")) return 3879;
		if(s.equals("3 4 5 6 8 10")) return 3879;
		if(s.equals("3 4 5 6 8 9")) return 23117;
		if(s.equals("3 4 5 6 8 9 10")) return 28099;
		if(s.equals("3 4 5 6 7")) return 2207;
		if(s.equals("3 4 5 6 7 10")) return 7895;
		if(s.equals("3 4 5 6 7 9")) return 37131;
		if(s.equals("3 4 5 6 7 9 10")) return 711725;
		if(s.equals("3 4 5 6 7 8")) return 58775;
		if(s.equals("3 4 5 6 7 8 10")) return 2688153;
		if(s.equals("3 4 5 6 7 8 9")) return 569669;
		if(s.equals("3 4 5 6 7 8 9 10")) return 11814485;
		if(s.equals("2")) return 2;
		if(s.equals("2 10")) return 7;
		if(s.equals("2 9")) return 3;
		if(s.equals("2 9 10")) return 91;
		if(s.equals("2 8")) return 8;
		if(s.equals("2 8 10")) return 97;
		if(s.equals("2 8 9")) return 27;
		if(s.equals("2 8 9 10")) return 1177;
		if(s.equals("2 7")) return 7;
		if(s.equals("2 7 10")) return 7;
		if(s.equals("2 7 9")) return 125;
		if(s.equals("2 7 9 10")) return 1337;
		if(s.equals("2 7 8")) return 1001;
		if(s.equals("2 7 8 10")) return 34527;
		if(s.equals("2 7 8 9")) return 6393;
		if(s.equals("2 7 8 9 10")) return 48041;
		if(s.equals("2 6")) return 6;
		if(s.equals("2 6 10")) return 44;
		if(s.equals("2 6 9")) return 415;
		if(s.equals("2 6 9 10")) return 1033;
		if(s.equals("2 6 8")) return 216;
		if(s.equals("2 6 8 10")) return 608;
		if(s.equals("2 6 8 9")) return 4977;
		if(s.equals("2 6 8 9 10")) return 9867;
		if(s.equals("2 6 7")) return 49;
		if(s.equals("2 6 7 10")) return 49;
		if(s.equals("2 6 7 9")) return 2753;
		if(s.equals("2 6 7 9 10")) return 71735;
		if(s.equals("2 6 7 8")) return 47089;
		if(s.equals("2 6 7 8 10")) return 245035;
		if(s.equals("2 6 7 8 9")) return 569669;
		if(s.equals("2 6 7 8 9 10")) return 2662657;
		if(s.equals("2 5")) return 5;
		if(s.equals("2 5 10")) return 7;
		if(s.equals("2 5 9")) return 27;
		if(s.equals("2 5 9 10")) return 91;
		if(s.equals("2 5 8")) return 27;
		if(s.equals("2 5 8 10")) return 219;
		if(s.equals("2 5 8 9")) return 27;
		if(s.equals("2 5 8 9 10")) return 1177;
		if(s.equals("2 5 7")) return 7;
		if(s.equals("2 5 7 10")) return 7;
		if(s.equals("2 5 7 9")) return 125;
		if(s.equals("2 5 7 9 10")) return 29913;
		if(s.equals("2 5 7 8")) return 1001;
		if(s.equals("2 5 7 8 10")) return 34527;
		if(s.equals("2 5 7 8 9")) return 6393;
		if(s.equals("2 5 7 8 9 10")) return 246297;
		if(s.equals("2 5 6")) return 49;
		if(s.equals("2 5 6 10")) return 49;
		if(s.equals("2 5 6 9")) return 415;
		if(s.equals("2 5 6 9 10")) return 4577;
		if(s.equals("2 5 6 8")) return 1975;
		if(s.equals("2 5 6 8 10")) return 3879;
		if(s.equals("2 5 6 8 9")) return 4977;
		if(s.equals("2 5 6 8 9 10")) return 28099;
		if(s.equals("2 5 6 7")) return 49;
		if(s.equals("2 5 6 7 10")) return 49;
		if(s.equals("2 5 6 7 9")) return 37131;
		if(s.equals("2 5 6 7 9 10")) return 218301;
		if(s.equals("2 5 6 7 8")) return 48769;
		if(s.equals("2 5 6 7 8 10")) return 245035;
		if(s.equals("2 5 6 7 8 9")) return 569669;
		if(s.equals("2 5 6 7 8 9 10")) return 11814485;
		if(s.equals("2 4")) return 2;
		if(s.equals("2 4 10")) return 7;
		if(s.equals("2 4 9")) return 3;
		if(s.equals("2 4 9 10")) return 91;
		if(s.equals("2 4 8")) return 8;
		if(s.equals("2 4 8 10")) return 97;
		if(s.equals("2 4 8 9")) return 27;
		if(s.equals("2 4 8 9 10")) return 1177;
		if(s.equals("2 4 7")) return 7;
		if(s.equals("2 4 7 10")) return 7;
		if(s.equals("2 4 7 9")) return 125;
		if(s.equals("2 4 7 9 10")) return 1337;
		if(s.equals("2 4 7 8")) return 1001;
		if(s.equals("2 4 7 8 10")) return 34527;
		if(s.equals("2 4 7 8 9")) return 6393;
		if(s.equals("2 4 7 8 9 10")) return 48041;
		if(s.equals("2 4 6")) return 6;
		if(s.equals("2 4 6 10")) return 44;
		if(s.equals("2 4 6 9")) return 415;
		if(s.equals("2 4 6 9 10")) return 1033;
		if(s.equals("2 4 6 8")) return 216;
		if(s.equals("2 4 6 8 10")) return 608;
		if(s.equals("2 4 6 8 9")) return 4977;
		if(s.equals("2 4 6 8 9 10")) return 9867;
		if(s.equals("2 4 6 7")) return 49;
		if(s.equals("2 4 6 7 10")) return 49;
		if(s.equals("2 4 6 7 9")) return 2753;
		if(s.equals("2 4 6 7 9 10")) return 71735;
		if(s.equals("2 4 6 7 8")) return 47089;
		if(s.equals("2 4 6 7 8 10")) return 245035;
		if(s.equals("2 4 6 7 8 9")) return 569669;
		if(s.equals("2 4 6 7 8 9 10")) return 2662657;
		if(s.equals("2 4 5")) return 5;
		if(s.equals("2 4 5 10")) return 7;
		if(s.equals("2 4 5 9")) return 27;
		if(s.equals("2 4 5 9 10")) return 91;
		if(s.equals("2 4 5 8")) return 27;
		if(s.equals("2 4 5 8 10")) return 219;
		if(s.equals("2 4 5 8 9")) return 27;
		if(s.equals("2 4 5 8 9 10")) return 1177;
		if(s.equals("2 4 5 7")) return 7;
		if(s.equals("2 4 5 7 10")) return 7;
		if(s.equals("2 4 5 7 9")) return 125;
		if(s.equals("2 4 5 7 9 10")) return 29913;
		if(s.equals("2 4 5 7 8")) return 1001;
		if(s.equals("2 4 5 7 8 10")) return 34527;
		if(s.equals("2 4 5 7 8 9")) return 6393;
		if(s.equals("2 4 5 7 8 9 10")) return 246297;
		if(s.equals("2 4 5 6")) return 49;
		if(s.equals("2 4 5 6 10")) return 49;
		if(s.equals("2 4 5 6 9")) return 415;
		if(s.equals("2 4 5 6 9 10")) return 4577;
		if(s.equals("2 4 5 6 8")) return 1975;
		if(s.equals("2 4 5 6 8 10")) return 3879;
		if(s.equals("2 4 5 6 8 9")) return 4977;
		if(s.equals("2 4 5 6 8 9 10")) return 28099;
		if(s.equals("2 4 5 6 7")) return 49;
		if(s.equals("2 4 5 6 7 10")) return 49;
		if(s.equals("2 4 5 6 7 9")) return 37131;
		if(s.equals("2 4 5 6 7 9 10")) return 218301;
		if(s.equals("2 4 5 6 7 8")) return 48769;
		if(s.equals("2 4 5 6 7 8 10")) return 245035;
		if(s.equals("2 4 5 6 7 8 9")) return 569669;
		if(s.equals("2 4 5 6 7 8 9 10")) return 11814485;
		if(s.equals("2 3")) return 3;
		if(s.equals("2 3 10")) return 13;
		if(s.equals("2 3 9")) return 3;
		if(s.equals("2 3 9 10")) return 91;
		if(s.equals("2 3 8")) return 27;
		if(s.equals("2 3 8 10")) return 219;
		if(s.equals("2 3 8 9")) return 27;
		if(s.equals("2 3 8 9 10")) return 1177;
		if(s.equals("2 3 7")) return 143;
		if(s.equals("2 3 7 10")) return 167;
		if(s.equals("2 3 7 9")) return 143;
		if(s.equals("2 3 7 9 10")) return 1337;
		if(s.equals("2 3 7 8")) return 5719;
		if(s.equals("2 3 7 8 10")) return 48041;
		if(s.equals("2 3 7 8 9")) return 35785;
		if(s.equals("2 3 7 8 9 10")) return 48041;
		if(s.equals("2 3 6")) return 79;
		if(s.equals("2 3 6 10")) return 79;
		if(s.equals("2 3 6 9")) return 707;
		if(s.equals("2 3 6 9 10")) return 6073;
		if(s.equals("2 3 6 8")) return 3879;
		if(s.equals("2 3 6 8 10")) return 3879;
		if(s.equals("2 3 6 8 9")) return 10089;
		if(s.equals("2 3 6 8 9 10")) return 28099;
		if(s.equals("2 3 6 7")) return 2207;
		if(s.equals("2 3 6 7 10")) return 6307;
		if(s.equals("2 3 6 7 9")) return 37131;
		if(s.equals("2 3 6 7 9 10")) return 613479;
		if(s.equals("2 3 6 7 8")) return 47089;
		if(s.equals("2 3 6 7 8 10")) return 697563;
		if(s.equals("2 3 6 7 8 9")) return 569669;
		if(s.equals("2 3 6 7 8 9 10")) return 4817803;
		if(s.equals("2 3 5")) return 23;
		if(s.equals("2 3 5 10")) return 23;
		if(s.equals("2 3 5 9")) return 27;
		if(s.equals("2 3 5 9 10")) return 91;
		if(s.equals("2 3 5 8")) return 27;
		if(s.equals("2 3 5 8 10")) return 219;
		if(s.equals("2 3 5 8 9")) return 27;
		if(s.equals("2 3 5 8 9 10")) return 1177;
		if(s.equals("2 3 5 7")) return 143;
		if(s.equals("2 3 5 7 10")) return 7895;
		if(s.equals("2 3 5 7 9")) return 143;
		if(s.equals("2 3 5 7 9 10")) return 120149;
		if(s.equals("2 3 5 7 8")) return 5719;
		if(s.equals("2 3 5 7 8 10")) return 120407;
		if(s.equals("2 3 5 7 8 9")) return 128821;
		if(s.equals("2 3 5 7 8 9 10")) return 346719;
		if(s.equals("2 3 5 6")) return 79;
		if(s.equals("2 3 5 6 10")) return 79;
		if(s.equals("2 3 5 6 9")) return 1695;
		if(s.equals("2 3 5 6 9 10")) return 6073;
		if(s.equals("2 3 5 6 8")) return 3879;
		if(s.equals("2 3 5 6 8 10")) return 3879;
		if(s.equals("2 3 5 6 8 9")) return 23117;
		if(s.equals("2 3 5 6 8 9 10")) return 28099;
		if(s.equals("2 3 5 6 7")) return 2207;
		if(s.equals("2 3 5 6 7 10")) return 7895;
		if(s.equals("2 3 5 6 7 9")) return 37131;
		if(s.equals("2 3 5 6 7 9 10")) return 711725;
		if(s.equals("2 3 5 6 7 8")) return 58775;
		if(s.equals("2 3 5 6 7 8 10")) return 2688153;
		if(s.equals("2 3 5 6 7 8 9")) return 569669;
		if(s.equals("2 3 5 6 7 8 9 10")) return 11814485;
		if(s.equals("2 3 4")) return 3;
		if(s.equals("2 3 4 10")) return 13;
		if(s.equals("2 3 4 9")) return 3;
		if(s.equals("2 3 4 9 10")) return 91;
		if(s.equals("2 3 4 8")) return 27;
		if(s.equals("2 3 4 8 10")) return 219;
		if(s.equals("2 3 4 8 9")) return 27;
		if(s.equals("2 3 4 8 9 10")) return 1177;
		if(s.equals("2 3 4 7")) return 143;
		if(s.equals("2 3 4 7 10")) return 167;
		if(s.equals("2 3 4 7 9")) return 143;
		if(s.equals("2 3 4 7 9 10")) return 1337;
		if(s.equals("2 3 4 7 8")) return 5719;
		if(s.equals("2 3 4 7 8 10")) return 48041;
		if(s.equals("2 3 4 7 8 9")) return 35785;
		if(s.equals("2 3 4 7 8 9 10")) return 48041;
		if(s.equals("2 3 4 6")) return 79;
		if(s.equals("2 3 4 6 10")) return 79;
		if(s.equals("2 3 4 6 9")) return 707;
		if(s.equals("2 3 4 6 9 10")) return 6073;
		if(s.equals("2 3 4 6 8")) return 3879;
		if(s.equals("2 3 4 6 8 10")) return 3879;
		if(s.equals("2 3 4 6 8 9")) return 10089;
		if(s.equals("2 3 4 6 8 9 10")) return 28099;
		if(s.equals("2 3 4 6 7")) return 2207;
		if(s.equals("2 3 4 6 7 10")) return 6307;
		if(s.equals("2 3 4 6 7 9")) return 37131;
		if(s.equals("2 3 4 6 7 9 10")) return 613479;
		if(s.equals("2 3 4 6 7 8")) return 47089;
		if(s.equals("2 3 4 6 7 8 10")) return 697563;
		if(s.equals("2 3 4 6 7 8 9")) return 569669;
		if(s.equals("2 3 4 6 7 8 9 10")) return 4817803;
		if(s.equals("2 3 4 5")) return 23;
		if(s.equals("2 3 4 5 10")) return 23;
		if(s.equals("2 3 4 5 9")) return 27;
		if(s.equals("2 3 4 5 9 10")) return 91;
		if(s.equals("2 3 4 5 8")) return 27;
		if(s.equals("2 3 4 5 8 10")) return 219;
		if(s.equals("2 3 4 5 8 9")) return 27;
		if(s.equals("2 3 4 5 8 9 10")) return 1177;
		if(s.equals("2 3 4 5 7")) return 143;
		if(s.equals("2 3 4 5 7 10")) return 7895;
		if(s.equals("2 3 4 5 7 9")) return 143;
		if(s.equals("2 3 4 5 7 9 10")) return 120149;
		if(s.equals("2 3 4 5 7 8")) return 5719;
		if(s.equals("2 3 4 5 7 8 10")) return 120407;
		if(s.equals("2 3 4 5 7 8 9")) return 128821;
		if(s.equals("2 3 4 5 7 8 9 10")) return 346719;
		if(s.equals("2 3 4 5 6")) return 79;
		if(s.equals("2 3 4 5 6 10")) return 79;
		if(s.equals("2 3 4 5 6 9")) return 1695;
		if(s.equals("2 3 4 5 6 9 10")) return 6073;
		if(s.equals("2 3 4 5 6 8")) return 3879;
		if(s.equals("2 3 4 5 6 8 10")) return 3879;
		if(s.equals("2 3 4 5 6 8 9")) return 23117;
		if(s.equals("2 3 4 5 6 8 9 10")) return 28099;
		if(s.equals("2 3 4 5 6 7")) return 2207;
		if(s.equals("2 3 4 5 6 7 10")) return 7895;
		if(s.equals("2 3 4 5 6 7 9")) return 37131;
		if(s.equals("2 3 4 5 6 7 9 10")) return 711725;
		if(s.equals("2 3 4 5 6 7 8")) return 58775;
		if(s.equals("2 3 4 5 6 7 8 10")) return 2688153;
		if(s.equals("2 3 4 5 6 7 8 9")) return 569669;
		if(s.equals("2 3 4 5 6 7 8 9 10")) return 11814485;
		throw new RuntimeException();
	}
}
