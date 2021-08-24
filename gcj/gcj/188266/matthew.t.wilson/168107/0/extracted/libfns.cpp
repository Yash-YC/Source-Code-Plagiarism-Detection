#include "stdafx.h"
#include "libfns.h"

tokenizer::tokenizer()
{
    setFile(NULL);
}

tokenizer::tokenizer( FILE* fp )
{
    setFile(fp);
}

void tokenizer::setFile( FILE* fp )
{
    dataFile = fp;
    memset(line,0,sizeof(line));
    retval = NULL;
    MOD_SEPS = "\t\n";
}

char* tokenizer::getToken()
{
    char* tokens = 0;
    while(1)
    {
        if(retval==NULL)    //reached end of line
        {
            if(fgets(line,1023,dataFile)==NULL)
                return NULL;
            tokens = line;
        }
        retval = strtok(tokens,MOD_SEPS);
        if(retval)
            return retval;
    }
    return retval;
}
tokenizer::~tokenizer(){}
