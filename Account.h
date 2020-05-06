
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <time.h>
#include <string>
using namespace std;

class Account
{
private:
	float balance;
	string oldBalance, name, tempID;
	int kbInput;
	float amount;
	int pinCode;
	string path;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	void Pos(short x, short y) {

		COORD XY{ x , y };
		SetConsoleCursorPosition(h, XY);
	}
	void Color(int i) {
		SetConsoleTextAttribute(h, i);
	}
	void Box(int x, int y, int length, int heigth, bool blank) {

		int tempX = x;
		int tempY = y;
		for (int i = 1; i <= length - 1; i++) {
			Pos(x + 1, y); cout << "-";
			Pos(x + 1, y + heigth); cout << "-";
			x++;
		}
		x = tempX;
		for (int i = 1; i <= heigth - 1; i++) {
			Pos(x, y + 1); cout << "|";
			Pos(x + length, y + 1); cout << "|";
			y++;
		}
		y = tempY;
		x = tempX;
		if (blank == FALSE) {
			for (int i = 0; i < heigth - 1; i++) {
				for (int ii = 0; ii < length - 1; ii++) {
					Pos(x + 1, y + 1); cout << " ";
					x++;
				}
				x = tempX;
				y++;

			}
		}

	}
	string getLine(ifstream& file, int line) {

		string tempLine;
		file.seekg(0, ios::beg);
		for (int i = 1; i <= line; i++)
			file >> tempLine;
		return tempLine;
	}
	int random(int min, int max) {

		int temp;

		srand(time(NULL));
		temp = rand() % (max - min) + min;

		return temp;
	}
	void replace(string path, string old, string re) {

		vector<string> file;
		string temp;

		ifstream infile(path);

		while (!infile.eof())
		{
			getline(infile, temp);
			file.push_back(temp);
		}
		// done reading file
		infile.close();

		string item;
		for (int i = 0; i < (int)file.size(); ++i)
		{
			
			if (file[i] == old)
			{

				file[i]= re;
				i = 0; // Reset search
			}
		}
		//write new order list back out
		ofstream out(path, ios::out | ios::trunc);

		for (vector<string>::const_iterator i = file.begin(); i != file.end(); ++i)
		{
			out << *i << endl;
		}
		out.close();
	}

public:
	Account(string ID);
	void deposite();
	void withdraw();
	void checkBalance();
	void transfer();
	void info();
	void settings();
	
};


