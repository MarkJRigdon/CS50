// caesar.c by Mark J. Rigdon
// CS50
// 2018-12-16
// Program encrypts messages using Caesar's cipher.

// Includes
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Declare values
    int key;
    string plaintext;

    // Must input one and only one key...specs don't require numeric chk.
    if (argc != 2)
    {
        printf("TERMINATED--Program requires a single key value.\n");
        printf("Rerun program with a single key value as a command line argument.\n");
        return 1;
    }
    else
    {
        // Turn key into an integer
        key = atoi(argv[1]);
        printf("Your selected shift key is: %i\n", key);
    }

    // Accept plain text to encrypt
    plaintext = get_string("plaintext: ");

    // Encipher and print the plaintext (preserve casing & numbers)
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Check for alphabetic letter
        if (isalpha(plaintext[i]))
        {
            // Check for lower case
            if (islower(plaintext[i]))
            {
                // preserve case, shift, and print.
                printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
            }
            // Check for upper case
            if (isupper(plaintext[i]))
            {
                // preserve case, shift, and print.
                printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);
            }
        }
        else
        {
            // It's not alpha letter so it's a number:  Simply print the number.
            printf("%c", plaintext[i]);
        }

    }
    // Per spec... print a new line.
    printf("\n");

    // Per spec...exit with return 0.
    return 0;
}

/*
** Caesar Cipher math thought process
** Formula:  Ci = (Pi + k)mod26
**
** EG:  (plaintext[i] + key) % 26)
**
** We start with plaintext[i] being an ASCII value.
** So, 'A' in ASCII is 65 and adding a key of 2 yields 67 which is 'C' in ASCII.
** Lower case 'a' in ASCII is 97 and adding a key of 2 yields 99 which is 'c' in ASCII.
** However to encrypt in modulo, we are using alphabetical indexing.
** Due to indexing we have to deal with the alphabet wraparound.
** So ASCII to Alpha-index to encrypt --> back to ASCII to print
** Capital 'A' is 65 in ASCII and 0 in index EG -65 to index and +65 to ASCII
** LowerCase 'a' is 97 in ASCII and 0 in index EG -97 to index and +97 to ASCII
**
** Therefore, (((plaintext[i] +k) -65) % 26) to encrypt the upper case
** Therefore, (((plaintext[i] + k) -97) % 26) to encrypt the lower case
**
** To print encrypted upper:  ((((plaintext[i] +k) - 65) % 26) + 65)
** To print encrypted lower:  ((((plaintext[i] +k) -97) % 26) + 97)
*/
