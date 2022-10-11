#include <stdio.h>
#include <string.h>
#include <gmp.h>


// Function reading public key
//
// Parameter:
//  e
//  n
//
// Return:
//   0: success to read
//  -1: fail to read
int readPublicKey(mpz_t e, mpz_t n) {
    char str[1024], prefix[4], key[1024];
    FILE *public_key_file;

    // Open public key file
    public_key_file = fopen("./key/public_key", "rt");

    if (public_key_file == NULL) {
        printf("There is no public key file.\n");
        printf("The public key must be stored in ./key/public_key.\n");
        return -1;
    }

    // Read e
    strcpy(str, "");
    strcpy(prefix, "");
    strcpy(key, "");

    fgets(str, 1024, public_key_file);

    strncpy(prefix, str, 3);
    if (strcmp(prefix, "e: \0") != 0) {
        printf("The public key file is corrupted.\n");
        printf("Please generate keys again.\n");
        return -1;
    }

    strncpy(key, str + 3, strlen(str));

    if(mpz_init_set_str(e, key, 10) == -1) {
        printf("The public key e is invalid.\n");
    }

    // Read n
    strcpy(str, "");
    strcpy(prefix, "");
    strcpy(key, "");

    fgets(str, 1024, public_key_file);

    strncpy(prefix, str, 3);
    if (strcmp(prefix, "n: \0") != 0) {
        printf("The public key file is corrupted.\n");
        printf("Please generate keys again.\n");
        return -1;
    }

    strncpy(key, str + 3, strlen(str));

    if(mpz_init_set_str(n, key, 10) == -1) {
        printf("The public key n is invalid.\n");
    }

    // Close public key file
    fclose(public_key_file);

    return 0;
}



// Encrypting function
void encrypt() {
    mpz_t e, n;

    // 1. Read public key
    if (readPublicKey(e, n) == -1) { return; }
}