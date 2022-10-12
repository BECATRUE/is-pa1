#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
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

    // 2. Validate whether two inputs are different
    if (mpz_cmp(p, q) == 0) {
        printf("The inputs must be different.\n");
        return -1;
    }

    // 3. Validate whether two inputs are prime
    int isPrime = mpz_probab_prime_p(p, 50);
    if (isPrime == 0) {
        printf("The first input is not prime.\n");
        return -1;
    } else if (isPrime == 1) {
        printf("\nThe first input is probably prime.\n");
        printf("Not sure, but proceed.\n");
    }

    isPrime = mpz_probab_prime_p(q, 50);
    if (isPrime == 0) {
        printf("The second input is not prime.\n");
        return -1;
    } else if (isPrime == 1) {
        printf("\nThe second input is probably prime.\n");
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
//  phi
//  p  : first number
//  q  : second number
//
// Return:
//   0: success to choose
//  -1: fail to choose
int chooseE(mpz_t e, mpz_t phi, mpz_t p, mpz_t q) {
    // Set e to the next prime greater than max(p, q)
    mpz_nextprime(e, (mpz_cmp(p, q) > 0 ? p : q));

    // Validate whether e is smaller than phi
    if (mpz_cmp(e, phi) >= 0) {
        printf("Failed to choose appropriate e.\n");
        return -1;
    }

    return 0;
}


// Function determining d
//
// Parameter:
//  d  : result
//  e  
//  phi
//
// Return:
//   0: success to determine
//  -1: fail to determine
int determineD(mpz_t d, mpz_t e, mpz_t phi) {
    // Validate whether the inverse exists
    if (mpz_invert(d, e, phi) == 0) {
        printf("Failed to determine appropriate d.\n");
        return -1;
    }

    return 0;
}


// Function saving keys
//
// Parameter:
//  e
//  n
//  d
void saveKeys(mpz_t e, mpz_t n, mpz_t d) {
    FILE *public_key_file, *private_key_file;

    mkdir("./key", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    // Save public key
    public_key_file = fopen("./key/public_key", "wt");
    gmp_fprintf(public_key_file, "e: %Zd\nn: %Zd", e, n);
    fclose(public_key_file);

    // Save private key
    private_key_file = fopen("./key/private_key", "wt");
    gmp_fprintf(private_key_file, "d: %Zd", d);
    fclose(private_key_file);

    // Print descriptions
    printf("\nPublic key\n");
    gmp_printf("   e: %Zd\n   n: %Zd\n\n", e, n);

    printf("Private key\n");
    gmp_printf("   d: %Zd\n\n", d);

    printf("The generated keys are stored in ./key.\n\n");
}


// Function generating key
//
// Parameter:
//  str_p: string of first number
//  str_q: string of second number
void generateKey(char *str_p, char *str_q) {
    mpz_t p, q;
    mpz_t n, phi, e, d;

    mpz_inits(p, q, n, phi, e, d, NULL);

    // 1. Validate whether two inputs are valid
    if (validateInput(str_p, str_q, p, q) == -1) { return; }

    // 2. Compute n = pq
    computeN(n, p, q);
    
    // 3. Compute phi = (p - 1)(q - 1)
    computePhi(phi, p, q);

    // 4. Choose e s.t. 1 < e < phi & gcd(e, phi)) = 1
    if (chooseE(e, phi, p, q) == -1) { return; }

    // 5. Determine d = e^(-1) mod phi
    if (determineD(d, e, phi) == -1) { return; }

    // 6. Save public/private key
    saveKeys(e, n, d);

    mpz_clears(p, q, n, phi, e, d, NULL);
}