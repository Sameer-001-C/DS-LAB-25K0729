#include <iostream>
using namespace std;


/*

Interpolation Search performs good on  uniformly distributed data because it can estimate the aproximate position
of the key, giving an average complexity of O(log log n). With non-uniform data, this position estimate 
becomes less effective as well as accurate, causing the search to behave more like Linear Search and approach O(n).

*/

int interpolationSearch(int arr[], int n, int key)
{


    int low = 0;
    int high = n - 1;

    int iterations = 0;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        iterations++;

        if (arr[low] == arr[high])
        {
            if (arr[low] == key)
                return low;

            return -1;
        }

        int pos = low + ((key - arr[low]) * (high - low) /
                         (arr[high] - arr[low]));

        if (arr[pos] == key)
            return pos;

        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;

    }

    return -1;

}




int main()
{
    int arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};

    int n = 20;

    int key = 75;

    int result = interpolationSearch(arr, n, key);

    cout << "\n======Searching for 75 in the first array====\n" << endl;

    if (result != -1)
        cout << "Key found at index: " << result << endl;
    else
        cout << "Key not found" << endl;



    cout << "\n======Searching for 1000 in the second array====\n" << endl;

    result = interpolationSearch(arr, n, key);

    cout << "\n======Searching for 75 in the first array====\n" << endl;

    if (result != -1)
        cout << "Key found at index: " << result << endl;
    else
        cout << "Key not found" << endl;




    return 0;

}