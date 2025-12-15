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
			// enter variables
			cout << "Enter Initial Position (x0): ";
			double x0;
			cin >> x0;
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
			// calculate final position
			double x = x0 + v * t;
			cout << "Final Position (x) = " << x << "\n";
		}
		else if (choice == 3)
		{
			cout << "You chose to solve for Velocity (v).\n";
			// enter variables
			cout << "Enter Initial Position (x0): ";
			double x0;
			cin >> x0;
			cout << "Enter Final Position (x): ";
			double x;
			cin >> x;
			cout << "Enter Time (t): ";
			double t;
			cin >> t;
			// edge case for zero or negative time
			if (t <= 0)
			{
				cout << "Time must be positive and non-zero.\n";
				return;
			}
			// calculate velocity
			double v = (x - x0) / t;
			cout << "Velocity (v) = " << v << "\n";
		}
		else if (choice == 4)
		{
			cout << "You chose to solve for Time (t).\n";
			// enter variables
			cout << "Enter Initial Position (x0): ";
			double x0;
			cin >> x0;
			cout << "Enter Final Position (x): ";
			double x;
			cin >> x;
			cout << "Enter Velocity (v): ";
			double v;
			cin >> v;
			// edge case for zero velocity
			if (v == 0)
			{
				cout << "Velocity cannot be zero.\n";
				return;
			}
			// calculate time
			double t = (x - x0) / v;
			cout << "Time (t) = " << t << "\n";
		}
		else
		{
			cout << "Invalid choice for variable to solve for.\n";
		}
	}
	else if (type == 2)
	{
		cout << "========== Constant Acceleration Selected ==========\n";
		// chose variable to solve for
		cout << "choose the variable you want to solve for:\n";
		cout << "1. Initial Velocity (v0)\n";
		cout << "2. Final Velocity (v)\n";
		cout << "3. Acceleration (a)\n";
		cout << "4. Time (t)\n";
		cout << "5. Displacement (d)\n";
		cout << "Enter your choice (1-5): ";
		int choice;
		cin >> choice;

		// calculations
		if (choice == 1)
		{
			// solve for initial velocity (v0)
			// initial velocity has 2 formulas
			// we either have final velocity, acceleration, and time
			// or we have displacement, final velocity, and acceleration
			// so we need to gather information from the user and then decide what to use
			cout << "You chose to solve for Initial Velocity (v0).\n";
			cout << "what are your available variables?.\n";
			cout << "1. final velocity (v), acceleration (a), and time (t)\n";
			cout << "2. displacement (d), final velocity (v), and acceleration (a)\n";
			cout << "Enter your choice (1-2): ";
			int subChoice;
			cin >> subChoice;
			if (subChoice == 1)
			{
				cout << "Enter Final Velocity (v): ";
				double v;
				cin >> v;
				cout << "Enter Acceleration (a): ";
				double a;
				cin >> a;
				cout << "Enter Time (t): ";
				double t;
				cin >> t;

				// edge case for zero or negative time
				if (t <= 0)
				{
					cout << "Time must be positive and non-zero.\n";
					return;
				}
				// calculate initial velocity
				double v0 = v - a * t;
				cout << "Initial Velocity (v0) = " << v0 << "\n";
			}
			else if (subChoice == 2)
			{
				cout << "Enter Displacement (d): ";
				double d;
				cin >> d;

				cout << "Enter Final Velocity (v): ";
				double v;
				cin >> v;

				cout << "Enter Acceleration (a): ";
				double a;
				cin >> a;

				// compute inside of sqrt
				double value = v * v - 2 * a * d;

				if (value < 0)
				{
					cout << "Error: The values lead to a negative number under the square root.\n";
					cout << "Please check your inputs";
					return;
				}

				double v0 = sqrt(value);
				cout << "Initial Velocity (v0) = " << v0 << "\n";
			}
			else
			{
				cout << "Invalid choice for sub-option.\n";
			}
		}
		else if (choice == 2)
		{
			// solve for final velocity (v)
			cout << "You chose to solve for Final Velocity (v).\n";
			cout << "what are your available variables?.\n";
			cout << "1. initial velocity (v0), acceleration (a), and time (t)\n";
			cout << "2. displacement (d), initial velocity (v0), and acceleration (a)\n";
			cout << "Enter your choice (1-2): ";
			int subChoice;
			cin >> subChoice;

			if (subChoice == 1)
			{
				cout << "Enter Initial Velocity (v0): ";
				double v0;
				cin >> v0;
				cout << "Enter Acceleration (a): ";
				double a;
				cin >> a;
				cout << "Enter Time (t): ";
				double t;
				cin >> t;

				// edge case for zero or negative time
				if (t <= 0)
				{
					cout << "Time must be positive and non-zero.\n";
					return;
				}
				// calculate final velocity
				double v = v0 + a * t;
				cout << "Final Velocity (v) = " << v << "\n";
			}
			else if (subChoice == 2)
			{
				cout << "Enter Displacement (d): ";
				double d;
				cin >> d;

				cout << "Enter Initial Velocity (v0): ";
				double v0;
				cin >> v0;

				cout << "Enter Acceleration (a): ";
				double a;
				cin >> a;

				// compute inside of sqrt
				double value = v0 * v0 + 2 * a * d;

				if (value < 0)
				{
					cout << "Error: The values lead to a negative number under the square root.\n";
					cout << "Please check your inputs";
					return;
				}

				double v = sqrt(value);
				cout << "Final Velocity (v) = " << v << "\n";
			}
			else
			{
				cout << "Invalid choice for sub-option.\n";
			}
		}
		else if (choice == 3)
		{
			// solve for acceleration (a)
			cout << "You chose to solve for Acceleration (a).\n";
			cout << "what are your available variables?.\n";
			cout << "1. initial velocity (v0), final velocity (v), and time (t)\n";
			cout << "2. displacement (d), initial velocity (v0), and time (t)\n";
			cout << "3. initial velocity (v0), final velocity (v), and displacement (d)\n";
			cout << "Enter your choice (1-3):";
			int subChoice;
			cin >> subChoice;

			if (subChoice == 1)
			{
				cout << "Enter Initial Velocity (v0): ";
				double v0;
				cin >> v0;
				cout << "Enter Final Velocity (v): ";
				double v;
				cin >> v;
				cout << "Enter Time (t): ";
				double t;
				cin >> t;

				// edge case for zero or negative time
				if (t <= 0)
				{
					cout << "Time must be positive and non-zero.\n";
					return;
				}
				// calculate acceleration
				double a = (v - v0) / t;
				cout << "Acceleration (a) = " << a << "\n";
			}
			else if (subChoice == 2)
			{
				cout << "Enter Displacement (d): ";
				double d;
				cin >> d;

				cout << "Enter Initial Velocity (v0): ";
				double v0;
				cin >> v0;

				cout << "Enter Time (t): ";
				double t;
				cin >> t;

				// edge case for zero or negative time
				if (t <= 0)
				{
					cout << "Time must be positive and non-zero.\n";
					return;
				}

				// calculate acceleration
				double a = (2 * (d - v0 * t)) / (t * t);
				cout << "Acceleration (a) = " << a << "\n";
			}
			else if (subChoice == 3)
			{
				cout << "Enter Initial Velocity (v0): ";
				double v0;
				cin >> v0;

				cout << "Enter Final Velocity (v): ";
				double v;
				cin >> v;

				cout << "Enter Displacement (d): ";
				double d;
				cin >> d;

				// calculate acceleration
				double a = (v * v - v0 * v0) / (2 * d);
				cout << "Acceleration (a) = " << a << "\n";
			}
			else
			{
				cout << "Invalid choice for sub-option.\n";
			}
		}
		else if (choice == 4)
		{
			// solve for time (t)
			// v = at + v0 ==> t = (v - v0) / a
			// we have a quadratic equation when solving for time using d = v0t + 0.5at^2
			// we can use the function we already have for quadratic equations
			cout << "You chose to solve for Time (t).\n";
			cout << "what are your available variables?.\n";
			cout << "1. initial velocity (v0), final velocity (v), and acceleration (a)\n";
			cout << "2. displacement (d), initial velocity (v0), and acceleration (a)\n";
			cout << "Enter your choice (1-2): ";
			int subChoice;
			cin >> subChoice;

			if (subChoice == 1)
			{
				cout << "Enter Initial Velocity (v0): ";
				double v0;
				cin >> v0;
				cout << "Enter Final Velocity (v): ";
				double v;
				cin >> v;
				cout << "Enter Acceleration (a): ";
				double a;
				cin >> a;

				// edge case for zero acceleration
				if (a == 0)
				{
					cout << "Acceleration cannot be zero.\n";
					return;
				}
				// calculate time
				double t = (v - v0) / a;
				cout << "Time (t) = " << t << "\n";
			}
			else if (subChoice == 2)
			{
				cout << "Enter Displacement (d): ";
				double d;
				cin >> d;

				cout << "Enter Initial Velocity (v0): ";
				double v0;
				cin >> v0;

				cout << "Enter Acceleration (a): ";
				double a;
				cin >> a;

				// set up quadratic equation: 0.5at^2 + v0t - d = 0
				double A = 0.5 * a;
				double B = v0;
				double C = -d;

				// calculate delta
				double delta = (B * B) - (4 * A * C);
				cout << "Delta is " << delta << "\n";

				// calculate roots
				if (delta < 0)
				{
					cout << "No real roots exist for time.\n";
				}
				else if (delta == 0)
				{
					double t = -B / (2 * A);
					cout << "One real root exists for time: t = " << t << "\n";
				}
				else
				{
					double t1 = (-B + sqrt(delta)) / (2 * A);
					double t2 = (-B - sqrt(delta)) / (2 * A);
					if (t1 >= 0)
						cout << "t1 = " << t1 << "\n";
					if (t2 >= 0)
						cout << "t2 = " << t2 << "\n";
				}
			}
			else
			{
				cout << "Invalid choice for sub-option.\n";
			}
		}
		else if (choice == 5)
		{
			// solve for displacement (d)
			cout << "You chose to solve for Displacement (d).\n";
			cout << "what are your available variables?.\n";
			cout << "1. initial velocity (v0), time (t), and acceleration (a)\n";
			cout << "2. initial velocity (v0), final velocity (v), and acceleration (a)\n";
			cout << "Enter your choice (1-2): ";
			int subChoice;
			cin >> subChoice;

			if (subChoice == 1)
			{
				cout << "Enter Initial Velocity (v0): ";
				double v0;
				cin >> v0;
				cout << "Enter Time (t): ";
				double t;
				cin >> t;
				cout << "Enter Acceleration (a): ";
				double a;
				cin >> a;

				// edge case for negative time
				if (t < 0)
				{
					cout << "Time cannot be negative.\n";
					return;
				}
				// calculate displacement
				double d = v0 * t + 0.5 * a * t * t;
				cout << "Displacement (d) = " << d << "\n";
			}
			else if (subChoice == 2)
			{
			}
			else
			{
				cout << "Invalid choice for sub-option.\n";
			}
		}
		else
		{
			cout << "Invalid choice for variable to solve for.\n";
		}
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
