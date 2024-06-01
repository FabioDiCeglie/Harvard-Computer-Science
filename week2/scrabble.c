#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Define a structure to hold a letter and its corresponding value
typedef struct {
    char letter;
    int value;
} LetterValue;

// Initialize the array with the given values
LetterValue letter_values[26] = {
    {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1},
    {'F', 4}, {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8},
    {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1}, {'O', 1},
    {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1},
    {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8}, {'Y', 4}, {'Z', 10}
};

// Function to get the value of a letter
int get_letter_value(char letter) {
    // Convert to uppercase if the letter is lowercase
    if (letter >= 'a' && letter <= 'z') {
        letter = letter - 'a' + 'A';
    }

    // Find the letter in the array and return its value
    for (int i = 0; i < 26; i++) {
        if (letter_values[i].letter == letter) {
            return letter_values[i].value;
        }
    }
    return 0; // Return 0 for non-alphabetic characters
}

int get_word_value(string word){
        int total_value = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            int word_value = get_letter_value(word[i]);
            total_value += word_value;
        }
        return total_value;
}

int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = get_word_value(word1);
    int score2 = get_word_value(word2);
    // // Loop through each character in the string
    // for (int i = 0; word1[i] != '\0'; i++) {
    //     // printf("Character at index %d is %c\n", i, word1[i]);
    //     int word_value = get_letter_value(word1[i]);
    //     total_value_first_word += word_value;
    // }
    // for (int i = 0; word2[i] != '\0'; i++) {
    //     // printf("Character at index %d is %c\n", i, word1[i]);
    //     int word_value = get_letter_value(word2[i]);
    //     total_value_second_word += word_value;
    // }
    // printf("Character value %d \n", total_value_first_word);
    // printf("Character value %d \n", total_value_second_word);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}




// ----------------------------------------------------------------------------------------
// DIFFERENT SOLUTION

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner   
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Keep track of score
    int score = 0;

    // Compute score for each character
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}