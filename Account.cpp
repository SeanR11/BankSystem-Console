#include "Account.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define underline "\033[4m"
#define stopUnderline "\033[0m"
#define ENTER 13

Account::Account(string ID) {

	path = "Accounts/" + ID + "/accountInfo.dll";
	ifstream file(path);
	ifstream file2("Accounts/" + ID + "/details.dll");
	balance = stof(getLine(file, 10).c_str());
	oldBalance = getLine(file, 10).c_str();
	pinCode = atoi(getLine(file, 8).c_str());
	name = getLine(file2, 3);
	tempID = ID;
}

void Account::deposite() {

	int selection = 1;
	Color(7);
	Box(64 / 2 - 14, 30 / 2 - 3, 28, 7, FALSE);
	Color(6); Pos(64 / 2 - 11, 30 / 2 - 2); cout << "Deposite amount: ";
	Color(7); Pos(64 / 2 - 11, 30 / 2); cout << "Current balance: "; if (balance > 0) Color(2); else if (balance == 0) Color(3); else Color(4); cout << balance; Color(7);
	Pos(64 / 2 - 5, 30 / 2 + 2); cout << "Deposite";
	Pos(64 / 2 - 5, 30 / 2 + 3); cout << "Cancel";
	while (1) {

		kbInput = _getch();

		if (kbInput == DOWN && selection != 3)
			selection++;
		else if (kbInput == UP && selection != 1)
			selection--;
		if (kbInput == ENTER) {
			if (selection == 1) {
				Color(7); Pos(64 / 2 - 11, 30 / 2 - 2); cout << "Deposite amount:         ";
				Color(6); Pos(64 / 2 - 11 + 17, 30 / 2 - 2); cin >> amount;
				Color(7); Pos(64 / 2 - 11, 30 / 2 - 2); cout << "Deposite amount: ";
			}
			else if (selection == 2) {
				balance += amount;
				Box(64 / 2 - 10, 30 / 2 - 2, 20, 5, FALSE);
				Color(3); Pos(64 / 2 - 8, 30 / 2); cout << "Balance updated!";
				Sleep(1500);
				amount = 0;
				deposite();
				break;
			}
			else if (selection == 3) {
				system("cls");
				if (oldBalance != to_string(balance))
					replace(path, oldBalance, to_string(balance));
				break;
			}
		}
		if (selection == 1) {
			Color(6); Pos(64 / 2 - 11, 30 / 2 - 2); cout << "Deposite amount: ";
			Color(7); Pos(64 / 2 - 5, 30 / 2 + 2); cout << "Deposite";
		}
		else if (selection == 2) {
			Color(7); Pos(64 / 2 - 11, 30 / 2 - 2); cout << "Deposite amount: ";
			Color(6); Pos(64 / 2 - 5, 30 / 2 + 2); cout << "Deposite";
			Color(7); Pos(64 / 2 - 5, 30 / 2 + 3); cout << "Cancel";
		}
		else if (selection == 3) {
			Color(7); Pos(64 / 2 - 5, 30 / 2 + 2); cout << "Deposite";
			Color(6); Pos(64 / 2 - 5, 30 / 2 + 3); cout << "Cancel";
		}
	}

}

