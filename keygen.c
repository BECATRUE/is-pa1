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
    // 1. Validate whether two inputs are number
    if (mpz_init_set_str(*p, str_p, 10) == -1) {
        printf("The first input is not an integer.\n");
        return -1;
    }

    if (mpz_init_set_str(*q, str_q, 10) == -1) {
        printf("The second input is not an integer.\n");
        return -1;
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