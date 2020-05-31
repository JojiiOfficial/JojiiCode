#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "functions.h"
#include "strutils.h"

extern int errno;

// get file size
int
get_file_size(FILE *file)
{
    fseek(file, 0L, SEEK_END);
    int sz = ftell(file);
    fseek(file, 0L, SEEK_SET);
    rewind(file);
    return sz;
}

// read file
int
read_file(FILE *file, char **out)
{
    int sz = get_file_size(file);
    *out = (char*) malloc(sz);
    int read = fread(*out, sizeof(char), sz, file);
    if (read != sz){
        return -1;
    }

    return sz;
}

// trim string
void
trim_char(char **c, int len)
{
    (*c)[len] = '\0';
}

void
run_instruction(char *instruction, char *params)
{
    if (charcmp(instruction, "Print")) {
        print(params);
        return;
    }else if (charcmp(instruction,"let")){

    }else{
        printf("Undefined command '%s'\n", instruction);
    }
}

// convert single instruction
void
exec_instruction(char *instruction, int len)
{
    trim_char(&instruction, len);

    int instLen = -1;
    char *cmd = (char*) malloc(150);
    char *args = (char*) malloc(250);

    int isCMD = 1;

    for (int i = 0; i < len; i++){
        if (isCMD){
            if (instruction[i] == ':'){
                isCMD = 0;
                continue;
            }else {
                cmd[i] = instruction[i];
            }
        } else {
            if (instLen == -1 && instruction[i] == ' '){
                instLen = 0;
                continue;
            }
            
            args[instLen] = instruction[i];
            instLen++;
        }
    }

    run_instruction(cmd, args);
}

// convert all instructions
void
run_conversion(char *content, int size)
{
    char *buff = (char *) malloc(500);
    int buffSize = 0;

    for (int i = 0; i < size; i++){
        if (content[i] == ((char)10)){
            exec_instruction(buff, buffSize);
            buffSize = 0;
        }else {
            buff[buffSize] = content[i];
            buffSize++;
        }
    }
}


int main(int argc, char **argv)
{
    FILE *file;

    file = fopen(argv[1], "rw");
    if (file == NULL) {
        printf("%s '%s': %d","Error opening file", argv[1], errno);
        return 1; 
    }

    char *content;
    int sz = read_file(file, &content);
    if (sz == -1){
        printf("%s%d","Error reading file: ", errno);
        return 1; 
    }else if (sz == 0){
        printf("File is empty");
        return 0;
    }

    run_conversion(content, sz);

    fclose(file);

    return 0;
}