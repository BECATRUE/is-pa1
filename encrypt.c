#include <stdio.h>
#include <gmp.h>


// Function reading key
//
// Parameter:
//  e
//  n
//
// Return:
//   0: success to read
//  -1: fail to read
int readKey(mpz_t e, mpz_t n) {
    return 0;
}



// Encrypting function
void encrypt() {
    mpz_t e, n;

    // 1. Read public key
    if (readKey(e, n) == -1) { return; }
}