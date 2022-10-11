#include <stdio.h>
#include <string.h>
#include <gmp.h>


extern int readPublicKey(mpz_t e, mpz_t n);
extern int readPlainText(mpz_t pt);


// Compute ciphertext
//
// Parameter:
//  pt: plaintext
//  ct: ciphertext
//  e
//  n
void computeCiphertext(mpz_t pt, mpz_t ct, mpz_t e, mpz_t n) {
    mpz_powm(ct, pt, e, n);
}



// Encrypting function
void encrypt() {
    mpz_t e, n;
    mpz_t pt, ct;

    mpz_inits(e, n, pt, ct, NULL);

    // 1. Read public key
    if (readPublicKey(e, n) == -1) { return; }

    // 2. Read plaintext
    if (readPlainText(pt) == -1) { return; }

    // 3. Compute ciphertext
    computeCiphertext(pt, ct, e, n);
    gmp_printf("%Zd\n", ct);

    mpz_clears(e, n, pt, NULL);
}