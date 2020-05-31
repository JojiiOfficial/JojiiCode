#include <stdio.h>
#include "functions.h"
#include "strutils.h"
#include "misc.h"

int
print(char *args)
{
    printf("%s\n",args);
    return 1;
}

int
vardef(char *args)
{
    if (!charhas(args, '=')){
        print_err("Missing '=' in var def");
        return 0;
    }

    // try to get the name
    char *name = name_from_vardef(args);

    if (name == NULL){
        print_err("Invalid var definition!");
        return 0;
    }

    return 1;
}