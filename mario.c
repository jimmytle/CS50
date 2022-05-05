#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user to input height of mario blocks
    int height = get_int("How tall do you want the Mario blocks? : ");
    
    //Will prompt user to pick 1-8 if not in that parameter
    if (height < 1 || height > 8)
    {
        do
        {
            height = get_int("Height has to be between 1 and 8, input new height: ");
        }
        while (height < 1 || height > 8);
    }
    
    //Counter for height blocks
    int counter_height;
    
    //Will create the rows that user input
    for (int i = 0; i < height ; i++)
    {
        counter_height = height;
        
        //This counter will ensure the right number of # blocks created
        counter_height = counter_height - i;
        
        //Will create the columns on the left side
        for (int j = 1; j <= height ; j++)
        {
            if (j < counter_height)
            {
                printf(" ");
            }
            
            if (j >= counter_height)
            {
                printf("#");
            }
        }
        
        printf("  ");
        
        //Will create the columns on the right side
        for (int k = 1; k <= height ; k++)
        {
            
            if (k >= counter_height)
            {
                printf("#");
            }
        }
        //Will start the new line after the loop is done
        printf("\n");
    }
}