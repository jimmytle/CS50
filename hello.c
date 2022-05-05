#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Program that will ask for your name and print it after
    string answer = get_string("What is your name? ");
    printf("Hello, %s\n", answer);

}

