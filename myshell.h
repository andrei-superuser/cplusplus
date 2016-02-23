//Created by Ahmed Abdalmaksoud, CS330
//February 1,2016
//200304665
#include <stdio.h>
#include <stdlib.h>

const int LIMIT = 512;

void processLine (char [],bool);
void readLine(char [],FILE*);
void batchMode(char *[]); 
void interactive();

struct oneCommand
{
    //unpared command (command name,options,destinations are not separated)
    char *unparsed;        
    //Maximum options for one command (10)
    char *cmd[10];
    //cmd[0] is the command name
    // everything that follows cmd[1]........ cmd[2] are command options and file destination, etc

};


