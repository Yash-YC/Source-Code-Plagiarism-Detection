//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

int __fastcall TForm1::outputData(void)
{
char aaa[5];
aaa[1]=' ';
aaa[2]=0;

AnsiString abc="Case #"+IntToStr(inum_samples)+": "+IntToStr(luckyNum)+" \n";
fputs(abc.c_str(), out);
       return 1;
}

bool __fastcall  TForm1::good(int N,int ss)
{
int sum=0;
int iter=1;
int mas[10000];
mas[0]=N;
   while(true)
    {
     while(N != 0)
       {
        sum+=(N % ss) * (N % ss);
        N = N / ss;

        if(N == 0 && sum == 1)return true;
       }

     for(int ix=0; ix < iter; ++ix)
            if(mas[ix] == sum)return false;
     mas[iter++]=sum;
     N=sum;
     sum=0;       
    }
}



void __fastcall TForm1::Button1Click(TObject *Sender)
{
//in: A-small_in.in
//

   if ((in = fopen("B-small.in", "rt"))
       == NULL)
   {
      ShowMessage("Cannot open input file");
      return;
   }
   if ((out = fopen("B-small.out", "wt"))
       == NULL)
   {
      ShowMessage("Cannot open output file.");
      return;
   }

num_samples=0;

int x;

   fgets(msg, 100, in);
   sscanf(msg,"%i", &num_samples);

   int sourceMap[500];

   for(inum_samples=1; inum_samples <= num_samples; ++inum_samples)
     {

             x=0;
             fgets(msg1, 1000, in);

                 for(int dl=0; dl<strlen(msg1); ++dl)
                  {
                    if(msg1[dl] != ' ')
                      {
                        int sum=0;
                        do
                          {

                            sum=msg1[dl]-0x30+sum*10;
                            dl++;
                          }while(msg1[dl] != ' ' && msg1[dl] != '\n');

                        sourceMap[x]=sum;
                        x++;

                      }
                  }

             luckyNum=2;

             while(true)
              {

               bool successful=true;
               for(int ix=0; ix < x; ix++)
                 {
                   if(!good(luckyNum,sourceMap[ix]))
                     {
                      luckyNum++;
                      successful=false;
                      break;
                     }
                 }
               if(!successful)continue;
                else {outputData(); break;}
              }
     }

}
//---------------------------------------------------------------------------
 