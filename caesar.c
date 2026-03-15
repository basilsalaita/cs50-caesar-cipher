#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char ch = plaintext[i];

        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                int pos = ch - 'A';
                int newpos = (pos + key) % 26;
                char cipher = newpos + 'A';
                printf("%c", cipher);
            }
            else
            {
                int pos = ch - 'a';
                int newpos = (pos + key) % 26;
                char cipher = newpos + 'a';
                printf("%c", cipher);
            }
        }
        else
        {
            printf("%c", ch);
        }
    }

    printf("\n");
    return 0;
}
