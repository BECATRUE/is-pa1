#include <stdio.h>
#include <string.h>
#include <gmp.h>


extern int readPublicKey(mpz_t e, mpz_t n);
extern int readPrivateKey(mpz_t d);
extern int readPlainText(mpz_t pt);
extern int readCipherText(mpz_t ct);


// Decrypting function
void decrypt() {
    mpz_t e, n, d;
    mpz_t ct, pt, org_pt;

    mpz_inits(e, n, d, ct, pt, org_pt, NULL);

    // 1. Read public key
    if (readPublicKey(e, n) == -1) { return; }

    // 2. Read private key
    if (readPrivateKey(d) == -1) { return; }

    // 3. Read ciphertext
    if (readCipherText(ct) == -1) { return; }

    // 4. Compute plaintext

    // 5. Read original plaintext
    if (readPlainText(org_pt) == -1) { return; }

    mpz_clears(e, n, d, ct, pt, org_pt, NULL);
}