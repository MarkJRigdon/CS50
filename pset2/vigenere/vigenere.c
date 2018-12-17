// vigenere.c by Mark J. Rigdon
// CS50
// 2018-12-16
// Program encrypts messages using Vigenere's cipher.

// Includes
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Declare values
    string keyword;
    string plaintext;
    int plaintextlength;
    int keywordlength;

    // Must input one and only one keyword
    if (argc != 2)
    {
        printf("TERMINATED--Program requires a single keyword.\n");
        printf("Rerun program with a single keyword as a command line argument.\n");
        return 1;
    }

    keyword = argv[1];

    // Test to make sure ALL characters of keyword are alphabetical, otherwise reject.
    for (int i = 1, n = strlen(keyword); i < n; i++)
    {
        if (isalpha(keyword[i]))
        {
            printf("");
        }
        else
        {
            printf("Your keyword must contain ONLY letters.  Run the program again.\n");
            return 1;
        }
    }

    // Accept plain text to encrypt
    plaintext = get_string("plaintext: ");

    // Calculate lenghts of plaintext message and keyword
    plaintextlength = strlen(plaintext);
    keywordlength = strlen(keyword);

    // Encipher plaintext using vingenere and print the plaintext (preserve casing, numbers, and punctuation)
    printf("ciphertext: ");
    // Loop through the plaintext and keyword
    for (int i = 0, j = 0; i < plaintextlength; i++)
    {

        // Check for alaphabetic character
        if (isalpha(plaintext[i]))
        {

            // Check for case outcomes of plaintext and keyword:  There are four.
            // In each case:  preserve letter case, shift in ASCII, convert back to numeric and print.
            // Case:  both plaintext and keyword characters are lower case.
            if (islower(plaintext[i]) && islower(keyword[j]))
            {
                printf("%c", (((plaintext[i] - 97) + (keyword[j] - 97)) % 26) + 97);
            }
            // Case: Both plaintext and keyword characters are upper case
            else if (isupper(plaintext[i]) && isupper(keyword[j]))
            {
                printf("%c", (((plaintext[i] - 65) + (keyword[j] - 65)) % 26) + 65);
            }
            // Case: plaintext character is uppercase and keyword character is lower case
            else if (isupper(plaintext[i]) && islower(keyword[j]))
            {
                printf("%c", (((plaintext[i] - 65) + (keyword[j] - 97)) % 26) + 65);
            }
            // Case: plaintext character is lower case and keyword character is upper case.
            else if (islower(plaintext[i]) && isupper(keyword[j]))
            {
                printf("%c", (((plaintext[i] - 97) + (keyword[j] - 65)) % 26) + 97);
            }

            // Only iterate keyword when used.
            j++;

            // End of key word?  Wrap around at start at it's first character again.
            if (j == keywordlength)
            {
                j = 0;
            }
        }
        // If plaintext isn't an alphabet character then just print it and do not iterate the keyword
        else
        {
            printf("%c", plaintext[i]);
        }


    }
    // Per spec... print a new line.
    printf("\n");

    // Per spec...exit with return 0.
    return 0;
}

