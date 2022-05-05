#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int population = get_int("What is the population size for the llamas?: ");

    if (population < 9)
    {
        do
        {
            population = get_int("Population size has to be greater than 9, what is the population size for the llamas?: ");
        }
        while (population < 9);
    }
    // TODO: Prompt for end size

    int end_population;

    for (end_population = get_int("How many llamas are we expecting?: "); end_population < population;)
    {
        end_population = get_int("Ending population has to be greater than starting population, how many llamas are we expecting?: ");
    }
    // TODO: Calculate number of years until we reach threshold
    int born;
    int death;
    int counter_years;
    for (counter_years = 0 ; population < end_population; counter_years++)
    {
        born = population / 3;
        
        death = population / 4;
        
        population = population + born - death;
    }    
    // TODO: Print number of years
    printf("Years: %i\n", counter_years);
}