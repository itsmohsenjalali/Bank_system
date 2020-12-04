#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<Windows.h> 
using namespace std;

//*****************************function****************************
int menu();
void open_account(char[30][30]);
void box(char[30][30]);
void output(char[30][30]);
void refresh(char[30][30]);
void gotoxy(int, int);
void finalForm(char[30][30], int);
void close_account(char[30][30]);
void transfer_money(char[30][30]);
void recieve_money(char[30][30]);
void balance_enquiry(char[30][30]);
void Buy_Mobile_Charge(char[30][30]);
void recieve_bill(char[30][30]);
void transaction_list(char box1[30][30]);
void request_loan(char box1[30][30]);
void date(int, int);
void crt(char[30][30]);
void lottery(char[30][30]);
void cas9(char[30][30]);

//******************************variable***************************
int nCAR1 = 0;
int nCAR2 = 0;
long long int nationalCodeC[100];
long long int nationalCodeS[100];
string name_familyC[100];
string name_familyS[100];
long long int accountNumC[100];
long long int accountNumS[100];
long long int moneyC[100];
long long int moneyS[100];
string passwordC[100];
string passwordS[100];
long long int billC[100][100];
long long int billS[100][100];
static int countBillC[100];
static int countBillS[100];
string signC[100][100];
string signS[100][100];
int dateC[100][100][3];
int dateS[100][100][3];

