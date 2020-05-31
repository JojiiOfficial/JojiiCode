#include "strutils.h"

int
charcmp(const char s1[], const char s2[])
{
    int i = 0;
    while(1)
    {
        if (s1[i] == s2[i] && s1[i] == '\0'){
            return 1;
        }

        // If one of them is 0 they don't match
        if (s1[i] != s2[i] && (s1[i] == '\0' || s2[i] == '\0')){
            return 0;
        } 

        if (s1[i] != s2[i]){
            return 0;
        }

        i++;
    }

    return 1;
}