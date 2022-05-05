#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long cc_num = get_long("What is the credit card number?: ");
    long cc_numcopy = cc_num;
    int digitcounter = 1;
    
    for (; cc_num > 10; digitcounter++)
    {
        cc_num = cc_num/10;
    }
    
    

    int indexcounter = 0;
    int evencounter = 0;
    int oddcounter = 0;
    int even = 0;
    int digitcopy = digitcounter;
    int digitcardcheck = digitcounter;
    long cc_numcopycount = cc_numcopy;
    long first2 = cc_numcopy;
    for (int i=0; indexcounter < digitcounter; indexcounter++)
    {
        int currentdigit = cc_numcopy % 10;
        i = digitcopy%2;
        
        if (cc_numcopycount % 2 == 0)
        {
            if (i == 1)
            {
                even = currentdigit * 2;
                
                if (even > 9)
                {
                    even = even % 10;
                    evencounter = evencounter + even + 1;
                }
                else
                {
                    evencounter = evencounter + even;
                }
            }
        
            if (i == 0)
            {
                oddcounter = oddcounter + currentdigit;
            }
        }
        else
        {
            if (i == 0)
            {
                even = currentdigit * 2;
                
                if (even > 9)
                {
                    even = even % 10;
                    evencounter = evencounter + even + 1;
                }
                else
                {
                    evencounter = evencounter + even;
                }
            }
        
            if (i == 1)
            {
                oddcounter = oddcounter + currentdigit;
            }
        }

        digitcopy--;
        cc_numcopy = floor(cc_numcopy / 10);
        
        //printf("i: %i\n", i);
        //printf("currentdigit: %i\n", currentdigit);
        //printf("evencounter: %i\n", evencounter);
        //printf("oddcounter: %i\n", oddcounter);
        
    }
    
    int checker = oddcounter + evencounter;
    
    
    while (first2 >= 100)
    {
        first2 = first2/10;
    }
    
    if (checker % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (digitcounter != 13 && digitcounter != 15 && digitcounter != 16)
    {
        printf("INVALID\n");
    }
    else if ((first2 > 50 && first2 < 56) && digitcardcheck == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((first2 > 39 && first2 < 50) && (digitcardcheck == 13 || digitcardcheck == 16))
    {
        printf("VISA\n");
    }
    else if ((first2 == 34 || first2 == 37) && digitcardcheck == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
    

}