void Account::withdraw() {
	int selection = 1;
		Color(7);
		Box(64 / 2 - 14, 30 / 2 - 3, 28, 7, FALSE);
		Color(6); Pos(64 / 2 - 12, 30 / 2 - 2); cout << "Withdrawal amount: ";
		Color(7); Pos(64 / 2 - 12, 30 / 2); cout << "Current balance: "; if (balance > 0) Color(2); else if (balance == 0) Color(3); else Color(4); cout << balance; Color(7);
		Pos(64 / 2 - 5, 30 / 2 + 2); cout << "Withdrawal";
	Pos(64 / 2 - 5, 30 / 2 + 3); cout << "Cancel";
	while (1) {

		kbInput = _getch();

		if (kbInput == DOWN && selection != 3)
			selection++;
		else if (kbInput == UP && selection != 1)
			selection--;
		if (kbInput == ENTER) {
			if (selection == 1) {
				Color(7); Pos(64 / 2 - 12, 30 / 2 - 2); cout << "Withdrawal amount:        ";
				Color(6); Pos(64 / 2 - 12 + 18, 30 / 2 - 2); cin >> amount;
				Color(7); Pos(64 / 2 - 12, 30 / 2 - 2); cout << "Withdrawal amount:";
			}
			else if (selection == 2) {
				if ((balance + (amount*-1)) < -1000) {
					Box(64 / 2 - 10, 30 / 2 - 2, 20, 5, FALSE);
					Color(4); Pos(64 / 2 - 9, 30 / 2 + 0.5); cout << "insufficient fund!"; 
					Sleep(1500);
					withdraw();
					break;
				}
				balance -= amount;
				Box(64 / 2 - 10, 30 / 2 - 2, 20, 5, FALSE);
				Color(3); Pos(64 / 2 - 8, 30 / 2); cout << "Balance updated!";
				Sleep(1500);
				amount = 0;
				withdraw();
				break;
			}
			else if (selection == 3) {
				system("cls");
				if (oldBalance != to_string(balance))
					replace(path, oldBalance, to_string(balance));
				break;
			}
		}
		if (selection == 1) {
			Color(6); Pos(64 / 2 - 12, 30 / 2 - 2); cout << "Withdrawal amount:";
			Color(7); Pos(64 / 2 - 5, 30 / 2 + 2); cout << "Withdrawal";
		}
		else if (selection == 2) {
			Color(7); Pos(64 / 2 - 12, 30 / 2 - 2); cout << "Withdrawal amount:";
			Color(6); Pos(64 / 2 - 5, 30 / 2 + 2); cout << "Withdrawal";
			Color(7); Pos(64 / 2 - 5, 30 / 2 + 3); cout << "Cancel";
		}
		else if (selection == 3) {
			Color(7); Pos(64 / 2 - 5, 30 / 2 + 2); cout << "Withdrawal";
			Color(6); Pos(64 / 2 - 5, 30 / 2 + 3); cout << "Cancel";
		}
	}

}
void Account::checkBalance() {
	
	system("cls");

	Color(7);
	Box(64 / 2 - 14, 30 / 2 - 3, 28, 7, FALSE);
	Color(7); Pos(64 / 2 - 6, 30 / 2 - 2); cout << "Welcome " + name;
	Pos(64 / 2 - 12, 30 / 2); cout << "Current balance: "; if (balance > 0) Color(2); else if (balance == 0) Color(3); else Color(4); cout << balance; Color(7);
	Pos(64 / 2 - 2, 30 / 2 + 3); cout << "1.Back";
	while (1) {
		kbInput = _getch();
		if (kbInput == 49) {
			break;
		}
	}


}

