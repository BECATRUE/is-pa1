#include <stdio.h>
#include <string.h>
#include <gmp.h>


extern int readPublicKey(mpz_t e, mpz_t n);
extern int readPlainText(mpz_t pt);


// Encrypting function
void encrypt() {
    mpz_t e, n;
    mpz_t pt;

    mpz_inits(e, n, pt, NULL);

    // 1. Read public key
    if (readPublicKey(e, n) == -1) { return; }

    // 2. Read plaintext
    if (readPlainText(pt) == -1) { return; }

    mpz_clears(e, n, pt, NULL);
}