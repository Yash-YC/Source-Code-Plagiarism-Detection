#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>

using namespace std;

const int MAX=12000000;
void run()
{
    //const char flnm_in[] = "A-small.in";
    //const char flnm_in[] = "A-small-attempt1.in";
    //const char flnm_out[] = "A-small-1.out";
    const char flnm_in[] = "A-large.in";
    const char flnm_out[] = "A-large.out";
    char buf[1000];
    ifstream i_file;
    i_file.open(flnm_in);
    ofstream o_file;
    o_file.open(flnm_out);
    if (!i_file.is_open())
        return;
    if (!o_file.is_open())
        return;
    int T=0;
    i_file>>T;
    i_file.getline(buf, 1000);
    char **ss = new char*[11];
    for (int j=0;j<11;j++)
    {
        ss[j]=new char[MAX];
    }
    for (int i=0;i<T;i++)
    {
        int b[11];
        memset(b,0,sizeof(b));
        i_file.getline(buf, 1000);
        char * p= strtok(buf, " ");
        while (p)
        {
            b[atoi(p)]=1;
            p=strtok(0, " ");
        }
        if (b[4]&&b[5]&&b[6]&&b[7]&&b[8]&&b[9]&&b[10])
        {
                cout << "Case #"<<i+1<<": "<<11814485<<"\n";
                o_file << "Case #"<<i+1<<": "<<11814485<<"\n";
            break;
        }
        for (int j=0;j<11;j++)
        {
            memset(ss[j],0,sizeof(char)*MAX);
        }
        for (int j=2;j<=10;j++)
            ss[j][1]=1;
        for (int ret=2;ret<MAX;ret++)
        {
            if (ret==MAX-1)
                cout<<"!!!"<<ret<<endl;
            int cc=0;
            for (int j=3;j<=10;j++)
            {
                if (!b[j])
                {
                    cc++;
                    continue;
                }
                if (ss[j][ret]>0)
                {
                    cc++;
                    continue;
                }
                else if (ss[j][ret]<0)
                    break;

                int u=0,m=ret;
                int dep=0;
                int ip[10000];
                ip[dep++]=ret;
                while(1)
                {
                    u=0;
                    while(m)
                    {
                        int mm=m%j;
                        u+=mm*mm;
                        m/=j;
                    }
                    if (u<MAX && ss[j][u])
                    {
                        ss[j][ret]=ss[j][u];
                        if (ss[j][ret] == 1)
                            cc++;
                        break;
                    }
                    else
                    {
                        bool round=false;
                        for (int k=0;k<dep;k++)
                        {
                            if (ip[k]==u)
                            {
                                round = true;
                                break;
                            }
                        }
                        if (round)
                        {
                            for (int k=0;k<dep;k++)
                            {
                                ss[j][ip[k]]=-1;
                            }
                            break;
                        }
                        else
                        {
                            //cout<<"-"<<u<<endl;
                            m=u;
                            ip[dep++]=u;
                        }
                    }
                }
            }
            if (cc==8)
            {
                cout << "Case #"<<i+1<<": "<<ret<<"\n";
                o_file << "Case #"<<i+1<<": "<<ret<<"\n";
                break;
            }
        }
    }
    i_file.close();
    o_file.close();
}

int main(int argc, char* argv[])
{
    run();
    return 0;
}

