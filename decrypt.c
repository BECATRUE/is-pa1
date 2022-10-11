#include <stdio.h>
#include <string.h>
#include <gmp.h>


extern int readPublicKey(mpz_t e, mpz_t n);
extern int readPrivateKey(mpz_t d);


// Decrypting function
void decrypt() {
    mpz_t e, n, d;

    mpz_inits(e, n, d, NULL);

    // 1. Read public key
    if (readPublicKey(e, n) == -1) { return; }

    // 2. Read private key
    if (readPrivateKey(d) == -1) { return; }

    mpz_clears(e, n, d, NULL);
}