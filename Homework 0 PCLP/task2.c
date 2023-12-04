// Inputs a number and prints all the numbers from 1 to that number, each on a separate line
// printing the number and if the number is in the peremeters of the Trick or Treat game is prints
// the word assinged to it

#include <stdio.h>
#define Trick 7
#define Treat 11
int main()
{
    int number = 0;
    scanf("%d", &number); // reads a number
    for (int i = 1; i <= number; i++)
    {
        if (i % Trick == 0 && i % Treat == 0)
            printf("TrickOrTreat ");    // prints TrickOrTreat if the number is divisible by both Trick and Treat
        else if (i % Trick == 0)
            printf("Trick ");           // prints Trick if the number is divisible by Trick
        else if (i % Treat == 0)
            printf("Treat ");           // prints Treat if the number is divisible by Treat
        else
            printf("%d ", i);
    }
    return 0;
}
