// C Program to generate a random number in a given
// range using rand_r()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRandoms(int min, int max, int count)
{
    printf("Random numbers between %d and %d: ", min, max);

    // Taking current time as seed
    srand(time(0));

    for (int i = 0; i < count; i++)
    {
        // Generate a random number in the range [min, max]
        int rd_num = rand() % (max - min + 1) + min;
        printf("%d ", rd_num);
    }
}

int main()
{
    int min = 0, max = 255, count = 10;
    printRandoms(min, max, count);
    return 0;
}
