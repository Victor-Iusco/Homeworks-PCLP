#include<stdio.h>
#define Trick 7
#define Treat 11
int main() {
    int numar = 0;
    scanf("%d", &numar);
    for (int i = 1; i <= numar; i++) {
        if (i % Trick == 0 && i % Treat == 0)
            printf("TrickOrTreat ");
        else if (i % Trick == 0)
            printf("Trick ");
        else if (i % Treat == 0)
            printf("Treat ");
        else
            printf("%d ", i);
    }
    return 0;
}

