#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) exit(1);

    int num = strtol(argv[1], NULL, 10);

    bool set = false;
    if (argc >= 3 && !strncmp("yes", argv[2], 3))
        set = true;

    int num2 = 42;
    if (argc >= 4)
        num2 = strtol(argv[3], NULL, 10);

    switch (num) {
        case 1:
            if (set)
        case 2:
            switch (num2)
        case 3:
                printf("Totally expected\n");
                if (set)
                    break;
        case 4:
                printf("Or is it?\n");
                break;
        default:
            printf("Switch-case e'rybody\n");
    }

    return 0;
}
