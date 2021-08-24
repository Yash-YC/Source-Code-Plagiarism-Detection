// Using libUtil from libGlov (Graphics Library of Victory) available at http://bigscreensmallgames.com/libGlov
#include "utilUtils.h"
#include "utilFile.h"
#include "utilString.h"
#include <assert.h>
#include "utilArray.h"
#include "utilRand.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>

extern char *doA(char **&toks);
extern char *doB(char **&toks);
extern char *doC(char **&toks);
extern char *doD(char **&toks);
extern char *doE(char **&toks);

typedef char *(*Solver)(char **&toks);

void myfprintf(FILE *f, const char *fmt, ...)
{
	va_list va;
	char buf[32768];

	va_start(va, fmt);
	Vsprintf(buf, fmt, va);
	va_end(va);

	printf("%s", buf);
	fprintf(f, "%s", buf);
}

#define fprintf myfprintf


void doProblem(char *filename, Solver s, char *delims)
{
	char outname[MAX_PATH];
	sprintf(outname, "%s.out", filename);
	FILE *fout = fopen(outname, "w");
	char *data = fload(filename, "rb", NULL);
	char **toks=NULL;
	tokenizeStringAlloc(data, delims, &toks);
	int N = atoi(toks[0]);
	char **curtoks = &toks[1];
	for (int i=0; i<N; i++) {
		fprintf(fout, "Case #%d: %s\n", i+1, s(curtoks));
	}
	assert(curtoks == &toks[arrayGetSize(&toks)]);
	fclose(fout);
}

void doProblemNonGeneric(char *filename, Solver s, char *delims)
{
	char outname[MAX_PATH];
	sprintf(outname, "%s.out", filename);
	FILE *fout = fopen(outname, "w");
	char *data = fload(filename, "rb", NULL);
	char **toks=NULL;
	tokenizeStringAlloc(data, delims, &toks);
	//int N = atoi(toks[0]);
	char **curtoks = &toks[0];
	fprintf(fout, "%s", s(curtoks));
	assert(curtoks == &toks[arrayGetSize(&toks)]);
	fclose(fout);
}

void gentest()
{
	FILE *f = fopen("B-large.in", "wb");
#undef fprintf
	fprintf(f, "%d\n", 100);
	for (int i=0; i<100; i++)
	{
		fprintf(f, "%d %d\n", 100, 100);
		for (int j=0; j<100; j++)
		{
			for (int k=0; k<100; k++)
			{
				fprintf(f, "%d ", randInt(10001));
			}
			fprintf(f, "\n");
		}
	}
	fclose(f);
}


int main(int argc, char *argv[])
{
	//gentest();
	//doProblem("A-small.in", doA, " \t\n\r");
	//doProblemNonGeneric("A-large.in", doA, " \t\n\r");
	//doProblem("A-large.in", doA, " \t\n\r");
	doProblem("B-large.in", doB, " \t\n\r");
	//doProblem("C-large.in", doC, " \t\n\r");
	//doProblem("D-small.in", doD, " \t\n\r");
	//doProblem("D-large-test.in", doD, " \t\n\r");
	_getch();
	return 0;
}
