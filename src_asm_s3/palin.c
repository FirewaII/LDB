#include <stdio.h>
#include <stdbool.h>

bool palin(char *);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s chaine\n", argv[0]);
        return 1;
    }
    if (palin(argv[1])) {
        printf("\"%s\" est un palindrome.\n", argv[1]);
    } else {
        printf("\"%s\" n'est pas un palindrome.\n", argv[1]);
    }
    return 0;
}