//*******************************main********************************
int main()
{
	char box1[30][30];
	while (true)
	{
		system("cls");
		switch (menu())
		{
		case 1:
			system("cls");
			open_account(box1);
			break;
		case 2:
			system("cls");
			close_account(box1);
			break;
		case 3:
			system("cls");
			transfer_money(box1);
			break;
		case 4:
			system("cls");
			recieve_money(box1);
			break;
		case 5:
			system("cls");
			recieve_bill(box1);
			break;
		case 6:
			system("cls");
			balance_enquiry(box1);
			break;
		case 7:
			system("cls");
			transaction_list(box1);
			break;
		case 8:
			system("cls");
			Buy_Mobile_Charge(box1);
			break;
		case 9:
			system("cls");
			cas9(box1);
			break;
		case 10:
			system("cls");
			crt(box1);
			break;
		case 11:
			exit(0);
			break;

		default:
			gotoxy(10, 31);
			cout << "invalid number";
			_getch();
			break;
		}
	}
	system("pause");
}
//******************************Gotoxy*******************************
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}
//*******************************menu********************************
int menu()// first and main menu.
{
	int s;
	const int row = 30;
	const int column = 30;
	char a[row][column];
	string s1("Bank System");
	string s2("1.Open Account");
	string s3("2.Close Account");
	string s4("3.Money Transfer");
	string s5("4.Receive Money");
	string s6("5.Riceive Bill");
	string s7("6.Balance Enquiry");
	string s8("7.Transaction List");
	string s9("8.Buy Mobile Charge");
	string s10("9.lottery & loan");
	string s11("10.Creator");
	string s12("11.exit");
	string s13("Choose Your Action:");

	cout << "\n\n\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (i == 0 || i == 29)
				a[i][j] = '*';
			else
				a[i][j] = ' ';
			if (j == 0 || j == 29)
				a[i][j] = '*';
			if (i == 4 && j != 29 && j != 0)
				a[i][j] = '-';
		}
		for (int k = 0; k < 11; k++)
			a[2][k + 10] = s1[k];
		for (int k = 0; k < 14; k++)
			a[6][k + 1] = s2[k];
		for (int k = 0; k < 15; k++)
			a[8][k + 1] = s3[k];
		for (int k = 0; k < 16; k++)
			a[10][k + 1] = s4[k];
		for (int k = 0; k < 15; k++)
			a[12][k + 1] = s5[k];
		for (int k = 0; k < 14; k++)
			a[14][k + 1] = s6[k];
		for (int k = 0; k < 17; k++)
			a[16][k + 1] = s7[k];
		for (int k = 0; k < 18; k++)
			a[18][k + 1] = s8[k];
		for (int k = 0; k < 19; k++)
			a[20][k + 1] = s9[k];
		for (int k = 0; k < 16; k++)
			a[22][k + 1] = s10[k];
		for (int k = 0; k < 10; k++)
			a[24][k + 1] = s11[k];
		for (int k = 0; k < 7; k++)
			a[26][k + 1] = s12[k];
		for (int k = 0; k < 19; k++)
			a[27][k + 1] = s13[k];
	}
	for (int v = 0; v < row; v++)
	{
		cout << "\t";
		for (int b = 0; b < column; b++)
			cout << a[v][b] << " ";
		cout << "\n";
	}
	gotoxy(48, 30);
	cin >> s;
	return(s);

}
//*****************************open account**************************
void open_account(char box1[30][30])
{
	bool checkS1 = true, checkS2 = true;
	bool checkC1 = true, checkC2 = true;
	int e;
	refresh(box1);
	string s1("Open Account");
	string s2("1.Current Account");
	string s3("2.Savings Account");
	string s4("3.Back To Menu");
	string s5("Choose:");
	string s6("Enter National Code:");
	string s7("Current Account");
	string s8("Savings Account");
	string s9("Enter Your Full Name:");
	string s10("Enter Your Password:");
	for (int k = 0; k < 12; k++)
		box1[2][k + 9] = s1[k];
	for (int k = 0; k < 17; k++)
		box1[6][k + 1] = s2[k];
	for (int k = 0; k < 17; k++)
		box1[10][k + 1] = s3[k];
	for (int k = 0; k < 14; k++)
		box1[14][k + 1] = s4[k];
	for (int k = 0; k < 8; k++)
		box1[18][k + 1] = s5[k];
	box(box1);
	gotoxy(27, 20);
	cin >> e;
	switch (e)
	{
	case 1:// this case is for opening current account.
		system("cls");
		refresh(box1);
		for (int k = 0; k < 15; k++)
			box1[2][k + 8] = s7[k];
		box(box1);
		gotoxy(13, 10);
		cout << s6;
		gotoxy(13, 12);
		cin >> nationalCodeC[nCAR1];
		for (int i = 0; i < 100; i++) // This For search if a person with this national code had a current account
									  //before and does not allow that person to have another current account.
		{
			if (nationalCodeC[nCAR1] == nationalCodeC[i] && i != nCAR1)
			{
				gotoxy(13, 14);
				cout << "You Had Account before.";
				_getch();
				checkC1 = false;
				break;
			}
		}
		for (int i = 0; i < 100; i++) // This For check to find the name and family name of the user who enter
									  //his national code if had a saving account before.
		{
			if (nationalCodeC[nCAR1] == nationalCodeS[i])
			{
				checkC2 = false;
				name_familyC[nCAR1] = name_familyS[i];
			}
		}
		if (checkC1 == true && checkC2 == true)// If the user does not have a current or saving account commands 
											   //of this if run.
		{
			gotoxy(13, 14);
			cout << s9;
			gotoxy(13, 16);
			cin.get();
			getline(cin, name_familyC[nCAR1]);

		}
		if (checkC1 == true)  // If user with this national code does not have a current
							  //acount before check is true and methoud comands run. 
		{
			accountNumC[nCAR1] = nationalCodeC[nCAR1] * 1000 + 67;//0106323703003
			if (checkC2 == true)
				gotoxy(13, 18);
			else
				gotoxy(13, 16);
			cout << "First Money Amount?";
			if (checkC2 == true && checkC1 == true)
				gotoxy(13, 20);
			else
				gotoxy(13, 18);
			cin >> moneyC[nCAR1];
			billC[nCAR1][countBillC[nCAR1]] = moneyC[nCAR1];
			signC[nCAR1][countBillC[nCAR1]] = '+';
			gotoxy(13, 22);
			cout << s10;
			gotoxy(13, 24);
			cin.get();
			getline(cin, passwordC[nCAR1]);
			system("cls");
			box(box1);
			date(1, nCAR1);
			finalForm(box1, e);
			countBillC[nCAR1]++;
			nCAR1++;
		}
		break;
	case 2:// this case is for opening saving account.
		system("cls");
		refresh(box1);
		for (int k = 0; k < 15; k++)
			box1[2][k + 8] = s8[k];
		box(box1);
		gotoxy(13, 10);
		cout << s6;
		gotoxy(13, 12);
		cin >> nationalCodeS[nCAR2];
		for (int i = 0; i < 100; i++) //This For search if a person with this national code had a saving account
									  //before and does not allow that person to have another current account.
		{
			if (nationalCodeS[nCAR2] == nationalCodeS[i] && i != nCAR2)
			{
				gotoxy(13, 14);
				cout << "You Had Account before.";
				checkS1 = false;
				break;
			}
		}
		for (int i = 0; i < 100; i++) // This For check to find the name and family name of the user who enter
									  //his national code if had a current account before.
		{
			if (nationalCodeS[nCAR2] == nationalCodeC[i])
			{
				checkS2 = false;
				name_familyS[nCAR2] = name_familyC[i];
			}
		}
		if (checkS1 == true && checkS2 == true)
		{
			gotoxy(13, 14);
			cout << s9;
			gotoxy(13, 16);
			cin.get();
			getline(cin, name_familyS[nCAR2]);
		}
		if (checkS1 == true)  // If user with this national code does not have a saving
							  //acount before check is true and methoud comands run. 
		{
			accountNumS[nCAR2] = nationalCodeS[nCAR2] * 1000 + 115;
			if (checkS2 == true && checkS1 == true)
				gotoxy(13, 18);
			else
				gotoxy(13, 16);
			cout << "First Money Amount?";
			if (checkS2 == true && checkS1 == true)
				gotoxy(13, 20);
			else
				gotoxy(13, 18);
			cin >> moneyS[nCAR2];
			billS[nCAR2][countBillS[nCAR2]] = moneyS[nCAR2];
			signS[nCAR2][countBillS[nCAR2]] = '+';
			gotoxy(13, 22);
			cout << s10;
			gotoxy(13, 24);
			cin.get();
			getline(cin, passwordS[nCAR2]);
			system("cls");
			box(box1);
			date(2, nCAR2);
			finalForm(box1, e);
			countBillS[nCAR2]++;
			nCAR2++;
		}
		break;
	}
}
//*****************************box1**********************************
void box(char box1[30][30])// This method make the box of open account.
{
	cout << "\n\n";
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (i == 0 || i == 29)
				box1[i][j] = '#';
			if (j == 0 || j == 29)
				box1[i][j] = '#';
			if (i == 4 && j != 29 && j != 0)
				box1[i][j] = '-';
		}
	}
	output(box1);
}
//****************************output*********************************
void output(char box1[30][30])// This method Print the box of open account.
{
	for (int v = 0; v < 30; v++)
	{
		cout << "\t" << "  ";
		for (int b = 0; b < 30; b++)
			cout << box1[v][b] << " ";
		cout << "\n";
	}
}
//***************************refresh*********************************
void refresh(char a[30][30])//This method is for making Box Array empty.
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			a[i][j] = ' ';
		}
	}
}
//***************************finalform*******************************
void finalForm(char box1[30][30], int select)// this method is for printing data that we got
											 //from user to open an account.
{
	system("cls");
	refresh(box1);
	string s1("Final Form");
	switch (select)
	{
	case 1:

		for (int k = 0; k < 11; k++)
			box1[2][k + 10] = s1[k];
		box(box1);
		gotoxy(13, 10);
		cout << name_familyC[nCAR1];
		gotoxy(13, 13);
		cout << "Your Account Number Is :" << accountNumC[nCAR1];
		gotoxy(13, 16);
		cout << "Your Saving Money Is :" << moneyC[nCAR1];
		gotoxy(13, 19);
		cout << "Your Password Is :" << passwordC[nCAR1];
		gotoxy(13, 20);
		_getch();
		break;
	case 2:
		for (int k = 0; k < 11; k++)
			box1[2][k + 10] = s1[k];
		box(box1);
		gotoxy(13, 10);
		cout << name_familyS[nCAR2];
		gotoxy(13, 13);
		cout << "Your Account Number Is :" << accountNumS[nCAR2];
		gotoxy(13, 16);
		cout << "Your Saving Money Is :" << moneyS[nCAR2];
		gotoxy(13, 19);
		cout << "Your Password Is :" << passwordS[nCAR2];
		gotoxy(13, 20);
		_getch();
		break;
	}
}
//*************************checkAccount******************************
void date(int s, int count)
{
	switch (s)
	{
	case 1:
		gotoxy(13, 15);
		cout << "Enter the date: ";
		gotoxy(13, 17);
		cout << "Year : ";
		gotoxy(13, 18);
	YearC:cin >> dateC[count][countBillC[count]][0];
		if (dateC[count][countBillC[count]][0] < dateC[count][countBillC[count] - 1][0])
		{
			gotoxy(13, 19);
			cout << "Wrong Year";
			_getch();
			gotoxy(13, 18);
			cout << "           ";
			gotoxy(13, 19);
			cout << "                ";
			goto YearC;
		}
		gotoxy(13, 20);
		cout << "Month: ";
		gotoxy(13, 21);
	MonthC:cin >> dateC[count][countBillC[count]][1];
		if ((dateC[count][countBillC[count]][0] == dateC[count][countBillC[count] - 1][0]) && (dateC[count][countBillC[count]][1] < dateC[count][countBillC[count] - 1][1]))
		{
			gotoxy(13, 22);
			cout << "Wrong Month";
			_getch();
			gotoxy(13, 21);
			cout << "        ";
			gotoxy(13, 22);
			cout << "              ";
			goto MonthC;
		}
		gotoxy(13, 23);
		cout << "Day: ";
		gotoxy(13, 24);
	DayC:cin >> dateC[count][countBillC[count]][2];
		if ((dateC[count][countBillC[count]][0] == dateC[count][countBillC[count] - 1][0]) && (dateC[count][countBillC[count]][1] == dateC[count][countBillC[count] - 1][1]) && (dateC[count][countBillC[count]][2] < dateC[count][countBillC[count] - 1][2]))
		{
			gotoxy(13, 25);
			cout << "Wrong Day";
			_getch();
			gotoxy(13, 24);
			cout << "        ";
			gotoxy(13, 25);
			cout << "            ";
			goto DayC;
		}
		break;
	case 2:
		gotoxy(13, 15);
		cout << "Enter the date: ";
		gotoxy(13, 17);
		cout << "Year : ";
		gotoxy(13, 18);
	YearS:cin >> dateS[count][countBillS[count]][0];
		if (dateS[count][countBillS[count]][0] < dateS[count][countBillS[count] - 1][0])
		{
			gotoxy(13, 19);
			cout << "Wrong Year";
			_getch();
			gotoxy(13, 18);
			cout << "           ";
			gotoxy(13, 19);
			cout << "                ";
			goto YearS;
		}
		gotoxy(13, 20);
		cout << "Month: ";
		gotoxy(13, 21);
	MonthS:cin >> dateS[count][countBillS[count]][1];
		if ((dateS[count][countBillS[count]][0] == dateS[count][countBillS[count] - 1][0]) && (dateS[count][countBillS[count]][1] < dateS[count][countBillS[count] - 1][1]))
		{
			gotoxy(13, 22);
			cout << "Wrong Month";
			_getch();
			gotoxy(13, 21);
			cout << "        ";
			gotoxy(13, 22);
			cout << "              ";
			goto MonthS;
		}
		gotoxy(13, 23);
		cout << "Day: ";
		gotoxy(13, 24);
	DayS:cin >> dateS[count][countBillS[count]][2];
		if ((dateS[count][countBillS[count]][0] == dateS[count][countBillS[count] - 1][0]) && (dateS[count][countBillS[count]][1] == dateS[count][countBillS[count] - 1][1]) && (dateS[count][countBillS[count]][2] < dateS[count][countBillS[count] - 1][2]))
		{
			gotoxy(13, 25);
			cout << "Wrong Day";
			_getch();
			gotoxy(13, 24);
			cout << "        ";
			gotoxy(13, 25);
			cout << "            ";
			goto DayS;
		}
		break;
	}
}
//**************************closeaccount*****************************
void close_account(char box1[30][30]) // This method is for closing accounts.
{
	string s1("Close Account");
	int chNum, chNum1, count1 = 0, count2 = 0;
	char chChar;
	long long int nationalCodeCL;
	long long int accountNumCL;
	string name_familyCL;
	string password;
	bool check1 = false, check2 = false;
	system("cls");
	refresh(box1);
	for (int k = 0; k < 13; k++)
		box1[2][k + 9] = s1[k];
	box(box1);
	gotoxy(13, 8);
label0:cout << "how do you want to close your account?";// There are three ways for closing account 
														//that user can choose one of them.
	gotoxy(13, 11);
	cout << "1. With name.";
	gotoxy(13, 13);
	cout << "2. With national code.";
	gotoxy(13, 15);
	cout << "3. With account number.";
	gotoxy(13, 17);
	cout << "4. Back to menu.";
	gotoxy(13, 18);
	cout << "Chose The number :";
	gotoxy(13, 19);
	cin >> chNum1;
	switch (chNum1)
	{
	case 1: // This case use full name to close account.
		gotoxy(13, 20);
		cout << "Enter your full name:";
		gotoxy(13, 21);
		cin.get();
		getline(cin, name_familyCL);
		for (int i = 0; i < 100; i++) // This For search to find full name in arrays room of current 
									  //and saving account.
		{
			if (name_familyCL == name_familyC[i])
			{
				count1 = i;
				check1 = true;
			}
			if (name_familyCL == name_familyS[i])
			{
				count2 = i;
				check2 = true;
			}
		}
		if (check1 == true && check2 == true) // If user have two account this If ask user which acount 
											  //do you want to close.
		{
			gotoxy(13, 22);
		label:cout << "Which one do you want to close?";
			gotoxy(13, 23);
			cout << "1. current Account";
			gotoxy(13, 24);
			cout << "2. saving Account";
			gotoxy(13, 25);
			cin >> chNum;
			switch (chNum) // This Switch clean the rooms of arrays account.
			{
			case 1:
				gotoxy(13, 26);
				cout << "Enter your password: ";
				gotoxy(13, 27);
				cin >> password;
				if (password == passwordC[count1])
				{
					nationalCodeC[count1] = 0;
					name_familyC[count1] = ' ';
					accountNumC[count1] = 0;
					moneyC[count1] = 0;
					gotoxy(13, 28);
					cout << "your current account closed.";
					_getch();
					break;
				}
				else
				{
					gotoxy(13, 28);
					cout << "Your Password Is Wrong Try Again.";
					gotoxy(13, 27);
					cout << "                    ";
					_getch();
					goto label;
				}
				break;

			case 2:
				gotoxy(13, 26);
				cout << "Enter your password: ";
				gotoxy(13, 27);
				cin >> password;
				if (password == passwordS[count2])
				{
					nationalCodeS[count2] = 0;
					name_familyS[count2] = ' ';
					accountNumS[count2] = 0;
					moneyS[count2] = 0;
					gotoxy(13, 28);
					cout << "Your saving account closed.";
					_getch();
					break;
				}
				else
				{
					gotoxy(13, 28);
					cout << "Your Password Is Wrong Try Again.";
					gotoxy(13, 27);
					cout << "                   ";
					_getch();
					goto label;
				}
				break;
			default:
				gotoxy(13, 26);
				cout << "You enter invalid number try again.";
				_getch();
				gotoxy(13, 27);
				cout << "                   ";
				goto label;
				break;
			}
		}
		else if (check1 == true && check2 == false)  // This Else if clean the arrays rooms of current account
													 //if user just has a current account.
		{
			gotoxy(13, 22);
		label1:cout << "Do you want close your current account?(y/n)";
			gotoxy(13, 23);
			cin >> chChar;
			if (chChar == 'y' || chChar == 'Y')
			{
				gotoxy(13, 24);
				cout << "Enter your password: ";
				gotoxy(13, 25);
				cin >> password;
				if (password == passwordC[count1])
				{
					nationalCodeC[count1] = 0;
					name_familyC[count1] = ' ';
					accountNumC[count1] = 0;
					moneyC[count1] = 0;
					gotoxy(13, 26);
					cout << "Your current account closed.";
					gotoxy(13, 27);
					_getch();
					break;
				}
				else
				{
					gotoxy(13, 26);
					cout << "Your Password Is Wrong .";
					gotoxy(13, 25);
					cout << "                     ";
					_getch();
					goto label1;
				}
			}
			else if (chChar == 'n' || chChar == 'N')
				break;
			else
			{
				gotoxy(13, 24);
				cout << "You enter invalid charactor Try again.";
				_getch();
				gotoxy(13, 25);
				cout << "                     ";
				goto label1;
			}
		}
		else if (check1 == false && check2 == true) // This Else if clean the arrays rooms of saving account
													//if user just has a saving account.
		{
			gotoxy(13, 22);
		label2:cout << "Do you want close saving account?(y/n)";
			gotoxy(13, 23);
			cin >> chChar;
			if (chChar == 'y' || chChar == 'Y')
			{
				gotoxy(13, 24);
				cout << "Enter your password: ";
				gotoxy(13, 25);
				cin >> password;
				if (password == passwordS[count2])
				{
					nationalCodeS[count2] = 0;
					name_familyS[count2] = ' ';
					accountNumS[count2] = 0;
					moneyS[count2] = 0;
					gotoxy(13, 26);
					cout << "Your saving account closed.";
					gotoxy(13, 27);
					_getch();
					break;
				}
				else
				{
					gotoxy(13, 26);
					cout << "Your Password Is Wrong .";
					gotoxy(13, 25);
					cout << "                      ";
					_getch();
					goto label2;
				}
			}
			else if (chChar == 'n' || chChar == 'N')
				break;
			else
			{
				gotoxy(13, 24);
				cout << "You enter invalid charactor Try again.";
				gotoxy(13, 25);
				_getch();
				goto label2;
			}
		}
		else
		{
			gotoxy(13, 22);
			cout << "You do not have account with this name.";
			gotoxy(13, 23);
			_getch();
		}
		break;
	case 2: // This case use national code to close account.
		gotoxy(13, 20);
		cout << "Enter your national code.";
		gotoxy(13, 21);
		cin >> nationalCodeCL;
		for (int i = 0; i < 100; i++) // This For search to find national code in arrays room of current 
									  //and saving account.
		{
			if (nationalCodeCL == nationalCodeC[i])
			{
				count1 = i;
				check1 = true;
			}
			if (nationalCodeCL == nationalCodeS[i])
			{
				count2 = i;
				check2 = true;
			}
		}
		if (check1 == true && check2 == true) // If user have two account this If ask user which acount 
											  //do you want to close.
		{
			gotoxy(13, 22);
		label3:cout << "Which one do you want to close?";
			gotoxy(13, 23);
			cout << "1. current Account";
			gotoxy(13, 24);
			cout << "2. saving Account";
			gotoxy(13, 25);
			cin >> chNum;
			switch (chNum)
			{
			case 1:
				gotoxy(13, 26);
				cout << "Enter your password: ";
				gotoxy(13, 27);
				cin >> password;
				if (password == passwordC[count1])
				{
					nationalCodeC[count1] = 0;
					name_familyC[count1] = ' ';
					accountNumC[count1] = 0;
					moneyC[count1] = 0;
					gotoxy(13, 28);
					cout << "Your current account closed.";
					_getch();
					break;
				}
				else
				{
					gotoxy(13, 28);
					cout << "Your Password Is Wrong.";
					gotoxy(13, 27);
					cout << "                     ";
					_getch();
					goto label3;
				}
				break;
			case 2:
				gotoxy(13, 26);
				cout << "Enter your password: ";
				gotoxy(13, 27);
				cin >> password;
				if (password == passwordS[count2])
				{
					nationalCodeS[count2] = 0;
					name_familyS[count2] = ' ';
					accountNumS[count2] = 0;
					moneyS[count2] = 0;
					gotoxy(13, 28);
					cout << "Your saving account closed.";
					_getch();
					break;
				}
				else
				{
					gotoxy(13, 28);
					cout << "Your Password Is Wrong.";
					gotoxy(13, 27);
					cout << "                     ";
					_getch();
					goto label3;
				}
				break;
			default:
				gotoxy(13, 26);
				cout << "You enter invalid number try again.";
				_getch();
				goto label3;
			}
		}
		else if (check1 == true && check2 == false) // This Else if clean the arrays rooms of current account
													//if user just has a current account.
		{
			gotoxy(13, 22);
		label4:cout << "Do you want close your current account?(y/n)";
			gotoxy(13, 23);
			cin >> chChar;
			if (chChar == 'y' || chChar == 'Y')
			{
				gotoxy(13, 24);
				cout << "Enter your password: ";
				gotoxy(13, 25);
				cin >> password;
				if (password == passwordC[count1])
				{
					nationalCodeC[count1] = 0;
					name_familyC[count1] = ' ';
					accountNumC[count1] = 0;
					moneyC[count1] = 0;
					gotoxy(13, 26);
					cout << "Your current account closed.";
					gotoxy(13, 27);
					_getch();
					break;
				}
				else
				{
					gotoxy(13, 26);
					cout << "Your Password Is Wrong.";
					gotoxy(13, 25);
					cout << "                     ";
					_getch();
					goto label4;
				}
			}
			else if (chChar == 'n' || chChar == 'N')
				break;
			else
			{
				gotoxy(13, 24);
				cout << "You enter invalid charactor Try again.";
				gotoxy(13, 25);
				_getch();
				goto label4;

			}
		}
		else if (check1 == false && check2 == true) // This Else if clean the arrays rooms of saving account
													//if user just has a saving account.
		{
			gotoxy(13, 22);
		label5:cout << "Do you want close saving account?(y/n)";
			gotoxy(13, 23);
			cin >> chChar;
			if (chChar == 'y' || chChar == 'Y')
			{
				gotoxy(13, 24);
				cout << "Enter your password: ";
				gotoxy(13, 25);
				cin >> password;
				if (password == passwordS[count2])
				{
					nationalCodeS[count2] = 0;
					name_familyS[count2] = ' ';
					accountNumS[count2] = 0;
					moneyS[count2] = 0;
					gotoxy(13, 26);
					cout << "Your saving account closed.";
					gotoxy(13, 27);
					_getch();
					break;
				}
				else
				{
					gotoxy(13, 26);
					cout << "Your Password Is Wrong.";
					gotoxy(13, 25);
					cout << "                       ";
					_getch();
					goto label5;
				}
			}
			else if (chChar == 'n' || chChar == 'N')
				break;
			else
			{
				gotoxy(13, 24);
				cout << "You enter invalid charactor Try again.";
				gotoxy(13, 25);
				_getch();
				goto label5;
			}
		}
		else
		{
			gotoxy(13, 22);
			cout << "You do not have account with this name.";
			gotoxy(13, 23);
			_getch();
		}
		break;
	case 3: // This case use account number to close account.
		int i;
		gotoxy(13, 20);
		cout << "Enter your account number.";
		gotoxy(13, 21);
		cin >> accountNumCL;
		for (i = 0; i < 100; i++)
		{
			if (accountNumCL == accountNumC[i]) // This If is for when account number is for a cuurent account.
			{
				gotoxy(13, 22);
				cout << "Do you want close your current account?(y/n)";
			label6:gotoxy(13, 23);
				cin >> chChar;
				if (chChar == 'y' || chChar == 'Y')
				{
					gotoxy(13, 24);
					cout << "Enter your password: ";
				labelpassC:gotoxy(13, 25);
					cin >> password;
					if (password == passwordC[i])
					{
						nationalCodeC[i] = 0;
						name_familyC[i] = ' ';
						accountNumC[i] = 0;
						moneyC[i] = 0;
						gotoxy(13, 26);
						cout << "Your current account closed.";
						gotoxy(13, 27);
						_getch();
						break;
					}
					else
					{
						gotoxy(13, 26);
						cout << "Password Is Wrong.";
						gotoxy(13, 25);
						cout << "                       ";
						_getch();
						goto labelpassC;
					}
				}
				else if (chChar == 'n' || chChar == 'N')
					break;
				else
				{
					gotoxy(13, 24);
					cout << "Invalid";
					_getch();
					gotoxy(13, 23);
					cout << "        ";
					goto label6;
				}
			}
			else if (accountNumCL == accountNumS[i]) // This Else if is for when account number is for a saving account.
			{
				gotoxy(13, 22);
				cout << "Do you want close saving account?(y/n)";
			label7:gotoxy(13, 23);
				cin >> chChar;
				if (chChar == 'y' || chChar == 'Y')
				{
					gotoxy(13, 24);
					cout << "Enter your password: ";
				labelpassS:gotoxy(13, 25);
					cin >> password;
					if (password == passwordS[i])
					{
						nationalCodeS[i] = 0;
						name_familyS[i] = ' ';
						accountNumS[i] = 0;
						moneyS[i] = 0;
						gotoxy(13, 26);
						cout << "Your saving account closed.";
						gotoxy(13, 27);
						_getch();
						break;
					}
					else
					{
						gotoxy(13, 26);
						cout << "Password Is Wrong.";
						gotoxy(13, 25);
						cout << "                       ";
						_getch();
						goto labelpassS;
					}
				}
				else if (chChar == 'n' || chChar == 'N')
					break;
				else
				{
					gotoxy(13, 24);
					cout << "Invalid";
					gotoxy(13, 25);
					_getch();
					gotoxy(13, 23);
					cout << "     ";
					goto label7;
				}
			}
		}
		if (nationalCodeS[i] != 0 || nationalCodeC[i] != 0)
		{
			gotoxy(13, 22);
			cout << "You do not have account with this name.";
			gotoxy(13, 23);
			_getch();
		}
		break;
	case 4:
		int main();
		break;
	default:
		gotoxy(13, 20);
		cout << "You enter a wrong number try again.";
		_getch();
		gotoxy(13, 19);
		cout << "      ";
		goto label0;
	}
}
//*************************transfermoney*****************************
void transfer_money(char box1[30][30])
{
	string s1("Money Transfer");
	int chNum, count1 = 0, count2 = 0, count3 = 0, s;
	long long int moneyTM;
	long long int accountNumTM;
	string name_familyTM;
	string password;
	bool check1 = false, check2 = false, check3 = false, check4 = false, check5 = false;
label:system("cls");
	refresh(box1);
	for (int k = 0; k < 14; k++)
		box1[2][k + 9] = s1[k];
	box(box1);
label1:gotoxy(13, 7);
	cout << "Select The Number:";
	gotoxy(13, 8);
	cout << "1.Money Transfer.";
	gotoxy(13, 9);
	cout << "2.Back To Menu.";
	gotoxy(13, 10);
	cin >> s;
	switch (s)
	{
	case 1:
		gotoxy(13, 11);
		cout << "Enter your account number: ";
		gotoxy(13, 12);
		cin >> accountNumTM;
		for (int i = 0; i < 100; i++) // This For check to find account number that want transfer money.
		{
			if (accountNumTM == accountNumC[i]) // This If find account number between current accounts.
			{
				count1 = i;
				check1 = true;
				break;

			}
			else if (accountNumTM == accountNumS[i]) // This If find account number between saving accounts.
			{
				count1 = i;
				check2 = true;
				break;
			}
		}
		if (check1 == false && check2 == false) // This If is for when the account number that user enter 
												// is wrong or does not exist.
		{
			gotoxy(13, 13);
			cout << "Your account number does not exist in system.";
			_getch();
			goto label;
		}
		else
		{
			for (int i = 0; i < 100; i++) // This For search to find if a person with this account number have another account.
			{
				if (check1 == true && nationalCodeC[count1] == nationalCodeS[i]) // This If search between saving accounts.
				{
					count2 = i;
					check3 = true;
				}
				else if (check2 == true && nationalCodeS[count1] == nationalCodeC[i]) // This If search between current accounts.
				{
					count2 = i;
					check3 = true;
				}
			}
			gotoxy(13, 14);
			cout << "Enter your password: ";
			gotoxy(13, 15);
		label2:cin >> password;
			if (password == passwordC[count1] && check1 == true) // This if is for checking password. And if 
																 // password of current account is true commands run.
			{
				gotoxy(13, 16);
				cout << "How much money do you want to transfer?";
				gotoxy(13, 17);
				cin >> moneyTM;
				if (moneyTM < moneyC[count1] || moneyTM == moneyC[count1]) // First This If check if money that we want
																		   //transfer is not less than account balance commands run.
				{
					if (check3 == true)
					{
						gotoxy(13, 18);
						cout << "You want to transfer money to:" << endl;
						gotoxy(13, 19);
						cout << "1. Your account." << endl;
						gotoxy(13, 20);
						cout << "2. Another person account." << endl;
					loop:gotoxy(13, 21);
						cin >> chNum;
						switch (chNum) // This Switch is to choose you want transfer money to your account
									   //or another person account.
						{
						case 1:
							moneyC[count1] -= moneyTM;
							billC[count1][countBillC[count1]] = moneyTM;
							signC[count1][countBillC[count1]] = '-';
							system("cls");
							box(box1);
							date(1, count1);
							moneyS[count2] += moneyTM;
							billS[count2][countBillS[count2]] = moneyTM;
							signS[count2][countBillS[count2]] = '+';
							dateS[count2][countBillS[count2]][0] = dateC[count1][countBillC[count1]][0];
							dateS[count2][countBillS[count2]][1] = dateC[count1][countBillC[count1]][1];
							dateS[count2][countBillS[count2]][2] = dateC[count1][countBillC[count1]][2];
							countBillC[count1]++;
							countBillS[count2]++;
							gotoxy(13, 26);
							cout << "Transaction Has Been Done.";
							gotoxy(13, 27);
							_getch();
							break;
						case 2:
							gotoxy(13, 22);
							cout << "Enter account number of reciever: ";
							gotoxy(13, 23);
							cin >> accountNumTM;
							for (int i = 0; i < 100; i++) // This For search to find reciever 
														  //account number between accounts.
							{
								if (accountNumTM == accountNumC[i])
								{
									count3 = i;
									check4 = true;
									break;
								}
								else if (accountNumTM == accountNumS[i])
								{
									count3 = i;
									check5 = true;
									break;
								}
							}
							if (check4 == false && check5 == false)// This If is for when account number 
																   //there is not between accounts.
							{
								gotoxy(13, 24);
								cout << "Your account number does not exist in system.";
								gotoxy(13, 25);
								_getch();
								goto label;
							}
							else if (check4 == true)
							{
								moneyC[count1] -= moneyTM;
								billC[count1][countBillC[count1]] = moneyTM;
								signC[count1][countBillC[count1]] = '-';
								system("cls");
								box(box1);
								date(1, count1);
								moneyC[count3] += moneyTM;
								billC[count3][countBillC[count3]] = moneyTM;
								signC[count3][countBillC[count3]] = '+';
								dateC[count3][countBillC[count3]][0] = dateC[count1][countBillC[count1]][0];
								dateC[count3][countBillC[count3]][1] = dateC[count1][countBillC[count1]][1];
								dateC[count3][countBillC[count3]][2] = dateC[count1][countBillC[count1]][2];
								countBillC[count1]++;
								countBillC[count3]++;
								gotoxy(13, 26);
								cout << "Transaction Has Been Done.";
								gotoxy(13, 27);
								_getch();
								break;
							}
							else if (check5 == true)
							{
								moneyC[count1] -= moneyTM;
								billC[count1][countBillC[count1]] = moneyTM;
								signC[count1][countBillC[count1]] = '-';
								system("cls");
								box(box1);
								date(1, count1);
								moneyS[count3] += moneyTM;
								billS[count3][countBillS[count3]] = moneyTM;
								signS[count3][countBillS[count3]] = '+';
								dateS[count3][countBillS[count3]][0] = dateC[count1][countBillC[count1]][0];
								dateS[count3][countBillS[count3]][1] = dateC[count1][countBillC[count1]][1];
								dateS[count3][countBillS[count3]][2] = dateC[count1][countBillC[count1]][2];
								countBillC[count1]++;
								countBillS[count3]++;
								gotoxy(13, 26);
								cout << "Transaction Has Been Done.";
								gotoxy(13, 27);
								_getch();
								break;
							}
							break;
						default:
							gotoxy(13, 22);
							cout << "Wrong Number.";
							_getch();
							gotoxy(13, 21);
							cout << "      ";
							goto loop;
							break;
						}
					}
					else
					{
						gotoxy(13, 18);
						cout << "Enter account number of reciever: ";
						gotoxy(13, 19);
						cin >> accountNumTM;
						for (int i = 0; i < 100; i++) // This For search to find reciever 
													  //account number between accounts.
						{
							if (accountNumTM == accountNumC[i])
							{
								count3 = i;
								check4 = true;
								break;
							}
							else if (accountNumTM == accountNumS[i])
							{
								count3 = i;
								check5 = true;
								break;
							}
						}
						if (check4 == false && check5 == false)// This If is for when account number 
															   //there is not between accounts.
						{
							gotoxy(13, 20);
							cout << "Your account number does not exist in system.";
							gotoxy(13, 21);
							_getch();
							goto label;
						}
						else if (check4 == true)
						{
							moneyC[count1] -= moneyTM;
							billC[count1][countBillC[count1]] = moneyTM;
							signC[count1][countBillC[count1]] = '-';
							system("cls");
							box(box1);
							date(1, count1);
							moneyC[count3] += moneyTM;
							billC[count3][countBillC[count3]] = moneyTM;
							signC[count3][countBillC[count3]] = '+';
							dateC[count3][countBillC[count3]][0] = dateC[count1][countBillC[count1]][0];
							dateC[count3][countBillC[count3]][1] = dateC[count1][countBillC[count1]][1];
							dateC[count3][countBillC[count3]][2] = dateC[count1][countBillC[count1]][2];
							countBillC[count1]++;
							countBillC[count3]++;
							gotoxy(13, 26);
							cout << "Transaction Has Been Done.";
							gotoxy(13, 27);
							_getch();
							break;
						}
						else if (check5 == true)
						{
							moneyC[count1] -= moneyTM;
							billC[count1][countBillC[count1]] = moneyTM;
							signC[count1][countBillC[count1]] = '-';
							system("cls");
							box(box1);
							date(1, count1);
							moneyS[count3] += moneyTM;
							billS[count3][countBillS[count3]] = moneyTM;
							signS[count3][countBillS[count3]] = '+';
							dateS[count3][countBillS[count3]][0] = dateC[count1][countBillC[count1]][0];
							dateS[count3][countBillS[count3]][1] = dateC[count1][countBillC[count1]][1];
							dateS[count3][countBillS[count3]][2] = dateC[count1][countBillC[count1]][2];
							countBillC[count1]++;
							countBillS[count3]++;
							gotoxy(13, 26);
							cout << "Transaction Has Been Done.";
							gotoxy(13, 27);
							_getch();
							break;
						}

					}
				}
				else
				{
					gotoxy(13, 20);
					cout << "Your account balance is not enough.";
					gotoxy(13, 21);
					_getch();
					goto label;
				}
			}
			else if (password == passwordS[count1] && check2 == true)
			{
				gotoxy(13, 16);
				cout << "How much money do you want to transfer?";
				gotoxy(13, 17);
				cin >> moneyTM;
				if (moneyTM < moneyS[count1] || moneyTM == moneyS[count1]) // First This If check if money that we want
																		   //transfer is not less than account balance commands run.
				{
					if (check3 == true)
					{
						gotoxy(13, 18);
						cout << "You want to transfer money to:" << endl;
						gotoxy(13, 19);
						cout << "1. Your account." << endl;
						gotoxy(13, 20);
						cout << "2. Another person account." << endl;
						gotoxy(13, 21);
						cin >> chNum;
						switch (chNum) // This Switch is to choose you want transfer money to your account
									   //or another person account.
						{
						case 1:
							moneyS[count1] -= moneyTM;
							billS[count1][countBillS[count1]] = moneyTM;
							signS[count1][countBillS[count1]] = '-';
							system("cls");
							box(box1);
							date(2, count1);
							moneyC[count2] += moneyTM;
							billC[count2][countBillC[count2]] = moneyTM;
							signC[count2][countBillC[count2]] = '+';
							dateC[count2][countBillC[count2]][0] = dateS[count1][countBillS[count1]][0];
							dateC[count2][countBillC[count2]][1] = dateS[count1][countBillS[count1]][1];
							dateC[count2][countBillC[count2]][2] = dateS[count1][countBillS[count1]][2];
							countBillS[count1]++;
							countBillC[count2]++;
							gotoxy(13, 26);
							cout << "Transaction Has Been Done.";
							gotoxy(13, 27);
							_getch();
							break;
						case 2:
							gotoxy(13, 22);
							cout << "enter account number of reciever: ";
							gotoxy(13, 23);
							cin >> accountNumTM;
							for (int i = 0; i < 100; i++) // This For search to find reciever 
														  //account number between accounts.
							{
								if (accountNumTM == accountNumC[i])
								{
									count3 = i;
									check4 = true;
									break;
								}
								else if (accountNumTM == accountNumS[i])
								{
									count3 = i;
									check5 = true;
									break;
								}
							}
							if (check4 == false && check5 == false)// This If is for when account number 
																   //there is not between accounts.
							{
								gotoxy(13, 24);
								cout << "Your account number does not exist in system.";
								gotoxy(13, 25);
								_getch();
								goto label;
							}
							else if (check4 == true)
							{
								moneyS[count1] -= moneyTM;
								billS[count1][countBillS[count1]] = moneyTM;
								signS[count1][countBillS[count1]] = '-';
								system("cls");
								box(box1);
								date(2, count1);
								moneyC[count3] += moneyTM;
								billC[count3][countBillC[count3]] = moneyTM;
								signC[count3][countBillC[count3]] = '+';
								dateC[count3][countBillC[count3]][0] = dateS[count1][countBillS[count1]][0];
								dateC[count3][countBillC[count3]][1] = dateS[count1][countBillS[count1]][1];
								dateC[count3][countBillC[count3]][2] = dateS[count1][countBillS[count1]][2];
								countBillS[count1]++;
								countBillC[count3]++;
								gotoxy(13, 26);
								cout << "Transaction Has Been Done.";
								gotoxy(13, 27);
								_getch();
								break;
							}
							else if (check5 == true)
							{
								moneyS[count1] -= moneyTM;
								billS[count1][countBillS[count1]] = moneyTM;
								signS[count1][countBillS[count1]] = '-';
								system("cls");
								box(box1);
								date(2, count1);
								moneyS[count3] += moneyTM;
								billS[count3][countBillS[count3]] = moneyTM;
								signS[count3][countBillS[count3]] = '+';
								dateS[count3][countBillS[count3]][0] = dateS[count1][countBillS[count1]][0];
								dateS[count3][countBillS[count3]][1] = dateS[count1][countBillS[count1]][1];
								dateS[count3][countBillS[count3]][2] = dateS[count1][countBillS[count1]][2];
								countBillS[count1]++;
								countBillS[count3]++;
								gotoxy(13, 26);
								cout << "Transaction Has Been Done.";
								gotoxy(13, 27);
								_getch();
								break;
							}
							break;
						default:
							gotoxy(13, 22);
							cout << "Wrong Number.";
							_getch();
							gotoxy(13, 21);
							cout << "      ";
							goto loop;
							break;
						}
					}
					else // This else is for when we enter a wrong account number.
					{
						gotoxy(13, 18);
						cout << "enter account number of reciever: ";
						gotoxy(13, 19);
						cin >> accountNumTM;
						for (int i = 0; i < 100; i++) // This For search to find reciever 
													  //account number between accounts.
						{
							if (accountNumTM == accountNumC[i])
							{
								count3 = i;
								check4 = true;
								break;
							}
							else if (accountNumTM == accountNumS[i])
							{
								count3 = i;
								check5 = true;
								break;
							}
						}
						if (check4 == false && check5 == false)// This If is for when account number 
															   //there is not between accounts.
						{
							gotoxy(13, 20);
							cout << "Your account number does not exist in system.";
							gotoxy(13, 21);
							_getch();
							goto label;
						}
						else if (check4 == true)
						{
							moneyS[count1] -= moneyTM;
							billS[count1][countBillS[count1]] = moneyTM;
							signS[count1][countBillS[count1]] = '-';
							system("cls");
							box(box1);
							date(2, count1);
							moneyC[count3] += moneyTM;
							billC[count3][countBillC[count3]] = moneyTM;
							signC[count3][countBillC[count3]] = '+';
							dateC[count3][countBillC[count3]][0] = dateS[count1][countBillS[count1]][0];
							dateC[count3][countBillC[count3]][1] = dateS[count1][countBillS[count1]][1];
							dateC[count3][countBillC[count3]][2] = dateS[count1][countBillS[count1]][2];
							countBillS[count1]++;
							countBillC[count3]++;
							gotoxy(13, 26);
							cout << "Transaction Has Been Done.";
							gotoxy(13, 27);
							_getch();
							break;
						}
						else if (check5 == true)
						{
							moneyS[count1] -= moneyTM;
							billS[count1][countBillS[count1]] = moneyTM;
							signS[count1][countBillS[count1]] = '-';
							system("cls");
							box(box1);
							date(2, count1);
							moneyS[count3] += moneyTM;
							billS[count3][countBillS[count3]] = moneyTM;
							signS[count3][countBillS[count3]] = '+';
							dateS[count3][countBillS[count3]][0] = dateS[count1][countBillS[count1]][0];
							dateS[count3][countBillS[count3]][1] = dateS[count1][countBillS[count1]][1];
							dateS[count3][countBillS[count3]][2] = dateS[count1][countBillS[count1]][2];
							countBillS[count1]++;
							countBillS[count3]++;
							gotoxy(13, 26);
							cout << "Transaction Has Been Done.";
							gotoxy(13, 27);
							_getch();
							break;
						}
					}
				}
				else // This Else is for when account ballance is not enough.
				{
					gotoxy(13, 20);
					cout << "Your account balance is not enough.";
					gotoxy(13, 21);
					_getch();
					goto label;
				}
			}
			else // This else is for when user inter a wrong password.
			{
				gotoxy(13, 16);
				cout << "Password Is Wrong.";
				_getch();
				gotoxy(13, 15);
				cout << "              ";
				goto label2;
			}
		}
		break;
	case 2:
		main();
		break;
	default:
		gotoxy(13, 10);
		cout << "    ";
		goto label1;
		break;
	}

}
//***********************Recieve_Money*******************************
void recieve_money(char box1[30][30])
{
	long long int accountNumRM, moneyRM;
	int count, c;
	bool check1 = false, check2 = false;
	string s1("Recieve Money");
	string password;
labelcls:system("cls");
	refresh(box1);
	for (int k = 0; k < 13; k++)
		box1[2][k + 7] = s1[k];
	box(box1);
	gotoxy(13, 8);
	cout << "Choose Action:";
	gotoxy(13, 10);
	cout << "1.recieve money";
	gotoxy(13, 11);
	cout << "2.Back To menu";
	gotoxy(13, 12);
	cin >> c;
	switch (c)
	{
	case 1:
		gotoxy(13, 14);
		cout << "Enter yor account number: ";
		gotoxy(13, 15);
		cin >> accountNumRM;
		for (int i = 0; i < 100; i++) // This For search to find account number that we enter between arrays room.
		{
			if (accountNumRM == accountNumC[i]) // This If find account number between current accounts.
			{
				count = i;
				check1 = true;
				break;
			}
			else if (accountNumRM == accountNumS[i]) // This If find account number between saving accounts.
			{
				count = i;
				check2 = true;
				break;
			}

		}
		if (check1 == false && check2 == false) // If account number does not exist between arrays rooms this Else use.
		{
			gotoxy(13, 19);
			cout << "Your account number does not exist in system.";
			gotoxy(13, 20);
			_getch();
			goto labelcls;
		}
		else // If check1 == true or check2 == true commands run.
		{
			gotoxy(13, 17);
		labelpass:cout << "Enter your password. ";
			gotoxy(13, 18);
			cin >> password;
			if (check1 == true && password == passwordC[count]) // If account is current and password is true commands run.
			{
				gotoxy(13, 20);
				cout << "How much money do you want to recieve? ";
				gotoxy(13, 22);
				cin >> moneyRM;
				if (moneyRM == moneyC[count] || moneyRM < moneyC[count])
				{
					moneyC[count] -= moneyRM;
					billC[count][countBillC[count]] = moneyRM;
					signC[count][countBillC[count]] = '-';
					system("cls");
					box(box1);
					date(1, count);
					gotoxy(13, 26);
					cout << "Your account balance is :" << moneyC[count];
					gotoxy(13, 27);
					_getch();
					countBillC[count]++;
				}
				else // If account balance is not enough here we have an error.
				{
					gotoxy(13, 25);
					cout << "Your account balance is not enough.";
					gotoxy(13, 26);
					_getch();
					main();
				}
			}
			else if (check2 == true && password == passwordS[count]) //If account is saving and password is true commands run.
			{
				gotoxy(13, 20);
				cout << "How much money do you want to recieve? ";
				gotoxy(13, 22);
				cin >> moneyRM;
				if (moneyRM == moneyS[count] || moneyRM < moneyS[count])
				{
					moneyS[count] -= moneyRM;
					billS[count][countBillS[count]] = moneyRM;
					signS[count][countBillS[count]] = '-';
					system("cls");
					box(box1);
					date(2, count);
					gotoxy(13, 26);
					cout << "Your account balance is :" << moneyS[count];
					gotoxy(13, 27);
					_getch();
					countBillS[count]++;
				}
				else // If account balance is not enough here we have an error.
				{
					gotoxy(13, 25);
					cout << "Your account balance is not enough.";
					gotoxy(13, 26);
					_getch();
					main();
				}
			}
			else if (password != passwordS[count] && password != passwordC[count])
			{
				gotoxy(13, 20);
				cout << "Your Password Is Wrong.";
				_getch();
				gotoxy(13, 18);
				cout << "                           ";
				goto labelpass;
			}
		}
		break;
	case 2:
		main();
		break;
	default:
		gotoxy(13, 17);
		cout << "The Number Is Wrong.";
		_getch();
		goto labelcls;
		break;
	}

}
//************************balance_enquiry****************************
void balance_enquiry(char box1[30][30])
{
	long long int accountNumBE;
	int count, c;
	bool check1 = false, check2 = false;
	string s1("Balance Enquiry");
	string password;
label4:system("cls");
	refresh(box1);
	for (int k = 0; k < 15; k++)
		box1[2][k + 9] = s1[k];
	box(box1);
	gotoxy(13, 8);
	cout << "Choose Action:";
	gotoxy(13, 10);
	cout << "1.balance enquiry";
	gotoxy(13, 11);
	cout << "2.Back To menu";
	gotoxy(13, 12);
	cin >> c;
	switch (c)
	{
	case 1:
		gotoxy(13, 14);
		cout << "Enter yor account number: ";
		gotoxy(13, 16);
		cin >> accountNumBE;
		for (int i = 0; i < 100; i++) // This For search to find account number that we enter between arrays room.
		{
			if (accountNumBE == accountNumC[i]) // This If find account number between current accounts.
			{
				count = i;
				check1 = true;
				break;
			}
			else if (accountNumBE == accountNumS[i]) // This If find account number between saving accounts.
			{
				count = i;
				check2 = true;
				break;
			}

		}
		if (check1 == false && check2 == false) // If account number does not exist between arrays rooms this Else use.
		{
			gotoxy(13, 18);
			cout << "Your account number does not exist in system.";
			gotoxy(13, 20);
			_getch();
			goto label4;
		}
		else // If check1 == true or check2 == true commands run.
		{
			gotoxy(13, 18);
			cout << "Enter your password:";
			gotoxy(13, 19);
			cin >> password;
			if (check1 == true && password == passwordC[count]) // If account is current and password is true commands run.
			{
				gotoxy(13, 21);
				cout << "Your Name Is :" << name_familyC[count];
				gotoxy(13, 23);
				cout << "Your Account Number Is :" << accountNumC[count];
				gotoxy(13, 25);
				cout << "Your account balance is : " << moneyC[count];
				gotoxy(13, 27);
				_getch();
			}
			else if (check2 == true && password == passwordS[count]) //If account is saving and password is true commands run.
			{
				gotoxy(13, 21);
				cout << "Your Name Is :" << name_familyS[count];
				gotoxy(13, 23);
				cout << "Your Account Number Is :" << accountNumS[count];
				gotoxy(13, 25);
				cout << "Your account balance is : " << moneyS[count];
				gotoxy(13, 27);
				_getch();
			}
		}
		break;
	case 2:
		main();
		break;
	default:
		goto label4;
		break;
	}
}
//**********************Buy_Mobile_Charge****************************
void Buy_Mobile_Charge(char box1[30][30])
{
	long long int accountNumBMC, chargeBMC1, chargeBMC2, chargeBMC3;
	int count, chNum, c;
	bool check1 = false, check2 = false;
	string password;
	string s1("Mobile Charge");
labelcls:system("cls");
	refresh(box1);
	for (int k = 0; k < 13; k++)
		box1[2][k + 7] = s1[k];
	box(box1);
	gotoxy(13, 8);
	cout << "Choose Action:";
	gotoxy(13, 10);
	cout << "1.Buy mobile charge";
	gotoxy(13, 12);
	cout << "2.Back To menu";
	gotoxy(13, 14);
	cin >> c;
	switch (c)
	{
	case 1:
		gotoxy(13, 16);
		cout << "Enter yor account number: ";
		gotoxy(13, 17);
		cin >> accountNumBMC;
		for (int i = 0; i < 100; i++) // This For search to find account number that we enter between arrays room.
		{
			if (accountNumBMC == accountNumC[i]) // This If find account number between current accounts.
			{
				count = i;
				check1 = true;
				break;
			}
			else if (accountNumBMC == accountNumS[i]) // This If find account number between saving accounts.
			{
				count = i;
				check2 = true;
				break;
			}
		}
		if (check1 == false && check2 == false) // If account number does not exist between arrays rooms this Else use.
		{
			gotoxy(13, 20);
			cout << "Your account number does not exist in system.";
			gotoxy(13, 21);
			_getch();
			goto labelcls;
		}
		else // If check1 == true or check2 == true commands run.
		{
			gotoxy(13, 19);
		labelpass:cout << "Enter your password. ";
			gotoxy(13, 20);
			cin >> password;
			if (check1 == true && password == passwordC[count]) // If account is current and password is true commands run.
			{
				gotoxy(13, 22);
				cout << "which one do you choose?";
				gotoxy(13, 24);
				cout << "1. Irancell ";
				gotoxy(13, 25);
				cout << "2. MCI ";
				gotoxy(13, 26);
				cout << "3. RighTel ";
				gotoxy(13, 27);
				cin >> chNum;
				system("cls");
				box(box1);
				switch (chNum)
				{
				case 1:
				case 2:
				case 3:
					gotoxy(13, 8);
					cout << "1. 10000 R";
					gotoxy(13, 9);
					cout << "2. 20000 R";
					gotoxy(13, 10);
					cout << "3. 50000 R";
					gotoxy(13, 11);
					cout << "4. 100000 R";
					gotoxy(13, 12);
					cout << "5. 200000 R";
					gotoxy(13, 13);
				labelre:cin >> chNum;
					switch (chNum)
					{
					case 1:
						if (moneyC[count] >= 10000)
						{
							moneyC[count] -= 10000;
							billC[count][countBillC[count]] = 10000;
							signC[count][countBillC[count]] = '-';
							date(1, count);
							countBillC[count]++;
						}
						else
						{
							gotoxy(13, 26);
							cout << "Your Account Ballance Is Not Enough.";
							_getch();
							main();
						}
						break;
					case 2:
						if (moneyC[count] >= 20000)
						{
							moneyC[count] -= 20000;
							billC[count][countBillC[count]] = 20000;
							signC[count][countBillC[count]] = '-';
							date(1, count);
							countBillC[count]++;
						}
						else
						{
							gotoxy(13, 26);
							cout << "Your Account Ballance Is Not Enough.";
							_getch();
							main();
						}
						break;
					case 3:
						if (moneyC[count] >= 50000)
						{
							moneyC[count] -= 50000;
							billC[count][countBillC[count]] = 50000;
							signC[count][countBillC[count]] = '-';
							date(1, count);
							countBillC[count]++;
						}
						else
						{
							gotoxy(13, 26);
							cout << "Your Account Ballance Is Not Enough.";
							_getch();
							main();
						}
						break;
					case 4:
						if (moneyC[count] >= 100000)
						{
							moneyC[count] -= 100000;
							billC[count][countBillC[count]] = 100000;
							signC[count][countBillC[count]] = '-';
							date(1, count);
							countBillC[count]++;
						}
						else
						{
							gotoxy(13, 26);
							cout << "Your Account Ballance Is Not Enough.";
							_getch();
							main();
						}
						break;
					case 5:
						if (moneyC[count] >= 200000)
						{
							moneyC[count] -= 200000;
							billC[count][countBillC[count]] = 200000;
							signC[count][countBillC[count]] = '-';
							date(1, count);
							countBillC[count]++;
						}
						else
						{
							gotoxy(13, 26);
							cout << "Your Account Ballance Is Not Enough.";
							_getch();
							main();
						}
						break;
					default:
						gotoxy(13, 24);
						cout << "            ";
						goto labelre;
						break;
					}
					break;
				default:
					goto labelcls;
					break;
				}
				chargeBMC1 = rand() % (899) + 100;
				chargeBMC2 = rand() % (899) + 100;
				chargeBMC3 = rand() % (8999) + 1000;
				gotoxy(13, 26);
				cout << "charge code : " << (chargeBMC1 * 10000000) + (chargeBMC2 * 10000) + chargeBMC3;
				gotoxy(13, 28);
				cout << "Your account balance is : " << moneyC[count];
				gotoxy(13, 29);
				cout << "Transaction Has Been Done.";
				_getch();
			}
			else if (check2 == true && password == passwordS[count]) //If account is saving and password is true commands run.
			{
				gotoxy(13, 22);
				cout << "which one do you choose?";
				gotoxy(13, 24);
				cout << "1. Irancell ";
				gotoxy(13, 25);
				cout << "2. MCI ";
				gotoxy(13, 26);
				cout << "3. RighTel ";
				gotoxy(13, 27);
				cin >> chNum;
				system("cls");
				box(box1);
				switch (chNum)
				{
				case 1:
				case 2:
				case 3:
					gotoxy(13, 8);
					cout << "1. 10000 R";
					gotoxy(13, 9);
					cout << "2. 20000 R";
					gotoxy(13, 10);
					cout << "3. 50000 R";
					gotoxy(13, 11);
					cout << "4. 100000 R";
					gotoxy(13, 12);
					cout << "5. 200000 R";
					gotoxy(13, 13);
				labelre1:cin >> chNum;
					switch (chNum)
					{
					case 1:
						if (moneyC[count] >= 10000)
						{
							moneyS[count] -= 10000;
							billS[count][countBillS[count]] = 10000;
							signS[count][countBillS[count]] = '-';
							date(2, count);
							countBillS[count]++;
						}
						else
						{
							gotoxy(13, 26);
							cout << "Your Account Ballance Is Not Enough.";
							_getch();
							main();
						}
						break;
					case 2:
						if (moneyC[count] >= 20000)
						{
							moneyS[count] -= 20000;
							billS[count][countBillS[count]] = 20000;
							signS[count][countBillS[count]] = '-';
							date(2, count);
							countBillS[count]++;
						}
						else
						{
							gotoxy(13, 26);
							cout << "Your Account Ballance Is Not Enough.";
							_getch();
							main();
						}
						break;
					case 3:
						if (moneyC[count] >= 50000)
						{
							moneyS[count] -= 50000;
							billS[count][countBillS[count]] = 50000;
							signS[count][countBillS[count]] = '-';
							date(2, count);
							countBillS[count]++;
						}
						else
						{
							gotoxy(13, 26);
							cout << "Your Account Ballance Is Not Enough.";
							_getch();
							main();
						}
						break;
					case 4:
						if (moneyC[count] >= 100000)
						{
							moneyS[count] -= 100000;
							billS[count][countBillS[count]] = 100000;
							signS[count][countBillS[count]] = '-';
							date(2, count);
							countBillS[count]++;
						}
						else
						{
							gotoxy(13, 26);
							cout << "Your Account Ballance Is Not Enough.";
							_getch();
							main();
						}
						break;
					case 5:
						if (moneyC[count] >= 10000)
						{
							moneyS[count] -= 200000;
							billS[count][countBillS[count]] = 200000;
							signS[count][countBillS[count]] = '-';
							date(2, count);
							countBillS[count]++;
						}
						else
						{
							gotoxy(13, 26);
							cout << "Your Account Ballance Is Not Enough.";
							_getch();
							main();
						}
						break;
					default:
						gotoxy(13, 24);
						cout << "            ";
						goto labelre1;
						break;
					}
					break;
				default:
					goto labelcls;
					break;
				}
				chargeBMC1 = rand() % (899) + 100;
				chargeBMC2 = rand() % (899) + 100;
				chargeBMC3 = rand() % (8999) + 1000;
				gotoxy(13, 26);
				cout << "charge code : " << (chargeBMC1 * 10000000) + (chargeBMC2 * 10000) + chargeBMC3;
				gotoxy(13, 28);
				cout << "Your account balance is : " << moneyS[count];
				gotoxy(13, 29);
				cout << "Transaction Has Been Done.";
				_getch();
			}
			else
			{
				gotoxy(13, 18);
				cout << "You enter a wrong password try again.";
				_getch();
				gotoxy(13, 16);
				cout << "                         ";
				goto labelpass;
			}
		}
		break;
	case 2:
		main();
	default:
		goto labelcls;
		break;
	}
}
//************************Creator************************************
void crt(char box1[30][30])
{
	refresh(box1);
	string s1("Creator");
	for (int k = 0; k < 7; k++)
		box1[2][k + 11] = s1[k];
	box(box1);
	int n = 500;
	gotoxy(25, 12);
	cout << "N";
	Sleep(n);
	cout << "E";
	Sleep(n);
	cout << "D";
	Sleep(n);
	cout << "A";
	Sleep(n);
	cout << "  E";
	Sleep(n);
	cout << "S";
	Sleep(n);
	cout << "H";
	Sleep(n);
	cout << "R";
	Sleep(n);
	cout << "A";
	Sleep(n);
	cout << "G";
	Sleep(n);
	cout << "H";
	Sleep(n);
	cout << "I";
	Sleep(n);
	cout << " & ";
	Sleep(n);
	cout << "M";
	Sleep(n);
	cout << "O";
	Sleep(n);
	cout << "H";
	Sleep(n);
	cout << "S";
	Sleep(n);
	cout << "E";
	Sleep(n);
	cout << "N";
	Sleep(n);
	cout << " J";
	Sleep(n);
	cout << "A";
	Sleep(n);
	cout << "L";
	Sleep(n);
	cout << "A";
	Sleep(n);
	cout << "L";
	Sleep(n);
	cout << "I";
	Sleep(n);
	Sleep(n);
}
//************************Riceive Bill*******************************
void recieve_bill(char box1[30][30])
{
	long long int accountNumRB;
	string password;
	string s1("Riceive Bill");
	int count, countBill = 0, c;
	bool check1 = false, check2 = false;
labelcls:system("cls");
	refresh(box1);
	for (int k = 0; k < 12; k++)
		box1[2][k + 8] = s1[k];
	box(box1);
	gotoxy(13, 8);
	cout << "Choose Action:";
	gotoxy(13, 10);
	cout << "1.Riceive Bill";
	gotoxy(13, 12);
	cout << "2.Back To menu";
	gotoxy(13, 14);
	cin >> c;
	switch (c)
	{
	case 1:
		gotoxy(13, 16);
		cout << "Enter yor account number: ";
		gotoxy(13, 17);
		cin >> accountNumRB;
		for (int i = 0; i < 100; i++) // This For search to find account number that we enter between arrays room.
		{
			if (accountNumRB == accountNumC[i]) // This If find account number between current accounts.
			{
				count = i;
				check1 = true;
				break;
			}
			else if (accountNumRB == accountNumS[i]) // This If find account number between saving accounts.
			{
				count = i;
				check2 = true;
				break;
			}
		}
		if (check1 == false && check2 == false) // If account number does not exist between arrays rooms this Else use.
		{
			gotoxy(13, 18);
			cout << "Your account number does not exist in system.";
			_getch();
			goto labelcls;
		}
		else // If check1 == true or check2 == true commands run.
		{
			gotoxy(13, 18);
			cout << "Enter your password. ";
			gotoxy(13, 19);
		labelpass:gotoxy(13, 19);
			cin >> password;
			if (check1 == true && password == passwordC[count]) // If account is current and password is true commands run.
			{
				countBill = countBillC[count] - 1;
				for (int i = 0; i < 10; i++)
				{
					if (countBill < 0) // This If define because maybe a user does not work with
									   // his/her account 10 time so this If help come out of loop.
						break;
					else
					{
						gotoxy(13, i + 20);
						cout << signC[count][countBill] << " " << billC[count][countBill];
						countBill--;
					}
				}
				_getch();
			}
			else if (check2 == true && password == passwordS[count]) //If account is saving and password is true commands run.
			{
				countBill = countBillS[count] - 1;
				for (int i = 0; i < 10; i++)
				{
					if (countBill < 0)
						break;
					else
					{
						gotoxy(13, i + 20);
						cout << signS[count][countBill] << " " << billS[count][countBill];
						countBill--;
					}
				}
				_getch();
			}

			else
			{
				gotoxy(13, 25);
				cout << "wrong password";
				_getch();
				gotoxy(13, 19);
				cout << "                  ";
				gotoxy(13, 25);
				cout << "                      ";
				goto labelpass;

			}
		}
		break;
	case 2:
		main();
	default:
		goto labelcls;
		break;
	}

}
//****************************lottery & request loan********************************
void cas9(char box1[30][30])
{
	int c;
labelcls:system("cls");
	refresh(box1);
	string s1("Lottery & Loan");
	for (int k = 0; k < 14; k++)
		box1[2][k + 7] = s1[k];
	box(box1);
	gotoxy(13, 12);
	cout << "1.lottery";
	gotoxy(13, 14);
	cout << "2.Request Loan";
	gotoxy(13, 16);
	cout << "3.Back";
	gotoxy(13, 18);
	cin >> c;
	switch (c)
	{
	case 1:
		lottery(box1);
	case 2:
		request_loan(box1);
	case 3:
		main();
	default:
		goto labelcls;
		break;
	}
}
//****************************lottery***********************************
void lottery(char box1[30][30])
{

	int m, n, count = 0;
	for (int i = 0; i < 100; i++)
	{
		if (countBillS[i] == -858993460)
			break;
		count += countBillS[i];
	}

	int *lottery;
	lottery = new int[count];
	if (!lottery)
	{
		exit(1);
	}
	for (int i = 0; i < 100; i++)
	{
		if (countBillS[i] == -858993460)
			break;
		for (int j = 0; j < countBillS[i]; j++)
		{
			*(lottery + j) = i;
		}
	}
	m = rand() % (count);
	n = *(lottery + m);
	gotoxy(13, 10);
	cout << "National Code Is:" << nationalCodeS[n];//+++++++++
	gotoxy(13, 12);
	cout << "Full Name Is:" << name_familyS[n];//+++++++
	gotoxy(13, 14);
	cout << "Account Number Is:" << accountNumS[n];//++++++++++++
	_getch();
	delete[] lottery;
}
//***********************TransactionList*****************************
void transaction_list(char box1[30][30])
{
	int yearTL, monthTL, dayTL;
	long long int accountNumTL;
	string password;
	string s1("Transaction List");
labelcls:system("cls");
	refresh(box1);
	for (int k = 0; k < 18; k++)
		box1[2][k + 7] = s1[k];
	box(box1);
	int count1, count2;
	bool check1 = false, check2 = false, check3 = false;
	gotoxy(13, 8);
	cout << "Enter yor account number: ";
	cin >> accountNumTL;
	for (int i = 0; i < 100; i++) // This For search to find account number that we enter between arrays room.
	{
		if (accountNumTL == accountNumC[i]) // This If find account number between current accounts.
		{
			count1 = i;
			check1 = true;
			break;
		}
		else if (accountNumTL == accountNumS[i]) // This If find account number between saving accounts.
		{
			count1 = i;
			check2 = true;
			break;
		}
	}
	if (check1 == false && check2 == false) // If account number does not exist between arrays rooms this Else use.
	{
		gotoxy(13, 20);
		cout << "Your account number does not exist in system.";
		goto labelcls;
	}
	else // If check1 == true or check2 == true commands run.
	{
		gotoxy(13, 10);
			cout << "Enter your password. ";
	labelpass:gotoxy(13, 11);
		cin >> password;
		if (check1 == true && password == passwordC[count1]) // If account is current and password is true commands run.
		{
			gotoxy(13, 13);
			cout << "From which year do you want get bill? ";
			cin >> yearTL;
			gotoxy(13, 15);
			cout << "From which month? ";
			cin >> monthTL;
			gotoxy(13, 17);
			cout << "From which day? ";
			cin >> dayTL;
			for (int i = 0; i < 100; i++) // This For define to search between years.
			{
				if (yearTL < dateC[count1][i][0])
				{
					check3 = true;
					count2 = i;
					break;
				}
				else if (yearTL == dateC[count1][i][0])
				{
					for (int j = i; dateC[count1][j][0] == yearTL; j++) // This For search between months.
					{
						if (monthTL < dateC[count1][j][1])
						{
							check3 = true;
							count2 = j;
							break;
						}
						else if (monthTL == dateC[count1][j][1])
						{
							for (int k = j; (dateC[count1][k][0] == yearTL) && (monthTL == dateC[count1][k][1]); k++) // This For search between days.
							{
								if (dayTL < dateC[count1][k][2])
								{
									check3 = true;
									count2 = j;
									break;
								}
								else if (dayTL == dateC[count1][k][2])
								{
									check3 = true;
									count2 = j;
									break;
								}
							}
							if (check3 == true)
								break;
						}
					}
					if (check3 == true)
						break;
				}
			}
			if (check3 == false)
			{
				gotoxy(13, 22);
				cout << "After this date you did not work with your account.";
				_getch();
				main();
			}
			system("cls");
			box(box1);
			for (int i = count2, k = 0; i <= countBillC[count1] - 1; i++, k++) // This For define to print transaction list.
			{
				if (k == 28)
				{
					gotoxy(13, 28);
					cout << "Press To See More.";
					_getch();
					system("cls");
					box(box1);
					k = 0;
				}
				gotoxy(13, k);
				cout << signC[count1][i] << " " << billC[count1][i] << "     ";
				cout << dateC[count1][i][0] << "/" << dateC[count1][i][1] << "/" << dateC[count1][i][2];
			}
			_getch();
		}
		else if (check2 == true && password == passwordS[count1]) //If account is saving and password is true commands run.
		{
			gotoxy(13, 13);
			cout << "From which year do you want get bill? ";
			cin >> yearTL;
			gotoxy(13, 15);
			cout << "From which month? ";
			cin >> monthTL;
			gotoxy(13, 17);
			cout << "From which day? ";
			cin >> dayTL;
			for (int i = 0; i < 100; i++) // This For define to search between years.
			{
				if (yearTL < dateS[count1][i][0])
				{
					check3 = true;
					count2 = i;
					break;
				}
				else if (yearTL == dateS[count1][i][0])
				{
					for (int j = i; dateS[count1][j][0] == yearTL; j++) // This For search between months.
					{
						if (monthTL < dateS[count1][j][1])
						{
							check3 = true;
							count2 = j;
							break;
						}
						else if (monthTL == dateS[count1][j][1])
						{
							for (int k = j; (dateS[count1][k][0] == yearTL) && (monthTL == dateS[count1][k][1]); k++) // This For search between days.
							{
								if (dayTL < dateS[count1][k][2])
								{
									check3 = true;
									count2 = j;
									break;
								}
								else if (dayTL == dateS[count1][k][2])
								{
									check3 = true;
									count2 = j;
									break;
								}
							}
							if (check3 == true)
								break;
						}
					}
					if (check3 == true)
						break;
				}
			}
			if (check3 == false)
			{
				gotoxy(13, 22);
				cout << "After this date you did not work with your account.";
				_getch();
				main();
			}
			system("cls");
			box(box1);
			for (int i = count2, k = 0; i <= countBillS[count1] - 1; i++, k++) // This For define to print transaction list.
			{
				if (k == 28)
				{
					gotoxy(13, 28);
					cout << "Press To See More.";
					_getch();
					system("cls");
					box(box1);
					k = 0;
				}
				gotoxy(13, k);
				cout << signS[count1][i] << " " << billS[count1][i] << "     ";
				cout << dateS[count1][i][0] << "/" << dateS[count1][i][1] << "/" << dateS[count1][i][2];
			}
			_getch();
		}
		else
		{
			gotoxy(13, 24);
			cout << "You enter a wrong password try again.";
			_getch();
			gotoxy(13, 12);
			cout << "        ";
			goto labelpass;
		}
	}
}
//**************************RequestLoan******************************
void request_loan(char box1[30][30])
{
	int yearRL, monthRL, dayRL;
	long long int accountNumRL, sum1 = 0, sum2 = 0, result = 0;
	string password;
	int count1, count2;
	bool check1 = false, check2 = false, check3 = false;
	string s1("Request Laon");
labelcls:system("cls");
	refresh(box1);
	for (int k = 0; k < 12; k++)
		box1[2][k + 9] = s1[k];
	box(box1);
	gotoxy(13, 8);
	cout << "Enter your account number: ";
	gotoxy(13, 10);
	cin >> accountNumRL;
	for (int i = 0; i < 100; i++) // This For search to find account number that we enter between arrays room.
	{
		if (accountNumRL == accountNumC[i]) // This If find account number between current accounts.
		{
			count1 = i;
			check1 = true;
			break;
		}
		else if (accountNumRL == accountNumS[i]) // This If find account number between saving accounts.
		{
			count1 = i;
			check2 = true;
			break;
		}
	}
	if (check1 == false && check2 == false) // If account number does not exist between arrays rooms this Else use.
	{
		gotoxy(13, 12);
		cout << "Your account number does not exist in system.";
		goto labelcls;
	}
	else // If check1 == true or check2 == true commands run.
	{
		gotoxy(13, 14);
		cout << "Enter your password. ";
		gotoxy(13, 15);
		cin >> password;
		if (check1 == true && password == passwordC[count1])
		{
			yearRL = dateC[count1][countBillC[count1]][0];
			monthRL = dateC[count1][countBillC[count1]][1] - 4;
			dayRL = dateC[count1][countBillC[count1]][2];
			for (int i = 0; i < 100; i++) // This For define to search between years.
			{
				if (yearRL < dateC[count1][i][0])
				{
					check3 = true;
					count2 = i;
					break;
				}
				else if (yearRL == dateC[count1][i][0])
				{
					for (int j = i; dateC[count1][j][0] == yearRL; j++) // This For search between months.
					{
						if (monthRL < dateC[count1][j][1])
						{
							check3 = true;
							count2 = j;
							break;
						}
						else if (monthRL == dateC[count1][j][1])
						{
							for (int k = j; (dateC[count1][k][0] == yearRL) && (monthRL == dateC[count1][k][1]); k++) // This For search between days.
							{
								if (dayRL < dateC[count1][k][2])
								{
									check3 = true;
									count2 = j;
									break;
								}
								else if (dayRL == dateC[count1][k][2])
								{
									check3 = true;
									count2 = j;
									break;
								}
							}
							if (check3 == true)
								break;
						}
					}
					if (check3 == true)
						break;
				}
			}
			sum1 = moneyC[count1];
			sum2 = moneyC[count1];
			for (int i = countBillC[count1] - 1; i >= count2; i--)
			{
				if (signC[count1][i] == "+")
				{
					sum1 -= billC[count1][i];
					sum2 += sum1;
				}
				else if (signC[count1][i] == "-")
				{
					sum1 += billC[count1][i];
					sum2 += sum1;
				}
			}
			result = sum2 / countBillC[count1] - count2;
			gotoxy(13, 18);
			cout << "You can have   " << result << "   as Loan.";
			_getch();
		}
		else if (check2 == true && password == passwordS[count1]) //If account is saving and password is true commands run.
		{
			yearRL = dateS[count1][countBillS[count1]][0];
			monthRL = dateS[count1][countBillS[count1]][1] - 4;
			dayRL = dateS[count1][countBillS[count1]][2];
			for (int i = 0; i < 100; i++) // This For define to search between years.
			{
				if (yearRL < dateS[count1][i][0])
				{
					check3 = true;
					count2 = i;
					break;
				}
				else if (yearRL == dateS[count1][i][0])
				{
					for (int j = i; dateS[count1][j][0] == yearRL; j++) // This For search between months.
					{
						if (monthRL < dateS[count1][j][1])
						{
							check3 = true;
							count2 = j;
							break;
						}
						else if (monthRL == dateS[count1][j][1])
						{
							for (int k = j; (dateS[count1][k][0] == yearRL) && (monthRL == dateS[count1][k][1]); k++) // This For search between days.
							{
								if (dayRL < dateS[count1][k][2])
								{
									check3 = true;
									count2 = j;
									break;
								}
								else if (dayRL == dateS[count1][k][2])
								{
									check3 = true;
									count2 = j;
									break;
								}
							}
							if (check3 == true)
								break;
						}
					}
					if (check3 == true)
						break;
				}
			}
			sum1 = moneyS[count1];
			sum2 = moneyS[count1];
			for (int i = countBillS[count1] - 1; i >= count2; i--)
			{
				if (signS[count1][i] == "+")
				{
					sum1 -= billS[count1][i];
					sum2 += sum1;
				}
				else if (signS[count1][i] == "-")
				{
					sum1 += billS[count1][i];
					sum2 += sum1;
				}
			}
			result = sum2 / countBillS[count1] - count2;
			gotoxy(13, 18);
			cout << "You can have   " << result << "   as Loan.";
			_getch();
		}
		else
		{
			gotoxy(13, 20);
			cout << "You enter a wrong password try again.";
			_getch();
			goto labelcls;
		}
	}
}
