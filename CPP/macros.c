#include <stdio.h>

// Helper Macros. We need them because concatination character blues macros :(
#define CAT(x, ...) CATRE(x, __VA_ARGS__)
#define CATRE(x, ...) x ## __VA_ARGS__

// Selector Macros
#define HEAD(x, ...) x
#define LAST(x, y, ...) y
#define TAIL(x, ...) __VA_ARGS__

// Abstract boolean types away
#define PROBE(...) LAST(__VA_ARGS__, false)
#define _PROBE() ~, true // ~ is basically never valid C syntax so we'll at least get compile errors

// All values that are not 'false' are truthy
#define NOT(b) PROBE(CATRE(_NOT_, b))
#define _NOT_false _PROBE()

#define AND(x, y) CATRE(_AND_, x)(y)
#define _AND_false(y) false
#define _AND_true(y) y

#define OR(x, y) CATRE(_OR_, x)(y)
#define _OR_false(y) y
#define _OR_true(y) true

#define IF(cond) _IF(BOOL(cond))
#define _IF(cond) CAT(_IF_, cond)
#define _IF_true(...) __VA_ARGS__
#define _IF_false(...)

// 'Cast' to bool. Yep. (All values except a literal 'false' are truthy)
#define BOOL(x) NOT(NOT(x))

// Force the CPP to do another pass
// I think you can see where this is going.
#define EVAL(...)       EVAL_16(__VA_ARGS__)
#define EVAL_16(...)    EVAL_8(EVAL_8(__VA_ARGS__))
#define EVAL_8(...)     EVAL_4(EVAL_4(__VA_ARGS__))
#define EVAL_4(...)     EVAL_2(EVAL_2(__VA_ARGS__))
#define EVAL_2(...)     EVAL_1(EVAL_1(__VA_ARGS__))
#define EVAL_1(...)     __VA_ARGS__

// Defer expansion to the next iteration
#define EMPTY()
#define DEFER(id) id EMPTY()
#define DEFER_2(id) id EMPTY EMPTY()()
#define DEFER_3(id) id EMPTY EMPTY EMPTY()()()

// Are there arguments left
#define XS(...) BOOL(HEAD(XS_NO __VA_ARGS__)())
#define XS_NO() false

// Lets define some actually useful stuff

#define APPLY(f, p) f(p)

#define MAP(f, x, ...)  \
    f(x)                \
    IF(XS(__VA_ARGS__)) \
        (, DEFER_2(_MAP)()(f, __VA_ARGS__))
#define _MAP() MAP

#define FOLD(f, a, x, ...) \
    IF(XS(__VA_ARGS__)) \
        (DEFER_2(_FOLD)()(f, f(a,x), __VA_ARGS__)) \
    IF(NOT(XS(__VA_ARGS__)))\
        f(a, x)
#define _FOLD() FOLD

#define ID(a) (a)
#define PLUS_ONE(a) ((a) + 1)

#define PLUS(a, b) ((a) + (b))
#define MULT(a, b) ((a) * (b))

int main(int argc, char *argv[])
{
    printf("%i %i %i %i %i %i\n", EVAL(MAP(PLUS_ONE, 0, 1, 2, 3, 4, 5)));
    printf("Add 1 through 5 and you get: %i\n", EVAL(FOLD(PLUS, 0, 1, 2, 3, 4, 5)));
    return 0;
}
