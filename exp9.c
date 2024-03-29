#include <stdio.h>
#include <math.h>
#include <limits.h>

void swap(int x, int y)
{
    int t;
    t = x;
    x = y;
    y = t;
}

void main()
{
    int arr[7] = {2, 4, 6, 3, 9, 8, 7};
    printf("unsorted array:");
    for (int i = 0; i <= 6; i++)
    {
        printf("%d ", arr[i]);
    }
    // selection sort algo
    for (int i = 0; i <= 6; i++)
    {
        int min = INT_MAX;
        int mindx = -1;
        for (int j = i; j <= 6; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                mindx = j;
            }
        }
        int temp = arr[mindx];
        arr[mindx] = arr[i];
        arr[i] = temp;
    }

    printf("\nsorted array:");
    for (int i = 0; i <= 6; i++)
    {
        printf("%d ", arr[i]);
    }
}