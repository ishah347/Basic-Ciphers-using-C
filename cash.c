// cash.c
// Make some change!

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for change owed
    float dollars;
    do
    {
        dollars = get_float("Change: ");
    }
    while (dollars < 0);

    // Convert dollars to cents to avoid floating-point imprecision
    int cents = round(dollars * 100);

    // Initialize counter for coins
    int coins = 0;

    // Take as many 25-cent bites out of problem as possible, relying on integer division for whole number
    coins += cents / 25;

    // Amount of changed owed now equals remainder after dividing by 25
    cents = cents % 25;

    // Repeat for dimes
    coins += cents / 10;
    cents = cents % 10;

    // Repeat for nickels
    coins += cents / 5;
    cents = cents % 5;

    // Remainder is now < 5, so handle with pennies
    coins += cents;

    // Print counter
    printf("%i\n", coins);
}
