#include "Bank.h"
#include "Account.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include <ctime>
#include <chrono>


using namespace std;

#define underline "\033[4m"
#define stopUnderline "\033[0m"
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

void menu();
void createAccount();
void login();
void bank(string ID);

int main() {

	system("cls");

	setWindow(64, 30, 600, 600, FALSE);
	Box(64 / 2 - 15, 30 / 2 - 5, 30, 10, FALSE);

	menu();

	return 0;
}

void menu() {

	int kbInput;

	system("cls");

	//bank("318517433");
	Box(64 / 2 - 15, 30 / 2 - 5, 30, 10, TRUE);
	Pos(64 / 2 - 11, 30 / 2 - 3); cout << underline << "Welcome to Bank Yahav:" << stopUnderline;
	Pos(64 / 2 - 7, 30 / 2 - 1); cout << "1.New Account";
	Pos(64 / 2 - 7, 30 / 2 + 1); cout << "2.Login";
	Pos(64 / 2 - 7, 30 / 2 + 3); cout << "3.Exit";

	while (1) {
		kbInput = _getch();

		if (kbInput == 49)
			createAccount();
		else if (kbInput == 50)
			login();
		else if (kbInput == 51)
			PostMessage(GetConsoleWindow(), WM_CLOSE, 0, 0);
	}
}
void createAccount() {

	string fName, lName, phoneNum, ID, bDay, bMonth, bYear, eMail, addressStreet, adressApp;
	int kbInput, selection = 1, pinCode;

	system("cls");

	Box(64 / 2 - 15, 2, 30, 25, TRUE);
	Pos(64 / 2 - 10, 30 / 2 - 12); cout << underline << "Create neww account:" << stopUnderline;
	Color(6);	Pos(64 / 2 - 13, 30 / 2 - 10); cout << "First name:";
	Color(7); Pos(64 / 2 - 13, 30 / 2 - 8); cout << "Last name:";
	Pos(64 / 2 - 13, 30 / 2 - 6); cout << "ID:";
	Pos(64 / 2 - 13, 30 / 2 - 4); cout << underline << "Birthday details:" << stopUnderline;
	Pos(64 / 2 - 13, 30 / 2 - 3); cout << "Day:";
	Pos(64 / 2 - 13, 30 / 2 - 2); cout << "Month:";
	Pos(64 / 2 - 13, 30 / 2 - 1); cout << "Year:";
	Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Phone Number:";
	Pos(64 / 2 - 13, 30 / 2 + 3); cout << "Address Street:";
	Pos(64 / 2 - 13, 30 / 2 + 5); cout << "Address Appartment:";
	Pos(64 / 2 - 13, 30 / 2 + 7); cout << "EMAIL:";
	Pos(64 / 2 - 7, 30 / 2 + 10); cout << "1.Send";
	Pos(64 / 2 + 3, 30 / 2 + 10); cout << "2.Cancel";

	while (1) {
		kbInput = _getch();

		if (kbInput == DOWN && selection != 10)
			selection++;
		else if (kbInput == UP && selection != 1)
			selection--;
		if (kbInput == ENTER) {
			if (selection == 1) {
				do {
					Color(7); Pos(64 / 2 - 13, 30 / 2 - 10); cout << "First name:            "; Color(6);
					Pos(64 / 2 - 13 + 11, 30 / 2 - 10);
					cin >> fName;
				} while (fName.length() > 8 || fName.length() <= 1);
				Color(7); 	Pos(64 / 2 - 13 + 11, 30 / 2 - 10); cout << fName;
				Color(6); Pos(64 / 2 - 13, 30 / 2 - 10); cout << "First name:";
			}
			else if (selection == 2) {
				do {
					Color(7); Pos(64 / 2 - 13, 30 / 2 - 8); cout << "Last name:          "; Color(6);
					Pos(64 / 2 - 13 + 11, 30 / 2 - 8);
					cin >> lName;
				} while (lName.length() > 8 || lName.length() < 1);
				Color(7); Pos(64 / 2 - 13 + 11, 30 / 2 - 8); cout << lName;
				Color(6); Pos(64 / 2 - 13, 30 / 2 - 8); cout << "Last name:";
			}
			else if (selection == 3) {
				do {
					Color(7);	Pos(64 / 2 - 13, 30 / 2 - 6); cout << "ID:             "; Color(6);
					Pos(64 / 2 - 13 + 5, 30 / 2 - 6);
					cin >> ID;
				} while (ID.length() < 8);
				Color(7); Pos(64 / 2 - 13 + 5, 30 / 2 - 6); cout << ID;
				Color(6); Pos(64 / 2 - 13, 30 / 2 - 6); cout << "ID:";
			}
			else if (selection == 4) {
				do {
					Color(7);	Pos(64 / 2 - 13, 30 / 2 - 3); cout << "Day:          "; Color(6);
					Pos(64 / 2 - 13 + 5, 30 / 2 - 3);
					cin >> bDay;
				} while (bDay.length() > 3 || bDay.length() < 1);
				Color(7); Pos(64 / 2 - 13 + 5, 30 / 2 - 3); cout << bDay;
				Color(6); Pos(64 / 2 - 13, 30 / 2 - 3); cout << "Day:";
			}
			else if (selection == 5) {
				do {
					Color(7);	Pos(64 / 2 - 13, 30 / 2 - 2); cout << "Month:          "; Color(6);
					Pos(64 / 2 - 13 + 7, 30 / 2 - 2);
					cin >> bMonth;
				} while (bMonth.length() > 3 || bMonth.length() < 1);
				Color(7); Pos(64 / 2 - 13 + 7, 30 / 2 - 2); cout << bMonth;
				Color(6);	Pos(64 / 2 - 13, 30 / 2 - 2); cout << "Month:";
			}
			else if (selection == 6) {
				do {
					Color(7);	Pos(64 / 2 - 13, 30 / 2 - 1); cout << "Year:           "; Color(6);
					Pos(64 / 2 - 13 + 6, 30 / 2 - 1);
					cin >> bYear;
				} while (bYear.length() > 5 || bYear.length() < 3);
				Color(7); Pos(64 / 2 - 13 + 6, 30 / 2 - 1); cout << bYear;
				Color(6);	Pos(64 / 2 - 13, 30 / 2 - 1); cout << "Year:";
			}
			else if (selection == 7) {
				do {
					Color(7);	Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Phone Number:              "; Color(6);
					Pos(64 / 2 - 13 + 14, 30 / 2 + 1);
					cin >> phoneNum;
				} while (phoneNum.length() > 11 || phoneNum.length() < 9);
				Color(7); Pos(64 / 2 - 13 + 14, 30 / 2 + 1); cout << phoneNum;
				Color(6);	Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Phone Number:";
			}
			else if (selection == 8) {
				do {
					Color(7);	Pos(64 / 2 - 13, 30 / 2 + 3); cout << "Address Street:             "; Color(6);
					Pos(64 / 2 - 13 + 16, 30 / 2 + 3);
					getline(cin, addressStreet);
				} while (addressStreet.length() > 12 || addressStreet.length() < 1);
				Color(7); Pos(64 / 2 - 13 + 16, 30 / 2 + 3); cout << addressStreet;
				Color(6);	Pos(64 / 2 - 13, 30 / 2 + 3); cout << "Address Street:";
			}
			else if (selection == 9) {
				do {
					Color(7);	Pos(64 / 2 - 13, 30 / 2 + 5); cout << "Address Appartment:      "; Color(6);
					Pos(64 / 2 - 13 + 20, 30 / 2 + 5);
					cin >> adressApp;
				} while (adressApp.length() > 5 || adressApp.length() < 1);
				Color(7); Pos(64 / 2 - 13 + 20, 30 / 2 + 5); cout << adressApp;
				Color(6);	Pos(64 / 2 - 13, 30 / 2 + 5); cout << "Address Appartment:";
			}
			else if (selection == 10) {
				do {
					Color(7);	Pos(64 / 2 - 13, 30 / 2 + 7); cout << "EMAIL:                      "; Color(6);
					Pos(64 / 2 - 13 + 7, 30 / 2 + 7);
					cin >> eMail;
				} while (eMail.length() < 8);
				Color(7); Pos(64 / 2 - 13 + 7, 30 / 2 + 7); cout << eMail;
				Color(6);	Pos(64 / 2 - 13, 30 / 2 + 7); cout << "EMAIL:";
			}
		}
		if (kbInput == 49) {
			Color(7);
			const string& folder = "Accounts/" + ID;
			DWORD tempFolder = GetFileAttributesA(folder.c_str());

			if (tempFolder == FILE_ATTRIBUTE_DIRECTORY) {
				Box(64 / 2 - 14, 30 / 2 - 5, 28, 10, FALSE);
				Pos(64 / 2 - 7, 30 / 2); cout << "Account exists!";
				_getch();
				createAccount();

			}
			else if (tempFolder == INVALID_FILE_ATTRIBUTES) {
				_mkdir(folder.c_str());
				string temp = "Accounts/" + ID + "/details.dll";
				ofstream file(temp);
				ofstream file2("Accounts/" + ID + "/accountInfo.dll");
				file << "First name:" << endl << fName << endl;
				file << "Last name:" << endl << lName << endl;
				file << "ID:" << endl << ID << endl;
				file << "Birthday:" << endl << bDay << endl << bMonth << endl << bYear << endl;
				file << "Phone Number:" << endl << phoneNum << endl;
				file << "Address:" << endl << addressStreet << endl << adressApp << endl;
				file << "Email:" << endl << eMail << endl;
				file << "Password:" << endl << bDay+bMonth+bYear;
				file.close();
				file2 << "Account number:" << endl << random(100000, 999999) << endl;
				file2 << "Bank number:" << endl << random(1,100) << endl;
				pinCode = random(1000, 9999);
				file2 << "pinCode:" << endl << pinCode << endl;
				file2 << "Balance:" << endl << "0" << endl;
				file2.close();
				Box(64 / 2 - 14, 30 / 2 - 5, 28, 10, FALSE);
				Pos(64 / 2 - 7, 30 / 2 ); cout << "Account created!";
				Pos(64 / 2 - 7, 30 / 2 + 1); cout << "Pin code:" << pinCode;
				_getch();
				file.close();
				menu();
			}

		}
		else if (kbInput == 50)
			menu();

		if (selection == 1) {
			Color(6); Pos(64 / 2 - 13, 30 / 2 - 10); cout << "First name:";
			Color(7); Pos(64 / 2 - 13, 30 / 2 - 8); cout << "Last name:";
		}
		else if (selection == 2) {
			Color(7);	Pos(64 / 2 - 13, 30 / 2 - 10); cout << "First name:";
			Color(6); Pos(64 / 2 - 13, 30 / 2 - 8); cout << "Last name:";
			Color(7); Pos(64 / 2 - 13, 30 / 2 - 6); cout << "ID:";
		}
		else if (selection == 3) {
			Color(7); Pos(64 / 2 - 13, 30 / 2 - 8); cout << "Last name:";
			Color(6); Pos(64 / 2 - 13, 30 / 2 - 6); cout << "ID:";
			Color(7); Pos(64 / 2 - 13, 30 / 2 - 3); cout << "Day:";
		}
		else if (selection == 4) {
			Color(7); Pos(64 / 2 - 13, 30 / 2 - 6); cout << "ID:";
			Color(6); Pos(64 / 2 - 13, 30 / 2 - 3); cout << "Day:";
			Color(7); Pos(64 / 2 - 13, 30 / 2 - 2); cout << "Month:";
		}
		else if (selection == 5) {
			Color(7); Pos(64 / 2 - 13, 30 / 2 - 3); cout << "Day:";
			Color(6); Pos(64 / 2 - 13, 30 / 2 - 2); cout << "Month:";
			Color(7); Pos(64 / 2 - 13, 30 / 2 - 1); cout << "Year:";
		}
		else if (selection == 6) {
			Color(7); Pos(64 / 2 - 13, 30 / 2 - 2); cout << "Month:";
			Color(6); Pos(64 / 2 - 13, 30 / 2 - 1); cout << "Year:";
			Color(7); Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Phone Number:";
		}
		else if (selection == 7) {
			Color(7); Pos(64 / 2 - 13, 30 / 2 - 1); cout << "Year:";
			Color(6); Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Phone Number:";
			Color(7); Pos(64 / 2 - 13, 30 / 2 + 3); cout << "Address Street:";
		}
		else if (selection == 8) {
			Color(7); Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Phone Number:";
			Color(6); Pos(64 / 2 - 13, 30 / 2 + 3); cout << "Address Street:";
			Color(7); Pos(64 / 2 - 13, 30 / 2 + 5); cout << "Address Appartment:";
		}
		else if (selection == 9) {
			Color(7); Pos(64 / 2 - 13, 30 / 2 + 3); cout << "Address Street:";
			Color(6); Pos(64 / 2 - 13, 30 / 2 + 5); cout << "Address Appartment:";
			Color(7); Pos(64 / 2 - 13, 30 / 2 + 7); cout << "EMAIL:";
		}
		else if (selection == 10) {
			Color(7); Pos(64 / 2 - 13, 30 / 2 + 5); cout << "Address Appartment:";
			Color(6); Pos(64 / 2 - 13, 30 / 2 + 7); cout << "EMAIL:";
		}
	}
}
void login() {

	int kbInput, selection = 1;
	string tempID, tempPassword, ID, pass;
	ifstream file;
	system("cls");

	Box(64 / 2 - 15, 30 / 2 - 5, 30, 10, TRUE);
	Pos(64 / 2 - 3, 30 / 2 - 3); cout << underline << "Login:" << stopUnderline;
	Color(6); Pos(64 / 2 - 7, 30 / 2 - 1); cout << "ID:";
	Color(7); Pos(64 / 2 - 7, 30 / 2 + 1); cout << "Password:";
	Pos(64 / 2 - 10, 30 / 2 + 3); cout << "1.Login";
	Pos(64 / 2 + 3, 30 / 2 + 3); cout << "2.Back";
	Color(4); Pos(64 / 2 - 17, 30 / 2 + 6); cout << "*first login password is birthday*";

	while (1) {

		kbInput = _getch();

		if (kbInput == DOWN)
			selection = 2;
		else if (kbInput == UP)
			selection = 1;
		else if (kbInput == ENTER) {
			if (selection == 1) {
				do {
					Color(7); Pos(64 / 2 - 7, 30 / 2 - 1); cout << "ID:            "; Color(6);
					Pos(64 / 2 - 7 + 4, 30 / 2 - 1); cin >> ID;
				} while (ID.length() <= 8);
				Color(7); Pos(64 / 2 - 7 + 4, 30 / 2 - 1); cout << ID;
				Color(6); Pos(64 / 2 - 7, 30 / 2 - 1); cout << "ID:";
			}
			else if (selection == 2) {
				do {
					Color(7); Pos(64 / 2 - 7, 30 / 2 + 1);  cout << "Password:          "; Color(6);
					Pos(64 / 2 - 7 + 10, 30 / 2 + 1);  cin >> pass;
				} while (pass.length() > 8);
				Color(7); Pos(64 / 2 - 7 + 10, 30 / 2 + 1);  cout << pass;
				Color(6); Pos(64 / 2 - 7, 30 / 2 + 1);  cout << "Password:";
			}
		}
		else if (kbInput == 49) {
			Color(7);
			file.open("Accounts/" + ID + "/details.dll");
			if (!file) {
				Box(64 / 2 - 16, 30 / 2 - 5, 32, 10, FALSE);
				Pos(64 / 2 - 10, 30 / 2); cout << "Account doesnt exists!";
				_getch();
				file.close();
				login();
			}
			else {
				tempPassword = getLine(file, 24);
				if (tempPassword == pass) {
					file.close();
					bank(ID);
					break;
				}
				else {
					Box(64 / 2 - 16, 30 / 2 - 5, 32, 10, FALSE);
					Pos(64 / 2 - 7, 30 / 2); cout << "Wrong details!";
					cout << getLine(file, 24);
					_getch();
					file.close();
					login();
				}
			}
				
		}
		else if (kbInput == 50) {
			Color(7);
			menu();
		}

		if (selection == 1) {
			Color(6); Pos(64 / 2 - 7, 30 / 2 - 1); cout << "ID:";
			Color(7); Pos(64 / 2 - 7, 30 / 2 + 1); cout << "Password:";
		}
		else if (selection == 2) {
			Color(7); Pos(64 / 2 - 7, 30 / 2 - 1); cout << "ID:";
			Color(6); Pos(64 / 2 - 7, 30 / 2 + 1); cout << "Password:";
		}
	}
}

