#include <iostream>
using namespace std;



int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;


    int *arr = new int[n];

    cout << "Enter " << n << " elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    int sum = 0;
    double average;

    int min = arr[0];
    int max = arr[0];

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        else if(arr[i] < min)
        {
            min = arr[i];
        }

        sum += arr[i];
    }

    average = (double)sum/n;

	cout << "Sum = " << sum;
	cout << ", Average = " << average;
	cout << ", Max = " << max;
    cout << ", Min: " << min << endl;
    
    
    

	delete[] arr;


    return 0;
}
