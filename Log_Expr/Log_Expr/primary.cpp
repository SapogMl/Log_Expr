#include<iostream>
using namespace std;

/*
пробелы
регистр
скобки
*
*/

/* Ввод: строка
Вывод: строка без пробелов, лишних скобок, символов *, с буквами в одном регистре */
string InputCleaner(string str) {

	for (int i = 0; &(str[i]) != nullptr; i++) {

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

	for (int i = index; i < str.length - 1; i++) {

		str[i] = str[i + 1];

	}
	delete str[str.length - 1];

	return str;
}

string change_reg(string str, int index) {

	str[index] = str[index] + 'A' - 'a';

	return str;
}

int bracket_search(string str, int index) {

	int unpaired_counter = 1;

	for (int i = index; i < str.length; i++) {

		if (str[i] == '(') {
			unpaired_counter++;
		}
		else if (str[i] == ')') {
			unpaired_counter--;
		}

		if (unpaired_counter == 0) {
			return i;
		}

	}

}

/* Ввод: строка
Вывод: код ошибки ввода */
int InputCorrect(string a) {}
