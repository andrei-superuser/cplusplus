//Created by Ahmed Abdalmaksoud, CS330
//February 1,2016
//200304665

//This program mimics the Linux/Unix shell
//It runs in two modes
//Interactive Mode: User inputs commands
//Batch Mode: Commands are executed from a file
//All executable commands that exists in /bin directory
//Shell builtin commands like cd,exit are not executed
//Interactive Mode: keeps running until user enters quit
//Batch Mode:keeps running until either quit found or end of commands in the file reached 

#include "myshell.h"

int main(int argc, char *argv[])
{
        if(argc == 1)
       {
       		 interactive();
       	 
       }
       else if(argc == 2)
       {
                batchMode(argv);
       }
       else
       {
       		printf("Invalid arguments\n");    
       		printf("Usage: myshell [batchfile]\n");
       		printf("batchfile is optional\n");
       		exit(2);
       }
       return 0;
}
