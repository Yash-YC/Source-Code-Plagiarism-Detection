#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<afxwin.h>

int T;
int temp[1024];
int numBuff[1024]={0};
int numIndex=0;
// Is Happy
int isHappy(int num, int base){
	int mod=0;
	int sum=0;
	int temp=num;
	while(temp!=0){
		mod = temp%base;
		temp/=base;
		sum+=mod*mod;
	}
	if(sum==1){
		return true;
	}
	else{
		for(int i=0; i<numIndex; i++){
			if(sum==numBuff[i])
				return false;
		}
		numBuff[numIndex]=num;
		numIndex++;
		return isHappy(sum, base);
	}
	
}


// Main
int main()
{
	
	//char filename[32]="sample";
	char filename[32]="A-small-attempt0";
	//char filename[32]="A-large";
	
	char infile[32], outfile[32];
	//scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	//FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	// Read File
	CStdioFile f_input;
	f_input.Open(infile, CStdioFile::modeReadWrite);
	CStdioFile f_output;
	f_output.Open(outfile, CStdioFile::modeReadWrite|CStdioFile::modeCreate);
	// Read Line
	CString strValue;
	f_input.ReadString(strValue);
	char* line = strValue.GetBuffer(strValue.GetLength());


	int i, j, k;
	// Get Case
	//fscanf(fp, "%d", &T);
	sscanf(line, "%d", &T);
	for(i=0; i<T; i++){
		f_input.ReadString(strValue);
		char* line = strValue.GetBuffer(strValue.GetLength());
		// Get Base
		int base[16]={0};

		int len = strlen(line);
		int index=0;
		int blen=0;
		while(line[index]!='\0'){
			sscanf(line+index,"%d", &base[blen]);
			blen++;
			while(line[index]!=' '&& line[index]!='\0'){
				index++;
			}
			if(line[index]=='\0'){
				break;
			}
			else{
				index++;
			}
		}
		// 
		//
		//int result = isHappy(11, 10);
		//printf("%d\n", result);

		// cal happy
		int result=0;
		int num=2;
		while(result!=blen){
			numIndex=0;
			if(isHappy(num, base[blen-result-1])){
				result++;
			}
			else{
				result=0;
				num++;
			}
		}
		//printf("Case #%d: %d\n", i+1, num);
		//
		/*printf("[%d] ", i+1);
		for(j=0; j<blen; j++){
			printf("%d ", base[j]);
		}
		printf("\n");*/

		// Output
		//fprintf(ofp, "Case #%d: %d\n", i+1, 0);
		CString strWriteValue;
		strWriteValue.Format("Case #%d: %d\n", i+1, num);
		f_output.WriteString(strWriteValue);

	}

	f_input.Close();
	f_output.Close();


		
	return 0;
}
