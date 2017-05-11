## If it compiles it's valid C.

### Fun facts

Array access:
```c
a[5];       // Just gets compiled to:
*(a + 5);   // But since + is commutative that's the same as:
*(5 + a);   // Which - you guessed it means:
5[a];       // is the same code as the one above.
```
