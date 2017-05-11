# Proof that gcc has the better Warnings than clang.

`make gcc` vs `make clang`

# FUN FACT

You can make the whole thing compile with no warnings by writing this line:
```c
#pragma GCC diagnostic ignored "-Wmain"
```
Somewhere before the `main` symbol.
So if you want to submit that kind of code but have requirements that it must not give any compiler warnings....
(thanks to condret)
