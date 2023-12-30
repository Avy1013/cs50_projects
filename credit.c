#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addsum(char input[]);
int inp_size;
int sum_of_digits(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    char input[50]; //= {'3', '7', '8', '2', '8', '2', '2', '2', '4', '6', '3', '1', '0', '0', '0', '5','\0'};

    // do
    // {
    //     printf("Number: ");
    //     fgets(input, sizeof(input), stdin);
    //     inp_size = strlen(input)-1;
    //     int position = strcspn(input, "-"); // Find the position of the hyphen
    //     if (position < inp_size)
    //     {
    //         input[position] = '\0'; // Null terminate at the position of the hyphen
    //     }

    // } while (inp_size < 13 || inp_size > 16);

    printf("Number: ");
    fgets(input, sizeof(input), stdin);
    inp_size = strlen(input) - 1;

    if (inp_size >= 13 && inp_size <= 16)
    {
        int mkl = addsum(input);
        if (mkl % 10 == 0)
        {
            if (input[0] == '5' && (input[1] == '4' || input[1] == '1' || input[1] == '2' || input[1] == '3' || input[1] == '5') &&
                inp_size == 16)
            {
                printf("MASTERCARD\n");
            }
            else if (input[0] == '4' && (inp_size == 13 || inp_size == 16))
            {
                printf("VISA\n");
            }
            else if ((input[0] == '3' && (input[1] == '4' || input[1] == '7')) && inp_size == 15)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }

    return 0;
}

int addsum(char input[])
{
    int card[16];

    char *ptr;
    int *ptr2;
    ptr = input;
    ptr2 = card;

    for (size_t i = 0; i < inp_size; i++)
    {

        *ptr2 = *ptr - '0';
        ptr++;
        ptr2++;
        if (*ptr == '\0')
        {
            break;
        }
    }

    int addsum = 0;

    for (int i = inp_size - 2; i >= 0; i -= 2)
    {
        card[i] = sum_of_digits(2 * card[i]);
    }

    for (int i = 0; i < inp_size; i++)
    {
        addsum += card[i];
    }

    return addsum;
}
