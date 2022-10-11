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

    if (mpz_init_set_str(pt, str, 10) == -1) {
        printf("The plaintext is invalid.\n");
        return -1;
    }

    if (mpz_sgn(pt) <= 0) {
        printf("The plaintext must be positive.\n");
        return -1;
    }

    // Close plaintext file
    fclose(plaintext_file);

    return 0;
}


// Function reading ciphertext
//
// Parameter:
//  ct: ciphertext
//
// Return:
//   0: success to read
//  -1: fail to read
int readCipherText(mpz_t ct) {
    char str[1024];
    FILE *ciphertext_file;

    // Open ciphertext file
    ciphertext_file = fopen("./text/ciphertext", "rt");

    if (ciphertext_file == NULL) {
        printf("There is no ciphertext file.\n");
        printf("The ciphertext must be stored in ./text/ciphertext.\n");
        return -1;
    }

    fseek(ciphertext_file, 0, SEEK_END);
    if (ftell(ciphertext_file) >= 1024) {
        printf("The ciphertext is too long.\n");
        printf("The length of ciphertext must be at most 1023.\n");
        return -1;
    }
    fseek(ciphertext_file, 0, SEEK_SET);

    // Read ciphertext
    fgets(str, 10, ciphertext_file);

    if (mpz_init_set_str(ct, str, 10) == -1) {
        printf("The ciphertext is invalid.\n");
        return -1;
    }

    if (mpz_sgn(ct) <= 0) {
        printf("The ciphertext must be positive.\n");
        return -1;
    }

    // Close ciphertext file
    fclose(ciphertext_file);

    return 0;
}