void bank(string ID) {

	int kbInput;
	string fName, lName, fullName, accountNum, bankNum, pinCode;

	Color(7);
	system("cls");

	ifstream file("Accounts/" + ID + "/details.dll");
	fName = getLine(file, 3);
	lName = getLine(file, 6);
	fullName = fName + " " + lName;
	file.close();
	ifstream file2("Accounts/" + ID + "/accountInfo.dll");
	accountNum = getLine(file2, 2);
	bankNum = getLine(file2, 4);
	pinCode = getLine(file2, 6);
	file2.close();

	Account loggedAccount(ID);

	Box(64 / 2 - 15, 30 / 2 - 5, 30, 10, TRUE);

	Pos(64 / 2 - 14, 30 / 2 - 4); cout << "Welcome, " << fullName;
	Pos(64 / 2 - 8, 30 / 2 - 2); cout << "1.Deposite";
	Pos(64 / 2 - 8, 30 / 2 - 1); cout << "2.Withdraw";
	Pos(64 / 2 - 8, 30 / 2); cout << "3.Balance";
	Pos(64 / 2 - 8, 30 / 2 + 1); cout << "4.Money transfer";
	Pos(64 / 2 - 8, 30 / 2 + 2); cout << "5.Account info";
	Pos(64 / 2 - 8, 30 / 2 + 3); cout << "6.Change info";
	Pos(64 / 2 - 8, 30 / 2 + 4); cout << "7.Logout";

	int x = 2;
	while (1) {

		kbInput = _getch();

		switch (kbInput) {
		case 49:
			loggedAccount.deposite();
			bank(ID);
		case 50:
			loggedAccount.withdraw();
			bank(ID);
		case 51:
			loggedAccount.checkBalance();
			bank(ID);
		case 52:
			loggedAccount.transfer();
			bank(ID);
		case 53:
			loggedAccount.info();
			bank(ID);
		case 54:
			loggedAccount.settings();
			bank(ID);
		case 55:
			system("cls");
			return;
		}


	}

}