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
		cout << "\nЧисло : ";
		cin >> number;

		converter.convert(number);
		cout << "\n\nРезультат: " << converter.getResult();
		cout << "\n\nEsc - Выход";
	} while (_getch() != 27);

}