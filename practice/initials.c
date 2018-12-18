// Mark J. Rigdon
// Program takes a person's full name, where start of names are capitalized, and spits out person's initials.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string name = get_string("Name: ");
    char initials[4];
    int counter = 0;

    for (int i = 0; i < strlen(name); i++)
    {
        if (isupper(name[i]))
        {
            initials[counter] = name[i];
            counter++;
        }
    }
    initials[counter] = '\0';
    printf("%s\n", initials);
}