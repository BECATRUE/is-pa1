#include <stdio.h>
#include <string.h>
#include <gmp.h>


// Function reading plaintext
//
// Parameter:
//  pt: plaintext
//
// Return:
//   0: success to read
//  -1: fail to read
int readPlainText(mpz_t pt) {
    char str[1024];
    FILE *plaintext_file;

    // Open plaintext file
    plaintext_file = fopen("./text/plaintext", "rt");

    if (plaintext_file == NULL) {
        printf("There is no plaintext file.\n");
        printf("The plaintext must be stored in ./text/plaintext.\n");
        return -1;
    }

    fseek(plaintext_file, 0, SEEK_END);
    if (ftell(plaintext_file) >= 1024) {
        printf("The plaintext is too long.\n");
        printf("The length of plaintext must be at most 1023.\n");
        return -1;
    }
    fseek(plaintext_file, 0, SEEK_SET);

    // Read plaintext
    fgets(str, 10, plaintext_file);

    if(mpz_init_set_str(pt, str, 10) == -1) {
        printf("The plaintext is invalid.\n");
    }

    // Close plaintext file
    fclose(plaintext_file);

    return 0;
}