void Account::transfer() {

	system("cls");
	Color(7);

	int x = 64 / 2, y = 30 / 2 - 2;
	int selection = 1;
	string cName, cAccNum, cBankNum, cPin, cID;

	Box(x - 15, y - 5, 30, 14, TRUE);
	Pos(x - 8, y - 4); cout << "\033[4m" << "Money Transfer:";
	Pos(x - 8, y - 2); cout << "Reciver info:" << stopUnderline;
	Color(6); Pos(x - 13, y - 1); cout << "Full name:";
	Color(7); Pos(x - 13, y); cout << "Account number:";
	Pos(x - 13, y + 1); cout << "Bank number:";
	Pos(x - 13, y + 2); cout << "ID:";
	Pos(x - 13, y + 3); cout << "Amount:";
	Pos(x - 8, y + 5); cout << underline << "Your'e info:" << stopUnderline;
	Pos(x - 13, y + 6); cout << "Pin Code:";
	Pos(x - 10, y + 7); cout << "Send";
	Pos(x + 7, y + 7); cout << "Cancel";

	while (1) {

		kbInput = _getch();
		if (kbInput == DOWN) {
			if (selection != 7 && selection != 8)
				selection++;
		}
		else if (kbInput == UP) {
			if (selection != 1 && selection != 8)
				selection--;
			else if (selection == 8)
				selection = 6;
		}
		else if (kbInput == RIGHT && selection == 7)
			selection = 8;
		else if (kbInput == LEFT && selection == 8)
			selection = 7;
		else if (kbInput == ENTER) {
			if (selection == 1) {
				Color(7); Pos(x - 13, y - 1); cout << "Full name:                  ";
				Color(6); Pos(x - 13 + 11, y - 1); getline(cin, cName);
				Color(7); Pos(x - 13 + 11, y - 1); cout << cName;
				Color(6); Pos(x - 13, y - 1); cout << "Full name:";
			}
			else if (selection == 2) {
				Color(7); Pos(x - 13, y); cout << "Account number:             ";
				Color(6); Pos(x - 13 + 16, y); cin >> cAccNum;
				Color(7); Pos(x - 13 + 16, y); cout << cAccNum;
				Color(6); Pos(x - 13, y); cout << "Account number:";
			}
			else if (selection == 3) {
				Color(7); Pos(x - 13, y + 1); cout << "Bank number:              ";
				Color(6); Pos(x - 13 + 13, y + 1); cin >> cBankNum;
				Color(7); Pos(x - 13 + 13, y + 1); cout << cBankNum;
				Color(6); Pos(x - 13, y + 1); cout << "Bank number:";
			}
			else if (selection == 4) {
				Color(7); Pos(x - 13, y + 2); cout << "ID:                      ";
				Color(6); Pos(x - 13 + 4, y + 2); cin >> cID;
				Color(7); Pos(x - 13 + 4, y + 2); cout << cID;
				Color(6); Pos(x - 13, y + 2); cout << "ID:";
			}
			else if (selection == 5) {
				Color(7); Pos(x - 13, y + 3); cout << "Amount:                   ";
				Color(6); Pos(x - 13 + 8, y + 3); cin >> amount;
				Color(7); Pos(x - 13 + 8, y + 3); cout << amount;
				Color(6); Pos(x - 13, y + 3); cout << "Amount:";
			}
			else if (selection == 6) {
				Color(7); Pos(x - 13, y + 6); cout << "Pin Code:              ";
				Color(6); Pos(x - 13 + 10, y + 6); cin >> cPin;
				Color(7); Pos(x - 13 + 10, y + 6); cout << cPin;
				Color(6); Pos(x - 13, y + 6); cout << "Pin Code:";
			}
			else if (selection == 7) {
				ifstream reciver("Accounts/" + cID + "/accountInfo.dll");
				ifstream recivern("Accounts/" + cID + "/details.dll");
				ifstream sender("Accounts/" + tempID + "/accountInfo.dll");
				string path2 = "Accounts/" + cID + "/accountInfo.dll";
				string path3 = "Accounts/" + tempID + "/accountInfo.dll";
				if (!reciver || !recivern) {
					Box(64 / 2 - 14, 30 / 2 - 2, 28, 5, FALSE);
					Color(3); Pos(64 / 2 - 10, 30 / 2); cout << "Wrong reciver details";
					system("cls");
					cout << !reciver << endl << !recivern;
					Sleep(1500);
					transfer();
					break;
				}
				if (cName == getLine(recivern, 3) + " " + getLine(recivern, 6) && cAccNum == getLine(reciver, 3) &&
					cBankNum == getLine(reciver, 6) && cPin == to_string(pinCode) && amount > 0) {
					string temp = getLine(sender, 10);
					if (amount < stof(temp)) {
						float temp1 = stof(temp) - amount;
						string tempBalance = to_string(temp1);
						replace(path3, temp, tempBalance);
						temp = getLine(reciver, 10);
						temp1 = stof(temp) + amount;
						tempBalance = to_string(temp1);
						replace(path2, temp, tempBalance);
						Box(64 / 2 - 14, 30 / 2 - 2, 28, 5, FALSE);
						Color(3); Pos(64 / 2 - 10, 30 / 2); cout << "Transfer successed!";
						Sleep(1500);
						transfer();
						break;
					}
					else {
						Box(64 / 2 - 14, 30 / 2 - 2, 28, 5, FALSE);
						Color(4); Pos(64 / 2 - 10, 30 / 2); cout << "insufficient fund!";
						Sleep(1500);
						transfer();
						break;
					}

				}
				else {
					Box(64 / 2 - 14, 30 / 2 - 2, 28, 5, FALSE);
					Color(3); Pos(64 / 2 - 10, 30 / 2); cout << "Wrong pin code";
					Sleep(1500);
					transfer();
					break;
				}
			}



			else if (selection == 8) {
				break;
			}
		}


		if (selection == 1) {
			Color(6); Pos(x - 13, y - 1); cout << "Full name:";
			Color(7); Pos(x - 13, y); cout << "Account number:";
		}
		else if (selection == 2) {
			Color(7); Pos(x - 13, y - 1); cout << "Full name:";
			Color(6); Pos(x - 13, y); cout << "Account number:";
			Color(7); Pos(x - 13, y + 1); cout << "Bank number:";
		}
		else if (selection == 3) {
			Color(7); Pos(x - 13, y); cout << "Account number:";
			Color(6); Pos(x - 13, y + 1); cout << "Bank number:";
			Color(7); Pos(x - 13, y + 2); cout << "ID:";
		}
		else if (selection == 4) {
			Color(7); Pos(x - 13, y + 1); cout << "Bank number:";
			Color(6); Pos(x - 13, y + 2); cout << "ID:";
			Color(7); Pos(x - 13, y + 3); cout << "Amount:";
		}
		else if (selection == 5) {
			Color(7); Pos(x - 13, y + 2); cout << "ID:";
			Color(6); Pos(x - 13, y + 3); cout << "Amount:";
			Color(7); Pos(x - 13, y + 6); cout << "Pin Code:";
		}
		else if (selection == 6) {
			Color(7); Pos(x - 13, y + 3); cout << "Amount:";
			Color(6); Pos(x - 13, y + 6); cout << "Pin Code:";
			Color(7); Pos(x - 10, y + 7); cout << "Send";
			Color(7); Pos(x + 7, y + 7); cout << "Cancel";
		}
		else if (selection == 7) {
			Color(7); Pos(x - 13, y + 6); cout << "Pin Code:";
			Color(6); Pos(x - 10, y + 7); cout << "Send";
			Color(7); Pos(x + 7, y + 7); cout << "Cancel";
		}
		else if (selection == 8) {
			Color(7); Pos(x - 10, y + 7); cout << "Send";
			Color(6); Pos(x + 7, y + 7); cout << "Cancel";
		}
		Pos(0, 0); cout << selection;
	}
}

