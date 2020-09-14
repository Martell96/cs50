#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

// Initial function declaration
void count_letters(string text, int *l, int *w, int *s);
int get_index(int l, int w, int s);

int main(void)
{
    string s = get_string("Text: "); // Ask for the text we will analyze
    int letters, words, sentences; // Create the variables to store the number of letters, words, and sentences

    count_letters(s, &letters, &words, &sentences); // Call count letters and pass the pointer references of our variables

    int index = get_index(letters, words, sentences); // Calculate the index using get_index

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

void count_letters(string text, int *l, int *w, int *s) // Using the pointer references to return more than one value back
{
    *l = 0;
    *w = 1; // Starting with 1 for workaround for last word.
    *s = 0;

    for (int c = 0; c < strlen(text); c++)
    {
        if ((text[c] >= 'A' && text[c] <= 'Z') || (text[c] >= 'a' && text[c] <= 'z'))
        {
            *l += 1;
        }
        else if (text[c] == ' ')
        {
            *w += 1;
        }
        else if (text[c] == '?' || text[c] == '.' || text[c] == '!')
        {
            *s += 1;
        }
    }
}

int get_index(int l, int w, int s)
{
    return round(0.0588 * (l / (float) w * 100) - 0.296 * (s / (float) w * 100) - 15.8);
}
