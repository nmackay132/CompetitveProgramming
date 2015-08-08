#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void reverseString(char* str) {
	//int end = 0;
	char* end = str;
	while (*end) {
		++end;
	}
	--end;
	while (str < end) {
		char front = *str;
		*str++ = *end;
		*end-- = front;
	}
}

void copyString(char * str, char * copy) {
	char * temp = str;
	while (*temp) {
		*copy++ = *temp++;
	}
	*copy = '\0';
}

char* copyString2(char * str) {
	int len = 0;
	char *temp = str;
	while (*temp++) {
		len++;
	}
	char* result = (char*) malloc((len + 1)*sizeof(char));
	for (int i = 0; i < len; i++) {
		result[i] = str[i];
	}
	result[len] = '\0';
	return result;
}

int main() {
	/*char st[] = "abcde";
	reverseString(st);
	cout << st << endl;
	printf("%s\n", st);*/

	char str1[] = "Nathan";
	cout << &str1 << endl;
	char str2[] = "";
	//copyString(str1, str2);
	char* str3 = copyString2(str1);
	cout << str1 << " " << str3;
	//cout << &str1 << " " << &str2 << endl;

	return 0;
}