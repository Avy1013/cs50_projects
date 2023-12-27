#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start, end, temp, years = 0;
    ;
    // TODO: Prompt for start size
    do
    {
        printf("Start size: ");
        scanf("%d", &start);
    }
    while (start < 9);

    // TODO: Prompt for end size
    do
    {
        printf("End size: ");
        scanf("%d", &end);
    }
    while (end < start);
    // TODO: Calculate number of years until we reach threshold
    while (end != start)
    {
        years++;
        start = (start + ((int) (start / 3) - (int) (start / 4)));
        if (start > end)
        {
            break;
        }
    }
    // TODO: Print number of years
    printf("Years: %d\n", years);
    printf("\n");
}
