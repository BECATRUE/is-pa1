#include <stdio.h>
#include <gmp.h>


// Function validating two inputs are valid
//
// Parameter: 
//  str_p: string of first number
//  str_q: string of second number
//  p    : address of first number
//  q    : address of second number
//
// Return:
//   0: valid
//  -1: invalid
int validateInput(char *str_p, char *str_q, mpz_t *p, mpz_t *q) {
    // 1. Validate whether two inputs are integers
    if (mpz_init_set_str(*p, str_p, 10) == -1) {
        printf("The first input is not an integer.\n");
        return -1;
    }

    if (mpz_init_set_str(*q, str_q, 10) == -1) {
        printf("The second input is not an integer.\n");
        return -1;
    }

    // 2. Validate whether two inputs are prime
    int isPrime = mpz_probab_prime_p(*p, 50);
    if (isPrime == 0) {
        printf("The first input is not prime.\n");
        return -1;
    } else if (isPrime == 1) {
        printf("The first input is probably prime.\n");
        printf("Not sure, but proceed.\n");
    }

    isPrime = mpz_probab_prime_p(*q, 50);
    if (isPrime == 0) {
        printf("The second input is not prime.\n");
        return -1;
    } else if (isPrime == 1) {
        printf("The second input is probably prime.\n");
        printf("Not sure, but proceed.\n");
    }
    
    return 0;
}


// Function generating key
//
// Parameter:
//  str_p: string of first number
//  str_q: string of second number
void generateKey(char *str_p, char *str_q) {
    mpz_t p, q;

    // 1. Validate whether two inputs are valid
    if (validateInput(str_p, str_q, &p, &q) == -1) { return; }
}