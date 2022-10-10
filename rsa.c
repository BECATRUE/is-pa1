#include <stdio.h>
#include <string.h>

extern void generateKey(char *str_p, char *str_q);

int main(int argc, char *argv[]) {
    // If no argument
    if (argc == 1) {
        printf("An argument is essential.\n");

        return 0;
    }

    char *mode = argv[1];

    // Generate key
    if (strcmp(mode, "-keygen") == 0) {
        if (argc != 4) {
            printf("After -keygen, there must be only two numbers.\n");

            return 0;
        }

        generateKey(argv[2], argv[3]);
    }

    // Encrypt
    else if (strcmp(mode, "-encrypt") == 0) {
        printf("Encrypt\n");
    }

    // Decrypt
    else if (strcmp(mode, "-decrypt") == 0) {
        printf("Decrypt\n");
    }

    // Else
    else {
        printf("The first argument must be -keygen/-encrypt/-decrypt.\n");
    }

    return 0;
}