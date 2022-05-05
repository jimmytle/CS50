#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int compute_grade(string sentence);

int main(void)
{
    //Get input from user
    string sentence = get_string("Text: ");
    
    //Calls the function compute_grade
    int index = compute_grade(sentence);
    
    //Computes the grade level
    if (index > 16)
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

int compute_grade(string sentence)
{
    int sent_count = 0;
    int letter_count = 0;
    int word_count = 1; //Count starts at one because it can count the last word
    
    for (int i = 0, n = strlen(sentence); i < n; i++)
    {
        //Changes the letter to lower case
        if (isupper(sentence[i]))
        {
            sentence[i] = tolower(sentence[i]);
        }
        
        //Add to counter if a-z
        if (sentence[i] >= 97 && sentence[i] <= 122)
        {
            letter_count++;
        }
        
        //Add to counter whenever there is a space (this will count for words)
        else if (sentence[i] == 32)
        {
            word_count++;
        }
        
        //Add to counter if its a .!?
        else if (sentence[i] == 33 || sentence[i] == 46 || sentence[i] == 63)
        {
            sent_count++;
        }
        

        
    }
    //printf("Letter: %i\nWord: %i\nSentence: %i", letter_count,word_count,sent_count );
    float l = ((float)letter_count / word_count) * 100;
    float s = ((float)sent_count / word_count) * 100;
    int index = round(0.0588 * l - .296 * s - 15.8);
    return index;
}