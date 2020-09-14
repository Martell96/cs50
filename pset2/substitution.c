#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    const int ASCII_A = 65;
    if (argc != 2) // Check if we have anything else than 2 arguments
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26) // Check if our key is anything else than 26 characters long
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        string key = argv[1];
        for (int i = 0; i < strlen(key); i++) // Check that our key is valid
        {
            if (!isalpha(key[i])) // Confirm that all characters in our key are alphabet characters
            {
                return 1;
            }
            for (int j = i + 1; j < strlen(key); j++) // Confirm that we don't have any duplicate key characters
            {
                if (key[i] == key[j])
                {
                    return 1;
                }
            }
        }
        string plaintext = get_string("plaintext: "); // Get plaintext from user
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++) // Iterate over plaintext characters
        {
            if (isalpha(plaintext[i])) // If current character is from alphabet, apply key
            {
                int l = key[toupper(plaintext[i]) - ASCII_A]; // Get equivalent letter from key

                if (isupper(plaintext[i])) // If plaintext character is uppercase, print equivalent letter uppercase
                {
                    printf("%c", toupper(l));
                }
                else // If plaintext character is lowercase, print equivalent letter lowercase
                {
                    printf("%c", tolower(l));
                }
            }
            else // If character is not from alphabet, print as is
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
}
