# M1522.002300 Internet Security (Fall 2022)

# Programming Assignment #1: RSA Encryption/Decryption

This can be download from Github at https://github.com/BECATRUE/is-pa1/.

## 1. Generate keys
```
$ ./rsa -keygen [p] [q]
$ ./rsa -keygen 112349 203431

Public key
   e: 203449
   n: 22855269419

Private key
   d: 22020622969

The generated keys are stored in ./key.
```
- Both `p` and `q` must be prime numbers.
- The generated keys are stored in ./key.

## 2. Encrypt
```
$ ./rsa -encrypt

Plaintext
   : 202010015

Encrypted ciphertext
   : 9239585899

The encrypted ciphertext is stored in ./text/ciphertext.
```
- The plaintext must be stored in ./text/plaintext.
- The plaintext must be a positive integer.
- The keys must be stored in ./key.

## 3. Decrypt
```
$ ./rsa -decrypt

Ciphertext
   : 9239585899

Decrypted plaintext
   : 202010015

Original plaintext (identical)
   : 202010015

The decrypted plaintext is stored in ./text/plaintext.
```
- The ciphertext must be stored in ./text/ciphertext.
- The keys must be stored in ./key.
