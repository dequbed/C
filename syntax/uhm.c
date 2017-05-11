#ifdef __cpp
// Shut up C++ compilers
#define chdr extern C {
#else
#define chdr /*extern C*/ {
#define _ return
#define chdre }
#endif

#define end ef[b]
#define test malloc(ef)
#define print free
#define string /*nah*/

#include <stdio.h>
#include <stdlib.h>

// We don't use the stdint header
#define long /*int_32*/\
for (int i=0;i<(ef-1);++i) /* allocate array */
    char a[] = {72,97,108,108,111,44,32,114,101,105,116,122,101,110,115,116,101,105,110,33,13,10};

int ef = 23;

int func_a(int n) chdr
    _ n[a];
chdre

int func_b(int filter) chdr
    _ filter;
chdre

int main() chdr
    char *b = test;
    long func_b(i)[b] = func_a(i);

    end = '\0';

    printf("%s", b);

    print(b);
chdre

#ifdef __cpp
} /*extern C*/
#endif __cpp