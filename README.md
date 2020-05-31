# JojiiLang
A very (very very) small interpreted language written in C `without strings.h`. Developed for educational purposes.

# Compile 
```bash
automake --add-missing
./configure
make
sudo make install

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
