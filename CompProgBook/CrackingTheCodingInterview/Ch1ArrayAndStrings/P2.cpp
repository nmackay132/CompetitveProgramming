#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>

using namespace std;

string compressString(string str) {
	string result = "";
	int count = 1;
	for (int i = 1; i < str.length(); i++) {
		if (str[i] == str[i - 1]) {
			count++;
		}
		else {
			result += str[i - 1];
			result += '0' + count;
			count = 1;
		}
	}
	result += str[str.length() - 1];
	result += '0' + count;

	return result;
}

int g1[10][10];

void rotateMatrix() {
	int offset = 10 / 2;
	for (int i = 0; i < offset; i++) {
		//save right
		int right[10];
		for (int j = 0 + offset; j < 9 - offset; j++) {
			//right <- top
			right[j] = g1[j][9-offset];
			//bottom <- right
			g1[j][9 - offset] = g1[offset][j];

		}

	}
}

int main() {
	int count = 0;
	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			g1[i][j] = count++;
		}
	}*/
	return 0;
}
