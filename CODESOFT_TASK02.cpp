#include<iostream>
#include<iomanip>  //USE FOR SETFILL()  & SETW()
#include<conio.h>   //USE FOR _GETCH()
#include<cstdlib> //USE FOR RAND() & SRAND()
#include<ctime>   // USE FOR TIME(0)

using namespace std;

//FUNCTION PROTOTYPE FOR VALIDATION OF RANGES

void is_valid(int& max, int& min, int limit);

int main()
{
	int lower_bound = 0, upper_bound = 10;
	srand(time(0));  //FOR RANDOMIZATION
	while (true)
	{
		system("cls");
		char option;
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
		cout << setw(76) << setfill(' ') << "NUMBER GUESSING GAME " << "\n";
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
		cout << "\tCHOOSE THE OPTION FROM THE GIVEN BELOW\n";
		cout << "\t1. EASY\n\t2. MEDIUM\n\t3. HARD\n\t4. EXIT";
		option = _getch();
		cout << "\n";
		while (option <= '0' || option > '4')
		{
			cout << "\t\t\tinvalid option!\n";
			cout << "\tCHOOSE THE OPTION FROM THE GIVEN BELOW\n";
			cout << "\t1. EASY\n\t2. MEDIUM\n\t3. HARD\n\t4. EXIT";
			option = _getch();
			cout << "\n";

		}

		if (option == '1')
		{
			system("cls");
			cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
			cout << setw(76) << setfill(' ') << "NUMBER GUESSING GAME " << "\n";
			cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
			short random_Num = rand() % (upper_bound - lower_bound + 1) + lower_bound;
			bool flag = false;
			short guess = 0;
			for (int i = 0;i < upper_bound && !flag;i++)
			{

				cout << "\n\tYOU HAVE REMAIN " << 10 - i << " ATTEMPTS LEFT\n";
				cout << "\tMake a guess beween (" << lower_bound << " to " << upper_bound << ") : ";
				cin >> guess;
				if (random_Num == guess)
				{
					cout << "\n\t\t------YOU GOT IT, JUST IN " << i + 1 << " ATTEMPTS" << "------ \n ";
					system("pause");
					flag = true;
				}
				else if (random_Num > guess)
				{
					cout << "\tTOO LOW TRY AGAIN!\n";
				}
				else
				{
					cout << "\tTOO HIGH TRY AGAIN!\n";
				}

			}
			if (!flag)
			{
				cout << "\n\t\t------YOU LOST THE GAME ------.. \n ";
				system("pause");
			}

		}

		else if (option == '2')
		{
			system("cls");
			cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
			cout << setw(76) << setfill(' ') << "NUMBER GUESSING GAME " << "\n";
			cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
			cout << "\tENTER THE MAXIMUM RANGE OF NUMBER : ";
			cin >> upper_bound;
			cout << "\tENTER THE MINIMUM RANGE OF NUMBER : ";
			cin >> lower_bound;
			is_valid(upper_bound, lower_bound, 5);
			int attempts = (upper_bound - lower_bound) / 2;
			short random_Num = rand() % (upper_bound - lower_bound + 1) + lower_bound;
			bool flag = false;
			short guess = 0;
			for (int i = 0;i < attempts && !flag;i++)
			{

				cout << "\n\tYOU HAVE REMAIN " << attempts - i << " ATTEMPTS LEFT\n";
				cout << "\tMake a guess beween (" << lower_bound << " to " << upper_bound << ") : ";
				cin >> guess;
				if (random_Num == guess)
				{
					cout << "\n\t\t------YOU GOT IT, JUST IN " << i + 1 << " ATTEMPTS" << "------ \n ";
					system("pause");
					flag = true;
				}
				else if (random_Num > guess)
				{
					cout << "\tTOO LOW TRY AGAIN!\n";
				}
				else
				{
					cout << "\tTOO HIGH TRY AGAIN!\n";
				}

			}
			if (!flag)
			{
				cout << "\n\t\t------YOU LOST THE GAME ------.. \n ";
				system("pause");
			}
		}

		else if (option == '3')
		{

			system("cls");
			cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
			cout << setw(76) << setfill(' ') << "NUMBER GUESSING GAME " << "\n";
			cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
			cout << "\tENTER THE MAXIMUM RANGE OF NUMBER : ";
			cin >> upper_bound;
			cout << "\tENTER THE MINIMUM RANGE OF NUMBER : ";
			cin >> lower_bound;
			is_valid(upper_bound, lower_bound, 10);
			int attempts = (upper_bound - lower_bound) / 4;
			short random_Num = rand() % (upper_bound - lower_bound + 1) + lower_bound;
			bool flag = false;
			short guess = 0;
			for (int i = 0;i < attempts && !flag;i++)
			{

				cout << "\n\tYOU HAVE REMAIN " << attempts - i << " ATTEMPTS LEFT\n";
				cout << "\tMake a guess beween (" << lower_bound << " to " << upper_bound << ") : ";
				cin >> guess;
				if (random_Num == guess)
				{
					cout << "\n\t\t------YOU GOT IT, JUST IN " << i + 1 << " ATTEMPTS" << "------ \n ";
					system("pause");
					flag = true;
				}
				else if (random_Num > guess)
				{
					cout << "\tTOO LOW TRY AGAIN!\n";
				}
				else
				{
					cout << "\tTOO HIGH TRY AGAIN!\n";
				}

			}
			if (!flag)
			{
				cout << "\n\t\t------YOU LOST THE GAME ------.. \n ";
				system("pause");
			}
		}

		else
		{
			cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
			cout << setw(79) << setfill(' ') << " HASSNAIN@CODESOFT " << "\n";
			cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
			return 0;
		}

	}

}

//FUNCTION DEFINITION FOR VALIDATION OF RANGES

void is_valid(int& max, int& min, int limit)
{
	bool flag = true;
	while (flag) {
		if ((max < 0) || (min < 0)) {
			cout << "\tYOU CANNOT ENTER NEGATIVE RANGES\n ";
			cout << "\tENTER THE MAXIMUM RANGE OF NUMBER : ";
			cin >> max;
			cout << "\tENTER THE MAXIMUM RANGE OF NUMBER : ";
			cin >> min;
		}
		else if (max < min) {
			cout << "\tYOUR ENTER MAXIMUM RANGE CAN'T BE SMALLER THAN MINIMUM RANGE\n ";
			cout << "\tENTER THE MAXIMUM RANGE OF NUMBER : ";
			cin >> max;
		}
		else if (max == min) {
			cout << "\tYOU CAN'T ENTERED SAME RANGES FOR MAXIMUN AND MINIMUM\n";
			cout << "\tENTER THE MAXIMUM RANGE OF NUMBER : ";
			cin >> max;
			cout << "\tENTER THE MINIMUM RANGE OF NUMBER : ";
			cin >> min;
		}
		else if ((max - min) < limit) {
			cout << "\tTHE DIFFERNCE BETWEEN THE MAXIMUN AND MINIMUM RANGES SHOULD BE AT LEAST " << limit << "\n";
			cout << "\tENTER THE MAXIMUM RANGE OF NUMBER : ";
			cin >> max;
			cout << "\tENTER THE MINIMUM RANGE OF NUMBER : ";
			cin >> min;
		}
		else
		{
			flag = false;
		}

	}
}
