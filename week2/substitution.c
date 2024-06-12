#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    // exit if are more or less than one key
    if (argc == 2)
    {
        size_t string_length = strlen(key);
        if (string_length != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        for (int i = 1; i <= strlen(key) - 1; i++)
        {
            // exit if are not alphabetical
            if (!isalpha(key[i]))
            {
                printf("The key must be alphabetical\n");
                return 1;
            }
            // handles duplicate characters in key
            for (int j = 0; j <= strlen(key) - 1; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (key[i] == key[j])
                {
                    printf("The key must contain unique char\n");
                    return 1;
                }
            }
        }

        string plaintext = get_string("plaintext: ");
        char chipertext[strlen(plaintext)];
        chipertext[0] = '\0';

        // Encrypt the key and transform it to lower or uppercase after check the corresponding alphabetical position
        for (int i = 0; i <= strlen(plaintext) - 1; i++)
        {
            int alphabetic_index;
            if (islower(plaintext[i]))
            {
                alphabetic_index = plaintext[i] - 'a';
            }
            else
            {
                alphabetic_index = plaintext[i] - 'A';
            }
            char letter = argv[1][alphabetic_index];
            if (!((plaintext[i] >= 'a' && plaintext[i] <= 'z') || (plaintext[i] >= 'A' && plaintext[i] <= 'Z')))
            {
                letter = plaintext[i];
            }
            if (isupper(plaintext[i]))
            {
                letter = toupper(letter);
            }
            else if (islower(plaintext[i]))
            {
                letter = tolower(letter);
            }
            strncat(chipertext, &letter, 1);
        }
        printf("ciphertext: %s\n", chipertext);
        return 0;
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}
