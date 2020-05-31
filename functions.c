#include <stdio.h>
#include <stdlib.h>
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
    // Check if def contains a =
    if (!charhas(args, '=')) {
        print_err("Missing '=' in var def");
        return 0;
    }

    // try parsing the name
    char *name = name_from_vardef(args);
    if (name == NULL) {
        print_err("Invalid var definition!");
        return 0;
    }

    // try parsing the value
    char *value = value_from_vardef(args);
    if (value == NULL) {
        print_err("Invalid value syntax!");
        return 0;
    }

    // DEBUG
    printf("name: %s", name);
    printf("value: %s", value);

    return 1;
}

int
run_system(char *args)
{
    int ret = system(args);
    if (ret == 0){
        return 1;
    }

    print_err("System exited with non success statuscode");

    return 0;
}