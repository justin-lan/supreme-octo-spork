#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//The above defines the libs we will be using.

//Program Descrption. This program will take a user's file, store it to memory and write to to the screen via stdout. 
//The bufrw will be the vulnerable function where an overflow will occur. The file you give the program should be bigger than the allocated buffer.
// From there a user should be able to return to libc and execute abritrary code founnd in standard libs e.g bin/sh or reboot etc

#ifndef BUF_SIZE
#define BUF_SIZE 152 //defines bufsize
#endif

//Function that reads the memory and writes to the screen. 
int bufrw(FILE *fh)
{
    char buffer[BUF_SIZE]; //defines buffer
    fread(buffer, sizeof(char), 300, fh); //reads data from the file into given desitnation, the buffer)
    printf("File contents:  \n"); 
    printf("%s",buffer, "\n"); //prints contents of buffer.
    printf("\n End file contents. \n");
    return 1;
}

//main function that will take a file as in input and send it to bufrw
int main(int argc, char **argv)
{
    FILE * fh =fopen(argv[1], "r"); //read file as fh, location of file is given via cmdline argument.
    char bsize[BUF_SIZE*5];  memset(bsize, 0, BUF_SIZE*5); //fills block of memory per given sizes. 
    bufrw(fh); //sends fh to bufrw function. 
    printf("Program Successful, exiting\n"); //when returning from bufrw. print this statemememt.
    fclose(fh); // close fh.
    return 1;
}
               
