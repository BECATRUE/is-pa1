#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *mode = argv[1];

    // Generate key
    if (strcmp(mode, "-keygen") == 0) {
        printf("Generate key\n");
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
        printf("Invalid argument\n");
    }

    return 0;
}