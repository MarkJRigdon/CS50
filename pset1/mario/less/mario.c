// Mark J Rigdon
// 2018-12-11
// Problem set 1
// Creates a half right-aligned pyramid for Mario

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
        int number_of_hashes = i + 2;

        // Print the spaces
        for (int j = 0; j < number_of_spaces; j++)
        {
            printf(" ");
        }

        // Print the hashes
        for (int k = 0; k < number_of_hashes; k++)
        {
            printf("#");
        }

        // Generate new line
        printf("\n");
    }
}