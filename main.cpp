#include <Windows.h>
#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

const int X = 10; //Размерность массива
const int Y = 10;

int Speed = 200;

int Column = 5;
int Line = 0;

int Level = 10;
int countOfSymbolInLevel = 0;

char Letter[] = { 'A','B','C','D','E','F','G','H','K','L','X','Y','1','2','3','4' };
int NumLength = -1;
int NumLetter = 0;

char Mass[X][Y];

void getLengthLetterMass() {
	for (int i = 0; Letter[i]; i++) {
		NumLength++;
	}
	NumLength--;
}

void SymbolFallingMechanism()
{
	if (Y > Line) { ++Line; }
	else { Letter[0] = ' '; }
}

void CleanDisplay()
{
	Sleep(Speed);
	system("cls");
}

void MassWorker()
{
	while (Y > Line)
	{
		for (int i = 0; i < X; ++i)
		{
			for (int j = 0; j < Y; ++j)
			{
				if (i == Line && j == Column)
				{
					Mass[i][j] = Letter[NumLetter];
					cout << Mass[i][j] << ' ';
					continue;
				}
				Mass[i][j] = ' ';
				cout << Mass[i][j] << ' ';
			}
			cout << "\n";
		}
		SymbolFallingMechanism();
		CleanDisplay();
	}
}

void StartNextSymbol()
{
	while (Level > countOfSymbolInLevel)
	{
		Line = 0;
		++countOfSymbolInLevel;
		NumLetter = rand() % NumLength + 1;
		MassWorker();
	}
}

void main()
{
	getLengthLetterMass();
	StartNextSymbol();
}