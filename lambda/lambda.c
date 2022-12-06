#include <stdio.h>

#define λ(return_type, function_body) \
({ \
      return_type fn function_body \
          fn; \
})

int main(int argc, char* argv[]) 
{
    int (*max)(int,int) = λ(int, (int x, int y) { return x > y ? x : y; });

    int bigger = max(37, 42);

    printf("%d\n", bigger);
}
