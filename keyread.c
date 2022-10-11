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
        return -1;
    }

    // Close public key file
    fclose(public_key_file);

    return 0;
}


// Function reading private key
//
// Parameter:
//  d
//
// Return:
//   0: success to read
//  -1: fail to read
int readPrivateKey(mpz_t d) {
    char str[1024], prefix[4], key[1024];
    FILE *private_key_file;

    // Open private key file
    private_key_file = fopen("./key/private_key", "rt");

    if (private_key_file == NULL) {
        printf("There is no private key file.\n");
        printf("The private key must be stored in ./key/private_key.\n");
        return -1;
    }

    // Read d
    strcpy(str, "");
    strcpy(prefix, "");
    strcpy(key, "");

    fgets(str, 1024, private_key_file);

    strncpy(prefix, str, 3);
    if (strcmp(prefix, "d: \0") != 0) {
        printf("The private key file is corrupted.\n");
        printf("Please generate keys again.\n");
        return -1;
    }

    strncpy(key, str + 3, strlen(str));

    if(mpz_init_set_str(d, key, 10) == -1) {
        printf("The private key d is invalid.\n");
        return -1;
    }

    // Close private key file
    fclose(private_key_file);

    return 0;
}