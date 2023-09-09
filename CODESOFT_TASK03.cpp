#include<iostream>
#include<iomanip>
#include<conio.h>
#include<cstdlib>
#include<ctime>

using namespace std;

class TicTacToe {
private:
	char board[3][3];
	string Name[2];
	char symbol[2];
	char mark;
	int turn;
public:

	//PARAMETIZED CONSTRUCTOR

	TicTacToe(string names[2])
	{
		srand(time(0));
		for (int i = 0;i < 2;i++)
		{
			Name[i] = names[i];
		}
		symbol[0] = 'O';
		symbol[1] = 'X';
		mark = symbol[rand() % (1 - 0 + 1) + 0];
		turn = rand() % (1 - 0 + 1) + 0;
		for (int row = 0; row < 3; row++)
		{
			static char count = '1';
			for (int col = 0; col < 3; col++)
			{
				board[row][col] = count;
				count = count + 1;
			}

		}
	}

	//getters

	char getMark()const {
		return mark;
	}
	int getTurn()const {
		return turn;
	}
	string getName()const {
		return Name[turn];
	}

	//setter AND VOID FUNCTIONS

	void ToGetRow_Colomn(char choice, int& row, int& col)
	{
		if (choice == '1')
		{
			row = 0, col = 0;
		}
		else if (choice == '2')
		{
			row = 0, col = 1;
		}
		else if (choice == '3')
		{
			row = 0, col = 2;
		}
		else if (choice == '4')
		{
			row = 1, col = 0;
		}
		else if (choice == '5')
		{
			row = 1, col = 1;
		}
		else if (choice == '6')
		{
			row = 1, col = 2;
		}
		else if (choice == '7')
		{
			row = 2, col = 0;
		}
		else if (choice == '8')
		{
			row = 2, col = 1;
		}
		else if (choice == '9')
		{
			row = 2, col = 2;
		}
	}

	void MakeMove(int row, int col) {
		board[row][col] = mark;
		mark = (mark == 'X') ? 'O' : 'X';
		changeTurn();

	}

	void changeTurn()
	{
		turn = (turn == 1) ? 0 : 1;
	}

	//DISPLAY FUNTIONS IN WHICH PLAYER NAME OR SYMBOL IS MENTIONED

	void DisplayBoard() {
		system("cls");
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
		cout << setw(76) << setfill(' ') << "TIC TAC TOE GAME " << "\n";
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n\n\n";

		cout << setw(49) << setfill(' ') << "Mark: " << mark << " " << setw(39) << setfill(' ') << "Player: " << Name[turn] << "\n";
		cout << "\t\t\t\t\t\t\t" << "    |       |    " << "\n";
		cout << "\t\t\t\t\t\t\t" << board[0][0] << "   |   " << board[0][1] << "   |  " << board[0][2] << "\n";
		cout << "\t\t\t\t\t\t\t" << "____|_______|____" << "\n";
		cout << "\t\t\t\t\t\t\t" << "    |       |    " << "\n";
		cout << "\t\t\t\t\t\t\t" << board[1][0] << "   |   " << board[1][1] << "   |  " << board[1][2] << "\n";
		cout << "\t\t\t\t\t\t\t" << "____|_______|____" << "\n";
		cout << "\t\t\t\t\t\t\t" << "    |       |    " << "\n";
		cout << "\t\t\t\t\t\t\t" << board[2][0] << "   |   " << board[2][1] << "   |  " << board[2][2] << "\n";
		cout << "\t\t\t\t\t\t\t" << "    |       |    " << "\n\n";

	}

	//DISPLAY FUNTIONS IN WHICH PLAYER NAME OR SYMBOL IS NOT MENTIONED

	void DisplayBoard2() {
		system("cls");
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
		cout << setw(76) << setfill(' ') << "TIC TAC TOE GAME " << "\n";
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n\n\n";

		cout << "\t\t\t\t\t\t\t" << "    |       |    " << "\n";
		cout << "\t\t\t\t\t\t\t" << board[0][0] << "   |   " << board[0][1] << "   |  " << board[0][2] << "\n";
		cout << "\t\t\t\t\t\t\t" << "____|_______|____" << "\n";
		cout << "\t\t\t\t\t\t\t" << "    |       |    " << "\n";
		cout << "\t\t\t\t\t\t\t" << board[1][0] << "   |   " << board[1][1] << "   |  " << board[1][2] << "\n";
		cout << "\t\t\t\t\t\t\t" << "____|_______|____" << "\n";
		cout << "\t\t\t\t\t\t\t" << "    |       |    " << "\n";
		cout << "\t\t\t\t\t\t\t" << board[2][0] << "   |   " << board[2][1] << "   |  " << board[2][2] << "\n";
		cout << "\t\t\t\t\t\t\t" << "    |       |    " << "\n\n";

	}

	//VALIADATION FUNTIONS

	bool IsMoveValid(int row, int col) {
		if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] <= '9') {
			return true;
		}
		return false;
	}

	bool IsGameEnd() {
		return (CheckWin('X') || CheckWin('O') || IsBoardFull());
	}

	bool IsBoardFull() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] <= '9') {
					return false;
				}
			}
		}
		return true;
	}

	bool CheckWin(char MARK)
	{

		for (int i = 0; i < 3; i++)
		{
			//for row win
			if (board[i][0] == MARK && board[i][1] == MARK && board[i][2] == MARK)
			{
				return true;
			}
			//for colomn win
			if (board[0][i] == MARK && board[1][i] == MARK && board[2][i] == MARK) {
				return true;
			}
		}
		//for diagnal win
		if (board[0][0] == MARK && board[1][1] == MARK && board[2][2] == MARK)
		{
			return true;
		}
		if (board[0][2] == MARK && board[1][1] == MARK && board[2][0] == MARK) {
			return true;
		}
		return false;
	}

	//DESTRUCTOR

	~TicTacToe() {
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
		cout << setw(79) << setfill(' ') << " HASSNAIN@CODESOFT " << "\n";
		cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";

	}
};

int main()
{

	system("cls");
	string Names[2];
	cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
	cout << setw(76) << setfill(' ') << "TIC TAC TOE GAME " << "\n";
	cout << setw(39) << setfill(' ') << " " << setw(60) << setfill('=') << "\n";
	cout << "\n\t\t\tEnter PLayer 1 name : ";
	cin >> Names[0];
	cout << "\n\t\t\tEnter PLayer 2 name : ";
	cin >> Names[1];

	TicTacToe t(Names);
	int row, col;
	char choice;


	while (!t.IsGameEnd())
	{
		t.DisplayBoard();
		cout << "\t\t\t\t\tSELECT THE POSITION  ";
		choice = _getch();
		cout << "\n";
		t.ToGetRow_Colomn(choice, row, col);

		if (t.IsMoveValid(row, col))
		{
			t.MakeMove(row, col);
		}
		else
		{
			cout << "\n\t\t\t\t\t\t----Invalid move! Try again.----\n";
			system("pause");
		}


	}
	t.DisplayBoard2();
	if (t.CheckWin('X'))
	{
		if (t.getMark() != 'X')
		{
			t.changeTurn();
		}
		cout << "\t\t\t\t\t\t" << t.getName() << "  WIN\n";
	}
	else if (t.CheckWin('O'))
	{
		if (t.getMark() != 'O')
		{
			t.changeTurn();
		}
		cout << "\t\t\t\t\t\t" << t.getName() << "  WIN\n";

	}
	else
	{
		cout << "\t\t\t\t\t\t----------------GAME DRAW!----------------\n";
	}




	return 0;

}