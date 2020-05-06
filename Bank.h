
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <time.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void setWindow(short x, short y, int length, int heigth, bool mouse) {

	MoveWindow(GetConsoleWindow(), 1500 / 2 - (length / 2), 800 / 2 - (heigth / 2), length, heigth, TRUE);
	COORD XY{ x , y };
	SetConsoleScreenBufferSize(h, XY);
	//ShowScrollBar(GetConsoleWindow(), SB_BOTH, FALSE);

	CONSOLE_CURSOR_INFO info;

	GetConsoleCursorInfo(h, &info);
	info.bVisible = mouse;
	SetConsoleCursorInfo(h, &info);


}
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
			Pos(x+1, y); cout << "-";
			Pos(x + 1, y+heigth); cout << "-";
			x++;
		}
		x = tempX;
		for (int i = 1; i <= heigth - 1; i++) {
			Pos(x, y+1); cout << "|";
			Pos(x + length, y+1); cout << "|";
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
