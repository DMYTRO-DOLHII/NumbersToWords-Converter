#include <iostream> 
#include <fstream> 
#include <string>
#include <conio.h>
#include <clocale>
#include "Converter.h"

using namespace std;

void main() {
	setlocale(LC_ALL, "Russian");

	Converter converter;

	do {
		system("cls");
		unsigned long long int number;
		cout << "\n����� : ";
		cin >> number;

		converter.convert(number);
		cout << "\n\n���������: " << converter.getResult();
		cout << "\n\nEsc - �����";
	} while (_getch() != 27);

}