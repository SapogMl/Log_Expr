#include<iostream>
using namespace std;
#include<primary.h>
#include<string> // temporary

int main() {
	string a = "ABC   + A*B";
	cout << InputCleaner(a);
	return 0;
}