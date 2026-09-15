#include <iostream>
using namespace std;


/*

Shell Sort is generally faster than Insertion Sort because it compares elements that are 
far apart, and then swaps, using the gaps, which helps shrink and sort the array more quickly.
This reduces the number of instructions compared to a normal insertion sort.

*/

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}



void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = arr[j];
            int i = j;

            while (i >= gap && arr[i - gap] > temp)
            {
                arr[i] = arr[i - gap];
                i -= gap;
            }

            arr[i] = temp;
        }

        cout << "After gap " << gap << ": ";
        printArray(arr, n);
    }
}




int main()
{
    int arr[] = {12, 34, 54, 2, 3};
    int n = 5;

    shellSort(arr, n);

    cout << "Final sorted array: ";
    printArray(arr, n);

    return 0;
}
