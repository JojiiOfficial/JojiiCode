#include "strutils.h"
#include <stddef.h>
#include <stdlib.h>

// Check if s1 and s2 contain an equal string
int
charcmp(const char s1[], const char s2[])
{
    int i = 0;
    while(1) {
        if (s1[i] == s2[i] && s1[i] == '\0') {
            return 1;
        }

        // If one of them is 0 they don't match
        if (s1[i] != s2[i] && (s1[i] == '\0' || s2[i] == '\0')) {
            return 0;
        } 

        if (s1[i] != s2[i]) {
            return 0;
        }

        i++;
    }

    return 1;
}

// Check if s1 contains at least one 'substring'
int 
charhas(const char s1[], const char substring)
{
    int i = 0;
    while(1)
    {
        if (s1[i] == '\0') {
            break;
        }

        if (s1[i] == substring) {
            return 1;
        }
        
        i++;
    }

    return 0;
}

// Get name from a variable definition
char*
name_from_vardef(const char vardef[])
{
    int nameStarted= -1;
    int i = 0;
    char *name = malloc(100);

    while(1) {
        if (vardef[i] == '\0' || vardef[i] == '=' || (nameStarted > -1 && vardef[i] == ' ')) {
            if (nameStarted == -1) {
                return NULL;
            }

            break;
        }

        if (nameStarted != -1 || vardef[i] != ' ') {
            nameStarted ++;
            name[nameStarted] = vardef[i];
        }

        i++;
    }

    if (nameStarted == -1) {
        return NULL;
    }
    
    name[nameStarted+1] = '\0';
    return name;
}

// Get a value from a variable definition
char*
value_from_vardef(const char vardef[])
{
    int i = -1;
    int offset = -1;

    while(1)
    {
        i++;

        if (offset == -1 && vardef[i] == ' '){
            continue;
        }
        return NULL;
        // TODO
    }
    
    return NULL;
}