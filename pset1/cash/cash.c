// Mark J Rigdon
// 2018-12-11
// Problem set 1
// Program calculates the minimum number of coins required to give a user change.
// Greedy algorithm example...

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float change;
    int coins_used = 0;

    // Prompt user for amount of change in dollar
    printf("Let's calculate your change!\n");
    do
    {
        change = get_float("Input Change (in dollars): ");
    }
    // Validate input:  No negative change allowed.
    while (change < 0);

    // Convert Change from dollars into cents and round off
    change = round(change * 100);
    printf("Your change in 'cents' is: %.0f cents\n", change);

    // Always use the largest coin possible first
    // Process quarters
    while (change >= 25)
    {
        coins_used++;
        change = change - 25;
    }
    // Process dimes
    while (change >= 10)
    {
        coins_used++;
        change = change - 10;
    }
    // Process nickels
    while (change >= 5)
    {
        coins_used++;
        change = change - 5;
    }
    // Process pennies
    while (change >= 1)
    {
        coins_used++;
        change = change - 1;
    }

    // Print final coins_used
    printf("Min number of coins used to make change:\n");
    printf("%d\n", coins_used);

}
