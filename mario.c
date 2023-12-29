#include <stdio.h>

int main()
{
    int i=0,n;
    int inputCheck;
    

    do
    {
        printf("Height: ");
        inputCheck = scanf("%d", &n);

        if (inputCheck != 1) {
            while (getchar() != '\n');
        }

    } while (inputCheck != 1 || n < 1 || n > 8);
    int block=n-n+1;
    int space = n-1;
    while (i!=n)
    {
        
        
       for ( int sp = 0; sp < space ; sp++)
       {
            printf(" ");
       }
       
        for (int j = block; j > 0; j--)
        {
            printf("#");
        }
        printf("  ");
        for (int k = block; k > 0; k--)
        {
            printf("#");
        }
        printf("\n");
        space--;
        block++;
        i++;
    }
    
}
