#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
class Calculator {
private:
	float Num1, Num2;

public:
	//default constructor

	Calculator() {
		Num1 = 0;
		Num2 = 0;
	}

	//getter to get the values of number

	float getFirstNumber()const { return Num1; }
	float getSecondNumber()const { return Num2; }

	//setters to set the value of numbers

	void setNumbers() {
		cout << "\tEnter the first Number : ";
		cin >> Num1;
		cout << "\n";
		cout << "\tEnter the Second Number : ";
		cin >> Num2;
		cout << "\n";
	}

	//funtions for arithmetic operations

	void Addition()
	{
		cout << "\tTHE ADDITION of " << Num1 << " & " << Num2 << " = " << Num1 + Num2 << "\n";
	}
	void Subtraction()
	{
		cout << "\tTHE SUBTRACTION of " << Num1 << " & " << Num2 << " = " << Num1 - Num2 << "\n";

	}
	void Multiplication()
	{
		cout << "\tTHE MULTIPLICATION of " << Num1 << " & " << Num2 << " = " << Num1 * Num2 << "\n";

	}
	void Division()
	{
		if (Num2 != 0)
		{
			cout << "\tTHE DIVISION of " << Num1 << " & " << Num2 << " = " << Num1 / Num2 << "\n";
		}
		cout << "\t\t\t!!!!SYNTAX ERROR!!!!" << "\n";

	}

	// FUNCTION MENU 

	void Menu(char& choice) {
		system("cls");
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
		cout << setw(73) << setfill(' ') << "CALCULATOR " << "\n";
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
		cout << "\tCHOOSE THE OPERATION FROM THE GIVEN BELOW\n";
		cout << "\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division";
		choice = _getch();
		while (choice <= '0' || choice > '4')
		{
			cout << "\t\t\tinvalid choice!\n";
			cout << "\tCHOOSE THE OPERATION FROM THE GIVEN BELOW\n";
			cout << "\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division";
			choice = _getch();
		}
		cout << "\n";
	}

	//operator overloading using friend function

	friend istream& operator>>(istream& in, Calculator& object) {
		cout << "\tEnter the first Number :  ";
		in >> object.Num1;
		cout << "\n";
		cout << "\tEnter the Second Number :  ";
		in >> object.Num2;
		cout << "\n";
		return in;
	}

	//destructor 

	~Calculator()
	{
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
		cout << setw(79) << setfill(' ') << " HASSNAIN@CODESOFT " << "\n";
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
	}

};

int main()
{
	Calculator obj;
	char option;
	while (true)
	{

		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
		cout << setw(73) << setfill(' ') << "CALCULATOR " << "\n";
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
		cout << "\t\tIf you want to exit Then press the-->  SPACE BAR  <--key & press any key to continue";
		option = _getch();
		cout << "\n";
		if (option == ' ')
		{
			return 0;
		}
		else
		{
			char choice;

			cin >> obj;
			obj.Menu(choice);

			if (choice == '1') { obj.Addition(); }

			else if (choice == '2') { obj.Subtraction(); }

			else if (choice == '3') { obj.Multiplication(); }

			else { obj.Division(); }
		}

	}

}
