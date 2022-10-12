#include <stdio.h>
#include <string.h>
#include <gmp.h>


extern int readPublicKey(mpz_t e, mpz_t n);
extern int readPrivateKey(mpz_t d);
extern int readPlainText(mpz_t pt);
extern int readCipherText(mpz_t ct);


// Function computing plaintext
//
// Parameter:
//  pt: plaintext
//  ct: ciphertext
//  d
//  n
void computePlaintext(mpz_t pt, mpz_t ct, mpz_t d, mpz_t n) {
    mpz_powm(pt, ct, d, n);
}


// Function comparing with original plaintext
//
// Parameter:
//  ct    : ciphertext
//  pt    : plaintext
//  org_pt: original plaintext
void compareWithOriginalPlaintext(mpz_t ct, mpz_t pt, mpz_t org_pt) {
    printf("\nCiphertext\n");
    gmp_printf("   : %Zd\n\n", ct);

    printf("Decrypted plaintext\n");
    gmp_printf("   : %Zd\n\n", pt);

    printf("Original plaintext (%s)\n", mpz_cmp(pt, org_pt) == 0 ? "identical" : "non-identical");
    gmp_printf("   : %Zd\n\n", org_pt);

    printf("The decrypted plaintext is stored in ./text/plaintext.\n\n");
}


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
    computePlaintext(pt, ct, d, n);

    // 5. Read original plaintext
    if (readPlainText(org_pt) == -1) { return; }

    // 6. Compare with original plaintext
    compareWithOriginalPlaintext(ct, pt, org_pt);

    mpz_clears(e, n, d, ct, pt, org_pt, NULL);
}