#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
    //cout<<"gunjan"<<endl;
    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");
    int t,b[4];
    for(int i=0;i<4;i++)
    b[i]=0;
    string s;
    //cout<<"gunjan"<<endl;
    in>>t;
    getline(in,s);
    for(int prob=0;prob<t;prob++)
    {
            for(int i=0;i<4;i++)
            b[i]=0;
            getline(in,s);
            //cout<<s<<endl;
            int j=0;
            for(int i=0;s[i]!='\0';i++)
            {
                    if(s[i]!=' ')
                    {
                               char c=s[i];
                               b[j]=b[j]*10+(c-'0');
                    }
                    else
                    j++;
            }
            cout<<j<<endl;
            int signal=0,n=1;
            while(signal!=1)
            {
                  n++;
                  for(int k=0;k<=j;k++)
                  {
                            //cout<<"gunjan"<<endl;
                            int temp=n,total=0;
                            while(temp!=0)
                            {
                                          int rem=temp%b[k];
                                          total=total+(rem*rem);
                                          temp=temp/b[k];
                            }
                            //cout<<total<<endl;
                            //system("pause");
                            temp=total;
                            int temp1=999,count=0;
                            while(count<1000)
                            {
                                          temp1=total;
                                          total=0;
                                          while(temp!=0)
                                          {
                                                        int rem=temp%b[k];
                                                        total=total+(rem*rem);
                                                        temp=temp/b[k];
                                          }
                                          temp=total;
                                          count++;
                                          //if(prob==2)
                                          //{cout<<n<<" "<<b[k]<<" "<<total<<endl;system("pause");}
                            }
                            if(temp!=1)
                            {
                                          total=0;
                                          while(temp!=0)
                                          {
                                                        int rem=temp%b[k];
                                                        total=total+(rem*rem);
                                                        temp=temp/b[k];
                                          }
                                          if(total!=1)
                                          {//if(prob==2)
                                          //cout<<"hi"<<endl;
                                          signal=0;
                                          break;}
                                          else
                                          signal=1;
                            }
                            else
                            signal=1;
                  }
            }
            
            
            
            
            cout<<"Case #"<<prob+1<<": "<<n<<endl;
            out<<"Case #"<<prob+1<<": "<<n<<endl;
    }
    
    in.close();
    out.close();
    system("pause");
    return 0;
}
