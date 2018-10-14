// caesar.c
// Encrypts user-supplied plaintext using a Caesar cipher.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Ensure key is non-negative
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("Key must be a non-negative integer.\n");
        return 1;
    }

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // Encrypt plaintext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Handle uppercase characters
        if (isupper(plaintext[i]))
        {
            printf("%c", ((plaintext[i] - 'A' + key) % 26) + 'A');
        }

        // Handle lowercase characters
        else if (islower(plaintext[i]))
        {
            printf("%c", ((plaintext[i] - 'a' + key) % 26) + 'a');
        }

        // Handle other characters
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
