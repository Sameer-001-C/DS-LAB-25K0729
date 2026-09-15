#include <iostream>
#include <chrono>
#include <random>


using namespace std;
using namespace chrono;




void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

}



void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}



void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
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
    }
}



void combSort(int arr[], int n)
{
    int gap = n;
    const double shrink = 1.3;

    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap = gap / shrink;

        if (gap < 1)
            gap = 1;

        swapped = false;

        for (int i = 0; i + gap < n; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}



void generateArray(int arr[], int n)
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);

    for (int i = 0; i < n; i++)
        arr[i] = dist(gen);


}



long long measureTime(void (*sortFunction)(int[], int), int original[], int n)
{

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        arr[i] = original[i];

    auto start = high_resolution_clock::now();

    sortFunction(arr, n);

    auto end = high_resolution_clock::now();

    delete[] arr;

    return duration_cast<milliseconds>(end - start).count();


}




int main()
{


    int sizes[] = {100, 1000, 10000, 50000};

    for (int n : sizes)
    {
        int* arr = new int[n];

        // generateArray(arr, n);   // for a random array

        // for a sorted array (in order)
        //for(int i = 0; i < n; i++)
        //{
        //    arr[i] = i;
        //}

        // for a sorted array (reverse order)
        for(int i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }

        cout << "\nn = " << n << endl;

        cout << "Bubble Sort: "
             << measureTime(bubbleSort, arr, n)
             << " ms" << endl;

        cout << "Selection Sort: "
             << measureTime(selectionSort, arr, n)
             << " ms" << endl;

        cout << "Insertion Sort: "
             << measureTime(insertionSort, arr, n)
             << " ms" << endl;

        cout << "Shell Sort: "
             << measureTime(shellSort, arr, n)
             << " ms" << endl;

        cout << "Comb Sort: "
             << measureTime(combSort, arr, n)
             << " ms" << endl;

        delete[] arr;
    }



    return 0;


}