#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// function prototypes
int count_letters(string Text);
int count_words(string Text);
int count_sentences(string Text);

int main(void)
{
    // user enters the text
    string Text = get_string("Text : ");

    // function calls
    float words = count_words(Text);
    float L = count_letters(Text) / words * 100;
    float S = count_sentences(Text) / words * 100;

    // Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}
// function counting sentences
int count_sentences(string Text)
{
    int sentences = 0;

    for (int a = 0; a < strlen(Text); a++)

        if (Text[a] == '.' || Text[a] == '!' || Text[a] == '?')
        {
            sentences++;
        }
    return sentences;
}
// function counting words
int count_words(string Text)

{
    int words = 1;

    for (int j = 0; j < strlen(Text); j++)

        if (Text[j] == ' ')
        {
            words++;
        }

    return words;
}

// function definition
int count_letters(string Text)
{

    int letters = 0;
    // for loop length of text

    {
        for (int i = 0; i < strlen(Text); i++)
        {
            if (isalpha(Text[i]))
            {
                letters++;
            }
        }
        return letters;
    }
}
