#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    //Takes user input and makes sure that change is positive.
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    //Converts dollars to cents
    int cents = round(dollars * 100);

    //A value for tracking how many coins are used.
    int coinCounter = 0;

    //Counts coins from highest denomination to lowest and subtracts each value from the remaining total while adding a new coin to the coin counter.
    while(cents > 0)
    {
        if(cents > 24)
        {
            cents -= 25;
            coinCounter++;
        }
        else if (cents > 9)
        {
            cents -= 10;
            coinCounter++;
        }
        else if (cents > 4)
        {
            cents -= 5;
            coinCounter++;
        }
        else
        {
            cents--;
            coinCounter++;
        }
    }

    //displays the result for amount of coins.
    printf("%i\n", coinCounter);
}