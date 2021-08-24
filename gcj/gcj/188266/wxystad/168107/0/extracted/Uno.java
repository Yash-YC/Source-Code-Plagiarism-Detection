package euler;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class Uno {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		cuarentayDos();		
	}
	public static void cuarentayDos(){
		BufferedReader input;		 
		 HashMap<Integer, Boolean> hash = new HashMap<Integer, Boolean>();
		for (int i=1; i< 100 ;i ++){
			hash.put(((i+1)*i)/2, true);
		}
		try {
				input = new BufferedReader(new FileReader("words.txt"));
			int sum =0;
			StringTokenizer st = new StringTokenizer(input.readLine(),",\"");
			while (st.hasMoreElements()){
				String s = st.nextToken();
				
				int val = 0;
				for (int i =0 ; i<s.length(); i++){
					val += s.charAt(i) - 'A' + 1;					
				}
				System.out.println(s + " " + val);
				if (s.compareTo("SKY") == 0)
					System.out.println("SKY vale" + val);
				if (hash.containsKey(val)){
				
					sum++;
				}
			}
			System.out.println(sum);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static void cuarentaUbo(){
		int size = 7654322;
		int[] numbers = new int[size];
		numbers[1] = 1;
		for (int i = 2; i < size; i++){
			if (numbers[i]==0){
				for (int j = i*2; j<size;j+=i){
					numbers[j]=1;
				}
			}
		}
		System.out.println("listo primos");
		int[] s = {1,2,3,4,5,6,7};
		int[] p = new int[s.length+1];
		for(int i =0 ; i <p.length ; i++)
			p[i] = i;
		int i = 1;
		int x = 0;
		int max = 0;
		while (i<s.length){
			//if (s[s.length - 1] %2 !=0){
				int num = 0;
				for (int j = 0; j< s.length; j++){
					num = num*10 + s[j];
				}
				if (numbers[num] == 0){
					for (int j = 0; j< s.length; j++)
						System.out.print(s[j]);
					System.out.println();
					System.out.println(num);
					if (num > max)
						max = num;
				}
		//	}
			x++;			
			p[i] --;
			int j = 0;
			if (i%2==1)
				j = p[i];
			int aux = s[j];
			s[j] = s[i];
			s[i] = aux;
			i = 0;
			while (i<p.length &&  p[i] ==0 ){
				p[i] = i;
				i++;
			}
			
		}		
		System.out.println(max);
	}
	public static void cuarenta(){
		String s = "0";
		int i = 1;
		int largo = 0;
		while (largo<1000000){
			largo +=  String.valueOf(i).length();
			s =i + s;
			i++;
		//	System.out.println(s.length());
		}
		int sum = 1;
		for (i = 1; i<1000000; i*=10){
			sum *= s.charAt(i) - '0';
		}
		System.out.println(sum);
	}
	public static void treintayNueve(){
		int maxSol = 0;
		int max = 0;
		for (int h = 1; h<1000; h++){
			int perimetro = h;
			int sol = 0;
			
			for (int i = 1; i*3<= perimetro; i++){
				for (int j = i; 2*j+i< perimetro; j++ ){
					int k = perimetro - i -j;
			//		System.out.println(i + " " + j + " " + k);
					if (i*i + j*j == k*k){
						sol ++;
					}
				}
			}	
			if (sol > maxSol){
				max= h;
				maxSol=sol;
			}
		}
		
		System.out.println(max + " " + maxSol);
	}
	
	public static void treintayOcho(){
		int num =0;
		String max = "";
		for (int i = 2; i< 1000000;i++){
			num = 0;
			int aux = 0;
			String s = "";
			for(int j = 1;j<10;j++){
				if (s.length() + String.valueOf(i*j).length() <= 9) 
					s += String.valueOf(i*j);
				else
					break;
			}
			//System.out.println(s + " " + i);
			//String s = String.valueOf(aux);
			if (s.length() == 9){
				boolean ok = true;
				for (int k =1;k<=9;k++){
					boolean encontre = false;
					for (int l=0;l<9;l++){
						if (s.charAt(l) -'0' == k){
							encontre = true;
							break;
						}
					}
					if (!encontre){
						ok = false;
						break;
					}
				
				}
				if (ok && s.compareTo( max) > 0){
					max = s;
					System.out.println(max + " " + i);
				}
			}
					
		}
		System.out.println(max);
	}
	public static void treintaySiete(){
		int size = 1000000;
		int[] numbers = new int[size];
		numbers[1] = 1;
		for (int i = 2; i < size; i++){
			if (numbers[i]==0){
				for (int j = i*2; j<size;j+=i){
					numbers[j]=1;
				}
			}
		}
		for (int i = 11; i < size; i++){
			if (numbers[i]==0){
				int izq = i;
				int der = i;
				while (izq!= 0 && numbers[izq] == 0){
					izq /=10;					
				}
				if (izq==0){
					int resto = 10;
					while (der%resto != i && numbers[der%resto] == 0){
						resto *=10;
					}
					if (der%resto ==i)
						System.out.println(i);
				}
			}				
		}
		
	}
	public static String aBinario(int i){
		String s = "";
		while (i>0){
			s += i %2;
			i/=2;
		}
		return s;
	}
	
	public static void treintaySeis(){
		int suma = 0;
		for (int i = 1; i< 1000000; i+=2){
			String s = String.valueOf(i);
			boolean flag = true;
			for (int j = 0 ; j< s.length()/2 ; j++){
				if (s.charAt(j) != s.charAt(s.length() -j -1)){
					flag = false;
					break;
				}
					
			}
			if (flag){
				s = aBinario(i);
				flag = true;
				for (int j = 0 ; j< s.length()/2 ; j++){
					if (s.charAt(j) != s.charAt(s.length() -j -1)){
						flag = false;
						break;
					}
						
				}
				if (flag){
					//System.out.println(i);
					suma +=i;
				}
			}
		}
		System.out.println(suma);
	}
	
	public static void treintayCinco(){
		int size = 1000000;
		int[] numbers = new int[size];
		for (int i = 2; i < size; i++){
			if (numbers[i]==0){
				for (int j = i*2; j<size;j+=i){
					numbers[j]=1;
				}
			}
		}
		int cant = 0;
		for (int i = 2;i<size;i++){
			if (numbers[i]==0){
				
				int aux = i;
				aux = (aux /10 + aux%10 * ((int)  Math.pow(10,  String.valueOf(i).length() -1)));
				while (aux != i && numbers[aux] == 0){					
					aux = (aux /10 + aux%10 * ((int)  Math.pow(10,  String.valueOf(i).length()-1))); 
				}
				if (aux==i)
					cant ++;
			}
		}
		System.out.println(cant);
	}
	public static void treintayTres(){
		for (int i = 100; i< 1000; i++){
			int num = i/10;
			int otro = i%10;
			String s = String.valueOf(i);
			int uno = s.charAt(0) - '0';
			int dos = s.charAt(1) -'0';
			int tres = s.charAt(2) - '0';
			if (dos != 0 && uno != 0 && tres!=0 && otro !=1 ){
				if (num*otro == (dos*10 + tres)*uno && num < (dos*10 + tres))
					System.out.println(i);
			}
		}
	}
	
	public static void treintayCuatro(){
		int fact[] = new int[10];
		fact[0] = 1;
		for (int i = 1; i< 10;i++){
			fact[i] = fact[i-1] * i;
		}
		for (int i = 3;i<1000000;i++){
			char[] c = String.valueOf(i).toCharArray();
			int sum = 0;
			for (int j = 0; j<c.length;j++){
				sum+= fact[c[j] -'0'];
			}
			if (sum == i){
				System.out.println(i);
			}
		}
	}
	public static void mm(int[] s){
		int i = 0;
		while (i<s.length -2){
			for(int j = i+1; j<s.length-1;j++ ){
				int val1 = 0;
				for (int x =0 ; x<=i;x++)
					val1 = val1*10 +s[x];				
				int val2 = 0;
				for (int y = i+1; y<=j;y++)
					val2 = val2*10 + s[y];
				int val3 = 0;
				for (int z = j+1; z<s.length; z++)
					val3 = val3*10 + s[z];
				if (val1*val2 == val3){
					//for (int h=0;h<s.length;h++)
						System.out.print(val3);
					System.out.println();
				}
				
			}
			i++;
		}
	}
	public static void treintayDos(){		
		int[] s = {1,2,3,4,5,6,7,8,9};
		int[] p = new int[s.length+1];
		for(int i =0 ; i <p.length ; i++)
			p[i] = i;
		int i = 1;
		int x = 0;
		while (i<s.length){
			x++;
/*			for (int h=0;h<s.length;h++)
				System.out.print(s[h]);
			System.out.println(" " + x);*/
			mm(s);
			p[i] --;
			int j = 0;
			if (i%2==1)
				j = p[i];
			int aux = s[j];
			s[j] = s[i];
			s[i] = aux;
			i = 0;
			while (i<p.length &&  p[i] ==0 ){
				p[i] = i;
				i++;
			}
			
		}		
	}
	
	public static void treintayUno(){
		int count = 0;
		for(int a=0; a<=200; a+=200)
		    for(int b=0; a+b<=200; b+=100)
		        for(int c=0; a+b+c<=200; c+=50)
		            for(int d=0; a+b+c+d<=200; d+=20)
		                for(int e=0; a+b+c+d+e<=200; e+=10)
		                    for(int f=0; a+b+c+d+e+f<=200; f+=5)
		                        for(int g=0; a+b+c+d+e+f+g<=200; g+=2)
		                            for(int h=0; a+b+c+d+e+f+g+h<=200; h++)
		                                if(a+b+c+d+e+f+g+h==200) count++;
		System.out.println(count);
		
		
	}
	public static void treinta(){
		int pow = 5;
		int pepe = 0;
		for(int i = 1; i<100000000;i++){
			String s = String.valueOf(i);
			double sum= 0;
			for (int j = 0; j< s.length(); j++){
				sum+=  Math.pow(( s.charAt(j) - '0'),pow);
			}
			if (sum == i){
				pepe += i;
				System.out.println(i);
			}
		}
		System.out.println(pepe);
	}
	public static void veintinueve(){
		HashMap<Double, Boolean> p = new HashMap<Double, Boolean>();
		for (int i = 2; i<= 100;i++){
			for (int j = 2; j<=100;j++){
				double b = Math.pow(i, j);
				if (!p.containsKey(b)){
					p.put(b, true);
				}
			}
		}
		System.out.println(p.size());		
		
	}
	public static void veintiocho(){
		int sum = 1;
		int val = 1;
		for (int i = 1 ; i< (1001+1)/2; i+=1){
			val +=i*2;
			System.out.println(val);
			sum+= val;
			
			val +=i*2;
			sum+= val;
			System.out.println(val);
			val +=i*2;
			System.out.println(val);
			sum+= val;
			val +=i*2;
			System.out.println(val);
			sum+= val;
		}
		System.out.println(sum);
		
	}
	public static void noventaySiete(){
		BigInteger bi = new BigInteger("28433");
		BigInteger pepe = new BigInteger("2");		
		pepe = pepe.modPow(new BigInteger("7830457"), new BigInteger("1000000000000")).multiply(bi).add(new BigInteger("1"));
			System.out.println(pepe);
	}
	public static void cuarentayOcho(){
		BigInteger bi = new BigInteger("0");
		int ii =1;
		for (BigInteger i = new BigInteger("1"); i.compareTo(new BigInteger("1000")) <= 0;i = i.add(new BigInteger("1")) ){
			bi = bi.add(i.pow(ii));
			System.out.println(ii);
			ii++;
		}
		System.out.println(bi);
	}
	public static void veintisiete(){
		
		int size = 1000000;
		int[] numbers = new int[size];
		for (int i = 2; i < size; i++){
			if (numbers[i]==0){
				for (int j = i*2; j<size;j+=i){
					numbers[j]=1;				
				}
			}
		}
		LinkedList<Integer> ll = new LinkedList<Integer>(); 
		for (int i = 2;i<1000;i++){
			if (numbers[i]==0){
				System.out.println(i);
				ll.add(i);
			}
		}	
		int num = 0;
		int maxA = 0;
		int maxB = 0;
		int i = 0;
		for(int a = -1000; a<= 1000; a ++){
			for (Integer b : ll){
				i = 0;
				int val = b;
				//System.out.println(b);
				while (val >= 0 && numbers[val] == 0){					
					i++;
					val = i*i + a*i + b;
				}
				if (i > num){
					num = i;
					maxA = a;
					maxB = b;
				}
				 
			}
			for (Integer b : ll){
				i = 0;
				int val = -b;
				//System.out.println(b);
				while (val >= 0 && numbers[val] == 0){					
					i++;
					val = i*i + a*i - b;
				}
				if (i > num){
					num = i;
					maxA = a;
					maxB = b;
				}
				 
			}
		}
		System.out.println(num + " " + maxA+ " " +maxB );
	}
	public static void veinticuatro(){
		BigInteger bi = new BigInteger("1");
		BigInteger ant = new BigInteger("1");
		BigInteger fin = new BigInteger("10");
		fin = fin.pow(999);
		int i = 3;
		while (bi.compareTo(fin) < 0){
			BigInteger aux = bi;
			bi =bi.add(ant);
			ant = aux;
		//	System.out.println(i + " " + bi);
			i++;
		}
		System.out.println(i -1);
		
		
			
		
	}
	public static void veintidos(){
		System.out.println("23  " + "2783915460");
		ArrayList<Integer> abundante = new ArrayList<Integer>();
		int array[] = new int[28123];	
		for(int i = 2 ; i< array.length;i++){
			
			for (int j = 1; j<=i/2;j++){
				if (i%j ==0){
					array[i] += j;
				}
			}
			if (array[i] > i)
				abundante.add(i);
		}
		int vec[] = new int[28124];
		System.out.println("pre suma" + abundante.size());
		int suma = 0;
		int val = 0;
		for(Integer i : abundante){
			for(int k = val; k<abundante.size();k++){
				Integer j = abundante.get(k);
				if (i+j< vec.length)
					vec[i+j] = 1;
			}
			val ++;
		}
		
		for (int i=0; i< vec.length ; i++){
			if (vec[i] != 1 )
				suma += i;
		}
		/*System.out.println("pre sort " + sum.size());
		Collections.sort(sum);
		int ant = 0;
		int suma = 0;
		for (Integer i: sum){
			if (ant !=i){
				suma+= i;
				ant = i;
			}
		}*/
		System.out.println(suma);
	}
	public static void veintiuno(){
		int array[] = new int[10001];	
		for(int i = 2 ; i< array.length;i++){
			for (int j = 1; j<=i/2;j++){
				if (i%j ==0){
					array[i] += j;
				}
			}
		}
		int sum = 0;
		for (int i = 2; i<array.length;i++){
			if (array[i] < array.length && array[array[i]] == i &&  array[i] != i) {
				sum += i;
				System.out.println(i + " " + array[i]);
			}
		}
		System.out.println(sum);
		
	}
	
	
	public static void diecisiete(){	
		String smallNumbers[] = new String[10];
		
		smallNumbers[0] ="zero";
		smallNumbers[1] ="one";
		smallNumbers[2] ="two";
		smallNumbers[3] ="three";
		smallNumbers[4] ="four";
		smallNumbers[5] ="five";
		smallNumbers[6] ="six";
		smallNumbers[7] ="seven";
		smallNumbers[8] ="eight";
		smallNumbers[9] ="nine";
		
		String mediumNumbers[] = new String[10];
		mediumNumbers[0] ="ten";
		mediumNumbers[1] ="eleven";
		mediumNumbers[2] ="twelwe";
		mediumNumbers[3] ="thirteen";
		mediumNumbers[4] ="fourteen";
		mediumNumbers[5] ="fifteen";
		mediumNumbers[6] ="sixteen";
		mediumNumbers[7] ="seventeen";
		mediumNumbers[8] ="eighteen";
		mediumNumbers[9] ="nineteen";


		String [] tenMultiples = new String[10];
		tenMultiples[0] ="ten";
		tenMultiples[1] ="twenty";
		tenMultiples[2] ="thirty";
		tenMultiples[3] ="forty";
		tenMultiples[4] ="fifty";
		tenMultiples[5] ="sixty";
		tenMultiples[6] ="seventy";
		tenMultiples[7] ="eighty";
		tenMultiples[8] ="ninety";
		
		String hundred= "hundred";
		String sal = "";
		for (int h = 1; h<=1000;h++ ){
			int x = h;
			boolean flag=false;
			if (x == 1000){
				sal += "onethousand";
				x=0;
			}
			if (x >= 100){
				int val = String.valueOf(x).charAt(0) -'0';
				sal += smallNumbers[val] + hundred;
				x-=100*val;
				flag = true;
			}
			if (x >= 20){	
				if (flag)
					sal+="and";
				flag = false;
				int val = String.valueOf(x).charAt(0) -'0';
				sal+= tenMultiples[val-1];
				x-=val*10;
			}
			if (x >= 10){
				if (flag)
					sal+="and";
				flag = false;
				int val = String.valueOf(x).charAt(1) -'0';
				sal+= mediumNumbers[val];
				x =0;
			}
			if (x>0){
				if (flag)
					sal+="and";
				flag = false;
				int val = String.valueOf(x).charAt(0) -'0';
				sal += smallNumbers[val];
			}
		//	sal += " " + h + "\n" ;
		}
		System.out.println(sal.length());
	}
	
	
	public static void dieciseis(){
		
		int[] vec = new int[5000];
		vec[0] = 2;
		for (int i = 1; i< 1000; i++){
			int meLlevo = 0;
			for (int g = 0 ; g<5000; g++){
				vec[g] = vec[g]* 2 + meLlevo ;
				if (vec[g] > 9){
					vec[g] -=10;
					meLlevo = 1;
				}
				else meLlevo = 0;
			}
		}		
		int sum = 0;
		for (int g = 0 ; g<5000; g++){
			sum +=vec[g];
			System.out.print(vec[g]);
		}
		System.out.println();
		System.out.println(sum);
	}
	
	public static void quince(){
		int tam = 20;
		long mat[][] = new long[tam + 1][tam + 1];
		mat = recu(0,0,tam,mat);
		for (int i =0 ; i<= tam ;i ++){
			for (int j =0 ; j<= tam ;j ++)
				System.out.print(mat[i][j] + " ");
			System.out.println();
		}
	}
	
	public static long[][]  recu(int posx, int posy, int size,long[][] mat){
		if (posx == size && posy == size)
			mat[posx][posy] =0;
		else if (posx == size || posy == size )
			mat[posx][posy] =1;		 
		else{
			if (mat[posx][posy+1] ==0)
				mat =recu(posx, posy+1,size,mat);
			if (mat[posx+1][posy] == 0)  
				mat = recu(posx+1,posy,size,mat);
			
			mat[posx][posy] = mat[posx+1][posy] + mat[posx][posy+1];
		}
		return mat;
	}
	public static void catorce(){
		int max = 0;
		int maxVal =0;		
		for (int j = 1; j <= 1000000; j++){
			int i = 0;
			long val = j;
			while (val > 1){
				if (val % 2 ==0)
					val /=2;
				else 
					val = 3*val +1;
		
				i +=1;
			}
			if (i >= max){
				max = i;
				maxVal = j;
			}
			System.out.println(j + " "+  i );
		}
		System.out.println(maxVal + " " + max);
	}
	
	
	public static void trece(){
		String[] s = {
			"37107287533902102798797998220837590246510135740250",
		"46376937677490009712648124896970078050417018260538",
		"74324986199524741059474233309513058123726617309629",
		"91942213363574161572522430563301811072406154908250",
		"23067588207539346171171980310421047513778063246676",
		"89261670696623633820136378418383684178734361726757",
		"28112879812849979408065481931592621691275889832738",
		"44274228917432520321923589422876796487670272189318",
		"47451445736001306439091167216856844588711603153276",
		"70386486105843025439939619828917593665686757934951",
		"62176457141856560629502157223196586755079324193331",
		"64906352462741904929101432445813822663347944758178",
		"92575867718337217661963751590579239728245598838407",
		"58203565325359399008402633568948830189458628227828",
		"80181199384826282014278194139940567587151170094390",
		"35398664372827112653829987240784473053190104293586",
		"86515506006295864861532075273371959191420517255829",
		"71693888707715466499115593487603532921714970056938",
		"54370070576826684624621495650076471787294438377604",
		"53282654108756828443191190634694037855217779295145",
		"36123272525000296071075082563815656710885258350721",
		"45876576172410976447339110607218265236877223636045",
		"17423706905851860660448207621209813287860733969412",
		"81142660418086830619328460811191061556940512689692",
		"51934325451728388641918047049293215058642563049483",
		"62467221648435076201727918039944693004732956340691",
		"15732444386908125794514089057706229429197107928209",
		"55037687525678773091862540744969844508330393682126",
		"18336384825330154686196124348767681297534375946515",
		"80386287592878490201521685554828717201219257766954",
		"78182833757993103614740356856449095527097864797581",
		"16726320100436897842553539920931837441497806860984",
		"48403098129077791799088218795327364475675590848030",
		"87086987551392711854517078544161852424320693150332",
		"59959406895756536782107074926966537676326235447210",
		"69793950679652694742597709739166693763042633987085",
		"41052684708299085211399427365734116182760315001271",
		"65378607361501080857009149939512557028198746004375",
		"35829035317434717326932123578154982629742552737307",
		"94953759765105305946966067683156574377167401875275",
		"88902802571733229619176668713819931811048770190271",
		"25267680276078003013678680992525463401061632866526",
		"36270218540497705585629946580636237993140746255962",
		"24074486908231174977792365466257246923322810917141",
		"91430288197103288597806669760892938638285025333403",
		"34413065578016127815921815005561868836468420090470",
		"23053081172816430487623791969842487255036638784583",
		"11487696932154902810424020138335124462181441773470",
		"63783299490636259666498587618221225225512486764533",
		"67720186971698544312419572409913959008952310058822",
		"95548255300263520781532296796249481641953868218774",
		"76085327132285723110424803456124867697064507995236",
		"37774242535411291684276865538926205024910326572967",
		"23701913275725675285653248258265463092207058596522",
		"29798860272258331913126375147341994889534765745501",
		"18495701454879288984856827726077713721403798879715",
		"38298203783031473527721580348144513491373226651381",
		"34829543829199918180278916522431027392251122869539",
		"40957953066405232632538044100059654939159879593635",
		"29746152185502371307642255121183693803580388584903",
		"41698116222072977186158236678424689157993532961922",
		"62467957194401269043877107275048102390895523597457",
		"23189706772547915061505504953922979530901129967519",
		"86188088225875314529584099251203829009407770775672",
		"11306739708304724483816533873502340845647058077308",
		"82959174767140363198008187129011875491310547126581",
		"97623331044818386269515456334926366572897563400500",
		"42846280183517070527831839425882145521227251250327",
		"55121603546981200581762165212827652751691296897789",
		"32238195734329339946437501907836945765883352399886",
		"75506164965184775180738168837861091527357929701337",
		"62177842752192623401942399639168044983993173312731",
		"32924185707147349566916674687634660915035914677504",
		"99518671430235219628894890102423325116913619626622",
		"73267460800591547471830798392868535206946944540724",
		"76841822524674417161514036427982273348055556214818",
		"97142617910342598647204516893989422179826088076852",
		"87783646182799346313767754307809363333018982642090",
		"10848802521674670883215120185883543223812876952786",
		"71329612474782464538636993009049310363619763878039",
		"62184073572399794223406235393808339651327408011116",
		"66627891981488087797941876876144230030984490851411",
		"60661826293682836764744779239180335110989069790714",
		"85786944089552990653640447425576083659976645795096",
		"66024396409905389607120198219976047599490197230297",
		"64913982680032973156037120041377903785566085089252",
		"16730939319872750275468906903707539413042652315011",
		"94809377245048795150954100921645863754710598436791",
		"78639167021187492431995700641917969777599028300699",
		"15368713711936614952811305876380278410754449733078",
		"40789923115535562561142322423255033685442488917353",
		"44889911501440648020369068063960672322193204149535",
		"41503128880339536053299340368006977710650566631954",
		"81234880673210146739058568557934581403627822703280",
		"82616570773948327592232845941706525094512325230608",
		"22918802058777319719839450180888072429661980811197",
		"77158542502016545090413245809786882778948721859617",
		"72107838435069186155435662884062257473692284509516",
		"20849603980134001723930671666823555245252804609722",
		"53503534226472524250874054075591789781264330331690"};
		int meLlevo = 0;
		for (int j = 49; j >=0 ; j--){
			int sum = meLlevo;
			meLlevo = 0;
			for (int i = 0; i<s.length ; i++){
				sum+= s[i].charAt(j) - '0';
			}
			if (j  < 10){
				System.out.println(j + " " + sum%10);
			}
			meLlevo = sum / 10;
		}
		System.out.println(meLlevo);
		
	}
	public static void doce(){
		int i = 7;
		long valor = 28;
		while(true){
			int cantDiv = 0;
			for (int j=1; j<= Math.sqrt( valor); j++ ){
				if (valor % j ==0 ){
					if (j*j ==valor)
						cantDiv +=1;
					else
						cantDiv+=2;
				}
				
			}
			System.out.println(i + " " + valor + " "  + cantDiv );
			if (cantDiv >=500)
				break;
			i++;
			valor += i;
			
		}
		System.out.println(i + "  " + valor);
	}
	
	public static void once(){
		int[][] x= {{8 ,02 ,22, 97, 38, 15, 00, 40, 00, 75, 04, 05, 07, 78, 52, 12, 50, 77, 91, 8},
		{49 ,49 ,99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 04 ,56, 62 ,00},		
		{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 03, 49, 13, 36, 65},
		{52, 70, 95, 23, 04, 60, 11, 42, 69, 24, 68, 56, 01, 32, 56, 71, 37, 02, 36, 91},
		{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
		{24, 47, 32, 60, 99, 03, 45, 02, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
		{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
		{67, 26, 20, 68, 02, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
		{24, 55, 58, 05, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
		{21, 36, 23, 9, 75, 00, 76, 44, 20, 45, 35, 14, 00, 61, 33, 97, 34, 31, 33, 95},
		{78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 04, 62, 16, 14, 9, 53, 56, 92},
		{16, 39, 05, 42, 96, 35, 31, 47, 55, 58, 88, 24, 00, 17, 54, 24, 36, 29, 85, 57},
		{86, 56, 00, 48, 35, 71, 89, 07, 05, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
		{19, 80, 81, 68, 05, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 04, 89, 55, 40},
		{04, 52, 8, 83, 97, 35, 99, 16, 07, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
		{88, 36, 68, 87, 57, 62, 20, 72, 03, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
		{04, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
		{20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 04, 36, 16},
		{20, 73, 35, 29, 78, 31, 90, 01, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 05, 54},
		{01, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 01, 89, 19, 67, 48}};
		
		int max = 0;
		
		for (int i = 0; i<20; i++){
			for (int j = 0; j< 20; j++){
				int tot = 1;
				int tot2 = 1;
				int tot3 = 1;
				int tot4 = 1;
				int tot5 = 1;
				int tot6 = 1;
				for (int k = 0; k < 4 ; k++){
					if (j+k< 20)
						tot *= x[i][j +k];
					if (i + k <20)
						tot2 *= x[i+k][j];
					if (i+k <20 && j+k<20)
						tot3*=x[i+k][j+k];
					if (i-k >= 0 && j-k>=0)
						tot4*=x[i-k][j-k];
					if (i-k >=0 && j+k<20)
						tot5*=x[i-k][j+k];
					if (i+k<20 && j-k >=0)
						tot6*=x[i+k][j-k];
				}				
				if (tot > max)
					max = tot;
				if (tot2 > max)
					max = tot2;
				if (tot3 > max)
					max = tot3;
				if (tot4 > max)
					max = tot4;
				if (tot5 > max)
					max = tot5;
				if (tot6 > max)
					max = tot6;
			}
		}				
		System.out.println(max);
	}
	public static void diez(){
		int size = 2000000;
		int[] numbers = new int[size];
		for (int i = 2; i < size; i++){
			if (numbers[i]==0){
				for (int j = i*2; j<size;j+=i){
					numbers[j]=1;				
				}
			}
		}
		long j = 0;
		for (int i = 2;i<size;i++){
			if (numbers[i]==0){
				System.out.println(i);
				j+= i;
			}
		}
		System.out.println(j);
	}
	public static void nueve(){
		for (int a = 0; a< 1000 ; a++){
			for (int b= 0; b<1000; b++){
				if (500000 - (1000*a) - (1000*b) + a*b ==0)
					System.out.println(a + " " + b + " " + (1000 -b -a) + " " + a*b*(1000 -b -a));
			}
		}
	}
	public static void ocho(){
		String s = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
		int max =0 ;
		for (int i = 0; i< s.length() -4; i++){
			int tot = 1;
			for (int j = 0; j < 5 ; j++)
				tot *= s.charAt(i + j) - '0';
			System.out.println(tot);
			if (tot > max)
				max = tot;
		}
		System.out.println(max);
	}
	public static void siete(){
		int size = 10000000;
		int[] numbers = new int[size];
		for (int i = 2; i < size; i++){
			if (numbers[i]==0){
				for (int j = i*2; j<size;j+=i){
					numbers[j]=1;
				}
			}
		}
		int j = 0;
		for (int i = 1;i<size;i++){
			if (numbers[i]==0){
				
			
				if (j == 10001)
					System.out.println(i + " "  + j);
				j++;
			}
		}
	}
	public static void seis(){
		int sum1 = 0;
		int sum2 = 0;
		for (int i=1; i<= 100; i++){
			sum1 += i*i;
			sum2 += i;
		}
		System.out.println(sum2*sum2 - sum1);
	}

	public static void cinco(){
		int i = 2520;
		boolean flag =false;
		while (!flag){
			flag =true;
			for (int j = 2; j< 21 ;j++ ){
				if (i % j !=0 ){
					flag = false;
					break;
				}				
			}
			i++;
		}
		System.out.println(i);
	}
	public static void cuatro(){
		int max = 0;
		for (int uno = 100; uno<1000; uno++){
			for (int dos = 100; dos<1000; dos++){
				int total = uno * dos;
				String s = String.valueOf(total);
				
				if (s.length() > 5 &&
						s.charAt(0) == s.charAt(5) && 
							s.charAt(1) == s.charAt(4) &&
								s.charAt(2) == s.charAt(3))
					if (total > max)
						max = total;
			}
		}
		System.out.println(max);
	}
	public static void tres(){
		// 486847
		//104441
		//59569
		double val = 600851475143d;
		Double rai = Math.sqrt(val);
		//long raiz = rai.longValue();
		long raiz = 59568;
		while (val % raiz !=0){
			raiz --;
			System.out.println(raiz);
		}
		System.out.println(raiz);
	}
	
	public static void dos(){
		int sum = 0;
		int ant = 1;
		int actual =1;
		while (actual <4000000){
			int aux = ant;
			ant = actual;
			actual += aux;
		//	System.out.println(actual);
			if (actual %2 ==0)
				sum +=actual;
		}
		System.out.println(sum);
	}
	public static void uno(){
		int sum =0;
		for (int i = 0; i<=1000; i++){
			if (i%3 ==0 || i%5==0)
				sum+=i;
		}
		System.out.println(sum);
	}

	BigInteger bi = new BigInteger("1");

}
