// Mark J Rigdon
// 2018-12-11
// Problem set 1
// Creates a half right-aligned pyramid and a left-aligned pyramid for Mario

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt and validate user input:  integer between 0 and 23.
    int height;
    printf("Let's generate Mario's half pyramid!\n");
    do
    {
        height = get_int("Input: ");
    }
    // Invalid heights
    while (height < 0 || height > 23);

    // Generate the half pyramid
    // Loop through the height of the pyramid
    for (int i = 0; i < height; i++)
    {
        int number_of_spaces = (height - 1) - i;
        int number_of_hashes = i + 1;

        // Print the spaces for left side of pyramid
        for (int j = 0; j < number_of_spaces; j++)
        {
            printf(" ");
        }

        // Print the hashes for left side of pyramid
        for (int k = 0; k < number_of_hashes; k++)
        {
            printf("#");
        }

        // Print double space between the two pyramid halves
        printf("  ");

        // Print the hashes for right side of pyramid
        for (int k = 0; k < number_of_hashes; k++)
        {
            printf("#");
        }

        // Generate new line
        printf("\n");
    }
}
