// base convert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>

using namespace std;

//change the number to base 10
long long toBaseTen(int base, long long number) {
	long long baseTenN = 0;
	int i = 0;
	while (number) {
		baseTenN += number % 10 * pow(base, i);
		i++;
		number = number / 10;
	}
	return baseTenN;
}

//convert base 10 number to base(2-16) and print it on screen
void toAnyBase(int base, long long number) {
	int data[100] = { 0 };
	int top = -1;
	while (number) {
		top++;
		data[top] = number % base;
		number = number / base;
	}

	cout << "                     number:";
	while (top >= 0) {
		if (data[top] < 10)
			cout << data[top];
		else {
			switch (data[top]) {
			case 10: cout << 'A';
				break;
			case 11: cout << 'B';
				break;
			case 12: cout << 'C';
				break;
			case 13: cout << 'D';
				break;
			case 14: cout << 'E';
				break;
			case 15: cout << 'F';
				break;
			default: cout << '?';
			}

		}
		top--;
	}
	cout << endl;
}



int main()
{
	long long original;
	int baseO, baseN;
	long long baseTNum;
	cout << "original number- input base(2-10): ";
	cin >> baseO;
	cout << "                 input number: ";
	cin >> original;
	cout << "converted number- input base(2-16): ";
	cin >> baseN;

	baseTNum = toBaseTen(baseO, original);
	//cout << "number in base 10: " << baseTNum << endl;

	toAnyBase(baseN, baseTNum);
	return 0;
}

