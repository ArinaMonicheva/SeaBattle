#include <iostream>

using namespace std;

int main() {
	int size = 10;
	int** playersField = new int*[size];
	int** AIField = new int*[size];

	for (int i = 0; i < size; i++) {
		playersField[i] = new int[size];
		AIField[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			playersField[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {
		delete [] playersField[i];
		delete[] AIField[i];
	}

	delete[] playersField;
	delete[] AIField;

	return 0;
}

void drawField(int** field, int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			switch (field[i][j]) {
			case 0:
				cout << '~';
				break;
			case 1:
				cout << '=';
				break;
			case 2:
				cout << 'x';
				break;
			}
		}
	}

	return;
}

void fillField(int** field, int size) {

	cout << "Enter ship's coords" << endl;

	for (int i = 1; i < 5; i++) {
		for (int j = 4; j > 0; j--) {
			noRepeatRead(field, i, j);
		}
	}

	return;
}

void noRepeatRead(int** field, int loops, int decks) {

	int X, Y;

	for (int i = 0; i < loops; i++) {
		cout << "Enter deck coords for" << i << "-deck ship" << endl;
		for (int j = 0; j < decks; j++) {
			cin >> X >> Y;
			field[Y][X] = 1;
		}
	}

	return;
}