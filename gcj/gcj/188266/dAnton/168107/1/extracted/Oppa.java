import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Oppa implements Runnable {
	public static void main(String[] args) throws IOException {
		new Thread(new Oppa()).start();
	}

	public void run() {
		try {
			run1();
		} catch (IOException e) {

		}
	}

	int[] rres = new int[] { 0, 0, 1, 2, 2, 3, 3, 3, 4, 2, 5, 2, 6, 3, 7, 3, 8,
			5, 9, 5, 10, 23, 11, 23, 12, 5, 13, 5, 14, 23, 15, 23, 16, 6, 17,
			6, 18, 79, 19, 79, 20, 6, 21, 6, 22, 79, 23, 79, 24, 49, 25, 49,
			26, 79, 27, 79, 28, 49, 29, 49, 30, 79, 31, 79, 32, 7, 33, 7, 34,
			143, 35, 143, 36, 7, 37, 7, 38, 143, 39, 143, 40, 7, 41, 7, 42,
			143, 43, 143, 44, 7, 45, 7, 46, 143, 47, 143, 48, 49, 49, 49, 50,
			2207, 51, 2207, 52, 49, 53, 49, 54, 2207, 55, 2207, 56, 49, 57, 49,
			58, 2207, 59, 2207, 60, 49, 61, 49, 62, 2207, 63, 2207, 64, 8, 65,
			8, 66, 27, 67, 27, 68, 8, 69, 8, 70, 27, 71, 27, 72, 27, 73, 27,
			74, 27, 75, 27, 76, 27, 77, 27, 78, 27, 79, 27, 80, 216, 81, 216,
			82, 3879, 83, 3879, 84, 216, 85, 216, 86, 3879, 87, 3879, 88, 1975,
			89, 1975, 90, 3879, 91, 3879, 92, 1975, 93, 1975, 94, 3879, 95,
			3879, 96, 1001, 97, 1001, 98, 5719, 99, 5719, 100, 1001, 101, 1001,
			102, 5719, 103, 5719, 104, 1001, 105, 1001, 106, 5719, 107, 5719,
			108, 1001, 109, 1001, 110, 5719, 111, 5719, 112, 47089, 113, 47089,
			114, 47089, 115, 47089, 116, 47089, 117, 47089, 118, 47089, 119,
			47089, 120, 48769, 121, 48769, 122, 58775, 123, 58775, 124, 48769,
			125, 48769, 126, 58775, 127, 58775, 128, 3, 129, 3, 130, 3, 131, 3,
			132, 3, 133, 3, 134, 3, 135, 3, 136, 27, 137, 27, 138, 27, 139, 27,
			140, 27, 141, 27, 142, 27, 143, 27, 144, 415, 145, 415, 146, 707,
			147, 707, 148, 415, 149, 415, 150, 707, 151, 707, 152, 415, 153,
			415, 154, 1695, 155, 1695, 156, 415, 157, 415, 158, 1695, 159,
			1695, 160, 125, 161, 125, 162, 143, 163, 143, 164, 125, 165, 125,
			166, 143, 167, 143, 168, 125, 169, 125, 170, 143, 171, 143, 172,
			125, 173, 125, 174, 143, 175, 143, 176, 2753, 177, 2753, 178,
			37131, 179, 37131, 180, 2753, 181, 2753, 182, 37131, 183, 37131,
			184, 37131, 185, 37131, 186, 37131, 187, 37131, 188, 37131, 189,
			37131, 190, 37131, 191, 37131, 192, 27, 193, 27, 194, 27, 195, 27,
			196, 27, 197, 27, 198, 27, 199, 27, 200, 27, 201, 27, 202, 27, 203,
			27, 204, 27, 205, 27, 206, 27, 207, 27, 208, 4977, 209, 4977, 210,
			10089, 211, 10089, 212, 4977, 213, 4977, 214, 10089, 215, 10089,
			216, 4977, 217, 4977, 218, 23117, 219, 23117, 220, 4977, 221, 4977,
			222, 23117, 223, 23117, 224, 6393, 225, 6393, 226, 35785, 227,
			35785, 228, 6393, 229, 6393, 230, 35785, 231, 35785, 232, 6393,
			233, 6393, 234, 128821, 235, 128821, 236, 6393, 237, 6393, 238,
			128821, 239, 128821, 240, 569669, 241, 569669, 242, 569669, 243,
			569669, 244, 569669, 245, 569669, 246, 569669, 247, 569669, 248,
			569669, 249, 569669, 250, 569669, 251, 569669, 252, 569669, 253,
			569669, 254, 569669, 255, 569669, 256, 7, 257, 7, 258, 13, 259, 13,
			260, 7, 261, 7, 262, 13, 263, 13, 264, 7, 265, 7, 266, 23, 267, 23,
			268, 7, 269, 7, 270, 23, 271, 23, 272, 44, 273, 44, 274, 79, 275,
			79, 276, 44, 277, 44, 278, 79, 279, 79, 280, 49, 281, 49, 282, 79,
			283, 79, 284, 49, 285, 49, 286, 79, 287, 79, 288, 7, 289, 7, 290,
			167, 291, 167, 292, 7, 293, 7, 294, 167, 295, 167, 296, 7, 297, 7,
			298, 7895, 299, 7895, 300, 7, 301, 7, 302, 7895, 303, 7895, 304,
			49, 305, 49, 306, 6307, 307, 6307, 308, 49, 309, 49, 310, 6307,
			311, 6307, 312, 49, 313, 49, 314, 7895, 315, 7895, 316, 49, 317,
			49, 318, 7895, 319, 7895, 320, 97, 321, 97, 322, 219, 323, 219,
			324, 97, 325, 97, 326, 219, 327, 219, 328, 219, 329, 219, 330, 219,
			331, 219, 332, 219, 333, 219, 334, 219, 335, 219, 336, 608, 337,
			608, 338, 3879, 339, 3879, 340, 608, 341, 608, 342, 3879, 343,
			3879, 344, 3879, 345, 3879, 346, 3879, 347, 3879, 348, 3879, 349,
			3879, 350, 3879, 351, 3879, 352, 34527, 353, 34527, 354, 48041,
			355, 48041, 356, 34527, 357, 34527, 358, 48041, 359, 48041, 360,
			34527, 361, 34527, 362, 120407, 363, 120407, 364, 34527, 365,
			34527, 366, 120407, 367, 120407, 368, 245035, 369, 245035, 370,
			697563, 371, 697563, 372, 245035, 373, 245035, 374, 697563, 375,
			697563, 376, 245035, 377, 245035, 378, 2688153, 379, 2688153, 380,
			245035, 381, 245035, 382, 2688153, 383, 2688153, 384, 91, 385, 91,
			386, 91, 387, 91, 388, 91, 389, 91, 390, 91, 391, 91, 392, 91, 393,
			91, 394, 91, 395, 91, 396, 91, 397, 91, 398, 91, 399, 91, 400,
			1033, 401, 1033, 402, 6073, 403, 6073, 404, 1033, 405, 1033, 406,
			6073, 407, 6073, 408, 4577, 409, 4577, 410, 6073, 411, 6073, 412,
			4577, 413, 4577, 414, 6073, 415, 6073, 416, 1337, 417, 1337, 418,
			1337, 419, 1337, 420, 1337, 421, 1337, 422, 1337, 423, 1337, 424,
			29913, 425, 29913, 426, 120149, 427, 120149, 428, 29913, 429,
			29913, 430, 120149, 431, 120149, 432, 71735, 433, 71735, 434,
			613479, 435, 613479, 436, 71735, 437, 71735, 438, 613479, 439,
			613479, 440, 218301, 441, 218301, 442, 711725, 443, 711725, 444,
			218301, 445, 218301, 446, 711725, 447, 711725, 448, 1177, 449,
			1177, 450, 1177, 451, 1177, 452, 1177, 453, 1177, 454, 1177, 455,
			1177, 456, 1177, 457, 1177, 458, 1177, 459, 1177, 460, 1177, 461,
			1177, 462, 1177, 463, 1177, 464, 9867, 465, 9867, 466, 28099, 467,
			28099, 468, 9867, 469, 9867, 470, 28099, 471, 28099, 472, 28099,
			473, 28099, 474, 28099, 475, 28099, 476, 28099, 477, 28099, 478,
			28099, 479, 28099, 480, 48041, 481, 48041, 482, 48041, 483, 48041,
			484, 48041, 485, 48041, 486, 48041, 487, 48041, 488, 246297, 489,
			246297, 490, 346719, 491, 346719, 492, 246297, 493, 246297, 494,
			346719, 495, 346719, 496, 2662657, 497, 2662657, 498, 4817803, 499,
			4817803, 500, 2662657, 501, 2662657, 502, 4817803, 503, 4817803,
			504, 11814485, 505, 11814485, 506, 11814485, 507, 11814485, 508,
			11814485, 509, 11814485, 510, 11814485, 511, 11814485 };

	boolean[][] was;
	boolean[][] res;

	boolean ook(int a, int b, int j) {
		if (was[j][a])
			return res[j][a];
		if (a == 1)
			return true;
		was[j][a] = true;
		int tmp = a;
		int tmp1 = 0;
		while (tmp > 0) {
			int tmp2 = tmp % b;
			tmp1 += tmp2 * tmp2;
			tmp /= b;
		}
		if (ook(tmp1, b, j)) {
			res[j][a] = true;
			return true;
		}
		return false;
	}

	private void run1() throws IOException {
		Scanner sc = new Scanner(new FileReader("bonus.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("bonus.out"));
		int T = sc.nextInt();
		sc.nextLine();
		for (int tn = 1; tn <= T; tn++) {
			// int n = Integer.bitCount(tn);
			String[] s = sc.nextLine().split(" ");
			int n = s.length;
			int[] b = new int[n];
			// {
			// int v = 0;
			// for (int i = 0; i < 9; i++) {
			// if ((1 & (tn >> i)) != 0) {
			// b[v++] = i + 2;
			// }
			// }
			// }
			int h = 0;
			for (int i = 0; i < b.length; i++) {
				b[i] = Integer.parseInt(s[i]);
				h += 1 << (b[i] - 2);
			}
			System.out.println(h);
			pw.printf("Case #%d: %d", tn, rres[h * 2 + 1]);
			pw.println();
			// int i = 2;
			// int max = 12000000;
			// was = new boolean[n][max];
			// res = new boolean[n][max];
			// for (; i < max; i++) {
			// boolean ok = true;
			// for (int j = 0; j < n; j++) {
			// ok &= ook(i, b[j], j);
			// }
			// if (ok || i > 7000000) {
			// int r = i;
			// if (i > 7000000)
			// r = 11814485;
			// System.out.print("," + tn + "," + r);
			// if (i > 7000000) {
			// pw.println("oppa");
			// }
			// pw.printf("Case #%d: %d", tn, r);
			// pw.println();
			// break;
			// }
			// }
		}
		pw.close();
	}

	private int[] get(int[] cur, int[][][] next) {
		if (next[cur[0]][cur[1]][0] == cur[0]
				&& next[cur[0]][cur[1]][1] == cur[1]) {
			return cur;
		}
		return next[cur[0]][cur[1]] = get(next[cur[0]][cur[1]], next);
	}
}
