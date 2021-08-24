#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<afxwin.h>

int T, C, N;
int i, j, k;
int n[11]={0};
// Main
int main()
{
	// ¼ÆËã½×³Ë
	n[0]=1;
	n[1]=1;
	for(i=2; i<=10; i++){
		n[i]=i*n[i-1];
	}
	
	//char filename[32]="sample";
	char filename[32]="C-small-attempt1";
	//char filename[32]="A-large";
	
	char infile[32], outfile[32];
	//scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	// Read File
	//CStdioFile f_input;
	//f_input.Open(infile, CStdioFile::modeReadWrite);
	//CStdioFile f_output;
	//f_output.Open(outfile, CStdioFile::modeReadWrite|CStdioFile::modeCreate);
	// Read Line
	//CString strValue;
	//f_input.ReadString(strValue);
	//char* line = strValue.GetBuffer(strValue.GetLength());


	
	// Get Case
	fscanf(fp, "%d", &T);
	//sscanf(line, "%d", &T);
	for(i=0; i<T; i++){
		//f_input.ReadString(strValue);
		//char* line = strValue.GetBuffer(strValue.GetLength());
		// Get Data
		fscanf(fp, "%d%d", &C, &N);
		
		double total = n[C]/(n[C-N]*n[N]);
		double up = n[C-1]/(n[C-1-N+1]*n[N-1]);
		int num = C-N;
		
		double p = total/up;

		double result = 1+num*p;
		


		printf("Case #%d: %.7lf\n", i+1, result);
		//
		/*printf("[%d] ", i+1);
		for(j=0; j<blen; j++){
			printf("%d ", base[j]);
		}
		printf("\n");*/

		// Output
		fprintf(ofp, "Case #%d: %.7lf\n", i+1, result);
		
		//CString strWriteValue;
		//strWriteValue.Format("Case #%d: %d\n", i+1, num);
		//f_output.WriteString(strWriteValue);

	}

	//f_input.Close();
	//f_output.Close();
	fclose(fp);
	fclose(ofp);


		
	return 0;
}
