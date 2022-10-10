#include <stdio.h>
#include <gmp.h>


// Function validating two inputs are valid
//
// Parameter: 
//  str_p: string of first number
//  str_q: string of second number
//  p    : first number
//  q    : second number
//
// Return:
//   0: valid
//  -1: invalid
int validateInput(char *str_p, char *str_q, mpz_t p, mpz_t q) {
    // 1. Validate whether two inputs are integers
    if (mpz_init_set_str(p, str_p, 10) == -1) {
        printf("The first input is not an integer.\n");
        return -1;
    }

    if (mpz_init_set_str(q, str_q, 10) == -1) {
        printf("The second input is not an integer.\n");
        return -1;
    }

    // 2. Validate whether two inputs are prime
    int isPrime = mpz_probab_prime_p(p, 50);
    if (isPrime == 0) {
        printf("The first input is not prime.\n");
        return -1;
    } else if (isPrime == 1) {
        printf("The first input is probably prime.\n");
        printf("Not sure, but proceed.\n");
    }

    isPrime = mpz_probab_prime_p(q, 50);
    if (isPrime == 0) {
        printf("The second input is not prime.\n");
        return -1;
    } else if (isPrime == 1) {
        printf("The second input is probably prime.\n");
        printf("Not sure, but proceed.\n");
    }
    
    return 0;
}


// Function computing n
//
// Parameter: 
//  n: result
//  p: first number
//  q: second number
void computeN(mpz_t n, mpz_t p, mpz_t q) {
    mpz_mul(n, p, q);
}


// Function computing phi
//
// Parameter: 
//  phi: result
//  p  : first number
//  q  : second number
void computePhi(mpz_t phi, mpz_t p, mpz_t q) {
    mpz_t p_1, q_1;

    mpz_inits(p_1, q_1, NULL);

    mpz_sub_ui(p_1, p, 1);
    mpz_sub_ui(q_1, q, 1);

    mpz_mul(phi, p_1, q_1);

    mpz_clears(p_1, q_1, NULL);
}


// Function choosing e
//
// Parameter:
//  e  : result
//  phi: phi
//  p  : first number
//  q  : second number
void chooseE(mpz_t e, mpz_t phi, mpz_t p, mpz_t q) {

}


// Function generating key
//
// Parameter:
//  str_p: string of first number
//  str_q: string of second number
void generateKey(char *str_p, char *str_q) {
    mpz_t p, q;
    mpz_t n, phi, e;

    mpz_inits(p, q, n, phi, e, NULL);

    // 1. Validate whether two inputs are valid
    if (validateInput(str_p, str_q, p, q) == -1) { return; }

    // 2. Compute n = pq
    computeN(n, p, q);
    
    // 3. Compute phi = (p - 1)(q - 1)
    computePhi(phi, p, q);

    // 4. Choose e s.t. 1 < e < phi & gcd(e, phi)) = 1
    chooseE(e, phi, p, q);
}