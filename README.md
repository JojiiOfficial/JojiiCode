# JojiiLang
A very (very very) small interpreted language written in C `without strings.h`. Developed for educational purposes.

# Compile 
```bash
gcc main.c misc.c functions.c strutils.c -o jojiilang -O2
```

# Run 
```
./jojiilang <file>
```

# Syntax
```
Print: print test   # prints 'print test' to screen
exec: ps -ef        # run ps -ef 
let: a = 0          # set a to 0 (not completely implemented)  
```