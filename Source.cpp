#include <iostream>

// https://github.com/ArinaMonicheva/SeaBattle

using namespace std;

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
			case 3:
				cout << 'O';
				break;
			}
		}
	}

	return;
}

void noRepeatRead(int** field, int loops, int decks) {

	int X, Y;

	for (int i = 0; i < loops; i++) {
		cout << "Enter deck coords for" << i << "-deck ship" << endl;
		int j = 0;
		while (j < decks) {
			cin >> X >> Y;
			if (X > 1 && X < 11 && Y > 1 && Y < 11 && field[Y][X] != 1) {
				field[Y - 1][X - 1] = 1;
				j++;
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

void gameLogic(int** playersField, int** AIField) {
	bool gameOn = true;
	int X, Y;

	while (gameOn) {
		cout << "Enter coords to shoot" << endl;
		bool incorrect = true;
		while (incorrect) {
			cin >> X >> Y;
			if (X > 1 && X < 11 && Y > 1 && Y < 11 && AIField[Y][X] != 3 && AIField[Y][X] != 2) {
				switch (AIField[Y - 1][X - 1]) {
				case 0:
					cout << "You missed" << endl;
					AIField[Y - 1][X - 1] = 3;
					incorrect = false;
					break;
				case 1:
					int untouchedDeck = 0;
					for (int i = Y - 2; i < Y; i++) {
						for (int j = X - 2; j < X; j++) {
							if (AIField[Y - 1][X - 1] == 1) {
								untouchedDeck++;
							}
						}
					}

					if (untouchedDeck) {
						cout << "Hit!" << endl;
					}
					else {
						cout << "Sinked!" << endl;
					}

					AIField[Y - 1][X - 1] = 2;
					break;
				};
			}
			else {
				cout << "Wrong coord, try again!" << endl;
			}
		}
	}
}

int main() {
	int size = 10;
	int** playersField = new int* [size];
	int** AIField = new int* [size];

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
		delete[] playersField[i];
		delete[] AIField[i];
	}

	delete[] playersField;
	delete[] AIField;

	return 0;
}