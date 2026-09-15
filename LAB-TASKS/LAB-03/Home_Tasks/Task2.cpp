#include <iostream>
using namespace std;





void combSort(int arr[], int n)
{


    int gap = n;
    const double shrink = 1.3;

    bool swapped = true;

    int comparisons = 0;
    int swaps = 0;

    while (gap != 1 || swapped)
    {
        gap = gap / shrink;

        if (gap < 1)
            gap = 1;

        swapped = false;

        for (int i = 0; i + gap < n; i++)
        {
            comparisons++;

            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swaps++;
                swapped = true;
            }
        }
    }

    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

}




void bubbleSort(int arr[], int n)
{

    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

}




int main()
{
    int arr1[20];
    int arr2[20];

    for (int i = 0; i < 20; i++)
    {
        arr1[i] = 20 - i;
        arr2[i] = 20 - i;
    }


    cout << "Comb Sort:" << endl;
    combSort(arr1, 20);

    cout << endl;

    cout << "Bubble Sort:" << endl;
    bubbleSort(arr2, 20);

    return 0;
}