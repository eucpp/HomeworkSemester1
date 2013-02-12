#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int findHWVar(int student, int *homeworks)
{
	if (homeworks[student] == 1 || homeworks[student] == 2 || homeworks[student] == 3)
	{
		return homeworks[student];
	}
	int HWVar = findHWVar(homeworks[student], homeworks);
	homeworks[student] = HWVar;
	return HWVar;
}
int main()
{
	int students = 0;
	cout << "Enter count of students: ";
	cin >> students;
	while (students < 3)
	{
		cout << endl << "Count of students must be more than 3" << endl;;
		cout << "Enter count of students: ";
		cin >> students;
	}
	int *homeworks = new int[students + 1];
	cout << endl << "Enter student's number and number of homework:" << endl;
	for (int i = 1; i <= students; i++)
	{
		int studentNum = 0;
		int hwVar = 0;
		cin >> studentNum;
		cin >> hwVar;
		homeworks[studentNum] = hwVar;
	}
	cout << endl;

	for (int i = 4; i <= students; i++)
	{
		if (homeworks[i] != 1 || homeworks[i] != 2 || homeworks[i] != 3)
		{
			findHWVar(i, homeworks);
		}
	}

	for (int i = 1; i <= students; i++)
	{
		cout << "Student's num: " << i << "; num of homework: " << homeworks[i] << endl;
	}
	delete[] homeworks;

	int nothing;
	cin >> nothing;
	return 0;
}
