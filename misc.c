#include "misc.h"
#include "stdio.h"

const char *err_string = "\033[31mError\033[39m";

void 
print_err(char *err)
{
    printf("%s %s\n", err_string, err);
}

void
print_line_error(int line)
{
    printf("\033[31m--> AT LINE %d\033[39m\n", line);
}