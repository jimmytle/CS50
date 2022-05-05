#include <stdio.h>
#include <cs50.h>
#include <math.h>

void cent_counter(int cents);

int main(void)
{
    //Get how much change is due
    float change = get_float("How much is the change?: ");
    
    //Amount has to be positive or no change is due.
    while (change < 0)
    {
        change = get_float("Change has to be a positive number, how much is the change?: ");
    }
    
    //Change it to whole numbers
    int cents = round(change * 100);
    
    //Calls the class, cent_counter to run the change
    cent_counter(cents);
    
}

void cent_counter(int cents)
{
    //Count how many cents has been given out
    int cent_count = 0;
    
    //Gives 25 cent if it is applicable
    for (; cents >= 25 ; cent_count++)
    {
        cents = cents - 25;
    }
    
    //Gives 10 cent if it is applicable
    for (; cents >= 10 ; cent_count++)
    {
        cents = cents - 10;
    }
    
    //Gives 5 cent if it is applicable
    for (; cents >= 5 ; cent_count++)
    {
        cents = cents - 5;
    }
    
    //Give 1 cent if it is applicable
    for (; cents >= 1 ; cent_count++)
    {
        cents = cents - 1;
    }
    
    printf("%i\n", cent_count);
}