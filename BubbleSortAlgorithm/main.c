#include <stdio.h>
#include <stdlib.h>

void main()
{
    int size = 5;
    int array[] = {3, 4, 1, 5, 2};

    for (int i = 0; i < size - 1; i++)
    {
        int j = i + 1;

        int x = array[i];
        int y = array[j];

        if (x > y)
        {
            array[i] = y;
            array[j] = x;
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}
