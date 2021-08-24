//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <stdio.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        void __fastcall Button1Click(TObject *Sender);
        int __fastcall outputData(void);
        bool __fastcall  good(int oldBasin,int newBasin);
private:	// User declarations
public:		// User declarations

   FILE *in, *out;
   int N;
   char msg[5000];
   char msg1[100000];
   int inum_samples;

   int luckyNum;

int num_samples;

        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
