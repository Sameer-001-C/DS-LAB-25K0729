#include <iostream>
using namespace std;

class Student
{
	private:
		int *marks;
		int size;
		
	public:
		Student(int size)
		{
			this->size = size;
			marks = new int[size];
		}
		
		Student(const Student &s)
		{
			this->size = s.size;
			
			marks = new int[size];
			
			for(int i = 0; i < size; i++)
			{
				this->marks[i] = s.marks[i];
			}
		}
		
		Student& operator= (const Student &s)
		{
			this->size = s.size;
			
			delete[] marks;
			
			marks = new int[size];
			
			for(int i = 0; i < size; i++)
			{
				this->marks[i] = s.marks[i];
			}
			
			return *this;
		}
		
		
		void Input()
		{
			for(int i = 0; i < size; i++)
			{
				cout << "Enter marks for subject " << i + 1 << ": ";
				cin >> marks[i];
			}
		}
		
		void Display() const
		{
			cout << "\n ===================== Student Marks =========================== \n" << endl;
			for(int i = 0; i < size; i++)
			{
				cout << "Marks for Subject " << i+1 << ": " << marks[i] << endl;
			}
		}
		
		double CalculateAverage() const
		{
			int total = 0;
			for(int i = 0; i < size; i++)
			{
				total += marks[i];
			}
			
			return total/size;
		}
		
		~Student()
		{
			delete[] marks;
		}
		
		
};

/*
int main()
{
	int size;
	cout << "Please enter number of students: ";
	cin >> size;
	
	int *marks;
	
	marks = new int[size];
	int total = 0;
	
	for(int i = 0; i < size; i++)
	{
		cout << "Enter marks for student " << i + 1 << ": ";
		cin >> marks[i];
		total += marks[i];
	}
	
	cout << "\n=========================Displaying Student Marks =======================" << endl;
	
	
	for(int i = 0; i < size; i++)
	{
		cout << "Marks for Student " << i+1 << ": " << marks[i] << endl;
	}
	
	cout << "Average = " << total/size << endl;
	
	
	return 0;
}
*/

int main()
{
	int size;
	cout << "Enter number of students: ";
	cin >> size;
	
	Student s1(size);
	
	s1.Input();
	s1.Display();
	
	cout << "Average: " << s1.CalculateAverage() << endl;
	
	Student s2 = s1;
	
	s2.Display();
	cout << "Average: " << s2.CalculateAverage() << endl;
}