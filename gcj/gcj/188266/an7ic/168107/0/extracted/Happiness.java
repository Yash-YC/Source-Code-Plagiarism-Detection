import java.util.*;
public class Happiness {
  public static ArrayList<Integer> al[] = new ArrayList[8];
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int T=sc.nextInt();
    sc.nextLine();
    for(int i = 0; i<al.length; i++) al[i]=new ArrayList<Integer>();
    for (int n=0; n<T; n++){
      String bases[]=sc.nextLine().trim().split(" ");
      int r = 1;
      boolean h=false;
      while(!h){
      	      r++;
      	      h=true;      	      
      	      for(int j = 0; j<bases.length; j++){	
      	      	int bb = Integer.parseInt(bases[j]);
      	      	//System.out.println("X: "+r+" Base: "+bb);
      	      	if(bb>2){
			if(!(al[bb-3].contains(r))){
				if(p(r,bb))
					al[bb-3].add(r);
				else
					h = false;
			}
      	      	}
      	      }
      }
      System.out.println("Case #"+(n+1)+": "+r);
    }
  }
  public static boolean p(int x, int b){
  	  int r=0;
  	  int xx=Integer.parseInt(Integer.toString(x, b));
  	  //System.out.println("Base: "+b+" x entrada:"+xx);
  	  ArrayList<Integer> last=new ArrayList<Integer>();
  	  while (true){
		  last.add(xx);
  	  	  r=0;
		  while(xx>=10){
			  r += (xx%10)*(xx%10);
			  xx = (xx-(xx%10))/10;
		  }
		  r += xx*xx;
		  xx = Integer.parseInt(Integer.toString(r, b));
		  //System.out.println("Base: "+b+" x:"+xx);
		  if(al[b-3].contains(r)) return true;
		  if(last.contains(xx))return false;
		  if(xx==1)return true;
  	  }
  	  //return xx==1;
  }
}
