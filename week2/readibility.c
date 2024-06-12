#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = 0;
    int words = 1;
    int sentences = 0;

    if (!isalpha(text[0])) {
        printf("The key must be alphabetical\n");
        return 1;
    }

    for(int i = 0; i <= strlen(text) - 1; i++)
    {
        if(text[i] == ' ')
        {
            words += 1;
        }
        if(text[i] != ' ' && text[i] != '!' && text[i] != '?' && text[i] != '.' && text[i] != ',' && text[i] != '\'' )
        {
            letters += 1;
        }
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }

    // Compute the Coleman-Liau index
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", index);
    }

    return 0;
}