//Created by Ahmed Abdalmaksoud, CS330
//February 1,2016
//200304665
#include "myshell.h"
#include <unistd.h>
#include <cstring> 
#include <cstdlib> 
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
// Batch Mode function
// Pre condition: argc = 2
// Post condition: File openend for reading and readLine called
void batchMode(char * argv[])
{
    FILE* batchFile;
    printf("Batch Mode\n");
    char oneLine[LINE_MAX];
    batchFile = fopen(argv[1], "r");

    if(batchFile == NULL)
    {
        perror("File");
        exit(1);
    }    
    
    readLine(oneLine,batchFile);
    fclose(batchFile);
}
// Interactive Mode function
// Pre condition: argc = 1
// Post condition: readLine called
void interactive()
{
    printf("Interactive  Mode\n");
    char oneLine[LINE_MAX];
        readLine(oneLine,stdin);
}
// Pre condition: oneLine has been declared
// Post condition: input read (if interactive Mode), line read(if Batch Mode)
void readLine(char oneLine[], FILE* type)
{

    // to wait or not to wait
    bool parallel;
    int length;
    if(type == stdin)
    {
        parallel = false;
        while(printf("[AHMED_ABDALMAKSOUD]#") && fgets(oneLine,LIMIT,type) != NULL)
        {
        
            length = strlen(oneLine);
                   if(length > LIMIT)
            {
                printf("Very long command: Unacceptable \n");
            }
            if(strcmp(oneLine,"\n") != 0)
            {
                processLine(oneLine,parallel);
            }
        
        }
    }
    else
    {    
        parallel = true;
        while(fgets(oneLine,LIMIT,type) != NULL)
        {
            if(strcmp(oneLine,"\n") != 0)
            {
                processLine(oneLine,parallel);
            }
        }
    }
}

// Parse the input and extract and separate the commands
// Pre:  Line is already read by the readLine function
// Post: all commands have been executed that exists in line
void processLine (char line[],bool parallel)
{
    
    char delim[] = ";\n"; 
    char space[] = " ";
    int numOfCommands = 0;
    oneCommand commands[100];
    char * separated;
    pid_t process;
    int child_status;
    int counter = 0;


    // separate commands, a command ends when encountering a semi-colon
    separated = strtok(line,delim);

    if(separated != NULL)
    {
        commands[numOfCommands++].unparsed = strdup(separated);
    }
    else
    {
        printf("Empty Line !\n");
    }

    while((separated=strtok(NULL, delim))!=NULL)
    {
            commands[numOfCommands++].unparsed = strdup(separated);
    }
        
    commands[numOfCommands].unparsed = NULL;    
    // Now we want to separate the command name and options (and destination for cp like commands)
    for(int i =0 ;i < numOfCommands;i++)
    {
        commands[i].cmd[0] = strtok(commands[i].unparsed,space);

        while((commands[i].cmd[++counter]=strtok(NULL, space))!= NULL  && counter < 10);
        counter = 0;    
    }

    for(int i =0;i < numOfCommands;i++)
    {
        if(commands[i].cmd[0] == NULL)
        {
            printf("Please don't enter empty commands!\n");
            continue;
        }
        
        printf("Executing command: %s\n", commands[i].cmd[0]);
           
        process = fork();
        if(process == 0)
        {
		// Call execvp to run the desired commands
		// and if didn't return succesfully, handle it
        	if(execvp(commands[i].cmd[0],commands[i].cmd) == -1)
                {
                	if(strcmp(commands[i].cmd[0],"quit") == 0)
               		{
                        	exit(0);
                	}
               		else
                	{
                    		printf("%s: Command not found.\n", commands[i].cmd[0]);
                   		kill(getpid(),SIGKILL);
                	}
       		} 
	}          
        else 
        {
            if(strcmp(commands[i].cmd[0],"quit") == 0)
            {
                printf("Quit command found ! \nExiting ");
            
                    for(int i = 0;i < 3;i++)
                    {
                    	printf(".");
                    	fflush(stdout);
                    	sleep(1);
                    
                    }
                    printf("\n");
		    exit(0);            
            }
            else
            {
                if(parallel == false)
                {
		     // Wait for children in the interactive Mode
                    wait(&child_status);
                }
                else
                {  
		     // do no wait (to allow for paralell processing and intermixed results)
		}
                
            }
        }
	
    }
	//outside the for loop
	if(parallel == true)
	{
		//make sure all children processes terminated cleanly (in Batch mode)
		 for(int i = 0;i <numOfCommands;i++)
   		 {
      			  wait(&child_status);
   		 }
	}
}
