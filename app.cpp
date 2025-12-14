#include <iostream>
#include <cmath>
using namespace std;

void quadratic()
{
	cout << "Quadratic Equation Solver Selected.\n";

	// get a
	cout << "Please enter a :";
	double a;
	cin >> a;

	// get b
	cout << "Please enter b :";
	double b;
	cin >> b;

	// get c
	cout << "Please enter c :";
	double c;
	cin >> c;

	// display equation
	cout << "your equation is " << a << "x^2 + " << b << "x + " << c << " = 0\n";

	// calculate delta
	double delta = (b * b) - (4 * a * c);
	cout << "Delta is " << delta << "\n";

	// calculate roots
	if (delta < 0)
	{
		cout << "No real roots exist.\n";
	}
	else if (delta == 0)
	{
		double root = -b / (2 * a);
		cout << "One real root exists: x = " << root << "\n";
		cout << "the equation is (x - " << root << ")^2 = 0\n";
	}
	else
	{
		double root1 = (-b + sqrt(delta)) / (2 * a);
		double root2 = (-b - sqrt(delta)) / (2 * a);
		cout << "Two real roots exist: x1 = " << root1 << ", x2 = " << root2 << "\n";
		cout << "the equation is (x - " << root1 << ")(x - " << root2 << ") = 0\n";
	}
}

void kinematics()
{
	cout << "Kinematics Calculator Selected.\n";

	// types of problems
	cout << "Choose a kinematics problem type:\n";
	cout << "1. motion with constant velocity\n";
	cout << "2. motion with constant acceleration\n";
	cout << "Enter your choice (1-2): ";

	int type;
	cin >> type;

	if (type == 1)
	{
		cout << "Constant Velocity Selected.\n";
	}
	else if (type == 2)
	{
		cout << "Constant Acceleration Selected.\n";
	}
	else
	{
		cout << "Invalid choice for kinematics problem type.\n";
	}
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
