#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    char *encryptkey = argv[1];
    int keyLength = strlen(encryptkey);
    if (keyLength != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < keyLength; i++)
    {
        if (!isalpha(encryptkey[i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }

        for (int j = i + 1; j < keyLength; j++)
        {
            if (encryptkey[i] == encryptkey[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    char normalLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char input[100];
    printf("Plaintext: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Ciphertext: ");
    for (int i = 0, length = strlen(input); i < length; i++)
    {
        char c = input[i];
        if (isalpha(c))
        {
            char uppercase = toupper(c);
            int index = uppercase - 'A';
            char encryptedChar = encryptkey[index];
            if (islower(c))
            {
                printf("%c", tolower(encryptedChar));
            }
            else
            {
                printf("%c", toupper(encryptedChar));
            }
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}