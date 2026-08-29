#include <iostream>
using namespace std;

void insertSubject(int** arr, int totalStudents, int* courses, int student, int marks)
{
    if(student < 0 || student >= totalStudents)
    {
        cout << "Invalid student index." << endl;
        return;
    }

    int* temp = new int[courses[student] + 1];

    for(int i = 0; i < courses[student]; i++)
    {
        temp[i] = arr[student][i];
    }

    temp[courses[student]] = marks;

    courses[student]++;

    delete[] arr[student];

    arr[student] = temp;

}



int main()
{
    int n; // number of students

    cout << "Enter number of students: ";
    cin >> n;

    int **arr = new int* [n];

    int *courses = new int [n];

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter the number of courses student " << i+1 << " is enrolled in: ";
        cin >> courses[i];

        arr[i] = new int [courses[i]];

        for(int j = 0; j < courses[i]; j++)
        {
            cout << "Enter marks for student " << i+1 << " for subject " << j+1 << " :";
            cin >> arr[i][j];
        }
    }

    double* averages = new double [n];


    // displaying all marks of each student
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        cout << "\n====== Student " << i+1 << " ==========\n" << endl;

        for(int j = 0; j < courses[i]; j++)
        {
            cout << "Marks for course " << j+1 << " :" << arr[i][j] << endl;
            sum += arr[i][j];
        }

        averages[i] = (double)sum/courses[i];

        cout << "\nAverage: " << averages[i] << endl;
    }


    int maxIdx = 0;
    int minIdx = 0;

    // calculating max average
    for(int i = 0; i < n; i++)
    {
        if(averages[i] > averages[maxIdx])
        {
            maxIdx = i;
        }

        if(averages[i] < averages[minIdx])
        {
            minIdx = i;
        }
    }

    cout << "Student with the max average: Student " <<maxIdx + 1 << ", with an average of: " << averages[maxIdx] << endl;
    cout << "Student with the min average: Student " <<minIdx + 1 << ", with an average of: " << averages[minIdx] << endl;


    insertSubject(arr, n, courses, 0, 100);

    for(int i = 0; i < courses[0]; i++)
    {
        cout << "Student 0 course: " << i+1 << " : "<< arr[0][i] << endl;
    }



    

    delete[] courses;
    delete[] averages;

    for(int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;


    return 0;
}