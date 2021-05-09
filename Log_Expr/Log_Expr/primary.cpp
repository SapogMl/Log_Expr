#include<iostream>
#include<primary.h>
using namespace std;



string InputCleaner(string str) {

	for (int i = 0; str[i] != '\n'; i++) {

		if ((str[i] == ' ') or (str[i] == '*')) { // пробелы и символы

			str = delete_char(str, i);

		}
		else if (('a' <= str[i]) and (str[i] <= 'z')) { // регистр

			str = change_reg(str, i);

		}
		else if (str[i] == '(') { // скобки
			delete_char(str, bracket_search(str, i));
			delete_char(str, i);
		}

	}

	return str;
}

string delete_char(string str, int index) {

	for (int i = index; i < str.length() - 1; i++) {

		str[i] = str[i + 1];

	}

	string str_twin = "";
	for (int i = 0; i < str.length() - 1; i++) {

		str_twin[i] = str[i];

	}

	return str_twin;
}

string change_reg(string str, int index) {

	str[index] = str[index] + 'A' - 'a';

	return str;
}

int bracket_search(string str, int index) {

	int unpaired_counter = 1;
	int result = 0;

	for (int i = index; i < str.length(); i++) {

		if (str[i] == '(') {
			unpaired_counter++;
		}
		else if (str[i] == ')') {
			unpaired_counter--;
		}

		if (unpaired_counter == 0) {
			result = i;
			break;
		}

	}

	return result;
}