void Account::info() {

	string tPin;
	Box(64 / 2 - 16, 30 / 2 - 2, 32, 6, FALSE);
	Color(4); Pos(64 / 2 - 7, 30 / 2 +1); cout << "Pin code:"; cin >> tPin;
	if (atoi(tPin.c_str()) == pinCode) {



		Color(7);
		system("cls");
		ifstream account("Accounts/" + tempID + "/accountInfo.dll");
		ifstream details("Accounts/" + tempID + "/details.dll");

		int x = 64 / 2 - 4, y = 30 / 2;

		string owner = getLine(details,3)+" "+getLine(details,6), tAccNum = getLine(account,3), tBankNum = getLine(account,6), 
			birthDay = getLine(details,10)+"."+getLine(details,11)+"."+getLine(details,12), tPass = getLine(details,23);
		Box(x - 15, y - 5, 34, 14, TRUE);
		Pos(x - 7, y - 4); cout << "\033[4m" << "Account information:" << stopUnderline;
		Pos(x - 13, y - 2); cout << "Account owner:" << owner;
		Pos(x - 13, y - 1); cout << "Account number:" << tAccNum;
		Pos(x - 13, y); cout << "Bank number:" << tBankNum;
		Pos(x - 13, y + 1); cout << "Pin code:" << tPin;
		Pos(x - 13, y + 2); cout << "Password:" << tPass;
		Pos(x - 13, y + 3); cout << "Birthday:" << birthDay;
		Pos(x -2, y + 6); cout << "1.Back";

		while (1) {
			kbInput = _getch();
			if (kbInput == 49)
				break;
		}
	}
	
}
void Account::settings() {

	string tPin;
	Box(64 / 2 - 16, 30 / 2 - 2, 32, 6, FALSE);
	Color(4); Pos(64 / 2 - 7, 30 / 2 + 1); cout << "Pin code:"; cin >> tPin;
	if (atoi(tPin.c_str()) == pinCode) {

	start:
		Color(7);
		system("cls");

		int x = 64 / 2, y = 30 / 2;
		int subject = 1;
		int selected = 1;
		string oldPass, newPass, newPass2;

		Box(x - 15, y - 5, 34, 10, TRUE);
		Pos(x - 4, y - 4); cout << "\033[4m" << "Change info:" << stopUnderline;
		Color(6); Pos(x - 14, y); cout << "Choose subject(Arrows):"; 
		Color(7); Pos(x - 14 + 23, y); cout << " Password ";
		Pos(x , y + 4); cout << "Back";

		while (1) {
			kbInput = _getch();

			if (kbInput == RIGHT && subject != 5)
				subject++;
			else if (kbInput == LEFT && subject != 1)
				subject--;
			else if (kbInput == DOWN && selected != 2)
				selected++;
			else if (kbInput == UP && selected != 1)
				selected--;
			else if (kbInput == ENTER) {
				if (selected == 1 &&subject == 1) {
					mid:
					int selection = 1;
					
					Box(64 / 2 - 14, 30 / 2 - 3, 32, 7, FALSE);
					Color(6); Pos(64 / 2 - 13, 30 / 2 -1); cout << "Old password:";
					Color(7); Pos(64 / 2 - 13, 30 / 2 ); cout << "New password:";
					Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Re new password:";
					Pos(64 / 2 - 8, 30 / 2 + 3); cout << "Apply";
					Pos(64 / 2 +2, 30 / 2 + 3); cout << "Cancel";

					while (1) {
						kbInput = _getch();

						if (kbInput == DOWN && selection != 4 && selection != 5)
							selection++;
						else if (kbInput == UP && selection != 1)
							selection--;
						else if (kbInput == UP && selection == 6)
							selection = 4;
						else if (kbInput == RIGHT && selection == 4)
							selection = 5;
						else if (kbInput == LEFT && selection == 5)
							selection = 4;
						else if (kbInput == ENTER) {
							if (selection == 1) {
								Color(7); Pos(64 / 2 - 13, 30 / 2 - 1); cout << "Old password:              ";
								Color(6); Pos(64 / 2 - 13 + 14, 30 / 2 - 1); cin >> oldPass;
								Color(7); Pos(64 / 2 - 13 + 14, 30 / 2 - 1); cout << oldPass;
								Color(6); Pos(64 / 2 - 13, 30 / 2 - 1); cout << "Old password:";
							}
							else if (selection == 2) {
								Color(7); Pos(64 / 2 - 13 ,30 / 2); cout << "New password:              ";
								Color(6);  Pos(64 / 2- 13 + 14, 30 / 2); cin >> newPass;
								Color(7); Pos(64 / 2- 13 + 14, 30 / 2); cout << newPass;
								Color(6); Pos(64 / 2 - 13, 30 / 2); cout << "New password:";
							}
							else if (selection == 3) {
								Color(7); Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Re new password:              ";
								Color(6);  Pos(64 / 2 -13 + 17, 30 / 2 + 1); cin >> newPass2;
								Color(7); Pos(64 / 2-13 + 17, 30 / 2 + 1); cout << newPass2;
								Color(6); Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Re new password:";
							}
							else if (selection == 4) {
								ifstream file("Accounts/" + tempID + "/details.dll");
								if (newPass == newPass2 && oldPass == getLine(file, 23)) {

									string path1 = "Accounts/" + tempID + "/details.dll";
									replace(path1, oldPass, newPass);
									Box(64 / 2 - 14, 30 / 2 - 2, 30, 6, FALSE);
									Color(3); Pos(64 / 2 - 8, 30 / 2+1); cout << "Password changed!"; 
									Sleep(2000);
									Color(7);
									goto start;
									break;
								}
								else if (oldPass != getLine(file, 23)) {
									Box(64 / 2 - 13, 30 / 2 - 2, 28, 5, FALSE);
									Color(3); Pos(64 / 2 - 6, 30 / 2); cout << "Wrong password!";
									Sleep(1500);
									Color(7);
									Box(64 / 2 - 14, 30 / 2 - 3, 32, 7, FALSE);
									goto mid;
									break;
								}
								else if (newPass != newPass2) {
									Box(64 / 2 - 13, 30 / 2 - 2, 28, 5, FALSE);
									Color(3); Pos(64 / 2 - 8, 30 / 2); cout << "Password isn't Match!"; Color(7);
									Sleep(1500);
									Box(64 / 2 - 14, 30 / 2 - 3, 32, 7, FALSE);
									goto mid;
									break;
								}
							}
							else if (selection == 5) {
								goto start;
								break;
							}
						}

							

						if (selection == 1) {
							Color(6); Pos(64 / 2 - 13, 30 / 2 - 1); cout << "Old password:";
							Color(7); Pos(64 / 2 - 13, 30 / 2 ); cout << "New password:";
						}
						else if (selection == 2) {
							Color(7); Pos(64 / 2 - 13, 30 / 2 - 1); cout << "Old password:";
							Color(6); Pos(64 / 2 - 13, 30 / 2); cout << "New password:";
							Color(7); Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Re new password:";
						}
						else if (selection == 3) {
							Color(7); Pos(64 / 2 - 13, 30 / 2 ); cout << "New password:";
							Color(6); Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Re new password:";
							Color(7); Pos(64 / 2 - 8, 30 / 2 + 3); cout << "Apply";
							Color(7); Pos(64 / 2 + 2, 30 / 2 + 3); cout << "Cancel";
						}
						else if (selection == 4) {
							Color(7); Pos(64 / 2 - 13, 30 / 2 + 1); cout << "Re new password:";
							Color(6); Pos(64 / 2 - 8, 30 / 2 + 3); cout << "Apply";
							Color(7); Pos(64 / 2 + 2, 30 / 2 + 3); cout << "Cancel";
						}
						else if (selection == 5) {
							Color(7); Pos(64 / 2 - 8, 30 / 2 + 3); cout << "Apply";
							Color(6); Pos(64 / 2 + 2, 30 / 2 + 3); cout << "Cancel";
						}
					}
				}
				if (selected == 1 && subject == 2) {
					Box(64 / 2 - 18, 30 / 2 - 3, 40, 5, FALSE);
					string path1 = "Accounts/" + tempID + "/accountInfo.dll";
					ifstream file(path1);
					string tempPin = getLine(file, 8);
					int tPin;
					Color(3); Pos(64 / 2 - 9, 30 / 2 - 1); cout << "New Pin code created!";
					cout << "1";
					tPin = random(1000, 9999);
					Color(4); Pos(64 / 2 - 4, 30 / 2); cout << "New pin: " << tPin; Color(7);
					replace(path1, tempPin, to_string(tPin));
					Sleep(2000);
					goto start;
					break;
				}
				else if (selected == 2) {
				break;
}
			}
			


			if (subject == 1) {
				Color(7); Pos(x - 14 + 23, y); cout << " Password ";
			}
			else if (subject == 2) {
				Color(7); Pos(x - 14 + 23, y); cout << " Pin Code ";
			}

			if (selected == 1) {
				Color(6); Pos(x - 14, y); cout << "Choose subject(Arrows):";
				Color(7); Pos(x , y + 4); cout << "Back";
			}
			else if (selected == 2) {
				Color(7); Pos(x - 14, y); cout << "Choose subject(Arrows):";
				Color(6); Pos(x , y + 4); cout << "Back";
			}
		}
	}
	
}