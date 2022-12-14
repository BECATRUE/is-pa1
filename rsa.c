#include <stdio.h>
#include <string.h>


extern void generateKey(char *str_p, char *str_q);
extern void encrypt();
extern void decrypt();


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
        if (argc != 2) {
            printf("After -encrypt, there must be no argument.\n");

            return 0;
        }
        
        encrypt();
    }

    // Decrypt
    else if (strcmp(mode, "-decrypt") == 0) {
        if (argc != 2) {
            printf("After -decrypt, there must be no argument.\n");

            return 0;
        }
        
        decrypt();
    }

    // Else
    else {
        printf("The first argument must be -keygen/-encrypt/-decrypt.\n");
    }

    return 0;
}