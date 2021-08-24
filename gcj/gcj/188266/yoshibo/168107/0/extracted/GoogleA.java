import java.util.*;
import java.io.*;
public class GoogleA{
    public static void main(String[] args){
	String[] t = FileManage.fileRead(args[0]);
	FileManage.fileWrite(new Happy().happy(t),"out.txt");
    }
}
class FileManage{
    public static String[] fileRead(String filename){
        String line="";
        ArrayList<String> file = new ArrayList<String>();
        try{
            BufferedReader reader = new BufferedReader(new FileReader(new File(filename)));
            while((line=reader.readLine()) != null){
                file.add(line);
            }
            reader.close();
        }catch(Exception e){
        }
        String[] ret = new String[file.size()];
	for(int i=0;i<file.size();i++)ret[i]=file.get(i);
	return ret;
    }
    public static void fileWrite(String[] file,String filename){
        try{
            BufferedWriter writer = new BufferedWriter(new FileWriter(new File(filename)));
            for(int i=0;i<file.length;i++){
                writer.write(file[i]);
                writer.newLine();
            }
            writer.close();
        }catch(Exception e){
        }
    }
}
class Happy{
    public String[] happy(String[] input){
	int N = Integer.parseInt(input[0]);
	String[] ans=new String[N];
	boolean[][] num = new boolean[11][100001];
	LOOP:
	for(int i=2;i<=10;i++){
	    for(int j=2;j<100001;j++){
		boolean []iss = new boolean[100001];
		if(iss[j])continue;
		int tmp=j;
		while(true){
		    tmp=getnext(tmp,i);
		    if(tmp==1)break;
		    if(iss[tmp])break;
		    iss[tmp]=true;
		}
		if(tmp == 1){
		    num[i][j]=true;
		}
	    }
	}
	for(int i=0;i<N;i++){
	    String[] tmp = input[i+1].split(" ");
	    int si=tmp.length;
	    int[] base = new int[si];
	    for(int j=0;j<si;j++)base[j]=Integer.parseInt(tmp[j]);
	    for(int j=2;j<100001;j++){
		boolean ok=true;
		for(int k=0;k<si;k++){
		    if(num[base[k]][j] == false){
			ok=false;
			break;
		    }
		}
		if(ok){
		    ans[i]="Case #"+(i+1)+": "+j;
		    break;
		}
	    }
	}
	return ans;	    
    }
    public int getnext(int i,int base){
	int res=0;
	while(i!=0){
	    res+=(i%base)*(i%base);
	    i=i/base;
	}
	return res;
    }
}
		
		