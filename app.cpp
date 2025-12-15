#include <iostream>
#include <cmath>
using namespace std;

void quadratic()
{
	cout << "========== Quadratic Equation Solver Selected ==========\n";

	// get a
	cout << "========== Please enter a: ==========\n";
	double a;
	cin >> a;

	if (a == 0)
	{
		cout << "This is not a quadratic equation (a cannot be 0).\n";
		return;
	}

	// get b
	cout << "========== Please enter b: ==========\n";
	double b;
	cin >> b;

	// get c
	cout << "========== Please enter c: ==========\n";
	double c;
	cin >> c;

	// display equation
	cout << "Your equation is "
		 << a << "x^2 "
		 << (b > 0 ? "+ " : "- ") << abs(b) << "x "
		 << (c > 0 ? "+ " : "- ") << abs(c)
		 << " = 0\n";

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
		cout << "The equation is (x - " << root << ")^2 = 0\n";
	}
	else
	{
		double root1 = (-b + sqrt(delta)) / (2 * a);
		double root2 = (-b - sqrt(delta)) / (2 * a);
		cout << "Two real roots exist: x1 = " << root1 << ", x2 = " << root2 << "\n";
		cout << "The equation is (x "
			 << (root1 < 0 ? "+ " : "- ") << abs(root1)
			 << ")(x "
			 << (root2 < 0 ? "+ " : "- ") << abs(root2)
			 << ") = 0\n";
	}
}

void kinematics()
{
	cout << "========== Kinematics Calculator Selected ==========\n";

	cout << "Choose a kinematics problem type:\n";
	cout << "1. Motion with constant velocity\n";
	cout << "2. Motion with constant acceleration\n";
	cout << "Enter your choice (1-2): ";

	int type;
	cin >> type;

	if (type == 1)
	{
		cout << "========== Constant Velocity Selected ==========\n";
		// all the variables : initial position (x0), final position (x), velocity (v), time (t)
		cout << "choose the variable you want to solve for:\n";
		cout << "1. Initial Position (x0)\n";
		cout << "2. Final Position (x)\n";
		cout << "3. Velocity (v)\n";
		cout << "4. Time (t)\n";
		cout << "Enter your choice (1-4): ";

		int choice;
		cin >> choice;

		if (choice == 1)
		{
			cout << "You chose to solve for Initial Position (x0).\n";
			// enter variables
			cout << "Enter Final Position (x): ";
			double x;
			cin >> x;
			cout << "Enter Velocity (v): ";
			double v;
			cin >> v;
			cout << "Enter Time (t): ";
			double t;
			cin >> t;

			// edge case for negative time
			if (t < 0)
			{
				cout << "Time cannot be negative.\n";
				return;
			}
			// calculate initial position
			double x0 = x - v * t;
			cout << "Initial Position (x0) = " << x0 << "\n";
		}
		else if (choice == 2)
		{
			cout << "You chose to solve for Final Position (x).\n";
		}
		else if (choice == 3)
		{
			cout << "You chose to solve for Velocity (v).\n";
		}
		else if (choice == 4)
		{
			cout << "You chose to solve for Time (t).\n";
		}
		else
		{
			cout << "Invalid choice for variable to solve for.\n";
		}
	}
	else if (type == 2)
	{
		cout << "========== Constant Acceleration Selected ==========\n";
	}
	else
	{
		cout << "========== Invalid choice for kinematics problem type ==========\n";
	}
}

void vectors()
{
	cout << "========== Vector Operations Selected ==========\n";
}

int main()
{
	cout << "========== Physics & Math Helper ==========\n";
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
