#pragma once
#include <string>
#include <string.h>
#include <iostream>

#define N 7

using namespace std;

class Converter{
private:
	unsigned long long int number;
	string result;
	unsigned long long int numbersByCategory[N];
	string categories[N] = {"����������", "����������", "��������", "��������", "�������", "�����", ""};

public:
	void setNumber(unsigned long long int number) {
		this->number = number;
	}

	unsigned long long int getNumber() {
		return number;
	}

	void setResult(string result) {
		this->result = result;
	}

	string getResult() {
		return result;
	}

	void divideByCategory() {
		unsigned long long int n = number;
		unsigned long long int category = 0;
		unsigned long long int divider = 1000000000000000000;
		int i = 0;

		for (i = 0; i < N; i++) {
			numbersByCategory[i] = 0;
		}

		i = 0;

		while(n != 0) {
			category = n / divider;
			if (category != 0) {
				numbersByCategory[i] = category;
			}
			n -= category * divider;
			divider /= 1000;
			i++;
		}
	}

	string numberToString(unsigned long long int num, int i) {
		string n = "";

		unsigned long long int hundreds = num / 100;
		switch (hundreds)
		{
		case 1: n += "���"; break;
		case 2: n += "������"; break;
		case 3: n += "������"; break;
		case 4: n += "���������"; break;
		case 5: n += "������"; break;
		case 6: n += "�������"; break;
		case 7: n += "������"; break;
		case 8: n += "��������"; break;
		case 9: n += "��������"; break;
		default:
			break;
		}

		num -= hundreds * 100;

		unsigned long long int tens = num / 10;

		switch (tens) {
		case 1: 
			switch (num / 1)
			{
			case 10: n += " ������"; return n;
			case 11: n += " ����������"; return n;
			case 12: n += " ����������"; return n;
			case 13: n += " ����������"; return n;
			case 14: n += " ������������"; return n;
			case 15: n += " ����������"; return n;
			case 16: n += " �����������"; return n;
			case 17: n += " ����������"; return n;
			case 18: n += " ������������"; return n;
			case 19: n += " ������������"; return n;
			default:
				break;
			}
		case 2: n += " ��������"; break;
		case 3: n += " ��������"; break;
		case 4: n += " �����"; break;
		case 5: n += " ��������"; break;
		case 6: n += " ���������"; break;
		case 7: n += " ��������"; break;
		case 8: n += " ����������"; break;
		case 9: n += " ���������"; break;
		default:
			break;
		}

		num -= tens * 10;

		unsigned long long int ones = num / 1;

		if (i == 5) {
			if (ones == 1) {
				n += " ����";
				return n;
			} else if (ones == 2) {
				n += " ���";
				return n;
			}
		}

		switch (ones)
		{
		case 1: n += " ����"; return n;
		case 2: n += " ���"; return n;
		case 3: n += " ���"; return n;
		case 4: n += " ������"; return n;
		case 5: n += " ����"; return n;
		case 6: n += " �����"; return n;
		case 7: n += " ����"; return n;
		case 8: n += " ������"; return n;
		case 9: n += " ������"; return n;
		default:
			break;
		}

		return n;
	}

	string ending(int i) {
		if (to_string(numbersByCategory[i]).length() == 3) {
			char ones = to_string(numbersByCategory[i]).at(2);
			char tens = to_string(numbersByCategory[i]).at(1);

			if (ones == '2' || ones == '3' || ones == '4') {
				return "� ";
			} else if (ones == '1' && tens != '1') {
				return " ";
			} else {
				return "�� ";
			}
		} else if (to_string(numbersByCategory[i]).length() == 2) {
			char ones = to_string(numbersByCategory[i]).at(1);
			char tens = to_string(numbersByCategory[i]).at(0);

			if (ones == '2' || ones == '3' || ones == '4') {
				return "� ";
			}
			else if (ones == '1' && tens != '1') {
				return " ";
			}
			else {
				return "�� ";
			}
		} else {
			char ones = to_string(numbersByCategory[i]).at(0);

			if (ones == '2' || ones == '3' || ones == '4') {
				return "� ";
			} else if (ones == '1') {
				return " ";
			} else {
				return "�� ";
			}
		}
		return "";
	}


	void convert(unsigned long long int number) {
		setNumber(number);
		divideByCategory();

		string r = "";

		for (int i = 0; i < N; i++) {
			if (numbersByCategory[i] != 0) {
				switch (i) {
				case 0: r += numberToString(numbersByCategory[i], i) + " " + categories[i] + ending(i); break;
				case 1: r += numberToString(numbersByCategory[i], i) + " " + categories[i] + ending(i); break;
				case 2: r += numberToString(numbersByCategory[i], i) + " " + categories[i] + ending(i); break;
				case 3: r += numberToString(numbersByCategory[i], i) + " " + categories[i] + ending(i); break;
				case 4: r += numberToString(numbersByCategory[i], i) + " " + categories[i] + ending(i); break;
				case 5:
					if (to_string(numbersByCategory[i]).length() == 3) {
						char ones = to_string(numbersByCategory[i]).at(2);
						char tens = to_string(numbersByCategory[i]).at(1);

						if (ones == '2' || ones == '3' || ones == '4') {
							r += numberToString(numbersByCategory[i], i) + " " + categories[i] + "� "; break;
						}
						else if (ones == '1' && tens != '1') {
							r += numberToString(numbersByCategory[i], i) + " " + categories[i] + "� "; break;
						}
						else {
							r += numberToString(numbersByCategory[i], i) + " " + categories[i] + " "; break;
						}
					}
					else if (to_string(numbersByCategory[i]).length() == 2) {
						char ones = to_string(numbersByCategory[i]).at(1);
						char tens = to_string(numbersByCategory[i]).at(0);

						if (ones == '2' || ones == '3' || ones == '4') {
							r += numberToString(numbersByCategory[i], i) + " " + categories[i] + "� "; break;
						}
						else if (ones == '1' && tens != '1') {
							r += numberToString(numbersByCategory[i], i) + " " + categories[i] + "� "; break;
						}
						else {
							r += numberToString(numbersByCategory[i], i) + " " + categories[i] + " "; break;
						}
					}
					else {
						char ones = to_string(numbersByCategory[i]).at(0);

						if (ones == '2' || ones == '3' || ones == '4') {
							r += numberToString(numbersByCategory[i], i) + " " + categories[i] + "� "; break;
						}
						else if (ones == '1') {
							r += numberToString(numbersByCategory[i], i) + " " + categories[i] + "� "; break;
						}
						else {
							r += numberToString(numbersByCategory[i], i) + " " + categories[i] + " "; break;
						}
					}
					break;
				case 6: r += numberToString(numbersByCategory[i], i) + " " + categories[i] + " "; break;
				}
			}
		}
		if (r == "") {
			r = "����";
		}
		setResult(r);
	}

	void print() {
		for (int i = 0; i < N; i++) {
			cout << "\n" << numbersByCategory[i];
		}
	}
};

