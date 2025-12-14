#include <iostream>
using namespace std;

void quadratic()
{
	cout << "Quadratic Equation Solver Selected.\n";
}

void kinematics()
{
	cout << "Kinematics Calculator Selected.\n";
}

void vectors()
{
	cout << "Vector Operations Selected.\n";
}

int main()
{
	cout << "=== Physics & Math Helper ===\n";
	cout << "Choose an option:\n";
	cout << "1. Quadratic Equation\n";
	cout << "2. Kinematics\n";
	cout << "3. Vectors\n";
	cout << "Enter your choice (1-3): ";

	int choice;
	cin >> choice;

	if (choice == 1)
	{
		quadratic();
	}
	else if (choice == 2)
	{
		kinematics();
	}
	else if (choice == 3)
	{
		vectors();
	}
	else
	{
		cout << "Invalid choice. Please run the program again.\n";
	}
	return 0;
}
