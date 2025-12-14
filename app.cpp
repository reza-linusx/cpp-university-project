#include <iostream>
using namespace std;

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
		cout << "You selected Quadratic Equation.\n";
	}
	else if (choice == 2)
	{
		cout << "You selected Kinematics.\n";
	}
	else if (choice == 3)
	{
		cout << "You selected Vectors.\n";
	}
	else
	{
		cout << "Invalid choice. Please run the program again.\n";
	}
	return 0;
}
