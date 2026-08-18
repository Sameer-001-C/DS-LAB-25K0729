#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of integers: ";
    cin >> n;

    int* array = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> *(array + i);
    }

    int sum = 0;
    int max = *array;
    int min = *array;

    for (int i = 0; i < n; i++)
    {
        sum += *(array + i);

        if (*(array + i) > max)
        {
            max = *(array + i);
        }

        if (*(array + i) < min)
        {
            min = *(array + i);
        }
    }

    double average = static_cast<double>(sum) / n;

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;

    delete[] array;

    return 0;
}
