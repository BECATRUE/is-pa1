#include <stdio.h>
#include <string.h>
#include <gmp.h>


extern int readPublicKey(mpz_t e, mpz_t n);


// Encrypting function
void encrypt() {
    mpz_t e, n;

    // 1. Read public key
    if (readPublicKey(e, n) == -1) { return; }
}